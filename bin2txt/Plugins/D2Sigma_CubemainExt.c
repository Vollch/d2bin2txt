#include "../global.h"

#define FILE_PREFIX "CubemainExt"

#pragma pack(push, 1)
typedef struct
{
    int vgoldcost;
} ST_LINE_INFO;
#pragma pack(pop)

static unsigned int m_iLines = 0;
static ST_LINE_INFO *m_astLines = NULL;

MODULE_SETLINES_FUNC(m_astLines, ST_LINE_INFO);

char *CubemainExt_ExternList[] =
{
    "description",
    "goldcost",
    NULL,
};

int CubemainExt_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( iLineNo >= m_iLines )
    {
        return 0;
    }
    else if ( !stricmp(acKey, "goldcost") && m_astLines[iLineNo].vgoldcost )
    {
        sprintf(acOutput, "%d", m_astLines[iLineNo].vgoldcost);
        return 1;
    }

    return 0;
}

static int CubemainExt_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "goldcost") )
    {
        memcpy(&m_astLines[m_iLines++], pvLineInfo, sizeof(ST_LINE_INFO));
    }

    return 0;
}

int process_CubemainExt(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, goldcost, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(CellFiles, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_EXTENSION;
            m_stCallback.pfnConvertValue = CubemainExt_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


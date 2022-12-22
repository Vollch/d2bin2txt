#include "../global.h"

#define FILE_PREFIX "Towns"
#define NAME_PREFIX "tw"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vAct;
    unsigned char vLevelID;
} ST_LINE_INFO_813568;

typedef struct
{
    ST_LINE_INFO_813568 sLineInfo;

    unsigned char vdifficulty;
} ST_LINE_INFO_2900992;

#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int Towns_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_813568 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(Towns), 0xFFFF, pcTemplate, Levels_GetLevelName(pstLineInfo->vLevelID), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_Towns(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO_813568 *pstLineInfo = (ST_LINE_INFO_813568 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelID, UCHAR);

    if ( m_iBinStructSize == sizeof(ST_LINE_INFO_2900992) )
    {
        ST_LINE_INFO_2900992 *pstLineInfoExt = (ST_LINE_INFO_2900992 *)m_acLineInfoBuf;

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoExt, difficulty, UCHAR);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = Towns_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, m_iBinStructSize, 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


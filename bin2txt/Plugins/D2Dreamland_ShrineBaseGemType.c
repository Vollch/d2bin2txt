#include "../global.h"

#define FILE_PREFIX "ShrineBaseGemTypes"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned char vitemCode[4];
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int ShrineBaseGemTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        char acCode[5] = {0};
        strncpy(acCode, pstLineInfo->vitemCode, sizeof(pstLineInfo->vitemCode));
        String_Trim(acCode);

        if ( !String_BuildName(FORMAT(ShrineBaseGemTypes), Misc_GetItemString2(acCode), pcTemplate, acCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vitemCode, sizeof(pstLineInfo->vitemCode));
        }

        return 1;
    }

    return 0;
}

int process_ShrineBaseGemTypes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemCode, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = ShrineBaseGemTypes_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


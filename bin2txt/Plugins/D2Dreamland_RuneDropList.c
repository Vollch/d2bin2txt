#include "../global.h"

#define FILE_PREFIX "RuneDropList"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned char vItemCode[4];
    unsigned int vprob;
    unsigned short vminlevel;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int RuneDropList_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        char acCode[5] = {0};
        unsigned int uiString = 0xFFFF;
        ST_BT_NODE *sItem;

        strncpy(acCode, pstLineInfo->vItemCode, sizeof(pstLineInfo->vItemCode));
        String_Trim(acCode);

        if ( sItem = Tree_Search(Map_Items, acCode) )
        {
            uiString = Lookup_ItemString(sItem->uiId);
        }

        if ( !String_BuildName(FORMAT(RuneDropList), uiString, pcTemplate, acCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vItemCode, sizeof(pstLineInfo->vItemCode));
        }

        return 1;
    }

    return 0;
}

int process_RuneDropList(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prob, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minlevel, USHORT);

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
            m_stCallback.pfnFieldProc = RuneDropList_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


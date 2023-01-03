#include "../global.h"

#define FILE_PREFIX "Gamble"

typedef struct
{
    char vcode[12];
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "name",
    NULL,
};

static int Gamble_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "name") )
    {
        char acCode[13] = {0};
        char *pcName = &acCode[0];
        unsigned int uiString = 0xFFFF;
        ST_BT_NODE *sItem;

        strncpy(acCode, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        String_Trim(acCode);
        if ( sItem = Tree_Search(Map_Items, acCode) )
        {
            pcName = Lookup_ItemName(sItem->uiId);
            uiString = Lookup_ItemString(sItem->uiId);
        }

        if ( !String_BuildName(FORMAT(gamble), uiString, pcTemplate, pcName, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        }

        return 1;
    }

    return 0;
}

static char *Gamble_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vcode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_gamble(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(armor, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(weapons, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            //m_stCallback.pfnGetKey = Gamble_GetKey;
            m_stCallback.pfnFieldProc = Gamble_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
        default:
            break;
    }

    return 1;
}


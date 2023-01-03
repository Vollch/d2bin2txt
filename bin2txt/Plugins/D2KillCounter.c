#include "../global.h"

#define FILE_PREFIX "D2KillCounter"
#define NAME_PREFIX "kc"

typedef struct
{
    unsigned short vStat;
    unsigned short vValue;

    unsigned short vLevelsUnderYou;
    unsigned short vLevelsAboveYou;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int D2KillCounter_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(D2KillCounter), ItemStatCost_GetString(pstLineInfo->vStat), pcTemplate, Lookup_ItemStatCost(pstLineInfo->vStat), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_D2KillCounter(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Value, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelsUnderYou, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelsAboveYou, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2KillCounter_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


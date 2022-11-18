#include "global.h"

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
    "*eol",
    NULL,
};

static int D2KillCounter_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "*desc") )
    {
        char *pcName = ItemStatCost_GetStateName(pstLineInfo->vStat);
        if ( !String_BuildName(FORMAT(D2KillCounter), ItemStatCost_GetString(pstLineInfo->vStat), pcTemplate, pcName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int D2KillCounter_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "Stat") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vStat);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }

    return result;
}

int process_D2KillCounter(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Value, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelsUnderYou, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelsAboveYou, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnConvertValue = D2KillCounter_ConvertValue;
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


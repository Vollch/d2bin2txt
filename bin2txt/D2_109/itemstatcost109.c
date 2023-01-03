#include "../global.h"

#define FILE_PREFIX "ItemStatCost"
#define NAME_PREFIX "is"

static char *m_apcInternalProcess[] =
{
    "Stat",
    "ID",
    NULL,
};

static int ItemStatCost_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_ITEMSTATCOST_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Stat") )
    {
        if ( !String_BuildName(FORMAT(itemstatcost), 0xFFFF, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "ID") )
    {
        sprintf(acOutput, "%u", iLineNo);

        return 1;
    }

    return 0;
}

static void ItemStatCost_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_ITEMSTATCOST_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, damagerelated, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemspecific, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Divide, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Multiply, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Add, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ValShift, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspBits, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspAdd, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetmyspStat, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Percent, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PerLevel, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PerLevelShift, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ByTime, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Encode, CHAR);
}

int process_itemstatcost109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_ITEMSTATCOST_109 *pstLineInfo = (ST_ITEMSTATCOST_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            ItemStatCost_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = ItemStatCost_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


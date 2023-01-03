#include "../global.h"

#define FILE_PREFIX "Runes"

static void Runes_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_RUNES_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunemyspName, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, complete, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, server, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune1, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune2, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune3, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune4, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune5, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune6, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code7, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max7, INT);
}

int process_runes109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_RUNES_109 *pstLineInfo = (ST_RUNES_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Runes_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "UniqueItems"

static char *m_apcNotUsed[] =
{
    "type",
    NULL,
};

static void UniqueItems_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_UNIQUEITEMS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beta, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transform, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invtransform, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelReq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, completed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod1Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod1Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod2Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod2Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod3Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod3Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod3Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod4Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod4Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod4Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod4Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod5Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod5Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod5Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod5Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod6Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod6Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod6Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod6Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod7Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod7Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod7Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod7Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod8Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod8Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod8Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod8Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod9Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod9Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod9Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod9Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod10Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod10Param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod10Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemMod10Max, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, End, EOL);
}

int process_uniqueitems109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_UNIQUEITEMS_109 *pstLineInfo = (ST_UNIQUEITEMS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            UniqueItems_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

static char *m_apcNotUsed[] =
{
    "transform",
    NULL,
};

static void Magic_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_MAGIC_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, COLOR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classspecific, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classlevelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, frequency, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multiply, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, add, UINT);
}

int process_magic109(char* pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_MAGIC_109 *pstLineInfo = (ST_MAGIC_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Magic_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, pcFilename, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


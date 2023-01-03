#include "../global.h"

static char *m_apcNotUsed[] =
{
    "divide",
    "multiply",
    "add",
    NULL,
};

static void Rare_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_RARE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
}

int process_rare109(char* pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_RARE_109 *pstLineInfo = (ST_RARE_109 *)m_acLineInfoBuf;
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
            break;

        case EN_MODULE_INIT:
            Rare_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, pcFilename, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


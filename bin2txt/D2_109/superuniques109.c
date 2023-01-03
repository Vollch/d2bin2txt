#include "../global.h"

#define FILE_PREFIX "SuperUniques"

static void SuperUniques_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_SUPERUNIQUE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinGrp, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxGrp, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoPos, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EClass, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stacks, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TC, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCmybr1Nmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCmybr1Hmybr2, TREASURE);
}

int process_superuniques109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_SUPERUNIQUE_109 *pstLineInfo = (ST_SUPERUNIQUE_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            SuperUniques_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


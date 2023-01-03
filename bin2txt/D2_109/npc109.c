#include "../global.h"

#define FILE_PREFIX "Npc"

static void NPC_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_NPC_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, npc, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, buymyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sellmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, repmyspmult, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuy, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuymyspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuymyspmybr1Hmybr2, UINT);
}

int process_npc109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_NPC_109 *pstLineInfo = (ST_NPC_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            NPC_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


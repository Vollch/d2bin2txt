#include "../global.h"

#define FILE_PREFIX "Npc"


typedef struct
{
    unsigned short vnpc;  //monstats
    unsigned char pad0x02[2];

    unsigned int vsellmyspmult;
    unsigned int vbuymyspmult;
    unsigned int vrepmyspmult;

    unsigned int vquestflagmyspA;
    unsigned int vquestflagmyspB;
    unsigned int vquestflagmyspC;

    unsigned int vquestsellmultmyspA;
    unsigned int vquestsellmultmyspB;
    unsigned int vquestsellmultmyspC;

    unsigned int vquestbuymultmyspA;
    unsigned int vquestbuymultmyspB;
    unsigned int vquestbuymultmyspC;

    unsigned int vquestrepmultmyspA;
    unsigned int vquestrepmultmyspB;
    unsigned int vquestrepmultmyspC;

    unsigned int vmaxmyspbuy;
    unsigned int vmaxmyspbuymyspmybr1Nmybr2;
    unsigned int vmaxmyspbuymyspmybr1Hmybr2;
} ST_LINE_INFO;

static unsigned int m_iBinStructSize = 0;

static void NPC_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, npc, MONSTAT);

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

int process_npc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_NPC_109) )
    {
        return process_npc109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
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


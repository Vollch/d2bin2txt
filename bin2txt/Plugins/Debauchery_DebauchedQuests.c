#include "../global.h"

#define FILE_PREFIX "DebauchedQuests"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vHcIdx;
    unsigned int vGroup;
    unsigned char vQuest[6];
    char vGranted;
    char vStarted;
    char vGoalAchieved;
    char vCompleted;
    char vDifficulty;
} ST_LINE_INFO;
#pragma pack(pop)

int process_DebauchedQuests(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quest, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Granted, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Started, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GoalAchieved, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Completed, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, CHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


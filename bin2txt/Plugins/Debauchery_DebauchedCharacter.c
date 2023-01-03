#include "../global.h"

#define FILE_PREFIX "DebauchedCharacter"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vHcIdx;
    unsigned char vFunction[16];
    unsigned char vClass; // class
    unsigned int vStatID; // itemstat
    unsigned int vSkillName; // skill
    int vValue;
    unsigned char vName[16];
} ST_LINE_INFO;
#pragma pack(pop)

int process_DebauchedCharacter(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Function, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatID, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillName, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Value, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
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


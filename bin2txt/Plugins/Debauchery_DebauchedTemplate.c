#include "../global.h"

#define FILE_PREFIX "DebauchedTemplate"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vHcIdx;
    unsigned short vLevel;
    unsigned int vGroup;
    unsigned char vClass; // class
    unsigned short vStr;
    unsigned short vDex;
    unsigned short vVit;
    unsigned short vEnr;
    unsigned int vSkillGroup;
    unsigned int vItemGroup;
    unsigned int vWaypointGroup;
    unsigned int vQuestGroup;
} ST_LINE_INFO;
#pragma pack(pop)

int process_DebauchedTemplate(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dex, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vit, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Enr, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillGroup, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemGroup, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WaypointGroup, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QuestGroup, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
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


#include "../global.h"

#define FILE_PREFIX "SkillTree"

typedef struct
{
    unsigned short vPosX;
    unsigned short vPosY;
} ST_LINE_INFO;

int process_SkillTree(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PosX, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PosY, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


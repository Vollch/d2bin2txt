#include "../global.h"

#define FILE_PREFIX "Charstats2"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vhcIdx;
    unsigned char vclassID; // class
    unsigned int vSkillPerLevel; // skillcode
} ST_LINE_INFO;
#pragma pack(pop)

int process_Charstats2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classID, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillPerLevel, UINT_SKILLCODE);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);

            return SkillsCode_ParseBin(acTemplatePath, acBinPath, acTxtPath);
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


#include "../global.h"

#define FILE_PREFIX "SkillTabs"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vcharClass;
    unsigned char vtab;
    unsigned short vcaption;
    unsigned short vcaptionPosX;
    unsigned short vcaptionPosY;
} ST_LINE_INFO;
#pragma pack(pop)

int process_SkillTabs(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charClass, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, tab, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, caption, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, captionPosX, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, captionPosY, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
        default:
            break;
    }

    return 1;
}


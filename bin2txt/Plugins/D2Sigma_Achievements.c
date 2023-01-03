#include "../global.h"

#define FILE_PREFIX "Achievements"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vLayer;
    int vBronze;
    int vSilver;
    int vGold;
    unsigned short vStrBadgeTitle;
    unsigned short vStrBadgeDesc;
} ST_LINE_INFO;
#pragma pack(pop)

int process_Achievements(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Layer, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Bronze, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Silver, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gold, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrBadgeTitle, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrBadgeDesc, TBL_STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
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


#include "../global.h"

#define FILE_PREFIX "npctalk"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vid; // monstats
    char vnomenu;
    char vvarmsgnum;
    unsigned short vmsg1; // string
    unsigned short vmsg2; // string
    unsigned short vmsg3; // string
    unsigned short vmsg4; // string
    unsigned short vmsg5; // string
    unsigned short vmsg6; // string
    unsigned short vchance;
} ST_LINE_INFO;
#pragma pack(pop)

int process_npctalk(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, id, USHORT_MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nomenu, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, varmsgnum, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg1, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg2, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg3, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg4, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg5, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, msg6, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
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


#include "../global.h"

#define FILE_PREFIX "Utility"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vId;

    int vParam1;
    int vParam2;
    int vParam3;
    int vParam4;
    int vParam5;
    int vParam6;
    int vParam7;
    int vParam8;
    int vParam9;
    int vParam10;
} ST_LINE_INFO;
#pragma pack(pop)

int process_Utility(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param10, INT);

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


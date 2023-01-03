#include "../global.h"

#define FILE_PREFIX "DebauchedWaypoints"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vHcIdx;
    unsigned int vGroup;
    unsigned int vWaypointID;
    char vAllDiffsmyqm;
} ST_LINE_INFO;
#pragma pack(pop)

int process_DebauchedWaypoints(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WaypointID, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AllDiffsmyqm, CHAR);

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


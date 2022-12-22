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
} ST_LINE_INFO_2900992;

typedef struct
{
    unsigned char vhcidx;
    int vvalue;
    unsigned char vIntensity;
    unsigned char vred;
    unsigned char vgreen;
    unsigned char vblue;
} ST_LINE_INFO_813568;
#pragma pack(pop)

static unsigned int m_iBinStructSize = 0;

int process_Utility_2900992(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_2900992 *pstLineInfo = (ST_LINE_INFO_2900992 *)m_acLineInfoBuf;

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

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Utility_813568(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_813568 *pstLineInfo = (ST_LINE_INFO_813568 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcidx, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Intensity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, blue, UCHAR);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Utility(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_2900992) )
            {
                return process_Utility_2900992(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize == sizeof(ST_LINE_INFO_813568) )
            {
                return process_Utility_813568(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize > 0 )
            {
                my_printf("Unknown version of Utility\n");
            }
            break;

        default:
            break;
    }

    return 1;
}


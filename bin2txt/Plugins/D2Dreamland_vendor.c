#include "../global.h"

#define FILE_PREFIX "Vendor"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vvendor; // monstats
    unsigned char vvendormin;
    unsigned char vvendormax;
    unsigned char vvendormagicmin;
    unsigned char vvendormagicmax;
    int vvendormagiclvl;
    unsigned char vitemcode[4];
    int vquality;
} ST_LINE_INFO;
#pragma pack(pop)

int process_vendor(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendor, USHORT_MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendormin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendormax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendormagicmin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendormagicmax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vendormagiclvl, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemcode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, quality, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
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


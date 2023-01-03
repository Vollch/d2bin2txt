#include "../global.h"

#define FILE_PREFIX "DreamlandConfig"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned char venabled;
} ST_LINE_INFO;
#pragma pack(pop)

static int m_iModuleActive = 0;

int isD2DreamlandActive()
{
    return m_iModuleActive;
}

int process_DreamlandConfig(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            if ( getBinStructSize(acBinPath, FILE_PREFIX) == sizeof(ST_LINE_INFO) )
            {
                m_iModuleActive = 1;
            }
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


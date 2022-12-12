#include "../global.h"

#define FILE_PREFIX "_LevelsExtension"

typedef struct
{
    int vLevel;
    int vBlockTP;
    int vMinLevel;
    int vMinLevelmyspmybr1Nmybr2;
    int vMinLevelmyspmybr1Hmybr2;
    int vMaxLevel;
    int vMaxLevelmyspmybr1Nmybr2;
    int vMaxLevelmyspmybr1Hmybr2;
    int vDescString;
    int vAllowReveal;
    int vDestinationOnly;
} ST_LINE_INFO;

static int m_iModuleActive = 0;

int isRoSActive()
{
    return m_iModuleActive;
}

int process_RoS(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlockTP, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevel, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevelmyspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevelmyspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevel, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevelmyspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevelmyspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DescString, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AllowReveal, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestinationOnly, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, end, EOL);

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


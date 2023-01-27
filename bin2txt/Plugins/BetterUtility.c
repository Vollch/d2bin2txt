#include "../global.h"

#define FILE_PREFIX "BetterUtility"

#pragma pack(push, 1)
typedef struct
{
    char vHcIDx;
    char vEnabled;
    int vPar1;
    int vPar2;
    char vPar3[32];
    char vPar4[32];
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcNotUsed[] =
{
    "*Settings",
    NULL,
};

int process_BetterUtility(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIDx, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Enabled, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Par1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Par2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Par3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Par4, STRING);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "custtp"

typedef struct
{
    unsigned int vsourceLVL;
    unsigned int vsourceDS1;
    unsigned int vtargetLvl;
} ST_LINE_INFO;

int process_MagicTwn(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sourceLVL, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sourceDS1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, targetLvl, UINT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
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


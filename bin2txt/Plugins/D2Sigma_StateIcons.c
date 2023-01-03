#include "../global.h"

#define FILE_PREFIX "StateIcons"

typedef struct
{
    unsigned short vState; //state
    unsigned char vType;
    unsigned char vPalshift;

    unsigned short vFrame;
    unsigned short vNameStr; //string
} ST_LINE_INFO;

int process_StateIcons(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, State, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Type, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Palshift, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Frame, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameStr, TBL_STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
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


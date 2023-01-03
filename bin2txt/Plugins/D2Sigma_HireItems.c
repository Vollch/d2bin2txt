#include "../global.h"

#define FILE_PREFIX "HireItems"

typedef struct
{
    unsigned short vitype1;
    unsigned short vitype2;
    unsigned short vitype3;
    unsigned short vitype4;
    unsigned short vitype5;
    unsigned short vitype6;

    unsigned short vetype1;
    unsigned short vetype2;
    unsigned short vetype3;
    unsigned short vetype4;
    unsigned short vetype5;
    unsigned short vetype6;
} ST_LINE_INFO;

int process_HireItems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype6, ITEMTYPE);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
        default:
            break;
    }

    return 1;
}


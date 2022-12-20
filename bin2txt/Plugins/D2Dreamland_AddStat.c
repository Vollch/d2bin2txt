#include "../global.h"

#define FILE_PREFIX "AddStat"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned char vitemcode[4];
    char venabled;
    char vhardcore;
    char vsoftcore;
    unsigned short vchance;
    unsigned int vsound;
    unsigned int vmodcode1; // property
    unsigned int vmodcode2; // property
    unsigned int vmodcode3; // property
    unsigned int vmodcode4; // property
    unsigned int vmodcode5; // property
    unsigned int vmodparam1;
    unsigned int vmodparam2;
    unsigned int vmodparam3;
    unsigned int vmodparam4;
    unsigned int vmodparam5;
    int vmodmin1;
    int vmodmin2;
    int vmodmin3;
    int vmodmin4;
    int vmodmin5;
    int vmodmax1;
    int vmodmax2;
    int vmodmax3;
    int vmodmax4;
    int vmodmax5;
} ST_LINE_INFO;
#pragma pack(pop)

int process_AddStat(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemcode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hardcore, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, softcore, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sound, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modcode1, UINT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modcode2, UINT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modcode3, UINT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modcode4, UINT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modcode5, UINT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modparam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modparam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modparam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modparam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modparam5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax5, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
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


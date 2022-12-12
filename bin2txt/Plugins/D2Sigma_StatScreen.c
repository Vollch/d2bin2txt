#include "../global.h"

#define FILE_PREFIX "StatScreen"

#pragma pack(push, 1)
typedef struct
{
    char vpage;
    unsigned int vtype;
    unsigned short vx;
    unsigned short vy;
    unsigned short vtext;
    unsigned char vcolor;
    unsigned char vfont;
    unsigned short vstat;
    unsigned short vlayer; 
    unsigned char visBase;
    unsigned char visPercent;
    int valign;
} ST_LINE_INFO;
#pragma pack(pop)

int process_StatScreen(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, page, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, x, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, y, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, text, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, color, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, font, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, layer, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, isBase, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, isPercent, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, align, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
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


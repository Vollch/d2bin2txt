#include "../global.h"

#define FILE_PREFIX "DebauchedItems"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vHcIdx;
    unsigned int vGroup;
    unsigned char vItem[84]; // cube output
    unsigned char vItemLoc; // bodyloc
    unsigned char vItemQuality;
    unsigned char vItemLevel;
    unsigned char vItemCount;
} ST_LINE_INFO;
#pragma pack(pop)


static int DebauchedItems_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Item") )
    {
        return Cubemain_ProcessOutput(&pstLineInfo->vItem, acOutput);
    }

    return 0;
}

int process_DebauchedItems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemLoc, UCHAR_BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemCount, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(cubemain, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = DebauchedItems_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


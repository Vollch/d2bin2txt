#include "../global.h"

#define FILE_PREFIX "MonEquip"

typedef struct
{
    unsigned short vmonster;   //MonStats
    unsigned short vlevel;

    unsigned int voninit;

    unsigned char vitem1[4];
    unsigned char vitem2[4];
    unsigned char vitem3[4];

    unsigned char vloc1; //bodylocs
    unsigned char vloc2; //bodylocs
    unsigned char vloc3; //bodylocs
    unsigned char vmod1;

    unsigned char vmod2;
    unsigned char vmod3;
    unsigned char pad0x1A[2];
} ST_LINE_INFO;

static int MonEquip_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "monster") )
    {
        if ( 0xFFFF == pstLineInfo->vmonster )
        {
            strcpy(acOutput, "*end*  do not remove");
            return 1;
        }
    }

    return 0;
}

int process_monequip(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monster, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, oninit, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc1, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc2, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc3, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = MonEquip_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


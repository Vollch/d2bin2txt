#include "../global.h"

#define FILE_PREFIX "Gems"

typedef struct
{
    unsigned char vname[32];
    unsigned char vletter[8];

    unsigned int vcode;

    unsigned char pad0x2C[2];
    unsigned char vnummods;
    unsigned char vtransform;

    unsigned int vweaponMod1Code; // property
    unsigned int vweaponMod1Param;
    int vweaponMod1Min;
    int vweaponMod1Max;

    unsigned int vweaponMod2Code; // property
    unsigned int vweaponMod2Param;
    int vweaponMod2Min;
    int vweaponMod2Max;

    unsigned int vweaponMod3Code; // property
    unsigned int vweaponMod3Param;
    int vweaponMod3Min;
    int vweaponMod3Max;

    unsigned int vhelmMod1Code; // property
    unsigned int vhelmMod1Param;
    int vhelmMod1Min;
    int vhelmMod1Max;

    unsigned int vhelmMod2Code; // property
    unsigned int vhelmMod2Param;
    int vhelmMod2Min;
    int vhelmMod2Max;

    unsigned int vhelmMod3Code; // property
    unsigned int vhelmMod3Param;
    int vhelmMod3Min;
    int vhelmMod3Max;

    unsigned int vshieldMod1Code; // property
    unsigned int vshieldMod1Param;
    int vshieldMod1Min;
    int vshieldMod1Max;

    unsigned int vshieldMod2Code; // property
    unsigned int vshieldMod2Param;
    int vshieldMod2Min;
    int vshieldMod2Max;

    unsigned int vshieldMod3Code; // property
    unsigned int vshieldMod3Param;
    int vshieldMod3Min;
    int vshieldMod3Max;
} ST_LINE_INFO;

static int Gems_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        char acLetter[9] = {0};
        char *pcItem = Lookup_Item(pstLineInfo->vcode);

        strncpy(acLetter, pstLineInfo->vletter, sizeof(pstLineInfo->vletter));
        String_Trim(acLetter);

        if ( pcItem && acLetter[0] )
        {
            Map_RuneLetter = Tree_Insert(Map_RuneLetter, pcItem, (unsigned int)strdup(acLetter));
        }

        return 0;
    }

    return 0;
}

int process_gems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, letter, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nummods, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transform, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Max, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnConvertValue = Gems_ConvertValue;

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


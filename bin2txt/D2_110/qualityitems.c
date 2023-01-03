#include "../global.h"

#define FILE_PREFIX "QualityItems"


typedef struct
{
    unsigned char varmor;
    unsigned char vweapon;
    unsigned char vshield;
    unsigned char vscepter;

    unsigned char vwand;
    unsigned char vstaff;
    unsigned char vbow;
    unsigned char vboots;

    unsigned char vgloves;
    unsigned char vbelt;
    unsigned char vnummods;
    unsigned char pad0x0B;

    unsigned int vmod1code; //properties
    unsigned int vmod1param;
    int vmod1min;
    int vmod1max;

    unsigned int vmod2code; //properties
    unsigned int vmod2param;
    int vmod2min;
    int vmod2max;

    unsigned char veffect1[32];
    unsigned char veffect2[32];

    unsigned char pad0x6C[4];
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "ToHitMin",
    "ToHitMax",
    "Dam%Min",
    "Dam%Max",
    "AC%Min",
    "AC%Max",
    "Dur%Min",
    "Dur%Max",
    "thrown",
    "level",
    "multiply",
    "add",
    NULL,
};

int process_qualityitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, armor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weapon, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shield, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, scepter, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, wand, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, staff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, boots, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gloves, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, belt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nummods, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, effect1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, effect2, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


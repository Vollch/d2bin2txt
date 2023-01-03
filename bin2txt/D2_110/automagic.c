#include "../global.h"

#define FILE_PREFIX "AutoMagic"

typedef struct
{
    unsigned char vName[32];

    unsigned char pad0x21[2];
    unsigned short vversion;

    unsigned int vmod1code; //properties
    unsigned int vmod1param;
    int vmod1min;
    int vmod1max;

    unsigned int vmod2code; //properties
    unsigned int vmod2param;
    int vmod2min;
    int vmod2max;

    unsigned int vmod3code; //properties
    unsigned int vmod3param;
    int vmod3min;
    int vmod3max;

    unsigned char vspawnable;
    unsigned char pad0x55;
    unsigned char vtransformcolor; //colors
    unsigned char pad0x57;

    unsigned int vlevel;
    unsigned int vgroup;
    unsigned int vmaxlevel;

    unsigned char vrare;
    unsigned char vlevelreq;
    unsigned char vclassspecific; //playerclass
    unsigned char vclass; //playerclass

    unsigned short vclasslevelreq;
    unsigned short vitype1; //itemtypes

    unsigned short vitype2;
    unsigned short vitype3;

    unsigned short vitype4;
    unsigned short vitype5;
    unsigned short vitype6;
    unsigned short vitype7;

    unsigned short vetype1;
    unsigned short vetype2;
    unsigned short vetype3;
    unsigned short vetype4; //实际无用，bin文件不同不用管

    unsigned short vetype5; //实际无用，bin文件不同不用管
    unsigned short vfrequency;

    unsigned int vdivide;
    unsigned int vmultiply;
    unsigned int vadd;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*comment",
    "transform",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static char *AutoMagic_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vName, sizeof(pstLineInfo->vName));
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}
static void AutoMagic_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3code, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, COLOR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classspecific, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classlevelreq, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype5, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, frequency, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multiply, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, add, UINT);
}

int process_automagic(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_MAGIC_109) )
    {
        return process_magic109(FILE_PREFIX, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            AutoMagic_InitValueMap(pstValueMap, pstLineInfo);
            //m_stCallback.pfnGetKey = AutoMagic_GetKey;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


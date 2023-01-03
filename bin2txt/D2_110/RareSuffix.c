#include "../global.h"

#define FILE_PREFIX "RareSuffix"


typedef struct
{
    unsigned char pad0x00[14];
    unsigned short vversion;

    unsigned short vitype1;
    unsigned short vitype2;

    unsigned short vitype3;
    unsigned short vitype4;

    unsigned short vitype5;
    unsigned short vitype6;

    unsigned short vitype7;
    unsigned short vetype1;

    unsigned short vetype2;
    unsigned short vetype3;

    unsigned short vetype4;
    unsigned char vname[32];

    unsigned char pad0x46[2];
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "divide",
    "multiply",
    "add",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static void RareSuffix_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
}

int process_raresuffix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_RARE_109) )
    {
        return process_rare109(FILE_PREFIX, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            RareSuffix_InitValueMap(pstValueMap, pstLineInfo);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


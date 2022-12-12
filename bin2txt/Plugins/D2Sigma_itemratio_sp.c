#include "../global.h"

#define FILE_PREFIX "itemratio_sp"
#define NAME_PREFIX "ir"

typedef struct
{
    unsigned int vUnique;
    unsigned int vUniqueDivisor;
    unsigned int vUniqueMin;
    unsigned int vRare;
    unsigned int vRareDivisor;
    unsigned int vRareMin;
    unsigned int vSet;
    unsigned int vSetDivisor;
    unsigned int vSetMin;
    unsigned int vMagic;

    unsigned int vMagicDivisor;
    unsigned int vMagicMin;
    unsigned int vHiQuality;
    unsigned int vHiQualityDivisor;
    unsigned int vNormal;
    unsigned int vNormalDivisor;

    unsigned short vVersion;
    unsigned char vUber;
    unsigned char vClassmyspSpecific;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Function",
    NULL,
};

static int ItemRatio_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Function") )
    {
        if ( !String_BuildName(FORMAT(itemratio), 0xFFFF, pcTemplate, NAME_PREFIX, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_itemratio_sp(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Unique, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UniqueDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UniqueMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RareDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RareMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Set, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SetDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SetMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MagicDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MagicMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HiQuality, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HiQualityDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NormalDivisor, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Version, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Uber, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClassmyspSpecific, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            m_stCallback.pfnFieldProc = ItemRatio_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

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


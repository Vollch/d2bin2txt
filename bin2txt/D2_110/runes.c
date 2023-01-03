#include "../global.h"

#define FILE_PREFIX "Runes"


typedef struct
{
    unsigned char vName[64];

    unsigned char vRunemyspName[64];

    unsigned char vcomplete;
    unsigned char vserver;
    unsigned char pad0x82[4];
    unsigned short vitype1; //itemtypes

    unsigned short vitype2; //itemtypes
    unsigned short vitype3; //itemtypes

    unsigned short vitype4; //itemtypes
    unsigned short vitype5; //itemtypes

    unsigned short vitype6; //itemtypes
    unsigned short vetype1; //itemtypes

    unsigned short vetype2; //itemtypes
    unsigned short vetype3; //itemtypes

    unsigned int vRune1; //miscs
    unsigned int vRune2;

    unsigned int vRune3;
    unsigned int vRune4;

    unsigned int vRune5;
    unsigned int vRune6;

    unsigned int vT1Code1; //properties
    unsigned int vT1Param1;
    int vT1Min1;
    int vT1Max1;

    unsigned int vT1Code2; //properties
    unsigned int vT1Param2;
    int vT1Min2;
    int vT1Max2;

    unsigned int vT1Code3; //properties
    unsigned int vT1Param3;
    int vT1Min3;
    int vT1Max3;

    unsigned int vT1Code4; //properties
    unsigned int vT1Param4;
    int vT1Min4;
    int vT1Max4;

    unsigned int vT1Code5; //properties
    unsigned int vT1Param5;
    int vT1Min5;
    int vT1Max5;

    unsigned int vT1Code6; //properties
    unsigned int vT1Param6;
    int vT1Min6;
    int vT1Max6;

    unsigned int vT1Code7; //properties
    unsigned int vT1Param7;
    int vT1Min7;
    int vT1Max7;
} ST_LINE_INFO;

typedef struct
{
    ST_LINE_INFO sLineInfo;

    unsigned int vT1Code8;  //properties
    unsigned int vT1Param8;
    int vT1Min8;
    int vT1Max8;

    unsigned int vT1Code9;  //properties
    unsigned int vT1Param9;
    int vT1Min9;
    int vT1Max9;

    unsigned int vT1Code10;  //properties
    unsigned int vT1Param10;
    int vT1Min10;
    int vT1Max10;

    unsigned int vT1Code11;  //properties
    unsigned int vT1Param11;
    int vT1Min11;
    int vT1Max11;

    unsigned int vT1Code12;  //properties
    unsigned int vT1Param12;
    int vT1Min12;
    int vT1Max12;

    unsigned int vT1Code13;  //properties
    unsigned int vT1Param13;
    int vT1Min13;
    int vT1Max13;
} ST_LINE_INFO_D2SIGMA;

typedef struct
{
    unsigned int vT1Code1;  //properties
    unsigned int vT1Param1;
    int vT1Min1;
    int vT1Max1;
} ST_RUNE_CODE;

static char *m_apcInternalProcess[] =
{
    "*runes",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int Runes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*runes") )
    {
        unsigned int *piRune = (unsigned int *)&pstLineInfo->vRune1;
        ST_BT_NODE *sItem;
        char *pcRune;
        int i;

        for ( i = 0; i < 6; i++ )
        {
            if ( (pcRune = Lookup_Item(piRune[i])) &&
                 (sItem = Tree_Search(Map_RuneLetter, pcRune)) )
            {
                strcpy(acOutput, (char *)sItem->uiId);
                acOutput += strlen(acOutput);
            }
        }

        return 1;
    }

    return 0;
}

static int Runes_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;

    if ( 1 == sscanf(acKey, "T1Param%d", &id) )
    {
        ST_RUNE_CODE *pwItype = (ST_RUNE_CODE *)&pstLineInfo->vT1Code1;
        if ( 0 != pwItype[id - 1].vT1Param1 )
        {
            if ( pcResult = Lookup_Skill(pwItype[id - 1].vT1Param1) )
            {
                strcpy(acOutput, pcResult);
            }
            else
            {
                sprintf(acOutput, "%d", pwItype[id - 1].vT1Param1);
            }
        }
        else
        {
            acOutput[0] = 0;
        }
        return 1;
    }

    return 0;
}

static void Runes_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunemyspName, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, complete, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, server, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune1, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune2, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune3, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune4, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune5, ITEM);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rune6, ITEM);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Code7, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Param7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Min7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, T1Max7, INT);

    if ( isD2SigmaActive() )
    {
        ST_LINE_INFO_D2SIGMA *pstLineInfoSigma = (ST_LINE_INFO_D2SIGMA *)m_acLineInfoBuf;

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code8, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param8, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min8, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max8, INT);

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code9, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param9, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min9, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max9, INT);

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code10, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param10, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min10, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max10, INT);

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code11, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param11, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min11, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max11, INT);

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code12, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param12, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min12, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max12, INT);

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Code13, PROPERTY);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Param13, UINT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Min13, INT);
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoSigma, T1Max13, INT);
    }

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);
}

int process_runes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_RUNES_109) )
    {
        return process_runes109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(CellFiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(armor, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(weapons, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(gems, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Runes_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Runes_ConvertValue;
            m_stCallback.pfnFieldProc = Runes_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, m_iBinStructSize,
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


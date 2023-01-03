#include "../global.h"

#define FILE_PREFIX "SkillDesc"
#define NAME_PREFIX "sd"


typedef struct
{//total 288 bytes
    unsigned short vskilldesc;
    unsigned char vSkillPage;
    unsigned char vSkillRow;

    unsigned char vSkillColumn;
    unsigned char vListRow;
    unsigned char vListPool;
    unsigned char vIconCel;

    //0-9999 string.txt 10000-19999 patchstring.txt 20000- expansionstring.txt
    unsigned short vstrmyspname;
    unsigned short vstrmyspshort;

    unsigned short vstrmysplong;
    unsigned short vstrmyspalt;

    unsigned short vstrmyspmana;
    ////////////////////////////////////////////
    unsigned short vdescdam;

    unsigned short vdescatt;
    unsigned char pad0x16[2];

    unsigned int vddammyspcalc1;    //skilldesccode
    unsigned int vddammyspcalc2;

    unsigned char vp1dmelem; //elemtypes
    unsigned char vp2dmelem; //elemtypes
    unsigned char vp3dmelem; //elemtypes
    unsigned char pad0x23;

    unsigned int vp1dmmin;  //skilldesccode
    unsigned int vp2dmmin;
    unsigned int vp3dmmin;
    unsigned int vp1dmmax;
    unsigned int vp2dmmax;
    unsigned int vp3dmmax;

    unsigned short vdescmissile1;   //missiles
    unsigned short vdescmissile2;   //missiles

    unsigned short vdescmissile3;   //missiles
    unsigned char vdescline1;
    unsigned char vdescline2;

    unsigned char vdescline3;
    unsigned char vdescline4;
    unsigned char vdescline5;
    unsigned char vdescline6;

    unsigned char vdsc2line1;
    unsigned char vdsc2line2;
    unsigned char vdsc2line3;
    unsigned char vdsc2line4;

    unsigned char vdsc3line1;
    unsigned char vdsc3line2;
    unsigned char vdsc3line3;
    unsigned char vdsc3line4;

    unsigned char vdsc3line5;
    unsigned char vdsc3line6;
    unsigned char vdsc3line7;
    unsigned char pad0x53;

    //0-9999 string.txt 10000-19999 patchstring.txt 20000- expansionstring.txt
    unsigned short vdesctexta1;
    unsigned short vdesctexta2;

    unsigned short vdesctexta3;
    unsigned short vdesctexta4;

    unsigned short vdesctexta5;
    unsigned short vdesctexta6;

    unsigned short vdsc2texta1;
    unsigned short vdsc2texta2;

    unsigned short vdsc2texta3;
    unsigned short vdsc2texta4;

    unsigned short vdsc3texta1;
    unsigned short vdsc3texta2;

    unsigned short vdsc3texta3;
    unsigned short vdsc3texta4;

    unsigned short vdsc3texta5;
    unsigned short vdsc3texta6;

    unsigned short vdsc3texta7;
    unsigned short vdesctextb1;

    unsigned short vdesctextb2;
    unsigned short vdesctextb3;

    unsigned short vdesctextb4;
    unsigned short vdesctextb5;

    unsigned short vdesctextb6;
    unsigned short vdsc2textb1;

    unsigned short vdsc2textb2;
    unsigned short vdsc2textb3;

    unsigned short vdsc2textb4;
    unsigned short vdsc3textb1;

    unsigned short vdsc3textb2;
    unsigned short vdsc3textb3;

    unsigned short vdsc3textb4;
    unsigned short vdsc3textb5;

    unsigned short vdsc3textb6;
    unsigned short vdsc3textb7;
    ////////////////////////////////////////////

    //char acPadding4[136];
    unsigned int vdesccalca1;   //skilldesccode
    unsigned int vdesccalca2;
    unsigned int vdesccalca3;
    unsigned int vdesccalca4;
    unsigned int vdesccalca5;
    unsigned int vdesccalca6;
    unsigned int vdsc2calca1;
    unsigned int vdsc2calca2;
    unsigned int vdsc2calca3;
    unsigned int vdsc2calca4;
    unsigned int vdsc3calca1;
    unsigned int vdsc3calca2;
    unsigned int vdsc3calca3;
    unsigned int vdsc3calca4;
    unsigned int vdsc3calca5;
    unsigned int vdsc3calca6;
    unsigned int vdsc3calca7;

    unsigned int vdesccalcb1;
    unsigned int vdesccalcb2;
    unsigned int vdesccalcb3;
    unsigned int vdesccalcb4;
    unsigned int vdesccalcb5;
    unsigned int vdesccalcb6;
    unsigned int vdsc2calcb1;
    unsigned int vdsc2calcb2;
    unsigned int vdsc2calcb3;
    unsigned int vdsc2calcb4;
    unsigned int vdsc3calcb1;
    unsigned int vdsc3calcb2;
    unsigned int vdsc3calcb3;
    unsigned int vdsc3calcb4;
    unsigned int vdsc3calcb5;
    unsigned int vdsc3calcb6;
    unsigned int vdsc3calcb7;
} ST_LINE_INFO;

typedef struct
{
    char vskilldesc[64];
    unsigned short vstrmyspname;
} ST_SKILL_DESC;

static unsigned int m_iSkillDescCount = 0;
static unsigned int m_iSkillDescHaveEmpty = 0;
static ST_SKILL_DESC *m_astSkillDesc = NULL;

MODULE_SETLINES_FUNC(m_astSkillDesc, ST_SKILL_DESC);
MODULE_HAVENAME_FUNC(m_astSkillDesc, vskilldesc, m_iSkillDescCount);

static char *SkillDesc_GetDesc(unsigned int id)
{
    if ( id < m_iSkillDescCount )
    {
        return m_astSkillDesc[id].vskilldesc;
    }

    if ( id == -1 && m_iSkillDescHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static unsigned int SkillDesc_GetString(unsigned int id)
{
    if ( id < m_iSkillDescCount )
    {
        return m_astSkillDesc[id].vstrmyspname;
    }

    return 0xFFFF;
}

static int SkillDesc_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "skilldesc") )
    {
        if ( !String_BuildName(FORMAT(skilldesc), pstLineInfo->vstrmyspname, pcTemplate, NULL, pstLineInfo->vskilldesc, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vskilldesc);
        }

        m_astSkillDesc[pstLineInfo->vskilldesc].vstrmyspname = pstLineInfo->vstrmyspname;
        strncpy(m_astSkillDesc[pstLineInfo->vskilldesc].vskilldesc, acOutput, sizeof(m_astSkillDesc[pstLineInfo->vskilldesc].vskilldesc));
        String_Trim(m_astSkillDesc[pstLineInfo->vskilldesc].vskilldesc);
        m_iSkillDescHaveEmpty |= !m_astSkillDesc[pstLineInfo->vskilldesc].vskilldesc[0];

        m_iSkillDescCount++;
        return 1;
    }

    return 0;
}

static int SkillDesc_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "ListRow") )
    {
        if ( 0xFF == pstLineInfo->vListRow )
        {
            strcpy(acOutput, "-1");
            return 1;
        }
    }

    return 0;
}

static void SkillDesc_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skilldesc, SKILLDESC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillPage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillRow, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillColumn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ListRow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ListPool, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IconCel, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strmyspname, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strmyspshort, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strmysplong, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strmyspalt, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strmyspmana, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descdam, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descatt, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p1dmelem, ELEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p2dmelem, ELEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p3dmelem, ELEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descmissile1, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descmissile2, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descmissile3, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descline6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2line1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2line2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2line3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2line4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3line7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta5, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctexta6, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2texta1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2texta2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2texta3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2texta4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta5, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta6, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3texta7, TBL_STRING2);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb5, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desctextb6, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2textb1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2textb2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2textb3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2textb4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb1, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb2, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb3, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb4, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb5, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb6, TBL_STRING2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3textb7, TBL_STRING2);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ddammyspcalc1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ddammyspcalc2, DESCCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p1dmmin, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p2dmmin, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p3dmmin, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p1dmmax, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p2dmmax, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, p3dmmax, DESCCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca5, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalca6, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calca1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calca2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calca3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calca4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca5, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca6, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calca7, DESCCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb5, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, desccalcb6, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calcb1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calcb2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calcb3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc2calcb4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb1, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb2, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb3, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb4, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb5, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb6, DESCCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dsc3calcb7, DESCCODE);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);
}

int process_skilldesc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            SkillDesc_InitValueMap(pstValueMap, pstLineInfo);

            m_iSkillDescCount = 0;
            Lookup_SkillDesc = SkillDesc_GetDesc;
            Lookup_SkillDescString = SkillDesc_GetString;

            m_stCallback.pfnConvertValue = SkillDesc_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skilldesccode, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            SkillDesc_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = SkillDesc_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


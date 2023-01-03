#include "../global.h"

#define FILE_PREFIX "Properties"
#define NAME_PREFIX "pr"


typedef struct
{// total 46 bytes
    unsigned short vcode;
    unsigned char vset1;
    unsigned char vset2;

    unsigned char vset3;
    unsigned char vset4;
    unsigned char vset5;
    unsigned char vset6;

    unsigned char vset7;
    unsigned char vpad0x09;
    unsigned short vval1;

    unsigned short vval2;
    unsigned short vval3;

    unsigned short vval4;
    unsigned short vval5;

    unsigned short vval6;
    unsigned short vval7;

    unsigned char vfunc1;
    unsigned char vfunc2;
    unsigned char vfunc3;
    unsigned char vfunc4;

    unsigned char vfunc5;
    unsigned char vfunc6;
    unsigned char vfunc7;
    unsigned char vpad0x1F;

    unsigned short vstat1;
    unsigned short vstat2;

    unsigned short vstat3;
    unsigned short vstat4;

    unsigned short vstat5;
    unsigned short vstat6;

    unsigned short vstat7;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vcode[64];
} ST_PROPERTY;

static char *m_apcNotUsed[] =
{
    "*done",
    "*desc",
    "*param",
    "*min",
    "*max",
    "*notes",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iPropertyCount = 0;
static unsigned int m_iPropertyHaveEmpty = 0;
static ST_PROPERTY *m_astProperty = NULL;

MODULE_SETLINES_FUNC(m_astProperty, ST_PROPERTY);
MODULE_HAVENAME_FUNC(m_astProperty, vcode, m_iPropertyCount);

char *Properties_GetProperty(unsigned int id)
{
    if ( id < m_iPropertyCount )
    {
        return m_astProperty[id].vcode;
    }

    if ( id == -1 && m_iPropertyHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Properties_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        if ( !String_BuildName(FORMAT(properties), ItemStatCost_GetPropertyString(&pstLineInfo->vstat1), pcTemplate, Lookup_ItemStatCost(pstLineInfo->vstat1), pstLineInfo->vcode, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vcode);
        }

        strncpy(m_astProperty[pstLineInfo->vcode].vcode, acOutput, sizeof(m_astProperty[pstLineInfo->vcode].vcode));
        String_Trim(m_astProperty[pstLineInfo->vcode].vcode);
        m_iPropertyHaveEmpty |= !m_astProperty[pstLineInfo->vcode].vcode[0];

        m_iPropertyCount++;
        return 1;
    }

    return 0;
}

static void Properties_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func7, UCHAR);

    if ( isRoSActive() ) {
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, ShowRange, pad0x1F, UCHAR);
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat5, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat6, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat7, ITEMSTAT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_properties(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_PROPERTIES_109) )
    {
        return process_properties109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(RoS, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(PropertiesExt, acTemplatePath, acBinPath, acTxtPath);
            Properties_InitValueMap(pstValueMap, pstLineInfo);

            m_iPropertyCount = 0;
            Lookup_Property = Properties_GetProperty;

            m_stCallback.pfnConvertValue = Properties_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            if ( isD2SigmaActive() )
            {
                m_stCallback.pfnFieldProc = PropertiesExt_ExternProc;
                m_stCallback.ppcKeyInternalProcess = PropertiesExt_ExternList;
            }

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


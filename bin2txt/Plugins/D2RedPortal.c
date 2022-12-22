#include "../global.h"

#define FILE_PREFIX "D2RedPortal"
#define NAME_PREFIX "rp"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vsrcLvl;
    unsigned int vdestLvl;
    unsigned int vobject;

    unsigned short vop1;
    unsigned short vstat1; // itemstat
    int vparam1;
    int vvalue1;

    unsigned short vop2;
    unsigned short vstat2; // itemstat
    int vparam2;
    int vvalue2;

    unsigned short vop3;
    unsigned short vstat3; // itemstat
    int vparam3;
    int vvalue3;

    unsigned short vop4;
    unsigned short vstat4; // itemstat
    int vparam4;
    int vvalue4;
} ST_LINE_INFO_V2;

typedef struct
{
    unsigned short vSourceLvl;
    unsigned short vTargetLvl;

    unsigned short vstat1Item; // itemstat
    int vval1Item;
    unsigned short vstat2Item; // itemstat
    int vval2Item;
    unsigned short vstat3Item; // itemstat
    int vval3Item;
    unsigned short vstat4Item; // itemstat
    int vval4Item;

    unsigned short vstat1Char; // itemstat
    int vval1Char;
    unsigned short vstat2Char; // itemstat
    int vval2Char;
    unsigned short vstat3Char; // itemstat
    int vval3Char;
    unsigned short vstat4Char; // itemstat
    int vval4Char;
} ST_LINE_INFO_V1;
#pragma pack(pop)

static char *m_apcInternalProcess_V1[] =
{
    "*desc",
    "*ID",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int D2RedPortal_FieldProc_V1(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_V1 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(D2RedPortal), 0xFFFF, pcTemplate, Levels_GetLevelName(pstLineInfo->vSourceLvl), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "*ID") )
    {
        if ( !String_BuildName(FORMAT(D2RedPortal), 0xFFFF, pcTemplate, Levels_GetLevelName(pstLineInfo->vTargetLvl), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_D2RedPortal_V2(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_V2 *pstLineInfo = (ST_LINE_INFO_V2 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srcLvl, UINT_ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, destLvl, UINT_ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, object, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value1, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value2, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value3, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value4, UINT_ITEMCODE);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_D2RedPortal_V1(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_V1 *pstLineInfo = (ST_LINE_INFO_V1 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SourceLvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetLvl, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1Item, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val1Item, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2Item, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val2Item, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3Item, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val3Item, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4Item, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val4Item, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1Char, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val1Char, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2Char, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val2Char, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3Char, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val3Char, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4Char, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val4Char, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;
    m_stCallback.pfnFieldProc = D2RedPortal_FieldProc_V1;
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess_V1;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_D2RedPortal(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_V1) )
            {
                MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize == sizeof(ST_LINE_INFO_V2) )
            {
                MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
                return ItemsCode_ParseBin(acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_INIT:

            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_V1) )
            {
                return process_D2RedPortal_V1(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize == sizeof(ST_LINE_INFO_V2) )
            {
                return process_D2RedPortal_V2(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize > 0 )
            {
                my_printf("Unknown version of D2RedPortal\n");
            }
            break;

        default:
            break;
    }

    return 1;
}


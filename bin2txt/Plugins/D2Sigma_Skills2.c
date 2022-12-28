#include "../global.h"

#define FILE_PREFIX "Skills2"

#pragma pack(push, 1)
typedef struct
{
    int vAuraStatParam1;
    int vAuraStatParam2;
    int vAuraStatParam3;
    int vAuraStatParam4;
    int vAuraStatParam5;
    int vAuraStatParam6;

    int vPassiveStatParam1;
    int vPassiveStatParam2;
    int vPassiveStatParam3;
    int vPassiveStatParam4;
    int vPassiveStatParam5;

    unsigned char vDelayGroup;
    unsigned char vBaseSynergy;
    unsigned char vStaticDamage;
    unsigned short vmaxlevel;
    unsigned char vnoitemdesc;
} ST_LINE_INFO;
#pragma pack(pop)

static unsigned int m_iLines = 0;
static ST_LINE_INFO *m_astLines = NULL;

MODULE_SETLINES_FUNC(m_astLines, ST_LINE_INFO);

char *Skills2_ExternList[] =
{
    "Id",
    "AuraStatParam1",
    "AuraStatParam2",
    "AuraStatParam3",
    "AuraStatParam4",
    "AuraStatParam5",
    "AuraStatParam6",
    "PassiveStatParam1",
    "PassiveStatParam2",
    "PassiveStatParam3",
    "PassiveStatParam4",
    "PassiveStatParam5",
    "DelayGroup",
    "BaseSynergy",
    "StaticDamage",
    "maxlevel",
    "noitemdesc",
    NULL,
};

int Skills2_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( iLineNo >= m_iLines )
    {
        return 0;
    }
    else if ( !stricmp(acKey, "AuraStatParam1") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam1, acOutput);
    }
    else if ( !stricmp(acKey, "AuraStatParam2") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam2, acOutput);
    }
    else if ( !stricmp(acKey, "AuraStatParam3") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam3, acOutput);
    }
    else if ( !stricmp(acKey, "AuraStatParam4") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam4, acOutput);
    }
    else if ( !stricmp(acKey, "AuraStatParam5") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam5, acOutput);
    }
    else if ( !stricmp(acKey, "AuraStatParam6") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vAuraStatParam6, acOutput);
    }
    else if ( !stricmp(acKey, "PassiveStatParam1") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vPassiveStatParam1, acOutput);
    }
    else if ( !stricmp(acKey, "PassiveStatParam2") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vPassiveStatParam2, acOutput);
    }
    else if ( !stricmp(acKey, "PassiveStatParam3") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vPassiveStatParam3, acOutput);
    }
    else if ( !stricmp(acKey, "PassiveStatParam4") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vPassiveStatParam4, acOutput);
    }
    else if ( !stricmp(acKey, "PassiveStatParam5") )
    {
        return process_value(EN_VALUE_INT, 4, &m_astLines[iLineNo].vPassiveStatParam5, acOutput);
    }
    else if ( !stricmp(acKey, "DelayGroup") )
    {
        return process_value(EN_VALUE_UCHAR, 1, &m_astLines[iLineNo].vDelayGroup, acOutput);
    }
    else if ( !stricmp(acKey, "BaseSynergy") )
    {
        return process_value(EN_VALUE_UCHAR, 1, &m_astLines[iLineNo].vBaseSynergy, acOutput);
    }
    else if ( !stricmp(acKey, "StaticDamage") )
    {
        return process_value(EN_VALUE_UCHAR, 1, &m_astLines[iLineNo].vStaticDamage, acOutput);
    }
    else if ( !stricmp(acKey, "maxlevel") )
    {
        return process_value(EN_VALUE_UCHAR, 1, &m_astLines[iLineNo].vmaxlevel, acOutput);
    }
    else if ( !stricmp(acKey, "noitemdesc") )
    {
        return process_value(EN_VALUE_UCHAR, 1, &m_astLines[iLineNo].vnoitemdesc, acOutput);
    }

    return 0;
}

static int Skills2_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "AuraStatParam1") )
    {
        memcpy(&m_astLines[m_iLines++], pvLineInfo, sizeof(ST_LINE_INFO));
    }

    return 0;
}

int process_Skills2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AuraStatParam6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PassiveStatParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PassiveStatParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PassiveStatParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PassiveStatParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PassiveStatParam5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DelayGroup, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseSynergy, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaticDamage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, noitemdesc, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(CellFiles, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_EXTENSION;
            m_stCallback.pfnConvertValue = Skills2_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


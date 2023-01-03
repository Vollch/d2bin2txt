#include "../global.h"

#define FILE_PREFIX "KillExp"
#define NAME_PREFIX "ke"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vamaVsWeakMon;
    unsigned short vamaVsStrongMon;
    unsigned short vamaVsWeakMonmybr1Nmybr2;
    unsigned short vamaVsStrongMonmybr1Nmybr2;
    unsigned short vamaVsWeakMonmybr1Hmybr2;
    unsigned short vamaVsStrongMonmybr1Hmybr2;

    unsigned short vsorVsWeakMon;
    unsigned short vsorVsStrongMon;
    unsigned short vsorVsWeakMonmybr1Nmybr2;
    unsigned short vsorVsStrongMonmybr1Nmybr2;
    unsigned short vsorVsWeakMonmybr1Hmybr2;
    unsigned short vsorVsStrongMonmybr1Hmybr2;

    unsigned short vnecVsWeakMon;
    unsigned short vnecVsStrongMon;
    unsigned short vnecVsWeakMonmybr1Nmybr2;
    unsigned short vnecVsStrongMonmybr1Nmybr2;
    unsigned short vnecVsWeakMonmybr1Hmybr2;
    unsigned short vnecVsStrongMonmybr1Hmybr2;

    unsigned short vpalVsWeakMon;
    unsigned short vpalVsStrongMon;
    unsigned short vpalVsWeakMonmybr1Nmybr2;
    unsigned short vpalVsStrongMonmybr1Nmybr2;
    unsigned short vpalVsWeakMonmybr1Hmybr2;
    unsigned short vpalVsStrongMonmybr1Hmybr2;

    unsigned short vbarVsWeakMon;
    unsigned short vbarVsStrongMon;
    unsigned short vbarVsWeakMonmybr1Nmybr2;
    unsigned short vbarVsStrongMonmybr1Nmybr2;
    unsigned short vbarVsWeakMonmybr1Hmybr2;
    unsigned short vbarVsStrongMonmybr1Hmybr2;

    unsigned short vdruVsWeakMon;
    unsigned short vdruVsStrongMon;
    unsigned short vdruVsWeakMonmybr1Nmybr2;
    unsigned short vdruVsStrongMonmybr1Nmybr2;
    unsigned short vdruVsWeakMonmybr1Hmybr2;
    unsigned short vdruVsStrongMonmybr1Hmybr2;

    unsigned short vassVsWeakMon;
    unsigned short vassVsStrongMon;
    unsigned short vassVsWeakMonmybr1Nmybr2;
    unsigned short vassVsStrongMonmybr1Nmybr2;
    unsigned short vassVsWeakMonmybr1Hmybr2;
    unsigned short vassVsStrongMonmybr1Hmybr2;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Difference",
    NULL,
};

static int KillExp_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Difference") )
    {
        if ( !String_BuildName(FORMAT(KillExp), 0xFFFF, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_KillExp(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,amaVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,sorVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,necVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,palVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,barVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,druVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsWeakMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsStrongMon, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsWeakMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsStrongMonmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsWeakMonmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,assVsStrongMonmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = KillExp_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "MonLvl"
#define NAME_PREFIX "mv"

typedef struct
{
    unsigned int vAC;
    unsigned int vACmybr1Nmybr2;
    unsigned int vACmybr1Hmybr2;

    unsigned int vLmysubAC;
    unsigned int vLmysubACmybr1Nmybr2;
    unsigned int vLmysubACmybr1Hmybr2;

    unsigned int vTH;
    unsigned int vTHmybr1Nmybr2;
    unsigned int vTHmybr1Hmybr2;

    unsigned int vLmysubTH;
    unsigned int vLmysubTHmybr1Nmybr2;
    unsigned int vLmysubTHmybr1Hmybr2;

    unsigned int vHP;
    unsigned int vHPmybr1Nmybr2;
    unsigned int vHPmybr1Hmybr2;

    unsigned int vLmysubHP;
    unsigned int vLmysubHPmybr1Nmybr2;
    unsigned int vLmysubHPmybr1Hmybr2;

    unsigned int vDM;
    unsigned int vDMmybr1Nmybr2;
    unsigned int vDMmybr1Hmybr2;

    unsigned int vLmysubDM;
    unsigned int vLmysubDMmybr1Nmybr2;
    unsigned int vLmysubDMmybr1Hmybr2;

    unsigned int vXP;
    unsigned int vXPmybr1Nmybr2;
    unsigned int vXPmybr1Hmybr2;

    unsigned int vLmysubXP;
    unsigned int vLmysubXPmybr1Nmybr2;
    unsigned int vLmysubXPmybr1Hmybr2;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Level",
    NULL,
};

static int MonLvl_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Level") )
    {
        if ( !String_BuildName(FORMAT(monlvl), 0xFFFF, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_monlvl(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubAC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubACmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubACmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TH, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, THmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, THmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTH, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTHmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTHmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DM, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DMmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DMmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDM, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDMmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDMmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXPmybr1Hmybr2, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = MonLvl_FieldProc;
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


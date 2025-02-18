#include "../global.h"

#define FILE_PREFIX "MonMode"

typedef struct
{
    unsigned char vname[32];
    unsigned char vtoken[20];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vtoken[20];
} ST_MONMODE;

static char *m_apcInternalProcess[] =
{
    "code",
    NULL,
};

static unsigned int m_iMonModeCount = 0;
static unsigned int m_iMonModeHaveEmpty = 0;
static ST_MONMODE *m_astMonMode = NULL;

MODULE_SETLINES_FUNC(m_astMonMode, ST_MONMODE);

static char *MonMode_GetCode(unsigned int id)
{
    if ( id < m_iMonModeCount )
    {
        return m_astMonMode[id].vtoken;
    }

    if ( id == -1 && m_iMonModeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonMode_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        char acName[21] = {0};
        strncpy(acName, pstLineInfo->vtoken, sizeof(pstLineInfo->vtoken));

        if ( !String_BuildName(FORMAT(monmode), 0xFFFF, pcTemplate, acName, m_iMonModeCount, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vtoken, sizeof(pstLineInfo->vtoken));
        }

        strncpy(m_astMonMode[m_iMonModeCount].vtoken, acOutput, sizeof(m_astMonMode[m_iMonModeCount].vtoken));
        String_Trim(m_astMonMode[m_iMonModeCount].vtoken);
        m_iMonModeHaveEmpty |= !m_astMonMode[m_iMonModeCount].vtoken[0];

        m_iMonModeCount++;
        return 1;
    }

    return 0;
}

static char *MonMode_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vtoken);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_monmode(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, token, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iMonModeCount = 0;
            Lookup_MonMode = MonMode_GetCode;

            m_stCallback.pfnFieldProc = MonMode_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            //m_stCallback.pfnGetKey = MonMode_GetKey;
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

#include "../global.h"

#define FILE_PREFIX "PlrMode"

typedef struct
{
    unsigned char vName[32];
    unsigned char vToken[20];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vToken[20];
} ST_PLRMODE;

static char *m_apcInternalProcess[] =
{
    "Code",
    NULL,
};

static unsigned int m_iPlrModeCount = 0;
static unsigned int m_iPlrModeHaveEmpty = 0;
static ST_PLRMODE *m_astPlrMode = NULL;

MODULE_SETLINES_FUNC(m_astPlrMode, ST_PLRMODE);

static char *PlrMode_GetCode(unsigned int id)
{
    if ( id < m_iPlrModeCount )
    {
        return m_astPlrMode[id].vToken;
    }

    if ( id == -1 && m_iPlrModeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int PlrMode_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp("Code", acKey) )
    {
        char acName[21] = {0};
        strncpy(acName, pstLineInfo->vToken, sizeof(pstLineInfo->vToken));

        if ( !String_BuildName(FORMAT(plrmode), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            strcpy(acOutput, pstLineInfo->vToken);
        }

        strncpy(m_astPlrMode[m_iPlrModeCount].vToken, acOutput, sizeof(m_astPlrMode[m_iPlrModeCount].vToken));
        String_Trim(m_astPlrMode[m_iPlrModeCount].vToken);
        m_iPlrModeHaveEmpty |= !m_astPlrMode[m_iPlrModeCount].vToken[0];

        m_iPlrModeCount++;
        return 1;
    }

    return 0;
}

static char *PlrMode_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vToken);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_plrmode(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Token, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iPlrModeCount = 0;
            Lookup_PlrMode = PlrMode_GetCode;

            m_stCallback.pfnFieldProc = PlrMode_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            //m_stCallback.pfnGetKey = PlrMode_GetKey;
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

#include "global.h"

#define FILE_PREFIX "bodylocs"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_BODY_LOCS;

static char *m_apcInternalProcess[] =
{
    "Body Location",
    NULL,
};

static unsigned int m_iBodyLocs = 0;
static ST_BODY_LOCS *m_astBodyLocs = NULL;

MODULE_SETLINES_FUNC(m_astBodyLocs, ST_BODY_LOCS);

static int BodyLocs_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Body Location") )
    {
        strncpy(m_astBodyLocs[m_iBodyLocs].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(bodylocs), 0xFFFF, pcTemplate, m_astBodyLocs[m_iBodyLocs].vCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        String_Trim(m_astBodyLocs[m_iBodyLocs].vCode);
        m_iBodyLocs++;
        return 1;
    }

    return 0;
}

static char *BodyLocs_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_bodylocs(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE_3(pstValueMap, pstLineInfo, myastEOL, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iBodyLocs = 0;

            //m_stCallback.pfnGetKey = BodyLocs_GetKey;
            m_stCallback.pfnFieldProc = BodyLocs_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
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

char *BodyLocs_GetLocStr(unsigned int id)
{
    if ( id >= m_iBodyLocs )
    {
        return NULL;
    }

    return m_astBodyLocs[id].vCode;
}


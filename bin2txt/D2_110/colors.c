#include "../global.h"

#define FILE_PREFIX "Colors"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_COLORS;

static char *m_apcInternalProcess[] =
{
    "Transform Color",
    NULL,
};

static unsigned int m_iColorCount = 0;
static unsigned int m_iColorHaveEmpty = 0;
static ST_COLORS *m_astColors = NULL;

MODULE_SETLINES_FUNC(m_astColors, ST_COLORS);

static char *Colors_GetColorCode(unsigned int id)
{
    if ( id < m_iColorCount )
    {
        return m_astColors[id].vCode;
    }

    if ( id == -1 && m_iColorHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Colors_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Transform Color") )
    {
        strncpy(m_astColors[m_iColorCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astColors[m_iColorCount].vCode);
        m_iColorHaveEmpty |= !m_astColors[m_iColorCount].vCode[0];

        if ( !String_BuildName(FORMAT(colors), 0xFFFF, pcTemplate, m_astColors[m_iColorCount].vCode, m_iColorCount, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        m_iColorCount++;
        return 1;
    }

    return 0;
}

static char *Colors_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_colors(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iColorCount = 0;
            Lookup_Color = Colors_GetColorCode;

            //m_stCallback.pfnGetKey = Colors_GetKey;
            m_stCallback.pfnFieldProc = Colors_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
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

#include "../global.h"

#define FILE_PREFIX "Properties"

typedef struct
{
    char vCode[64];
} ST_PROPERTY;

static unsigned int m_iPropertyCount = 0;
static unsigned int m_iPropertyHaveEmpty = 0;
static ST_PROPERTY *m_astProperty = NULL;

static char *m_apcNotUsed[] =
{
    "Done",
    "ModFuncOffset",
    "Description",
    "Param",
    "Min",
    "Max",
    "Additional Notes",
    NULL,
};

MODULE_SETLINES_FUNC(m_astProperty, ST_PROPERTY);

static char *Properties_GetProperty(unsigned int id)
{
    if ( id < m_iPropertyCount )
    {
        return m_astProperty[id].vCode;
    }

    if ( id == -1 && m_iPropertyHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Properties_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_PROPERTIES_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Code") )
    {
        if ( !strncmp(pcTemplate, pstLineInfo->vCode, sizeof(pstLineInfo->vCode)) )
        {
            strncpy(acOutput, pcTemplate, sizeof(m_astProperty[m_iPropertyCount].vCode));
        }
        else
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        strncpy(m_astProperty[m_iPropertyCount].vCode, acOutput, sizeof(m_astProperty[m_iPropertyCount].vCode));
        String_Trim(m_astProperty[m_iPropertyCount].vCode);
        m_iPropertyHaveEmpty |= !m_astProperty[m_iPropertyCount].vCode[0];

        m_iPropertyCount++;
        return 1;
    }

    return 0;
}

int process_properties109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_PROPERTIES_109 *pstLineInfo = (ST_PROPERTIES_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iPropertyCount = 0;
            Lookup_Property = Properties_GetProperty;

            m_stCallback.pfnConvertValue = Properties_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

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

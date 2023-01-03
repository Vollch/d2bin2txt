#include "../global.h"

#define FILE_PREFIX "ElemTypes"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_ELEM_TYPES;

static char *m_apcInternalProcess[] =
{
    "Elemental Type",
    NULL,
};

static unsigned int m_iElemTypesCount = 0;
static unsigned int m_iElemTypesHaveEmpty = 0;
static ST_ELEM_TYPES *m_astElemTypes = NULL;

MODULE_SETLINES_FUNC(m_astElemTypes, ST_ELEM_TYPES);

static char *ElemTypes_GetElemStr(unsigned int id)
{
    if ( id < m_iElemTypesCount )
    {
        return m_astElemTypes[id].vCode;
    }

    if ( id == -1 && m_iElemTypesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int ElemTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Elemental Type") )
    {
        strncpy(m_astElemTypes[m_iElemTypesCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astElemTypes[m_iElemTypesCount].vCode);
        m_iElemTypesHaveEmpty |= !m_astElemTypes[m_iElemTypesCount].vCode[0];

        if ( !String_BuildName(FORMAT(elemtypes), 0xFFFF, pcTemplate, m_astElemTypes[m_iElemTypesCount].vCode, m_iElemTypesCount, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        m_iElemTypesCount++;
        return 1;
    }

    return 0;
}

static char *ElemTypes_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_elemtypes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);
    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myastEOL, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iElemTypesCount = 0;
            Lookup_ElemType = ElemTypes_GetElemStr;

            //m_stCallback.pfnGetKey = ElemTypes_GetKey;
            m_stCallback.pfnFieldProc = ElemTypes_FieldProc;
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

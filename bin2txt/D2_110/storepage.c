#include "../global.h"

#define FILE_PREFIX "storepage"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_STORE_PAGE;

static unsigned int m_iStorePageCount = 0;
static unsigned int m_iStorePageHaveEmpty = 0;
static ST_STORE_PAGE *m_astStorePage = NULL;

static char *m_apcInternalProcess[] =
{
    "Store Page",
    NULL,
};

MODULE_SETLINES_FUNC(m_astStorePage, ST_STORE_PAGE);

static char *StorePage_GetCode(unsigned int id)
{
    if ( id < m_iStorePageCount )
    {
        return m_astStorePage[id].vCode;
    }

    if ( id == -1 && m_iStorePageHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int StorePage_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Store Page") )
    {
        strncpy(m_astStorePage[m_iStorePageCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astStorePage[m_iStorePageCount].vCode);
        m_iStorePageHaveEmpty |= !m_astStorePage[m_iStorePageCount].vCode[0];

        if ( !String_BuildName(FORMAT(storepage), 0xFFFF, pcTemplate, m_astStorePage[m_iStorePageCount].vCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        m_iStorePageCount++;
        return 1;
    }

    return 0;
}

static char *StorePage_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_storepage(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iStorePageCount = 0;
            Lookup_Store = StorePage_GetCode;

            //m_stCallback.pfnGetKey = StorePage_GetKey;
            m_stCallback.pfnFieldProc = StorePage_FieldProc;
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

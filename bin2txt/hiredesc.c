#include "global.h"

#define FILE_PREFIX "hiredesc"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    ST_LINE_INFO sLineInfo;

    unsigned short vNameStr;
} ST_LINE_INFO_MERCDESC;

typedef struct
{
    char vCode[5];
} ST_HIRE_DESC;

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iHireDesc = 0;
static ST_HIRE_DESC *m_astHireDesc = NULL;

static char *m_apcInternalProcess[] =
{
    "Hireling Description",
    NULL,
};

MODULE_SETLINES_FUNC(m_astHireDesc, ST_HIRE_DESC);

char *HireDesc_GetDesc(unsigned int id)
{
    if ( id >= m_iHireDesc )
    {
        return NULL;
    }

    return m_astHireDesc[id].vCode;
}

static int HireDesc_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Hireling Description") )
    {
        unsigned int uiString = 0xFFFF;
        if ( m_iBinStructSize == sizeof(ST_LINE_INFO_MERCDESC) )
        {
            uiString = ((ST_LINE_INFO_MERCDESC *)pvLineInfo)->vNameStr;
        }

        strncpy(m_astHireDesc[m_iHireDesc].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(hiredesc), uiString, pcTemplate, m_astHireDesc[m_iHireDesc].vCode, m_iHireDesc, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        String_Trim(m_astHireDesc[m_iHireDesc].vCode);
        m_iHireDesc++;
        return 1;
    }

    return 0;
}
static void HireDesc_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    if ( m_iBinStructSize == sizeof(ST_LINE_INFO_MERCDESC) )
    {
        ST_LINE_INFO_MERCDESC *pstLineInfoMD = (ST_LINE_INFO_MERCDESC *)m_acLineInfoBuf;

        VALUE_MAP_DEFINE(pstValueMap, pstLineInfoMD, NameStr, USHORT_STRING);
    }

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myastEOL, EOL);
}

int process_hiredesc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);

            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_MERCDESC) )
            {
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_SELF_DEPEND:
            HireDesc_InitValueMap(pstValueMap, pstLineInfo);

            m_iHireDesc = 0;

            m_stCallback.pfnFieldProc = HireDesc_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, m_iBinStructSize, 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


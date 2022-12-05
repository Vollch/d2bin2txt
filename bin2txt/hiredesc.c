#include "global.h"

#define FILE_PREFIX "hiredesc"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO_D2;

typedef struct
{
    char vCode[4];
    unsigned short vNameStr;
} ST_LINE_INFO_MD;

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
    "*EOL",
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

static int HireDesc_FieldProc_D2(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_D2 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Hireling Description") )
    {
        strncpy(m_astHireDesc[m_iHireDesc].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(hiredesc), 0xFFFF, pcTemplate, m_astHireDesc[m_iHireDesc].vCode, m_iHireDesc, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        String_Trim(m_astHireDesc[m_iHireDesc].vCode);
        m_iHireDesc++;
        return 1;
    }
    else if ( !stricmp(acKey, "*EOL") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int HireDesc_FieldProc_MD(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_MD *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Hireling Description") )
    {
        strncpy(m_astHireDesc[m_iHireDesc].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(hiredesc), pstLineInfo->vNameStr, pcTemplate, m_astHireDesc[m_iHireDesc].vCode, m_iHireDesc, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        String_Trim(m_astHireDesc[m_iHireDesc].vCode);
        m_iHireDesc++;
        return 1;
    }

    return 0;
}

int process_hiredesc_D2(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_D2 *pstLineInfo = (ST_LINE_INFO_D2 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    m_stCallback.pfnFieldProc = HireDesc_FieldProc_D2;
    m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
    m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_hiredesc_MD(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_MD *pstLineInfo = (ST_LINE_INFO_MD *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameStr, USHORT_STRING);

    m_stCallback.pfnFieldProc = HireDesc_FieldProc_MD;
    m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
    m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_hiredesc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);

            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_MD) )
            {
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iHireDesc = 0;

            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_MD) )
            {
                my_printf("  MercDesc detected, make sure you have \"NameStr\" in hiredesc.txt template\n");
                return process_hiredesc_MD(acTemplatePath, acBinPath, acTxtPath);
            }
            return process_hiredesc_D2(acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


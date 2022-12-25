#include "global.h"

#define FILE_PREFIX "monai"
#define NAME_PREFIX "ma"

typedef struct
{
    unsigned short vAI;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*aip1",
    "*aip2",
    "*aip3",
    "*aip4",
    "*aip5",
    "*aip6",
    "*aip7",
    "*aip8",
    NULL,
};

typedef struct
{
    char vAI[64];
} ST_MON_AI;

static unsigned int m_iMonAiCount = 0;
static ST_MON_AI *m_astMonAi = NULL;

MODULE_SETLINES_FUNC(m_astMonAi, ST_MON_AI);
MODULE_HAVENAME_FUNC(m_astMonAi, vAI, m_iMonAiCount);

static int MonAI_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "AI") )
    {
        if ( !String_BuildName(FORMAT(monai), 0xFFFF, pcTemplate, NAME_PREFIX, pstLineInfo->vAI, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vAI);
        }

        strncpy(m_astMonAi[pstLineInfo->vAI].vAI, acOutput, sizeof(m_astMonAi[pstLineInfo->vAI].vAI));
        m_iMonAiCount++;
        return 1;
    }

    return 0;
}

static char *MonAI_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    memset(pcKey, 0, sizeof(pcKey));
    sprintf(pcKey, "%u", pstLineInfo->vAI);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_monai(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AI, USHORT_MONAI);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iMonAiCount = 0;

            //m_stCallback.pfnGetKey = MonAI_GetKey;
            m_stCallback.pfnConvertValue = MonAI_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
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

char *MonAi_GetAiName(unsigned int id)
{
    if ( id >= m_iMonAiCount )
    {
        return NULL;
    }

    return m_astMonAi[id].vAI;
}


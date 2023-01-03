#include "../global.h"

#define FILE_PREFIX "HitClass"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_HIT_CLASS;

static char *m_apcInternalProcess[] =
{
    "Hit Class",
    NULL,
};

static unsigned int m_iHitClassCount = 0;
static unsigned int m_iHitClassHaveEmpty = 0;
static ST_HIT_CLASS *m_astHitClass = NULL;

MODULE_SETLINES_FUNC(m_astHitClass, ST_HIT_CLASS);

static char *HitClass_GetClassStr(unsigned int id)
{
    if ( id < m_iHitClassCount )
    {
        return m_astHitClass[id].vCode;
    }

    if ( id == -1 && m_iHitClassHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int HitClass_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Hit Class") )
    {
        strncpy(m_astHitClass[m_iHitClassCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astHitClass[m_iHitClassCount].vCode);
        m_iHitClassHaveEmpty |= !m_astHitClass[m_iHitClassCount].vCode[0];

        if ( !String_BuildName(FORMAT(hitclass), 0xFFFF, pcTemplate, m_astHitClass[m_iHitClassCount].vCode, m_iHitClassCount, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        m_iHitClassCount++;
        return 1;
    }

    return 0;
}

static char *HitClass_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_hitclass(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
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
            m_iHitClassCount = 0;
            Lookup_HitClass = HitClass_GetClassStr;

            //m_stCallback.pfnGetKey = HitClass_GetKey;
            m_stCallback.pfnFieldProc = HitClass_FieldProc;
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

#include "../global.h"

#define FILE_PREFIX "PlayerClass"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_PLAYER_CLASS;

static char *m_apcInternalProcess[] =
{
    "Player Class",
    NULL,
};

static unsigned int m_iPlayerClassCount = 0;
static unsigned int m_iPlayerClassHaveEmpty = 0;
static ST_PLAYER_CLASS *m_astPlayerClass = NULL;

MODULE_SETLINES_FUNC(m_astPlayerClass, ST_PLAYER_CLASS);

static char *PlayerClass_GetClass(unsigned int id)
{
    if ( id < m_iPlayerClassCount )
    {
        return m_astPlayerClass[id].vCode;
    }

    if ( id == -1 && m_iPlayerClassHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int PlayerClass_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Player Class") )
    {
        strncpy(m_astPlayerClass[m_iPlayerClassCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astPlayerClass[m_iPlayerClassCount].vCode);
        m_iPlayerClassHaveEmpty |= !m_astPlayerClass[m_iPlayerClassCount].vCode[0];

        if ( !String_BuildName(FORMAT(playerclass), 0xFFFF, pcTemplate, m_astPlayerClass[m_iPlayerClassCount].vCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        m_iPlayerClassCount++;
        return 1;
    }

    return 0;
}

static char *PlayerClass_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_playerclass(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iPlayerClassCount = 0;
            Lookup_Class = PlayerClass_GetClass;

            //m_stCallback.pfnGetKey = PlayerClass_GetKey;
            m_stCallback.pfnFieldProc = PlayerClass_FieldProc;
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

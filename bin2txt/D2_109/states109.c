#include "../global.h"

#define FILE_PREFIX "States"

typedef struct
{
    char vstate[64];
} ST_STATE;

static unsigned int m_iStatesCount = 0;
static unsigned int m_iStatesHaveEmpty = 0;
static ST_STATE *m_astStates = NULL;

MODULE_SETLINES_FUNC(m_astStates, ST_STATE);

static char *States_GetState(unsigned int id)
{
    if ( id < m_iStatesCount )
    {
        return m_astStates[id].vstate;
    }

    if ( id == -1 && m_iStatesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int States_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_STATES_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "state") )
    {
        if ( !strncmp(pcTemplate, pstLineInfo->vstate, sizeof(pstLineInfo->vstate)) )
        {
            strncpy(acOutput, pcTemplate, sizeof(m_astStates[m_iStatesCount].vstate));
        }
        else
        {
            strncpy(acOutput, pstLineInfo->vstate, sizeof(pstLineInfo->vstate));
        }

        strncpy(m_astStates[m_iStatesCount].vstate, acOutput, sizeof(m_astStates[m_iStatesCount].vstate));
        String_Trim(m_astStates[m_iStatesCount].vstate);
        m_iStatesHaveEmpty |= !m_astStates[m_iStatesCount].vstate[0];

        m_iStatesCount++;
        return 1;
    }

    return 0;
}

int process_states109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_STATES_109 *pstLineInfo = (ST_STATES_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iStatesCount = 0;
            Lookup_State = States_GetState;

            m_stCallback.pfnConvertValue = States_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

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

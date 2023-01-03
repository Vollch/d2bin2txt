#include "../global.h"

#define FILE_PREFIX "Events"
#define NAME_PREFIX "ev"

typedef struct
{
    unsigned short vevent;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*desc",
    NULL,
};

typedef struct
{
    char vevent[64];
} ST_EVENTS;

static unsigned int m_iEventsCount = 0;
static unsigned int m_iEventsHaveEmpty = 0;
static ST_EVENTS *m_astEvents = NULL;

MODULE_SETLINES_FUNC(m_astEvents, ST_EVENTS);
MODULE_HAVENAME_FUNC(m_astEvents, vevent, m_iEventsCount);

static char *Events_GetEventName(unsigned int id)
{
    if ( id < m_iEventsCount )
    {
        return m_astEvents[id].vevent;
    }

    if ( id == -1 && m_iEventsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Events_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "event") )
    {
        if ( !String_BuildName(FORMAT(events), 0xFFFF, pcTemplate, NULL, m_iEventsCount, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vevent);
        }

        strncpy(m_astEvents[m_iEventsCount].vevent, acOutput, sizeof(m_astEvents[m_iEventsCount].vevent));
        String_Trim(m_astEvents[m_iEventsCount].vevent);
        m_iEventsHaveEmpty |= !m_astEvents[m_iEventsCount].vevent[0];

        m_iEventsCount++;
        return 1;
    }

    return 0;
}

int process_events(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, event, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iEventsCount = 0;
            Lookup_Event = Events_GetEventName;

            m_stCallback.pfnConvertValue = Events_ConvertValue;
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

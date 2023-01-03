#include "../global.h"

#define FILE_PREFIX "Experience"

static char *m_apcInternalProcess[] =
{
    "Level",
    NULL,
};

static int Experience_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Level") )
    {
        char acName[16] = {0};
        sprintf(acName, "%d", iLineNo - 1);

        if ( !String_BuildName(FORMAT(experience), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%u", iLineNo - 1);
        }

        return 1;
    }

    return 0;
}

static void Experience_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_EXPERIENCE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Amazon, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sorceress, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Necromancer, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Paladin, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Barbarian, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Druid, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Assassin, UINT);
}

int process_experience109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_EXPERIENCE_109 *pstLineInfo = (ST_EXPERIENCE_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            Experience_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Experience_FieldProc;
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


#include "../global.h"

#define FILE_PREFIX "LvlMaze"
#define NAME_PREFIX "lm"

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Beta",
    NULL,
};

static int LvlMaze_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LVLMAZE_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        if ( !String_BuildName(FORMAT(lvlmaze), 0xFFFF, pcTemplate, Lookup_Level(pstLineInfo->vLevel), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

static void LvlMaze_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LVLMAZE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rooms, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Merge, UINT);
}

int process_lvlmaze109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LVLMAZE_109 *pstLineInfo = (ST_LVLMAZE_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            LvlMaze_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = LvlMaze_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


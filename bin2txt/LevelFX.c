#include "global.h"

#define FILE_PREFIX "levelfx"
#define NAME_PREFIX "lx"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vID;
    unsigned char vStarfield;
    unsigned char vSnow;
    unsigned char vParralax;
    unsigned char vLight;
    unsigned int vLightQuestID;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Level Name",
    "end",
    NULL,
};

static int LevelFX_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Level Name") )
    {
        if ( !String_BuildName(FORMAT(LevelFX), 0xFFFF, pcTemplate, Levels_GetLevelName(pstLineInfo->vID), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "end") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_LevelFX(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Starfield, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Snow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parralax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightQuestID, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = LevelFX_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


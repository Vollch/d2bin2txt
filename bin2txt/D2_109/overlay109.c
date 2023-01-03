#include "../global.h"

#define FILE_PREFIX "Overlay"
#define NAME_PREFIX "ol"

static char *m_apcInternalProcess[] =
{
    "Overlay",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Character",
    NULL,
};

static int Overlay_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_OVERLAY_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Overlay") )
    {
        char acName[65] = {0};
        String_StripFileName(pstLineInfo->vFilename, acName, 64);

        if ( !String_BuildName(FORMAT(overlay), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

static void Overlay_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_OVERLAY_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filename, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Frames, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PreDraw, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1ofN, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Open, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beta, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xoffset, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Yoffset, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimRate, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InitRadius, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Radius, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LoopWaitTime, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumDirections, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LocalBlood, UCHAR);
}

int process_overlay109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_OVERLAY_109 *pstLineInfo = (ST_OVERLAY_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            Overlay_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Overlay_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
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


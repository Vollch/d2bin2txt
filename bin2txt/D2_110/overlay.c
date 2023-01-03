#include "../global.h"

#define FILE_PREFIX "Overlay"
#define NAME_PREFIX "ol"


typedef struct
{
    unsigned short voverlay;
    unsigned char vFilename[64];
    unsigned short vversion;

    unsigned int vFrames;

    unsigned char vPreDraw;
    unsigned char pad0x49[3];

    unsigned int v1ofN;

    unsigned char vDir;
    unsigned char vOpen;
    unsigned char vBeta;
    unsigned char pad0x53;

    int vXoffset;
    int vYoffset;
    int vHeight1;
    int vHeight2;
    int vHeight3;
    int vHeight4;
    unsigned int vAnimRate;

    unsigned int vInitRadius;
    unsigned int vRadius;
    unsigned int vLoopWaitTime;

    unsigned char vTrans;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;

    unsigned char vNumDirections;
    unsigned char vLocalBlood;
    unsigned char pad0x82[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned char voverlay[64];
} ST_OVERLAY;

static char *m_apcNotUsed[] =
{
    "Character",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iOverlayCount = 0;
static unsigned int m_iOverlayHaveEmpty = 0;
static ST_OVERLAY *m_astOverlay = NULL;

MODULE_SETLINES_FUNC(m_astOverlay, ST_OVERLAY);
MODULE_HAVENAME_FUNC(m_astOverlay, voverlay, m_iOverlayCount);

static char *Overlay_GetOverlay(unsigned int id)
{
    if ( id < m_iOverlayCount )
    {
        return m_astOverlay[id].voverlay;
    }

    if ( id == -1 && m_iOverlayHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Overlay_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "overlay") )
    {
        char acFile[33] = {0};
        String_StripFileName(pstLineInfo->vFilename, acFile, 32);
        if ( !String_BuildName(FORMAT(overlay), 0xFFFF, pcTemplate, acFile, pstLineInfo->voverlay, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->voverlay);
        }

        strncpy(m_astOverlay[pstLineInfo->voverlay].voverlay, acOutput, sizeof(m_astOverlay[pstLineInfo->voverlay].voverlay));
        String_Trim(m_astOverlay[pstLineInfo->voverlay].voverlay);
        m_iOverlayHaveEmpty |= !m_astOverlay[pstLineInfo->voverlay].voverlay[0];

        m_iOverlayCount++;
        return 1;
    }

    return 0;
}

static void Overlay_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filename, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);
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

int process_overlay(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_OVERLAY_109) )
    {
        return process_overlay109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            Overlay_InitValueMap(pstValueMap, pstLineInfo);

            m_iOverlayCount = 0;
            Lookup_Overlay = Overlay_GetOverlay;

            m_stCallback.pfnConvertValue = Overlay_ConvertValue;
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


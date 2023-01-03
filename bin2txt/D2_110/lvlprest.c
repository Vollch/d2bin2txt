#include "../global.h"

#define FILE_PREFIX "LvlPrest"
#define NAME_PREFIX "lp"

typedef struct
{
    int vDef;
    int vLevelId;
    int vPopulate;
    int vLogicals;
    int vOutdoors;
    int vAnimate;
    int vKillEdge;
    int vFillBlanks;
    int vExpansion;
    unsigned char pad0x24[4];

    int vSizeX;
    int vSizeY;
    int vAutoMap;
    int vScan;
    int vPops;
    int vPopPad;
    int vFiles;

    unsigned char vFile1[60];
    unsigned char vFile2[60];
    unsigned char vFile3[60];
    unsigned char vFile4[60];
    unsigned char vFile5[60];
    unsigned char vFile6[60];

    int vDt1Mask;
} ST_LINE_INFO;

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

static int LvlPrest_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        char acName[33] = {0};
        ( String_StripFileName(pstLineInfo->vFile1, acName, 32) ||
          String_StripFileName(pstLineInfo->vFile2, acName, 32) ||
          String_StripFileName(pstLineInfo->vFile3, acName, 32) ||
          String_StripFileName(pstLineInfo->vFile4, acName, 32) ||
          String_StripFileName(pstLineInfo->vFile5, acName, 32) );
        if ( !String_BuildName(FORMAT(lvlprest), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_lvlprest(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Def, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelId, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Populate, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Logicals, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Outdoors, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Animate, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KillEdge, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FillBlanks, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dt1Mask, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoMap, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Scan, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pops, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PopPad, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Files, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File6, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expansion, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = LvlPrest_FieldProc;
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


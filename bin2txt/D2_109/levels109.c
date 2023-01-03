#include "../global.h"

#define FILE_PREFIX "Levels"
#define BIN_TEMP    "temp_"

typedef struct
{
    char vname[64];
} ST_LEVEL_DESC;

static char *m_apcNotUsed[] =
{
    "Beta",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static unsigned int m_iLevelsCount = 0;
static ST_LEVEL_DESC *m_astLevels = NULL;

MODULE_SETLINES_FUNC(m_astLevels, ST_LEVEL_DESC);

static char *Levels_GetLevelName(unsigned int id)
{
    if ( id >= m_iLevelsCount )
    {
        return NULL;
    }

    return m_astLevels[id].vname;
}

static int Levels_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LEVELS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        char acName[41] = {0};
        strncpy(acName, pstLineInfo->vLevelName, sizeof(pstLineInfo->vLevelName));

        if ( !String_BuildName(FORMAT(levels), 0xFFFF, pcTemplate, acName, pstLineInfo->vId, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vLevelName, sizeof(pstLineInfo->vLevelName));
        }

        strncpy(m_astLevels[pstLineInfo->vId].vname, acOutput, sizeof(m_astLevels[pstLineInfo->vId].vname));
        String_Trim(m_astLevels[pstLineInfo->vId].vname);

        m_iLevelsCount++;
        return 1;
    }

    return 0;
}

static void Levels_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LEVELS_109 *pstLineInfo)
{
    ST_LEVELDEFS_109 *pstLineInfoDefs = (ST_LEVELDEFS_109 *)((char *)pstLineInfo + sizeof(ST_LEVELS_109));
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rain, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mud, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoPer, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsInside, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawEdges, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WarpDist, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1Ex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2Ex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3Ex, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDen, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonWndr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSpcWalk, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mtot, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utot, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M8, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M9, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M10, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M11, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M12, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M13, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M14, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M15, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M16, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M17, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M18, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M19, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M20, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M21, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M22, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M23, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M24, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, M25, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S8, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S9, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S10, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S11, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S12, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S13, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S14, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S15, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S16, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S17, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S18, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S19, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S20, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S21, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S22, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S23, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S24, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S25, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U8, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U9, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U10, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U11, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U12, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U13, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U14, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U15, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U16, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U17, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U18, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U19, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U20, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U21, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U22, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U23, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U24, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, U25, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, C1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, C2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, C3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, C4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, C5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CA1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CA2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CA3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CA4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CA5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CD1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CD2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CD3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CD4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CD5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Waypoint, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelName, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelWarp, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntryFile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Themes, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FloorFilter, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlankScreen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SoundEnv, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Layer, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, OffsetX, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, OffsetY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Depend, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, DrlgType, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, LevelType, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SubType, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SubTheme, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SubWaypoint, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SubShrine, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis0, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Vis7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp0, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Warp7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Intensity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Blue, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Portal, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Position, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SaveMonsters, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, LOSDraw, INT);
}

int process_levels109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LEVELS_109 *pstLineInfo = (ST_LEVELS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;
    char acBinTempFile[256] = {0};

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            File_MergeFiles(acBinPath, "levels", sizeof(ST_LEVELS_109), "leveldefs", sizeof(ST_LEVELDEFS_109), BIN_TEMP FILE_PREFIX);
            Levels_InitValueMap(pstValueMap, pstLineInfo);

            m_iLevelsCount = 0;
            Lookup_Level = Levels_GetLevelName;

            m_stCallback.pfnFieldProc = Levels_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            sprintf(acBinTempFile, "%s\\%s", acBinPath, BIN_TEMP);

            return process_file_special_bin(acTemplatePath, acBinTempFile, acTxtPath, FILE_PREFIX, pstLineInfo,
                (sizeof(ST_LEVELS_109) + sizeof(ST_LEVELDEFS_109)), pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


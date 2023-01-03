#include "../global.h"

#define FILE_PREFIX "Levels"
#define BIN_TEMP    "temp_"
#define NAME_PREFIX "lv"

typedef struct
{
    unsigned short vId;
    unsigned char vPal;
    unsigned char vAct;

    unsigned char vTeleport;
    unsigned char vRain;
    unsigned char vMud;
    unsigned char vNoPer;

    unsigned char vIsInside;
    unsigned char vDrawEdges;
    unsigned short vpad0x0A;

    unsigned int vWarpDist;

    unsigned short vMonLvl1;
    unsigned short vMonLvl2;

    unsigned short vMonLvl3;
    unsigned short vMonLvl1Ex;

    unsigned short vMonLvl2Ex;
    unsigned short vMonLvl3Ex;

    unsigned int vMonDen;
    unsigned int vMonDenmybr1Nmybr2;
    unsigned int vMonDenmybr1Hmybr2;

    unsigned char vMonUMin;
    unsigned char vMonUMinmybr1Nmybr2;
    unsigned char vMonUMinmybr1Hmybr2;
    unsigned char vMonUMax;

    unsigned char vMonUMaxmybr1Nmybr2;
    unsigned char vMonUMaxmybr1Hmybr2;
    unsigned char vMonWndr;
    unsigned char vMonSpcWalk;

    unsigned char vQuest;
    unsigned char vrangedspawn;
    unsigned short vNumMon;

    unsigned char pad0x33[2];
    unsigned short vmon1;   //MonStats

    unsigned short vmon2;
    unsigned short vmon3;

    unsigned short vmon4;
    unsigned short vmon5;

    unsigned short vmon6;
    unsigned short vmon7;

    unsigned short vmon8;
    unsigned short vmon9;

    unsigned short vmon10;
    unsigned short vmon11;

    unsigned short vmon12;
    unsigned short vmon13;

    unsigned short vmon14;
    unsigned short vmon15;

    unsigned short vmon16;
    unsigned short vmon17;

    unsigned short vmon18;
    unsigned short vmon19;

    unsigned short vmon20;
    unsigned short vmon21;

    unsigned short vmon22;
    unsigned short vmon23;

    unsigned short vmon24;
    unsigned short vmon25;

    unsigned short vnmon1;   //MonStats
    unsigned short vnmon2;

    unsigned short vnmon3;
    unsigned short vnmon4;

    unsigned short vnmon5;
    unsigned short vnmon6;

    unsigned short vnmon7;
    unsigned short vnmon8;

    unsigned short vnmon9;
    unsigned short vnmon10;

    unsigned short vnmon11;
    unsigned short vnmon12;

    unsigned short vnmon13;
    unsigned short vnmon14;

    unsigned short vnmon15;
    unsigned short vnmon16;

    unsigned short vnmon17;
    unsigned short vnmon18;

    unsigned short vnmon19;
    unsigned short vnmon20;

    unsigned short vnmon21;
    unsigned short vnmon22;

    unsigned short vnmon23;
    unsigned short vnmon24;

    unsigned short vnmon25;
    unsigned short vumon1;  //monstats

    unsigned short vumon2;
    unsigned short vumon3;

    unsigned short vumon4;
    unsigned short vumon5;

    unsigned short vumon6;
    unsigned short vumon7;

    unsigned short vumon8;
    unsigned short vumon9;

    unsigned short vumon10;
    unsigned short vumon11;

    unsigned short vumon12;
    unsigned short vumon13;

    unsigned short vumon14;
    unsigned short vumon15;

    unsigned short vumon16;
    unsigned short vumon17;

    unsigned short vumon18;
    unsigned short vumon19;

    unsigned short vumon20;
    unsigned short vumon21;

    unsigned short vumon22;
    unsigned short vumon23;

    unsigned short vumon24;
    unsigned short vumon25;

    unsigned short vcmon1;  //monstats
    unsigned short vcmon2;

    unsigned short vcmon3;
    unsigned short vcmon4;

    unsigned short vcpct1;
    unsigned short vcpct2;

    unsigned short vcpct3;
    unsigned short vcpct4;

    unsigned short vcamt4;
    unsigned char pad0xDE[6];

    unsigned char vWaypoint;
    unsigned char vObjGrp0;
    unsigned char vObjGrp1;
    unsigned char vObjGrp2;

    unsigned char vObjGrp3;
    unsigned char vObjGrp4;
    unsigned char vObjGrp5;
    unsigned char vObjGrp6;

    unsigned char vObjGrp7;
    unsigned char vObjPrb0;
    unsigned char vObjPrb1;
    unsigned char vObjPrb2;

    unsigned char vObjPrb3;
    unsigned char vObjPrb4;
    unsigned char vObjPrb5;
    unsigned char vObjPrb6;

    unsigned char vObjPrb7;
    unsigned char vLevelName[40];

    unsigned char vLevelWarp[40];

    unsigned char vEntryFile[40];

    unsigned char pad0x16D[163];

    unsigned int vThemes;
    unsigned int vFloorFilter;
    unsigned int vBlankScreen;
    unsigned int vSoundEnv;
} ST_LINE_LEVELS;

typedef struct
{
    int vQuestFlag;
    int vQuestFlagEx;
    int vLayer;
    int vSizeX;
    int vSizeXmybr1Nmybr2;
    int vSizeXmybr1Hmybr2;
    int vSizeY;
    int vSizeYmybr1Nmybr2;
    int vSizeYmybr1Hmybr2;
    int vOffsetX;

    int vOffsetY;
    int vDepend;

    int vDrlgType;
    int vLevelType;
    int vSubType;

    int vSubTheme;
    int vSubWaypoint;
    int vSubShrine;
    int vVis0;
    int vVis1;

    int vVis2;
    int vVis3;
    int vVis4;
    int vVis5;
    int vVis6;
    int vVis7;
    int vWarp0;
    int vWarp1;
    int vWarp2;
    int vWarp3;

    int vWarp4;
    int vWarp5;
    int vWarp6;
    int vWarp7;

    unsigned char vIntensity;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;

    int vPortal;
    int vPosition;

    unsigned char vSaveMonsters;
    char pad0x95[3];

    int vLOSDraw;
} ST_LINE_LEVELDEFS;

typedef struct
{
    char vname[64];
    unsigned char vAct;
} ST_LEVEL_DESC;

static char *m_apcNotUsed[] =
{
    "camt1",
    "camt2",
    "camt3",
    "Beta",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iLevelsCount = 0;
static ST_LEVEL_DESC *m_astLevels = NULL;

MODULE_SETLINES_FUNC(m_astLevels, ST_LEVEL_DESC);
MODULE_HAVENAME_FUNC(m_astLevels, vname, m_iLevelsCount);

static char *Levels_GetLevelName(unsigned int id)
{
    if ( id < m_iLevelsCount )
    {
        return m_astLevels[id].vname;
    }

    return NULL;
}

static unsigned int Levels_GetAct(unsigned int id)
{
    if ( id < m_iLevelsCount )
    {
        return m_astLevels[id].vAct;
    }

    return 0;
}

static int Levels_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_LEVELS *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        char acName[41] = {0};
        strncpy(acName, pstLineInfo->vLevelName, sizeof(pstLineInfo->vLevelName));

        if ( !String_BuildName(FORMAT(levels), 0xFFFF, pcTemplate, acName, pstLineInfo->vId, MODULE_HAVENAME, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vLevelName, sizeof(pstLineInfo->vLevelName));
        }

        m_astLevels[pstLineInfo->vId].vAct = pstLineInfo->vAct;
        strncpy(m_astLevels[pstLineInfo->vId].vname, acOutput, sizeof(m_astLevels[pstLineInfo->vId].vname));
        String_Trim(m_astLevels[pstLineInfo->vId].vname);

        m_iLevelsCount++;
        return 1;
    }

    return 0;
}

static int Levels_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_LEVELS *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        strncpy(acOutput, m_astLevels[pstLineInfo->vId].vname, sizeof(m_astLevels[pstLineInfo->vId].vname));

        return 1;
    }

    return 0;
}

static int Levels_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_LEVELS *pstLineInfo = pvLineInfo;
    char *pcResult;

    if ( isD2SigmaActive() )
    {
        if ( !stricmp(acKey, "LvlBckg") )
        {
            if ( pcResult = CellFiles_GetName(*(unsigned short *)&pstLineInfo->vEntryFile[7]) )
            {
                strcpy(acOutput, pcResult);
            }

            return 1;
        }
        else if ( !stricmp(acKey, "PortalLevel") )
        {
            if ( pcResult = Lookup_Level(*(unsigned short *)&pstLineInfo->vEntryFile[9]) )
            {
                strcpy(acOutput, pcResult);
            }

            return 1;
        }
    }

    return 0;
}

static void Levels_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_LEVELS *pstLineInfo)
{
    ST_LINE_LEVELDEFS *pstLineInfoDefs = (ST_LINE_LEVELDEFS *)((char *)pstLineInfo + sizeof(ST_LINE_LEVELS));
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Teleport, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mud, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoPer, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsInside, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawEdges, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WarpDist, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1Ex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2Ex, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3Ex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDenmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDenmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMinmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMinmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMaxmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMaxmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonWndr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSpcWalk, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rangedspawn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumMon, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon1, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon2, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon3, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon4, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon5, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon6, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon7, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon8, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon9, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon10, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon11, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon12, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon13, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon14, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon15, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon16, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon17, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon18, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon19, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon20, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon21, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon22, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon23, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon24, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon25, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon1, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon2, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon3, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon4, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon5, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon6, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon7, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon8, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon9, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon10, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon11, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon12, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon13, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon14, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon15, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon16, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon17, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon18, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon19, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon20, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon21, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon22, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon23, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon24, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon25, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon1, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon2, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon3, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon4, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon5, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon6, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon7, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon8, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon9, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon10, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon11, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon12, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon13, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon14, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon15, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon16, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon17, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon18, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon19, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon20, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon21, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon22, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon23, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon24, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon25, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon1, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon2, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon3, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon4, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, camt4, USHORT);

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

    if ( isD2SigmaActive() )
    {
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Stars, Mud, UCHAR);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, EventSound, pad0x0A, 2, SOUND);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, StrLevelName, EntryFile[0], 2, TBL_STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, StrLevelWarp, EntryFile[2], 2, TBL_STRING);
        //VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Name, EntryFile[4], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, isTown, EntryFile[6], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, LvlBckg, EntryFile[7], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, PortalLevel, EntryFile[9], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, PortalMonth, EntryFile[11], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, MinDiff, EntryFile[12], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, NoAutomapWarp, EntryFile[13], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, QuestLock, EntryFile[14], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Tplock, EntryFile[16], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, PortalObject, EntryFile[17], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, LevelReqmyspmybr1Nmybr2, EntryFile[19], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, LevelReqmyspmybr1NMmybr2, EntryFile[20], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, LevelReqmyspmybr1Hmybr2, EntryFile[21], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, AlwaysDisplayName, EntryFile[22], UCHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, GoblinChance, EntryFile[23], USHORT);
    } else {
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntryFile, STRING);
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Themes, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FloorFilter, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlankScreen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SoundEnv, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, QuestFlag, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, QuestFlagEx, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Layer, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeXmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeXmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeYmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SizeYmybr1Hmybr2, INT);
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Portal, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, SaveMonsters, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, Position, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfoDefs, LOSDraw, INT);
}

int process_levels(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_LEVELS *pstLineInfo = (ST_LINE_LEVELS *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;
    char acBinTempFile[256] = {0};

    if ( m_iBinStructSize == sizeof(ST_LEVELS_109) )
    {
        return process_levels109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(CellFiles, acTemplatePath, acBinPath, acTxtPath);
            Levels_InitValueMap(pstValueMap, pstLineInfo);

            m_iLevelsCount = 0;
            Lookup_Level = Levels_GetLevelName;
            Lookup_LevelAct = Levels_GetAct;

            m_stCallback.pfnFieldProc = Levels_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            File_MergeFiles(acBinPath, "levels", sizeof(ST_LINE_LEVELS), "leveldefs", sizeof(ST_LINE_LEVELDEFS), BIN_TEMP FILE_PREFIX);
            sprintf(acBinTempFile, "%s\\%s", acBinPath, BIN_TEMP);

            return process_file_special_bin(acTemplatePath, acBinTempFile, NULL, FILE_PREFIX, pstLineInfo,
                (sizeof(ST_LINE_LEVELS) + sizeof(ST_LINE_LEVELDEFS)), pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            if ( isD2SigmaActive() )
            {
                MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_INIT:
            Levels_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Levels_ConvertValue;
            m_stCallback.pfnFieldProc = Levels_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            sprintf(acBinTempFile, "%s\\%s", acBinPath, BIN_TEMP);

            return process_file_special_bin(acTemplatePath, acBinTempFile, acTxtPath, FILE_PREFIX, pstLineInfo,
                (sizeof(ST_LINE_LEVELS) + sizeof(ST_LINE_LEVELDEFS)), pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

#include "../global.h"

#define FILE_PREFIX "Monstats3"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vBitCombined;
    unsigned char vNameColor;
    unsigned char vAutomapNameColor;
    unsigned char vAutomapVectorColor;
    unsigned char vDrawModeType;
    unsigned short vOverlay1; //overlay
    unsigned short vOverlay2; //overlay
    unsigned short vBossOverlay1; //overlay
    unsigned short vBossOverlay2; //overlay
    unsigned char vBossEventMode; //event
    unsigned short vBossEventMissile1; //Missile
    unsigned short vBossEventMissile2; //Missile
    unsigned short vPortraitGfx;
    unsigned short vAchievement;
    unsigned short vGoblinRarity;
    unsigned short vGoblinMinLevel;
    unsigned short vGoblinMaxLevel;
    unsigned short vGoblinLevelRestrict; //level
    unsigned char vOverlayType;
    unsigned char vNoKillTimestampUpdate;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Name",
    NULL,
};

static int Monstats3_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "GoblinLevelRestrict") )
    {
        char *pcResult = Levels_GetLevelName(pstLineInfo->vGoblinLevelRestrict);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        return 1;
    }
    else if ( !stricmp(acKey, "BossEventMode") )
    {
        char *pcResult = Events_GetEventName(pstLineInfo->vBossEventMode);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        return 1;
    }

    return 0;
}

static int Monstats3_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Name") )
    {
        char *pcResult = MonStats_GetStatsName(iLineNo);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        return 1;
    }

    return 0;
}

int process_Monstats3(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, GoblinRealmOnly, BitCombined, 12, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, RecordDamage, BitCombined, 11, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Goblin, BitCombined, 10, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SpecialLifebar, BitCombined, 9, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, AlterDrawMode, BitCombined, 8, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Boss, BitCombined, 7, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Heroic, BitCombined, 6, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Uber, BitCombined, 5, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Veteran, BitCombined, 4, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Elite, BitCombined, 3, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, AutomapShowName, BitCombined, 2, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Automap, BitCombined, 1, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, NoLifebar, BitCombined, 0, USHORT_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameColor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutomapNameColor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutomapVectorColor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawModeType, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Overlay1, USHORT_OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Overlay2, USHORT_OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BossOverlay1, USHORT_OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BossOverlay2, USHORT_OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BossEventMode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BossEventMissile1, USHORT_MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BossEventMissile2, USHORT_MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PortraitGfx, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Achievement, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GoblinRarity, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GoblinMinLevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GoblinMaxLevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GoblinLevelRestrict, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayType, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoKillTimestampUpdate, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = Monstats3_ConvertValue;
            m_stCallback.pfnFieldProc = Monstats3_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

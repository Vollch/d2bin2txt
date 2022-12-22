#include "../global.h"

#define FILE_PREFIX "Waypoints"
#define NAME_PREFIX "wp"

#pragma pack(push, 1)
typedef struct
{
    unsigned char cPad1;
    unsigned short vLevelID;
    unsigned char vWayptID;
    unsigned char vPage;
    unsigned char vTab;
    unsigned char vRow;
    unsigned short vHeader;
    unsigned char cPad2[2];
    unsigned char vNormal;
    unsigned char vNightmare;
    unsigned char vHell;
    unsigned char vHidden;
    unsigned char vReqDisable;
    unsigned char vOneWay;

    unsigned char vOnlyFrom1;
    unsigned char vOnlyFrom2;
    unsigned char vOnlyFrom3;
    unsigned char vOnlyFrom4;
    unsigned char vOnlyFrom5;

    unsigned char vOnlyTo1;
    unsigned char vOnlyTo2;
    unsigned char vOnlyTo3;
    unsigned char vOnlyTo4;
    unsigned char vOnlyTo5;

    int vEntranceFee;
    int vEntranceFeemybr1Nmybr2;
    int vEntranceFeemybr1Hmybr2;
    int vExitFee;
    int vExitFeemybr1Nmybr2;
    int vExitFeemybr1Hmybr2;

    unsigned char vKeyItem[4];
    unsigned char vKeyItemmybr1Nmybr2[4];
    unsigned char vKeyItemmybr1Hmybr2[4];
    unsigned char vKeyItemEquipped;
    unsigned char vKeyItemEquippedmybr1Nmybr2;
    unsigned char vKeyItemEquippedmybr1Hmybr2;
    unsigned char vKeyItemCarried;
    unsigned char vKeyItemCarriedmybr1Nmybr2;
    unsigned char vKeyItemCarriedmybr1Hmybr2;
    unsigned char vAlwaysNeedKeyItem;
    unsigned char vAlwaysNeedKeyItemmybr1Nmybr2;
    unsigned char vAlwaysNeedKeyItemmybr1Hmybr2;
    unsigned char vDestroyKeyItem;
    unsigned char vDestroyKeyItemmybr1Nmybr2;
    unsigned char vDestroyKeyItemmybr1Hmybr2;

    unsigned short vPenaltyStat;
    unsigned short vPenaltyStatmybr1Nmybr2;
    unsigned short vPenaltyStatmybr1Hmybr2;
    int vPenaltyVal;
    int vPenaltyValmybr1Nmybr2;
    int vPenaltyValmybr1Hmybr2;

    int vLevelReq;
    int vLevelReqmybr1Nmybr2;
    int vLevelReqmybr1Hmybr2;

    unsigned short vStat1;
    unsigned short vStat2;
    unsigned short vStat3;
    unsigned short vStat1mybr1Nmybr2;
    unsigned short vStat2mybr1Nmybr2;
    unsigned short vStat3mybr1Nmybr2;
    unsigned short vStat1mybr1Hmybr2;
    unsigned short vStat2mybr1Hmybr2;
    unsigned short vStat3mybr1Hmybr2;

    int vVal1;
    int vVal2;
    int vVal3;
    int vVal1mybr1Nmybr2;
    int vVal2mybr1Nmybr2;
    int vVal3mybr1Nmybr2;
    int vVal1mybr1Hmybr2;
    int vVal2mybr1Hmybr2;
    int vVal3mybr1Hmybr2;

    unsigned char vReqItem[4];
    unsigned char vReqItemmybr1Nmybr2[4];
    unsigned char vReqItemmybr1Hmybr2[4];
    unsigned char vReqItemEquipped;
    unsigned char vReqItemEquippedmybr1Nmybr2;
    unsigned char vReqItemEquippedmybr1Hmybr2;
    unsigned char vReqItemCarried;
    unsigned char vReqItemCarriedmybr1Nmybr2;
    unsigned char vReqItemCarriedmybr1Hmybr2;
    unsigned char vDestroyReqItem;
    unsigned char vDestroyReqItemmybr1Nmybr2;
    unsigned char vDestroyReqItemmybr1Hmybr2;
} ST_LINE_INFO_131;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
    unsigned short vLevelID;
    unsigned char vWayptID;
    unsigned char vTab;
    unsigned char vHidden;
    unsigned char vNormal;
    unsigned char vNightmare;
    unsigned char vHell;

    unsigned char vUnlockItem[4];
    unsigned char vUnlockItemmybr1Nmybr2[4];
    unsigned char vUnlockItemmybr1Hmybr2[4];
    unsigned char vReqItem[4];
    unsigned char vReqItemmybr1Nmybr2[4];
    unsigned char vReqItemmybr1Hmybr2[4];
    unsigned char vKeyItem[4];
    unsigned char vKeyItemmybr1Nmybr2[4];
    unsigned char vKeyItemmybr1Hmybr2[4];

    unsigned char vKillKeyItem;
    unsigned char vKillKeyItemmybr1Nmybr2;
    unsigned char vKillKeyItemmybr1Hmybr2;
} ST_LINE_INFO_010;
#pragma pack(pop)

static char *m_apcInternalProcess_131[] =
{
    "*LevelName",
    "*Act",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int Waypoints_FieldProc_131(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_131 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*LevelName") )
    {
        if ( !String_BuildName(FORMAT(Waypoints), 0xFFFF, pcTemplate, Levels_GetLevelName(pstLineInfo->vLevelID), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "*Act") )
    {
        sprintf(acOutput, "%u", Levels_GetAct(pstLineInfo->vLevelID));

        return 1;
    }

    return 0;
}

int process_Waypoints_131(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_131 *pstLineInfo = (ST_LINE_INFO_131 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelID, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WayptID, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Page, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Tab, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Row, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Header, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nightmare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hell, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hidden, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqDisable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OneWay, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyFrom1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyFrom2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyFrom3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyFrom4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyFrom5, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyTo1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyTo2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyTo3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyTo4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OnlyTo5, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntranceFee, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntranceFeemybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntranceFeemybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExitFee, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExitFeemybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExitFeemybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemmybr1Nmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemmybr1Hmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemEquipped, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemEquippedmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemEquippedmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemCarried, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemCarriedmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemCarriedmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysNeedKeyItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysNeedKeyItemmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysNeedKeyItemmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyKeyItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyKeyItemmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyKeyItemmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyStat, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyStatmybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyStatmybr1Hmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyVal, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyValmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PenaltyValmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelReq, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelReqmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelReqmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1mybr1Hmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2mybr1Hmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3mybr1Hmybr2, USHORT_ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1mybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2mybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3mybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemmybr1Nmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemmybr1Hmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemEquipped, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemEquippedmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemEquippedmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemCarried, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemCarriedmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemCarriedmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyReqItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyReqItemmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestroyReqItemmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;
    m_stCallback.pfnFieldProc = Waypoints_FieldProc_131;
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess_131;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Waypoints_010(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_010 *pstLineInfo = (ST_LINE_INFO_010 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelID, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WayptID, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Tab, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hidden, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nightmare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hell, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UnlockItem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UnlockItemmybr1Nmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UnlockItemmybr1Hmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemmybr1Nmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqItemmybr1Hmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemmybr1Nmybr2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KeyItemmybr1Hmybr2, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KillKeyItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KillKeyItemmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KillKeyItemmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Waypoints(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_131) )
            {
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_INIT:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_010) )
            {
                return process_Waypoints_010(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize == sizeof(ST_LINE_INFO_131) )
            {
                return process_Waypoints_131(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize > 0 )
            {
                my_printf("Unknown version of Waypoints\n");
            }
            break;

        default:
            break;
    }

    return 1;
}


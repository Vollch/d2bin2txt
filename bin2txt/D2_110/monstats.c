#include "../global.h"

#define FILE_PREFIX "MonStats"
#define NAME_PREFIX "ms"

typedef struct
{//total 424 bytes
    unsigned short vId;
    unsigned short vBaseId; //monstats

    unsigned short vNextInClass; //monstats
    unsigned short vNameStr; //strings

    unsigned short vDescStr; //strings
    unsigned char pad0x0A[2];

#if 1
    unsigned char vBitCombined1;
    unsigned char vBitCombined2;
    unsigned char vBitCombined3;
    unsigned char vBitCombined4;
#else
    //0B
    unsigned char vprimeevil : 1;
    unsigned char vboss : 1;
    unsigned char vBossXfer : 1;
    unsigned char vSetBoss : 1;

    unsigned char vopendoors : 1;
    unsigned char vnoRatio : 1;
    unsigned char visMelee : 1;
    unsigned char visSpawn : 1;

    //88
    unsigned char vkillable : 1;
    unsigned char vflying : 1;
    unsigned char vdemon : 1;
    unsigned char vhUndead : 1;

    unsigned char vlUndead : 1;
    unsigned char vinTown : 1;
    unsigned char vinteract : 1;
    unsigned char vnpc : 1;

    //41
    unsigned char vplacespawn : 1;
    unsigned char vzoo : 1;
    unsigned char vgenericSpawn : 1;
    unsigned char vdeathDmg : 1;

    unsigned char vpetIgnore : 1;
    unsigned char vneverCount : 1;
    unsigned char vnomultishot : 1;
    unsigned char vswitchai : 1;

    //02
    unsigned char bPad5 : 3;
    unsigned char vrangedtype : 1;

    unsigned char vnoAura : 1;
    unsigned char vNoShldBlock : 1;
    unsigned char venabled : 1;
    unsigned char vinventory : 1;
#endif

    unsigned char vCode[4];

    unsigned short vMonSound; //monsounds
    unsigned short vUMonSound; //monsounds

    unsigned short vMonStatsEx; //monstats2
    unsigned short vMonProp; //MonProp

    unsigned short vMonType; //montype
    unsigned short vAI; //monai

    unsigned short vspawn; //monstats
    char vspawnx;
    char vspawny;

    unsigned char vspawnmode; //monmode
    unsigned char pad0x25;
    unsigned short vminion1; //monstats

    unsigned short vminion2; //monstats
    unsigned char pad0x2A[2];

    unsigned char vPartyMin;
    unsigned char vPartyMax;
    unsigned char vRarity;
    unsigned char vMinGrp;

    unsigned char vMaxGrp;
    unsigned char vsparsePopulate;
    unsigned char vVelocity;

    unsigned short vRun;
    unsigned char pad0x35[4];
    unsigned short vMissA1; //Missiles

    unsigned short vMissA2;
    unsigned short vMissS1;

    unsigned short vMissS2;
    unsigned short vMissS3;

    unsigned short vMissS4;
    unsigned short vMissC;

    unsigned short vMissSQ;
    unsigned char pad0x49[2];

    unsigned char vAlign;
    unsigned char vTransLvl;
    unsigned char vthreat;
    unsigned char vaidel;

    unsigned char vaidelmybr1Nmybr2;
    unsigned char vaidelmybr1Hmybr2;
    unsigned char vaidist;
    unsigned char vaidistmybr1Nmybr2;

    unsigned char vaidistmybr1Hmybr2;
    unsigned char pad0x54;
    unsigned short vaip1;

    unsigned short vaip1mybr1Nmybr2;
    unsigned short vaip1mybr1Hmybr2;

    unsigned short vaip2;
    unsigned short vaip2mybr1Nmybr2;

    unsigned short vaip2mybr1Hmybr2;
    unsigned short vaip3;

    unsigned short vaip3mybr1Nmybr2;
    unsigned short vaip3mybr1Hmybr2;

    unsigned short vaip4;
    unsigned short vaip4mybr1Nmybr2;

    unsigned short vaip4mybr1Hmybr2;
    unsigned short vaip5;

    unsigned short vaip5mybr1Nmybr2;
    unsigned short vaip5mybr1Hmybr2;

    unsigned short vaip6;
    unsigned short vaip6mybr1Nmybr2;

    unsigned short vaip6mybr1Hmybr2;
    unsigned short vaip7;

    unsigned short vaip7mybr1Nmybr2;
    unsigned short vaip7mybr1Hmybr2;

    unsigned short vaip8;
    unsigned short vaip8mybr1Nmybr2;

    unsigned short vaip8mybr1Hmybr2;
    unsigned short vTreasureClass1; //33 treasureclassex

    unsigned short vTreasureClass2;
    unsigned short vTreasureClass3;

    unsigned short vTreasureClass4;
    unsigned short vTreasureClass1mybr1Nmybr2;

    unsigned short vTreasureClass2mybr1Nmybr2;
    unsigned short vTreasureClass3mybr1Nmybr2;

    unsigned short vTreasureClass4mybr1Nmybr2;
    unsigned short vTreasureClass1mybr1Hmybr2;

    unsigned short vTreasureClass2mybr1Hmybr2;
    unsigned short vTreasureClass3mybr1Hmybr2;

    unsigned short vTreasureClass4mybr1Hmybr2;
    unsigned char vTCQuestId;
    unsigned char vTCQuestCP;

    unsigned char vDrain;
    unsigned char vDrainmybr1Nmybr2;
    unsigned char vDrainmybr1Hmybr2;
    unsigned char vToBlock;

    unsigned char vToBlockmybr1Nmybr2;
    unsigned char vToBlockmybr1Hmybr2;
    unsigned short vCrit;

    unsigned short vSkillDamage;    //skills
    unsigned short vLevel;

    unsigned short vLevelmybr1Nmybr2;
    unsigned short vLevelmybr1Hmybr2;

    unsigned short vminHP;
    unsigned short vMinHPmybr1Nmybr2;

    unsigned short vMinHPmybr1Hmybr2;
    unsigned short vmaxHP;

    unsigned short vMaxHPmybr1Nmybr2;
    unsigned short vMaxHPmybr1Hmybr2;

    unsigned short vAC;
    unsigned short vACmybr1Nmybr2;

    unsigned short vACmybr1Hmybr2;
    unsigned short vA1TH;

    unsigned short vA1THmybr1Nmybr2;
    unsigned short vA1THmybr1Hmybr2;

    unsigned short vA2TH;
    unsigned short vA2THmybr1Nmybr2;

    unsigned short vA2THmybr1Hmybr2;
    unsigned short vS1TH;

    unsigned short vS1THmybr1Nmybr2;
    unsigned short vS1THmybr1Hmybr2;

    unsigned short vExp;
    unsigned short vExpmybr1Nmybr2;

    unsigned short vExpmybr1Hmybr2;
    unsigned short vA1MinD;

    unsigned short vA1MinDmybr1Nmybr2;
    unsigned short vA1MinDmybr1Hmybr2;

    unsigned short vA1MaxD;
    unsigned short vA1MaxDmybr1Nmybr2;

    unsigned short vA1MaxDmybr1Hmybr2;
    unsigned short vA2MinD;

    unsigned short vA2MinDmybr1Nmybr2;
    unsigned short vA2MinDmybr1Hmybr2;

    unsigned short vA2MaxD;
    unsigned short vA2MaxDmybr1Nmybr2;

    unsigned short vA2MaxDmybr1Hmybr2;
    unsigned short vS1MinD;

    unsigned short vS1MinDmybr1Nmybr2;
    unsigned short vS1MinDmybr1Hmybr2;

    unsigned short vS1MaxD;
    unsigned short vS1MaxDmybr1Nmybr2;

    unsigned short vS1MaxDmybr1Hmybr2;
    unsigned char vEl1Mode; //monmode
    unsigned char vEl2Mode;

    unsigned char vEl3Mode;
    unsigned char vEl1Type; //elemtypes
    unsigned char vEl2Type;
    unsigned char vEl3Type;

    unsigned char vEl1Pct;
    unsigned char vEl1Pctmybr1Nmybr2;
    unsigned char vEl1Pctmybr1Hmybr2;
    unsigned char vEl2Pct;

    unsigned char vEl2Pctmybr1Nmybr2;
    unsigned char vEl2Pctmybr1Hmybr2;
    unsigned char vEl3Pct;

    unsigned char vEl3Pctmybr1Nmybr2;
    unsigned char vEl3Pctmybr1Hmybr2;
    unsigned char pad0x10C;
    unsigned short vEl1MinD;

    unsigned short vEl1MinDmybr1Nmybr2;
    unsigned short vEl1MinDmybr1Hmybr2;

    unsigned short vEl2MinD;
    unsigned short vEl2MinDmybr1Nmybr2;

    unsigned short vEl2MinDmybr1Hmybr2;
    unsigned short vEl3MinD;

    unsigned short vEl3MinDmybr1Nmybr2;
    unsigned short vEl3MinDmybr1Hmybr2;

    unsigned short vEl1MaxD;
    unsigned short vEl1MaxDmybr1Nmybr2;

    unsigned short vEl1MaxDmybr1Hmybr2;
    unsigned short vEl2MaxD;

    unsigned short vEl2MaxDmybr1Nmybr2;
    unsigned short vEl2MaxDmybr1Hmybr2;

    unsigned short vEl3MaxD;
    unsigned short vEl3MaxDmybr1Nmybr2;

    unsigned short vEl3MaxDmybr1Hmybr2;
    unsigned short vEl1Dur;

    unsigned short vEl1Durmybr1Nmybr2;
    unsigned short vEl1Durmybr1Hmybr2;

    unsigned short vEl2Dur;
    unsigned short vEl2Durmybr1Nmybr2;

    unsigned short vEl2Durmybr1Hmybr2;
    unsigned short vEl3Dur;

    unsigned short vEl3Durmybr1Nmybr2;
    unsigned short vEl3Durmybr1Hmybr2;

    short vResDm;
    short vResDmmybr1Nmybr2;

    short vResDmmybr1Hmybr2;
    short vResMa;

    short vResMamybr1Nmybr2;
    short vResMamybr1Hmybr2;

    short vResFi;
    short vResFimybr1Nmybr2;

    short vResFimybr1Hmybr2;
    short vResLi;

    short vResLimybr1Nmybr2;
    short vResLimybr1Hmybr2;

    short vResCo;
    short vResComybr1Nmybr2;

    short vResComybr1Hmybr2;
    short vResPo;

    short vResPomybr1Nmybr2;
    short vResPomybr1Hmybr2;

    char vcoldeffect;
    char vcoldeffectmybr1Nmybr2;
    char vcoldeffectmybr1Hmybr2;
    unsigned char pad0x16A;

    unsigned int vSendSkills;

    unsigned short vSkill1; //skills
    unsigned short vSkill2;

    unsigned short vSkill3;
    unsigned short vSkill4;

    unsigned short vSkill5;
    unsigned short vSkill6;

    unsigned short vSkill7;
    unsigned short vSkill8;

    unsigned char vSk1modeType;
    unsigned char vSk2modeType;
    unsigned char vSk3modeType;
    unsigned char vSk4modeType;

    unsigned char vSk5modeType;
    unsigned char vSk6modeType;
    unsigned char vSk7modeType;
    unsigned char vSk8modeType;

    unsigned short vSk1mode;   //monseq
    unsigned short vSk2mode;

    unsigned short vSk3mode;
    unsigned short vSk4mode;

    unsigned short vSk5mode;
    unsigned short vSk6mode;

    unsigned short vSk7mode;
    unsigned short vSk8mode;

    unsigned char vSk1lvl;
    unsigned char vSk2lvl;
    unsigned char vSk3lvl;
    unsigned char vSk4lvl;

    unsigned char vSk5lvl;
    unsigned char vSk6lvl;
    unsigned char vSk7lvl;
    unsigned char vSk8lvl;

    unsigned int vDamageRegen;

    unsigned char vSplEndDeath;
    unsigned char vSplGetModeChart;
    unsigned char vSplEndGeneric;
    unsigned char vSplClientEnd;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vId[64];
    unsigned short vMonProp;
    unsigned short vNameStr;

    unsigned short vSkill1;
    unsigned short vSkill2;
    unsigned short vSkill3;
    unsigned short vSkill4;
    unsigned short vSkill5;
    unsigned short vSkill6;
    unsigned short vSkill7;
    unsigned short vSkill8;
} ST_MONSTAT;

static char *m_apcInternalProcess[] =
{
    "hcIdx",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iMonStatsCount = 0;
static unsigned int m_iMonStatsHaveEmpty = 0;
static ST_MONSTAT *m_astMonStats = NULL;

MODULE_SETLINES_FUNC(m_astMonStats, ST_MONSTAT);
MODULE_HAVENAME_FUNC(m_astMonStats, vId, m_iMonStatsCount);

int MonStats_LinkSkills(void *astSkills, unsigned int iSkillsCount, unsigned int iStructSize, unsigned int iMemberOffset)
{
    unsigned int i, j, iSkill;
    void *pcOwner;

    for ( i = 0; i < m_iMonStatsCount; i++ )
    {
        for ( j = 0; j < 8; j++ )
        {
            iSkill = *(&m_astMonStats[i].vSkill1 + j);
            if ( iSkill < iSkillsCount )
            {
                pcOwner = (char *)astSkills + (iSkill * iStructSize) + iMemberOffset;
                *(char **)pcOwner = &(m_astMonStats[i].vId[0]);
            }
        }
    }

    return 1;
}

int MonStats_LinkMonProp(void *astMonProp, unsigned int iMonPropCount, unsigned int iStructSize, unsigned int iMemberOffset)
{
    unsigned int i;
    void *psString;

    for ( i = 0; i < iMonPropCount; i++ )
    {
        psString = (char *)astMonProp + (i * iStructSize) + iMemberOffset;
        *(unsigned short *)psString = 0xFFFF;
    }

    for ( i = 0; i < m_iMonStatsCount; i++ )
    {
        if ( m_astMonStats[i].vMonProp < iMonPropCount )
        {
            psString = (char *)astMonProp + (m_astMonStats[i].vMonProp * iStructSize) + iMemberOffset;
            *(unsigned short *)psString = m_astMonStats[i].vNameStr;
        }
    }

    return 1;
}

static char *MonStats_GetStatsName(unsigned int id)
{
    if ( id < m_iMonStatsCount )
    {
        return m_astMonStats[id].vId;
    }

    if ( id == -1 && m_iMonStatsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonStats_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        char acName[5] = {0};
        strncpy(acName, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(monstats), pstLineInfo->vNameStr, pcTemplate, acName, pstLineInfo->vId, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vId);
        }

        memcpy(&m_astMonStats[pstLineInfo->vId].vSkill1, &pstLineInfo->vSkill1, sizeof(pstLineInfo->vSkill1) * 8);
        m_astMonStats[pstLineInfo->vId].vNameStr = pstLineInfo->vNameStr;
        m_astMonStats[pstLineInfo->vId].vMonProp = pstLineInfo->vMonProp;
        strncpy(m_astMonStats[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonStats[pstLineInfo->vId].vId));
        String_Trim(m_astMonStats[pstLineInfo->vId].vId);
        m_iMonStatsHaveEmpty |= !m_astMonStats[pstLineInfo->vId].vId[0];

        m_iMonStatsCount++;
        return 1;
    }

    return 0;
}

static int MonStats_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "hcIdx") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vId);

        return 1;
    }

    return 0;
}

static int MonStats_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;

    if ( !stricmp(acKey, "NameStr") )
    {
        if ( pcResult = String_FindString(pstLineInfo->vNameStr, NULL, NULL) )
        {
            strcpy(acOutput, pcResult);
        }

        return 1;
    }
    else if ( strlen("Sk1mode") == strlen(acKey) && 1 == sscanf(acKey, "Sk%dmode", &id) )
    {
        unsigned char ucType = ((char *)&pstLineInfo->vSk1modeType)[id - 1];
        unsigned short usSkMode = ((short *)&pstLineInfo->vSk1mode)[id - 1];
        unsigned short usSkill = ((short *)&pstLineInfo->vSkill1)[id - 1];

        if ( usSkill != 0xFFFF )
        {
            if ( ucType == 0x0E )
            {
                process_value(EN_VALUE_MONSEQ, sizeof(usSkMode), &usSkMode, acOutput);
            }
            else
            {
                process_value(EN_VALUE_MONMODE, sizeof(ucType), &ucType, acOutput);
            }
        }

        return 1;
    }

    return 0;
}

static void MonStats_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseId, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextInClass, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameStr, USHORT);    //strings

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DescStr, TBL_STRING);    //strings

    //0B
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, primeevil, BitCombined1, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, boss, BitCombined1, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, BossXfer, BitCombined1, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SetBoss, BitCombined1, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, opendoors, BitCombined1, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noRatio, BitCombined1, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, isMelee, BitCombined1, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, isSpawn, BitCombined1, 0, UCHAR_BIT);

    //88
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, killable, BitCombined2, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, flying, BitCombined2, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, demon, BitCombined2, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, hUndead, BitCombined2, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, lUndead, BitCombined2, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, inTown, BitCombined2, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, interact, BitCombined2, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, npc, BitCombined2, 0, UCHAR_BIT);

    //41
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, placespawn, BitCombined3, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, zoo, BitCombined3, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, genericSpawn, BitCombined3, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, deathDmg, BitCombined3, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, petIgnore, BitCombined3, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, neverCount, BitCombined3, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, nomultishot, BitCombined3, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, switchai, BitCombined3, 0, UCHAR_BIT);

    //02
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rangedtype, BitCombined4, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noAura, BitCombined4, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, NoShldBlock, BitCombined4, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, enabled, BitCombined4, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, inventory, BitCombined4, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSound, MONSOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UMonSound, MONSOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonStatsEx, MONSTAT2);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonProp, MONPROP);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType, MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AI, MONAI);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawn, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnx, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawny, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnmode, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minion1, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minion2, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PartyMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PartyMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinGrp, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxGrp, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sparsePopulate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Velocity, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Run, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA1, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA2, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS1, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS2, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS3, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS4, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissC, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissSQ, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Align, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TransLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, threat, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidel, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidelmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidelmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidistmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidistmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1mybr1Nmybr2, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2mybr1Nmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3mybr1Nmybr2, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4mybr1Nmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1mybr1Hmybr2, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2mybr1Hmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3mybr1Hmybr2, TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4mybr1Hmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCQuestId, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCQuestCP, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drainmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drainmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlock, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlockmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlockmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Crit, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillDamage, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minHP, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxHP, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AC, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1TH, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1THmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1THmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2TH, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2THmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2THmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1TH, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1THmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1THmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Exp, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Mode, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Mode, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Mode, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Type, ELEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Type, ELEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Type, ELEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pct, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pctmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pct, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pctmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pct, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pctmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Dur, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Durmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Durmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Dur, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Durmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Durmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Dur, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Durmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Durmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDm, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDmmybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDmmybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMa, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMamybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMamybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFi, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFimybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFimybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLi, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLimybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLimybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResCo, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResComybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResComybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPo, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPomybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPomybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffect, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffectmybr1Nmybr2, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffectmybr1Hmybr2, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendSkills, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill6, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill7, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill8, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk1mode, MONSEQ);   //monseq
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk2mode, MONSEQ);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk3mode, MONSEQ);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk4mode, MONSEQ);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk5mode, MONSEQ);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk6mode, MONSEQ);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk7mode, MONSEQ);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk8mode, MONSEQ);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk1lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk2lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk3lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk4lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk5lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk6lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk7lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk8lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRegen, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndDeath, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplGetModeChart, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndGeneric, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplClientEnd, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_monstats(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_MONSTATS_109) )
    {
        return process_monstats109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MonStats_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonStatsCount = 0;
            Lookup_MonStats = MonStats_GetStatsName;

            m_stCallback.pfnConvertValue = MonStats_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats2, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monsounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monprop, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(montype, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monai, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monseq, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonStats_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = MonStats_FieldProc;
            m_stCallback.pfnConvertValue = MonStats_ConvertValue;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


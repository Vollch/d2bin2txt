#include "../global.h"

#define FILE_PREFIX "Skills"
#define NAME_PREFIX "sk"


typedef struct
{
    unsigned short vskill;
    unsigned char pad0x02[2];

#if 1
    unsigned int vBitCombined;
    unsigned int vBitCombined2;
#else
    unsigned int vinterrupt : 1;
    unsigned int vleftskill : 1;
    unsigned int vItemTgtDo : 1;
    unsigned int vAttackNoMana : 1;

    unsigned int vTargetItem : 1;
    unsigned int vTargetAlly : 1;
    unsigned int vTargetPet : 1;
    unsigned int vTargetCorpse : 1;

    unsigned int vSearchOpenXY : 1;
    unsigned int vSearchEnemyNear : 1;
    unsigned int vSearchEnemyXY : 1;
    unsigned int vTargetableOnly : 1;

    unsigned int vUseAttackRate : 1;
    unsigned int vdurability : 1;
    unsigned int venhanceable : 1;
    unsigned int vnoammo : 1;

    unsigned int vimmediate : 1;
    unsigned int vweaponsnd : 1;
    unsigned int vstsounddelay : 1;
    unsigned int vstsuccessonly : 1;

    unsigned int vrepeat : 1;
    unsigned int vInGame : 1;
    unsigned int vKick : 1;
    unsigned int vInTown : 1;

    unsigned int vprgstack : 1;
    unsigned int vperiodic : 1;
    unsigned int vaura : 1;
    unsigned int vpassive : 1;

    unsigned int vfinishing : 1;
    unsigned int vprogressive : 1;
    unsigned int vlob : 1;
    unsigned int vdecquant : 1;

    unsigned int bPad7 : 25;
    unsigned int vwarp : 1;
    unsigned int vusemanaondo : 1;
    unsigned int vscroll : 1;

    unsigned int vgeneral : 1;
    unsigned int vItemCltCheckStart : 1;
    unsigned int vItemCheckStart : 1;
    unsigned int vTgtPlaceCheck : 1;
#endif

    unsigned char vcharclass; //playerclass
    unsigned char pad0x0D[3];

    unsigned char vanim; //plrmode
    unsigned char vmonanim; //monmode
    unsigned char vseqtrans; //plrmode
    unsigned char vseqnum;

    unsigned char vrange;
    unsigned char vSelectProc;
    unsigned short vseqinput;

    unsigned short vitypea1; //ItemTypes
    unsigned short vitypea2; //ItemTypes

    unsigned short vitypea3; //ItemTypes
    unsigned short vitypeb1; //ItemTypes

    unsigned short vitypeb2; //ItemTypes
    unsigned short vitypeb3; //ItemTypes

    unsigned short vetypea1; //ItemTypes
    unsigned short vetypea2; //ItemTypes

    unsigned short vetypeb1; //ItemTypes
    unsigned short vetypeb2; //ItemTypes

    unsigned short vsrvstfunc;
    unsigned short vsrvdofunc;

    unsigned short vsrvprgfunc1;
    unsigned short vsrvprgfunc2;

    unsigned short vsrvprgfunc3;
    unsigned char pad0x37[2];

    unsigned int vprgcalc1; //skillscode
    unsigned int vprgcalc2;
    unsigned int vprgcalc3;

    unsigned short vprgdam;
    unsigned short vsrvmissile; //missile

    unsigned short vsrvmissilea; //missile
    unsigned short vsrvmissileb; //missile

    unsigned short vsrvmissilec; //missile
    unsigned short vsrvoverlay; //overlay

    unsigned int vaurafilter;

    unsigned short vaurastat1; //ItemStatCost
    unsigned short vaurastat2; //ItemStatCost

    unsigned short vaurastat3; //ItemStatCost
    unsigned short vaurastat4; //ItemStatCost

    unsigned short vaurastat5; //ItemStatCost
    unsigned short vaurastat6; //ItemStatCost

    unsigned int vauralencalc; //skillscode
    unsigned int vaurarangecalc;
    unsigned int vaurastatcalc1;
    unsigned int vaurastatcalc2;
    unsigned int vaurastatcalc3;
    unsigned int vaurastatcalc4;
    unsigned int vaurastatcalc5;
    unsigned int vaurastatcalc6;

    unsigned short vaurastate;  //state
    unsigned short vauratargetstate; //state

    unsigned short vauraevent1; //event
    unsigned short vauraevent2; //event

    unsigned short vauraevent3; //event
    unsigned short vauraeventfunc1;

    unsigned short vauraeventfunc2;
    unsigned short vauraeventfunc3;

    unsigned short vauratgtevent; //event
    unsigned short vauratgteventfunc;

    unsigned short vpassivestate; //state
    unsigned short vpassiveitype; //itemtypes

    unsigned short vpassivestat1; //ItemStatCost
    unsigned short vpassivestat2; //ItemStatCost

    unsigned short vpassivestat3; //ItemStatCost
    unsigned short vpassivestat4; //ItemStatCost

    unsigned short vpassivestat5; //ItemStatCost
    unsigned char pad0xA2[2];

    unsigned int vpassivecalc1; //skillscode
    unsigned int vpassivecalc2;
    unsigned int vpassivecalc3;
    unsigned int vpassivecalc4;
    unsigned int vpassivecalc5;

    unsigned short vpassiveevent; //events
    unsigned short vpassiveeventfunc;

    unsigned short vsummon; //MonStats
    unsigned char vpettype; //PetType
    unsigned char vsummode; //MonMode

    unsigned int vpetmax; //skillscode

    unsigned short vsumskill1; //skills
    unsigned short vsumskill2; //skills

    unsigned short vsumskill3; //skills
    unsigned short vsumskill4; //skills

    unsigned short vsumskill5; //skills
    unsigned char pad0xCE[2];

    unsigned int vsumsk1calc; //skillscode
    unsigned int vsumsk2calc;
    unsigned int vsumsk3calc;
    unsigned int vsumsk4calc;
    unsigned int vsumsk5calc;

    unsigned short vsumumod;
    unsigned short vsumoverlay; //overlay

    unsigned short vcltmissile; //missiles
    unsigned short vcltmissilea; //missiles
    unsigned short vcltmissileb; //missiles
    unsigned short vcltmissilec; //missiles

    unsigned short vcltmissiled; //missiles
    unsigned short vcltstfunc;

    unsigned short vcltdofunc;
    unsigned short vcltprgfunc1;

    unsigned short vcltprgfunc2;
    unsigned short vcltprgfunc3;

    unsigned short vstsound; //sounds
    unsigned short vstsoundclass; //sounds

    unsigned short vdosound; //sounds
    unsigned short vdosoundmyspa; //sounds

    unsigned short vdosoundmyspb; //sounds
    unsigned short vcastoverlay; //overlay

    unsigned short vtgtoverlay; //overlay
    unsigned short vtgtsound; //sounds

    unsigned short vprgoverlay; //overlay
    unsigned short vprgsound; //sounds

    unsigned short vcltoverlaya; //overlay
    unsigned short vcltoverlayb; //overlay

    unsigned int vcltcalc1; //skillscode
    unsigned int vcltcalc2;
    unsigned int vcltcalc3;

    unsigned char vItemTarget;
    unsigned char pad0x121;
    unsigned short vItemCastSound; //sounds

    unsigned short vItemCastOverlay; //overlay
    unsigned char pad0x126[2];

    unsigned int vperdelay; //skillscode

    unsigned short vmaxlvl;
    unsigned short vResultFlags;

    unsigned int vHitFlags;
    unsigned int vHitClass;

    unsigned int vcalc1; //skillscode
    unsigned int vcalc2;
    unsigned int vcalc3;
    unsigned int vcalc4;

    int vParam1;
    int vParam2;
    int vParam3;
    int vParam4;
    int vParam5;
    int vParam6;
    int vParam7;
    int vParam8;

    unsigned short vweapsel;
    unsigned short vItemEffect;

    unsigned short vItemCltEffect;
    unsigned char pad0x16E[2];

    unsigned int vskpoints; //skillscode

    unsigned short vreqlevel;
    unsigned short vreqstr;

    unsigned short vreqdex;
    unsigned short vreqint;

    unsigned short vreqvit;
    unsigned short vreqskill1; //skills

    unsigned short vreqskill2; //skills
    unsigned short vreqskill3; //skills

    unsigned short vstartmana;
    unsigned short vminmana;

    unsigned short vmanashift;
    unsigned short vmana;

    short vlvlmana;
    unsigned char vattackrank;
    unsigned char vLineOfSight;

    unsigned int vdelay; //skillscode

    unsigned short vskilldesc; //skilldesc
    unsigned char pad0x196[2];

    unsigned int vToHit;
    unsigned int vLevToHit;
    unsigned int vToHitCalc; //skillscode

    unsigned char vHitShift;
    unsigned char vSrcDam;
    unsigned char pad0x1A6[2];

    unsigned int vMinDam;
    unsigned int vMaxDam;
    unsigned int vMinLevDam1;
    unsigned int vMinLevDam2;

    unsigned int vMinLevDam3;
    unsigned int vMinLevDam4;
    unsigned int vMinLevDam5;
    unsigned int vMaxLevDam1;
    unsigned int vMaxLevDam2;
    unsigned int vMaxLevDam3;
    unsigned int vMaxLevDam4;
    unsigned int vMaxLevDam5;

    unsigned int vDmgSymPerCalc; //skillscode

    unsigned char vEType; //elemtypes
    unsigned char pad0x1DD[3];

    unsigned int vEMin;
    unsigned int vEMax;
    unsigned int vEMinLev1;
    unsigned int vEMinLev2;
    unsigned int vEMinLev3;
    unsigned int vEMinLev4;
    unsigned int vEMinLev5;
    unsigned int vEMaxLev1;
    unsigned int vEMaxLev2;
    unsigned int vEMaxLev3;
    unsigned int vEMaxLev4;
    unsigned int vEMaxLev5;

    unsigned int vEDmgSymPerCalc; //skillscode
    unsigned int vELen;
    unsigned int vELevLen1;
    unsigned int vELevLen2;
    unsigned int vELevLen3;
    unsigned int vELenSymPerCalc; //skillscode

    unsigned short vrestrict;
    unsigned short vState1; //states

    unsigned short vState2; //states
    unsigned short vState3; //states

    unsigned short vaitype;
    short vaibonus;

    unsigned int vcostmyspmult;
    unsigned int vcostmyspadd;
} ST_LINE_INFO;

typedef struct
{
    char vskill[64];
    char *pcOwner;
} ST_SKILLS;

static char *m_apcNotUsed[] =
{
    "checkfunc",
    "nocostinstate",
    "*cltcalc1 desc",
    "*cltcalc2 desc",
    "*cltcalc3 desc",
    "*calc1 desc",
    "*calc2 desc",
    "*calc3 desc",
    "*calc4 desc",
    "*Param1 Description",
    "*Param2 Description",
    "*Param3 Description",
    "*Param4 Description",
    "*Param5 Description",
    "*Param6 Description",
    "*Param7 Description",
    "*Param8 Description",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Id",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iSkillsCount = 0;
static unsigned int m_iSkillsHaveEmpty = 0;
static ST_SKILLS *m_astSkills = NULL;

MODULE_SETLINES_FUNC(m_astSkills, ST_SKILLS);
MODULE_HAVENAME_FUNC(m_astSkills, vskill, m_iSkillsCount);

static void SetLines_Pre(unsigned int uiLines)
{
    SETLINES_FUNC_NAME(uiLines);
    MonStats_LinkSkills(m_astSkills, uiLines, sizeof(ST_SKILLS), offsetof(ST_SKILLS, pcOwner));
}

static char *Skills_GetSkillName(unsigned int id)
{
    if ( id < m_iSkillsCount )
    {
        return m_astSkills[id].vskill;
    }

    if ( id == -1 && m_iSkillsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Skills_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "skill") )
    {
        if ( !String_BuildName(FORMAT(skills), Lookup_SkillDescString(pstLineInfo->vskilldesc), pcTemplate, m_astSkills[pstLineInfo->vskill].pcOwner, pstLineInfo->vskill, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vskill);
        }

        strncpy(m_astSkills[pstLineInfo->vskill].vskill, acOutput, sizeof(m_astSkills[pstLineInfo->vskill].vskill));
        String_Trim(m_astSkills[pstLineInfo->vskill].vskill);
        m_iSkillsHaveEmpty |= !m_astSkills[pstLineInfo->vskill].vskill[0];

        m_iSkillsCount++;
        return 1;
    }

    return 0;
}

static int Skills_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vskill);

        return 1;
    }
    else if ( isD2SigmaActive() && Skills2_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static int Skills_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "range") )
    {
        if ( 3 == pstLineInfo->vrange )
        {
            strcpy(acOutput, "both");
        }
        else if ( 1 == pstLineInfo->vrange )
        {
            strcpy(acOutput, "h2h");
        }
        else if ( 2 == pstLineInfo->vrange )
        {
            strcpy(acOutput, "rng");
        }
        else if ( 0 == pstLineInfo->vrange )
        {
            strcpy(acOutput, "none");
        }
        else
        {
            acOutput[0] = 0;
        }
        return 1;
    }

    return 0;
}

static void Skills_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skill, SKILL);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, interrupt, BitCombined, 31, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, leftskill, BitCombined, 30, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ItemTgtDo, BitCombined, 29, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, AttackNoMana, BitCombined, 28, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TargetItem, BitCombined, 27, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TargetAlly, BitCombined, 26, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TargetPet, BitCombined, 25, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TargetCorpse, BitCombined, 24, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SearchOpenXY, BitCombined, 23, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SearchEnemyNear, BitCombined, 22, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SearchEnemyXY, BitCombined, 21, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TargetableOnly, BitCombined, 20, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, UseAttackRate, BitCombined, 19, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, durability, BitCombined, 18, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, enhanceable, BitCombined, 17, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noammo, BitCombined, 16, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, immediate, BitCombined, 15, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, weaponsnd, BitCombined, 14, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, stsounddelay, BitCombined, 13, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, stsuccessonly, BitCombined, 12, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, repeat, BitCombined, 11, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, InGame, BitCombined, 10, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Kick, BitCombined, 9, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, InTown, BitCombined, 8, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, prgstack, BitCombined, 7, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, periodic, BitCombined, 6, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, aura, BitCombined, 5, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, passive, BitCombined, 4, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, finishing, BitCombined, 3, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, progressive, BitCombined, 2, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, lob, BitCombined, 1, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, decquant, BitCombined, 0, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, warp, BitCombined2, 6, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, usemanaondo, BitCombined2, 5, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, scroll, BitCombined2, 4, UINT_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, general, BitCombined2, 3, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ItemCltCheckStart, BitCombined2, 2, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ItemCheckStart, BitCombined2, 1, UINT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TgtPlaceCheck, BitCombined2, 0, UINT_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, anim, PLRMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monanim, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, seqtrans, PLRMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, seqnum, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, range, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SelectProc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, seqinput, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypea1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypea2, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypea3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etypea1, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etypea2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypeb1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypeb2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itypeb3, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etypeb1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etypeb2, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvstfunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvdofunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvprgfunc1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvprgfunc2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvprgfunc3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgdam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvmissile, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvmissilea, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvmissileb, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvmissilec, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvoverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurafilter, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat2, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat3, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat4, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat5, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastat6, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastate, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auratargetstate, STATE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraevent1, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraevent2, EVENT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraevent3, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraeventfunc1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraeventfunc2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auraeventfunc3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auratgtevent, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auratgteventfunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestate, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passiveitype, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestat2, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestat3, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestat4, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivestat5, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passiveevent, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passiveeventfunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, summon, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pettype, PET);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, summode, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumskill1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumskill2, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumskill3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumskill4, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumskill5, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumumod, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumoverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltmissile, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltmissilea, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltmissileb, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltmissilec, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltmissiled, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltstfunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltdofunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltprgfunc1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltprgfunc2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltprgfunc3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stsound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stsoundclass, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dosound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dosoundmyspa, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dosoundmyspb, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, castoverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, tgtoverlay, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, tgtsound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgoverlay, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgsound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltoverlaya, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltoverlayb, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemTarget, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemCastSound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemCastOverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResultFlags, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitFlags, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param8, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weapsel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemEffect, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemCltEffect, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqlevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqstr, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqdex, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqint, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqvit, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill1, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill2, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill3, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, startmana, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmana, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, manashift, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mana, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmana, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, attackrank, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LineOfSight, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skilldesc, SKILLDESC);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevToHit, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitShift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcDam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinDam, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxDam, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EType, ELEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMinLev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMinLev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMinLev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMinLev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMinLev5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMaxLev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMaxLev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMaxLev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMaxLev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMaxLev5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen3, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, restrict, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, State1, STATE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, State2, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, State3, STATE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aitype, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aibonus, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgcalc1, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgcalc2, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prgcalc3, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, auralencalc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurarangecalc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc1, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc2, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc3, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc4, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc5, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aurastatcalc6, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivecalc1, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivecalc2, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivecalc3, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivecalc4, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, passivecalc5, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, petmax, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumsk1calc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumsk2calc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumsk3calc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumsk4calc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sumsk5calc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltcalc1, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltcalc2, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltcalc3, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, perdelay, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc1, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc2, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc3, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc4, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skpoints, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, delay, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHitCalc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgSymPerCalc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EDmgSymPerCalc, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELenSymPerCalc, SKILLCODE);
}

int process_skills(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_SKILLS_109) )
    {
        return process_skills109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skilldesc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(Skills2, acTemplatePath, acBinPath, acTxtPath);
            Skills_InitValueMap(pstValueMap, pstLineInfo);

            m_iSkillsCount = 0;
            Lookup_Skill = Skills_GetSkillName;

            m_stCallback.pfnConvertValue = Skills_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SetLines_Pre;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? Skills2_ExternList : m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(plrmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(pettype, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skillscode, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Skills_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Skills_FieldProc;
            m_stCallback.pfnConvertValue = Skills_ConvertValue;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? Skills2_ExternList : m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "MonStats"

static char *m_apcNotUsed[] =
{
    "namco",
    "Type",
    "PopulateId",
    "Beta",
    "ClientOnly",
    "Comment",
    "ElOver",
    NULL,
};

static void MonStats_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_MONSTATS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Descriptor, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseId, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Spawned, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoMap, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoOverlays, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayHeight, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Velocity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Run, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EXP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EXPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EXPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CanStealFrom, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ColdEffect, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MeleeRng, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinGrp, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxGrp, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HD, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TR, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LG, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RA, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LA, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LH, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S8, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TotalPieces, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseW, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AIParam1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AIParam2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AIParam3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AIParam4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AIParam5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeDH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeN, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeW, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeGH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeA1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeA2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeB, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeC, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeS1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeS2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeS3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeS4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeDD, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeKB, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeSQ, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ModeRN, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElMode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElType, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElPct, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElMinD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElMaxD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElDur, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissSQ, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1ToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1ToHitmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1ToHitmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2ToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2ToHitmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2ToHitmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1ToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1ToHitmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1ToHitmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4Move, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlock, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CMove, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Align, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsMelee, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsSel, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsSel2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NeverSel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CorpseSel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsAtt, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PetIgnore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsNPC, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsCritter, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InTown, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Bleed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shadow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoUniqueShift, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CompositeDeath, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1Seq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2Seq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3Seq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4Seq, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5Seq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1Lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2Lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3Lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4Lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5Lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightR, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightG, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightB, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageResist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageResistmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageResistmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MagicResist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MagicResistmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MagicResistmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FireResist, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FireResistmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FireResistmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightResist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightResistmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LightResistmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ColdResist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ColdResistmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ColdResistmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PoisonResist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PoisonResistmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PoisonResistmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRegen, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eLUndead, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eHUndead, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eDemon, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eMagicUsing, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eLarge, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eSmall, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eFlying, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eOpenDoors, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eBoss, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, eSpawnCol, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PixHeight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Interact, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpawnComponents, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Soft, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Heart, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyPart, STRING);
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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpawnPctBonus, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Killable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Switch, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Restore, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NeverCount, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndDeath, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplGetModeChart, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndGeneric, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplClientEnd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeadCollision, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UnflatDead, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BloodLocal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeathDamage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoGfxHitTest, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitTestTop, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitTestLeft, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitTestWidth, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitTestHeight, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutomapCel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GenericSpawn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SparsePopulate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Zoo, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjectCollision, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Inert, UCHAR);
}

int process_monstats109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_MONSTATS_109 *pstLineInfo = (ST_MONSTATS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonStats_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


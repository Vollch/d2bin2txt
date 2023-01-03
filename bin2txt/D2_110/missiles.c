#include "../global.h"

#define FILE_PREFIX "Missiles"
#define NAME_PREFIX "ml"

typedef struct
{
    unsigned short vMissile;
    unsigned char pad0x02[2];

#if 1
    unsigned short vBitCombined;
#else
    unsigned short vMissileSkill : 1;
    unsigned short vHalf2HSrc : 1;
    unsigned short vNoUniqueMod : 1;
    unsigned short vNoMultiShot : 1;
    unsigned short vSrcTown : 1;
    unsigned short vTown : 1;
    unsigned short vReturnFire : 1;
    unsigned short vApplyMastery : 1;
    unsigned short vSoftHit : 1;
    unsigned short vGetHit : 1;
    unsigned short vClientSend : 1;
    unsigned short vCanDestroy : 1;
    unsigned short vCanSlow : 1;
    unsigned short vPierce : 1;
    unsigned short vExplosion: 1;
    unsigned short vLastCollide : 1;
#endif

    unsigned char pad0x06[2];

    unsigned short vpCltDoFunc;
    unsigned short vpCltHitFunc;

    unsigned short vpSrvDoFunc;
    unsigned short vpSrvHitFunc;

    unsigned short vpSrvDmgFunc;
    unsigned short vTravelSound;

    unsigned short vHitSound;
    unsigned short vExplosionMissile;

    unsigned short vSubMissile1;
    unsigned short vSubMissile2;

    unsigned short vSubMissile3;
    unsigned short vCltSubMissile1;

    unsigned short vCltSubMissile2;
    unsigned short vCltSubMissile3;

    unsigned short vHitSubMissile1;
    unsigned short vHitSubMissile2;

    unsigned short vHitSubMissile3;
    unsigned short vHitSubMissile4;

    unsigned short vCltHitSubMissile1;
    unsigned short vCltHitSubMissile2;

    unsigned short vCltHitSubMissile3;
    unsigned short vCltHitSubMissile4;

    unsigned short vProgSound;
    unsigned short vProgOverlay;

    int vParam1;
    int vParam2;
    int vParam3;
    int vParam4;
    int vParam5;

    int vsHitPar1;
    int vsHitPar2;
    int vsHitPar3;

    int vCltParam1;
    int vCltParam2;
    int vCltParam3;
    int vCltParam4;
    int vCltParam5;

    int vcHitPar1;
    int vcHitPar2;
    int vcHitPar3;

    int vdParam1;
    int vdParam2;

    unsigned int vSrvCalc1;
    unsigned int vCltCalc1;
    unsigned int vSHitCalc1;
    unsigned int vCHitCalc1;
    unsigned int vDmgCalc1;

    unsigned short vHitClass;
    unsigned short vRange;

    unsigned short vLevRange;
    unsigned char vVel;
    unsigned char vVelLev;

    unsigned short vMaxVel;
    short vAccel;

    unsigned short vanimrate;
    short vxoffset;

    short vyoffset;
    short vzoffset;

    unsigned int vHitFlags;

    unsigned short vResultFlags;
    unsigned char vKnockBack;
    unsigned char pad0xAF;

    unsigned int vMinDamage;
    unsigned int vMaxDamage;
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

    unsigned int vDmgSymPerCalc;

    unsigned char vEType;
    unsigned char pad0xE5[3];

    unsigned int vEMin;
    unsigned int vEmax;
    unsigned int vMinELev1;
    unsigned int vMinELev2;
    unsigned int vMinELev3;
    unsigned int vMinELev4;
    unsigned int vMinELev5;
    unsigned int vMaxELev1;
    unsigned int vMaxELev2;
    unsigned int vMaxELev3;
    unsigned int vMaxELev4;
    unsigned int vMaxELev5;

    unsigned int vEDmgSymPerCalc;

    unsigned int vELen;
    unsigned int vELevLen1;
    unsigned int vELevLen2;
    unsigned int vELevLen3;

    unsigned char vCltSrcTown;
    unsigned char vSrcDamage;
    unsigned char vSrcMissDmg;
    unsigned char vHoly;

    unsigned char vLight;
    unsigned char vFlicker;
    unsigned char vRed;
    unsigned char vGreen;

    unsigned char vBlue;
    unsigned char vInitSteps;
    unsigned char vActivate;
    unsigned char vLoopAnim;

    unsigned char vCelFile[64];

    unsigned int vAnimLen;
    unsigned int vRandStart;

    unsigned char vSubLoop;
    unsigned char vSubStart;
    unsigned char vSubStop;
    unsigned char vCollideType;

    unsigned char vCollision;
    unsigned char vClientCol;
    unsigned char vCollideKill;
    unsigned char vCollideFriend;

    unsigned char vNextHit;
    unsigned char vNextDelay;
    unsigned char vSize;
    unsigned char vToHit;

    unsigned char vAlwaysExplode;
    unsigned char vTrans;
    unsigned short vQty;

    unsigned int vSpecialSetup;

    unsigned short vSkill;
    unsigned short vHitShift;

    unsigned char pad0x198[4];

    unsigned int vDamageRate;

    unsigned char vNumDirections;
    unsigned char vAnimSpeed;
    unsigned char vLocalBlood;
    unsigned char bUnKnown2;
} ST_LINE_INFO; //420 bytes

typedef struct
{
    unsigned char vMissile[64];
} ST_MISSILES;

static char *m_apcNotUsed[] =
{
    "*srv calc 1 desc",
    "*param1 desc",
    "*param2 desc",
    "*param3 desc",
    "*param4 desc",
    "*param5 desc",
    "*client calc 1 desc",
    "*client param1 desc",
    "*client param2 desc",
    "*client param3 desc",
    "*client param4 desc",
    "*client param5 desc",
    "*server hit calc 1 desc",
    "*server hit param1 desc",
    "*server hit param2 desc",
    "*server hit param3 desc",
    "*client hit calc1 desc",
    "*client hit param1 desc",
    "*client hit param2 desc",
    "*client hit param3 desc",
    "*damage calc 1",
    "*damage param1 desc",
    "*damage param2 desc",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Id",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iMisslesCount = 0;
static unsigned int m_iMisslesHaveEmpty = 0;
static ST_MISSILES *m_astMissiles = NULL;

MODULE_SETLINES_FUNC(m_astMissiles, ST_MISSILES);
MODULE_HAVENAME_FUNC(m_astMissiles, vMissile, m_iMisslesCount);

static char *Missiles_GetMissile(unsigned int id)
{
    if ( id < m_iMisslesCount )
    {
        return m_astMissiles[id].vMissile;
    }

    if ( id == -1 && m_iMisslesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Missiles_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Missile") )
    {
        char acName[33] = {0};
        String_StripFileName(pstLineInfo->vCelFile, acName, 32);
        if ( !String_BuildName(FORMAT(missiles), 0xFFFF, pcTemplate, acName, pstLineInfo->vMissile, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vMissile);
        }

        strncpy(m_astMissiles[pstLineInfo->vMissile].vMissile, acOutput, sizeof(m_astMissiles[pstLineInfo->vMissile].vMissile));
        String_Trim(m_astMissiles[pstLineInfo->vMissile].vMissile);
        m_iMisslesHaveEmpty |= !m_astMissiles[pstLineInfo->vMissile].vMissile[0];

        m_iMisslesCount++;
        return 1;
    }

    return 0;
}

static int Missiles_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vMissile);

        return 1;
    }
    else if ( isD2SigmaActive() && Missiles2_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static int Missiles_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "SrcDamage") )
    {
        if ( 0xFF == pstLineInfo->vSrcDamage )
        {
            strcpy(acOutput, "-1");
            return 1;
        }
    }

    return 0;
}

static void Missiles_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Missile, MISSILE);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, MissileSkill, BitCombined, 15, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Half2HSrc, BitCombined, 14, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, NoUniqueMod, BitCombined, 13, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, NoMultiShot, BitCombined, 12, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SrcTown, BitCombined, 11, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Town, BitCombined, 10, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ReturnFire, BitCombined, 9, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ApplyMastery, BitCombined, 8, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SoftHit, BitCombined, 7, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, GetHit, BitCombined, 6, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ClientSend, BitCombined, 5, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, CanDestroy, BitCombined, 4, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, CanSlow, BitCombined, 3, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Pierce, BitCombined, 2, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Explosion, BitCombined, 1, USHORT_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, LastCollide, BitCombined, 0, USHORT_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pCltDoFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pCltHitFunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvDoFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvHitFunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvDmgFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TravelSound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExplosionMissile, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile1, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile2, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile3, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile1, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile2, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile3, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile4, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile1, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile2, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile3, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile1, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile2, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile3, MISSILE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile4, MISSILE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ProgSound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ProgOverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dParam2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Range, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevRange, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VelLev, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxVel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Accel, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, animrate, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, xoffset, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, yoffset, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, zoffset, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitFlags, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResultFlags, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KnockBack, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxDamage, UINT);
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Emax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen3, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSrcTown, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcDamage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcMissDmg, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Holy, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flicker, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InitSteps, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Activate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LoopAnim, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CelFile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimLen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RandStart, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubLoop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStart, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideType, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Collision, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClientCol, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideKill, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideFriend, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextHit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextDelay, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Size, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHit, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysExplode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Qty, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpecialSetup, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitShift, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRate, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumDirections, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LocalBlood, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimSpeed, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrvCalc1, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltCalc1, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SHitCalc1, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CHitCalc1, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgCalc1, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgSymPerCalc, MISSCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EDmgSymPerCalc, MISSCODE);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, EOL, EOL);
}

int process_missiles(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_MISSILES_109) )
    {
        return process_missiles109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(Missiles2, acTemplatePath, acBinPath, acTxtPath);
            Missiles_InitValueMap(pstValueMap, pstLineInfo);

            m_iMisslesCount = 0;
            Lookup_Missile = Missiles_GetMissile;

            m_stCallback.pfnConvertValue = Missiles_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? Missiles2_ExternList : m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misscode, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Missiles_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Missiles_FieldProc;
            m_stCallback.pfnConvertValue = Missiles_ConvertValue;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? Missiles2_ExternList : m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


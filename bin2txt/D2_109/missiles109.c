#include "../global.h"

#define FILE_PREFIX "Missiles"
#define NAME_PREFIX "ml"

static char *m_apcNotUsed[] =
{
    "Param1 Comment",
    "Param2 Comment",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Missile",
    "Id",
    NULL,
};

static int Missiles_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_MISSILES_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Missile") )
    {
        char acName[65] = {0};
        String_StripFileName(pstLineInfo->vCelFile, acName, 64);

        if ( !String_BuildName(FORMAT(missiles), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "Id") )
    {
        sprintf(acOutput, "%u", iLineNo);

        return 1;
    }

    return 0;
}

static void Missiles_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_MISSILES_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxVel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Accel, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Range, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevRange, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flicker, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InitSteps, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Activate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LoopAnim, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CelFile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimLen, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RandStart, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubLoop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStart, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideType, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Collision, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClientCol, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideKill, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideFriend, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LastCollide, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CanDestroy, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClientSend, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextHit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextDelay, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Size, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysExplode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Explosion, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CanSlow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReturnFire, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GetHit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KnockBack, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Qty, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pierce, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Open, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beta, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpecialSetup, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitShift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevDam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevDam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevDam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EType, ELEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRate, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumDirections, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimSpeed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LocalBlood, UCHAR);
}

int process_missiles109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_MISSILES_109 *pstLineInfo = (ST_MISSILES_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Missiles_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Missiles_FieldProc;
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


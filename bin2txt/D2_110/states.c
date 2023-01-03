#include "../global.h"

#define FILE_PREFIX "States"
#define NAME_PREFIX "st"


typedef struct
{
    unsigned short vstate;
    unsigned short voverlay1; //overlay

    unsigned short voverlay2; //overlay
    unsigned short voverlay3; //overlay

    unsigned short voverlay4; //overlay
    unsigned short vcastoverlay; //overlay

    unsigned short vremoverlay; //overlay
    unsigned short vpgsvoverlay; //overlay

#if 1
    unsigned char vCombinedBits1;
    unsigned char vCombinedBits2;
    unsigned char vCombinedBits3;
    unsigned char vCombinedBits4;
    unsigned char vCombinedBits5;
#else
    unsigned char vdamblue : 1;
    unsigned char vremhit : 1;
    unsigned char vactive : 1;
    unsigned char vpgsv : 1;

    unsigned char vtransform : 1;
    unsigned char vhide : 1;
    unsigned char vaura : 1;
    unsigned char vnosend : 1;

    unsigned char vbossstaydeath : 1;
    unsigned char vmonstaydeath : 1;
    unsigned char vplrstaydeath : 1;
    unsigned char vcurable : 1;

    unsigned char vcurse : 1;
    unsigned char vattred : 1;
    unsigned char vattblue : 1;
    unsigned char vdamred : 1;

    unsigned char vrpblue : 1;
    unsigned char vrlblue : 1;
    unsigned char vrcblue : 1;
    unsigned char vrfblue : 1;

    unsigned char varmblue : 1;
    unsigned char vblue : 1;
    unsigned char vrestrict : 1;
    unsigned char vdisguise : 1;

    unsigned char vshatter : 1;
    unsigned char vexp : 1;
    unsigned char vrpred : 1;
    unsigned char vrlred : 1;

    unsigned char vrcred : 1;
    unsigned char vrfred : 1;
    unsigned char varmred : 1;
    unsigned char vstambarblue : 1;

    unsigned char vnotondead : 1;
    unsigned char vmeleeonly : 1;
    unsigned char vbossinv : 1;
    unsigned char vnoclear : 1;

    unsigned char vnooverlays : 1;
    unsigned char vgreen : 1;
    unsigned char vudead : 1;
    unsigned char vlife : 1;
#endif

    unsigned char pad0x15[3];

    unsigned short vstat; //ItemStatCost
    unsigned short vsetfunc;

    unsigned short vremfunc;
    unsigned short vgroup;

    unsigned char vcolorpri;
    unsigned char vcolorshift;
    unsigned char vlightmysubr;
    unsigned char vlightmysubg;

    unsigned char vlightmysubb;
    unsigned char pad0x25;
    unsigned short vonsound; //sounds

    unsigned short voffsound; //sounds
    unsigned short vitemtype; //itemtypes

    unsigned char vitemtrans; //colors
    unsigned char vgfxtype;
    unsigned short vgfxclass;

    unsigned short vcltevent; //events
    unsigned short vclteventfunc;
    unsigned short vcltactivefunc;
    unsigned short vsrvactivefunc;

    unsigned short vskill; //skill
    unsigned short vmissile; //missile
} ST_LINE_INFO;

typedef struct
{
    char vstate[64];
} ST_ITEM_STATES;

static char *m_apcNotUsed[] =
{
    "immed",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "id",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iStatesCount = 0;
static unsigned int m_iStatesHaveEmpty = 0;
static ST_ITEM_STATES *m_astStates = NULL;

MODULE_SETLINES_FUNC(m_astStates, ST_ITEM_STATES);
MODULE_HAVENAME_FUNC(m_astStates, vstate, m_iStatesCount);

char *States_GetState(unsigned int id)
{
    if ( id < m_iStatesCount )
    {
        return m_astStates[id].vstate;
    }

    if ( id == -1 && m_iStatesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int States_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "state") )
    {
        char *pcName = NULL;
        ( (pcName = Lookup_Overlay(pstLineInfo->voverlay1)) ||
          (pcName = Lookup_Overlay(pstLineInfo->voverlay2)) ||
          (pcName = Lookup_Overlay(pstLineInfo->voverlay3)) ||
          (pcName = Lookup_Overlay(pstLineInfo->voverlay4)) ||
          (pcName = Lookup_Overlay(pstLineInfo->vcastoverlay)) ||
          (pcName = Lookup_Overlay(pstLineInfo->vremoverlay)) ||
          (pcName = Lookup_Overlay(pstLineInfo->vpgsvoverlay)) ||
          (pstLineInfo->vonsound && (pcName = Lookup_Sound(pstLineInfo->vonsound))) ||
          (pstLineInfo->voffsound && (pcName = Lookup_Sound(pstLineInfo->voffsound))) );

        if ( !String_BuildName(FORMAT(states), 0xFFFF, pcTemplate, pcName, pstLineInfo->vstate, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vstate);
        }

        strncpy(m_astStates[pstLineInfo->vstate].vstate, acOutput, sizeof(m_astStates[pstLineInfo->vstate].vstate));
        String_Trim(m_astStates[pstLineInfo->vstate].vstate);
        m_iStatesHaveEmpty |= !m_astStates[pstLineInfo->vstate].vstate[0];

        m_iStatesCount++;
        return 1;
    }

    return 0;
}

static int States_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "id") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vstate);

        return 1;
    }

    return 0;
}

static void States_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay1, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay2, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay3, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay4, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, castoverlay, OVERLAY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, removerlay, OVERLAY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pgsvoverlay, OVERLAY);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, damblue, CombinedBits1, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, remhit, CombinedBits1, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, active, CombinedBits1, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, pgsv, CombinedBits1, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, transform, CombinedBits1, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, hide, CombinedBits1, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, aura, CombinedBits1, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, nosend, CombinedBits1, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, bossstaydeath, CombinedBits2, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, monstaydeath, CombinedBits2, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, plrstaydeath, CombinedBits2, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, curable, CombinedBits2, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, curse, CombinedBits2, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, attred, CombinedBits2, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, attblue, CombinedBits2, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, damred, CombinedBits2, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rpblue, CombinedBits3, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rlblue, CombinedBits3, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rcblue, CombinedBits3, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rfblue, CombinedBits3, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, armblue, CombinedBits3, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, blue, CombinedBits3, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, restrict, CombinedBits3, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, disguise, CombinedBits3, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, shatter, CombinedBits4, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, exp, CombinedBits4, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rpred, CombinedBits4, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rlred, CombinedBits4, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rcred, CombinedBits4, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, rfred, CombinedBits4, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, armred, CombinedBits4, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, stambarblue, CombinedBits4, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, notondead, CombinedBits5, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, meleeonly, CombinedBits5, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, bossinv, CombinedBits5, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noclear, CombinedBits5, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, nooverlays, CombinedBits5, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, green, CombinedBits5, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, udead, CombinedBits5, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, life, CombinedBits5, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setfunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, remfunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, colorpri, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, colorshift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubg, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubb, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, onsound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, offsound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemtype, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemtrans, COLOR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gfxtype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gfxclass, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltevent, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, clteventfunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltactivefunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvactivefunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missile, MISSILE);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);
}

int process_states(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_STATES_109) )
    {
        return process_states109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            States_InitValueMap(pstValueMap, pstLineInfo);

            m_iStatesCount = 0;
            Lookup_State = States_GetState;

            m_stCallback.pfnConvertValue = States_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            States_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = States_FieldProc;
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


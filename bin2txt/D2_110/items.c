#include "../global.h"

#define FILE_WEAPONS "Weapons"
#define FILE_ARMOR "Armor"
#define FILE_MISC "Misc"

typedef struct
{//total 424 bytes
    unsigned char vflippyfile[32];
    unsigned char vinvfile[32];
    unsigned char vuniqueinvfile[32];
    unsigned char vsetinvfile[32];

    unsigned char vcode[4];
    unsigned char vnormcode[4];
    unsigned char vubercode[4];
    unsigned char vultracode[4];
    unsigned char valternategfx[4];

    unsigned int vpSpell;

    unsigned short vstate;
    unsigned short vcstate1;
    unsigned short vcstate2;
    unsigned short vstat1;
    unsigned short vstat2;
    unsigned short vstat3;

    unsigned int vcalc1;
    unsigned int vcalc2;
    unsigned int vcalc3;
    unsigned int vlen;

    unsigned short vspelldesc;
    unsigned short vspelldescstr;
    unsigned int vspelldesccalc;

    unsigned char vBetterGem[4];
    unsigned char vwclass[4];
    unsigned char v2handedwclass[4];
    unsigned char vTMogType[4];

    unsigned int vminac;
    unsigned int vmaxac;
    unsigned int vgamblemyspcost;
    int vspeed;

    unsigned int vbitfield1;
    unsigned int vcost;

    unsigned int vminstack;
    unsigned int vmaxstack;
    unsigned int vspawnstack;
    unsigned int vgemoffset;

    unsigned short vnamestr;
    unsigned short vversion;
    unsigned short vautomyspprefix;
    unsigned short vmissiletype;

    unsigned char vrarity;
    unsigned char vlevel;
    unsigned char vmindam;
    unsigned char vmaxdam;

    unsigned char vminmisdam;
    unsigned char vmaxmisdam;
    unsigned char v2handmindam;
    unsigned char v2handmaxdam;

    unsigned short vrangeadder;
    unsigned short vStrBonus;
    unsigned short vDexBonus;
    unsigned short vreqstr;

    unsigned short vreqdex;
    unsigned char vabsorbs;
    unsigned char vinvwidth;

    unsigned char vinvheight;
    unsigned char vblock;
    unsigned char vdurability;
    unsigned char vnodurability;

    unsigned char pad0x114;
    unsigned char vcomponent;
    unsigned char vrArm;
    unsigned char vlArm;

    unsigned char vTorso;
    unsigned char vLegs;
    unsigned char vrSPad;
    unsigned char vlSPad;

    unsigned char v2handed;
    unsigned char vuseable;
    unsigned short vtype;

    unsigned short vtype2;
    unsigned char pad0x122[2];

    unsigned short vdropsound;
    unsigned short vusesound;

    unsigned char vdropsfxframe;
    unsigned char vunique;
    unsigned char vquest;
    unsigned char vquestdiffcheck;

    unsigned char vtransparent;
    unsigned char vtranstbl;
    unsigned char pad0x12E;
    unsigned char vlightradius;

    unsigned char vbelt;
    unsigned char vautobelt;
    unsigned char vstackable;
    unsigned char vspawnable;

    char vspellicon;
    unsigned char vdurwarning;
    unsigned char vqntwarning;
    unsigned char vhasinv;

    unsigned char vgemsockets;
    unsigned char vTransmogrify;
    unsigned char vTMogMin;
    unsigned char vTMogMax;

    unsigned char vhitmyspclass;
    unsigned char v1or2handed;
    unsigned char vgemapplytype;
    unsigned char vlevelreq;

    unsigned char vmagicmysplvl;
    unsigned char vTransform;
    unsigned char vInvTrans;
    unsigned char vcompactsave;

    unsigned char vSkipName;
    unsigned char vNameable;
    unsigned char vAkaraMin;
    unsigned char vGheedMin;

    unsigned char vCharsiMin;
    unsigned char vFaraMin;
    unsigned char vLysanderMin;
    unsigned char vDrognanMin;

    unsigned char vHraltiMin;
    unsigned char vAlkorMin;
    unsigned char vOrmusMin;
    unsigned char vElzixMin;

    unsigned char vAshearaMin;
    unsigned char vCainMin;
    unsigned char vHalbuMin;
    unsigned char vJamellaMin;

    unsigned char vMalahMin;
    unsigned char vLarzukMin;
    unsigned char vDrehyaMin;
    unsigned char vAkaraMax;

    unsigned char vGheedMax;
    unsigned char vCharsiMax;
    unsigned char vFaraMax;
    unsigned char vLysanderMax;

    unsigned char vDrognanMax;
    unsigned char vHraltiMax;
    unsigned char vAlkorMax;
    unsigned char vOrmusMax;

    unsigned char vElzixMax;
    unsigned char vAshearaMax;
    unsigned char vCainMax;
    unsigned char vHalbuMax;

    unsigned char vJamellaMax;
    unsigned char vMalahMax;
    unsigned char vLarzukMax;
    unsigned char vDrehyaMax;

    unsigned char vAkaraMagicMin;
    unsigned char vGheedMagicMin;
    unsigned char vCharsiMagicMin;
    unsigned char vFaraMagicMin;

    unsigned char vLysanderMagicMin;
    unsigned char vDrognanMagicMin;
    unsigned char vHraltiMagicMin;
    unsigned char vAlkorMagicMin;

    unsigned char vOrmusMagicMin;
    unsigned char vElzixMagicMin;
    unsigned char vAshearaMagicMin;
    unsigned char vCainMagicMin;

    unsigned char vHalbuMagicMin;
    unsigned char vJamellaMagicMin;
    unsigned char vMalahMagicMin;
    unsigned char vLarzukMagicMin;

    unsigned char vDrehyaMagicMin;
    unsigned char vAkaraMagicMax;
    unsigned char vGheedMagicMax;
    unsigned char vCharsiMagicMax;

    unsigned char vFaraMagicMax;
    unsigned char vLysanderMagicMax;
    unsigned char vDrognanMagicMax;
    unsigned char vHraltiMagicMax;

    unsigned char vAlkorMagicMax;
    unsigned char vOrmusMagicMax;
    unsigned char vElzixMagicMax;
    unsigned char vAshearaMagicMax;

    unsigned char vCainMagicMax;
    unsigned char vHalbuMagicMax;
    unsigned char vJamellaMagicMax;
    unsigned char vMalahMagicMax;

    unsigned char vLarzukMagicMax;
    unsigned char vDrehyaMagicMax;
    unsigned char vAkaraMagicLvl;
    unsigned char vGheedMagicLvl;

    unsigned char vCharsiMagicLvl;
    unsigned char vFaraMagicLvl;
    unsigned char vLysanderMagicLvl;
    unsigned char vDrognanMagicLvl;

    unsigned char vHraltiMagicLvl;
    unsigned char vAlkorMagicLvl;
    unsigned char vOrmusMagicLvl;
    unsigned char vElzixMagicLvl;

    unsigned char vAshearaMagicLvl;
    unsigned char vCainMagicLvl;
    unsigned char vHalbuMagicLvl;
    unsigned char vJamellaMagicLvl;

    unsigned char vMalahMagicLvl;
    unsigned char vLarzukMagicLvl;
    unsigned char vDrehyaMagicLvl;
    unsigned char pad0x19B;

    unsigned char vNightmareUpgrade[4];
    unsigned char vHellUpgrade[4];

    unsigned char vPermStoreItem;
    unsigned char vmultibuy;
    unsigned char pad0x1A6[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vcode[5];
    unsigned short vnamestr;
} ST_ITEM;

static char *m_apcInternalProcess[] =
{
    "name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "OpenBetaGfx",
    "szFlavorText",
    "special",
    "spelloffset",
    "throwable",
    "quivered",
    "namco",
    "Source Art",
    "Game Art",
    "*name",
    "*eol",
    "",
    NULL,
};

static ENUM_MODULE_ID m_enCurrentModule;
static unsigned int m_iBinStructSize = 0;
static unsigned int m_iItemCount = 0;
static ST_ITEM *m_astItem = NULL;

static void Items_SetLines(unsigned int uiLines)
{
    if ( m_astItem == NULL )
    {
        m_astItem = MemMgr_Malloc(sizeof(ST_ITEM) * uiLines);
    }
    else
    {
        m_astItem = MemMgr_Realloc(m_astItem, sizeof(ST_ITEM) * (m_iItemCount + uiLines));
    }

    if ( m_astItem == NULL )
    {
        my_error("malloc fail with %u lines\r\n", uiLines);
    }
    else
    {
        memset(&m_astItem[m_iItemCount], 0, sizeof(ST_ITEM) * uiLines);
    }
}

static char *Items_GetCode(unsigned int id)
{
    if ( id < m_iItemCount )
    {
        return m_astItem[id].vcode;
    }

    return NULL;
}

static unsigned int Items_GetString(unsigned int id)
{
    if ( id < m_iItemCount )
    {
        return m_astItem[id].vnamestr;
    }

    return 0xFFFF;
}

static int Items_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        m_astItem[m_iItemCount].vnamestr = pstLineInfo->vnamestr;
        strncpy(m_astItem[m_iItemCount].vcode, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        String_Trim(m_astItem[m_iItemCount].vcode);

        Map_Items = Tree_Insert(Map_Items, m_astItem[m_iItemCount].vcode, m_iItemCount);

        m_iItemCount++;
        return 0;
    }
    else if ( !stricmp(acKey, "rarity") )
    {
        if ( (999 % 256) == pstLineInfo->vrarity )
        {
            strcpy(acOutput, "999");
            return 1;
        }
    }

    return 0;
}

static int Items_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*name") )
    {
        String_BuildName(Get_ModuleNameFormat(m_enCurrentModule), Get_ModuleNameSize(m_enCurrentModule), Get_ModuleNameSeparator(m_enCurrentModule),
            pstLineInfo->vspelldescstr, pcTemplate, NULL, iLineNo, NULL, acOutput);

        return 1;
    }
    if ( !stricmp(acKey, "name") )
    {
        if ( !String_BuildName(Get_ModuleNameFormat(m_enCurrentModule), Get_ModuleNameSize(m_enCurrentModule), Get_ModuleNameSeparator(m_enCurrentModule),
            pstLineInfo->vnamestr, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        }

        return 1;
    }

    return 0;
}

static void Items_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniqueinvfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setinvfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, normcode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ubercode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ultracode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, alternategfx, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSpell, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cstate1, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cstate2, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc1, ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc2, ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc3, ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, len, ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldesc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldescstr, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldesccalc, ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BetterGem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, wclass, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handedwclass, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogType, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minac, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxac, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gamblemyspcost, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, speed, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bitfield1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemoffset, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, namestr, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, automyspprefix, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missiletype, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mindam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxdam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmisdam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmisdam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handmindam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handmaxdam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rangeadder, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrBonus, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DexBonus, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqstr, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqdex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, absorbs, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invwidth, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invheight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, block, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durability, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nodurability, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, component, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArm, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArm, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Torso, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Legs, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rSPad, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lSPad, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, useable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type2, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, unique, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questdiffcheck, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transparent, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transtbl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightradius, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, belt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, autobelt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stackable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spellicon, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qntwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hasinv, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemsockets, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Transmogrify, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hitmyspclass, HITCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1or2handed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemapplytype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, magicmysplvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Transform, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvTrans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, compactsave, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkipName, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nameable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NightmareUpgrade, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HellUpgrade, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PermStoreItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multibuy, UCHAR);
}

static void Items_InitDepend(char *acTemplatePath, char *acBinPath, char *acTxtPath, ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(hitclass, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
    MODULE_DEPEND_CALL(itemscode, acTemplatePath, acBinPath, acTxtPath);
    Items_InitValueMap(pstValueMap, pstLineInfo);

    Lookup_Item = Items_GetCode;
    Lookup_ItemString = Items_GetString;

    m_stCallback.pfnFieldProc = Items_FieldProc;
    m_stCallback.pfnConvertValue = Items_ConvertValue;
    m_stCallback.pfnSetLines = Items_SetLines;
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
    m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
}

int process_weapons(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_ITEM_109) )
    {
        return process_items109(FILE_WEAPONS, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_WEAPONS);
            break;

        case EN_MODULE_SELF_DEPEND:
            Items_InitDepend(acTemplatePath, acBinPath, acTxtPath, pstValueMap, pstLineInfo);
            m_enCurrentModule = MODULE_ID(weapons);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_WEAPONS, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            ( File_CopyFile(acBinPath, acTxtPath, "WeaponClass", ".txt") ||
              File_CopyFile(acTemplatePath, acTxtPath, "WeaponClass", ".txt") );
            break;

        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

int process_armor(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_ITEM_109) )
    {
        return process_items109(FILE_ARMOR, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(weapons, acTemplatePath, acBinPath, acTxtPath); // Do not move; Weapons -> Armor -> Misc should be loaded in exact order
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_ARMOR);
            break;

        case EN_MODULE_SELF_DEPEND:
            Items_InitDepend(acTemplatePath, acBinPath, acTxtPath, pstValueMap, pstLineInfo);
            m_enCurrentModule = MODULE_ID(armor);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_ARMOR, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

int process_misc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_ITEM_109) )
    {
        return process_items109(FILE_MISC, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(armor, acTemplatePath, acBinPath, acTxtPath); // Do not move; Weapons -> Armor -> Misc should be loaded in exact order
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_MISC);
            break;

        case EN_MODULE_SELF_DEPEND:
            Items_InitDepend(acTemplatePath, acBinPath, acTxtPath, pstValueMap, pstLineInfo);
            m_enCurrentModule = MODULE_ID(misc);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_MISC, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}
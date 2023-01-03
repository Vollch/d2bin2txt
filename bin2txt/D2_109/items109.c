#include "../global.h"

typedef struct
{
    unsigned char vcode[5];
    unsigned char vname[64];
} ST_ITEM;

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
    NULL,
};

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

static char *Items_GetName(unsigned int id)
{
    if ( id < m_iItemCount )
    {
        return m_astItem[id].vname;
    }

    return NULL;
}

static int Items_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_ITEM_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        strncpy(m_astItem[m_iItemCount].vcode, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        String_Trim(m_astItem[m_iItemCount].vcode);
        strncpy(m_astItem[m_iItemCount].vname, pstLineInfo->vname, sizeof(pstLineInfo->vname));
        String_Trim(m_astItem[m_iItemCount].vname);

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

static void Items_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_ITEM_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniqueinvfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setinvfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BetterGem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, normcode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ubercode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ultracode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, alternategfx, STRING);
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rangeadder, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrBonus, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DexBonus, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqstr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqdex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, absorbs, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invwidth, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invheight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, block, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durability, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nodurability, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missile, UCHAR);
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, subtype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sound, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, unique, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, quest, UCHAR);
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
}

int process_items109(char* pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_ITEM_109 *pstLineInfo = (ST_ITEM_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(hitclass, acTemplatePath, acBinPath, acTxtPath);
            Items_InitValueMap(pstValueMap, pstLineInfo);

            Lookup_Item = Items_GetCode;
            Lookup_ItemName = Items_GetName;

            m_stCallback.pfnConvertValue = Items_ConvertValue;
            m_stCallback.pfnSetLines = Items_SetLines;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, pcFilename, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


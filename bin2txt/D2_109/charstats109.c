#include "../global.h"

#define FILE_PREFIX "CharStats"

typedef struct
{
    char vclass[17];
} ST_CHAR_STATS;

static char *m_apcNotUsed[] =
{
    "tot",
    "Comment",
    "#walk",
    "#run",
    "#swing",
    "#spell",
    "#gethit",
    "#bow",
    NULL,
};

static unsigned int m_iCharStatsCount = 0;
static unsigned int m_iCharStatsHaveEmpty = 0;
static ST_CHAR_STATS *m_astCharStats = NULL;

MODULE_SETLINES_FUNC(m_astCharStats, ST_CHAR_STATS);

static char *CharStats_GetName(unsigned int id)
{
    if ( id < m_iCharStatsCount )
    {
        return m_astCharStats[id].vclass;
    }

    if ( id == -1 && m_iCharStatsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int CharStats_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_CHARSTATS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "class") )
    {
        strncpy(m_astCharStats[m_iCharStatsCount].vclass, pstLineInfo->vclass, sizeof(pstLineInfo->vclass));
        String_Trim(m_astCharStats[m_iCharStatsCount].vclass);

        m_iCharStatsCount++;
    }

    return 0;
}

static void CharStats_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_CHARSTATS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, str, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, int, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stamina, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hpadd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentStr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentInt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentDex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentVit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaRegen, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHitFactor, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WalkVelocity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunVelocity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunDrain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifePerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaminaPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifePerVitality, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaminaPerVitality, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaPerMagic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlockFactor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StartSkill, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseWClass, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10loc, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10count, UCHAR);
}

int process_charstats109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_CHARSTATS_109 *pstLineInfo = (ST_CHARSTATS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            CharStats_InitValueMap(pstValueMap, pstLineInfo);

            m_iCharStatsCount = 0;
            Lookup_ClassName = CharStats_GetName;

            m_stCallback.pfnConvertValue = CharStats_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "CharStats"

typedef struct
{
    char acHead[32];
    char vclass[16];

    unsigned char vstr;
    unsigned char vdex;
    unsigned char vint;
    unsigned char vvit;

    unsigned char vstamina;
    unsigned char vhpadd;
    unsigned char vPercentStr;
    unsigned char vPercentInt;

    unsigned char vPercentDex;
    unsigned char vPercentVit;
    unsigned char vManaRegen;
    unsigned char pad0x3B;

    int vToHitFactor;

    unsigned char vWalkVelocity;
    unsigned char vRunVelocity;
    unsigned char vRunDrain;
    unsigned char vLifePerLevel;

    unsigned char vStaminaPerLevel;
    unsigned char vManaPerLevel;
    unsigned char vLifePerVitality;
    unsigned char vStaminaPerVitality;

    unsigned char vManaPerMagic;
    unsigned char vBlockFactor;
    unsigned char pad0x4A[2];

    char vbaseWClass[4];

    unsigned char vStatPerLevel;
    unsigned char pad0x51;
    unsigned short vStrAllSkills;

    unsigned short vStrSkillTab1;
    unsigned short vStrSkillTab2;

    unsigned short vStrSkillTab3;
    unsigned short vStrClassOnly;

    char vitem1[4];
    unsigned char vitem1loc;
    unsigned char vitem1count;
    unsigned char pad0x62[2];

    char vitem2[4];
    unsigned char vitem2loc;
    unsigned char vitem2count;
    unsigned char pad0x6A[2];

    char vitem3[4];
    unsigned char vitem3loc;
    unsigned char vitem3count;
    unsigned char pad0x72[2];

    char vitem4[4];
    unsigned char vitem4loc;
    unsigned char vitem4count;
    unsigned char pad0x7A[2];

    char vitem5[4];
    unsigned char vitem5loc;
    unsigned char vitem5count;
    unsigned char pad0x82[2];

    char vitem6[4];
    unsigned char vitem6loc;
    unsigned char vitem6count;
    unsigned char pad0x8A[2];

    char vitem7[4];
    unsigned char vitem7loc;
    unsigned char vitem7count;
    unsigned char pad0x92[2];

    char vitem8[4];
    unsigned char vitem8loc;
    unsigned char vitem8count;
    unsigned char pad0x9A[2];

    char vitem9[4];
    unsigned char vitem9loc;
    unsigned char vitem9count;
    unsigned char pad0xA2[2];

    char vitem10[4];
    unsigned char vitem10loc;
    unsigned char vitem10count;
    unsigned char pad0xAA[2];

    unsigned short vStartSkill;
    unsigned short vSkillmysp1;
    unsigned short vSkillmysp2;
    unsigned short vSkillmysp3;
    unsigned short vSkillmysp4;
    unsigned short vSkillmysp5;
    unsigned short vSkillmysp6;
    unsigned short vSkillmysp7;
    unsigned short vSkillmysp8;
    unsigned short vSkillmysp9;
    unsigned short vSkillmysp10;

    unsigned char pad0xC2[2];
} ST_LINE_INFO;

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

static unsigned int m_iBinStructSize = 0;
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

static char *CharStats_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vclass, sizeof(pstLineInfo->vclass));
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static int CharStats_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "class") )
    {
        strncpy(m_astCharStats[m_iCharStatsCount].vclass, pstLineInfo->vclass, sizeof(pstLineInfo->vclass));
        String_Trim(m_astCharStats[m_iCharStatsCount].vclass);

        m_iCharStatsCount++;
    }

    return 0;
}

static void CharStats_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseWClass, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrAllSkills, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab2, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrClassOnly, TBL_STRING);

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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StartSkill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp2, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp4, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp5, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp6, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp7, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp8, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp9, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp10, SKILL);
}

int process_charstats(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_CHARSTATS_109) )
    {
        return process_charstats109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(CharStatsExp, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            CharStats_InitValueMap(pstValueMap, pstLineInfo);

            m_iCharStatsCount = 0;
            Lookup_ClassName = CharStats_GetName;

            m_stCallback.pfnConvertValue = CharStats_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            //m_stCallback.pfnGetKey = CharStats_GetKey;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            if ( isD2SigmaActive() )
            {
                m_stCallback.pfnFieldProc = CharStatsExp_ExternProc;
                m_stCallback.ppcKeyInternalProcess = CharStatsExp_ExternList;
            }

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


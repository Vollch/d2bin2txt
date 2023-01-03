#include "../global.h"

#define FILE_PREFIX "DifficultyLevels"
#define NAME_PREFIX "dl"

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static int DifficultyLevels_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Name") )
    {
        if ( !String_BuildName(FORMAT(difficultylevels), 0xFFFF, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

static void DifficultyLevels_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_DIFFICULTYLEVELS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResistPenalty, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeathExpPenalty, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UberCodeOddsNormal, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UberCodeOddsGood, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterSkillBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterFreezeDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterColdDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AiCurseDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UltraCodeOddsNormal, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UltraCodeOddsGood, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifeStealDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaStealDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExtraUniqueMonsters, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UniqueDamageBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChampionDamageBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HireableBossDamagePercent, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaticFieldMin, UINT);
}

int process_difficultylevels109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_DIFFICULTYLEVELS_109 *pstLineInfo = (ST_DIFFICULTYLEVELS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            DifficultyLevels_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = DifficultyLevels_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

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


#include "../global.h"

#define FILE_PREFIX "Skills"

typedef struct
{
    char vskill[64];
} ST_SKILLS;

static char *m_apcNotUsed[] =
{
    "What's left? - code",
    "What's Left - art",
    "Param1 Description",
    "Param2 Description",
    "Param3 Description",
    "Param4 Description",
    "Param5 Description",
    "Param6 Description",
    "effect",
    "leveleffect",
    "Done",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Id",
    NULL,
};

static unsigned int m_iSkillsCount = 0;
static unsigned int m_iSkillsHaveEmpty = 0;
static ST_SKILLS *m_astSkills = NULL;

MODULE_SETLINES_FUNC(m_astSkills, ST_SKILLS);

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
    ST_SKILLS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "skill") )
    {
        if ( !strncmp(pcTemplate, pstLineInfo->vskill, sizeof(pstLineInfo->vskill)) )
        {
            strncpy(acOutput, pcTemplate, sizeof(m_astSkills[m_iSkillsCount].vskill));
        }
        else
        {
            strncpy(acOutput, pstLineInfo->vskill, sizeof(pstLineInfo->vskill));
        }

        strncpy(m_astSkills[m_iSkillsCount].vskill, acOutput, sizeof(m_astSkills[m_iSkillsCount].vskill));
        String_Trim(m_astSkills[m_iSkillsCount].vskill);
        m_iSkillsHaveEmpty |= !m_astSkills[m_iSkillsCount].vskill[0];

        m_iSkillsCount++;
        return 1;
    }

    return 0;
}

static int Skills_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_SKILLS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "skill") )
    {
        strcpy(acOutput, m_astSkills[iLineNo].vskill);
        return 1;
    }

    return 0;
}

static int Skills_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_SKILLS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        sprintf(acOutput, "%u", iLineNo);

        return 1;
    }

    return 0;
}

static void Skills_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_SKILLS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skill, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monster, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enhanceable, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClassReq, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AttackRank, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemclass6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, anim, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monanim, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, seqnum, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Durability, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shiver, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UseAttackRate, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LineOfSight, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemeffect, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetableOnly, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SearchEnemyXY, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SearchMonsterNear, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SelectDead, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SearchOpenXY, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetPet, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetAlly, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, range, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AttackNoMana, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqlevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqstr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqdex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqint, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqvit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill2, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, castermyspstate, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, victimmyspstate, STATE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, isaura, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Delay, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skillpage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skillrow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skillcolumn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, iconcel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, leftskl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, manashift, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mana, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmana, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Interrupt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InTown, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Periodic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Finishing, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Passive, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InGame, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Open, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beta, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevToHit, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitShift, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcDam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinDam, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxDam, UINT);
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
}

int process_skills109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_SKILLS_109 *pstLineInfo = (ST_SKILLS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            Skills_InitValueMap(pstValueMap, pstLineInfo);

            m_iSkillsCount = 0;
            Lookup_Skill = Skills_GetSkillName;

            m_stCallback.pfnConvertValue = Skills_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Skills_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Skills_ConvertValue;
            m_stCallback.pfnFieldProc = Skills_FieldProc;
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

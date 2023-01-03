#include "../global.h"

#define FILE_PREFIX "Hireling"

static char *m_apcNotUsed[] =
{
    "Hireling",
    "SubType",
    "WType1",
    "WType2",
    NULL,
};

static void Hireling_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_HIRELING_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Seller, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gold, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExpmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HP, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Defense, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DefmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dex, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DexmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AR, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ARmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Share, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmysubMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmysubMax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Resist, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResistmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DefaultChance, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Head, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Torso, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shield, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill6, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance6, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLevel6, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HireDesc, HIREDESC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameFirst, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameLast, STRING);
}

int process_hireling109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_HIRELING_109 *pstLineInfo = (ST_HIRELING_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(hiredesc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Hireling_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "Hireling"

typedef struct
{
    unsigned int vVersion;
    unsigned int vId;
    unsigned int vClass;
    unsigned int vAct;
    unsigned int vDifficulty;
    unsigned int vSeller;
    unsigned int vGold;
    unsigned int vLevel;
    unsigned int vExpmyslashLvl;
    unsigned int vHP;

    unsigned int vHPmyslashLvl;
    unsigned int vDefense;
    unsigned int vDefmyslashLvl;
    unsigned int vStr;
    unsigned int vStrmyslashLvl;
    unsigned int vDex;
    unsigned int vDexmyslashLvl;
    unsigned int vAR;
    unsigned int vARmyslashLvl;
    unsigned int vShare;

    unsigned int vDmgmysubMin;
    unsigned int vDmgmysubMax;
    unsigned int vDmgmyslashLvl;
    unsigned int vResist;
    unsigned int vResistmyslashLvl;
    unsigned int vDefaultChance;

    unsigned int vHead;
    unsigned int vTorso;
    unsigned int vWeapon;
    unsigned int vShield;

    unsigned int vSkill1;   //skills
    unsigned int vSkill2;
    unsigned int vSkill3;
    unsigned int vSkill4;
    unsigned int vSkill5;
    unsigned int vSkill6;

    unsigned int vChance1;
    unsigned int vChance2;
    unsigned int vChance3;
    unsigned int vChance4;
    unsigned int vChance5;
    unsigned int vChance6;

    unsigned int vChancePerLvl1;
    unsigned int vChancePerLvl2;
    unsigned int vChancePerLvl3;
    unsigned int vChancePerLvl4;
    unsigned int vChancePerLvl5;
    unsigned int vChancePerLvl6;

    unsigned char vMode1;
    unsigned char vMode2;
    unsigned char vMode3;
    unsigned char vMode4;

    unsigned char vMode5;
    unsigned char vMode6;
    unsigned char vLevel1;
    unsigned char vLevel2;

    unsigned char vLevel3;
    unsigned char vLevel4;
    unsigned char vLevel5;
    unsigned char vLevel6;

    unsigned char vLvlPerLvl1;
    unsigned char vLvlPerLvl2;
    unsigned char vLvlPerLvl3;
    unsigned char vLvlPerLvl4;

    unsigned char vLvlPerLvl5;
    unsigned char vLvlPerLvl6;
    unsigned char vHireDesc; //hiredesc

    unsigned char vNameFirst[32];
    unsigned char vNameLast[32];
    unsigned char pad0x114[5];
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "Hireling",
    "SubType",
    "WType1",
    "WType2",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static void Hireling_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Version, UINT);
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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl6, UINT);

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

int process_hireling(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_HIRELING_109) )
    {
        return process_hireling109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
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


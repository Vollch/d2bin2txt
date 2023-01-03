#include "../global.h"

#define FILE_PREFIX "CharStats"

typedef struct
{
    char vitem[4]; //每个职业的第1-10个初始道具。
    unsigned char vitemloc; //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitemcount; //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x06[2]; //填充字节，无意义
} ST_ITEM_INFO;

typedef struct
{
    char acHead[32];    //填充字节，无意义

    char vclass[16];   //职业名称。

    unsigned char vstr;          //每个职业的初始力量值。
    unsigned char vdex;          //每个职业的初始敏捷值。
    unsigned char vint;          //每个职业的初始精力值。
    unsigned char vvit;          //每个职业的初始体力值。

    //tot：每个职业的初始属性值的总和。实际上没有用处，可以删除。
    unsigned char vstamina;      //每个职业的初始耐力值。
    unsigned char vhpadd;        //每个职业的初始生命值基数。
    //角色的最终初始生命值为hpadd + vit。
    unsigned char vPercentStr;   //无用参数。
    unsigned char vPercentInt;   //无用参数。

    unsigned char vPercentDex;   //无用参数。
    unsigned char vPercentVit;   //无用参数。
    unsigned char vManaRegen;   //每个职业的初始魔法值回复速度，含义为从魔法值为0到回复满需要多少秒。所以此列的值越小魔法回复速度越快。
    unsigned char pad0x3B;

    int vToHitFactor;   //每个职业的初始攻击准确率基数。

    unsigned char vWalkVelocity; //每个职业的初始走路速度。
    unsigned char vRunVelocity;  //每个职业的初始跑步速度。
    unsigned char vRunDrain;     //每个职业跑步时耐力的下降速度。数值越小表示跑步时耐力减少的越慢。
    unsigned char vLifePerLevel; //每个职业升级时增加的生命值因子，除以4后为每级实际增加的生命值。

    unsigned char vStaminaPerLevel;  //每个职业升级时增加的耐力值因子，除以4后为每级实际增加的耐力值。
    unsigned char vManaPerLevel; //每个职业升级时增加的法力值因子，除以4后为每级实际增加的法力值。
    unsigned char vLifePerVitality;  //每个职业每加一点体力增加的生命值因子，除以4后为每点体力实际增加的生命值。
    unsigned char vStaminaPerVitality;   //每个职业每加一点体力值增加的耐力值因子，除以4后为每点体力实际增加的耐力值。

    unsigned char vManaPerMagic; //每个职业每个一点精力增加的法力值因子，除以4后为每点精力值实际增加的法力值。
    unsigned char vBlockFactor;  //每个职业使用盾牌时的基础格挡概率。此值会加到盾牌格挡率的显示中。
    unsigned char pad0x4A[2];  //填充字节，无意义

    char vbaseWClass[4];   //空手时默认使用的武器类型。都默认为空手类型（这也算是一种武器类型），与WeaponClass.txt关联。

    unsigned char vStatPerLevel; //
    unsigned char pad0x51;
    unsigned short vStrAllSkills;

    unsigned short vStrSkillTab1;
    unsigned short vStrSkillTab2;

    unsigned short vStrSkillTab3;
    unsigned short vStrClassOnly;

    char vitem1[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem1loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem1count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x62[2];  //填充字节，无意义

    char vitem2[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem2loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem2count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x6A[2];  //填充字节，无意义

    char vitem3[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem3loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem3count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x72[2];  //填充字节，无意义

    char vitem4[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem4loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem4count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x7A[2];  //填充字节，无意义

    char vitem5[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem5loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem5count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x82[2];  //填充字节，无意义

    char vitem6[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem6loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem6count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x8A[2];  //填充字节，无意义

    char vitem7[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem7loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem7count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x92[2];  //填充字节，无意义

    char vitem8[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem8loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem8count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0x9A[2];  //填充字节，无意义

    char vitem9[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem9loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem9count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0xA2[2];  //填充字节，无意义

    char vitem10[4]; //每个职业的第1-10个初始道具。
    unsigned char vitem10loc;      //每个职业的第1-10个初始道具的位置。index，对应bodylocs.txt
    unsigned char vitem10count;    //每个职业的第1-10个初始道具的数量。
    unsigned char pad0xAA[2];  //填充字节，无意义

    unsigned short vStartSkill;  //每个职业的初始武器上所附加的技能。与Skills.txt关联。index FF无效，对应skills.txt
    unsigned short vSkillmysp1;  //每个职业的基础技能，包括投掷、踢击、回城、辨识、解除召唤等。index FF无效，对应skills.txt
    unsigned short vSkillmysp2;
    unsigned short vSkillmysp3;
    unsigned short vSkillmysp4;
    unsigned short vSkillmysp5;
    unsigned short vSkillmysp6;
    unsigned short vSkillmysp7;
    unsigned short vSkillmysp8;
    unsigned short vSkillmysp9;
    unsigned short vSkillmysp10;

    unsigned char pad0xC2[2];  //填充字节，无意义
} ST_LINE_INFO;

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

static char *CharStats_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vclass, sizeof(pstLineInfo->vclass));
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
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
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(CharStatsExp, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            CharStats_InitValueMap(pstValueMap, pstLineInfo);

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

        default:
            break;
    }

    return 1;
}


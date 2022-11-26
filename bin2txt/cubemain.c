#include "global.h"

#define FILE_PREFIX "cubemain"
#define NAME_PREFIX "cm"

/*
Title 	Cubemain.txt File Guide
Description 	by Nefarius & Myhrginoc
Sent by 	
OVERVIEW:

This is the file that controls one of the most interesting aspect in the game that is used by the horadic cube (that you get from second quest in act 2).

RELATED .TXT FILES:

This file is using:

    ItemTypes.txt
    Misc.txt
    Armor.txt
    Weapons.txt
    Setitems.txt
    Uniqueitems.txt
    Properities.txt
    Itemstatscost.txt



COLUMN DESCRIPTIONS :

description 	This column has no function, it only serves as a comment field to make it easier to find specific recipes.
enabled 	Boolean, this controls if a recipe is active in-game, 1 stands for yes and 0 stands for no.
ladder 	Boolean, 1 if only allowed in ladder on realms (TBD) (Note: Also works for single player, tcp/ip)
min diff 	minimum game difficulty to use recipe (0 = all difficulties, 1 = Nightmare and hell, 2 = hell only).
version 	Tells the game if this is a old classic, new classic or expansion recipe, 0=old classic d2, 1=new classic d2 and 100 is expansion recipe. (*I am not sure if 1 is used in this file, but this column works the same way it works in all the other 
item related files so it probably does.)
op 	replaces realtime field, can now select requirement for allowing recipe (See Appendix A for more details)
param 	replaces realtime field, can now select requirement for allowing recipe (for more details see Appendix A).
value 	replaces realtime field, can now select threshold for custom requirement (for more details see Appendix A).
class 	You can use this to make a recipe class specific by using the class codes, aka ama, bar, pal, nec, sor, dru and ass.
numinputs 	Controls the number of items you need to put into the cube for this recipe. If you are using the “qty” parameter in any inputs this number must include the sum of quantities.
inputs 1 through 7 	This controls the type of inputs used for the recipe, each cell stands for a different item. Also includes input parameters, please refer to Nefarius' Cubemain Code Reference in the Keep's resource section in order to read about 
these codes.

    input 1 - primary item of recipe, target of outputs for item transform recipes.
output 	Defines the first recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
lvl 	Controls the level of the item that is created in the first output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
plvl 	This column uses a portion of the players level for the output level.
ilvl 	This column uses a portion of the first input's level for the output level.
mod 1 through 5 	Defines additional attributes affixed to the first output item.

    mod # - the property code used to specify an attribute.
    mod # chance - the chance in percent the property will be assigned.
    mod # param - parameter field for properties that use parameters.
    mod # min - minimum field for properties that specify a range of values.
    mod # max - maximum field for properties that specify a range of values.

To make property have a fixed value make mod # min and mod # max the same.
output b 	Defines the second recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
b lvl 	Controls the level of the item that is created in the second output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
b plvl 	This column uses a portion of the players level for the output level.
b ilvl 	This column uses a portion of the (first or second ?TBD) input's level for the output level.
b mod 1 through 5 	Defines additional attributes affixed to the second output item. These fields work the same way as the mod # fields for the first item.
output c 	Defines the third recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
c lvl 	Controls the level of the item that is created in the third output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
c plvl 	This column uses a portion of the players level for the output level.
c ilvl 	This column uses a portion of the (first or third ?TBD) input's level for the output level.
c mod 1 through 5 	Defines additional attributes affixed to the third output item. These fields work the same way as the mod # fields for the first item.
*eol 	line terminator, must be filled if using MS Excel or similar spreadsheet that eats trailing tabs.


APPENDIX A by Joel:
Updated by Myhrginoc
Note: stat is using the ID from itemstatscost.txt (ie strength has ID 0)

Op: Param: Value: Effect:
1 x day # Valid recipe if (current day >= value)
2 x d. code Valid recipe if (current day == day code) [0=sunday,etc ...]
3 stat value Valid recipe if (stat.accr >= value)
4 stat value Valid recipe if (stat.accr <= value)
5 stat value Valid recipe if (stat.accr != value)
6 stat value Valid recipe if (stat.accr == value)
7 stat value Valid recipe if (stat.base >= value)
8 stat value Valid recipe if (stat.base <= value)
9 stat value Valid recipe if (stat.base != value)
10 stat value Valid recipe if (stat.base == value)
11 stat value Valid recipe if (stat.accr - stat.base >= value)
12 stat value Valid recipe if (stat.accr - stat.base <= value)
13 stat value Valid recipe if (stat.accr - stat.base != value)
14 stat value Valid recipe if (stat.accr - stat.base == value)
15 stat value Valid recipe if (input1.stat.accr >= value)
16 stat value Valid recipe if (input1.stat.accr <= value)
17 stat value Valid recipe if (input1.stat.accr != value)
18 stat value Valid recipe if (input1.stat.accr == value)
19 stat value Valid recipe if (input1.stat.base >= value)
20 stat value Valid recipe if (input1.stat.base <= value)
21 stat value Valid recipe if (input1.stat.base != value)
22 stat value Valid recipe if (input1.stat.base == value)
23 stat value Valid recipe if (input1.stat.accr - input1.stat.base >= value)
24 stat value Valid recipe if (input1.stat.accr - input1.stat.base <= value)
25 stat value Valid recipe if (input1.stat.accr - input1.stat.base != value)
26 stat value Valid recipe if (input1.stat.accr - input1.stat.base == value)
27 x x pItem->OtherID != value
28 x x pItem->QuestDiff < ptGame->Diff (only checked if Quest and QuestDiffCheck are 1)
29->255 Free op code. 

*/

/*
所以此文件是描述方块的主要文件，也就是描述合成公式的文件。
此文件中的每一行表示一个合成公式。

description：注释，用来描述解释此公式的，可随便写。

Enabled：此公式是否可在游戏中使用。0代表不可使用，1代表可以使用。

Ladder：是否只能在天梯模式中使用。0代表不是，1代表是。单机版不受此列影响，所以可不填。

min diff：使用此公式所需要的最低游戏难度。0代表普通，1代表恶梦，2代表地狱。

version：使用此公式所需要的最低游戏版本。0 代表原版本， 1 代表新版本，100 代表扩展任务（即“毁灭之王”）。

op：使用此公式的特殊效果或特殊条件。如28表示使用此公式时显示合成光芒。

param：op列的参数。

value：op列的参数。

class：使用此公式的角色职业限制。

numinputs：参与此公式合成的所有物品总数。

input1：此公式的主材料。如物品升级时一定要将待升级物品作为主要材料，即input1才行。后面会解释原因。

input2-7：此公式的附属材料。

output：此合成公式的第一个合成结果。

lvl：第一个合成结果的物品等级。若不填则使用紧跟的qlvl和ilvl决定合成结果的物品等级。若此列有值则qlvl和ilvl列无效。

qlvl：角色等级对合成结果物品等级的影响因子。

ilvl：此公式的主材料的物品等级对合成结果物品等级的影响因子。
若lvl列为空，则合成结果的物品等级为 [ [角色等级 * qlvl / 100] + [主材料物品等级 * ilvl / 100] ]。此式子中的方括号表示向下取整。
所以对于橙色物品的合成来说，qlvl=ilvl=50。所以一个99级的角色使用99级的装备作为主材料，合成出的橙色物品的等级为 2 * [99 * 50 / 100] = 2 * [49.5] = 2 * 49 = 98。

mod 1-5：第一个结果的第1-5个属性。与Properties.txt关联。

mod 1-5 chance：出现第1-5个属性的概率。

mod 1-5 param：第1-5个属性的参数。

mod 1-5 min：第1-5个属性的最小值参数。

mod 1-5 max：第1-5个属性的最大值参数。

output b：此合成公式的第二个合成结果。

以后28列的含义都是对合成公式的第二个合成结果的描述，请参考第一个合成结果的解释。

output c：此合成公式的第三个合成结果。

以后28列的含义都是对合成公式的第三个合成结果的描述，请参考第一个合成结果的解释。

*eol：行尾标志，必须填0。

特殊说明1：合成时游戏只会记录参与合成的主材料的信息，如装备类型、品质、物品等级之类的，自己编写新的公式时一定要注意这点。

特殊说明2：当合成结果所占的空间超过方块本身的大小时，则造成空间超出的合成结果将消失。

特殊说明3：
op列的值及其后param和Value的使用说明。
op Param Value 实际效果
1 x day 当前日期(时间？)大于给定参数时Cube配方有效
2 x 日期 当前日期等于给定参数时配方有效(0=星期天 等等 ...)
3 stat value 当前状态大于等于给定参数时配方有效
4 stat value 当前状态小于等于给定参数时配方有效
5 stat value 当前状态不等于给定参数时配方有效
6 stat value 当前状态等于给定参数时配方有效
7 stat value 基础状态小于等于给定参数时配方有效
8 stat value 基础状态大于等于给定参数时配方有效
9 stat value 基础状态不等于给定参数时配方有效
10 stat value 基础状态等于给定参数时配方有效
11 ? ? ?
12 ? ? ?
13 ? ? ?
14 ? ? ?
15 stat value input1当前状态小于等于给定参数时配方有效
16 stat value input1当前状态大于等于给定参数时配方有效
17 stat value input1当前状态不等于给定参数时配方有效
18 stat value input1当前状态等于给定参数时配方有效
19->27 闲置Op.
28 x x 显示合成时候的光芒.
29->255 闲置Op.

此部分摘录自Sloovy的发言，本人没有进行验证。

最后我再说明一下，如果大家想不失去最初合成用的原始物品；可以将 output b换成无变更的原始物品。
比如说：1怀特之腿+1回城魔法书=隐藏奶牛关；如果我想在生成牛关后继续拥有回城魔法书，可以在output b中输入tbk，并且不做任何的属性及参数调整，即可。


击中敌人时 5%机会 施展 等级5 伤害加深
这代码怎么填？
gethit-skill是这技能的代码！Amplefy Damage是伤害加深！
5个格子！该如何填？

gethit是被击中时，hit-skill是击中敌人时。
code（prop) = hit-skill
param = Amplify Damage 或 66
min = 5
max = 5
我应该在Properties.txt文件解析中提到过

struct D2CubeInputItem
{
   BYTE nInputFlags;               //0x00
   BYTE nItemType;                  //0x01
   WORD wItem;                     //0x02
   WORD wItemID;                  //0x04
   BYTE nQuality;                  //0x06
   BYTE nQuantity;                  //0x07
};


struct D2CubeOutputItem
{
   BYTE nItemFlags;               //0x00
   BYTE nItemType;                  //0x01
   WORD wItem;                     //0x02
   WORD wItemID;                  //0x04
   BYTE nQuality;                  //0x06
   BYTE nQuantity;                  //0x07
   BYTE nType;                     //0x08
   BYTE nLvl;                     //0x09
   BYTE nPLvl;                     //0x0A
   BYTE nILvl;                     //0x0B
   WORD wPrefixId;                  //0x0C
   WORD unk0x0E;                  //0x0E
   WORD unk0x10;                  //0x10
   WORD wSuffixId;                  //0x12
   DWORD unk0x14;                  //0x14
   struct
   {
      DWORD   dwMod;         //0x00
      WORD   wModParam;      //0x04
      WORD   wModMin;      //0x06
      WORD   wModMax;      //0x08
      WORD   wModChance;      //0x0A
   } sMods[5];                   //0x18
};
*/

typedef struct
{//total 328 bytes
    unsigned char venabled;
    unsigned char vladder;
    unsigned char vminmyspdiff;
    unsigned char vclass;   //playerclass

    unsigned int vop;
    unsigned int vparam;
    unsigned int vvalue;

    unsigned short vnuminputs;
    unsigned short vversion;

    unsigned char vinputmysp1[8];

    unsigned char vinputmysp2[8];

    unsigned char vinputmysp3[8];

    unsigned char vinputmysp4[8];

    unsigned char vinputmysp5[8];

    unsigned char vinputmysp6[8];

    unsigned char vinputmysp7[8];

    unsigned char voutput[20];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int iPadding24;

    unsigned int vmodmysp1;   //properties

    unsigned short vmodmysp1myspparam;
    short vmodmysp1myspmin;

    short vmodmysp1myspmax;
    unsigned short vmodmysp1myspchance;

    unsigned int vmodmysp2;   //properties

    unsigned short vmodmysp2myspparam;
    short vmodmysp2myspmin;

    short vmodmysp2myspmax;
    unsigned short vmodmysp2myspchance;

    unsigned int vmodmysp3;   //properties

    unsigned short vmodmysp3myspparam;
    short vmodmysp3myspmin;

    short vmodmysp3myspmax;
    unsigned short vmodmysp3myspchance;

    unsigned int vmodmysp4;   //properties

    unsigned short vmodmysp4myspparam;
    short vmodmysp4myspmin;

    short vmodmysp4myspmax;
    unsigned short vmodmysp4myspchance;

    unsigned int vmodmysp5;   //properties

    unsigned short vmodmysp5myspparam;
    short vmodmysp5myspmin;

    short vmodmysp5myspmax;
    unsigned short vmodmysp5myspchance;

    unsigned char voutputmyspb[20];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int iPadding45;

    unsigned int vbmyspmodmysp1;   //properties

    unsigned short vbmyspmodmysp1myspparam;
    short vbmyspmodmysp1myspmin;

    short vbmyspmodmysp1myspmax;
    unsigned short vbmyspmodmysp1myspchance;

    unsigned int vbmyspmodmysp2;   //properties

    unsigned short vbmyspmodmysp2myspparam;
    short vbmyspmodmysp2myspmin;

    short vbmyspmodmysp2myspmax;
    unsigned short vbmyspmodmysp2myspchance;

    unsigned int vbmyspmodmysp3;   //properties

    unsigned short vbmyspmodmysp3myspparam;
    short vbmyspmodmysp3myspmin;

    short vbmyspmodmysp3myspmax;
    unsigned short vbmyspmodmysp3myspchance;

    unsigned int vbmyspmodmysp4;   //properties

    unsigned short vbmyspmodmysp4myspparam;
    short vbmyspmodmysp4myspmin;

    short vbmyspmodmysp4myspmax;
    unsigned short vbmyspmodmysp4myspchance;

    unsigned int vbmyspmodmysp5;   //properties

    unsigned short vbmyspmodmysp5myspparam;
    short vbmyspmodmysp5myspmin;

    short vbmyspmodmysp5myspmax;
    unsigned short vbmyspmodmysp5myspchance;

    unsigned char voutputmyspc[20];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int iPadding66;

    unsigned int vcmyspmodmysp1;   //properties

    unsigned short vcmyspmodmysp1myspparam;
    short vcmyspmodmysp1myspmin;

    short vcmyspmodmysp1myspmax;
    unsigned short vcmyspmodmysp1myspchance;

    unsigned int vcmyspmodmysp2;   //properties

    unsigned short vcmyspmodmysp2myspparam;
    short vcmyspmodmysp2myspmin;

    short vcmyspmodmysp2myspmax;
    unsigned short vcmyspmodmysp2myspchance;

    unsigned int vcmyspmodmysp3;   //properties

    unsigned short vcmyspmodmysp3myspparam;
    short vcmyspmodmysp3myspmin;

    short vcmyspmodmysp3myspmax;
    unsigned short vcmyspmodmysp3myspchance;

    unsigned int vcmyspmodmysp4;   //properties

    unsigned short vcmyspmodmysp4myspparam;
    short vcmyspmodmysp4myspmin;

    short vcmyspmodmysp4myspmax;
    unsigned short vcmyspmodmysp4myspchance;

    unsigned int vcmyspmodmysp5;   //properties

    unsigned short vcmyspmodmysp5myspparam;
    short vcmyspmodmysp5myspmin;

    short vcmyspmodmysp5myspmax;
    unsigned short vcmyspmodmysp5myspchance;
} ST_LINE_INFO;

typedef enum
{
    GRADE_LOW = 1,
    GRADE_NORMAL,
    GRADE_SUPERIOR,
    GRADE_MAGIC,
    GRADE_SET,
    GRADE_RARE,
    GRADE_UNIQ,
    GRADE_CRAFT,
    GRADE_TAMPERED,
} EN_CUBE_GRADE;

typedef struct
{
    union {
        unsigned short sFlags;
        struct {
            unsigned short bItemCode: 1;
            unsigned short bTypeCode: 1;
            unsigned short bNoSock: 1;
            unsigned short bSock: 1;
            unsigned short bEthereal: 1;
            unsigned short bNotEthereal: 1;
            unsigned short bSpecific: 1;
            unsigned short bUpgrade: 1;
            unsigned short bBase: 1;
            unsigned short bExceptional: 1;
            unsigned short bElite: 1;
            unsigned short bNotRuneword: 1;
        };
    };
    unsigned short sGenericID;
    unsigned short sSpecificID;
    unsigned char cGrade;
    unsigned char cQuantity;
} ST_CUBE_INPUT;

typedef struct
{
    union {
        unsigned short sFlags;
        struct {
            unsigned short bKeepModifiers: 1;
            unsigned short bSockets: 1;
            unsigned short bEthereal: 1;
            unsigned short bSpecific: 1;
            unsigned short bDestroyFillers: 1;
            unsigned short bRemoveFillers: 1;
            unsigned short bRegenerate: 1;
            unsigned short bExceptional: 1;
            unsigned short bElite: 1;
            unsigned short bRepair: 1;
            unsigned short bRecharge: 1;
        };
    };
    unsigned short sGenericID;
    unsigned short sSpecificID;
    unsigned char cGrade;
    unsigned char cQuantity;
    unsigned char cType;
    unsigned char clvl;
    unsigned char cplvl;
    unsigned char cilvl;
    unsigned short sPrefix;
    unsigned short sPrefixMin;
    unsigned short sPrefixMax;
    unsigned short sSuffix;
    unsigned short sSuffixMin;
    unsigned short sSuffixMax;
    struct
    {
      unsigned int iMod;
      unsigned short sModParam;
      unsigned short sModMin;
      unsigned short sModMax;
      unsigned short sModChance;
    } sMods[5];
} ST_CUBE_OUTPUT;

static char *m_apcInternalProcess[] =
{
    "description",
    "lvl",
    "b lvl",
    "c lvl",
    "plvl",
    "b plvl",
    "c plvl",
    "ilvl",
    "b ilvl",
    "c ilvl",
    "*eol",
    NULL,
};

static char *Cubemain_GenerateInputProp(char *acOutput, ST_CUBE_INPUT *sInput, EN_CUBE_GRADE cOutGrade)
{
    if ( sInput->bNoSock )
    {
        strcpy(acOutput, ",nos");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bSock )
    {
        strcpy(acOutput, ",sock");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bEthereal )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bNotEthereal )
    {
        strcpy(acOutput, ",noe");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bUpgrade )
    {
        strcpy(acOutput, ",upg");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bBase )
    {
        strcpy(acOutput, ",bas");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bExceptional )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bElite )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bNotRuneword )
    {
        strcpy(acOutput, ",nru");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_LOW )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_NORMAL )
    {
        strcpy(acOutput, ",nor");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SUPERIOR )
    {
        strcpy(acOutput, ",hiq");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_MAGIC )
    {
        strcpy(acOutput, ",mag");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SET )
    {
        strcpy(acOutput, ",set");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_RARE )
    {
        strcpy(acOutput, ",rar");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_UNIQ )
    {
        strcpy(acOutput, ",uni");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_CRAFT )
    {
        strcpy(acOutput, ",crf");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_TAMPERED )
    {
        strcpy(acOutput, ",tmp");
        acOutput += strlen(acOutput);
    }

    if ( sInput->cQuantity > 0 )
    {
        sprintf(acOutput, ",qty=%d", sInput->cQuantity);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}

static char *Cubemain_GenerateOutputProp(char *acOutput, ST_CUBE_OUTPUT *sOutput, EN_CUBE_GRADE cOutGrade)
{
    if ( sOutput->bKeepModifiers )
    {
        strcpy(acOutput, ",mod");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bSockets )
    {
        sprintf(acOutput, ",sock=%d", sOutput->cQuantity);
        acOutput += strlen(acOutput);
    }
    else if ( sOutput->cQuantity > 0 )
    {
        sprintf(acOutput, ",qty=%d", sOutput->cQuantity);
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bEthereal )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bDestroyFillers )
    {
        strcpy(acOutput, ",uns");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRemoveFillers )
    {
        strcpy(acOutput, ",rem");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRegenerate )
    {
        strcpy(acOutput, ",reg");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bExceptional )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bElite )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRepair )
    {
        strcpy(acOutput, ",rep");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRecharge )
    {
        strcpy(acOutput, ",rch");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_LOW )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_NORMAL )
    {
        strcpy(acOutput, ",nor");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SUPERIOR )
    {
        strcpy(acOutput, ",hiq");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_MAGIC )
    {
        strcpy(acOutput, ",mag");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SET )
    {
        strcpy(acOutput, ",set");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_RARE )
    {
        strcpy(acOutput, ",rar");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_UNIQ )
    {
        strcpy(acOutput, ",uni");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_CRAFT )
    {
        strcpy(acOutput, ",crf");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_TAMPERED )
    {
        strcpy(acOutput, ",tmp");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->sPrefix > 0 )
    {
        sprintf(acOutput, ",pre=%d", sOutput->sPrefix);
        acOutput += strlen(acOutput);
    }

    if ( sOutput->sSuffix > 0 )
    {
        sprintf(acOutput, ",suf=%d", sOutput->sSuffix);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}

static int Cubemain_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    char *pcOutput = acOutput;
    int id;

    if ( 1 == sscanf(acKey, "input %d", &id) )
    {
        ST_CUBE_INPUT *sInput = (ST_CUBE_INPUT *)&pstLineInfo->vinputmysp1 + (id - 1);

        unsigned char cOutGrade = sInput->cGrade;
        if ( sInput->bSpecific && ( sInput->cGrade == GRADE_SET || sInput->cGrade == GRADE_UNIQ ) )
        {
            // No need to write ",uni" and ",set" after explicitly defined sets and uniques, it's just a clutter
            cOutGrade = 0;
        }

        if ( sInput->bItemCode || sInput->bTypeCode )
        { 
            if ( (sInput->sFlags & 0xFFBC) || cOutGrade || sInput->cQuantity )
            {
                // Add quotes if there's any qualifiers after ID
                pcOutput[0] = '"';
                pcOutput++;
            }

            if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_UNIQ && (pcResult = UniqueItems_GetItemUniqueCode(sInput->sSpecificID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_SET && (pcResult = SetItems_GetItemUniqueCode(sInput->sSpecificID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sInput->bItemCode && (pcResult = Misc_GetItemUniqueCode(sInput->sGenericID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sInput->bTypeCode && (pcResult = ItemTypes_GetItemCode(sInput->sGenericID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sInput->sGenericID == 0xFFFF )
            {
                strcpy(pcOutput, "any");
            }

            if ( (sInput->sFlags & 0xFFBC) || cOutGrade || sInput->cQuantity )
            {
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateInputProp(pcOutput, sInput, cOutGrade);
                pcOutput[0] = '"';
                pcOutput++;
            }
       }

       return 1;
    }
    else if ( !strnicmp(acKey, "output", strlen("output")) )
    {
        ST_CUBE_OUTPUT *sOutput = !stricmp("output b", acKey) ? (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb :
                                  !stricmp("output c", acKey) ? (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc :
                                                                (ST_CUBE_OUTPUT *)pstLineInfo->voutput;

        unsigned char cOutGrade = sOutput->cGrade;
        if ( sOutput->bSpecific && ( sOutput->cGrade == GRADE_SET || sOutput->cGrade == GRADE_UNIQ ) )
        {
            // No need to write ",uni" and ",set" after explicitly defined sets and uniques, it's just a clutter
            cOutGrade = 0;
        }

        if ( sOutput->bSpecific || sOutput->cType )
        {
            if ( (sOutput->sFlags & 0xFFF7) || cOutGrade || sOutput->cQuantity || sOutput->sPrefix || sOutput->sSuffix )
            {
                // Add quotes if there's any qualifiers after ID
                pcOutput[0] = '"';
                pcOutput++;
            }

            if ( sOutput->bSpecific && sOutput->cGrade == GRADE_UNIQ && (pcResult = UniqueItems_GetItemUniqueCode(sOutput->sSpecificID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sOutput->bSpecific && sOutput->cGrade == GRADE_SET && (pcResult = SetItems_GetItemUniqueCode(sOutput->sSpecificID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sOutput->cType == 0xFC && (pcResult = Misc_GetItemUniqueCode(sOutput->sGenericID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sOutput->cType == 0xFD && (pcResult = ItemTypes_GetItemCode(sOutput->sGenericID)) )
            {
                strcpy(pcOutput, pcResult);
            }
            else if ( sOutput->cType == 0xFE)
            {
                strcpy(pcOutput, "useitem");
            }
            else if ( sOutput->cType == 0xFF )
            {
                strcpy(pcOutput, "usetype");
            }
            else if ( sOutput->cType == 0x01 )
            {
                strcpy(pcOutput, "Cow Portal");
            }
            else if ( sOutput->cType == 0x02 )
            {
                strcpy(pcOutput, "Pandemonium Portal");
            }
            else if ( sOutput->cType == 0x03 )
            {
                strcpy(pcOutput, "Pandemonium Finale Portal");
            }

            if ( (sOutput->sFlags & 0xFFF7) || cOutGrade || sOutput->cQuantity || sOutput->sPrefix || sOutput->sSuffix )
            {
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateOutputProp(pcOutput, sOutput, cOutGrade);
                pcOutput[0] = '"';
                pcOutput++;
            }
        }

        return 1;
    }

    return 0;
}

static int Cubemain_BuildDescription(void *pvLineInfo, char *acOutput, unsigned int iOutputSize)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int i, j, iUse;
    char *pcResult;

    ST_CUBE_INPUT *sInput = (ST_CUBE_INPUT *)pstLineInfo->vinputmysp1;

    ST_CUBE_OUTPUT *sOutputs[] =
    {
        (ST_CUBE_OUTPUT *)pstLineInfo->voutput,
        (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb,
        (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc
    };

    for ( i = 0; i < 3; i++ )
    {
        iUse = 0;
        if ( sOutputs[i]->bSpecific && sOutputs[i]->cGrade == GRADE_UNIQ && (pcResult = UniqueItems_GetItemUniqueCode(sOutputs[i]->sSpecificID)) )
        {
            strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->bSpecific && sOutputs[i]->cGrade == GRADE_SET && (pcResult = SetItems_GetItemUniqueCode(sOutputs[i]->sSpecificID)) )
        {
            strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->cType == 0xFC && (pcResult = String_GetString(Misc_GetItemString(sOutputs[i]->sGenericID), NULL, NULL)) )
        {
            strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->cType == 0xFD && (pcResult = ItemTypes_GetItemCode(sOutputs[i]->sGenericID)) )
        {
            strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->cType == 0xFE)
        {
            iUse = 1; // useitem
        }
        else if ( sOutputs[i]->cType == 0xFF )
        {
            iUse = 2; // usetype
        }
        else if ( sOutputs[i]->cType == 0x01 )
        {
            strncpy(&acOutput[strlen(acOutput)], "Cow Portal", iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->cType == 0x02 )
        {
            strncpy(&acOutput[strlen(acOutput)], "Pandemonium Portal", iOutputSize-strlen(acOutput));
        }
        else if ( sOutputs[i]->cType == 0x03 )
        {
            strncpy(&acOutput[strlen(acOutput)], "Pandemonium Finale Portal", iOutputSize-strlen(acOutput));
        }

        if ( iUse )
        {
            if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_UNIQ && (pcResult = UniqueItems_GetItemUniqueCode(sInput->sSpecificID)) )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            }
            else if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_SET && (pcResult = SetItems_GetItemUniqueCode(sInput->sSpecificID)) )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            }
            else if ( sInput->bItemCode && (pcResult = String_GetString(Misc_GetItemString(sInput->sGenericID), NULL, NULL)) )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            }
            else if ( sInput->bTypeCode && (pcResult = ItemTypes_GetItemCode(sInput->sGenericID)) )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            }
            else if ( sInput->sGenericID == 0xFFFF )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            }

            for ( j = 0; j < 5; j++ )
            {
                if ( pcResult = Properties_GetProperty(sOutputs[i]->sMods[j].iMod) )
                {
                    strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
                }
            }
        }
    }

    return 1;
}

static int Cubemain_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp("description", acKey) )
    {
        char acName[64] = {0};
        Cubemain_BuildDescription(pvLineInfo, acName, 63);
        if ( !String_BuildName(FORMAT(cubemain), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp("lvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutput;
        sprintf(acOutput, "%d", sOutput->clvl);

        return 1;
    }
    else if ( !stricmp("b lvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb;
        sprintf(acOutput, "%d", sOutput->clvl);

        return 1;
    }
    else if ( !stricmp("c lvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc;
        sprintf(acOutput, "%d", sOutput->clvl);

        return 1;
    }
    else if ( !stricmp("plvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutput;
        sprintf(acOutput, "%d", sOutput->cplvl);

        return 1;
    }
    else if ( !stricmp("b plvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb;
        sprintf(acOutput, "%d", sOutput->cplvl);

        return 1;
    }
    else if ( !stricmp("c plvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc;
        sprintf(acOutput, "%d", sOutput->cplvl);

        return 1;
    }

    else if ( !stricmp("ilvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutput;
        sprintf(acOutput, "%d", sOutput->cilvl);

        return 1;
    }
    else if ( !stricmp("b ilvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb;
        sprintf(acOutput, "%d", sOutput->cilvl);

        return 1;
    }
    else if ( !stricmp("c ilvl", acKey) )
    {
        ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc;
        sprintf(acOutput, "%d", sOutput->cilvl);

        return 1;
    }
    else if ( !stricmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_cubemain(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ladder, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmyspdiff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, UCHAR_PLRCLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, numinputs, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp1, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp2, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp5, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp6, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp7, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, output, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspb, STRING);  //lvl、plvl、ilvl复用在这20个byte里

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspc, STRING);  //lvl、plvl、ilvl复用在这20个byte里

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5, UINT_PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspchance, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(uniqueitems, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(setitems, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Cubemain_ConvertValue;
            m_stCallback.pfnFieldProc = Cubemain_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

/*
Title Cubemain.txt Code Reference (v1.09x) 
Description by Nefarius 
Sent by  

--------------------------------------------------------------------------------
 
This resource originally appeared as a thread in the Phrozen Forums and we would also like to thank Sir_General, Myhrginoc and Ruvanal for their contributions to the list. 
item quality params
nor=normal
hiq=superior
eth=ethereal
rar=rare
mag=magic
uni=unique
set=set
crf=crafted
low=low quality
any=any item


others
noe=not ethereal
nos=no socket (for input)
sock=#sockets (eg: sock=4)
pre=prefix (row # -2 from magicprefix)
suf=suffix (row # -2 from magicsuffix)
usetype=uses base type of input1 for output
useitem=uses item from input 1
qty=amount of same item (eg: hpot,qty=3 means 3 hp potions)
upg=upgrades item normal>exceptional>elite 

For additional information, an abbreviated replica of the aforementioned thread has been provided below: 





--------------------------------------------------------------------------------

NefariusDX:
item quality params:
nor=normal
hiq=superior
eth=ethereal
rar=rare
mag=magic
uni=unique
set=set
crf=crafted
low=low quality
any=any item
others
noe=not ethereal
nos=no socket (for input)
sock=#sockets (eg: sock=4)
pre=prefix (row # -2 from magicprefix)
suf=suffix (row # -2 from magicsuffix)
usetype=uses base type of input1 for output
useitem=uses item from input 1
qty=amount of same item (eg: hpot,qty=3 means 3 hp potions)
upg=upgrades item normal>exceptional>elite 

Defeater:
dont forget to add "'s when you use params 

NefariusDX:
params are used like this no ' its ,
eg. uar,set,eth,sock=1 would create a set sacred armor which is ethereal and had one socket 

dectgap:
Would you really be able to create a ethereal set item, or was it just an example? I have never got the ethereal part working anyway...


NefariusDX:
the order is important (how ever sets can never spawn as ethereal) blizzard did this since if u would have 1 ethereal set item u would need to have all the other parts of that set as ethereal to in order to complete it how ever try it this way xh9,uni,
eth,sock=1 will create a ethereal socket vamp gaze (make the level for the stuff match!) now xh9,sock=1,eth,uni would not work to my knowledge the code must be ORDERED 

ShadowTalon:
what i would like to know is all the output formulas for cubemain such as the formulas that Sir_General uses on his rune mod i know you can add prefixes to items ,but i want to know if you can add the properties of the rune or gem in my case without 
typing up a **** load of new prefixes and suffixes so they would work the way i wanted them to 

NefariusDX:
i didnt understand ur q, if u mean having them "built in" to a item u just make a crafted item 

Sir_General:
If you type "useitem" in the output column and then put some stuff 
in the mod1, mod2, etc. columns you'll get the same item you put in, 
only with the added attributes in the mod1, mod2, etc. columns. 

ShadowTalon:
thx Sir_General, thats exactly what i wanted to hear 

Myhrginoc:
One more output code for your list, "hiq" to make an item superior. And it gets the random affixes that go with superior grade. If "hiq" doesn't work by itself, use "nor,hiq". 

NefariusDX:
thx Myhrginoc, if there is a hiq code then maybe there is a nor,low or loq 

Ruvanal:
Yes, there is 'low' quality mod. edit: Do not use with the 'nor' mod because you would be trying to apply 2 different quality levels to an item. I can't rember for sure but I think there is a 'noe' mod for 'not ethereal'. I need to try checking a lot of 
scattered notes to see if there are any other odd ones out there. 

NefariusDX:
tell me when your sure these are correct ill add em for now 

Ruvanal:
Double-checked the lists that I have. The 'noe' is for 'not ethereal' and is normally used on the input tests. I only see 2 other that you did not have in your list 'any' and 'upg'. From the various reports that I have heard from other I cannot 
recommend using the 'any' modifier as it usually causes more problems than it will help with. The 'upg' is for 'upgrade' and is used on the inputs to allow the upgrade forms of a specific item to be used also (e.g. an input of mbt,mag,upg would allow 
the mag Chain boots, mag Mesh boots or mag Boneweave boots to be used as valid inputs). Also a note on the outputs. If you don't specify a quality type (low, nor, hiq, mag, rar, crf, set, uni) then the game will spawn the item similar to an item drop 
and you can get an unplanned magical quality level. I do not know if the magic find you are equipped with will effect this type of drop or not. I ran into this when I was trying to test something and neglected to put a 'nor' quality in the output line 
and ended up with an ethereal magical version of what I was trying to test (I did not want either attribute and had to start the test run over again). Also a note on the 'sock=#' output code for those that are not aware of it. When this is used in the 
output column, you will be limited in the number of sockets as specified by the item, the ilvl (using the MaxSockX columns from itemtypes.txt) and the max sockets based on the magical quality of the item (magic MaxSock=3; set, rare, crafted and unique 
will get a MaxSock=1). If you need to exceed this amount you will need to put the socket value in one of the sets on mod columns instead (you still will not be able to exceed the values for the item and the itemtype limits). If your output code 
specifies a condition that is not possible for then the formula will not work in that case. Example: input code weap with an out put code of usetype,nor,sock=6, using a sword would work, but if you used a javelin then the formula would be non-functional 
(assuming you have not enabled sockets on this type of item). This type of problem is probably what has caused a lot of difficulties when modders are trying to use 'any' code. 

NefariusDX:
i didnt add any due to that reason
i didnt know about the other 1 though for upgrade

nor 普通物品(白色)
hiq 超强物品
low 劣质物品
mag 蓝色物品
rar 黄色物品
uni 暗金物品
set 绿色物品
tmp 暗绿物品
crf 橙色物品
bas 基础物品
exc 扩展物品
eli 精华物品
pre 物品前缀（一般对应afj sheet打开得前面那个数减2）
suf 物品后缀（一般对应afj sheet打开得前面那个数减2）
sock 孔
qty 物品数量
nos 无孔
uns 消除镶嵌物
rem 镶嵌物
usetype 同类型物品
useitem 原物品

输入（Input）：
any item any
magic mag (rin,mag)
rare rar
unique unq
crafted crf 
normal nor
no socket nos
item nums qty=? (r01,qty=3)
baseitem bas 
exceptionalitem exc 
socket sock=?
另外还有upg,low,hiq,tmp等，upg只在手工艺品公式中出现。tmp是1.10中新出现的物品类型，未开放，这是一种暗绿色的带rar物品前后缀的类型，但目前合出来不带任何属性。

3、合出（Output）：
usetype 物品类别rar/mag/uni/crf/set/tmp/nor等；
useitem 保持物品本来类型并添加新属性sock=?/uns/mod/exc/eli/bas等。这应当是最有用的了，可以在不改变物品本身属性的情况下添加新属性，例如打孔：（useitem,sock=6）
另外有些物品有特定的值限定，如suf=162这些，使用的机会较小，可不用考虑。
需要注意的是，输入物品的范围设定越大，公式出错机会越大。如武器，出错后有可能就是一把小斧。因此一定要多试验。尽量少用如 (any,mag)之类的写法，


*/


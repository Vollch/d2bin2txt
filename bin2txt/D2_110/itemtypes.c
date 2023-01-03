#include "../global.h"

#define FILE_PREFIX "ItemTypes"

typedef struct
{
    //ItemType在bin文件中没有体现
    unsigned char vCode[4]; //类型代码，或称索引。在各txt文件中对物品类型进行描述都应该使用此列的值。

    //Equiv1、2，需要到第二轮处理，因为引用了自身的其他字段
    unsigned short vEquiv1;
    unsigned short vEquiv2;

    unsigned char vRepair;  //是否可被修理。0代表不可以，1代表可以。只有此类别中的所有物品都可修理时此类别才算作可修理。
    unsigned char vBody;    //是否是穿在身上的装备。0代表不是，1代表是。
    unsigned char vBodyLoc1;    //装备的位置1。有如下几种位置：rarm右手、larm左手、tors躯干、rrin右戒指、lrin左戒指、neck脖子、feet脚、belt腰带、head头部、glov手套。
    unsigned char vBodyLoc2;    //装备的位置2。有如下几种位置：rarm右手、larm左手、tors躯干、rrin右戒指、lrin左戒指、neck脖子、feet脚、belt腰带、head头部、glov手套。

    //Shoots、Quiver，需要到第二轮处理，因为引用了自身的其他字段
    unsigned short vShoots;
    unsigned short vQuiver;

    unsigned char vThrowable;   //是否为投掷型物品。0表示不是，1表示是。如剑此列为0，标枪此列为1。
    unsigned char vReload;  //是否可以自动补充。0表示不可以，1表示可以。如箭矢射完一筒后会自动换新的一筒（如果你包里有），就是因为此列为1。
    unsigned char vReEquip; //数量使用完后物品是否消失。0表示是，1表示不是。如标枪此列为1，那么即使数量用光了标枪也还在。但箭矢此列为0，所以一个箭袋用完了此箭袋就消失了。
    unsigned char vAutoStack;   //是否自动叠加。0代表不是，1代表是。比如你原来背包里有一个箭袋，捡了一个新的箭袋之后由此列决定是否自动与原有的箭袋合并。

    unsigned char vMagic;   //是否一定是魔法物品（或以上级别）。0代表不是，1代表是。如戒指类此列就为1，表示不会有白色的戒指。
    unsigned char vRare;    //是否能有稀有级别的物品。0代表不能，1代表能。如护身符此列为0，表示不可能出现稀有（亮金）的护身符。
    unsigned char vNormal;  //是否只能是普通（白色）物品。0代表不是，1代表是。如回城卷轴此列为1，武器此列为0。
    unsigned char vCharm;   //是否是护身符。0代表不是，1代表是。

    unsigned char vGem; //是否是宝石。0代表不是，1代表是。
    unsigned char vBeltable;    //是否能放入腰带空间中。0代表不是，1代表是。
    unsigned char vMaxSock1;    //物品等级在1-23之间时的最大孔数。
    unsigned char vMaxSock25;   //物品等级在25-39之间时的最大孔数。

    unsigned char vMaxSock40;   //物品等级大于40级时的最大孔数。
    unsigned char vTreasureClass;   //财宝类型（TC）。是否能单独作为一个财宝类型（TC），实际上只有5种可以。武器、近战武器、装甲、弓、亚马逊弓。
    unsigned char vRarity;  //稀有度。在同一TC中出现的概率，值越大掉落的概率越大。请参考物品掉落原理。
    unsigned char vStaffMods;   //杖上面自带的加单一技能属性。比如法师的杖会加法师的技能，就是因为这列有sor这个值。关联playerclass.txt

    unsigned char vCostFormula; //物品价格计算方法（其实我不太明白这列的含义）。
    unsigned char vClass;   //职业限制。如法球类此列的值为sor，表示只有法师能用法球。关联playerclass.txt
    unsigned char vStorePage;   //此类别下具体物品的信息存储在哪个文件里，或者说此类别属于哪个大类。只有3个大类，防具armo，武器weap，杂物misc。
    unsigned char vVarInvGfx;   //在物品栏中可能出现的外观种类。如戒指类此列值为5，即戒指共有5种外观。

    unsigned char vInvGfx1[32];   //外观图片指针。
    unsigned char vInvGfx2[32];   //外观图片指针。
    unsigned char vInvGfx3[32];   //外观图片指针。
    unsigned char vInvGfx4[32];   //外观图片指针。
    unsigned char vInvGfx5[32];   //外观图片指针。
    unsigned char vInvGfx6[32];   //外观图片指针。
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_ITEM_TYPES;

static char *m_apcInternalProcess[] =
{
    "ItemType",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iItemTypesCount = 0;
static unsigned int m_iItemTypesHaveEmpty = 0;
static ST_ITEM_TYPES *m_astItemTypes = NULL;

MODULE_SETLINES_FUNC(m_astItemTypes, ST_ITEM_TYPES);

static char *ItemTypes_GetItemCode(unsigned int id)
{
    if ( id < m_iItemTypesCount )
    {
        return m_astItemTypes[id].vCode;
    }

    if ( id == -1 && m_iItemTypesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int ItemTypes_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        strncpy(m_astItemTypes[m_iItemTypesCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astItemTypes[m_iItemTypesCount].vCode);
        m_iItemTypesHaveEmpty |= !m_astItemTypes[m_iItemTypesCount].vCode[0];

        m_iItemTypesCount++;
        return 1;
    }
    else if ( !stricmp(acKey, "TreasureClass") )
    {
        if ( 0 != pstLineInfo->vTreasureClass )
        {
            g_iTreasureClassOffset += 32;
        }
    }

    return 0;
}

static int ItemTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "ItemType") )
    {
        char acName[5] = {0};
        strncpy(acName, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(itemtypes), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        return 1;
    }
    else if ( isD2SigmaActive() && ItemTypesExt_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static char *ItemTypes_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static void ItemTypes_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv2, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Repair, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Body, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc1, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc2, BODYLOC);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shoots, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quiver, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Throwable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Reload, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReEquip, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoStack, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Charm, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beltable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock25, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock40, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaffMods, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostFormula, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StorePage, STORE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VarInvGfx, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx6, STRING);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_itemtypes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_ITEMTYPES_109) )
    {
        return process_itemtypes109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(ItemTypesExt, acTemplatePath, acBinPath, acTxtPath);
            ItemTypes_InitValueMap(pstValueMap, pstLineInfo);

            m_iItemTypesCount = 0;
            Lookup_ItemType = ItemTypes_GetItemCode;

            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnConvertValue = ItemTypes_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? ItemTypesExt_ExternList : m_apcInternalProcess;

            g_iTreasureClassOffset = 1;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(storepage, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            ItemTypes_InitValueMap(pstValueMap, pstLineInfo);

            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnFieldProc = ItemTypes_FieldProc;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? ItemTypesExt_ExternList : m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


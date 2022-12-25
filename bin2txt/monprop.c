#include "global.h"

#define FILE_PREFIX "monprop"
#define NAME_PREFIX "mp"

/*
Monprop.txt Fileguide by cla$$ics

- This file is using: *Properties.txt *This file is used by: *Monstats.txt

ID - The name referenced by MonStats.txt, its case sensitive AFAIK
prop1 - The first property in Normal
chance1 - Prop1's chance to spawn on a monster, in %
par1 - Prop1's parameter
min1 - Prop1's minimum value
max1 - Prop1's maximum value

prop2 - The second property in Normal
chance2 - Prop2's chance to spawn on a monster, in %
par2 - Prop2's parameter
min2 - Prop2's minimum value
max2 - Prop2's maximum value

prop3 - The third property in Normal
chance3 - Prop3's chance to spawn on a monster, in %
par3 - Prop3's parameter
min3 - Prop3's minimum value
max3 - Prop3's maximum value

prop4 - The fourth property in Normal
chance4 - Prop4's chance to spawn on a monster, in %
par4 - Prop4's parameter
min4 - Prop4's minimum value
max4 - Prop4's maximum value

prop5 - The fifth property in Normal
chance5 - Prop5's chance to spawn on a monster, in %
par5 - Prop5's parameter
min5 - Prop5's minimum value
max5 - Prop5's maximum value

prop6 - The sixth property in Normal
chance6 - Prop6's chance to spawn on a monster, in %
par6 - Prop1's parameter
min6 - Prop6's minimum value
max6 - Prop6's maximum value

prop1 (N) - The first property in Nightmare
chance1 (N) - Prop1's (N) chance to spawn on a monster, in %
par1 (N) - Prop1's (N) parameter
min1 (N) - Prop1's (N) minimum value
max1 (N) - Prop1's (N) maximum value

prop2 (N) - The second property in Nightmare
chance2 (N) - Prop2's (N) chance to spawn on a monster, in %
par2 (N) - Prop2's (N) parameter
min2 (N) - Prop2's (N) minimum value
max2 (N) - Prop2's (N) maximum value

prop3 (N) - The third property in Nightmare
chance3 (N) - Prop3's (N) chance to spawn on a monster, in %
par3 (N) - Prop3's (N) parameter
min3 (N) - Prop3's (N) minimum value
max3 (N) - Prop3's (N) maximum value

prop4 (N) - The fourth property in Nightmare
chance4 (N) - Prop4's (N) chance to spawn on a monster, in %
par4 (N) - Prop4's (N) parameter
min4 (N) - Prop4's (N) minimum value
max4 (N) - Prop4's (N) maximum value

prop5 (N) - The fifth property in Nightmare
chance5 (N) - Prop5's (N) chance to spawn on a monster, in %
par5 (N) - Prop5's (N) parameter
min5 (N) - Prop5's (N) minimum value
max5 (N) - Prop5's (N) maximum value

prop6 (N) - The sixth property in Nightmare
chance6 (N) - Prop6's (N) chance to spawn on a monster, in %
par6 (N) - Prop6's (N) parameter
min6 (N) - Prop6's (N) minimum value
max6 (N) - Prop6's (N) maximum value

prop1 (H) - The first property in Hell
chance1 (H) - Prop1's (H) chance to spawn on a monster, in %
par1 (H) - Prop1's (H) parameter
min1 (H) - Prop1's (H) minimum value
max1 (H) - Prop1's (H) maximum value

prop2 (H) - The second property in Hell
chance2 (H) - Prop2's (H) chance to spawn on a monster, in %
par2 (H) - Prop2's (H) parameter
min2 (H) - Prop2's (H) minimum value
max2 (H) - Prop2's (H) maximum value

prop3 (H) - The third property in Hell
chance3 (H) - Prop3's (H) chance to spawn on a monster, in %
par3 (H) - Prop3's (H) parameter
min3 (H) - Prop3's (H) minimum value
max3 (H) - Prop3's (H) maximum value

prop4 (H) - The fourth property in Hell
chance4 (H) - Prop4's (H) chance to spawn on a monster, in %
par4 (H) - Prop4's (H) parameter
min4 (H) - Prop4's (H) minimum value
max4 (H) - Prop4's (H) maximum value

prop5 (H) - The fifth property in Hell
chance5 (H) - Prop5's (H) chance to spawn on a monster, in %
par5 (H) - Prop5's (H) parameter
min5 (H) - Prop5's (H) minimum value
max5 (H) - Prop5's (H) maximum value

prop6 (H) - The sixth property in Hell
chance6 (H) - Prop6's (H) chance to spawn on a monster, in %
par6 (H) - Prop6's (H) parameter
min6 (H) - Prop6's (H) minimum value
max6 (H) - Prop6's (H) maximum value


*eol (H) - Put a 0 here to avoid errors ingame then you using Microsoft's Excell then editing your Monprot.txt file. 
*/

/*
文件名解析：
Mon：Monster，即怪物。
Prop：Property，即属性。
所以本文件描述了某些怪物的特殊属性，如墨菲斯托有FCR属性。
此文件中的每一行表示一个具有特殊属性的怪物。


回复

    2楼
    2011-09-23 22:00

    举报 |

    zqtjingzi
    小吧主
    12

每列的含义如下：


回复

    3楼
    2011-09-23 22:00

    举报 |

    zqtjingzi
    小吧主
    12

Id：怪物的名字，与Monstats.txt关联。

prop1-6：在普通难度下此怪物可能拥有的第1-6个特殊属性。

chance1-6：在普通难度下此怪物可能拥有第1-6个特殊属性的概率，默认为100%。

par1-6：在普通难度下此怪物的第1-6个特殊属性的参数。

min1-6：在普通难度下此怪物的第1-6个特殊属性的最小值参数。

max1-6：在普通难度下此怪物的第1-6个特殊属性的最大值参数。

prop1-6(N)：在恶梦难度下此怪物可能拥有的第1-6个特殊属性。

chance1-6(N)：在恶梦难度下此怪物可能拥有第1-6个特殊属性的概率，默认为100%。

par1-6(N)：在恶梦难度下此怪物的第1-6个特殊属性的参数。

min1-6(N)：在恶梦难度下此怪物的第1-6个特殊属性的最小值参数。

max1-6(N)：在恶梦难度下此怪物的第1-6个特殊属性的最大值参数。

prop1-6(H)：在地狱难度下此怪物可能拥有的第1-6个特殊属性。

chance1-6(H)：在地狱难度下此怪物可能拥有第1-6个特殊属性的概率，默认为100%。

par1-6(H)：在地狱难度下此怪物的第1-6个特殊属性的参数。

min1-6(H)：在地狱难度下此怪物的第1-6个特殊属性的最小值参数。

max1-6(H)：在地狱难度下此怪物的第1-6个特殊属性的最大值参数。

*eol：行尾标志，必须为0。

*/

typedef struct
{
    unsigned int vId;   //monstats

    unsigned int vprop1;    //properties
    unsigned int vpar1;
    int vmin1;
    int vmax1;

    unsigned int vprop2;    //properties
    unsigned int vpar2;
    int vmin2;
    int vmax2;

    unsigned int vprop3;    //properties
    unsigned int vpar3;
    int vmin3;
    int vmax3;

    unsigned int vprop4;    //properties
    unsigned int vpar4;
    int vmin4;
    int vmax4;

    unsigned int vprop5;    //properties
    unsigned int vpar5;
    int vmin5;
    int vmax5;

    unsigned int vprop6;    //properties
    unsigned int vpar6;
    int vmin6;
    int vmax6;

    unsigned int vprop1myspmybr1Nmybr2;    //properties
    unsigned int vpar1myspmybr1Nmybr2;
    int vmin1myspmybr1Nmybr2;
    int vmax1myspmybr1Nmybr2;

    unsigned int vprop2myspmybr1Nmybr2;    //properties
    unsigned int vpar2myspmybr1Nmybr2;
    int vmin2myspmybr1Nmybr2;
    int vmax2myspmybr1Nmybr2;

    unsigned int vprop3myspmybr1Nmybr2;    //properties
    unsigned int vpar3myspmybr1Nmybr2;
    int vmin3myspmybr1Nmybr2;
    int vmax3myspmybr1Nmybr2;

    unsigned int vprop4myspmybr1Nmybr2;    //properties
    unsigned int vpar4myspmybr1Nmybr2;
    int vmin4myspmybr1Nmybr2;
    int vmax4myspmybr1Nmybr2;

    unsigned int vprop5myspmybr1Nmybr2;    //properties
    unsigned int vpar5myspmybr1Nmybr2;
    int vmin5myspmybr1Nmybr2;
    int vmax5myspmybr1Nmybr2;

    unsigned int vprop6myspmybr1Nmybr2;    //properties
    unsigned int vpar6myspmybr1Nmybr2;
    int vmin6myspmybr1Nmybr2;
    int vmax6myspmybr1Nmybr2;

    unsigned int vprop1myspmybr1Hmybr2;    //properties
    unsigned int vpar1myspmybr1Hmybr2;
    int vmin1myspmybr1Hmybr2;
    int vmax1myspmybr1Hmybr2;

    unsigned int vprop2myspmybr1Hmybr2;    //properties
    unsigned int vpar2myspmybr1Hmybr2;
    int vmin2myspmybr1Hmybr2;
    int vmax2myspmybr1Hmybr2;

    unsigned int vprop3myspmybr1Hmybr2;    //properties
    unsigned int vpar3myspmybr1Hmybr2;
    int vmin3myspmybr1Hmybr2;
    int vmax3myspmybr1Hmybr2;

    unsigned int vprop4myspmybr1Hmybr2;    //properties
    unsigned int vpar4myspmybr1Hmybr2;
    int vmin4myspmybr1Hmybr2;
    int vmax4myspmybr1Hmybr2;

    unsigned int vprop5myspmybr1Hmybr2;    //properties
    unsigned int vpar5myspmybr1Hmybr2;
    int vmin5myspmybr1Hmybr2;
    int vmax5myspmybr1Hmybr2;

    unsigned int vprop6myspmybr1Hmybr2;    //properties
    unsigned int vpar6myspmybr1Hmybr2;
    int vmin6myspmybr1Hmybr2;
    int vmax6myspmybr1Hmybr2;

    unsigned char vchance1;
    unsigned char vchance2;
    unsigned char vchance3;
    unsigned char vchance4;

    unsigned char vchance5;
    unsigned char vchance6;
    unsigned char vchance1myspmybr1Nmybr2;
    unsigned char vchance2myspmybr1Nmybr2;

    unsigned char vchance3myspmybr1Nmybr2;
    unsigned char vchance4myspmybr1Nmybr2;
    unsigned char vchance5myspmybr1Nmybr2;
    unsigned char vchance6myspmybr1Nmybr2;

    unsigned char vchance1myspmybr1Hmybr2;
    unsigned char vchance2myspmybr1Hmybr2;
    unsigned char vchance3myspmybr1Hmybr2;
    unsigned char vchance4myspmybr1Hmybr2;

    unsigned char vchance5myspmybr1Hmybr2;
    unsigned char vchance6myspmybr1Hmybr2;
    unsigned char pad0x136[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned int vprop1;    //properties
    unsigned int vpar1;
    int vmin1;
    int vmax1;
} ST_PROP;

typedef struct
{
    unsigned char vId[64];
    unsigned short sString;
} ST_MON_PROP;

static unsigned int m_iMonPropCount = 0;
static ST_MON_PROP *m_astMonProp = NULL;

MODULE_SETLINES_FUNC(m_astMonProp, ST_MON_PROP);
MODULE_HAVENAME_FUNC(m_astMonProp, vId, m_iMonPropCount);

static void module_SetLines_Pre(unsigned int uiLines)
{
    SETLINES_FUNC_NAME(uiLines);
    MonStats_LinkMonProp(m_astMonProp, uiLines, sizeof(ST_MON_PROP), offsetof(ST_MON_PROP, sString));
}

char *MonProp_GetPropId(unsigned int id)
{
    if ( id >= m_iMonPropCount )
    {
        return NULL;
    }

    return m_astMonProp[id].vId;
}

static int MonProp_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        if ( !String_BuildName(FORMAT(monprop), m_astMonProp[pstLineInfo->vId].sString, pcTemplate, NAME_PREFIX, m_iMonPropCount, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vId);
        }

        strncpy(m_astMonProp[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonProp[pstLineInfo->vId].vId));
        String_Trim(m_astMonProp[pstLineInfo->vId].vId);
        m_iMonPropCount++;
        return 1;
    }

    return 0;
}

static int MonProp_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        strncpy(acOutput, m_astMonProp[pstLineInfo->vId].vId, sizeof(m_astMonProp[pstLineInfo->vId].vId));

        return 1;
    }

    return 0;
}

static void MonProp_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6myspmybr1Nmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6myspmybr1Hmybr2, USHORT_PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2myspmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6myspmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4myspmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6myspmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_monprop(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            MonProp_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonPropCount = 0;

            m_stCallback.pfnConvertValue = MonProp_ConvertValue_Pre;
            m_stCallback.pfnSetLines = module_SetLines_Pre;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonProp_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = MonProp_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

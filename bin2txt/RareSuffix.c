#include "global.h"

#define FILE_PREFIX "RareSuffix"

/*
文件名解析：
Rare：稀有的，在暗黑里指亮金的。
Prefix：前缀，就是词缀中的前缀。
Suffix：后缀，就是词缀中的后缀。
所以这两个文件描述了所有亮金级词缀的前缀与后缀的相关信息。
此文件中的每一行表示一个词缀前缀或后缀。


回复

    2楼
    2011-09-30 22:15

    举报 |

    zqtjingzi
    小吧主
    12

每列的含义如下：


回复

    3楼
    2011-09-30 22:16

    举报 |

    zqtjingzi
    小吧主
    12

Name：前缀名或后缀名。

version：适用的最低游戏版本。

itype1-7：此词缀适用于的第1-7种装备类型。

etype1-4：此词缀不适用的第1-4种装备类型，所有etype应是某一itype的子类型。

此词缀最终能够适用的装备类型为sum(itype1-7) - sum(etype1-4)，即所有itype的总和再除去etype中的类型。

add：价格增加因子。

divide：价格约束因子。

multiply：价格放大因子。


回复

    4楼
    2011-09-30 22:16

    举报 |

    zqtjingzi
    小吧主
    12

特殊说明1：
之所以把这两个文件放在一起说明是因为它们所含有的列是一模一样的。


回复

    5楼
    2011-09-30 22:16

    举报 |

    zqtjingzi
    小吧主
    12

特殊说明2：
所有亮金级词缀都没有属性，只有名字和适用的装备类型。也就是说某一亮金级词缀是否出现只与装备底材类型有关，而且相同属性的装备词缀可能完全不一样。反之也是，相同名字的亮金装备属性可能完全不一样。
*/

typedef struct
{
    unsigned char pad0x00[14];
    unsigned short vversion;

    unsigned short vitype1;
    unsigned short vitype2;

    unsigned short vitype3;
    unsigned short vitype4;

    unsigned short vitype5;
    unsigned short vitype6;

    unsigned short vitype7;
    unsigned short vetype1;

    unsigned short vetype2;
    unsigned short vetype3;

    unsigned short vetype4;
    unsigned char vname[32];

    unsigned char pad0x46[2];
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "divide",
    "multiply",
    "add",
    NULL,
};

int process_raresuffix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, USHORT_ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, USHORT_ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, USHORT_ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, USHORT_ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, USHORT_ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


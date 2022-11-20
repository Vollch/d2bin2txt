#include "global.h"

#define FILE_PREFIX "books"
#define NAME_PREFIX "bk"

/*
Name：书名，未使用。

Nameco：名字后缀。此书的命名为Book + 后缀。

Completed：是否已完成。

ScrollSpellCode：对应卷轴的物品代码。

BookSpellCode：书的物品代码。

pSpell：使用效果。

SpellIcon：是否有使用图标。

ScrollSkill：使用卷轴对应的技能。

BookSkill：使用书对应的技能，即数量减1，并相当于使用一个卷轴。

BaseCost：书的价格。

CostPerCharge：每增加一个卷轴所增加的价格。
*/

typedef struct
{
    unsigned short vName; //strings
    char vSpellIcon;
    unsigned char iPadding0;

    unsigned int vpSpell;

    unsigned short vScrollSkill;  //skills
    unsigned short sPad1;
    unsigned short vBookSkill;    //skills
    unsigned short sPad2;

    unsigned int vBaseCost;

    unsigned int vCostPerCharge;

    unsigned char vScrollSpellCode[4];
    unsigned char vBookSpellCode[4];
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Completed",
    "Namco",
    NULL,
};

static int Books_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Namco") )
    {
        if ( !String_BuildName(FORMAT(books), pstLineInfo->vName, pcTemplate, Skills_GetSkillName(pstLineInfo->vBookSkill), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !strcmp(acKey, "Completed") )
    {
        acOutput[0] = '1';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_books(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpellIcon, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSpell, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ScrollSkill, USHORT_SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BookSkill, USHORT_SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseCost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostPerCharge, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ScrollSpellCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BookSpellCode, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = Books_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "Books"
#define NAME_PREFIX "bk"

typedef struct
{
    unsigned short vName; //strings
    char vSpellIcon;
    unsigned char pad0x03;

    unsigned int vpSpell;

    unsigned short vScrollSkill; //skills
    unsigned char pad0x0A[2];

    unsigned short vBookSkill; //skills
    unsigned char pad0x0E[2];

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

static unsigned int m_iBinStructSize = 0;

static int Books_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Namco") )
    {
        if ( !String_BuildName(FORMAT(books), pstLineInfo->vName, pcTemplate, Lookup_Skill(pstLineInfo->vBookSkill), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "Completed") )
    {
        acOutput[0] = '1';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static void Books_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpellIcon, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSpell, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ScrollSkill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BookSkill, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseCost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostPerCharge, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ScrollSpellCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BookSpellCode, STRING);
}

int process_books(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_BOOKS_109) )
    {
        return process_books109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Books_InitValueMap(pstValueMap, pstLineInfo);

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


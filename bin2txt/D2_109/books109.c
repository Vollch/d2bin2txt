#include "../global.h"

#define FILE_PREFIX "Books"

static char *m_apcNotUsed[] =
{
    "Completed",
    "Namco",
    NULL,
};

static void Books_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_BOOKS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpellIcon, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpellOffset, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillScrollOffset, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillBookOffset, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseCost, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostPerCharge, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ScrollSpellCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BookSpellCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
}

int process_books109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_BOOKS_109 *pstLineInfo = (ST_BOOKS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            Books_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


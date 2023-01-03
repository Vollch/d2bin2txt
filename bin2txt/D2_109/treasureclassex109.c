#include "../global.h"

#define FILE_PREFIX "TreasureClassEx"

typedef struct
{
    unsigned char vTreasuremyspClass[36];
} ST_TREASURECLASSEX;

static char *m_apcNotUsed[] =
{
    "SumItems",
    "TotalProb",
    "DropChance",
    "SumDrop",
    "Better",
    NULL,
};
static unsigned int m_iTreasureClassExCount = 0;
static ST_TREASURECLASSEX *m_astTreasureClassEx = NULL;

MODULE_SETLINES_FUNC(m_astTreasureClassEx, ST_TREASURECLASSEX);

static char *TreasureClassEx_GetItemTreasureClass(unsigned int id)
{
    unsigned int uiOffset = id - g_iTreasureClassOffset;

    if ( uiOffset < m_iTreasureClassExCount && strcmp("Gold", m_astTreasureClassEx[uiOffset].vTreasuremyspClass) )
    {
        return m_astTreasureClassEx[uiOffset].vTreasuremyspClass;
    }

    if ( id == -1 )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int TreasureClassEx_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_TREASURECLASSEX_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Treasure Class") )
    {
        strncpy(m_astTreasureClassEx[m_iTreasureClassExCount].vTreasuremyspClass, pstLineInfo->vTreasuremyspClass, sizeof(m_astTreasureClassEx[m_iTreasureClassExCount].vTreasuremyspClass));
        String_Trim(m_astTreasureClassEx[m_iTreasureClassExCount].vTreasuremyspClass);

        m_iTreasureClassExCount++;
    }

    return 0;
}

static void TreasureClassEx_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_TREASURECLASSEX_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasuremyspClass, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Picks, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Set, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Unique, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoDrop, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item10, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob10, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, Term, EOL);
}

int process_treasureclassex109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_TREASURECLASSEX_109 *pstLineInfo = (ST_TREASURECLASSEX_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            TreasureClassEx_InitValueMap(pstValueMap, pstLineInfo);

            m_iTreasureClassExCount = 0;
            Lookup_TreasureClass = TreasureClassEx_GetItemTreasureClass;

            m_stCallback.pfnConvertValue = TreasureClassEx_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "TreasureClassEx2"

#pragma pack(push, 1)
typedef struct
{
    unsigned char bMonType;
    unsigned short vmonster;
    unsigned int vhcIdx;
    unsigned short vgroup;
    unsigned short vminlevel;
    char vglobal;
    char vchampion;
    char vsuperunique;
    char vboss;
    char vPicks;
    int vUnique;
    int vSet;
    int vRare;
    int vMagic;
    int vNoDrop;
    unsigned char vItem1[4];
    unsigned char vItem2[4];
    unsigned char vItem3[4];
    unsigned char vItem4[4];
    unsigned char vItem5[4];
    unsigned char vItem6[4];
    unsigned char vItem7[4];
    unsigned char vItem8[4];
    unsigned char vItem9[4];
    unsigned char vItem10[4];
    int vProb1;
    int vProb2;
    int vProb3;
    int vProb4;
    int vProb5;
    int vProb6;
    int vProb7;
    int vProb8;
    int vProb9;
    int vProb10;
    char vact;
    int vLevelID;
    char vuniqueboss;
    char vPossessed;
    char vGhostly;
    char vMinion;
    char vEnabled;
    unsigned short vmaxlevel;
    unsigned short vglobalprob;
    unsigned int vmod1; // property
    unsigned int vmod2; // property
    unsigned int vmod3; // property
    int vmodchance1;
    int vmodchance2;
    int vmodchance3;
    unsigned int vmodpar1;
    unsigned int vmodpar2;
    unsigned int vmodpar3;
    int vmodmin1;
    int vmodmin2;
    int vmodmin3;
    int vmodmax1;
    int vmodmax2;
    int vmodmax3;
    int vmodquality1;
    int vmodquality2;
    int vmodquality3;
    char vItemQuality1;
    char vItemQuality2;
    char vItemQuality3;
    char vItemQuality4;
    char vItemQuality5;
    char vItemQuality6;
    char vItemQuality7;
    char vItemQuality8;
    char vItemQuality9;
    char vItemQuality10;
    char vNormal;
    char vNightmare;
    char vHell;
} ST_LINE_INFO;
#pragma pack(pop)

static int TreasureClassEx2_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "monster") )
    {
        char *pcResult = NULL;

        if ( 1 == pstLineInfo->bMonType && (pcResult = Lookup_MonStats(pstLineInfo->vmonster)))
        {
            strcpy(acOutput, pcResult);
        }
        else if ( 2 == pstLineInfo->bMonType && (pcResult = Lookup_SuperUnique(pstLineInfo->vmonster)))
        {
            strcpy(acOutput, pcResult);
        }

        return 1;
    }

    return 0;
}

int process_TreasureClassEx2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monster, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minlevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, global, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, champion, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, superunique, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, boss, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Picks, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Unique, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Set, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, INT);
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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, act, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelID, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniqueboss, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Possessed, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Ghostly, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Minion, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Enabled, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, globalprob, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modchance1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modchance2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modchance3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modpar1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modpar2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modpar3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmax3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modquality1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modquality2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modquality3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality1, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality2, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality3, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality4, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality5, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality6, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality7, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality8, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality9, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemQuality10, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nightmare, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hell, CHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(superuniques, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = TreasureClassEx2_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


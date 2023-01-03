#include "../global.h"

#define FILE_PREFIX "GlobalTCEx2Settings"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    char vTcPicksNormal;
    char vTcPicksSuperUnique;
    char vTcPicksBoss;
    char vTcPicksUnique;
    char vTcPicksChampion;
    char vTcPicksPossessed;
    char vTcPicksGhostly;
    char vTcPicksMinion;
    unsigned short vQualityBonusNormal;
    unsigned short vQualityBonusSuperUnique;
    unsigned short vQualityBonusBoss;
    unsigned short vQualityBonusUnique;
    unsigned short vQualityBonusChampion;
    unsigned short vQualityBonusPossessed;
    unsigned short vQualityBonusGhostly;
    unsigned short vQualityBonusMinion;
    unsigned short vnormDropChance;
    unsigned short vglobalDefaultChance;
    unsigned short vglobalNoDrop;
} ST_LINE_INFO;
#pragma pack(pop)


int process_GlobalTCEx2Settings(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksNormal, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksSuperUnique, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksBoss, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksUnique, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksChampion, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksPossessed, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksGhostly, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TcPicksMinion, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusNormal, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusSuperUnique, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusBoss, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusUnique, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusChampion, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusPossessed, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusGhostly, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QualityBonusMinion, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, normDropChance, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, globalDefaultChance, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, globalNoDrop, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


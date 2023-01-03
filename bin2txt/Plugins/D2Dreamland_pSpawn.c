#include "../global.h"

#define FILE_PREFIX "pSpawn"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vhcIdx;
    unsigned short vLevel;
    unsigned char vClass;
    char vcLvl;
    char vDifficulty;
    unsigned short vSuperUniqueMin; // uniq
    unsigned short vSuperUniqueMax; // uniq
    unsigned short vMonMin; // monstats
    unsigned short vMonMax; // monstats
    char vQtyMin;
    char vQtyMax;
    char vRadiusMin;
    char vRadiusMax;
    char vLeash;
    unsigned short vOverlay; // overlay
} ST_LINE_INFO;
#pragma pack(pop)

int process_pSpawn(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SuperUniqueMin, SUPERUNIQUE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SuperUniqueMax, SUPERUNIQUE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonMin, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonMax, MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QtyMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QtyMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RadiusMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RadiusMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Leash, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Overlay, OVERLAY);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(superuniques, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
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


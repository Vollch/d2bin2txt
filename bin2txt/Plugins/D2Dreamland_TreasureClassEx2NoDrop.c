#include "../global.h"

#define FILE_PREFIX "TreasureClassEx2NoDrop"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vMonsterId[3];
    unsigned int vhcIdx;
} ST_LINE_INFO;
#pragma pack(pop)

static int TreasureClassEx2NoDrop_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "MonsterId") )
    {
        unsigned short usMonster = *(unsigned short*)&pstLineInfo->vMonsterId[1];
        char *pcResult = NULL;

        if ( pstLineInfo->vMonsterId[0] == 1 && (pcResult = MonStats_GetStatsName(usMonster)))
        {
            strcpy(acOutput, pcResult);
        }
        else if ( pstLineInfo->vMonsterId[0] == 2 && (pcResult = SuperUniques_GetItemUniqueCode(usMonster)))
        {
            strcpy(acOutput, pcResult);
        }

        return 1;
    }

    return 0;
}

int process_TreasureClassEx2NoDrop(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterId, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = TreasureClassEx2NoDrop_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


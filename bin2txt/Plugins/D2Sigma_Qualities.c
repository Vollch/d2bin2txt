#include "../global.h"

#define FILE_PREFIX "Qualities"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vAutomagics;
    unsigned char vRuneword;
    unsigned short vEthChance;
    unsigned char vMaxSock;
} ST_LINE_INFO;
#pragma pack(pop)

int process_Qualities(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Automagics, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Runeword, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EthChance, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

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


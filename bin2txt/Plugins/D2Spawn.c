#include "../global.h"

#define FILE_PREFIX "D2Spawn"
#define NAME_PREFIX "sw"

typedef struct
{
    unsigned short vIDx;
    unsigned short vhcIDxSU1;

    unsigned short vhcIDxSU2;
    unsigned short vamountSU;

    unsigned short vrandMobs;
    unsigned short vhcIDxMob1;

    unsigned short vhcIDxMob2;
    unsigned short vamountMob;

    unsigned short vlevelreq;
    unsigned short vReqLevelID;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int D2Spawn_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        char* pcName = NULL;
        ( (pstLineInfo->vhcIDxSU1 && (pcName = SuperUniques_GetItemUniqueCode(pstLineInfo->vhcIDxSU1))) ||
          (pstLineInfo->vhcIDxSU2 && (pcName = SuperUniques_GetItemUniqueCode(pstLineInfo->vhcIDxSU2))) ||
          (pstLineInfo->vhcIDxMob1 && (pcName = MonStats_GetStatsName(pstLineInfo->vhcIDxMob1))) ||
          (pstLineInfo->vhcIDxMob2 && (pcName = MonStats_GetStatsName(pstLineInfo->vhcIDxMob2))) );
        if ( !String_BuildName(FORMAT(D2Spawn), 0xFFFF, pcTemplate, pcName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}


int process_D2Spawn(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IDx, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDxSU1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDxSU2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amountSU, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, randMobs, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDxMob1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDxMob2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amountMob, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReqLevelID, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(superuniques, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2Spawn_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);

        default:
            break;
    }

    return 1;
}


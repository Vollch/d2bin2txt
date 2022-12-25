#include "../global.h"

#define FILE_PREFIX "experience_sp"

typedef struct
{
    unsigned int vAmazon;
    unsigned int vSorceress;
    unsigned int vNecromancer;
    unsigned int vPaladin;

    unsigned int vBarbarian;
    unsigned int vDruid;
    unsigned int vAssassin;
    unsigned int vExpRatio;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Level",
    NULL,
};

static int Experience_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Level") )
    {
        char acName[16] = {0};
        sprintf(acName, "%d", iLineNo - 1);

        if ( !String_BuildName(FORMAT(experience), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%u", iLineNo - 1);
        }

        return 1;
    }

    return 0;
}

int process_experience_sp(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Amazon, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sorceress, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Necromancer, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Paladin, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Barbarian, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Druid, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Assassin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExpRatio, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            m_stCallback.pfnFieldProc = Experience_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

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


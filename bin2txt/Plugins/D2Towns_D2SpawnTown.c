#include "../global.h"

#define FILE_PREFIX "D2SpawnTown"
#define NAME_PREFIX "st"

#pragma pack(push, 1)
typedef struct
{
    int vSourceLvl;
    int vTargetLvl;
    char vAct;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int D2SpawnTown_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(D2SpawnTown), 0xFFFF, pcTemplate, Lookup_Level(pstLineInfo->vSourceLvl), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}


int process_D2SpawnTown(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SourceLvl, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TargetLvl, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, CHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2SpawnTown_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);

        default:
            break;
    }

    return 1;
}


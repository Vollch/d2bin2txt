#include "../global.h"

#define FILE_PREFIX "CellFiles"
#define NAME_PREFIX "cf"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vName; // 0x11
    unsigned char vFilename[128];
} ST_LINE_INFO;
#pragma pack(pop)

typedef struct
{
    char vName[64];
} ST_CELL_FILE;

static int m_iModuleActive = 0;

static unsigned int m_iCellFileCount = 0;
static ST_CELL_FILE *m_astCellFile = NULL;

MODULE_SETLINES_FUNC(m_astCellFile, ST_CELL_FILE);
MODULE_HAVENAME_FUNC(m_astCellFile, vName, m_iCellFileCount);

int isD2SigmaActive()
{
    return m_iModuleActive;
}

static int CellFiles_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        char acFile[129] = {0};
        String_StripFileName(pstLineInfo->vFilename, acFile, 128);

        if ( !String_BuildName(FORMAT(CellFiles), 0xFFFF, pcTemplate, acFile, m_iCellFileCount, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vName);
        }

        strncpy(m_astCellFile[pstLineInfo->vName].vName, acOutput, sizeof(m_astCellFile[pstLineInfo->vName].vName));
        String_Trim(m_astCellFile[pstLineInfo->vName].vName);
        m_iCellFileCount++;
        return 1;
    }

    return 0;
}

int process_CellFiles(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filename, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            if ( getBinStructSize(acBinPath, FILE_PREFIX) == sizeof(ST_LINE_INFO) )
            {
                m_iModuleActive = 1;
            }
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = CellFiles_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;

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

char *CellFiles_GetName(unsigned int id)
{
    if ( id >= m_iCellFileCount )
    {
        return NULL;
    }

    return m_astCellFile[id].vName;
}
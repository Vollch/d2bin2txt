#include "../global.h"

#define FILE_PREFIX "UniqueTitle"
#define NAME_PREFIX "ut"

typedef struct
{
    unsigned short vName;   //strings
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Namco",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int UniqueTitle_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Namco") )
    {
        if ( !String_BuildName(FORMAT(uniquetitle), pstLineInfo->vName, pcTemplate, NULL, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_uniquetitle(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_UNIQUE_109) )
    {
        return process_unique109(FILE_PREFIX, acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, TBL_STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = UniqueTitle_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


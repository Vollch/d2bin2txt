#include "../global.h"

#define FILE_PREFIX "UniquePrefix"
#define NAME_PREFIX "up"

typedef struct
{
    unsigned short vName;   //strings
} ST_LINE_INFO;

static unsigned int m_iBinStructSize = 0;

int process_uniqueprefix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
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
            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


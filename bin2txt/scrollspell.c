#include "global.h"

#define FILE_PREFIX "scrollspell"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vfilename[32];
    unsigned char venabled;
} ST_LINE_INFO;
#pragma pack(pop)

int process_scrollspell(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, filename, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);

    VALUE_MAP_DEFINE_3(pstValueMap, pstLineInfo, end, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.iOptional = 1;

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


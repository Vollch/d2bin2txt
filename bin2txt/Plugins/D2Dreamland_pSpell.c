#include "../global.h"

#define FILE_PREFIX "pSpell"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vitemCode[4];
    unsigned char vpSpell;
    unsigned char vdestroy;
} ST_LINE_INFO;
#pragma pack(pop)


int process_pSpell(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemCode, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSpell, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, destroy, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
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


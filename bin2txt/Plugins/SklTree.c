#include "../global.h"

#define FILE_PREFIX "SklTree"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vClass[4];
    unsigned char vSkillPage;
    unsigned int vTabStr; // string
    unsigned char vIconSize[8];
    unsigned char vRows[50];
    unsigned char vColumns[50];
    unsigned char vTabLoc[10];
    unsigned char vTabSize[10];
    unsigned char vCancelLoc[10];
    unsigned char vCancelSize[8];
    unsigned char vShowCancel;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcNotUsed[] = 
{
    "*remarks",
    NULL,
};

int process_SklTree(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillPage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TabStr, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IconSize, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rows, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Columns, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TabLoc, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TabSize, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CancelLoc, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CancelSize, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ShowCancel, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


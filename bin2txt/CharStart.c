#include "global.h"

#define FILE_PREFIX "CharStart"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vFunc[10];
    unsigned char vClass;
    unsigned short vStatName;
    unsigned short vSkillName;
    int vParamVal;
} ST_LINE_INFO; // 1.1
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] = 
{
    "*remarks",
    NULL,
};

static int CharStart_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_CharStart(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Func, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatName, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillName, USHORT_SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ParamVal, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = CharStart_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "global.h"

#define FILE_PREFIX "messages"
#define NAME_PREFIX "bl"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vNameStr;
    unsigned char vDifficulty;
    unsigned char vAct;
    unsigned short vArea;
    unsigned char vQuest;
    unsigned char vClass;
    unsigned short vLevelMin;
    unsigned short vLevelMax;
    unsigned char vTown;
    unsigned char vAllSame;
    unsigned char acPad[2];

} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    "*eol",
    NULL,
};

static int BookOfLore_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(BookOfLore), pstLineInfo->vNameStr, pcTemplate, NAME_PREFIX, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_BookOfLore(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameStr, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Area, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelMin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelMax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Town, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AllSame, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = BookOfLore_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


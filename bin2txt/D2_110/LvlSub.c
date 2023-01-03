#include "../global.h"

#define FILE_PREFIX "LvlSub"
#define NAME_PREFIX "ls"

typedef struct
{
    int vType;

    unsigned char vFile[60];

    int vCheckAll;
    int vBordType;
    int vDt1Mask;
    int vGridSize;

    unsigned char pad0x50[204];

    int vProb0;

    int vProb1;
    int vProb2;
    int vProb3;
    int vProb4;

    int vTrials0;

    int vTrials1;
    int vTrials2;
    int vTrials3;

    int vTrials4;

    int vMax0;

    int vMax1;
    int vMax2;
    int vMax3;
    int vMax4;

    int vExpansion;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Beta",
    NULL,
};

static int LvlSub_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        char acName[33] = {0};
        String_StripFileName(pstLineInfo->vFile, acName, 32);
        if ( !String_BuildName(FORMAT(lvlsub), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_lvlsub(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Type, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CheckAll, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BordType, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dt1Mask, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GridSize, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob0, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Prob4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trials0, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trials1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trials2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trials3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trials4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Max0, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Max3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expansion, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = LvlSub_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

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


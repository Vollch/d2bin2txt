#include "../global.h"

#define FILE_PREFIX "AutoMap"

typedef struct
{
    unsigned char vLevelName[16];
    unsigned char vTileName[8];

    unsigned char vStyle;
    char vStartSequence;
    char vEndSequence;
    unsigned char pad0x1B;

    int vCel1;
    int vCel2;
    int vCel3;

    int vCel4;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "Type1",
    "Type2",
    "Type3",
    "Type4",
    NULL,
};

static int automap_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;

    if ( isD2SigmaActive() )
    {
        if ( !stricmp(acKey, "LevelName") )
        {
            if ( pcResult = Lookup_LvlType(*(unsigned short *)&pstLineInfo->vLevelName[0]) )
            {
                strcpy(acOutput, pcResult);
            }

            return 1;
        }
    }

    return 0;
}

int process_automap(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( isD2SigmaActive() )
    {
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelName, USHORT);
    } else {
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelName, STRING);
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TileName, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Style, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StartSequence, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EndSequence, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Cel1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Cel2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Cel3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Cel4, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(CellFiles, acTemplatePath, acBinPath, acTxtPath);
            if ( isD2SigmaActive() )
            {
                MODULE_DEPEND_CALL(lvltypes, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.pfnConvertValue = automap_ConvertValue;

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


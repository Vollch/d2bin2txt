#include "global.h"

#define FILE_PREFIX "D2NewStats"
#define NAME_PREFIX "ns"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vStatOnly;
    unsigned char vStrOnly;

    unsigned short vtblIDx;
    unsigned short vStat;

    unsigned short vXleft;
    unsigned short vXright;
    unsigned short vY;
    unsigned short vXleft2;
    unsigned short vXright2;
    unsigned short vY2;

    unsigned char vFont;
    unsigned char vColor;
    unsigned char vFont2;
    unsigned char vColor2;
    unsigned char vRiN;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Name",
    "*eol",
    NULL,
};

static int D2NewStats_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Name") )
    {
        unsigned int iString = pstLineInfo->vtblIDx;
        if ( !String_FindString(iString, "dummy") )
        {
            iString = ItemStatCost_GetString(pstLineInfo->vStat);
        }
        if ( !String_BuildName(FORMAT(D2NewStats), iString, pcTemplate, ItemStatCost_GetStateName(pstLineInfo->vStat), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( !stricmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_D2NewStats(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatOnly, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrOnly, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, tblIDx, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xleft, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xright, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Y, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xleft2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xright2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Y2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Font, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Color, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Font2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Color2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RiN, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = D2NewStats_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "global.h"

#define FILE_PREFIX "monpreset"

typedef struct
{
    unsigned char vAct;
    unsigned char bPlaceType;
    unsigned short vPlace;
} ST_LINE_INFO;

static int MonPreset_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Place") )
    {
        char *pcResult = NULL;

        if ( 1 == pstLineInfo->bPlaceType && (pcResult = MonStats_GetStatsName(pstLineInfo->vPlace)) )
        {
            strcpy(acOutput, pcResult);
        }
        else if ( 0 == pstLineInfo->bPlaceType && (pcResult = MonPlace_GetPlaceName(pstLineInfo->vPlace)) )
        {
            strcpy(acOutput, pcResult);
        }
        else if ( 2 == pstLineInfo->bPlaceType && (pcResult = SuperUniques_GetItemUniqueCode(pstLineInfo->vPlace)) )
        {
            strcpy(acOutput, pcResult);
        }

        return 1;
    }

    return 0;
}

int process_monpreset(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Place, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monplace, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(superuniques, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = MonPreset_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


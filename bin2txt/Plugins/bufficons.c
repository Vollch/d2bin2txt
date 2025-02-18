#include "../global.h"

#define FILE_PREFIX "_bufficons"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vStateId;
    unsigned int vType;
    unsigned int vPalShift;
    unsigned int vSkillId;
    unsigned short vHoverString;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*IconCel",
    "*State",
    NULL,
};

static int BuffIcons_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;

    if ( !stricmp(acKey, "*IconCel") )
    {
        sprintf(acOutput, "%u", iLineNo);

        return 1;
    }
    if ( !stricmp(acKey, "*State") )
    {
        if ( pcResult = Lookup_State(pstLineInfo->vStateId) )
        {
            strcpy(acOutput, pcResult);
        }

        return 1;
    }

    return 0;
}

int process_bufficons(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StateId, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Type, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PalShift, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillId, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HoverString, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = BuffIcons_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


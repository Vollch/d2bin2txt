#include "../global.h"

#define FILE_PREFIX "D2AddSkill"
#define NAME_PREFIX "as"

#pragma pack(push, 1)
typedef struct
{
    unsigned short vID;
    unsigned short vSkill; // 0x11
    unsigned char vcharclass; // 0x0D
    short vminslvl;
    short vmaxslvl;
    short vminclvl;
    short vmaxclvl;
    unsigned short vstat1; // 0x14
    unsigned int vval1;
    unsigned short vstat2; // 0x14
    unsigned int vval2;
    unsigned short vstat3; // 0x14
    unsigned int vval3;
    unsigned short vstat4; // 0x14
    unsigned int vval4;
    unsigned short vreqskill1; // 0x11
    unsigned short vslvl1;
    unsigned short vreqskill2; // 0x11
    unsigned short vslvl2;
    unsigned short vreqskill3; // 0x11
    unsigned short vslvl3;
    unsigned short vreqskill4; // 0x11
    unsigned short vslvl4;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int D2AddSkill_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(D2AddSkill), 0xFFFF, pcTemplate, Lookup_Skill(pstLineInfo->vSkill), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_D2AddSkill(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minslvl, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxslvl, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minclvl, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxclvl, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill1, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, slvl1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill2, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, slvl2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill3, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, slvl3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqskill4, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, slvl4, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2AddSkill_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


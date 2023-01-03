#include "../global.h"

#define FILE_PREFIX "Charstats2"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vhcIdx;
    unsigned char vclassID; // class
    unsigned int vSkillPerLevel; // skillcode
} ST_LINE_INFO_2900992;

typedef struct
{
    unsigned char vhcIdx;
    unsigned short vclassID; // class
    unsigned char vSkillPerLevel;
} ST_LINE_INFO_813568;
#pragma pack(pop)

static unsigned int m_iBinStructSize = 0;

int process_Charstats2_2900992(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_2900992 *pstLineInfo = (ST_LINE_INFO_2900992 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classID, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillPerLevel, SKILLCODE);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Charstats2_813568(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_813568 *pstLineInfo = (ST_LINE_INFO_813568 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classID, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillPerLevel, UCHAR);

    m_stCallback.eModuleType = EN_MODULE_PLUGIN;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_Charstats2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_2900992) || m_iBinStructSize == sizeof(ST_LINE_INFO_813568) )
            {
                MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            }
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_2900992) )
            {
                MODULE_DEPEND_CALL(skillscode, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_INIT:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_2900992) )
            {
                return process_Charstats2_2900992(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize == sizeof(ST_LINE_INFO_813568) )
            {
                return process_Charstats2_813568(acTemplatePath, acBinPath, acTxtPath);
            }
            else if ( m_iBinStructSize > 0 )
            {
                my_printf("Unknown version of Charstats2\n");
            }
            break;

        default:
            break;
    }

    return 1;
}


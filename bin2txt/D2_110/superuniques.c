#include "../global.h"

#define FILE_PREFIX "SuperUniques"
#define NAME_PREFIX "su"


typedef struct
{
    unsigned short vSuperunique;
    unsigned short vName; //strings

    unsigned short vClass; //monstats
    unsigned char pad0x06[2];

    unsigned int vhcIdx;

    unsigned int vMod1;
    unsigned int vMod2;
    unsigned int vMod3;

    unsigned short vMonSound; //sounds
    unsigned char pad0x1A[2];

    unsigned int vMinGrp;
    unsigned int vMaxGrp;

    unsigned char vAutoPos;
    unsigned char vEClass;
    unsigned char vStacks;
    unsigned char vReplaceable;

    unsigned char vUtrans;
    unsigned char vUtransmybr1Nmybr2;
    unsigned char vUtransmybr1Hmybr2;
    unsigned char pad0x2B;

    unsigned short vTC; //treasure
    unsigned short vTCmybr1Nmybr2; //treasure

    unsigned short vTCmybr1Hmybr2; //treasure
    unsigned char pad0x32[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vSuperunique[64];
} ST_SUPER_UNIQUES;

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iSuperUniquesCount = 0;
static unsigned int m_iSuperUniquesHaveEmpty = 0;
static ST_SUPER_UNIQUES *m_astSuperUniques = NULL;

MODULE_SETLINES_FUNC(m_astSuperUniques, ST_SUPER_UNIQUES);
MODULE_HAVENAME_FUNC(m_astSuperUniques, vSuperunique, m_iSuperUniquesCount);

static char *SuperUniques_GetItemUniqueCode(unsigned int id)
{
    if ( id < m_iSuperUniquesCount )
    {
        return m_astSuperUniques[id].vSuperunique;
    }

    if ( id == -1 && m_iSuperUniquesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int SuperUniques_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult = NULL;

    if ( !stricmp(acKey, "Superunique") )
    {
        if ( !String_BuildName(FORMAT(superuniques), pstLineInfo->vName, pcTemplate, NULL, pstLineInfo->vSuperunique, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vSuperunique);
        }

        strncpy(m_astSuperUniques[pstLineInfo->vSuperunique].vSuperunique, acOutput, sizeof(m_astSuperUniques[pstLineInfo->vSuperunique].vSuperunique));
        String_Trim(m_astSuperUniques[pstLineInfo->vSuperunique].vSuperunique);
        m_iSuperUniquesHaveEmpty |= !m_astSuperUniques[pstLineInfo->vSuperunique].vSuperunique[0];

        m_iSuperUniquesCount++;
        return 1;
    }

    return 0;
}

static void SuperUniques_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Superunique, SUPERUNIQUE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, TBL_STRING);   //strings

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, MONSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mod3, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSound, MONSOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinGrp, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxGrp, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoPos, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EClass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stacks, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Replaceable, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utrans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utransmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utransmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TC, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCmybr1Nmybr2, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCmybr1Hmybr2, TREASURE);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_superuniques(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_SUPERUNIQUE_109) )
    {
        return process_superuniques109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            SuperUniques_InitValueMap(pstValueMap, pstLineInfo);

            m_iSuperUniquesCount = 0;
            Lookup_SuperUnique = SuperUniques_GetItemUniqueCode;

            m_stCallback.pfnConvertValue = SuperUniques_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monsounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            SuperUniques_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


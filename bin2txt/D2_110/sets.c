#include "../global.h"

#define FILE_PREFIX "Sets"
#define NAME_PREFIX "se"


typedef struct
{
    unsigned short vindex;
    unsigned short vname;   //strings

    unsigned short vversion;
    unsigned char pad0x06[10];

    unsigned int vPCode2a;   //properties
    int vPParam2a;  //skills
    int vPMin2a;
    int vPMax2a;

    unsigned int vPCode2b;   //properties
    int vPParam2b;  //skills
    int vPMin2b;
    int vPMax2b;

    unsigned int vPCode3a;   //properties
    int vPParam3a;  //skills
    int vPMin3a;
    int vPMax3a;

    unsigned int vPCode3b;   //properties
    int vPParam3b;  //skills
    int vPMin3b;
    int vPMax3b;

    unsigned int vPCode4a;   //properties
    int vPParam4a;  //skills
    int vPMin4a;
    int vPMax4a;

    unsigned int vPCode4b;   //properties
    int vPParam4b;  //skills
    int vPMin4b;
    int vPMax4b;

    unsigned int vPCode5a;   //properties
    int vPParam5a;  //skills
    int vPMin5a;
    int vPMax5a;

    unsigned int vPCode5b;   //properties
    int vPParam5b;  //skills
    int vPMin5b;
    int vPMax5b;

    unsigned int vFCode1;    //properties
    int vFParam1;
    int vFMin1;
    int vFMax1;

    unsigned int vFCode2;    //properties
    int vFParam2;
    int vFMin2;
    int vFMax2;

    unsigned int vFCode3;    //properties
    int vFParam3;
    int vFMin3;
    int vFMax3;

    unsigned int vFCode4;    //properties
    int vFParam4;
    int vFMin4;
    int vFMax4;

    unsigned int vFCode5;    //properties
    int vFParam5;
    int vFMin5;
    int vFMax5;

    unsigned int vFCode6;    //properties
    int vFParam6;
    int vFMin6;
    int vFMax6;

    unsigned int vFCode7;    //properties
    int vFParam7;
    int vFMin7;
    int vFMax7;

    unsigned int vFCode8;    //properties
    int vFParam8;
    int vFMin8;
    int vFMax8;

    unsigned char pad0x110[24];    //D2SetItemsTxt* pSetItem1
} ST_LINE_INFO;

typedef struct
{
    int vPCode2a;   //properties
    int vPParam2a;  //skills
    int vPMin2a;
    int vPMax2a;
} ST_SET_CODE;

static char *m_apcNotUsed[] =
{
    "level",
    NULL,
};

typedef struct
{
    unsigned char vindex[64];
} ST_SET_INDEX;

static unsigned int m_iSetCount = 0;
static unsigned int m_iSetHaveEmpty = 0;
static ST_SET_INDEX *m_astSets = NULL;

MODULE_SETLINES_FUNC(m_astSets, ST_SET_INDEX);
MODULE_HAVENAME_FUNC(m_astSets, vindex, m_iSetCount);

static char *Sets_GetSetName(unsigned int id)
{
    if ( id < m_iSetCount )
    {
        return m_astSets[id].vindex;
    }

    if ( id == -1 && m_iSetHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Sets_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "index") )
    {
        if ( !String_BuildName(FORMAT(sets), pstLineInfo->vname, pcTemplate, NULL, pstLineInfo->vindex, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vindex);
        }

        strncpy(m_astSets[pstLineInfo->vindex].vindex, acOutput, sizeof(m_astSets[pstLineInfo->vindex].vindex));
        String_Trim(m_astSets[pstLineInfo->vindex].vindex);
        m_iSetHaveEmpty |= !m_astSets[pstLineInfo->vindex].vindex[0];

        m_iSetCount++;
        return 1;
    }

    return 0;
}

static int Sets_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;

    if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PParam%da", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2a;

        if ( pcResult = Lookup_Property(pstSetItem[(id - 2) * 2].vPCode2a) )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[(id - 2) * 2].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                if ( pcResult = Lookup_State(pstSetItem[(id - 2) * 2].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
            }
        }

        return 1;
    }
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PParam%db", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2b;

        if ( pcResult = Lookup_Property(pstSetItem[(id - 2) * 2].vPCode2a) )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[(id - 2) * 2].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                if ( pcResult = Lookup_State(pstSetItem[(id - 2) * 2].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
            }
        }

        return 1;
    }
    else if ( strlen("FParam1") == strlen(acKey) && 1 == sscanf(acKey, "FParam%d", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vFCode1;

        if ( pcResult = Lookup_Property(pstSetItem[id - 1].vPCode2a) )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[id - 1].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                if ( pcResult = Lookup_State(pstSetItem[id - 1].vPParam2a) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
            }
        }

        return 1;
    }

    return 0;
}

static void Sets_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, index, SET);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode2a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam2a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax2a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode2b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam2b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax2b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode3a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam3a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax3a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode3b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam3b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax3b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode4a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam4a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax4a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode4b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam4b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax4b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode5a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam5a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax5a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode5b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam5b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax5b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode7, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode8, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax8, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_sets(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            Sets_InitValueMap(pstValueMap, pstLineInfo);

            m_iSetCount = 0;
            Lookup_Set = Sets_GetSetName;

            m_stCallback.pfnConvertValue = Sets_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Sets_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Sets_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


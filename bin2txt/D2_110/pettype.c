#include "../global.h"

#define FILE_PREFIX "PetType"
#define NAME_PREFIX "pt"


typedef struct
{
    unsigned int vpetmysptype;

#if 1
    unsigned char vCombinedBit;
#else
    unsigned char bPad6 : 2;
    unsigned char vdrawhp : 1;
    unsigned char vautomap : 1;

    unsigned char vunsummon : 1;
    unsigned char vpartysend : 1;
    unsigned char vrange : 1;
    unsigned char vwarp : 1;
#endif

    unsigned char pad0x05[3];

    unsigned short vgroup;
    unsigned short vbasemax;

    unsigned short vname;   //string
    unsigned char vicontype;
    unsigned char vbaseicon[32];
    unsigned char vmicon1[32];
    unsigned char vmicon2[32];
    unsigned char vmicon3[32];
    unsigned char vmicon4[32];
    unsigned char pad0x90;

    unsigned char pad0x91[2];
    unsigned short vmclass1;

    unsigned short vmclass2;
    unsigned short vmclass3;

    unsigned short vmclass4;
    unsigned char pad0xBA[2];

    unsigned char pad0xBC[36];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vpetmysptype[64];
} ST_PETTYPE;

static char *m_apcInternalProcess[] =
{
    "idx",
    NULL,
};

static unsigned int m_iPetTypeCount = 0;
static unsigned int m_iPetTypeHaveEmpty = 0;
static ST_PETTYPE *m_astPetTypes = NULL;

MODULE_SETLINES_FUNC(m_astPetTypes, ST_PETTYPE);
MODULE_HAVENAME_FUNC(m_astPetTypes, vpetmysptype, m_iPetTypeCount);

static char *Pettype_GetPetType(unsigned int id)
{
    if ( id < m_iPetTypeCount )
    {
        return m_astPetTypes[id].vpetmysptype;
    }

    if ( id == -1 && m_iPetTypeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int PetType_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "pet type") )
    {
        char acName[33] = {0};
        strncpy(acName, pstLineInfo->vbaseicon, sizeof(pstLineInfo->vbaseicon));

        if ( !String_BuildName(FORMAT(pettype), pstLineInfo->vname, pcTemplate, acName, pstLineInfo->vpetmysptype, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vpetmysptype);
        }

        strncpy(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype, acOutput, sizeof(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype));
        String_Trim(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype);
        m_iPetTypeHaveEmpty |= !m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype[0];

        m_iPetTypeCount++;
        return 1;
    }

    return 0;
}

static int PetType_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "idx") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vpetmysptype);

        return 1;
    }
    else if ( isD2SigmaActive() && PetTypeExt_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static char *PetType_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    sprintf(pcKey, "%u", pstLineInfo->vpetmysptype);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static void PetType_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, petmysptype, PET);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, drawhp, CombinedBit, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, automap, CombinedBit, 4, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, unsummon, CombinedBit, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, partysend, CombinedBit, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, range, CombinedBit, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, warp, CombinedBit, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, basemax, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, icontype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseicon, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass4, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);
}

int process_pettype(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(PetTypeExt, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            PetType_InitValueMap(pstValueMap, pstLineInfo);

            m_iPetTypeCount = 0;
            Lookup_Pet = Pettype_GetPetType;

            m_stCallback.pfnConvertValue = PetType_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            //m_stCallback.pfnGetKey = PetType_GetKey;
            m_stCallback.pfnFieldProc = PetType_FieldProc;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? PetTypeExt_ExternList : m_apcInternalProcess;

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


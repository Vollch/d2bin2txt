#include "../global.h"

#define FILE_PREFIX "objects3"
#define NAME_PREFIX "ot"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned int vObjectID;
    unsigned char vMonFN;
    unsigned int vMonID1;
    unsigned int vMonID2;
    unsigned int vMonID3;
    int vMonSpawnChance;
    unsigned int vTreasureClass; // treasure
    int viLvl;
    unsigned char vpicks;
    int vdropChance;
    int vmagic1;
    int vmagic2;
    int vrare;
    int vset;
    int vunique;
    unsigned char vitemCode1[4];
    unsigned char vitemCode2[4];
    unsigned char vitemCode3[4];
    int vnoDrop;
    unsigned char vSparkle;
    unsigned short vstringKey; // string
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int objects3_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(objects3), 0xFFFF, pcTemplate, Lookup_Object(pstLineInfo->vObjectID), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_objects3(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjectID, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonFN, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonID1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonID2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonID3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSpawnChance, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass, TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, iLvl, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, picks, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropChance, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, magic1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, magic2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rare, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, unique, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemCode1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemCode2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemCode3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, noDrop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sparkle, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stringKey, TBL_STRING);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(objects, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = objects3_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "SetItems"


typedef struct
{
    unsigned char pad0x00[2];
    unsigned char vindex[32];
    unsigned char pad0x22[6];

    unsigned char vitem[4];

    unsigned short vset; //sets.txt
    unsigned char pad0x2E[2];

    unsigned short vlvl;
    unsigned short vlvlmyspreq;

    unsigned int vrarity;

    unsigned int vcostmyspmult;
    unsigned int vcostmyspadd;

    unsigned char vchrtransform; //color
    unsigned char vinvtransform; //color
    unsigned char vflippyfile[32];

    unsigned char vinvfile[32];

    unsigned short vdropsound; //sounds

    unsigned short vusesound; //sounds
    unsigned char vdropsfxframe;
    unsigned char vaddmyspfunc;

    unsigned int vprop1; //properties
    int vpar1;
    int vmin1;
    int vmax1;

    unsigned int vprop2; //properties
    int vpar2;
    int vmin2;
    int vmax2;

    unsigned int vprop3; //properties
    int vpar3;
    int vmin3;
    int vmax3;

    unsigned int vprop4; //properties
    int vpar4;
    int vmin4;
    int vmax4;

    unsigned int vprop5; //properties
    int vpar5;
    int vmin5;
    int vmax5;

    unsigned int vprop6; //properties
    int vpar6;
    int vmin6;
    int vmax6;

    unsigned int vprop7; //properties
    int vpar7;
    int vmin7;
    int vmax7;

    unsigned int vprop8; //properties
    int vpar8;
    int vmin8;
    int vmax8;

    unsigned int vprop9; //properties
    int vpar9;
    int vmin9;
    int vmax9;

    unsigned int vaprop1a; //properties
    int vapar1a;
    int vamin1a;
    int vamax1a;
    unsigned int vaprop1b; //properties
    int vapar1b;
    int vamin1b;
    int vamax1b;

    unsigned int vaprop2a; //properties
    int vapar2a;
    int vamin2a;
    int vamax2a;
    unsigned int vaprop2b; //properties
    int vapar2b;
    int vamin2b;
    int vamax2b;

    unsigned int vaprop3a; //properties
    int vapar3a;
    int vamin3a;
    int vamax3a;

    unsigned int vaprop3b; //properties
    int vapar3b;
    int vamin3b;
    int vamax3b;

    unsigned int vaprop4a; //properties
    int vapar4a;
    int vamin4a;
    int vamax4a;

    unsigned int vaprop4b; //properties
    int vapar4b;
    int vamin4b;
    int vamax4b;

    unsigned int vaprop5a; //properties
    int vapar5a;
    int vamin5a;
    int vamax5a;

    unsigned int vaprop5b; //properties
    int vapar5b;
    int vamin5b;
    int vamax5b;
} ST_LINE_INFO;

typedef struct
{
    int vprop1; //properties
    int vpar1;
    int vmin1;
    int vmax1;
} ST_SETITEM;

typedef struct
{
    unsigned char vindex[32];
} ST_SETITEMS;

static char *m_apcInternalProcess[] =
{
    "*item",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_uiSetItemCount = 0;
static ST_SETITEMS *m_astSetItems = NULL;

MODULE_SETLINES_FUNC(m_astSetItems, ST_SETITEMS);

static char *SetItems_GetItemUniqueCode(unsigned int id)
{
    if ( id - 1 < m_uiSetItemCount )
    {
        return m_astSetItems[id - 1].vindex;
    }

    return NULL;
}

static int SetItems_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*item") )
    {
        char acCode[5] = {0};
        unsigned int uiString = 0xFFFF;
        ST_BT_NODE *sItem;

        strncpy(acCode, pstLineInfo->vitem, sizeof(pstLineInfo->vitem));
        String_Trim(acCode);

        if ( sItem = Tree_Search(Map_Items, acCode) )
        {
            uiString = Lookup_ItemString(sItem->uiId);
        }

        if ( !String_BuildName(FORMAT(setitems), uiString, pcTemplate, acCode, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vitem, sizeof(pstLineInfo->vitem));
        }

        return 1;
    }

    return 0;
}

static int SetItems_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "index") )
    {
        strncpy(m_astSetItems[m_uiSetItemCount].vindex, pstLineInfo->vindex, sizeof(m_astSetItems[m_uiSetItemCount].vindex));

        m_uiSetItemCount++;
    }

    return 0;
}

static int SetItems_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;

    if ( strlen("par1") == strlen(acKey) && 1 == sscanf(acKey, "par%d", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vprop1;

        if ( pcResult = Lookup_Property(pstSetItem[id - 1].vprop1) )
        {
            if ( !strcmp("skill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[id - 1].vpar1) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[id - 1].vpar1);
            }
        }

        return 1;
    }
    else if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "apar%da", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1a;

        if ( pcResult = Lookup_Property(pstSetItem[(id - 1) * 2].vprop1) )
        {
            if ( !strcmp("skill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[(id - 1) * 2].vpar1) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
            }
        }

        return 1;
    }
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "apar%db", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1b;

        if ( pcResult = Lookup_Property(pstSetItem[(id - 1) * 2].vprop1) )
        {
            if ( !strcmp("skill", pcResult) )
            {
                if ( pcResult = Lookup_Skill(pstSetItem[(id - 1) * 2].vpar1) )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
            }
        }

        return 1;
    }

    return 0;
}

static void SetItems_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, index, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set, SET);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmyspreq, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chrtransform, COLOR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invtransform, COLOR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, addmyspfunc, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop7, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop8, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max8, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop9, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max9, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop1a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar1a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin1a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax1a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop1b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar1b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin1b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax1b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop2a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax2a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop2b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax2b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop3a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax3a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop3b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax3b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop4a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax4a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop4b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax4b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop5a, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax5a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop5b, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax5b, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_setitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_SETITEMS_109) )
    {
        return process_setitems109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            SetItems_InitValueMap(pstValueMap, pstLineInfo);
            m_uiSetItemCount = 0;
            Lookup_SetItem = SetItems_GetItemUniqueCode;

            m_stCallback.pfnConvertValue = SetItems_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(sets, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            SetItems_InitValueMap(pstValueMap, pstLineInfo);
            m_stCallback.pfnConvertValue = SetItems_ConvertValue;
            m_stCallback.pfnFieldProc = SetItems_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;

}


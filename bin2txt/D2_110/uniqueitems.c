#include "../global.h"

#define FILE_PREFIX "UniqueItems"


typedef struct
{
    unsigned char pad0x00[2];
    unsigned char vindex[32];

    unsigned char pad0x22[2];
    unsigned int vversion;

    unsigned char vcode[4];

#if 1
    unsigned char vBitCombined;
#else
    //01
    unsigned char bPad4 : 4;

    unsigned char vladder : 1;
    unsigned char vcarry1 : 1;
    unsigned char vnolimit : 1;
    unsigned char venabled : 1;
#endif

    unsigned char pad0x2D[3];

    unsigned short vrarity;
    unsigned char pad0x32[2];

    unsigned short vlvl;
    unsigned short vlvlmyspreq;

    unsigned char vchrtransform;    //colors
    unsigned char vinvtransform;    //colors
    unsigned char vflippyfile[32];

    unsigned char vinvfile[32];

    unsigned char pad0x7A[2];

    unsigned int vcostmyspmult;

    unsigned int vcostmyspadd;

    unsigned short vdropsound;  //sounds
    unsigned short vusesound;   //sounds

    unsigned int vdropsfxframe;

    unsigned int vprop1;    //properties
    int vpar1;
    int vmin1;
    int vmax1;

    unsigned int vprop2;    //properties
    int vpar2;
    int vmin2;
    int vmax2;

    unsigned int vprop3;    //properties
    int vpar3;
    int vmin3;
    int vmax3;

    unsigned int vprop4;    //properties
    int vpar4;
    int vmin4;
    int vmax4;

    unsigned int vprop5;    //properties
    int vpar5;
    int vmin5;
    int vmax5;

    unsigned int vprop6;    //properties
    int vpar6;
    int vmin6;
    int vmax6;

    unsigned int vprop7;    //properties
    int vpar7;
    int vmin7;
    int vmax7;

    unsigned int vprop8;    //properties
    int vpar8;
    int vmin8;
    int vmax8;

    unsigned int vprop9;    //properties
    int vpar9;
    int vmin9;
    int vmax9;

    unsigned int vprop10;    //properties
    int vpar10;
    int vmin10;
    int vmax10;

    unsigned int vprop11;    //properties
    int vpar11;
    int vmin11;
    int vmax11;

    unsigned int vprop12;    //properties
    int vpar12;
    int vmin12;
    int vmax12;
} ST_LINE_INFO;

typedef struct
{
    int vprop1;    //properties
    int vpar1;
    int vmin1;
    int vmax1;
} ST_UNIQUEITEM;

typedef struct
{
    unsigned char vindex[32];
} ST_SEARCHITEMS;

static char *m_apcNotUsed[] =
{
    "*type",
    "*uber",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_uiUniqueItemCount = 0;
static ST_SEARCHITEMS *m_astUniqueItems = NULL;

MODULE_SETLINES_FUNC(m_astUniqueItems, ST_SEARCHITEMS);

static char *UniqueItems_GetItemUniqueCode(unsigned int id)
{
    if ( id - 1 < m_uiUniqueItemCount )
    {
        return m_astUniqueItems[id - 1].vindex;
    }

    return NULL;
}

static int UniqueItems_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "index") )
    {
        strncpy(m_astUniqueItems[m_uiUniqueItemCount].vindex, pstLineInfo->vindex, sizeof(m_astUniqueItems[m_uiUniqueItemCount].vindex));
        String_Trim(m_astUniqueItems[m_uiUniqueItemCount].vindex);

        m_uiUniqueItemCount++;
    }

    return 0;
}

static void UniqueItems_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, index, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);

    if ( isD2SigmaActive() ) {
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, nosocket, BitCombined, 4, UCHAR_BIT);
    }

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ladder, BitCombined, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, carry1, BitCombined, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, nolimit, BitCombined, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, enabled, BitCombined, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmyspreq, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chrtransform, COLOR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invtransform, COLOR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UINT);

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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop10, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par10, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min10, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max10, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop11, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par11, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min11, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max11, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop12, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par12, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min12, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max12, INT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_uniqueitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_UNIQUEITEMS_109) )
    {
        return process_uniqueitems109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(UniqueItems2, acTemplatePath, acBinPath, acTxtPath);
            UniqueItems_InitValueMap(pstValueMap, pstLineInfo);
            m_uiUniqueItemCount = 0;
            Lookup_UniqueItem = UniqueItems_GetItemUniqueCode;

            m_stCallback.pfnConvertValue = UniqueItems_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            if ( isD2SigmaActive() )
            {
                m_stCallback.ppcKeyInternalProcess = UniqueItems2_ExternList;
            }

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            UniqueItems_InitValueMap(pstValueMap, pstLineInfo);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            if ( isD2SigmaActive() )
            {
                m_stCallback.pfnFieldProc = UniqueItems2_ExternProc;
                m_stCallback.ppcKeyInternalProcess = UniqueItems2_ExternList;
            }

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


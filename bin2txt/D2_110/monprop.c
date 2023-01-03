#include "../global.h"

#define FILE_PREFIX "MonProp"
#define NAME_PREFIX "mp"

typedef struct
{
    unsigned int vId;   //monstats

    unsigned int vprop1;    //properties
    unsigned int vpar1;
    int vmin1;
    int vmax1;

    unsigned int vprop2;    //properties
    unsigned int vpar2;
    int vmin2;
    int vmax2;

    unsigned int vprop3;    //properties
    unsigned int vpar3;
    int vmin3;
    int vmax3;

    unsigned int vprop4;    //properties
    unsigned int vpar4;
    int vmin4;
    int vmax4;

    unsigned int vprop5;    //properties
    unsigned int vpar5;
    int vmin5;
    int vmax5;

    unsigned int vprop6;    //properties
    unsigned int vpar6;
    int vmin6;
    int vmax6;

    unsigned int vprop1myspmybr1Nmybr2;    //properties
    unsigned int vpar1myspmybr1Nmybr2;
    int vmin1myspmybr1Nmybr2;
    int vmax1myspmybr1Nmybr2;

    unsigned int vprop2myspmybr1Nmybr2;    //properties
    unsigned int vpar2myspmybr1Nmybr2;
    int vmin2myspmybr1Nmybr2;
    int vmax2myspmybr1Nmybr2;

    unsigned int vprop3myspmybr1Nmybr2;    //properties
    unsigned int vpar3myspmybr1Nmybr2;
    int vmin3myspmybr1Nmybr2;
    int vmax3myspmybr1Nmybr2;

    unsigned int vprop4myspmybr1Nmybr2;    //properties
    unsigned int vpar4myspmybr1Nmybr2;
    int vmin4myspmybr1Nmybr2;
    int vmax4myspmybr1Nmybr2;

    unsigned int vprop5myspmybr1Nmybr2;    //properties
    unsigned int vpar5myspmybr1Nmybr2;
    int vmin5myspmybr1Nmybr2;
    int vmax5myspmybr1Nmybr2;

    unsigned int vprop6myspmybr1Nmybr2;    //properties
    unsigned int vpar6myspmybr1Nmybr2;
    int vmin6myspmybr1Nmybr2;
    int vmax6myspmybr1Nmybr2;

    unsigned int vprop1myspmybr1Hmybr2;    //properties
    unsigned int vpar1myspmybr1Hmybr2;
    int vmin1myspmybr1Hmybr2;
    int vmax1myspmybr1Hmybr2;

    unsigned int vprop2myspmybr1Hmybr2;    //properties
    unsigned int vpar2myspmybr1Hmybr2;
    int vmin2myspmybr1Hmybr2;
    int vmax2myspmybr1Hmybr2;

    unsigned int vprop3myspmybr1Hmybr2;    //properties
    unsigned int vpar3myspmybr1Hmybr2;
    int vmin3myspmybr1Hmybr2;
    int vmax3myspmybr1Hmybr2;

    unsigned int vprop4myspmybr1Hmybr2;    //properties
    unsigned int vpar4myspmybr1Hmybr2;
    int vmin4myspmybr1Hmybr2;
    int vmax4myspmybr1Hmybr2;

    unsigned int vprop5myspmybr1Hmybr2;    //properties
    unsigned int vpar5myspmybr1Hmybr2;
    int vmin5myspmybr1Hmybr2;
    int vmax5myspmybr1Hmybr2;

    unsigned int vprop6myspmybr1Hmybr2;    //properties
    unsigned int vpar6myspmybr1Hmybr2;
    int vmin6myspmybr1Hmybr2;
    int vmax6myspmybr1Hmybr2;

    unsigned char vchance1;
    unsigned char vchance2;
    unsigned char vchance3;
    unsigned char vchance4;

    unsigned char vchance5;
    unsigned char vchance6;
    unsigned char vchance1myspmybr1Nmybr2;
    unsigned char vchance2myspmybr1Nmybr2;

    unsigned char vchance3myspmybr1Nmybr2;
    unsigned char vchance4myspmybr1Nmybr2;
    unsigned char vchance5myspmybr1Nmybr2;
    unsigned char vchance6myspmybr1Nmybr2;

    unsigned char vchance1myspmybr1Hmybr2;
    unsigned char vchance2myspmybr1Hmybr2;
    unsigned char vchance3myspmybr1Hmybr2;
    unsigned char vchance4myspmybr1Hmybr2;

    unsigned char vchance5myspmybr1Hmybr2;
    unsigned char vchance6myspmybr1Hmybr2;
    unsigned char pad0x136[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned int vprop1;    //properties
    unsigned int vpar1;
    int vmin1;
    int vmax1;
} ST_PROP;

typedef struct
{
    unsigned char vId[64];
    unsigned short sString;
} ST_MON_PROP;

static unsigned int m_iMonPropCount = 0;
static unsigned int m_iMonPropHaveEmpty = 0;
static ST_MON_PROP *m_astMonProp = NULL;

MODULE_SETLINES_FUNC(m_astMonProp, ST_MON_PROP);
MODULE_HAVENAME_FUNC(m_astMonProp, vId, m_iMonPropCount);

static void SetLines_Pre(unsigned int uiLines)
{
    SETLINES_FUNC_NAME(uiLines);
    MonStats_LinkMonProp(m_astMonProp, uiLines, sizeof(ST_MON_PROP), offsetof(ST_MON_PROP, sString));
}

static char *MonProp_GetPropId(unsigned int id)
{
    if ( id < m_iMonPropCount )
    {
        return m_astMonProp[id].vId;
    }

    if ( id == -1 && m_iMonPropHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonProp_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        if ( !String_BuildName(FORMAT(monprop), m_astMonProp[pstLineInfo->vId].sString, pcTemplate, NULL, m_iMonPropCount, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vId);
        }

        strncpy(m_astMonProp[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonProp[pstLineInfo->vId].vId));
        String_Trim(m_astMonProp[pstLineInfo->vId].vId);
        m_iMonPropHaveEmpty |= !m_astMonProp[pstLineInfo->vId].vId[0];

        m_iMonPropCount++;
        return 1;
    }

    return 0;
}

static int MonProp_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        strncpy(acOutput, m_astMonProp[pstLineInfo->vId].vId, sizeof(m_astMonProp[pstLineInfo->vId].vId));

        return 1;
    }

    return 0;
}

static void MonProp_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6myspmybr1Nmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6myspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6myspmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6myspmybr1Nmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6myspmybr1Hmybr2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6myspmybr1Hmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6myspmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6myspmybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2myspmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5myspmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6myspmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance1myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance2myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance3myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance4myspmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance5myspmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chance6myspmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_monprop(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            MonProp_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonPropCount = 0;
            Lookup_MonProp = MonProp_GetPropId;

            m_stCallback.pfnConvertValue = MonProp_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SetLines_Pre;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonProp_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = MonProp_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

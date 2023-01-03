#include "../global.h"

#define FILE_PREFIX "ItemTypes"

typedef struct
{
    char vCode[5];
} ST_ITEM_TYPES;

static char *m_apcInternalProcess[] =
{
    "ItemType",
    NULL,
};

static unsigned int m_iItemTypesCount = 0;
static unsigned int m_iItemTypesHaveEmpty = 0;
static ST_ITEM_TYPES *m_astItemTypes = NULL;

MODULE_SETLINES_FUNC(m_astItemTypes, ST_ITEM_TYPES);

static char *ItemTypes_GetItemCode(unsigned int id)
{
    if ( id < m_iItemTypesCount )
    {
        return m_astItemTypes[id].vCode;
    }

    if ( id == -1 && m_iItemTypesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int ItemTypes_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_ITEMTYPES_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "code") )
    {
        strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        strncpy(m_astItemTypes[m_iItemTypesCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astItemTypes[m_iItemTypesCount].vCode);
        m_iItemTypesHaveEmpty |= !m_astItemTypes[m_iItemTypesCount].vCode[0];

        m_iItemTypesCount++;
        return 1;
    }
    else if ( !stricmp(acKey, "TreasureClass") )
    {
        if ( 0 != pstLineInfo->vTreasureClass )
        {
            g_iTreasureClassOffset += 30;
        }
    }

    return 0;
}

static int ItemTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_ITEMTYPES_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "ItemType") )
    {
        char acName[5] = {0};
        strncpy(acName, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));

        if ( !String_BuildName(FORMAT(itemtypes), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        return 1;
    }

    return 0;
}

static char *ItemTypes_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_ITEMTYPES_109 *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static void ItemTypes_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_ITEMTYPES_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv2, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Repair, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Body, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc1, BODYLOC);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc2, BODYLOC);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shoots, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quiver, ITEMTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Throwable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Reload, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReEquip, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoStack, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Charm, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beltable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock25, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock40, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaffMods, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostFormula, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StorePage, STORE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VarInvGfx, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx6, STRING);
}

int process_itemtypes109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_ITEMTYPES_109 *pstLineInfo = (ST_ITEMTYPES_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            ItemTypes_InitValueMap(pstValueMap, pstLineInfo);

            m_iItemTypesCount = 0;
            Lookup_ItemType = ItemTypes_GetItemCode;

            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnConvertValue = ItemTypes_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            g_iTreasureClassOffset = 1;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(storepage, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            ItemTypes_InitValueMap(pstValueMap, pstLineInfo);
            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnFieldProc = ItemTypes_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


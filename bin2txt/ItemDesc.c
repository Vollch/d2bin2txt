#include "global.h"

#define FILE_PREFIX "ItemDesc"
#define NAME_PREFIX "id"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vItemType;
    unsigned int vItemDesc;
    unsigned char vWeaponLine;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Name",
    NULL,
};

static int ItemDesc_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Name") )
    {
        if ( !String_BuildName(FORMAT(ItemDesc), pstLineInfo->vItemDesc, pcTemplate, ItemTypes_GetItemCode(pstLineInfo->vItemType), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_ItemDesc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemType, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ItemDesc, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WeaponLine, UCHAR);

    VALUE_MAP_DEFINE_3(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = ItemDesc_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


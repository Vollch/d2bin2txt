#include "../global.h"

#define FILE_PREFIX "CubeMain"
#define NAME_PREFIX "cm"

static char *m_apcInternalProcess[] =
{
    "description",
    NULL,
};

static int Cubemain_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_CUBEMAIN_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp("description", acKey) )
    {
        char *pcName = NULL;
        ST_BT_NODE *sItem;

        if ( strlen(pstLineInfo->voutput) == 3 && (sItem = Tree_Search(Map_Items, pstLineInfo->voutput)) )
        {
            pcName = Lookup_ItemName(sItem->uiId);
        }

        if ( !String_BuildName(FORMAT(cubemain), 0xFFFF, pcTemplate, pcName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

static void Cubemain_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_CUBEMAIN_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmyspdiff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, startmyspday, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stopmyspday, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weekday, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, numinputs, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, output, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, plvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ilvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspchance, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspchance, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspchance, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspchance, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmin, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmax, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspchance, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, term, EOL);
}

int process_cubemain109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_CUBEMAIN_109 *pstLineInfo = (ST_CUBEMAIN_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            Cubemain_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Cubemain_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


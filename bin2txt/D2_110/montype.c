#include "../global.h"

#define FILE_PREFIX "MonType"
#define NAME_PREFIX "mt"

typedef struct
{
    unsigned short vtype;
    unsigned short vequiv1;

    unsigned short vequiv2;
    unsigned short vequiv3;

    unsigned short vstrsing;
    unsigned short vstrplur;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vtype[64];
} ST_MONTYPE;

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iMonTypeCount = 0;
static unsigned int m_iMonTypeHaveEmpty = 0;
static ST_MONTYPE *m_astMonType = NULL;

MODULE_SETLINES_FUNC(m_astMonType, ST_MONTYPE);
MODULE_HAVENAME_FUNC(m_astMonType, vtype, m_iMonTypeCount);

static char *MonType_GetType(unsigned int id)
{
    if ( id < m_iMonTypeCount )
    {
        return m_astMonType[id].vtype;
    }

    if ( id == -1 && m_iMonTypeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonType_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "type") )
    {
        char *pcName = String_FindString(pstLineInfo->vstrplur, "dummy", NULL);
        if ( !String_BuildName(FORMAT(montype), pstLineInfo->vstrsing, pcTemplate, pcName, pstLineInfo->vtype, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vtype);
        }

        strncpy(m_astMonType[pstLineInfo->vtype].vtype, acOutput, sizeof(m_astMonType[pstLineInfo->vtype].vtype));
        String_Trim(m_astMonType[pstLineInfo->vtype].vtype);
        m_iMonTypeHaveEmpty |= !m_astMonType[pstLineInfo->vtype].vtype[0];

        m_iMonTypeCount++;
        return 1;
    }

    return 0;
}

static void MonType_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv1, MONTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv2, MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv3, MONTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strsing, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strplur, TBL_STRING);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_montype(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_MONTYPE_109) )
    {
        return process_montype109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MonType_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonTypeCount = 0;
            Lookup_MonType = MonType_GetType;

            m_stCallback.pfnConvertValue = MonType_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            ( File_CopyFile(acBinPath, acTxtPath, "MonName", ".txt") ||
              File_CopyFile(acTemplatePath, acTxtPath, "MonName", ".txt") );
            break;

        case EN_MODULE_INIT:
            MonType_InitValueMap(pstValueMap, pstLineInfo);
            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


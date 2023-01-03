#include "../global.h"

#define FILE_PREFIX "MonType"

static void MonType_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_MONTYPE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Token, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DT_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NU_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WL_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GH_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BL_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SC_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DD_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KB_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SQ_Dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RN_Dir, UCHAR);
}

int process_montype109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_MONTYPE_109 *pstLineInfo = (ST_MONTYPE_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
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


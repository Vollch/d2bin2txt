#include "../global.h"

static char *m_apcNotUsed[] =
{
    "Namco",
    NULL,
};

static void Unique_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_UNIQUE_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType8, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType9, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType10, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType11, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType12, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType13, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType14, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType15, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType16, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType17, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType18, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType19, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType20, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType21, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType22, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType23, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType24, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType25, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType26, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType27, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType28, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType29, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType30, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType31, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType32, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType33, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType34, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType35, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType36, UCHAR);
}

int process_unique109(char* pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_UNIQUE_109 *pstLineInfo = (ST_UNIQUE_109 *)m_acLineInfoBuf;
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
            Unique_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, pcFilename, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "global.h"

#define FILE_PREFIX "D2RedPortal"
#define NAME_PREFIX "rp"

typedef struct
{
    unsigned int vsrcLvl;
    unsigned int vdestLvl;
    unsigned int vobject;

    unsigned short vop1;
    unsigned short vstat1;
    int vparam1;
    int vvalue1;

    unsigned short vop2;
    unsigned short vstat2;
    int vparam2;
    int vvalue2;

    unsigned short vop3;
    unsigned short vstat3;
    int vparam3;
    int vvalue3;

    unsigned short vop4;
    unsigned short vstat4;
    int vparam4;
    int vvalue4;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "*eol",
    NULL,
};

static int D2RedPortal_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

int process_D2RedPortal(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srcLvl, UINT_ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, destLvl, UINT_ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, object, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value1, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value2, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value3, UINT_ITEMCODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value4, UINT_ITEMCODE);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            return ItemsCode_ParseBin(acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.iOptional = 1;
            m_stCallback.pfnFieldProc = D2RedPortal_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


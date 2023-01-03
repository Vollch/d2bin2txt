#include "../global.h"

#define FILE_PREFIX "MonUMod"
#define NAME_PREFIX "mu"


typedef struct
{
    unsigned short vuniquemod;
    unsigned char pad0x02[2];

    unsigned short vversion;
    unsigned char venabled;
    unsigned char vxfer;

    unsigned char vchampion;
    unsigned char vfPick;
    unsigned short vexclude1;   //MonType

    unsigned short vexclude2;   //MonType
    unsigned short vcpick;

    unsigned short vcpickmyspmybr1Nmybr2;
    unsigned short vcpickmyspmybr1Hmybr2;

    unsigned short vupick;
    unsigned short vupickmyspmybr1Nmybr2;

    unsigned short vupickmyspmybr1Hmybr2;
    unsigned char pad0x1A[2];

    unsigned int vconstants;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "id",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "fInit",
    "*constant desc",
    NULL,
};

static int MonUMOD_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "uniquemod") )
    {
        if ( !String_BuildName(FORMAT(monumod), 0xFFFF, pcTemplate, NULL, pstLineInfo->vuniquemod, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vuniquemod);
        }

        return 1;
    }

    return 0;
}

static int MonUMOD_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "id") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vuniquemod);

        return 1;
    }
    else if ( isD2SigmaActive() && MonUModExp_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

int process_monumod(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniquemod, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, xfer, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, champion, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, fPick, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, exclude1, MONTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, exclude2, MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpick, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpickmyspmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpickmyspmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upick, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upickmyspmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upickmyspmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, constants, UINT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(montype, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(MonUModExp, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = MonUMOD_ConvertValue;
            m_stCallback.pfnFieldProc = MonUMOD_FieldProc;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? MonUModExp_ExternList : m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


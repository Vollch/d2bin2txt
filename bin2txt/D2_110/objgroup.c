#include "../global.h"

#define FILE_PREFIX "ObjGroup"
#define NAME_PREFIX "og"


typedef struct
{
    unsigned int vID0;
    unsigned int vID1;
    unsigned int vID2;
    unsigned int vID3;
    unsigned int vID4;
    unsigned int vID5;
    unsigned int vID6;
    unsigned int vID7;

    unsigned char vDENSITY0;
    unsigned char vDENSITY1;
    unsigned char vDENSITY2;
    unsigned char vDENSITY3;

    unsigned char vDENSITY4;
    unsigned char vDENSITY5;
    unsigned char vDENSITY6;
    unsigned char vDENSITY7;

    unsigned char vPROB0;
    unsigned char vPROB1;
    unsigned char vPROB2;
    unsigned char vPROB3;

    unsigned char vPROB4;
    unsigned char vPROB5;
    unsigned char vPROB6;
    unsigned char vPROB7;

    unsigned char vSHRINES;
    unsigned char vWELLS;
    unsigned char pad0x32[2];
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "GroupName",
    "Offset",
    NULL,
};

static unsigned int m_iObjGroupCount = 0;

static int ObjGroup_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Offset") )
    {
        sprintf(acOutput, "%u", m_iObjGroupCount);

        m_iObjGroupCount++;
        return 1;
    }
    else if ( !stricmp(acKey, "GroupName") )
    {
        char acObjects[513] = {0};
        unsigned int* piObjects[] = { &pstLineInfo->vID0, &pstLineInfo->vID1, &pstLineInfo->vID2, &pstLineInfo->vID3,
                                      &pstLineInfo->vID4, &pstLineInfo->vID5, &pstLineInfo->vID6, &pstLineInfo->vID7 };
        int i;
        for ( i = 0; i < 8; i++ )
        {
            char *pcName = Lookup_Object(*piObjects[i]);
            if ( pcName && stricmp(pcName, "dummy") )
            {
                strncpy(acObjects + strlen(acObjects), pcName, 64);
            }
        }

        if ( !String_BuildName(FORMAT(objgroup), 0xFFFF, pcTemplate, acObjects, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_objgroup(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID0, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID7, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DENSITY7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PROB7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SHRINES, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WELLS, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(objects, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = ObjGroup_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "global.h"

#define FILE_PREFIX "lvltypes"
#define NAME_PREFIX "lt"

typedef struct
{
    unsigned char vFilemysp1[60];
    unsigned char vFilemysp2[60];
    unsigned char vFilemysp3[60];
    unsigned char vFilemysp4[60];
    unsigned char vFilemysp5[60];
    unsigned char vFilemysp6[60];
    unsigned char vFilemysp7[60];
    unsigned char vFilemysp8[60];
    unsigned char vFilemysp9[60];
    unsigned char vFilemysp10[60];
    unsigned char vFilemysp11[60];
    unsigned char vFilemysp12[60];
    unsigned char vFilemysp13[60];
    unsigned char vFilemysp14[60];
    unsigned char vFilemysp15[60];
    unsigned char vFilemysp16[60];
    unsigned char vFilemysp17[60];
    unsigned char vFilemysp18[60];
    unsigned char vFilemysp19[60];
    unsigned char vFilemysp20[60];
    unsigned char vFilemysp21[60];
    unsigned char vFilemysp22[60];
    unsigned char vFilemysp23[60];
    unsigned char vFilemysp24[60];
    unsigned char vFilemysp25[60];
    unsigned char vFilemysp26[60];
    unsigned char vFilemysp27[60];
    unsigned char vFilemysp28[60];
    unsigned char vFilemysp29[60];
    unsigned char vFilemysp30[60];
    unsigned char vFilemysp31[60];
    unsigned char vFilemysp32[60];

    unsigned int vAct;
    unsigned int vExpansion;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Name",
    "Id",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Beta",
    NULL,
};

typedef struct
{
    char acName[64];
} ST_LVL_TYPE;

static unsigned int m_iLvlTypesCount = 0;
static ST_LVL_TYPE *m_astLvlTypes = NULL;

MODULE_SETLINES_FUNC(m_astLvlTypes, ST_LVL_TYPE);
MODULE_HAVENAME_FUNC(m_astLvlTypes, acName, m_iLvlTypesCount);

static int LvlTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Name") )
    {
        int iNextId = ( isD2SigmaActive() ? LvlTypeNames_GetLineID(iLineNo) : m_iLvlTypesCount );
        char acName[33] = {0};
        String_StripFileName(pstLineInfo->vFilemysp1, acName, 32);
        if ( !String_BuildName(FORMAT(lvltypes), 0xFFFF, pcTemplate, acName, iNextId, ( isD2SigmaActive() ? MODULE_HAVENAME : NULL ), acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iNextId);
        }

        strncpy(m_astLvlTypes[iNextId].acName, acOutput, sizeof(m_astLvlTypes[iNextId].acName));
        String_Trim(m_astLvlTypes[iNextId].acName);

        m_iLvlTypesCount++;
        return 1;
    }

    return 0;
}

int process_lvltypes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp11, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp12, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp13, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp14, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp15, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp16, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp17, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp18, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp19, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp20, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp21, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp22, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp23, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp24, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp25, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp26, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp27, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp28, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp29, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp30, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp31, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Filemysp32, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expansion, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(LvlTypeNames, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iLvlTypesCount = 0;

            m_stCallback.pfnFieldProc = LvlTypes_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

char *LvlTypes_GetName(unsigned int id)
{
    if ( id >= m_iLvlTypesCount )
    {
        return NULL;
    }

    return m_astLvlTypes[id].acName;
}

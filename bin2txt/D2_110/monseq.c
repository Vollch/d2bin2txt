#include "../global.h"

#define FILE_PREFIX "MonSeq"
#define NAME_PREFIX "mq"

typedef struct
{
    unsigned short vsequence;
    unsigned char vmode;   //monmode
    unsigned char vframe;

    unsigned char vdir;
    unsigned char vevent;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vsequence[64];
} ST_MONSEQ;

static unsigned int m_iMonSeqCount = 0;
static unsigned int m_iMonSeqHaveEmpty = 0;
static ST_MONSEQ *m_astMonSeq = NULL;

MODULE_SETLINES_FUNC(m_astMonSeq, ST_MONSEQ);
MODULE_HAVENAME_FUNC(m_astMonSeq, vsequence, m_iMonSeqCount);

static char *MonSeq_GetSequence(unsigned int id)
{
    if ( id < m_iMonSeqCount )
    {
        return m_astMonSeq[id].vsequence;
    }

    if ( id == -1 && m_iMonSeqHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonSeq_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "sequence") && m_iMonSeqCount <= pstLineInfo->vsequence )
    {
        if ( !String_BuildName(FORMAT(monseq), 0xFFFF, pcTemplate, NULL, pstLineInfo->vsequence, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vsequence);
        }

        strncpy(m_astMonSeq[pstLineInfo->vsequence].vsequence, acOutput, sizeof(m_astMonSeq[pstLineInfo->vsequence].vsequence));
        String_Trim(m_astMonSeq[pstLineInfo->vsequence].vsequence);
        m_iMonSeqHaveEmpty |= !m_astMonSeq[pstLineInfo->vsequence].vsequence[0];

        m_iMonSeqCount++;
        return 1;
    }

    return 0;
}

int process_monseq(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sequence, MONSEQ);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mode, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, frame, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dir, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, event, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iMonSeqCount = 0;
            Lookup_MonSeq = MonSeq_GetSequence;

            m_stCallback.pfnConvertValue = MonSeq_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

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


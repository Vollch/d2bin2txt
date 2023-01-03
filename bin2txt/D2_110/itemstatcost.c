#include "../global.h"

#define FILE_PREFIX "ItemStatCost"
#define NAME_PREFIX "is"

typedef struct
{//total 324 bytes
    unsigned short vStat;
    unsigned char pad0x02[2];

#if 1
    unsigned char vCombinedBits1;
    unsigned char vCombinedBits2;
#else
    unsigned char bPad13 : 3;
    unsigned char vdirect : 1;

    unsigned char vitemspecific : 1;
    unsigned char vdamagerelated : 1;
    unsigned char vSigned : 1;
    unsigned char vSendmyspOther : 1;

    unsigned char bPad7 : 1;
    unsigned char bPad6 : 1;
    unsigned char vCSvSigned : 1;
    unsigned char vSaved : 1;

    unsigned char vfCallback : 1;
    unsigned char vfMin : 1;
    unsigned char vUpdateAnimRate : 1;
    unsigned char bPad0 : 1;
#endif

    unsigned char pad0x06[2];

    unsigned char vSendmyspBits;
    unsigned char vSendmyspParammyspBits;
    unsigned char vCSvBits;
    unsigned char vCSvParam;

    unsigned int vDivide;
    int vMultiply;
    unsigned int vAdd;

    unsigned char vValShift;
    unsigned char vSavemyspBits;
    unsigned char v1mypoint09mysubSavemyspBits;
    unsigned char pad0x1B;

    int vSavemyspAdd;
    int v1mypoint09mysubSavemyspAdd;
    unsigned int vSavemyspParammyspBits;

    unsigned char pad0x28[4];
    unsigned int vMinAccr;

    unsigned char vEncode;
    unsigned char pad0x31;
    unsigned short vmaxstat;  //引用自身

    unsigned short vdescpriority;
    unsigned char vdescfunc;
    unsigned char vdescval;

    unsigned short vdescstrpos; //strings
    unsigned short vdescstrneg; //strings

    unsigned short vdescstr2;   //strings
    unsigned short vdgrp;

    unsigned char vdgrpfunc;
    unsigned char vdgrpval;
    unsigned short vdgrpstrpos; //strings

    unsigned short vdgrpstrneg; //strings
    unsigned short vdgrpstr2;   //strings

    unsigned short vitemevent1; //events
    unsigned short vitemevent2; //events

    unsigned short vitemeventfunc1;
    unsigned short vitemeventfunc2;

    unsigned int vkeepzero;

    unsigned char vop;
    unsigned char vopmyspparam;
    unsigned short vopmyspbase;   //引用自身

    unsigned short vopmyspstat1;  //引用自身
    unsigned short vopmyspstat2;  //引用自身

    unsigned short vopmyspstat3;  //引用自身

    unsigned char pad0x5E[226];

    unsigned int vstuff;
} ST_LINE_INFO;

typedef struct
{
    char vStat[64];
    unsigned short vdescstrpos;
    unsigned short vdgrp;
    unsigned short vdgrpstrpos;
} ST_ITEM_STATES;

static char *m_apcInternalProcess[] =
{
    "ID",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iItemStatesCount = 0;
static unsigned int m_iItemStatesHaveEmpty = 0;
static ST_ITEM_STATES *m_astItemStates = NULL;

MODULE_SETLINES_FUNC(m_astItemStates, ST_ITEM_STATES);
MODULE_HAVENAME_FUNC(m_astItemStates, vStat, m_iItemStatesCount);

static char *ItemStatCost_GetStateName(unsigned int id)
{
    if ( id < m_iItemStatesCount )
    {
        return m_astItemStates[id].vStat;
    }

    if ( id == -1 && m_iItemStatesHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

unsigned int ItemStatCost_GetString(unsigned int id)
{
    if ( id >= m_iItemStatesCount )
    {
        return 0xFFFF;
    }

    return m_astItemStates[id].vdescstrpos;
}

unsigned int ItemStatCost_GetPropertyString(unsigned short asStats[])
{
    unsigned int i;
    unsigned int iSkillGroup = 0;
    unsigned int iPropGroup = 0;
    unsigned int sGroupString = 0xFFFF;
    unsigned int sStatString = 0xFFFF;

    for ( i = 0; i < 7; i++ )
    {
        if ( asStats[i] < m_iItemStatesCount )
        {
            iSkillGroup = m_astItemStates[asStats[i]].vdgrp;

            if ( sStatString == 0xFFFF )
            {
                sStatString = m_astItemStates[asStats[i]].vdescstrpos;
            }

            if ( !iSkillGroup )
            {
                iPropGroup = 0;
                break;
            }
            else if ( !iPropGroup )
            {
                iPropGroup = iSkillGroup;
                sGroupString = m_astItemStates[asStats[i]].vdgrpstrpos;
            }
            else if ( iPropGroup != iSkillGroup )
            {
                iPropGroup = 0;
                break;
            }
        }
    }

    if ( !iPropGroup )
    {
        return sStatString;
    }

    for ( i = 0; i < m_iItemStatesCount; i++ )
    {
        if ( m_astItemStates[i].vdgrp == iPropGroup && asStats[0] != i
              && asStats[1] != i && asStats[2] != i && asStats[3] != i
              && asStats[4] != i && asStats[5] != i && asStats[6] != i  )
        {
            return sStatString;
        }
    }

    return sGroupString;
}

static int ItemStatCost_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Stat") )
    {
        if ( !String_BuildName(FORMAT(itemstatcost), pstLineInfo->vdescstrpos, pcTemplate, NULL, pstLineInfo->vStat, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vStat);
        }

        m_astItemStates[pstLineInfo->vStat].vdescstrpos = pstLineInfo->vdescstrpos;
        m_astItemStates[pstLineInfo->vStat].vdgrp = pstLineInfo->vdgrp;
        m_astItemStates[pstLineInfo->vStat].vdgrpstrpos = pstLineInfo->vdgrpstrpos;
        strncpy(m_astItemStates[pstLineInfo->vStat].vStat, acOutput, sizeof(m_astItemStates[pstLineInfo->vStat].vStat));
        String_Trim(m_astItemStates[pstLineInfo->vStat].vStat);
        m_iItemStatesHaveEmpty |= !m_astItemStates[pstLineInfo->vStat].vStat[0];

        m_iItemStatesCount++;
        return 1;
    }

    return 0;
}

static int ItemStatCost_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "ID") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vStat);

        return 1;
    }

    return 0;
}

static char *ItemStatCost_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    sprintf(pcKey, "%u", pstLineInfo->vStat);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static void ItemStatCost_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat, ITEMSTAT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, CSvSigned, CombinedBits2, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Saved, CombinedBits2, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, fCallback, CombinedBits2, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, fMin, CombinedBits2, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, UpdateAnimRate, CombinedBits2, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, direct, CombinedBits1, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemspecific, CombinedBits1, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, damagerelated, CombinedBits1, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Signed, CombinedBits1, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SendmyspOther, CombinedBits1, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendmyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendmyspParammyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CSvBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CSvParam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Multiply, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Add, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ValShift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1mypoint09mysubSavemyspBits, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspAdd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1mypoint09mysubSavemyspAdd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspParammyspBits, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinAccr, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Encode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxstat, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descpriority, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descfunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descval, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstrpos, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstrneg, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstr2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrp, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpfunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpval, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstrpos, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstrneg, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstr2, TBL_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemevent1, EVENT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemevent2, EVENT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemeventfunc1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemeventfunc2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, keepzero, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspparam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspbase, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat1, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat2, ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat3, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stuff, UINT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_itemstatcost(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_ITEMSTATCOST_109) )
    {
        return process_itemstatcost109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            ItemStatCost_InitValueMap(pstValueMap, pstLineInfo);

            m_iItemStatesCount = 0;
            Lookup_ItemStatCost = ItemStatCost_GetStateName;

            m_stCallback.pfnConvertValue = ItemStatCost_ConvertValue;
            //m_stCallback.pfnGetKey = ItemStatCost_GetKey;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            ItemStatCost_InitValueMap(pstValueMap, pstLineInfo);

            //m_stCallback.pfnGetKey = ItemStatCost_GetKey;
            m_stCallback.pfnFieldProc = ItemStatCost_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

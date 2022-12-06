#include "global.h"

#define FILE_PREFIX "KillCounter"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vFunc[10];
    unsigned char vClass[5];
    unsigned char vParamStr[10];
    int vParamID;
    int vParamVal;
    unsigned char vSoftcore;
    unsigned char vHardcore;
    unsigned char vNormal;
    unsigned char vNightmare;
    unsigned char vHell;
    int vStat1;
    int vVal1;
    int vStat2;
    int vVal2;
    int vStat3;
    int vVal3;
} ST_LINE_INFO_10;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
    unsigned char vMainFunc;
    unsigned char vSubFunc; 
    unsigned short vKilledMon;
    unsigned char vKilledPlayer;
    unsigned short vFuncStat;
    int vFuncVal;
    unsigned char vClass;
    unsigned char vSoftcore;
    unsigned char vHardcore;
    unsigned char vNormal;
    unsigned char vNightmare;
    unsigned char vHell;
    unsigned short vChance;
    unsigned short vChancemybr1Nmybr2;
    unsigned short vChancemybr1Hmybr2;
    unsigned short vTreasureClass;
    unsigned short vTreasureClassmybr1Nmybr2;
    unsigned short vTreasureClassmybr1Hmybr2;
    unsigned short vStat1;
    unsigned short vStat2;
    unsigned short vStat3;
    unsigned short vStat1mybr1Nmybr2;
    unsigned short vStat2mybr1Nmybr2;
    unsigned short vStat3mybr1Nmybr2;
    unsigned short vStat1mybr1Hmybr2;
    unsigned short vStat2mybr1Hmybr2;
    unsigned short vStat3mybr1Hmybr2;
    int vVal1;
    int vVal2;
    int vVal3;
    int vVal1mybr1Nmybr2;
    int vVal2mybr1Nmybr2;
    int vVal3mybr1Nmybr2;
    int vVal1mybr1Hmybr2;
    int vVal2mybr1Hmybr2;
    int vVal3mybr1Hmybr2;
    unsigned short vMainMsgStr;
    unsigned short vMainMsgStrmybr1Nmybr2;
    unsigned short vMainMsgStrmybr1Hmybr2;
    unsigned short vMsgParam1;
    unsigned short vMsgParam2;
    unsigned short vMsgParam3;
    unsigned short vMsgParam4;
    unsigned short vMsgParam5;
    unsigned short vMsgParam6;
    unsigned short vMsgParam7;
    unsigned short vMsgParam8;
    unsigned short vMsgParam9;
    unsigned short vMsgParam10;
    unsigned short vMsgParam1mybr1Nmybr2;
    unsigned short vMsgParam2mybr1Nmybr2;
    unsigned short vMsgParam3mybr1Nmybr2;
    unsigned short vMsgParam4mybr1Nmybr2;
    unsigned short vMsgParam5mybr1Nmybr2;
    unsigned short vMsgParam6mybr1Nmybr2;
    unsigned short vMsgParam7mybr1Nmybr2;
    unsigned short vMsgParam8mybr1Nmybr2;
    unsigned short vMsgParam9mybr1Nmybr2;
    unsigned short vMsgParam10mybr1Nmybr2;
    unsigned short vMsgParam1mybr1Hmybr2;
    unsigned short vMsgParam2mybr1Hmybr2;
    unsigned short vMsgParam3mybr1Hmybr2;
    unsigned short vMsgParam4mybr1Hmybr2;
    unsigned short vMsgParam5mybr1Hmybr2;
    unsigned short vMsgParam6mybr1Hmybr2;
    unsigned short vMsgParam7mybr1Hmybr2;
    unsigned short vMsgParam8mybr1Hmybr2;
    unsigned short vMsgParam9mybr1Hmybr2;
    unsigned short vMsgParam10mybr1Hmybr2;
} ST_LINE_INFO_12;
#pragma pack(pop)

static char *m_apcNotUsed[] = 
{
    "*remarks",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static int KillCounter_ConvertValue_12(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO_12 *pstLineInfo = pvLineInfo;
    int id;

    if ( !stricmp(acKey, "MainFunc") )
    {
        if ( pstLineInfo->vMainFunc == 0x01 )
        {
            strcpy(acOutput, "Kill");
        }
        else if ( pstLineInfo->vMainFunc == 0x02 )
        {
            strcpy(acOutput, "Bonus");
        }

        return 1;
    }
    else if ( !stricmp(acKey, "SubFunc") )
    {
        if ( pstLineInfo->vSubFunc == 0x01 )
        {
            strcpy(acOutput, "Player");
        }
        else if ( pstLineInfo->vSubFunc == 0x02 )
        {
            strcpy(acOutput, "Monster");
        }
        else if ( pstLineInfo->vSubFunc == 0x03 )
        {
            strcpy(acOutput, "Demon");
        }
        else if ( pstLineInfo->vSubFunc == 0x04 )
        {
            strcpy(acOutput, "Undead");
        }
        else if ( pstLineInfo->vSubFunc == 0x05 )
        {
            strcpy(acOutput, "Once");
        }
        else if ( pstLineInfo->vSubFunc == 0x06 )
        {
            strcpy(acOutput, "Recurring");
        }

        return 1;
    }
    else if ( !stricmp(acKey, "KilledPlayer") || !stricmp(acKey, "Class") )
    {
        unsigned int i = 0;

        for (i = 0; i < 7; i++ )
        {
            if ( pstLineInfo->vClass & i )
            {
                sprintf(&acOutput[strlen(acOutput)], "%s,", PlayerClass_GetClass(i));
            }
        }
        if ( *acOutput )
        {
            acOutput[strlen(acOutput)-1] = 0;
        }

        return 1;
    }
    else if ( 'H' == acKey[strlen(acKey)-2] && 1 == sscanf(acKey, "MsgParam%d(H)", &id) )
    {
        unsigned short sValue = *(&pstLineInfo->vMsgParam1mybr1Hmybr2 + (id - 1));

        if ( sValue == 0x4B24 )
        {
            strcpy(acOutput, "$k");
        }
        else if ( sValue == 0x5024 )
        {
            strcpy(acOutput, "$p");
        }
        else if ( sValue == 0x5324 )
        {
            strcpy(acOutput, "$s");
        }
        else if ( sValue == 0x5624 )
        {
            strcpy(acOutput, "$v");
        }
        else if ( sValue > 0 )
        {
            sprintf(acOutput, "#%u", sValue);
        }

        return 1;
    }
    else if ( 'N' == acKey[strlen(acKey)-2] &&  1 == sscanf(acKey, "MsgParam%d(N)", &id) )
    {
        unsigned short sValue = *(&pstLineInfo->vMsgParam1mybr1Nmybr2 + (id - 1));

        if ( sValue == 0x4B24 )
        {
            strcpy(acOutput, "$K");
        }
        else if ( sValue == 0x5024 )
        {
            strcpy(acOutput, "$P");
        }
        else if ( sValue == 0x5324 )
        {
            strcpy(acOutput, "$S");
        }
        else if ( sValue == 0x5624 )
        {
            strcpy(acOutput, "$V");
        }
        else if ( sValue > 0 )
        {
            sprintf(acOutput, "#%u", sValue);
        }

        return 1;
    }
    else if ( 1 == sscanf(acKey, "MsgParam%d", &id) )
    {
        unsigned short sValue = *(&pstLineInfo->vMsgParam1 + (id - 1));

        if ( sValue == 0x4B24 )
        {
            strcpy(acOutput, "$k");
        }
        else if ( sValue == 0x5024 )
        {
            strcpy(acOutput, "$p");
        }
        else if ( sValue == 0x5324 )
        {
            strcpy(acOutput, "$s");
        }
        else if ( sValue == 0x5624 )
        {
            strcpy(acOutput, "$v");
        }
        else if ( sValue > 0 )
        {
            sprintf(acOutput, "#%u", sValue);
        }

        return 1;
    }

 
    return 0;
}

int process_KillCounter_10(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_10 *pstLineInfo = (ST_LINE_INFO_10 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Func, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ParamStr, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ParamID, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ParamVal, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Softcore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hardcore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nightmare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hell, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3, INT);

    VALUE_MAP_DEFINE_3(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.iOptional = 1;
    m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_KillCounter_12(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO_12 *pstLineInfo = (ST_LINE_INFO_12 *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MainFunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubFunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KilledMon, USHORT_MONSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KilledPlayer, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncStat, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncVal, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Softcore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hardcore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nightmare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hell, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chancemybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chancemybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass, USHORT_TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClassmybr1Nmybr2, USHORT_TREASURE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClassmybr1Hmybr2, USHORT_TREASURE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3mybr1Nmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat1mybr1Hmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat2mybr1Hmybr2, USHORT_ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Stat3mybr1Hmybr2, USHORT_ITEMSTAT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3mybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val1mybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val2mybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Val3mybr1Hmybr2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MainMsgStr, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MainMsgStrmybr1Nmybr2, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MainMsgStrmybr1Hmybr2, USHORT_STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam7, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam9, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam10, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam1mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam2mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam3mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam4mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam5mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam6mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam7mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam8mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam9mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam10mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam1mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam2mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam3mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam4mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam5mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam6mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam7mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam8mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam9mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MsgParam10mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE_3(pstValueMap, pstLineInfo, myasteol, EOL);

    m_stCallback.iOptional = 1;
    m_stCallback.pfnConvertValue = KillCounter_ConvertValue_12;
    m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_KillCounter(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            if ( m_iBinStructSize != sizeof(ST_LINE_INFO_10) )
            {
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_INIT:
            if ( m_iBinStructSize == sizeof(ST_LINE_INFO_10) )
            {
                my_printf("KillCounter 1.0 detected\n");
                return process_KillCounter_10(acTemplatePath, acBinPath, acTxtPath);
            }
            return process_KillCounter_12(acTemplatePath, acBinPath, acTxtPath);
            break;

        default:
            break;
    }

    return 1;
}


#include "../global.h"

#define FILE_PREFIX "D2NPCFunc"
#define NAME_PREFIX "nf"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIDx;
    unsigned int vcount;

    unsigned short vStr1; // 0x16
    unsigned char vDLL1[32];
    unsigned int vFuncAddr1;
    unsigned short vStr2; // 0x16
    unsigned char vDLL2[32];
    unsigned int vFuncAddr2;
    unsigned short vStr3; // 0x16
    unsigned char vDLL3[32];
    unsigned int vFuncAddr3;
    unsigned short vStr4; // 0x16
    unsigned char vDLL4[32];
    unsigned int vFuncAddr4;
    unsigned short vStr5; // 0x16
    unsigned char vDLL5[32];
    unsigned int vFuncAddr5;

    unsigned char vSpecial;
    unsigned char vHeal;
    unsigned char vHire;
    unsigned char vTraRep;
    unsigned char vResurrect;
    unsigned int vqNo;
    unsigned char vflagNo;
    unsigned char vnotSet;
    unsigned char vqPlace;
    unsigned char vqNewC;

    unsigned short vqStr; // 0x16
    unsigned char vqDLL[32];
    unsigned int vqFuncAddr;

    unsigned char vact;
    unsigned int vEntryNo;
    unsigned char vukn1;
    unsigned char vukn2;
    unsigned char vSend;
    unsigned char vNoInto;
    unsigned char vukn5;

    unsigned short vsStr0; // 0x16
    unsigned char vcheckq0;
    unsigned char vsFlag0;
    unsigned int vquestNo0;
    unsigned char vclass0; // 0x0D

    unsigned short vsStr1; // 0x16
    unsigned char vcheckq1;
    unsigned char vsFlag1;
    unsigned int vquestNo1;
    unsigned char vclass1; // 0x0D

    unsigned short vsStr2; // 0x16
    unsigned char vcheckq2;
    unsigned char vsFlag2;
    unsigned int vquestNo2;
    unsigned char vclass2; // 0x0D

    unsigned short vsStr3; // 0x16
    unsigned char vcheckq3;
    unsigned char vsFlag3;
    unsigned int vquestNo3;
    unsigned char vclass3; // 0x0D

    unsigned short vsStr4; // 0x16
    unsigned char vcheckq4;
    unsigned char vsFlag4;
    unsigned int vquestNo4;
    unsigned char vclass4; // 0x0D

    unsigned short vsStr5; // 0x16
    unsigned char vcheckq5;
    unsigned char vsFlag5;
    unsigned int vquestNo5;
    unsigned char vclass5; // 0x0D

    unsigned short vsStr6; // 0x16
    unsigned char vcheckq6;
    unsigned char vsFlag6;
    unsigned int vquestNo6;
    unsigned char vclass6; // 0x0D

    unsigned short vsStr7; // 0x16
    unsigned char vcheckq7;
    unsigned char vsFlag7;
    unsigned int vquestNo7;
    unsigned char vclass7; // 0x0D

    unsigned short vsStr8; // 0x16
    unsigned char vcheckq8;
    unsigned char vsFlag8;
    unsigned int vquestNo8;
    unsigned char vclass8; // 0x0D

    unsigned short vsStr9; // 0x16
    unsigned char vcheckq9;
    unsigned char vsFlag9;
    unsigned int vquestNo9;
    unsigned char vclass9; // 0x0D

    unsigned short vsStr10; // 0x16
    unsigned char vcheckq10;
    unsigned char vsFlag10;
    unsigned int vquestNo10;
    unsigned char vclass10; // 0x0D

    unsigned short vsStr11; // 0x16
    unsigned char vcheckq11;
    unsigned char vsFlag11;
    unsigned int vquestNo11;
    unsigned char vclass11; // 0x0D

    unsigned short vsStr12; // 0x16
    unsigned char vcheckq12;
    unsigned char vsFlag12;
    unsigned int vquestNo12;
    unsigned char vclass12; // 0x0D

    unsigned short vsStr13; // 0x16
    unsigned char vcheckq13;
    unsigned char vsFlag13;
    unsigned int vquestNo13;
    unsigned char vclass13; // 0x0D

    unsigned short vsStr14; // 0x16
    unsigned char vcheckq14;
    unsigned char vsFlag14;
    unsigned int vquestNo14;
    unsigned char vclass14; // 0x0D

    unsigned short vsStr15; // 0x16
    unsigned char vcheckq15;
    unsigned char vsFlag15;
    unsigned int vquestNo15;
    unsigned char vclass15; // 0x0D

    unsigned short vsStr16; // 0x16
    unsigned char vcheckq16;
    unsigned char vsFlag16;
    unsigned int vquestNo16;
    unsigned char vclass16; // 0x0D

    unsigned short vsStr17; // 0x16
    unsigned char vcheckq17;
    unsigned char vsFlag17;
    unsigned int vquestNo17;
    unsigned char vclass17; // 0x0D

    unsigned short vsStr18; // 0x16
    unsigned char vcheckq18;
    unsigned char vsFlag18;
    unsigned int vquestNo18;
    unsigned char vclass18; // 0x0D

    unsigned short vsStr19; // 0x16
    unsigned char vcheckq19;
    unsigned char vsFlag19;
    unsigned int vquestNo19;
    unsigned char vclass19; // 0x0D

    unsigned char vSpecX;

    unsigned short vResStr; // 0x16
    unsigned int vResFunc;
    unsigned char vResDLL[32];

    unsigned char vPage;
    unsigned char vIdent;
    unsigned char vhasTrade;
    unsigned char vuknw;
    unsigned char vGamble;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*Name",
    NULL,
};

static int D2NPCFunc_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*Name") )
    {
        if ( !String_BuildName(FORMAT(D2NPCFunc), pstLineInfo->vsStr0, pcTemplate, Lookup_MonStats(pstLineInfo->vhcIDx), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}


int process_D2NPCFunc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, count, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DLL1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncAddr1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DLL2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncAddr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DLL3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncAddr3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DLL4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncAddr4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DLL5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FuncAddr5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Special, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Heal, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Hire, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TraRep, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Resurrect, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qNo, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flagNo, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, notSet, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qPlace, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qNewC, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qStr, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qDLL, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qFuncAddr, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntryNo, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ukn1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ukn2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Send, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoInto, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ukn5, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr0, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo0, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class0, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class1, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class2, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class3, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class4, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class5, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr6, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class6, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr7, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo7, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class7, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr8, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq8, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag8, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo8, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class8, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr9, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq9, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag9, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo9, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class9, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr10, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq10, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag10, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo10, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class10, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr11, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq11, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag11, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo11, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class11, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr12, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq12, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag12, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo12, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class12, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr13, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq13, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag13, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo13, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class13, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr14, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq14, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag14, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo14, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class14, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr15, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq15, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag15, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo15, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class15, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr16, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq16, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag16, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo16, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class16, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr17, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq17, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag17, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo17, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class17, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr18, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq18, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag18, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo18, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class18, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sStr19, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, checkq19, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sFlag19, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questNo19, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class19, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpecX, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResStr, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFunc, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDLL, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Page, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Ident, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hasTrade, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uknw, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gamble, UCHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2NPCFunc_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);

        default:
            break;
    }

    return 1;
}


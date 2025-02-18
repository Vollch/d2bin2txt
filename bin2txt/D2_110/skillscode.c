#include "../global.h"

//#define USE_NUMBER
#define EQUAL_OPER_BRACKET

#define FILE_PREFIX "SkillsCode"
#define STACK_HEAD  4

/*
优先级待处理

par1
04 08 00

lvl/par2
04 10 04 09 13 00

par1+lvl/par2
04 08 04 10 04 09 13 10 00

skill('Fire Trauma'.blvl)
08 FB 00 07 29 01 03 00

skill('Fire Trauma'.blvl)/3
08 FB 00 07 29 01 03 07 03 13 00

par1+lvl/par2+skill('Fire Trauma'.blvl)/3
04 08 04 10 04 09 13 10 08 fb 00 07 29 01 03 07 03 13 10 00

par1*(par2+par4)
04 08 04 09 04 0b 10 12 00

skill('Fire Trauma'.lvl)
08 FB 00 07 10 01 03 00

skill('Baal Clone Teleport'.blvl)
08 4B 01 07 29 01 03 00

ln34+(skill('Shiver Armor'.blvl)+skill('Chilling Armor'.blvl))*par7
04 02 07 32 07 29 01 03 07 3c 07 29 01 03 10 04 0e 12 10 00

skill('Shiver Armor'.blvl)
07 32 07 29 01 03 00

-par5
04 0c 15 00

((lvl < 4) ? 0 : ((lvl-3)*par3))
04 10 07 04 0a 07 00 04 10 07 03 11 04 0a 12 16 00

100-dm34
07 64 04 03 11 00

skill('Prayer'.edns)
07 63 07 26 01 03 00

"-min(ln34,150)"
04 02 08 96 00 01 00 15 00

"min((lvl+skill('Dopplezon'.blvl))*par7,85)"
04 10 07 1c 07 29 01 03 10 04 0e 12 07 55 01 00 00

-2
07 fe 00

(100+20)*(-30)
08 f0 f1 00

(100+20)*1000
09 c0 d4 01 00 00

stat('passive_fire_mastery'.accr)
08 49 01 07 00 01 04 00
*/

typedef struct
{
    unsigned char acExpressionTxt[10240];
    unsigned char acExpressionBin[10240];
    unsigned int uiBinLen;
} ST_SKILLCODE;

static void *m_pvStack = NULL;
static unsigned int m_uiExpressionIndex = 0;
static unsigned int m_uiSkillCodeCount = 0;

static unsigned int m_uiSkillCodeBuffSize = 0;
static ST_SKILLCODE *m_astSkillCode = NULL;

typedef int (*fnProcFuncArg)(unsigned char *pcBinBuf, unsigned char *pcTxtBuf);

static void SkillsCode_PrintHex()
{
    unsigned int j;

    for ( j = 0; j < m_uiExpressionIndex; j++ )
    {
        my_printf("%02x ", (unsigned char)m_acGlobalBuffer[j]);
    }
    if ( m_uiExpressionIndex > 0 )
    {
        my_printf("\r\n");
    }
}

#define FINISH_CODE_TAG 0xFF

static int SkillsCode_ConverterBin2Txt(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
            if ( pcResult = Lookup_SkillCalc(pcBinBuf[STACK_HEAD]) )
            {
                strcpy(pcTxtBuf, pcResult);
            }
            else
            {
                my_error("unknown skill calc in expression %u\r\n", m_uiSkillCodeCount);
                result = 0;
            }
            break;

        case 0x07:
            sprintf(pcTxtBuf, "%d", (char)pcBinBuf[STACK_HEAD]);
            break;

        case 0x08:
            sprintf(pcTxtBuf, "%d", *(short *)&pcBinBuf[STACK_HEAD]);
            break;

        case 0x09:
            sprintf(pcTxtBuf, "%d", *(int *)&pcBinBuf[STACK_HEAD]);
            break;

        case FINISH_CODE_TAG:
            strcpy(pcTxtBuf, &pcBinBuf[STACK_HEAD]);
            break;

        default:
            my_error("unknown binary in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    return result;
}

static int SkillsCode_SkillArg1Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown skill arg 1 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_Skill(uiSkillIndex) )
        {
            sprintf(pcTxtBuf, "'%s'", pcResult);
        }
        else
        {
            my_error("not found skill %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_SkillArg2Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown skill arg 2 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
        if ( pcResult = Lookup_SkillCalc(uiSkillIndex) )
        {
            strcpy(pcTxtBuf, pcResult);
        }
        else
        {
            my_error("not found skillcalc %u\r\n", uiSkillIndex);
            result = 0;
        }
    }

    return result;
}

static int SkillsCode_StatArg1Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown stat arg 1 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcBinBuf[0] == 0x04 && 0 == uiSkillIndex)
        {
            my_printf("  Expression %u is missing arg1 of stat()\r\n", m_uiSkillCodeCount);
            pcResult = g_pcFallbackID;
        }
        else
        {
            pcResult = Lookup_ItemStatCost(uiSkillIndex);
        }

        if ( pcResult )
        {
            sprintf(pcTxtBuf, "'%s'", pcResult);
        }
        else
        {
            my_error("not found itemstatcost %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_StatArg2Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown stat arg 2 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
        if ( pcBinBuf[0] == 0x04 && 0 == uiSkillIndex)
        {
            my_printf("  Expression %u is missing arg2 of stat()\r\n", m_uiSkillCodeCount);
            pcTxtBuf[-1] = ' ';
            strcpy(pcTxtBuf, g_pcFallbackCode);
        }
        else if ( 0 == uiSkillIndex )
        {
            strcpy(pcTxtBuf, "accr");
        }
        else if ( 1 == uiSkillIndex )
        {
            strcpy(pcTxtBuf, "base");
        }
        else if ( 2 == uiSkillIndex )
        {
            strcpy(pcTxtBuf, "mod");
        }
        else
        {
            my_error("invalid itemstatcost %u in expression %u\r\n", uiSkillIndex, m_uiSkillCodeCount);
            result = 0;
        }
    }

    return result;
}

static int SkillsCode_MissArg1Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown miss arg 1 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_Missile(uiSkillIndex) )
        {
            sprintf(pcTxtBuf, "'%s'", pcResult);
        }
        else
        {
            my_error("not found miss %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_MissArg2Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown miss arg 1 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_MissCalc(uiSkillIndex) )
        {
            strcpy(pcTxtBuf, pcResult);
        }
        else
        {
            my_error("not found misscalc %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_SkLvlArg1Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown skill arg 1 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_Skill(uiSkillIndex) )
        {
            sprintf(pcTxtBuf, "'%s'", pcResult);
        }
        else
        {
            my_error("not found skill %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_SkLvlArg2Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown skillcalc arg 2 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_SkillCalc(uiSkillIndex) )
        {
            strcpy(pcTxtBuf, pcResult);
        }
        else
        {
            my_error("not found skillcalc %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_SkLvlArg3Proc(unsigned char *pcBinBuf, unsigned char *pcTxtBuf)
{
    int result = 1;
    unsigned int uiSkillIndex;
    unsigned char *pcResult;

    switch ( pcBinBuf[0] )
    {
        case 0x04:
        case 0x07:
            uiSkillIndex = (unsigned char)pcBinBuf[STACK_HEAD];
            break;

        case 0x08:
            uiSkillIndex = *(unsigned short *)&pcBinBuf[STACK_HEAD];
            break;

        case 0x09:
            uiSkillIndex = *(unsigned int *)&pcBinBuf[STACK_HEAD];
            break;

        default:
            my_error("unknown skillcalc arg 3 in expression %u\r\n", m_uiSkillCodeCount);
            result = 0;
            break;
    }

    if ( 0 != result )
    {
#ifdef USE_NUMBER
        sprintf(pcTxtBuf, "%u", uiSkillIndex);
#else
        if ( pcResult = Lookup_SkillCalc(uiSkillIndex) )
        {
            strcpy(pcTxtBuf, pcResult);
        }
        else
        {
            my_error("not found skillcalc %u\r\n", uiSkillIndex);
            result = 0;
        }
#endif
    }

    return result;
}

static int SkillsCode_OutputExpression(unsigned char *pcTempBuf)
{
    if ( m_uiSkillCodeCount >= m_uiSkillCodeBuffSize )
    {
        ST_SKILLCODE *astNewArray = MemMgr_Realloc(m_astSkillCode, (sizeof(ST_SKILLCODE) * (m_uiSkillCodeBuffSize + 5000)));

        if ( !astNewArray )
        {
            return 0;
        }

        m_astSkillCode = astNewArray;
        memset(&m_astSkillCode[m_uiSkillCodeBuffSize], 0, sizeof(ST_SKILLCODE) * 5000);
        m_uiSkillCodeBuffSize += 5000;
    }

    if ( SkillsCode_ConverterBin2Txt(pcTempBuf, m_astSkillCode[m_uiSkillCodeCount].acExpressionTxt) )
    {
        int iExpLen = strlen(m_astSkillCode[m_uiSkillCodeCount].acExpressionTxt);
        if ( iExpLen >= 255 )
        {
            my_printf("  Expression %u is %u characters long, consider refactoring it, or shortening related IDs\r\n", m_uiSkillCodeCount, iExpLen);
        }
        memcpy(m_astSkillCode[m_uiSkillCodeCount].acExpressionBin, m_acGlobalBuffer, m_uiExpressionIndex);
        m_astSkillCode[m_uiSkillCodeCount].uiBinLen = m_uiExpressionIndex;
        m_uiExpressionIndex = 0;
        m_uiSkillCodeCount++;

        return 1;
    }

    return 0;
}

static int SkillsCode_ReadFile(unsigned char *pcBuffer, int iElemSize, int iElemCount, FILE *pfHandle)
{
    int iReadByte = (int)fread(pcBuffer, iElemSize, iElemCount, pfHandle);

    if ( iReadByte == iElemCount * iElemSize )
    {
        memcpy(&m_acGlobalBuffer[m_uiExpressionIndex], pcBuffer, iReadByte);
        m_uiExpressionIndex += iReadByte;

        return iReadByte;
    }

    return 0;
}

static int SkillsCode_OneOprandProc(unsigned char *pbOperater, unsigned int uiOpLevel, ENUM_OPERATER_ARGNUM enArgNum,
    ENUM_OPERATER_LEFTRIGHT enLeftRight, unsigned char *acExpressionBuf, unsigned int uiBufLen)
{
    int result = 1;
    unsigned char *pcOperand1 = NULL;

    Stack_Pop(m_pvStack, &pcOperand1);

    if ( !pcOperand1 )
    {
        return 0;
    }

    acExpressionBuf[0] = FINISH_CODE_TAG;
    acExpressionBuf[1] = (unsigned char)uiOpLevel;
    acExpressionBuf[2] = FINISH_CODE_TAG;
    acExpressionBuf[3] = FINISH_CODE_TAG;

#ifdef EQUAL_OPER_BRACKET
    if ( uiOpLevel <= pcOperand1[1] )
#else
    if ( uiOpLevel < pcOperand1[1] ||
        (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
    {
        sprintf(&acExpressionBuf[strlen(acExpressionBuf)], "%s(", pbOperater);
    }
    else
    {
        sprintf(&acExpressionBuf[strlen(acExpressionBuf)], "%s", pbOperater);
    }

    if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]) )
    {
        my_error("operater %s fail\r\n", pbOperater);
        result = 0;
    }
    else
    {
#ifdef EQUAL_OPER_BRACKET
        if ( uiOpLevel <= pcOperand1[1] )
#else
        if ( uiOpLevel < pcOperand1[1] ||
            (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
        {
            acExpressionBuf[strlen(acExpressionBuf)] = ')';
        }
        Stack_Push(m_pvStack, acExpressionBuf, (unsigned int)strlen(acExpressionBuf));
    }

    return result;
}

static int SkillsCode_TwoOprandProc(unsigned char *pbOperater, unsigned int uiOpLevel, ENUM_OPERATER_ARGNUM enArgNum,
    ENUM_OPERATER_LEFTRIGHT enLeftRight, unsigned char *acExpressionBuf, unsigned int uiBufLen)
{
    int result = 1;
    unsigned char *pcOperand1 = NULL;
    unsigned char *pcOperand2 = NULL;

    Stack_Pop(m_pvStack, &pcOperand2);
    Stack_Pop(m_pvStack, &pcOperand1);

    if ( !pcOperand1 || !pcOperand2 )
    {
        return 0;
    }

    acExpressionBuf[0] = FINISH_CODE_TAG;
    acExpressionBuf[1] = (unsigned char)uiOpLevel;
    acExpressionBuf[2] = FINISH_CODE_TAG;
    acExpressionBuf[3] = FINISH_CODE_TAG;

#ifdef EQUAL_OPER_BRACKET
    if ( uiOpLevel <= pcOperand1[1] )
#else
    if ( uiOpLevel < pcOperand1[1] ||
        (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
    {
        acExpressionBuf[strlen(acExpressionBuf)] = '(';
    }

    if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]) )
    {
        my_error("operater %s fail\r\n", pbOperater);
        result = 0;
    }
    else
    {
#ifdef EQUAL_OPER_BRACKET
        if ( uiOpLevel <= pcOperand1[1] )
#else
        if ( uiOpLevel < pcOperand1[1] ||
            (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
        {
            sprintf(&acExpressionBuf[strlen(acExpressionBuf)], ")%s", pbOperater);
        }
        else
        {
            sprintf(&acExpressionBuf[strlen(acExpressionBuf)], "%s", pbOperater);
        }

#ifdef EQUAL_OPER_BRACKET
        if ( uiOpLevel <= pcOperand2[1] )
#else
        if ( uiOpLevel < pcOperand2[1] ||
            (uiOpLevel == pcOperand2[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
        {
            acExpressionBuf[strlen(acExpressionBuf)] = '(';
        }

        if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]) )
        {
            my_error("operater %s fail 2\r\n", pbOperater);
            result = 0;
        }
        else
        {
#ifdef EQUAL_OPER_BRACKET
            if ( uiOpLevel <= pcOperand2[1] )
#else
            if ( uiOpLevel < pcOperand2[1] ||
                (uiOpLevel == pcOperand2[1] && EN_OPERATER_RIGHT == enLeftRight) )
#endif
            {
                acExpressionBuf[strlen(acExpressionBuf)] = ')';
            }
            Stack_Push(m_pvStack, acExpressionBuf, (unsigned int)strlen(acExpressionBuf));
        }
    }

    return result;
}

static int SkillsCode_ThreeOprandProc(unsigned char *pbOperater1, unsigned char *pbOperater2, unsigned int uiOpLevel,
    ENUM_OPERATER_ARGNUM enArgNum, ENUM_OPERATER_LEFTRIGHT enLeftRight, unsigned char *acExpressionBuf, unsigned int uiBufLen)
{
    int result = 1;
    unsigned char *pcOperand1 = NULL;
    unsigned char *pcOperand2 = NULL;
    unsigned char *pcOperand3 = NULL;

    Stack_Pop(m_pvStack, &pcOperand3);
    Stack_Pop(m_pvStack, &pcOperand2);
    Stack_Pop(m_pvStack, &pcOperand1);

    if ( !pcOperand1 || !pcOperand2 || !pcOperand3 )
    {
        return 0;
    }

    acExpressionBuf[0] = FINISH_CODE_TAG;
    acExpressionBuf[1] = (unsigned char)uiOpLevel;
    acExpressionBuf[2] = FINISH_CODE_TAG;
    acExpressionBuf[3] = FINISH_CODE_TAG;

#if 0
    if ( uiOpLevel < pcOperand1[1] ||
        (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
    if ( 1 < pcOperand1[1] )
#endif
    {
        acExpressionBuf[strlen(acExpressionBuf)] = '(';
    }

    if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]) )
    {
        my_error("operater %s fail\r\n", pbOperater1);
        result = 0;
    }
    else
    {
#if 0
        if ( uiOpLevel < pcOperand1[1] ||
            (uiOpLevel == pcOperand1[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
        if ( 1 < pcOperand1[1] )
#endif
        {
            acExpressionBuf[strlen(acExpressionBuf)] = ')';
            acExpressionBuf[strlen(acExpressionBuf)] = *pbOperater1;
        }
        else
        {
            acExpressionBuf[strlen(acExpressionBuf)] = *pbOperater1;
        }

#if 0
        if ( uiOpLevel < pcOperand2[1] ||
            (uiOpLevel == pcOperand2[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
        if ( 1 < pcOperand2[1] )
#endif
        {
            acExpressionBuf[strlen(acExpressionBuf)] = '(';
        }

        if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]) )
        {
            my_error("operater %s fail 2\r\n", pbOperater1);
            result = 0;
        }
        else
        {
#if 0
            if ( uiOpLevel < pcOperand2[1] ||
                (uiOpLevel == pcOperand2[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
            if ( 1 < pcOperand2[1] )
#endif
            {
                acExpressionBuf[strlen(acExpressionBuf)] = ')';
                acExpressionBuf[strlen(acExpressionBuf)] = *pbOperater2;
            }
            else
            {
                acExpressionBuf[strlen(acExpressionBuf)] = *pbOperater2;
            }

#if 0
            if ( uiOpLevel < pcOperand3[1] ||
                (uiOpLevel == pcOperand3[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
            if ( 1 < pcOperand3[1] )
#endif
            {
                acExpressionBuf[strlen(acExpressionBuf)] = '(';
            }

            if ( 0 == SkillsCode_ConverterBin2Txt(pcOperand3, &acExpressionBuf[strlen(acExpressionBuf)]) )
            {
                my_error("operater %s fail 3\r\n", pbOperater2);
                result = 0;
            }
            else
            {
#if 0
                if ( uiOpLevel < pcOperand3[1] ||
                    (uiOpLevel == pcOperand3[1] && EN_OPERATER_RIGHT == enLeftRight) )
#else
                if ( 1 < pcOperand3[1] )
#endif
                {
                    acExpressionBuf[strlen(acExpressionBuf)] = ')';
                }
                Stack_Push(m_pvStack, acExpressionBuf, (unsigned int)strlen(acExpressionBuf));
            }
        }
    }

    return result;
}

static int SkillsCode_TwoArgFuncProc(unsigned char *pbFunction, unsigned char *pbOperater,
    unsigned char *acExpressionBuf, unsigned int uiBufLen,
    fnProcFuncArg pfnProcArg1, fnProcFuncArg pfnProcArg2)
{
    int result = 1;
    unsigned char *pcOperand1 = NULL;
    unsigned char *pcOperand2 = NULL;

    Stack_Pop(m_pvStack, &pcOperand2);
    Stack_Pop(m_pvStack, &pcOperand1);

    if ( !pcOperand1 || !pcOperand2 )
    {
        return 0;
    }

    acExpressionBuf[0] = FINISH_CODE_TAG;
    acExpressionBuf[1] = FUNCTION_OPERATER_LEVEL;
    acExpressionBuf[2] = FINISH_CODE_TAG;
    acExpressionBuf[3] = FINISH_CODE_TAG;

    sprintf(&acExpressionBuf[strlen(acExpressionBuf)], "%s(", pbFunction);
    if ( (pfnProcArg1 && 1 == pfnProcArg1(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]))
        || 1 == SkillsCode_ConverterBin2Txt(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]) )
    {
        strcpy(&acExpressionBuf[strlen(acExpressionBuf)], pbOperater);

        if ( (pfnProcArg2 && 1 == pfnProcArg2(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]))
            || 1 == SkillsCode_ConverterBin2Txt(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]) )
        {
            acExpressionBuf[strlen(acExpressionBuf)] = ')';
            Stack_Push(m_pvStack, acExpressionBuf, (unsigned int)strlen(acExpressionBuf));
        }
        else
        {
            my_error("operater %s fail 2\r\n", pbOperater);
            result = 0;
        }
    }
    else
    {
        my_error("operater %s fail\r\n", pbOperater);
        result = 0;
    }

    return result;
}

static int SkillsCode_ThreeArgFuncProc(unsigned char *pbFunction, unsigned char *pbOperater1, unsigned char *pbOperater2,
    unsigned char *acExpressionBuf, unsigned int uiBufLen,
    fnProcFuncArg pfnProcArg1, fnProcFuncArg pfnProcArg2, fnProcFuncArg pfnProcArg3)
{
    int result = 1;
    unsigned char *pcOperand1 = NULL;
    unsigned char *pcOperand2 = NULL;
    unsigned char *pcOperand3 = NULL;

    Stack_Pop(m_pvStack, &pcOperand3);
    Stack_Pop(m_pvStack, &pcOperand2);
    Stack_Pop(m_pvStack, &pcOperand1);

    if ( !pcOperand1 || !pcOperand2 || !pcOperand3 )
    {
        return 0;
    }

    acExpressionBuf[0] = FINISH_CODE_TAG;
    acExpressionBuf[1] = FUNCTION_OPERATER_LEVEL;
    acExpressionBuf[2] = FINISH_CODE_TAG;
    acExpressionBuf[3] = FINISH_CODE_TAG;

    sprintf(&acExpressionBuf[strlen(acExpressionBuf)], "%s(", pbFunction);

    if ( (pfnProcArg1 && 1 == pfnProcArg1(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]))
        || 1 == SkillsCode_ConverterBin2Txt(pcOperand1, &acExpressionBuf[strlen(acExpressionBuf)]) )
    {
        strcpy(&acExpressionBuf[strlen(acExpressionBuf)], pbOperater1);

        if ( (pfnProcArg2 && 1 == pfnProcArg2(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]))
            || 1 == SkillsCode_ConverterBin2Txt(pcOperand2, &acExpressionBuf[strlen(acExpressionBuf)]) )
        {
            strcpy(&acExpressionBuf[strlen(acExpressionBuf)], pbOperater2);

            if ( (pfnProcArg3 && 1 == pfnProcArg3(pcOperand3, &acExpressionBuf[strlen(acExpressionBuf)]))
                || 1 == SkillsCode_ConverterBin2Txt(pcOperand3, &acExpressionBuf[strlen(acExpressionBuf)]) )
            {
                acExpressionBuf[strlen(acExpressionBuf)] = ')';
                Stack_Push(m_pvStack, acExpressionBuf, (unsigned int)strlen(acExpressionBuf));
            }
            else
            {
                my_error("operater %s fail 3\r\n", pbOperater2);
                result = 0;
            }
        }
        else
        {
            my_error("operater %s fail 2\r\n", pbOperater2);
            result = 0;
        }
    }
    else
    {
        my_error("operater %s fail\r\n", pbOperater1);
        result = 0;
    }

    return result;
}

static int SkillsCode_OperaterProc(unsigned char bOperater)
{
    int result = 1;
    unsigned int uiOpLevel;
    unsigned char *pcOpString;
    ENUM_OPERATER_ARGNUM enArgNum;
    ENUM_OPERATER_LEFTRIGHT enLeftRight;
    static unsigned char acExpressionBuf[10240];

    uiOpLevel = Operater_GetOpLevel((ENUM_OPERATER_TYPE)bOperater);
    pcOpString = Operater_GetOpStr((ENUM_OPERATER_TYPE)bOperater);
    enArgNum = Operater_GetArgNum((ENUM_OPERATER_TYPE)bOperater);
    enLeftRight = Operater_GetLeftRight((ENUM_OPERATER_TYPE)bOperater);

    if ( MAX_OPERATER_LEVEL == uiOpLevel )
    {
        my_error("unknown tag %u in expression %u\r\n", bOperater, m_uiSkillCodeCount);
        return result;
    }

    memset(acExpressionBuf, 0, sizeof(acExpressionBuf));

    switch ( enArgNum )
    {
        case EN_OPERATER_ARG_1:
            result = SkillsCode_OneOprandProc(pcOpString, uiOpLevel, enArgNum, enLeftRight, acExpressionBuf, sizeof(acExpressionBuf));
            break;

        case EN_OPERATER_ARG_2:
            result = SkillsCode_TwoOprandProc(pcOpString, uiOpLevel, enArgNum, enLeftRight, acExpressionBuf, sizeof(acExpressionBuf));
            break;

        case EN_OPERATER_ARG_3:
            result = SkillsCode_ThreeOprandProc(&pcOpString[0], &pcOpString[1], uiOpLevel, enArgNum, enLeftRight, acExpressionBuf, sizeof(acExpressionBuf));
            break;

        default:
            my_error("unknown argnum %u in expression %u\r\n", bOperater, m_uiSkillCodeCount);
            return result;
            break;
    }

    return result;
}

static int SkillsCode_ParseBin(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    int result = 1;
    unsigned int i, j;
    FILE *pfBinHandle = NULL;
    FILE *pfOutputHandle = NULL;
    unsigned char bOperater;
    unsigned char *pcTemp;
    static unsigned char acTempBuf[10240] = {0};

    if ( 0 < m_uiSkillCodeCount )
    {
        return 1;
    }

    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, FILE_PREFIX);
    pfBinHandle = fopen(m_acGlobalBuffer, "rb");

    if ( NULL == pfBinHandle )
    {
        my_error("failed to read %s bin\r\n", FILE_PREFIX);
        goto error;
    }

    sprintf(m_acGlobalBuffer, "%s\\%s.txt", acTxtPath, FILE_PREFIX);
    pfOutputHandle = fopen(m_acGlobalBuffer, "wb");

    if ( NULL == pfOutputHandle )
    {
        my_error("failed to create %s txt\r\n", FILE_PREFIX);
        goto error;
    }

    my_printf("start parsing %s.bin\r\n", FILE_PREFIX);

    m_uiExpressionIndex = 0;
    m_uiSkillCodeCount = 0;

    m_astSkillCode = MemMgr_Malloc(sizeof(ST_SKILLCODE) * 5000);
    memset(m_astSkillCode, 0, sizeof(ST_SKILLCODE) * 5000);
    m_uiSkillCodeBuffSize = 5000;

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);
    memset(acTempBuf, 0, sizeof(acTempBuf));

    if ( NULL == ( m_pvStack = Stack_Create(sizeof(acTempBuf), 500)) )
    {
        my_error("failed to create stack!\r\n");
        goto error;
    }

    while ( 1 == SkillsCode_ReadFile(acTempBuf, 1, 1, pfBinHandle) )
    {
        acTempBuf[1] = SINGLE_OPERATER_LEVEL;
        switch ( acTempBuf[0] )
        {
            case 0x04:
            case 0x07:
                //byte型数据
                if ( 1 != SkillsCode_ReadFile(&acTempBuf[STACK_HEAD], 1, sizeof(unsigned char), pfBinHandle) )
                {
                    my_error("invalid tag %x\r\n", acTempBuf[0]);
                    goto error;
                }
                Stack_Push(m_pvStack, acTempBuf, STACK_HEAD + sizeof(unsigned char));
                break;

            case 0x08:
                //short型数据
                if ( 2 != SkillsCode_ReadFile(&acTempBuf[STACK_HEAD], 1, sizeof(unsigned short), pfBinHandle) )
                {
                    my_error("invalid tag %x\r\n", acTempBuf[0]);
                    goto error;
                }
                Stack_Push(m_pvStack, acTempBuf, STACK_HEAD + sizeof(unsigned short));
                break;

            case 0x09:
                //int型数据
                if ( 4 != SkillsCode_ReadFile(&acTempBuf[STACK_HEAD], 1, sizeof(unsigned int), pfBinHandle) )
                {
                    my_error("invalid tag %x\r\n", acTempBuf[0]);
                    goto error;
                }
                Stack_Push(m_pvStack, acTempBuf, STACK_HEAD + sizeof(unsigned int));
                break;

            case 0x00:
                //表达式结束

                if ( Stack_GetIndex(m_pvStack) > 1 )
                {
                    my_printf("  Expression %u is missing some operators\r\n", m_uiSkillCodeCount);

                    while ( Stack_GetIndex(m_pvStack) > 1 )
                    {
                        // Try to save as much data as posible, and also preserve size of original expression
                        memset(acTempBuf, 0, sizeof(acTempBuf));
                        SkillsCode_TwoOprandProc("  ", SINGLE_OPERATER_LEVEL, EN_OPERATER_ARG_2, EN_OPERATER_LEFT, acTempBuf, sizeof(acTempBuf));
                    }
                }

                Stack_Pop(m_pvStack, &pcTemp);

                if ( 0 == SkillsCode_OutputExpression(pcTemp) )
                {
                    my_error("save expression fail\r\n");
                    goto error;
                }
                break;

            case 0x01:
                if ( 1 != SkillsCode_ReadFile(&acTempBuf[1], 1, 1, pfBinHandle) )
                {
                    my_error("invalid tag %x\r\n", acTempBuf[0]);
                    goto error;
                }

                result = 0;
                bOperater = acTempBuf[1];
                memset(acTempBuf, 0, sizeof(acTempBuf));
                if ( 0x03 == bOperater )
                {
                    //skill(xxx)
                    result = SkillsCode_TwoArgFuncProc("skill", ".", acTempBuf, sizeof(acTempBuf),
                        SkillsCode_SkillArg1Proc, SkillsCode_SkillArg2Proc);
                }
                else if ( 0x00 == bOperater )
                {
                    //min(xxx)
                    result = SkillsCode_TwoArgFuncProc("min", ",", acTempBuf, sizeof(acTempBuf), NULL, NULL);
                }
                else if ( 0x01 == bOperater )
                {
                    //max(xxx)
                    result = SkillsCode_TwoArgFuncProc("max", ",", acTempBuf, sizeof(acTempBuf), NULL, NULL);
                }
                else if ( 0x05 == bOperater )
                {
                    //stat(xxx)
                    result = SkillsCode_TwoArgFuncProc("stat", ".", acTempBuf, sizeof(acTempBuf),
                        SkillsCode_StatArg1Proc, SkillsCode_StatArg2Proc);
                }
                else if ( 0x02 == bOperater )
                {
                    //rand(xxx)
                    result = SkillsCode_TwoArgFuncProc("rand", ",", acTempBuf, sizeof(acTempBuf), NULL, NULL);
                }
                else if ( 0x04 == bOperater )
                {
                    //miss(xxx)
                    result = SkillsCode_TwoArgFuncProc("miss", ".", acTempBuf, sizeof(acTempBuf),
                        SkillsCode_MissArg1Proc, SkillsCode_MissArg2Proc);
                }
                else if ( 0x06 == bOperater )
                {
                    //sklvl(xxx)
                    result = SkillsCode_ThreeArgFuncProc("sklvl", ".", ".", acTempBuf, sizeof(acTempBuf),
                        SkillsCode_SkLvlArg1Proc, SkillsCode_SkLvlArg2Proc, SkillsCode_SkLvlArg3Proc);
                }

                if ( 0 == result )
                {
                    my_error("unknown tag2 %x in expression %u\r\n", bOperater, m_uiSkillCodeCount);
                    goto error;
                }
                break;

            default:
                if ( 0 == SkillsCode_OperaterProc(acTempBuf[0]) )
                {
                    my_error("proc operater %x fail in expression %u\r\n", acTempBuf[0], m_uiSkillCodeCount);
                    //goto error;
                }
                break;
        }
    }

    //写回bin文件
    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);
    for ( i = 0; i < m_uiSkillCodeCount; i++ )
    {
        sprintf(m_acGlobalBuffer, "%u\t%s\r\n\t", i, m_astSkillCode[i].acExpressionTxt);

        for ( j = 0; j < m_astSkillCode[i].uiBinLen; j++ )
        {
            sprintf(&m_acGlobalBuffer[strlen(m_acGlobalBuffer)], "%02x ", m_astSkillCode[i].acExpressionBin[j]);
        }

        strcpy(&m_acGlobalBuffer[strlen(m_acGlobalBuffer)], "\r\n");

        fwrite(m_acGlobalBuffer, 1, strlen(m_acGlobalBuffer), pfOutputHandle);
        memset(m_acGlobalBuffer, 0, strlen(m_acGlobalBuffer));
    }

    goto out;

error:
    SkillsCode_PrintHex();

    if ( 0 < m_uiSkillCodeCount )
    {
        my_error("last expression: %s\r\n", m_astSkillCode[m_uiSkillCodeCount - 1].acExpressionTxt);
        m_uiSkillCodeCount--;
    }
    if ( 0 < m_uiSkillCodeCount )
    {
        my_error("last expression: %s\r\n", m_astSkillCode[m_uiSkillCodeCount - 1].acExpressionTxt);
        m_uiSkillCodeCount--;
    }
    if ( 0 < m_uiSkillCodeCount )
    {
        my_error("last expression: %s\r\n", m_astSkillCode[m_uiSkillCodeCount - 1].acExpressionTxt);
        m_uiSkillCodeCount--;
    }

    result = 0;

out:
    Stack_Release(m_pvStack);

    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
        pfBinHandle = NULL;
    }
    if ( NULL != pfOutputHandle )
    {
        fclose(pfOutputHandle);
        pfOutputHandle = NULL;
    }

    if ( 0 == result )
    {
        my_error("parsing %s.bin failed!\r\n", FILE_PREFIX);
    }
    else
    {
        my_printf("parsing %s.bin success with %d lines!\r\n", FILE_PREFIX, m_uiSkillCodeCount);
    }

    return result;
}

char *SkillsCode_GetExpression(unsigned int id)
{
    unsigned int i;
    unsigned int uiOffset = 0;

    if ( 0xFFFFFFFF <= id )
    {
        return NULL;
    }

    for ( i = 0; i < m_uiSkillCodeCount; i++ )
    {
        if ( uiOffset == id)
        {
            return m_astSkillCode[i].acExpressionTxt;
        }

        uiOffset += m_astSkillCode[i].uiBinLen;
    }

    return NULL;
}

int process_skillscode(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skillcalc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misscalc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            return SkillsCode_ParseBin(acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}
#include "global.h"

static clock_t m_iStartTick = 0;
static clock_t m_iEndTick = 0;
#define START_TICK \
    m_iStartTick = clock()
#define CALC_TICK \
    do {\
        m_iEndTick = clock();\
        printf("duration: %u ms\r\n", m_iEndTick - m_iStartTick);\
    } while (0)

char m_acGlobalBuffer[m_iGlobaBufLength] = {0};
char m_acLineInfoBuf[m_iLineBufLength] = {0};
char m_acValueMapBuf[m_iValueBufLength] = {0};
unsigned int m_iValueMapIndex = 0;

ST_CALLBACK m_stCallback;

static char m_acTempBuffer[m_iGlobaBufLength] = {0};

unsigned int Global_GetValueMapCount()
{
    return m_iValueMapIndex;
}

int File_GetFileSize(char *pcFileName)
{
    int iresult;
    struct _stat buf;

    iresult = _stat(pcFileName, &buf);
    if ( iresult == 0 )
    {
        return buf.st_size;
    }

    return 0;
}

int File_CopyFile(char *pcFromPath, char *pcToPath, char *pcFileName, char *pcSuffix)
{
    memset(m_acTempBuffer, 0, sizeof(m_acTempBuffer));
    sprintf(m_acTempBuffer, "copy /y %s\\%s%s %s\\%s%s >NUL", pcFromPath, pcFileName, pcSuffix, pcToPath, pcFileName, pcSuffix);
    return 0 == system(m_acTempBuffer);
}


int File_MergeFiles(char *acBinPath, char *pcFile1, int iSize1, char *pcFile2, int iSize2, char *pcOutFile)
{
    int result = 1;
    unsigned int iLineCount;
    FILE *pfBinHandle = NULL;
    FILE *pfBin2Handle = NULL;
    FILE *pfOutputHandle = NULL;
    char *pcTemp;

    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, pcFile1);
    pfBinHandle = fopen(m_acGlobalBuffer, "rb");

    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, pcFile2);
    pfBin2Handle = fopen(m_acGlobalBuffer, "rb");

    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, pcOutFile);
    pfOutputHandle = fopen(m_acGlobalBuffer, "wb");

    if ( NULL == pfBinHandle || NULL == pfBin2Handle || NULL == pfOutputHandle )
    {
        my_printf("failed to merge %s and %s to %s\r\n", pcFile1, pcFile2, pcOutFile);
        goto error;
    }

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);

    //读取bin文件的文件头
    fread(&iLineCount, 1, sizeof(iLineCount), pfBinHandle);
    fread(m_acGlobalBuffer, 1, sizeof(iLineCount), pfBin2Handle);

    pcTemp = &m_acGlobalBuffer[sizeof(iLineCount)];
    while ( 0 < iLineCount )
    {
        fread(pcTemp, 1, iSize1, pfBinHandle);
        pcTemp += iSize1;

        fread(pcTemp, 1, iSize2, pfBin2Handle);
        pcTemp += iSize2;

        iLineCount--;
    }

    //写回bin文件
    fwrite(m_acGlobalBuffer, 1, pcTemp - m_acGlobalBuffer, pfOutputHandle);

    goto out;

error:
    result = 0;

out:
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
        pfBinHandle = NULL;
    }
    if ( NULL != pfBin2Handle )
    {
        fclose(pfBin2Handle);
        pfBin2Handle = NULL;
    }
    if ( NULL != pfOutputHandle )
    {
        fclose(pfOutputHandle);
        pfOutputHandle = NULL;
    }

    return result;
}

unsigned char *String_Trim(unsigned char *pcValue)
{
    int j;

    for ( j = (int)strlen(pcValue) - 1; j >= 0; j-- )
    {
        if ( ' ' != pcValue[j] )
        {
            break;
        }

        pcValue[j] = 0;
    }

    return pcValue;
}

void String_RestoreSpecialChar( char *key, char *acOutput )
{
    while ( *key )
    {
        if ( !strncmp(key, "mysp", strlen("mysp")) )
        {
            key += strlen("mysp");
            *acOutput = ' ';
            acOutput++;

        }
        else if ( !strncmp(key, "mypoint", strlen("mypoint")) )
        {
            key += strlen("mypoint");
            *acOutput = '.';
            acOutput++;
        }
        else if ( !strncmp(key, "mysub", strlen("mysub")) )
        {
            key += strlen("mysub");
            *acOutput = '-';
            acOutput++;
        }
        else if ( !strncmp(key, "myslash", strlen("myslash")) )
        {
            key += strlen("myslash");
            *acOutput = '/';
            acOutput++;
        }
        else if ( !strncmp(key, "mybr1", strlen("mybr1")) )
        {
            key += strlen("mybr1");
            *acOutput = '(';
            acOutput++;

        }
        else if ( !strncmp(key, "mybr2", strlen("mybr2")) )
        {
            key += strlen("mybr2");
            *acOutput = ')';
            acOutput++;

        }
        else if ( !strncmp(key, "myast", strlen("myast")) )
        {
            key += strlen("myast");
            *acOutput = '*';
            acOutput++;

        }
        else if ( !strncmp(key, "myqm", strlen("myqm")) )
        {
            key += strlen("myqm");
            *acOutput = '?';
            acOutput++;

        }
        else
        {
            *acOutput = *key;
            key++;
            acOutput++;
        }
    }
    *acOutput = 0;
}

static int String_ReplaceSpecialChar(char *key, char *acTempKey)
{
    int i, j;

    for ( i = 0, j = 0; i < (int)strlen(key); i++ )
    {
        if ( ' ' == key[i] )
        {
            strcpy(&acTempKey[j], "mysp");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '.' == key[i] )
        {
            strcpy(&acTempKey[j], "mypoint");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '-' == key[i] )
        {
            strcpy(&acTempKey[j], "mysub");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '/' == key[i] )
        {
            strcpy(&acTempKey[j], "myslash");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '(' == key[i] )
        {
            strcpy(&acTempKey[j], "mybr1");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( ')' == key[i] )
        {
            strcpy(&acTempKey[j], "mybr2");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '*' == key[i] )
        {
            strcpy(&acTempKey[j], "myast");
            j += (int)strlen(&acTempKey[j]);
        }
        else if ( '?' == key[i] )
        {
            strcpy(&acTempKey[j], "myqm");
            j += (int)strlen(&acTempKey[j]);
        }
        else
        {
            acTempKey[j] = key[i];
            j++;
        }
    }
    acTempKey[j] = 0;

    return j;
}

int process_value(ENUM_VALUE_TYPE enValueType, int iValueLen, void *pvValue, char *acOutput)
{
    int result = 1;

    if ( EN_VALUE_INT == enValueType )
    {
        int iVal = *(int *)pvValue;
        if ( iVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", iVal);
        }
    }
    else if ( EN_VALUE_UINT == enValueType )
    {
        unsigned int uiVal = *(unsigned int *)pvValue;
        if ( uiVal || g_iPrintZero )
        {
            sprintf(acOutput, "%u", uiVal);
        }
    }
    else if ( EN_VALUE_SHORT == enValueType )
    {
        short sVal = *(short *)pvValue;
        if ( sVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", sVal);
        }
    }
    else if ( EN_VALUE_USHORT == enValueType )
    {
        unsigned short usVal = *(unsigned short *)pvValue;
        if ( usVal || g_iPrintZero )
        {
            sprintf(acOutput, "%u", usVal);
        }
    }
    else if ( EN_VALUE_CHAR == enValueType )
    {
        char cVal = *(char *)pvValue;
        if ( cVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", cVal);
        }
    }
    else if ( EN_VALUE_UCHAR == enValueType )
    {
        unsigned char ucVal = *(unsigned char *)pvValue;
        if ( ucVal || g_iPrintZero )
        {
            sprintf(acOutput, "%u", ucVal);
        }
    }
    else if ( EN_VALUE_UINT_BIT == enValueType )
    {
        char bVal = ((*(unsigned int *)pvValue) & (1 << iValueLen)) != 0;
        if ( bVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", bVal);
        }
    }
    else if ( EN_VALUE_USHORT_BIT == enValueType )
    {
        char bVal = ((*(unsigned short *)pvValue) & (1 << iValueLen)) != 0;
        if ( bVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", bVal);
        }
    }
    else if ( EN_VALUE_UCHAR_BIT == enValueType )
    {
        char bVal = ((*(unsigned char *)pvValue) & (1 << iValueLen)) != 0;
        if ( bVal || g_iPrintZero )
        {
            sprintf(acOutput, "%d", bVal);
        }
    }
    else if ( EN_VALUE_STRING == enValueType )
    {
        strncpy(acOutput, pvValue, iValueLen);
        result = -1;
    }
    else if ( EN_VALUE_EOL == enValueType )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;
    }
    else
    {
        char *pcResult = NULL;
        unsigned int uiValue = 0;
        if ( iValueLen == 1 )
        {
            uiValue = *(unsigned char *)pvValue;
            uiValue = uiValue == 0xFF ? -1 : uiValue;
        }
        else if ( iValueLen == 2 )
        {
            uiValue = *(unsigned short *)pvValue;
            uiValue = uiValue == 0xFFFF ? -1 : uiValue;
        }
        else if ( iValueLen == 4 )
        {
            uiValue = *(unsigned int *)pvValue;
            uiValue = uiValue == 0xFFFFFFFF ? -1 : uiValue;
        }

        if ( EN_VALUE_ITEMCODE == enValueType )
        {
            pcResult = ItemsCode_GetExpression(uiValue);
        }
        else if ( EN_VALUE_MISSCODE == enValueType )
        {
            pcResult = MissCode_GetExpression(uiValue);
        }
        else if ( EN_VALUE_SKILLCODE == enValueType )
        {
            pcResult = SkillsCode_GetExpression(uiValue);
        }
        else if ( EN_VALUE_DESCCODE == enValueType )
        {
            pcResult = SkillDescCode_GetExpression(uiValue);
        }
        else if ( EN_VALUE_ITEM == enValueType )
        {
            pcResult = Lookup_Item(uiValue);
        }
        else if ( EN_VALUE_EVENT == enValueType )
        {
            pcResult = Lookup_Event(uiValue);
        }
        else if ( EN_VALUE_ITEMSTAT == enValueType )
        {
            pcResult = Lookup_ItemStatCost(uiValue);
        }
        else if ( EN_VALUE_ITEMTYPE == enValueType )
        {
            pcResult = Lookup_ItemType(uiValue);
        }
        else if ( EN_VALUE_MISSILE == enValueType )
        {
            pcResult = Lookup_Missile(uiValue);
        }
        else if ( EN_VALUE_MONAI == enValueType )
        {
            pcResult = Lookup_MonAI(uiValue);
        }
        else if ( EN_VALUE_MONPROP == enValueType )
        {
            pcResult = Lookup_MonProp(uiValue);
        }
        else if ( EN_VALUE_MONSEQ == enValueType )
        {
            pcResult = Lookup_MonSeq(uiValue);
        }
        else if ( EN_VALUE_MONSOUND == enValueType )
        {
            pcResult = Lookup_MonSounds(uiValue);
        }
        else if ( EN_VALUE_MONSTAT == enValueType )
        {
            pcResult = Lookup_MonStats(uiValue);
        }
        else if ( EN_VALUE_MONSTAT2 == enValueType )
        {
            pcResult = Lookup_MonStats2(uiValue);
        }
        else if ( EN_VALUE_MONTYPE == enValueType )
        {
            pcResult = Lookup_MonType(uiValue);
        }
        else if ( EN_VALUE_OVERLAY == enValueType )
        {
            pcResult = Lookup_Overlay(uiValue);
        }
        else if ( EN_VALUE_PROPERTY == enValueType )
        {
            pcResult = Lookup_Property(uiValue);
        }
        else if ( EN_VALUE_SET == enValueType )
        {
            pcResult = Lookup_Set(uiValue);
        }
        else if ( EN_VALUE_SKILLDESC == enValueType )
        {
            pcResult = Lookup_SkillDesc(uiValue);
        }
        else if ( EN_VALUE_SKILL == enValueType )
        {
            pcResult = Lookup_Skill(uiValue);
        }
        else if ( EN_VALUE_SOUND == enValueType )
        {
            pcResult = Lookup_Sound(uiValue);
        }
        else if ( EN_VALUE_SUPERUNIQUE == enValueType )
        {
            pcResult = Lookup_SuperUnique(uiValue);
        }
        else if ( EN_VALUE_STATE == enValueType )
        {
            pcResult = Lookup_State(uiValue);
        }
        else if ( EN_VALUE_TBL_STRING == enValueType )
        {
            pcResult = String_FindString(uiValue, "dummy", NULL);
            result = -1;
        }
        else if ( EN_VALUE_TBL_STRING2 == enValueType )
        {
            pcResult = String_FindString(uiValue, "dummy", "x");
            result = -1;
        }
        else if ( EN_VALUE_TREASURE == enValueType )
        {
            pcResult = Lookup_TreasureClass(uiValue);
        }
        else if ( EN_VALUE_BODYLOC == enValueType )
        {
            pcResult = Lookup_BodyLoc(uiValue);
        }
        else if ( EN_VALUE_COLOR == enValueType )
        {
            pcResult = Lookup_Color(uiValue);
        }
        else if ( EN_VALUE_ELEMTYPE == enValueType )
        {
            pcResult = Lookup_ElemType(uiValue);
        }
        else if ( EN_VALUE_HIREDESC == enValueType )
        {
            pcResult = Lookup_HireDesc(uiValue);
        }
        else if ( EN_VALUE_HITCLASS == enValueType )
        {
            pcResult = Lookup_HitClass(uiValue);
        }
        else if ( EN_VALUE_PET == enValueType )
        {
            pcResult = Lookup_Pet(uiValue);
        }
        else if ( EN_VALUE_CLASS == enValueType )
        {
            pcResult = Lookup_Class(uiValue);
        }
        else if ( EN_VALUE_PLRMODE == enValueType )
        {
            pcResult = Lookup_PlrMode(uiValue);
        }
        else if ( EN_VALUE_MONMODE == enValueType )
        {
            pcResult = Lookup_MonMode(uiValue);
        }
        else if ( EN_VALUE_STORE == enValueType )
        {
            pcResult = Lookup_Store(uiValue);
        }
        else if ( EN_VALUE_LEVEL == enValueType )
        {
            pcResult = Lookup_Level(uiValue);
        }

        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
    }

    return result;
}

/*
合并字段内容:
1、对表头的字段名进行转换，关联到结构体的字段名，空格符在字段变量名中用mysp替代
2、如果bin文件里有定义的话，就用bin里边的值
3、否则用模板里的内容
4、清除值字段末尾的所有空格
*/
static char * TXTBUF_FILL(char *key, ST_VALUE_MAP *map, int count, char *start, char *from,
    ST_CALLBACK *callback, void *pvLineInfo, int iLineNo, int iFieldNo)
{
    int i, iValResult;
    static char acTempKey[1024] = {0};
    static char acTempValue[1024] = {0};

    //1、对表头的字段名进行转换，关联到结构体的字段名，空格符在字段变量名中用mysp替代
    String_ReplaceSpecialChar(key, acTempKey);

    for ( i = 0; i < count; i++ )
    {
        if ( stricmp(acTempKey, map[i].acKeyName) )
        {
            continue;
        }

        //2、如果bin文件里有定义的话，就用bin里边的值
        if ( 0 < iFieldNo )
        {
            *start = '\t';
            start++;
        }
        memset(acTempValue, 0, sizeof(acTempValue));

        if ( !callback || !callback->pfnConvertValue || !(iValResult = callback->pfnConvertValue(pvLineInfo, key, iLineNo, from, acTempValue)))
        {
            iValResult = process_value(map[i].enValueType, map[i].iValueLen, map[i].pvValue, acTempValue);
        }

        if ( iValResult && acTempValue[0] != 0 )
        {
            if ( iValResult != -1 )
            {
                String_Trim(acTempValue);
            }
            strcpy(start, acTempValue);
            start += strlen(start);
        }

        break;
    }

    //3、否则用模板里的内容
    if ( i >= count )
    {
        if ( 0 < iFieldNo )
        {
            *start = '\t';
            start++;
        }
        if ( !callback || !callback->pfnFieldProc || 0 == callback->pfnFieldProc(pvLineInfo, key, iLineNo, from, start) )
        {
            strcpy(start, from);
        }
        start += strlen(start);
    }

    return start;
}

static int process_line_x(char *pcHeader, char *pcLineEnd, char *pcLineStart, char *pcTxt, char *acClass,
    void *pvLineInfo, ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback, int iLineNo)
{
    char *pcAnchor, *pcAnchor2, *pcAnchorTemp;
    char bAnchor, bAnchor2;
    int result = 1;
    int i = 0;

    //逐字段处理
    do
    {
        //找到表头字段尾，tab键和回车换行，先到为准
        pcAnchor = strchr(pcHeader, '\t');
        pcAnchorTemp = strchr(pcHeader, '\r');
        if ( pcAnchor && pcAnchorTemp )
        {
            if ( pcAnchor < pcAnchorTemp )
            {
                bAnchor = '\t';
            }
            else
            {
                pcAnchor = pcAnchorTemp;
                bAnchor = '\r';
            }
        }
        else if ( pcAnchor && !pcAnchorTemp )
        {
            bAnchor = '\t';
        }
        else if ( !pcAnchor && pcAnchorTemp )
        {
            pcAnchor = pcAnchorTemp;
            bAnchor = '\r';
        }
        else
        {
            my_error("%s fail1 at %s\r\n", acClass, pcHeader);
            result = 0;
            break;
        }

        //找到内容行的字段尾，tab键和回车换行，先到为准
        pcAnchor2 = strchr(pcLineStart, '\t');
        pcAnchorTemp = strchr(pcLineStart, '\r');
        if ( pcAnchor2 && pcAnchorTemp )
        {
            if ( pcAnchor2 < pcAnchorTemp )
            {
                bAnchor2 = '\t';
            }
            else
            {
                pcAnchor2 = pcAnchorTemp;
                bAnchor2 = '\r';
            }
        }
        else if ( pcAnchor2 && !pcAnchorTemp )
        {
            bAnchor2 = '\t';
        }
        else if ( !pcAnchor2 && pcAnchorTemp )
        {
            pcAnchor2 = pcAnchorTemp;
            bAnchor2 = '\r';
        }
        else
        {
            my_error("%s fail2 at %s\r\n", acClass, pcHeader);
            result = 0;
            break;
        }

        *pcAnchor = 0;
        *pcAnchor2 = 0;

        //合并该字段的内容
        pcTxt = TXTBUF_FILL(pcHeader, astValueMap, iCount, pcTxt, pcLineStart, pstCallback, pvLineInfo, iLineNo, i);

        *pcAnchor = bAnchor;
        *pcAnchor2 = bAnchor2;
    } while ( (pcHeader = strchr(pcHeader, '\t')) && (pcLineStart = strchr(pcLineStart, '\t'))
            && pcHeader < pcLineEnd && pcHeader++ && pcLineStart++ && ++i );

    //一行结束，加上回车换行
    *pcTxt = '\r';
    pcTxt++;
    *pcTxt = '\n';
    pcTxt++;

    if ( NULL != pcHeader && pcHeader < pcLineEnd )
    {
        my_error("%s fai1 at lineend\r\n", acClass);
        result = 0;
    }

    return result;
}

static int Find_StringInList(char **ppcList, char *pcLookup)
{
    int i = 0;

    if ( !ppcList || !pcLookup )
    {
        return -1;
    }

    while ( NULL != ppcList[i] )
    {
        if ( !stricmp(pcLookup, ppcList[i]) )
        {
            return i;
        }

        i++;
    }

    return -1;
}

//检查哪些字段在bin文件中没有读取出来的
static int check_template(char *pcHeader, char *pcLineEnd, ST_VALUE_MAP *astValueMap, int iCount, char *pcFileName, ST_CALLBACK *pstCallback)
{
    char *pcAnchor, *pcAnchorTemp;
    char bAnchor;
    int result = 1;
    int i, j;
    char acTempKey[256] = {0};
    int iIntKeys = 0;

    m_acTempBuffer[0] = 0;
    //逐字段处理
    do
    {
        //找到表头字段尾，tab键和回车换行，先到为准
        pcAnchor = strchr(pcHeader, '\t');
        pcAnchorTemp = strchr(pcHeader, '\r');
        if ( pcAnchor && pcAnchorTemp )
        {
            if ( pcAnchor < pcAnchorTemp )
            {
                bAnchor = '\t';
            }
            else
            {
                pcAnchor = pcAnchorTemp;
                bAnchor = '\r';
            }
        }
        else if ( pcAnchor && !pcAnchorTemp )
        {
            bAnchor = '\t';
        }
        else if ( !pcAnchor && pcAnchorTemp )
        {
            pcAnchor = pcAnchorTemp;
            bAnchor = '\r';
        }
        else
        {
            my_error("invalid head at %s of %s\r\n", pcHeader, pcFileName);
            result = 0;
            break;
        }

        *pcAnchor = 0;

        //检查字段是否存在
        String_ReplaceSpecialChar(pcHeader, acTempKey);
        for ( i = 0; i < iCount; i++ )
        {
            if ( !stricmp(acTempKey, astValueMap[i].acKeyName) )
            {
                astValueMap[i].iActiveColumn = 0;
                break;
            }
        }
        if ( i >= iCount )
        {
            int iColumn;
            if ( pstCallback && (iColumn = Find_StringInList(pstCallback->ppcKeyInternalProcess, pcHeader)) != -1 )
            {
                iIntKeys |= (1 << iColumn);
                //已被内部处理
            }
            else if ( pstCallback && Find_StringInList(pstCallback->ppcKeyNotUsed, pcHeader) != -1 )
            {
                if ( !g_iCompactOutput )
                {
                    sprintf(&m_acTempBuffer[strlen(m_acTempBuffer)], "  Not Used Field: %s\r\n", pcHeader);
                }
            }
            else if ( pstCallback && Find_StringInList(pstCallback->ppcKeyNotParsed, pcHeader) != -1 )
            {
                sprintf(&m_acTempBuffer[strlen(m_acTempBuffer)], "  Not Parsed Field: %s\r\n", pcHeader);
            }
            else
            {
                sprintf(&m_acTempBuffer[strlen(m_acTempBuffer)], "  Unknown Field: %s\r\n", pcHeader);
            }
        }

        *pcAnchor = bAnchor;
    } while ( (pcHeader = strchr(pcHeader, '\t')) && pcHeader < pcLineEnd && pcHeader++ );

    if ( pstCallback && pstCallback->ppcKeyInternalProcess )
    {
        for ( i = 0; NULL != pstCallback->ppcKeyInternalProcess[i]; i++ )
        {
            if ( (iIntKeys & (1 << i)) == 0 )
            {
                sprintf(&m_acTempBuffer[strlen(m_acTempBuffer)], "  Missing Field: %s\r\n", pstCallback->ppcKeyInternalProcess[i]);
            }
        }
    }
    for ( i = 0; i < iCount; i++ )
    {
        if ( astValueMap[i].iActiveColumn )
        {
            int iAliasColumn = 0;
            for ( j = 0; j < iCount; j++ ) {
                if ( j == i )
                {
                    continue;
                }
                if ( astValueMap[i].pvValue == astValueMap[j].pvValue && astValueMap[i].iValueLen == astValueMap[j].iValueLen && !astValueMap[j].iActiveColumn )
                {
                    iAliasColumn = 1;
                    break;
                }
            }
            if ( !iAliasColumn )
            {
                char acField[128] = {0};
                String_RestoreSpecialChar(astValueMap[i].acKeyName, acField);
                sprintf(&m_acTempBuffer[strlen(m_acTempBuffer)], "  Missing Field: %s\r\n", acField);
            }
        }
    }

    if ( m_acTempBuffer[0] )
    {
        my_printf("%s.txt template:\r\n%s", pcFileName, m_acTempBuffer);
    }

    return result;
}

static int process_line_withkey(char *acTplBuf, char *acTxtBuf, void *pvLineInfo, int iLineLength,
    char *acClass, int iKeyLen, ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback, int iLineNo)
{
    char acKey[256] = {0};
    char *pcHeader;
    char *pcLineStart;
    char *pcLineEnd;
    char *pcTxt;
    int result = 1;

    //找到txt文件尾
    pcTxt = acTxtBuf + strlen(acTxtBuf);

    //找到模板文件的第一行，即表头
    pcHeader = acTplBuf;
    pcLineEnd = strchr(pcHeader, '\r');
    if ( !pcLineEnd )
    {
        my_error("%s fail at lineend\r\n", acClass);
        return 0;
    }

    //找到key所在的那一行模板
    sprintf(acKey, "\n%s\t", acClass);
    pcLineStart = strstr(acTplBuf, acKey);
    if ( !pcLineStart )
    {
        sprintf(acKey, "\n%s\r", acClass);
        pcLineStart = strstr(acTplBuf, acKey);
#if 0
        //暂时只能支持顶头的key
        if ( !pcLineStart )
        {
            sprintf(acKey, "\t%s\t", acClass);
            pcLineStart = strstr(acTplBuf, acKey);
            if ( !pcLineStart )
            {
                sprintf(acKey, "\t%s\r", acClass);
                pcLineStart = strstr(acTplBuf, acKey);
            }
        }
#endif
    }

    if ( !pcLineStart )
    {
        int i = 0;

        //如果没有该key，则说明是bin文件比模板文件多出来的内容，构造一行空模板行便于后续处理
        pcLineStart = pcHeader;

        while ( pcLineStart != pcLineEnd )
        {
            if ( '\t' == *pcLineStart )
            {
                m_acTempBuffer[i] = *pcLineStart;
                i++;
            }

            pcLineStart++;
        }
        m_acTempBuffer[i] = '\r';
        i++;
        m_acTempBuffer[i] = '\n';
        pcLineStart = m_acTempBuffer;
    }
    else
    {
        //跳过'\r'
        while ( '\n' != *pcLineStart )
        {
            pcLineStart--;
        }
        pcLineStart++;
    }

    return process_line_x(pcHeader, pcLineEnd, pcLineStart, pcTxt, acClass, pvLineInfo, astValueMap, iCount, pstCallback, iLineNo);
}

static int process_line_withoutkey(char *acTplBuf, char *acTxtBuf, void *pvLineInfo, int iLineLength, int iLineNo,
    ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback,
    char *pcFilename, char **ppcIterator)
{
    char acClass[256] = {0};
    char *pcHeader;
    char *pcLineStart;
    char *pcLineEnd;
    char *pcTxt;
    char *pcAnchor;
    int result = 1;

    sprintf(acClass, "%d", iLineNo);

    //找到txt文件尾
    pcTxt = acTxtBuf + strlen(acTxtBuf);

    //找到模板文件的第一行，即表头
    pcHeader = acTplBuf;
    pcLineEnd = strchr(pcHeader, '\r');
    if ( !pcLineEnd )
    {
        my_error("%s fail find lineend\r\n", acClass);
        return 0;
    }

    //找到行号对应的行
    if ( NULL == *ppcIterator )
    {
        pcLineStart = acTplBuf;
    }
    else
    {
        pcLineStart = *ppcIterator;
    }

loop:
    pcAnchor = strstr(pcLineStart, "\r\n");
    if ( !pcAnchor || strlen("\r\n") == strlen(pcAnchor) )
    {
        int j = 0;

        //如果没有下一行了，则说明是bin文件比模板文件多出来的内容，构造一行空模板行便于后续处理
        pcLineStart = pcHeader;

        while ( pcLineStart != pcLineEnd )
        {
            if ( '\t' == *pcLineStart )
            {
                m_acTempBuffer[j] = *pcLineStart;
                j++;
            }

            pcLineStart++;
        }
        m_acTempBuffer[j++] = '\r';
        m_acTempBuffer[j++] = '\n';
        m_acTempBuffer[j] = 0;
        pcLineStart = m_acTempBuffer;
    }
    else
    {
        pcLineStart = pcAnchor + 2;
        *ppcIterator = pcLineStart;
    }

    if ( pcLineStart == strstr(pcLineStart, "Expansion") )
    {
        goto loop;
    }

    return process_line_x(pcHeader, pcLineEnd, pcLineStart, pcTxt, acClass, pvLineInfo, astValueMap, iCount, pstCallback, iLineNo);
}

static int check_bin(void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount, FILE *pfBinHandle, ST_FILE_HEADER stFileHeader)
{
    unsigned int i, j;
    unsigned int iFrom, iTo;

    memset(m_acTempBuffer, 0, iLineLength * 3);

    if ( iLineLength != fread((m_acTempBuffer+iLineLength), 1, iLineLength, pfBinHandle) )
    {
        return 0;
    }

    for ( i = 1; i < stFileHeader.iLines; i++ )
    {
        if ( iLineLength != fread((m_acTempBuffer+iLineLength*2), 1, iLineLength, pfBinHandle) )
        {
            return 0;
        }

        for ( j = 0; j < (unsigned int)iLineLength; j ++ )
        {
            if ( m_acTempBuffer[iLineLength*2+j] > 0x00 && m_acTempBuffer[iLineLength*2+j] < 0xFF
                ||  m_acTempBuffer[iLineLength+j] != m_acTempBuffer[iLineLength*2+j] )
            {
                m_acTempBuffer[j] = 1;
            }
        }
    }

    if ( ((int)fgetc(pfBinHandle)) != EOF )
    {
        return 0;
    }

    fseek(pfBinHandle, sizeof(stFileHeader), SEEK_SET);

    for ( j = 0; j < (unsigned int)iValueCount; j++ )
    {
        iFrom = (unsigned int)pstValueMap[j].pvValue - (unsigned int)pvLineInfo;

        if ( pstValueMap[j].enValueType == EN_VALUE_UCHAR_BIT )
        {
            iFrom += sizeof(unsigned char) - (pstValueMap[j].iValueLen / 8) - 1;
            iTo = iFrom + 1;
        }
        else if ( pstValueMap[j].enValueType == EN_VALUE_USHORT_BIT )
        {
            iFrom += sizeof(unsigned short) - (pstValueMap[j].iValueLen / 8) - 1;
            iTo = iFrom + 1;
        }
        else if ( pstValueMap[j].enValueType == EN_VALUE_UINT_BIT )
        {
            iFrom += sizeof(unsigned int) - (pstValueMap[j].iValueLen / 8) - 1;
            iTo = iFrom + 1;
        }
        else
        {
            iTo = iFrom + pstValueMap[j].iValueLen;
        }

        for ( i = iFrom; i < iTo; i++ )
        {
            if ( m_acTempBuffer[i] )
            {
                pstValueMap[j].iActiveColumn = 1;
                break;
            }
        }
    }

    return 1;
}

int getBinStructSize(char *acBinPath, char *pcFilename)
{
    char acBinFile[256] = {0};
    unsigned int iBinLineSize = 0;

    FILE *pfBinHandle = NULL;
    ST_FILE_HEADER stFileHeader;

    sprintf(acBinFile, "%s\\%s.bin", acBinPath, pcFilename);
    pfBinHandle = fopen(acBinFile, "rb");

    if ( !pfBinHandle || (sizeof(stFileHeader) != fread(&stFileHeader, 1, sizeof(stFileHeader), pfBinHandle)) )
    {
        goto out;
    }

    fseek(pfBinHandle, 0, SEEK_END);
    iBinLineSize = (ftell(pfBinHandle) - sizeof(stFileHeader)) / stFileHeader.iLines;

out:
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
    }
    return iBinLineSize;
}

static int process_file_x(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback, char *pcBinSplitter)
{
    static char acTemplateFile[256] = {0};
    static char acBinFile[256] = {0};
    static char acTxtFile[256] = {0};
    static char acTplBuf[MAX_FILE_SIZE] = {0};
    static char acTxtBuf[MAX_FILE_SIZE] = {0};

    FILE *pfTplHandle = NULL;
    FILE *pfBinHandle = NULL;
    FILE *pfTxtHandle = NULL;

    ST_FILE_HEADER stFileHeader;
    unsigned int i, iSuccess, iFailed;
    char *pcKey;
    char *pcIterator = NULL;
    int result = 1;

    char *pcExpansion = NULL;
    char *pcAnchor = NULL;
    int iExpansionLine = 0;

    memset(acTemplateFile, 0, sizeof(acTemplateFile));
    memset(acBinFile, 0, sizeof(acBinFile));
    memset(acTxtFile, 0, sizeof(acTxtFile));
    memset(acTplBuf, 0, sizeof(acTplBuf));
    memset(acTxtBuf, 0, sizeof(acTxtBuf));
    memset(m_acGlobalBuffer, 0, sizeof(m_acGlobalBuffer));
    memset(m_acTempBuffer, 0, sizeof(m_acTempBuffer));

    sprintf(acTxtFile, "%s\\%s.txt", acTxtPath, pcFilename);
    sprintf(acTemplateFile, "%s\\%s.txt", acTemplatePath, pcFilename);
    if ( pcBinSplitter )
    {
        sprintf(acBinFile, "%s%s%s.bin", acBinPath, pcBinSplitter, pcFilename);
    }
    else
    {
        sprintf(acBinFile, "%s%s.bin", acBinPath, pcFilename);
    }

    pfBinHandle = fopen(acBinFile, "rb");
    if ( NULL == pfBinHandle )
    {
        if ( pstCallback && pstCallback->eModuleType == EN_MODULE_CORE )
        {
            my_error("open %s bin file fail\r\n", pcFilename);
            goto error;
        }
        else
        {
            if ( !g_iCompactOutput )
            {
                my_printf("%s bin not found, module will be skipped\r\n", pcFilename);
            }
            goto out;
        }
    }

    pfTplHandle = fopen(acTemplateFile, "rb");
    if ( NULL == pfTplHandle )
    {
        char *pcColumn = acTplBuf;

        if ( pstCallback && pstCallback->eModuleType < ( g_iCompactOutput ? EN_MODULE_PLUGIN : EN_MODULE_EXTENSION ) )
        {
            my_printf("%s template not found, auto generated will be used\r\n", pcFilename);
        }

        if ( pstCallback && pstCallback->ppcKeyInternalProcess )
        {
            for ( i = 0; pstCallback->ppcKeyInternalProcess[i] != NULL; i++ )
            {
                String_RestoreSpecialChar(pstCallback->ppcKeyInternalProcess[i], m_acTempBuffer);
                pcColumn += sprintf(pcColumn, "%s\t", m_acTempBuffer);
            }
        }

        for ( i = 0; i < (unsigned int)iValueCount; i++ )
        {
            String_RestoreSpecialChar(pstValueMap[i].acKeyName, m_acTempBuffer);
            pcColumn += sprintf(pcColumn, "%s\t", m_acTempBuffer);
        }

        sprintf(pcColumn - 1, "\r\n");
    }
    else
    {
        //先把整个模板文件读入内存
        if ( 0 >= fread(acTplBuf, 1, sizeof(acTplBuf), pfTplHandle) )
        {
            my_error("read %s template file fail\r\n", pcFilename);
            goto error;
        }
    }

    //读取模板文件的表头，放入txt
    if ( strchr(acTplBuf, '\n') )
    {
        strncpy(acTxtBuf, acTplBuf, (strchr(acTplBuf, '\n') - acTplBuf + 1));
    }
    else
    {
        strcpy(acTxtBuf, acTplBuf);
        sprintf(&acTxtBuf[strlen(acTxtBuf)], "\r\n");
        sprintf(&acTplBuf[strlen(acTplBuf)], "\r\n");
    }

    //找到Expansion行，bin文件里不存在，直接写回txt
    pcExpansion = strstr(acTplBuf, "\r\nExpansion");
    if ( NULL != pcExpansion )
    {
        pcExpansion += strlen("\r\n");
        pcAnchor = acTplBuf;
        while ( (pcAnchor = strchr(pcAnchor, '\r')) )
        {
            if ( strncmp(pcAnchor + 2, "Expansion\t", strlen("Expansion\t")) )
            {
                iExpansionLine++;
                pcAnchor++;
            }
            else
            {
                break;
            }
        }

        pcAnchor = strchr(pcExpansion, '\r');
    }

    //读取bin文件的文件头
    if ( sizeof(stFileHeader) != fread(&stFileHeader, 1, sizeof(stFileHeader), pfBinHandle) )
    {
        my_error("read %s bin file head fail\r\n", pcFilename);
        goto error;
    }

    if ( !check_bin(pvLineInfo, iLineLength, pstValueMap, iValueCount, pfBinHandle, stFileHeader) )
    {
        my_error("%s bin struct check failed\r\n", pcFilename);
        goto error;
    }

    if ( acTxtPath )
    {
        //检查有哪些字段没有处理
        if ( !check_template(acTxtBuf, strchr(acTxtBuf, '\r'), pstValueMap, iValueCount, pcFilename, pstCallback) )
        {
            goto error;
        }

        pfTxtHandle = fopen(acTxtFile, "wb");
        if ( NULL == pfTxtHandle )
        {
            my_error("create %s txt file fail\r\n", pcFilename);
            goto error;
        }
    }

    //通知该模块，bin文件的行数，便于分配内存
    if ( pstCallback && pstCallback->pfnSetLines )
    {
        pstCallback->pfnSetLines(stFileHeader.iLines);
    }

    //轮询bin文件的每一行内容
    iSuccess = 0;
    iFailed = 0;
    for ( i = 0; i < stFileHeader.iLines; i++ )
    {
        if ( NULL != pcExpansion && NULL != pcAnchor && 0 < iExpansionLine && i == iExpansionLine )
        {
            iExpansionLine = 0;
            i--;

            *pcAnchor = 0;
            sprintf(&acTxtBuf[strlen(acTxtBuf)], "%s\r\n", pcExpansion);
            *pcAnchor = '\r';

            continue;
        }

        //从bin文件依次读取一行内容
        if ( iLineLength != fread(pvLineInfo, 1, iLineLength, pfBinHandle) )
        {
            my_error("\r\nread %s bin fail at line %d\r\n", pcFilename, i);
            goto error;
        }

        if ( pstCallback && pstCallback->pfnGetKey )
        {
            int iKeyLen = 0;

            //如果有getkey函数，就表示该文件是有key的，bin文件的这一行内容，直接与模板文件里的每一行进行key匹配，匹配上就合并
            pcKey = pstCallback->pfnGetKey(pvLineInfo, acBinFile, &iKeyLen);
            String_Trim(pcKey);
            if ( 1 != process_line_withkey(acTplBuf, acTxtBuf, pvLineInfo, iLineLength, pcKey, iKeyLen,
                pstValueMap, iValueCount, pstCallback, i) )
            {
                my_error("\r\nprocess %s failed at %s line\r\n", pcFilename, pcKey);
                iFailed++;
            }
            else
            {
                iSuccess++;
            }
        }
        else
        {
            //没有getkey函数，就表示该文件没有key，bin文件和模板文件只能逐行合并
            if ( 1 != process_line_withoutkey(acTplBuf, acTxtBuf, pvLineInfo, iLineLength, i, pstValueMap, iValueCount,
                pstCallback, pcFilename, &pcIterator) )
            {
                my_error("\r\nprocess %s failed at %d line\r\n", pcFilename, i);
                iFailed++;
            }
            else
            {
                iSuccess++;
            }
        }

        if ( 0 == (i % 10) || i == (stFileHeader.iLines - 1))
        {
            my_printf("\r%sprocessed %d of %d entries of %s", (acTxtPath ? "" : "pre-"), i + 1, stFileHeader.iLines, pcFilename);
        }

        //写回txt文件
        if ( acTxtPath )
        {
            fwrite(acTxtBuf, 1, strlen(acTxtBuf), pfTxtHandle);
        }
        memset(acTxtBuf, 0, strlen(acTxtBuf));
    }
    my_printf("\r\n");

    goto out;

error:
    result = 0;

out:
    if ( NULL != pfTplHandle )
    {
        fclose(pfTplHandle);
        pfTplHandle = NULL;
    }
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
        pfBinHandle = NULL;
    }
    if ( NULL != pfTxtHandle )
    {
        fclose(pfTxtHandle);
        pfTxtHandle = NULL;
    }

    //通知该模块释放内存
    //暂时不能释放，因为其他模块还需要查询
    if ( pstCallback && pstCallback->pfnFinished )
    {
        pstCallback->pfnFinished();
    }


    return result;
}

int process_file(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback)
{
    return process_file_x(acTemplatePath, acBinPath, acTxtPath, pcFilename, pvLineInfo,
        iLineLength, pstValueMap, iValueCount, pstCallback, "\\");
}

//bin文件名直接指定
int process_file_special_bin(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback)
{
    return process_file_x(acTemplatePath, acBinPath, acTxtPath, pcFilename, pvLineInfo,
        iLineLength, pstValueMap, iValueCount, pstCallback, NULL);
}


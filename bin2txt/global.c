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
    system(m_acTempBuffer);

    return 1;
}

unsigned char *String_Trim(unsigned char *pcValue)
{
    int j;

    if ( g_iTrimSpace == 0)
    {
        return pcValue;
    }
    else if ( g_iTrimSpace == 1 )
    {
        for ( j = (int)strlen(pcValue) - 1; j >= 0; j-- )
        {
            if ( ' ' != pcValue[j] )
            {
                break;
            }
        }
        if ( j < 0 )
        {
            return pcValue;
        }
    }


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
        else
        {
            acTempKey[j] = key[i];
            j++;
        }
    }
    acTempKey[j] = 0;

    return j;
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
    int i;
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

        if ( !callback || !callback->pfnConvertValue || 0 == callback->pfnConvertValue(pvLineInfo, key, from, acTempValue) )
        {
            if ( EN_VALUE_CHAR == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(char *)map[i].pvValue);
            }
            else if ( EN_VALUE_SHORT == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(short *)map[i].pvValue);
            }
            else if ( EN_VALUE_INT == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(int *)map[i].pvValue);
            }
            else if ( EN_VALUE_UCHAR == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned char *)map[i].pvValue);
            }
            else if ( EN_VALUE_USHORT == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned short *)map[i].pvValue);
            }
            else if ( EN_VALUE_UINT == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned int *)map[i].pvValue);
            }
            else if ( EN_VALUE_BIT == map[i].enValueType && callback && callback->pfnBitProc )
            {
                callback->pfnBitProc(pvLineInfo, key, acTempValue);
            }
            else if ( EN_VALUE_STRING == map[i].enValueType )
            {
                strncpy(acTempValue, map[i].pvValue, map[i].iValueLen);
            }
            else if ( EN_VALUE_UINT_ITEM == map[i].enValueType )
            {
                char *pcResult = Misc_GetItemUniqueCode(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UINT_ITEMCODE == map[i].enValueType )
            {
                char *pcResult = ItemsCode_GetExpression(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UINT_MISSCODE == map[i].enValueType )
            {
                char *pcResult = MissCode_GetExpression(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UINT_SKILLCODE == map[i].enValueType )
            {
                char *pcResult = SkillsCode_GetExpression(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UINT_DESCCODE == map[i].enValueType )
            {
                char *pcResult = SkillDescCode_GetExpression(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UINT_PROPERTY == map[i].enValueType )
            {
                char *pcResult = Properties_GetProperty(*(unsigned int *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_EVENT == map[i].enValueType )
            {
                char *pcResult = Events_GetEventName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_ITEMTYPE == map[i].enValueType )
            {
                char *pcResult = ItemTypes_GetItemCode(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_ITEMSTAT == map[i].enValueType )
            {
                char *pcResult = ItemStatCost_GetStateName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MISSILE == map[i].enValueType )
            {
                char *pcResult = Missiles_GetMissile(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONAI == map[i].enValueType )
            {
                char *pcResult = MonAi_GetAiName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONPROP == map[i].enValueType )
            {
                char *pcResult = MonProp_GetPropId(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONSOUND == map[i].enValueType )
            {
                char *pcResult = MonSounds_GetItemSoundsCode(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONSTAT == map[i].enValueType )
            {
                char *pcResult = MonStats_GetStatsName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONSTAT2 == map[i].enValueType )
            {
                char *pcResult = MonStats2_GetStatsName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_MONTYPE == map[i].enValueType )
            {
                char *pcResult = MonType_GetType(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_OVERLAY == map[i].enValueType )
            {
                char *pcResult = Overlay_GetOverlay(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_SET == map[i].enValueType )
            {
                char *pcResult = Sets_GetSetName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_SKILLDESC == map[i].enValueType )
            {
                char *pcResult = SkillDesc_GetDesc(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_SKILL == map[i].enValueType )
            {
                char *pcResult = Skills_GetSkillName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_STRING == map[i].enValueType )
            {
                char *pcResult = String_FindString(*(unsigned short *)map[i].pvValue, "dummy");
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_STRING2 == map[i].enValueType )
            {
                char *pcResult = String_FindString_2(*(unsigned short *)map[i].pvValue, "dummy", "x");
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_TREASURE == map[i].enValueType )
            {
                char *pcResult = TreasureClassEx_GetItemTreasureClass(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_SOUND == map[i].enValueType )
            {
                char *pcResult = Sounds_GetSoundName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_USHORT_STATE == map[i].enValueType )
            {
                char *pcResult = States_GetStateName(*(unsigned short *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_BODYLOC == map[i].enValueType )
            {
                char *pcResult = BodyLocs_GetLocStr(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_COLOR == map[i].enValueType )
            {
                char *pcResult = Colors_GetColorCode(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_ELEM == map[i].enValueType )
            {
                char *pcResult = ElemTypes_GetElemStr(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_HIREDESC == map[i].enValueType )
            {
                char *pcResult = HireDesc_GetDesc(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_HITCLASS == map[i].enValueType )
            {
                char *pcResult = HitClass_GetClassStr(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_PLRCLASS == map[i].enValueType )
            {
                char *pcResult = PlayerClass_GetClass(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_MONMODE == map[i].enValueType )
            {
                char *pcResult = MonMode_GetCode(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_PLRMODE == map[i].enValueType )
            {
                char *pcResult = PlrMode_GetCode(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_PET == map[i].enValueType )
            {
                char *pcResult = Pettype_GetPetType(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }
            else if ( EN_VALUE_UCHAR_STORE == map[i].enValueType )
            {
                char *pcResult = StorePage_GetCode(*(unsigned char *)map[i].pvValue);
                if ( pcResult )
                {
                    strcpy(acTempValue, pcResult);
                }
            }


            //4、清除值字段末尾的所有空格
            if ( 0 != acTempValue[0] && !('0' == acTempValue[0] && 0 == acTempValue[1] && EN_VALUE_STRING > map[i].enValueType) )
            {
                String_Trim(acTempValue);
                strcpy(start, acTempValue);
                start += strlen(start);
            }
        }
        else
        {
            //4、清除值字段末尾的所有空格
            if ( 0 != acTempValue[0] )
            {
                String_Trim(acTempValue);
                strcpy(start, acTempValue);
                start += strlen(start);
            }
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
        my_error("%s fail1 at lineend\r\n", acClass);
        result = 0;
    }

    return result;
}

static int Is_StringInList(char **ppcList, char *pcLookup)
{
    int i = 0;

    if ( !ppcList || !pcLookup )
    {
        return 0;
    }

    while ( NULL != ppcList[i] )
    {
        if ( !strcmp("all over in", ppcList[i]) )
        {
            return 1;
        }

        if ( !strcmp(pcLookup, ppcList[i]) )
        {
            return 1;
        }

        i++;
    }

    return 0;
}

//检查哪些字段在bin文件中没有读取出来的
static int check_missing(char *pcHeader, char *pcLineEnd, ST_VALUE_MAP *astValueMap, int iCount, char *pcFileName, ST_CALLBACK *pstCallback)
{
    char *pcAnchor, *pcAnchorTemp;
    char bAnchor;
    int result = 1;
    int i;
    char acTempKey[256] = {0};

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
            my_error("invalid head at %s\r\n", pcHeader);
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
                break;
            }
        }
        if ( i >= iCount )
        {
            if ( pstCallback && Is_StringInList(pstCallback->ppcKeyInternalProcess, pcHeader) )
            {
                //已被内部处理
            }
            else if ( pstCallback && Is_StringInList(pstCallback->ppcKeyNotUsed, pcHeader) )
            {
                my_printf("Not Used Field: %s\r\n", pcHeader);
            }
            else if ( pstCallback && Is_StringInList(pstCallback->ppcKeyNotParsed, pcHeader) )
            {
                my_printf("Not Parsed Field: %s\r\n", pcHeader);
            }
            else
            {
                my_printf("Unknown Field: %s\r\n", pcHeader);
            }
        }

        *pcAnchor = bAnchor;
    } while ( (pcHeader = strchr(pcHeader, '\t')) && pcHeader < pcLineEnd && pcHeader++ );

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
        if ( pstCallback->iOptional )
        {
            my_printf("%s bin not found, module will be skipped\r\n", pcFilename);
            goto out;
        }
        my_error("open %s bin file fail\r\n", pcFilename);
        goto error;
    }

    pfTplHandle = fopen(acTemplateFile, "rb");
    if ( NULL == pfTplHandle )
    {
        char *pcEol = NULL;
        char *pcColumn = acTplBuf;

        my_printf("%s template found, auto generated will be used\r\n", pcFilename);

        if ( pstCallback->ppcKeyInternalProcess )
        {
            i = 0;
            while ( pstCallback->ppcKeyInternalProcess[i] != NULL )
            {
                if ( !stricmp(pstCallback->ppcKeyInternalProcess[i], "eol") ||
                     !stricmp(pstCallback->ppcKeyInternalProcess[i], "*eol"))
                {
                    pcEol = pstCallback->ppcKeyInternalProcess[i];
                }
                else
                {
                    String_RestoreSpecialChar(pstCallback->ppcKeyInternalProcess[i], m_acTempBuffer);
                    pcColumn += sprintf(pcColumn, "%s\t", m_acTempBuffer);
                }
                i++;
            }
        }

        for ( i = 0; i < (unsigned int)iValueCount; i++ )
        {
            String_RestoreSpecialChar(pstValueMap[i].acKeyName, m_acTempBuffer);
            pcColumn += sprintf(pcColumn, "%s\t", m_acTempBuffer);
        }

        if ( pcEol )
        {
            pcColumn += sprintf(pcColumn, "%s\t", pcEol);
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

    if ( acTxtPath )
    {
        pfTxtHandle = fopen(acTxtFile, "wb");
        if ( NULL == pfTxtHandle )
        {
            my_error("create %s txt file fail\r\n", pcFilename);
            goto error;
        }
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

    //检查有哪些字段没有处理
    if ( 0 == check_missing(acTxtBuf, strchr(acTxtBuf, '\r'), pstValueMap, iValueCount, pcFilename, pstCallback) )
    {
        goto error;
    }

    //读取bin文件的文件头
    if ( sizeof(stFileHeader) != fread(&stFileHeader, 1, sizeof(stFileHeader), pfBinHandle) )
    {
        my_error("read %s bin file head fail\r\n", pcFilename);
        goto error;
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
            break;
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
            if ( i > 0 )
            {
                my_printf("\33[2K\r");
            }
            my_printf("%sprocessed %d of %d entries of %s", (acTxtPath ? "" : "pre-"), i + 1, stFileHeader.iLines, pcFilename);
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
#if 0
    //暂时不能释放，因为其他模块还需要查询
    if ( pstCallback && pstCallback->pfnFinished )
    {
        pstCallback->pfnFinished();
    }
#endif

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


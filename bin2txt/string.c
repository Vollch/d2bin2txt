#include "global.h"
#include "ctype.h"

typedef struct
{
    char *vString;
    char *vText;
} ST_STRING;

static unsigned int m_iStringCount;
static ST_STRING m_astString[10000];
static unsigned int m_iPatchStringCount;
static ST_STRING m_astPatchString[10000];
static unsigned int m_iExpansionsStringCount;
static ST_STRING m_astExpansionsString[30000];

static unsigned int m_iCustom1Count;
static ST_STRING m_astCustom1[10000];
static unsigned int m_iCustom2Count;
static ST_STRING m_astCustom2[10000];
static unsigned int m_iCustom3Count;
static ST_STRING m_astCustom3[10000];

static int load_strings(char *acBinPath, char *pcTxtFile, ST_STRING *aStringList, int iListSize)
{
    char acTxtFile[256] = {0};
    FILE *pfTxtHandle = NULL;
    char *pcAnchor;
    int iStringCount = 0;
    size_t iCurBufLength = 0;

    memset(aStringList, 0, iListSize * sizeof(aStringList[0]));

    sprintf(acTxtFile, "%s\\%s.txt", acBinPath, pcTxtFile);
    pfTxtHandle = fopen(acTxtFile, "rb");
    if ( pfTxtHandle )
    {
        memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);

        while ( fgets(m_acGlobalBuffer, m_iGlobaBufLength, pfTxtHandle) )
        {
            iCurBufLength = strlen(m_acGlobalBuffer);
            pcAnchor = strchr(m_acGlobalBuffer, '\t');
            *pcAnchor = 0;
            pcAnchor++;

            aStringList[iStringCount].vString = strdup(m_acGlobalBuffer);
            aStringList[iStringCount].vText = strdup(pcAnchor);
            iStringCount++;

            memset(m_acGlobalBuffer, 0, iCurBufLength);
        }

        fclose(pfTxtHandle);

        my_printf("%d %s\r\n", iStringCount, pcTxtFile);
    }
    else
    {
        my_printf("fail to open %s\r\n", acTxtFile);
    }

    return iStringCount;
}

static int process_string_x(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    m_iStringCount = load_strings(acBinPath, "string", m_astString, 10000);
    m_iPatchStringCount = load_strings(acBinPath, "patchstring", m_astPatchString, 10000);
    m_iExpansionsStringCount = load_strings(acBinPath, "expansionstring", m_astExpansionsString, 30000);

    if ( g_pcCustomTable1 )
    {
        m_iCustom1Count = load_strings(acBinPath, g_pcCustomTable1, m_astCustom1, 10000);
    }
    if ( g_pcCustomTable2 )
    {
        m_iCustom2Count = load_strings(acBinPath, g_pcCustomTable2, m_astCustom2, 10000);
    }
    if ( g_pcCustomTable3 )
    {
        m_iCustom3Count = load_strings(acBinPath, g_pcCustomTable3, m_astCustom3, 10000);
    }

    return (m_iStringCount && m_iPatchStringCount && m_iExpansionsStringCount &&
        (!g_pcCustomTable1 || m_iCustom1Count) && (!g_pcCustomTable2 || m_iCustom2Count) && (!g_pcCustomTable3 || m_iCustom3Count));
}

int process_string(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            return process_string_x(acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

ST_STRING *String_ResolveID(unsigned int id)
{
    ST_STRING *pcResult = NULL;

    if ( 0xFFFF <= id )
    {
        return NULL;
    }

    if ( id < m_iStringCount )
    {
        pcResult = &m_astString[id];
    }
    else if ( 10000 <= id && (id - 10000) < m_iPatchStringCount )
    {
        pcResult = &m_astPatchString[id - 10000];
    }
    else if ( 20000 <= id && (id - 20000) < m_iExpansionsStringCount )
    {
        pcResult = &m_astExpansionsString[id - 20000];
    }
    else if ( g_pcCustomTable1 && (30000 <= id && (id - 30000) < m_iCustom1Count) )
    {
        pcResult = &m_astCustom1[id - 30000];
    }
    else if ( g_pcCustomTable2 && (40000 <= id && (id - 40000) < m_iCustom2Count) )
    {
        pcResult = &m_astCustom2[id - 40000];
    }
    else if ( g_pcCustomTable3 && (50000 <= id && (id - 50000) < m_iCustom3Count) )
    {
        pcResult = &m_astCustom3[id - 50000];
    }

    return pcResult;
}

char *String_GetString(unsigned int id, char* pcFilter, char* pcFilter2)
{
    ST_STRING *pcResult = String_ResolveID(id);

    if ( !pcResult )
    {
        return NULL;
    }

    if ( NULL != pcFilter && !strcmp(pcResult->vString, pcFilter) )
    {
        return NULL;
    }

    if ( NULL != pcFilter2 && !strcmp(pcResult->vString, pcFilter2) )
    {
        return NULL;
    }

    return pcResult->vText;
}

int String_Sanitize(char *pcInput, char *acOutput, unsigned int iSize, char cSpace)
{
    int iCharFlag = 0;
    char *pcOrigin = acOutput;

    if ( !pcInput || !acOutput || !iSize )
    {
        return 0;
    }

    iSize--;
    while ( iSize && *pcInput )
    {
        if ( *pcInput == (char)0xC3 ) { // Strip colors
            pcInput += 4;
            continue;
        }
        else if ( isalpha(*pcInput) || isdigit(*pcInput) ) // Output letters and numbers
        {
            *acOutput = *pcInput;
            acOutput++;
            iSize--;
            iCharFlag = 1;
        }
        else if ( cSpace && iCharFlag && strncmp(pcInput, "'s ", 3) ) // Replace other symbols with spaces, ignoring
        {
            *acOutput = cSpace;
            acOutput++;
            iSize--;
            iCharFlag = 0;
        }
        pcInput++;
    }
    *acOutput = 0;

    if ( cSpace )
    {
        while ( --acOutput >= pcOrigin && *acOutput == cSpace )
        {
            *acOutput = 0;
        }
    }

    return 1;
}

int String_StripFileName(char *pcInput, char *acOutput, unsigned int iSize)
{
    char *pcFrom, *pcTo;

    if ( !pcInput || !iSize || !strcmp(pcInput, "0") || !stricmp(pcInput, "null") )
    {
        return 0;
    }

    pcFrom = pcInput;
    while ( (pcTo = memchr(pcFrom, '/', iSize - ( pcFrom - pcInput ))) ||
            (pcTo = memchr(pcFrom, '\\', iSize - ( pcFrom - pcInput ))) )
    {
        pcFrom = pcTo + 1;
    }
    pcTo = memchr(pcFrom, '.', iSize - ( pcFrom - pcInput ));
    if ( !pcTo )
    {
        pcTo = pcInput + iSize;
    }
    strncpy(acOutput, pcFrom, pcTo - pcFrom);

    return 1;
}

int String_BuildName(char *pcNameFormat, int iNameSize, char cNameSeparator, unsigned int iStingId, char *pcTemplate, char *pcName, unsigned int iLine, fnHaveName pfnHaveName, char* acOutput)
{
    char *pcOutPos = acOutput;
    char *pcFormatPos = pcNameFormat;
    char *pcTemp;
    int iTemplateFlag = 1;
    int iStringFlag = 0;
    unsigned int iMaxLength = iNameSize;
    unsigned int iCutOff = 0;

    if ( !pcNameFormat || !iNameSize )
    {
        return 0;
    }

    while ( *pcFormatPos )
    {
        pcTemp = NULL;
        iStringFlag = 0;
        if ( !strncmp(pcFormatPos, "%S", 2) )
        {
            pcTemp = String_FindString_2(iStingId, "dummy", "Dummy");
            iStringFlag = 1;
        }
        else if ( !strncmp(pcFormatPos, "%s", 2) )
        {
            pcTemp = String_GetString(iStingId, "dummy", "Dummy");
            iStringFlag = 1;
        }
        else if ( !strncmp(pcFormatPos, "%n", 2) )
        {
            pcTemp = pcName;
            iStringFlag = 1;
        }

        if ( iStringFlag == 1 )
        {
            if ( pcTemp && *pcTemp )
            {
                String_Sanitize(pcTemp, pcOutPos, iNameSize - (pcOutPos - acOutput), cNameSeparator);
                pcOutPos += strlen(pcOutPos);
                pcFormatPos += 2;
                iTemplateFlag = 0;
            }
            else
            {
                memset(acOutput, 0, strlen(acOutput));
                if ( !(pcTemp = strchr(pcFormatPos, '|')) )
                    return 0;
                pcFormatPos = pcTemp + 1;
                pcOutPos = acOutput;
                iTemplateFlag = 1;
            }
        }
        else
        {
            if ( !strncmp(pcFormatPos, "%t", 2) )
            {
                if ( *pcTemplate )
                {
                    strcpy(pcOutPos, pcTemplate);
                    pcOutPos += strlen(pcOutPos);
                    pcFormatPos += 2;
                }
                else
                {
                    memset(acOutput, 0, strlen(acOutput));
                    if ( !(pcTemp = strchr(pcFormatPos, '|')) )
                        return 0;
                    pcFormatPos = pcTemp + 1;
                    pcOutPos = acOutput;
                }
            }
            else if ( !strncmp(pcFormatPos, "%l", 2) )
            {
                sprintf(pcOutPos, "%u", iLine);
                pcOutPos += strlen(pcOutPos);
                pcFormatPos += 2;
                iTemplateFlag = 0;
            }
            else if ( *pcFormatPos == '|')
            {
                break;
            }
            else
            {
                *pcOutPos = *pcFormatPos;
                pcOutPos++;
                pcFormatPos++;
                iTemplateFlag = 0;
            }
        }
    }

    do
    {
        if ( !strlen(acOutput) )
        {
            return 0;
        }

        if ( pfnHaveName )
        {
            int iNameSuffux = 0;
            while ( pfnHaveName(acOutput) )
            {
                sprintf(pcOutPos, "%i", iNameSuffux++);
            }
        }

        if ( !iTemplateFlag && (strlen(acOutput) > (iMaxLength + iCutOff)) )
        {
            memset(acOutput+iMaxLength, 0, (strlen(acOutput)-iMaxLength));
            pcOutPos = acOutput+iMaxLength;
            iMaxLength--;
            iCutOff++;
            continue;
        }
        break;
    } while(1);

    return 1;
}

char *String_FindString(unsigned int id, char* pcFilter)
{
    ST_STRING *pcResult = String_ResolveID(id);

    if ( !pcResult )
    {
        return NULL;
    }

    if ( !strcmp("DescBlank", pcResult->vString) )
    {
        printf("\r\n======%d======\r\n", id);
    }

    if ( NULL != pcFilter && !strcmp(pcResult->vString, pcFilter) )
    {
        return NULL;
    }

    return pcResult->vString;
}

char *String_FindString_2(unsigned int id, char* pcFilter, char* pcFilter2)
{
    ST_STRING *pcResult = String_ResolveID(id);

    if ( !pcResult )
    {
        return NULL;
    }

    if ( NULL != pcFilter && !strcmp(pcResult->vString, pcFilter) )
    {
        return NULL;
    }

    if ( NULL != pcFilter2 && !strcmp(pcResult->vString, pcFilter2) )
    {
        return NULL;
    }

    return pcResult->vString;
}


// bin2txt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdarg.h>
#include "global.h"
#include <windows.h>

typedef int (*fn_process_module)(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
typedef struct
{
    char *pcFileName;
    char *pcNameFormat;
    int iNameSize;
    fn_process_module pfnProcessModule;
    ENUM_MODULE_PHASE enPhase;
} ST_MODULE;

static ST_MODULE m_astProcessModule[EN_MID_MAX];

#define MODULE_MAP_DEFINE(key) \
    do\
    {\
        m_astProcessModule[MODULE_ID(key)].pcFileName = #key;\
        m_astProcessModule[MODULE_ID(key)].pcNameFormat = NULL;\
        m_astProcessModule[MODULE_ID(key)].iNameSize = 24;\
        m_astProcessModule[MODULE_ID(key)].pfnProcessModule = process_##key;\
        m_astProcessModule[MODULE_ID(key)].enPhase = EN_MODULE_PHASE_START;\
    } while (0);


void Init_Module()
{
    ALL_MODULES(MODULE_MAP_DEFINE)
}

void Set_ModulePhase(ENUM_MODULE_ID enMid, ENUM_MODULE_PHASE enPhase)
{
    m_astProcessModule[enMid].enPhase = enPhase;
}

ENUM_MODULE_PHASE Get_ModulePhase(ENUM_MODULE_ID enMid)
{
    return m_astProcessModule[enMid].enPhase;
}

char *Get_ModuleNameFormat(ENUM_MODULE_ID enMid)
{
    return m_astProcessModule[enMid].pcNameFormat;
}

int Get_ModuleNameSize(ENUM_MODULE_ID enMid)
{
    return m_astProcessModule[enMid].iNameSize;
}

static FILE *m_pfLogHandle = NULL;

unsigned int bg_printf( const char *pcBG, const char *pcFormat,... )
{
    va_list args;
    unsigned int dwStringLength;
    static char m_acPrintTempBuf[2048];
    char acLine[40];

#ifdef NO_VERBOSE
    return 0;
#endif

    if ( !pcFormat )
    {
        return 0;
    }

    va_start(args, pcFormat);
    dwStringLength = vsnprintf( m_acPrintTempBuf, sizeof(m_acPrintTempBuf), pcFormat, args);

    if ( dwStringLength > sizeof(acLine) )
    {
        dwStringLength = my_printf(pcFormat, args);
        va_end(args);
        return dwStringLength;
    }
    va_end(args);

    memset(acLine, *pcBG, sizeof(acLine));
    strncpy((acLine + (sizeof(acLine)/2 - dwStringLength/2)), m_acPrintTempBuf, dwStringLength);

    printf("%.*s\r\n", sizeof(acLine), acLine);
    fflush(stdout);

    if ( NULL != m_pfLogHandle )
    {
        fwrite(acLine, 1, sizeof(acLine), m_pfLogHandle);
    }

    return dwStringLength;
}

unsigned int my_printf( const char *pcFormat,... )
{
    va_list args;
    unsigned int dwStringLength;
    static char m_acPrintTempBuf[2048];

    if ( !pcFormat )
    {
        return 0;
    }

    va_start(args, pcFormat);
    dwStringLength = vsnprintf( m_acPrintTempBuf, sizeof(m_acPrintTempBuf), pcFormat, args);
    va_end(args);

    if( dwStringLength >= 0 )
    {
        m_acPrintTempBuf[dwStringLength] = 0;
    }

    printf("%s", m_acPrintTempBuf);
    fflush(stdout);

    if ( NULL != m_pfLogHandle )
    {
        fwrite(m_acPrintTempBuf, 1, strlen(m_acPrintTempBuf), m_pfLogHandle);
    }

    return dwStringLength;
}

static ENUM_MODULE_ID Get_ModuleId(char *pcModuleName)
{
    unsigned int i = 0;

    if ( !stricmp("all", pcModuleName) )
    {
        return EN_MID_MAX;
    }

    for ( i = 0; i < EN_MID_MAX; i++ )
    {
        if ( !stricmp(pcModuleName, m_astProcessModule[i].pcFileName) )
        {
            return (ENUM_MODULE_ID)i;
        }
    }

    return EN_MID_MAX;
}

static void usage(int argc, char* argv[])
{
/*
-template指定模板文件路径
-bin指定bin文件路径
-output指定输出txt文件的路径
-all处理所有的bin文件
-file指定处理某一个bin文件
*/
    char *pcExeName;

    if ( pcExeName = strrchr(argv[0], '\\') )
    {
        my_printf("Usage: %s [args]\r\n", pcExeName + 1);
    }
    else
    {
        my_printf("Usage: %s [args]\r\n", argv[0]);
    }
    my_printf("    -tc <specific tc offset>\r\n");
    my_printf("    -template <template path>\r\n");
    my_printf("    -bin <bin path>\r\n");
    my_printf("    -output <output txt path>\r\n");
    my_printf("    -all | -file <specific file prefix>\r\n");
}

char *g_pcCustomTable1 = NULL;
char *g_pcCustomTable2 = NULL;
char *g_pcCustomTable3 = NULL;
int g_iMercDesc = 0;
int g_iTrimSpace = 0;

void Init_Settings(char* acTemplatePath, char* acBinPath, char* acTxtPath)
{
    char acIniBuff[64 * 1024] = {0};
    char *pcIniFile = ".\\bin2txt.ini";
    char *pcAnchor, *pcAnchor2;

    GetPrivateProfileString("GENERAL", "Template", ".\\template", acTemplatePath, 256, pcIniFile);
    GetPrivateProfileString("GENERAL", "Bin", ".\\bin", acBinPath, 256, pcIniFile);
    GetPrivateProfileString("GENERAL", "Output", ".\\txt", acTxtPath, 256, pcIniFile);

    GetPrivateProfileString("GENERAL", "TreasureClassOffset", "0", acIniBuff, sizeof(acIniBuff), pcIniFile);
    TreasureClassEx_SetOffset(atoi(acIniBuff));

    GetPrivateProfileString("GENERAL", "LogEnabled", "0", acIniBuff, sizeof(acIniBuff), pcIniFile);
    if ( atoi(acIniBuff) )
    {
        m_pfLogHandle = fopen("output.txt", "wt");
    }

    GetPrivateProfileString("GENERAL", "MercDesc", "0", acIniBuff, sizeof(acIniBuff), pcIniFile);
    g_iMercDesc = atoi(acIniBuff);

    GetPrivateProfileString("GENERAL", "TrimSpace", "0", acIniBuff, sizeof(acIniBuff), pcIniFile);
    g_iTrimSpace = atoi(acIniBuff);

    GetPrivateProfileString("GENERAL", "CustomTbl1", 0, acIniBuff, sizeof(acIniBuff), pcIniFile);
    if ( strlen(acIniBuff) > 0 )
    {
        char *cpDot = strchr(acIniBuff, '.');
        if ( cpDot )
        {
            memset(cpDot, 0, strlen(cpDot));
        }
        g_pcCustomTable1 = strdup(acIniBuff);
    }

    GetPrivateProfileString("GENERAL", "CustomTbl2", 0, acIniBuff, sizeof(acIniBuff), pcIniFile);
    if ( strlen(acIniBuff) > 0 )
    {
        char *cpDot = strchr(acIniBuff, '.');
        if ( cpDot )
        {
            memset(cpDot, 0, strlen(cpDot));
        }
        g_pcCustomTable2 = strdup(acIniBuff);
    }

    GetPrivateProfileString("GENERAL", "CustomTbl3", 0, acIniBuff, sizeof(acIniBuff), pcIniFile);
    if ( strlen(acIniBuff) > 0 )
    {
        char *cpDot = strchr(acIniBuff, '.');
        if ( cpDot )
        {
            memset(cpDot, 0, strlen(cpDot));
        }
        g_pcCustomTable3 = strdup(acIniBuff);
    }

    GetPrivateProfileSection("NAME_FORMAT", acIniBuff, sizeof(acIniBuff), pcIniFile);

    pcAnchor = acIniBuff;
    while ( *pcAnchor )
    {
        ENUM_MODULE_ID eModule;

        pcAnchor2 = strchr(pcAnchor, '=');
        *pcAnchor2 = 0;
        pcAnchor2++;

        if ( (eModule = Get_ModuleId(pcAnchor)) != EN_MID_MAX )
        {
            m_astProcessModule[eModule].pcNameFormat = strdup(pcAnchor2);
        }
        pcAnchor = pcAnchor2 + strlen(pcAnchor2) + 1;
    }

    GetPrivateProfileSection("NAME_SIZE", acIniBuff, sizeof(acIniBuff), pcIniFile);

    pcAnchor = acIniBuff;
    while ( *pcAnchor )
    {
        ENUM_MODULE_ID eModule;

        pcAnchor2 = strchr(pcAnchor, '=');
        *pcAnchor2 = 0;
        pcAnchor2++;

        if ( (eModule = Get_ModuleId(pcAnchor)) != EN_MID_MAX )
        {
            m_astProcessModule[eModule].iNameSize = atoi(pcAnchor2);
            if ( m_astProcessModule[eModule].iNameSize > 64 )
            {
                m_astProcessModule[eModule].iNameSize = 64;
            }
            if ( m_astProcessModule[eModule].iNameSize < 6 )
            {
                m_astProcessModule[eModule].iNameSize = 6;
            }
        }
        pcAnchor = pcAnchor2 + strlen(pcAnchor2) + 1;
    }
}

int main(int argc, char* argv[])
{
    static char acTemplatePath[256] = {0};
    static char acBinPath[256] = {0};
    static char acTxtPath[256] = {0};

    int iModFrom = 0;
    int iModTo = EN_MID_MAX;

    char acFailedList[100 * 32] = {0};

    char *pcFailed = acFailedList;
    int i = 1, j = 0;
    int iCount = 0;
    int iSuccess = 0;
    int iFail = 0;

    Init_Module();
    Init_Settings(acTemplatePath, acBinPath, acTxtPath);

    while (i < argc)
    {
        if ( !strcmp("-j", argv[i]) )
        {
            usage(argc, argv);
            goto out;
        }
        else if ( !strcmp("-tc", argv[i]) && argc > i+1 )
        {
            //161 原版
            //321 魔电v15
            //193 宝日8.4
            sscanf(argv[i + 1], "%d", &j);
            TreasureClassEx_SetOffset(j);
            i += 2;
        }
        else if ( !strcmp("-template", argv[i]) && argc > i+1 )
        {
            strcpy(acTemplatePath, argv[i + 1]);
            i += 2;
        }
        else if ( !strcmp("-bin", argv[i]) && argc > i+1 )
        {
            strcpy(acBinPath, argv[i + 1]);
            i += 2;
        }
        else if ( !strcmp("-output", argv[i]) && argc > i+1 )
        {
            strcpy(acTxtPath, argv[i + 1]);
            i += 2;
        }
        else if ( !strcmp("-file", argv[i]) && argc > i+1 )
        {
            j = Get_ModuleId(argv[i + 1]);
            if ( j >= EN_MID_MAX )
            {
                my_printf("Unknown module: %s\r\n", argv[i+1]);
                goto out;
            }
            iModFrom = j;
            iModTo = j + 1;
            i += 2;
        }
        else
        {
            my_printf("Unknown argument: %s\r\n", argv[i]);
            goto out;
        }
    }

    MemMgr_Init();

    my_printf("Args:\r\n");
    my_printf("    template path %s\r\n", acTemplatePath);
    my_printf("    bin path %s\r\n", acBinPath);
    my_printf("    output path %s\r\n", acTxtPath);
    if ( iModTo - iModFrom > 1 )
    {
        my_printf("    all module\r\n");
    }
    else
    {
        my_printf("    module %s\r\n", m_astProcessModule[iModFrom].pcFileName);
    }

    my_printf("confirm start?(y/n)");
    scanf("%c", &i);

    if ( 'y' != i && 'Y' != i )
    {
        goto out;
    }

    if ( _access(acTxtPath, 0) ) 
    {
        sprintf(m_acGlobalBuffer, "md %s", acTxtPath);
        system(m_acGlobalBuffer);
    }

    Operater_Init();

    iCount = sizeof(m_astProcessModule) / sizeof(m_astProcessModule[0]);
    memset(acFailedList, 0, sizeof(acFailedList));

    for ( i = iModFrom; i < iModTo; i++ )
    {
        if ( m_astProcessModule[i].pcFileName && m_astProcessModule[i].pfnProcessModule )
        {
            bg_printf("*", "[%d]", i+1);
            bg_printf("*", "%s", m_astProcessModule[i].pcFileName);

            for ( j = (int)Get_ModulePhase((ENUM_MODULE_ID)i) + 1; j < (int)EN_MODULE_PHASE_MAX; j++ )
            {
                bg_printf("*", "phase %d", j);
                Set_ModulePhase((ENUM_MODULE_ID)i, (ENUM_MODULE_PHASE)j);

                memset(&m_stCallback, 0, sizeof(m_stCallback));
                memset(m_acLineInfoBuf, 0, m_iLineBufLength);
                memset(m_acValueMapBuf, 0, m_iValueBufLength);
                m_iValueMapIndex = 0;

                if ( 0 == m_astProcessModule[i].pfnProcessModule(acTemplatePath, acBinPath, acTxtPath, (ENUM_MODULE_PHASE)j) )
                {
                    iFail++;
                    sprintf(pcFailed, "%s\r\n", m_astProcessModule[i].pcFileName);
                    pcFailed += strlen(pcFailed);
                    bg_printf("*", "failed");
                    break;
                }
                else
                {
                    bg_printf("*", "success");
                }
            }

            if ( j >= EN_MODULE_PHASE_MAX )
            {
                iSuccess++;
            }

            bg_printf("*", "%s", m_astProcessModule[i].pcFileName);
            bg_printf(" ", "");
            bg_printf(" ", "");
        }
    }

    my_printf("processed %d of %d modules\r\n", iSuccess, iCount);
    if ( 0 < iFail )
    {
        my_error("%d modules failed:\r\n%s\r\n", iFail, acFailedList);
    }

out:
    my_printf("press RETURN to exit!\r\n");
    if ( NULL != m_pfLogHandle )
    {
        fclose(m_pfLogHandle);
        m_pfLogHandle = NULL;
    }

    MemMgr_FreeAll();

    getchar();
    getchar();

    return 0;
}

#if 0
typedef struct
{
    unsigned int iPadding0;
    unsigned int iPadding1;
    unsigned int iPadding2;
    unsigned int iPadding3;
    unsigned int iPadding4;
    unsigned int iPadding5;
    unsigned int iPadding6;
    unsigned int iPadding7;
    unsigned int iPadding8;
    unsigned int iPadding9;

    unsigned int iPadding10;
    unsigned int iPadding11;
    unsigned int iPadding12;
    unsigned int iPadding13;
    unsigned int iPadding14;
    unsigned int iPadding15;
    unsigned int iPadding16;
    unsigned int iPadding17;
    unsigned int iPadding18;
    unsigned int iPadding19;

    unsigned int iPadding20;
    unsigned int iPadding21;
    unsigned int iPadding22;
    unsigned int iPadding23;
    unsigned int iPadding24;
    unsigned int iPadding25;
    unsigned int iPadding26;
    unsigned int iPadding27;
    unsigned int iPadding28;
    unsigned int iPadding29;

    unsigned int iPadding30;
    unsigned int iPadding31;
    unsigned int iPadding32;
    unsigned int iPadding33;
    unsigned int iPadding34;
    unsigned int iPadding35;
    unsigned int iPadding36;
    unsigned int iPadding37;
    unsigned int iPadding38;
    unsigned int iPadding39;

    unsigned int iPadding40;
    unsigned int iPadding41;
    unsigned int iPadding42;
    unsigned int iPadding43;
    unsigned int iPadding44;
    unsigned int iPadding45;
    unsigned int iPadding46;
    unsigned int iPadding47;
    unsigned int iPadding48;
    unsigned int iPadding49;

    unsigned int iPadding50;
    unsigned int iPadding51;
    unsigned int iPadding52;
    unsigned int iPadding53;
    unsigned int iPadding54;
    unsigned int iPadding55;
    unsigned int iPadding56;
    unsigned int iPadding57;
    unsigned int iPadding58;
    unsigned int iPadding59;

    unsigned int iPadding60;
    unsigned int iPadding61;
    unsigned int iPadding62;
    unsigned int iPadding63;
    unsigned int iPadding64;
    unsigned int iPadding65;
    unsigned int iPadding66;
    unsigned int iPadding67;
    unsigned int iPadding68;
    unsigned int iPadding69;

    unsigned int iPadding70;
    unsigned int iPadding71;
    unsigned int iPadding72;
    unsigned int iPadding73;
    unsigned int iPadding74;
    unsigned int iPadding75;
    unsigned int iPadding76;
    unsigned int iPadding77;
    unsigned int iPadding78;
    unsigned int iPadding79;

    unsigned int iPadding80;
    unsigned int iPadding81;
    unsigned int iPadding82;
    unsigned int iPadding83;
    unsigned int iPadding84;
    unsigned int iPadding85;
    unsigned int iPadding86;
    unsigned int iPadding87;
    unsigned int iPadding88;
    unsigned int iPadding89;

    unsigned int iPadding90;
    unsigned int iPadding91;
    unsigned int iPadding92;
    unsigned int iPadding93;
    unsigned int iPadding94;
    unsigned int iPadding95;
    unsigned int iPadding96;
    unsigned int iPadding97;
    unsigned int iPadding98;
    unsigned int iPadding99;

    unsigned int iPadding100;
    unsigned int iPadding101;
    unsigned int iPadding102;
    unsigned int iPadding103;
    unsigned int iPadding104;
    unsigned int iPadding105;
    unsigned int iPadding106;
    unsigned int iPadding107;
    unsigned int iPadding108;
    unsigned int iPadding109;

    unsigned int iPadding110;
    unsigned int iPadding111;
    unsigned int iPadding112;
    unsigned int iPadding113;
    unsigned int iPadding114;
    unsigned int iPadding115;
    unsigned int iPadding116;
    unsigned int iPadding117;
    unsigned int iPadding118;
    unsigned int iPadding119;

    unsigned int iPadding120;
    unsigned int iPadding121;
    unsigned int iPadding122;
    unsigned int iPadding123;
    unsigned int iPadding124;
    unsigned int iPadding125;
    unsigned int iPadding126;
    unsigned int iPadding127;
    unsigned int iPadding128;
    unsigned int iPadding129;

    unsigned int iPadding130;
    unsigned int iPadding131;
    unsigned int iPadding132;
    unsigned int iPadding133;
    unsigned int iPadding134;
    unsigned int iPadding135;
    unsigned int iPadding136;
    unsigned int iPadding137;
    unsigned int iPadding138;
    unsigned int iPadding139;

    unsigned int iPadding140;
    unsigned int iPadding141;
    unsigned int iPadding142;
    unsigned int iPadding143;
    unsigned int iPadding144;
    unsigned int iPadding145;
    unsigned int iPadding146;
    unsigned int iPadding147;
    unsigned int iPadding148;
    unsigned int iPadding149;
} ST_LINE_INFO;
#endif


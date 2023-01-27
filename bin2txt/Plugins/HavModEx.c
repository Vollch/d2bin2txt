#include "../global.h"

#define FILE_PREFIX "HavModEx"

#pragma pack(push, 1)
typedef struct
{
    int iInfiniteImbue;
    int iForceEnableImbue;
    int iCost;
    int iItemQuality;
    int iItemLevel;
    int iUseRandomQuality;
    int iChanceCrude;
    int iChanceMagic;
    int iChanceRare;
    int iChanceSet;
    int iChanceUnique;
    int iUseRandomItemlevel;
    int iMinRandomItemlevel;
    int iMaxRandomItemlevel;
    int iStringColorSuccess;
    int iStringColorFail;
    char pad0x40[20];
    char wFirstStringSuccess[2048];
    char wFirstStringFail[2048];
    char wLastString[2048];
} ST_BIN_HAVMODEX;
#pragma pack(pop)


static int process_HavModEx_x(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    static char acBinFile[256] = {0};
    static char acIniFile[256] = {0};
    FILE *pfBinHandle = NULL;
    FILE *pfOutputHandle = NULL;
    ST_BIN_HAVMODEX stConfig;

    sprintf(acBinFile, "%s\\%s.bin", acBinPath, FILE_PREFIX);
    pfBinHandle = fopen(acBinFile, "rb");
    if ( !pfBinHandle || sizeof(stConfig) != fread(&stConfig, 1, sizeof(stConfig), pfBinHandle) )
    {
        goto out;
    }

    sprintf(acIniFile, "%s\\%s.ini", acTxtPath, FILE_PREFIX);
    pfOutputHandle = fopen(acIniFile, "wb");

    if ( !pfOutputHandle )
    {
        goto out;
    }

    fprintf(pfOutputHandle, "[%s]\n", FILE_PREFIX);
    fprintf(pfOutputHandle, "InfiniteImbue=%i\n", stConfig.iInfiniteImbue);
    fprintf(pfOutputHandle, "ForceEnableImbue=%i\n", stConfig.iForceEnableImbue);
    fprintf(pfOutputHandle, "Cost=%i\n", stConfig.iCost);
    fprintf(pfOutputHandle, "ItemQuality=%i\n", stConfig.iItemQuality);
    fprintf(pfOutputHandle, "ItemLevel=%i\n", stConfig.iItemLevel);
    fprintf(pfOutputHandle, "UseRandomQuality=%i\n", stConfig.iUseRandomQuality);
    fprintf(pfOutputHandle, "ChanceCrude=%i\n", stConfig.iChanceCrude);
    fprintf(pfOutputHandle, "ChanceMagic=%i\n", stConfig.iChanceMagic);
    fprintf(pfOutputHandle, "ChanceRare=%i\n", stConfig.iChanceRare);
    fprintf(pfOutputHandle, "ChanceSet=%i\n", stConfig.iChanceSet);
    fprintf(pfOutputHandle, "ChanceUnique=%i\n", stConfig.iChanceUnique);
    fprintf(pfOutputHandle, "UseRandomItemlevel=%i\n", stConfig.iUseRandomItemlevel);
    fprintf(pfOutputHandle, "MinRandomItemlevel=%i\n", stConfig.iMinRandomItemlevel);
    fprintf(pfOutputHandle, "MaxRandomItemlevel=%i\n", stConfig.iMaxRandomItemlevel);
    fprintf(pfOutputHandle, "StringColorSuccess=%i\n", stConfig.iStringColorSuccess);
    fprintf(pfOutputHandle, "StringColorFail=%i\n", stConfig.iStringColorFail);
    fprintf(pfOutputHandle, "FirstStringSuccess=\"%S\"\n", stConfig.wFirstStringSuccess);
    fprintf(pfOutputHandle, "FirstStringFail=\"%S\"\n", stConfig.wFirstStringFail);
    fprintf(pfOutputHandle, "LastString=\"%S\"\n", stConfig.wLastString);

    my_printf("processed %s.ini\r\n", FILE_PREFIX);

out:
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
    }
    if ( NULL != pfOutputHandle )
    {
        fclose(pfOutputHandle);
    }

    return 1;
}

int process_HavModEx(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            return process_HavModEx_x(acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}
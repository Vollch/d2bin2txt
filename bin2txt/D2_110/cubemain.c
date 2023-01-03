#include "../global.h"

#define FILE_PREFIX "CubeMain"
#define NAME_PREFIX "cm"

typedef struct
{//total 328 bytes
    unsigned char venabled;
    unsigned char vladder;
    unsigned char vminmyspdiff;
    unsigned char vclass;   //playerclass

    unsigned int vop;
    unsigned int vparam;
    unsigned int vvalue;

    unsigned short vnuminputs;
    unsigned short vversion;

    unsigned char vinputmysp1[8];

    unsigned char vinputmysp2[8];

    unsigned char vinputmysp3[8];

    unsigned char vinputmysp4[8];

    unsigned char vinputmysp5[8];

    unsigned char vinputmysp6[8];

    unsigned char vinputmysp7[8];

    unsigned char voutput[24];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int vmodmysp1;   //properties

    unsigned short vmodmysp1myspparam;
    short vmodmysp1myspmin;

    short vmodmysp1myspmax;
    unsigned short vmodmysp1myspchance;

    unsigned int vmodmysp2;   //properties

    unsigned short vmodmysp2myspparam;
    short vmodmysp2myspmin;

    short vmodmysp2myspmax;
    unsigned short vmodmysp2myspchance;

    unsigned int vmodmysp3;   //properties

    unsigned short vmodmysp3myspparam;
    short vmodmysp3myspmin;

    short vmodmysp3myspmax;
    unsigned short vmodmysp3myspchance;

    unsigned int vmodmysp4;   //properties

    unsigned short vmodmysp4myspparam;
    short vmodmysp4myspmin;

    short vmodmysp4myspmax;
    unsigned short vmodmysp4myspchance;

    unsigned int vmodmysp5;   //properties

    unsigned short vmodmysp5myspparam;
    short vmodmysp5myspmin;

    short vmodmysp5myspmax;
    unsigned short vmodmysp5myspchance;

    unsigned char voutputmyspb[24];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int vbmyspmodmysp1;   //properties

    unsigned short vbmyspmodmysp1myspparam;
    short vbmyspmodmysp1myspmin;

    short vbmyspmodmysp1myspmax;
    unsigned short vbmyspmodmysp1myspchance;

    unsigned int vbmyspmodmysp2;   //properties

    unsigned short vbmyspmodmysp2myspparam;
    short vbmyspmodmysp2myspmin;

    short vbmyspmodmysp2myspmax;
    unsigned short vbmyspmodmysp2myspchance;

    unsigned int vbmyspmodmysp3;   //properties

    unsigned short vbmyspmodmysp3myspparam;
    short vbmyspmodmysp3myspmin;

    short vbmyspmodmysp3myspmax;
    unsigned short vbmyspmodmysp3myspchance;

    unsigned int vbmyspmodmysp4;   //properties

    unsigned short vbmyspmodmysp4myspparam;
    short vbmyspmodmysp4myspmin;

    short vbmyspmodmysp4myspmax;
    unsigned short vbmyspmodmysp4myspchance;

    unsigned int vbmyspmodmysp5;   //properties

    unsigned short vbmyspmodmysp5myspparam;
    short vbmyspmodmysp5myspmin;

    short vbmyspmodmysp5myspmax;
    unsigned short vbmyspmodmysp5myspchance;

    unsigned char voutputmyspc[24];  //lvl、plvl、ilvl复用在这20个byte里

    unsigned int vcmyspmodmysp1;   //properties

    unsigned short vcmyspmodmysp1myspparam;
    short vcmyspmodmysp1myspmin;

    short vcmyspmodmysp1myspmax;
    unsigned short vcmyspmodmysp1myspchance;

    unsigned int vcmyspmodmysp2;   //properties

    unsigned short vcmyspmodmysp2myspparam;
    short vcmyspmodmysp2myspmin;

    short vcmyspmodmysp2myspmax;
    unsigned short vcmyspmodmysp2myspchance;

    unsigned int vcmyspmodmysp3;   //properties

    unsigned short vcmyspmodmysp3myspparam;
    short vcmyspmodmysp3myspmin;

    short vcmyspmodmysp3myspmax;
    unsigned short vcmyspmodmysp3myspchance;

    unsigned int vcmyspmodmysp4;   //properties

    unsigned short vcmyspmodmysp4myspparam;
    short vcmyspmodmysp4myspmin;

    short vcmyspmodmysp4myspmax;
    unsigned short vcmyspmodmysp4myspchance;

    unsigned int vcmyspmodmysp5;   //properties

    unsigned short vcmyspmodmysp5myspparam;
    short vcmyspmodmysp5myspmin;

    short vcmyspmodmysp5myspmax;
    unsigned short vcmyspmodmysp5myspchance;
} ST_LINE_INFO;

typedef enum
{
    GRADE_LOW = 1,
    GRADE_NORMAL,
    GRADE_SUPERIOR,
    GRADE_MAGIC,
    GRADE_SET,
    GRADE_RARE,
    GRADE_UNIQ,
    GRADE_CRAFT,
    GRADE_TAMPERED,
} EN_CUBE_GRADE;

typedef struct
{
    union {
        unsigned short sFlags;
        struct {
            unsigned short bItemCode: 1;
            unsigned short bTypeCode: 1;
            unsigned short bNoSock: 1;
            unsigned short bSock: 1;
            unsigned short bEthereal: 1;
            unsigned short bNotEthereal: 1;
            unsigned short bSpecific: 1;
            unsigned short bUpgrade: 1;
            unsigned short bBase: 1;
            unsigned short bExceptional: 1;
            unsigned short bElite: 1;
            unsigned short bNotRuneword: 1;
        };
    };
    unsigned short sGenericID;
    unsigned short sSpecificID;
    unsigned char cGrade;
    unsigned char cQuantity;
} ST_CUBE_INPUT;

typedef struct
{
    union {
        unsigned short sFlags;
        struct {
            unsigned short bKeepModifiers: 1;
            unsigned short bSockets: 1;
            unsigned short bEthereal: 1;
            unsigned short bSpecific: 1;
            unsigned short bDestroyFillers: 1;
            unsigned short bRemoveFillers: 1;
            unsigned short bRegenerate: 1;
            unsigned short bExceptional: 1;
            unsigned short bElite: 1;
            unsigned short bRepair: 1;
            unsigned short bRecharge: 1;
        };
    };
    unsigned short sGenericID;
    unsigned short sSpecificID;
    unsigned char cGrade;
    unsigned char cQuantity;
    unsigned char cType;
    unsigned char clvl;
    unsigned char cplvl;
    unsigned char cilvl;
    unsigned short sPrefix;
    unsigned short sPrefixMin;
    unsigned short sPrefixMax;
    unsigned short sSuffix;
    unsigned short sSuffixMin;
    unsigned short sSuffixMax;
    struct
    {
      unsigned int iMod;
      unsigned short sModParam;
      unsigned short sModMin;
      unsigned short sModMax;
      unsigned short sModChance;
    } sMods[5];
} ST_CUBE_OUTPUT;

static char *m_apcInternalProcess[] =
{
    "description",
    NULL,
};

static unsigned int m_iBinStructSize = 0;

static char *Cubemain_GenerateInputProp(char *acOutput, ST_CUBE_INPUT *sInput, EN_CUBE_GRADE cOutGrade)
{
    if ( sInput->bNoSock )
    {
        strcpy(acOutput, ",nos");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bSock )
    {
        strcpy(acOutput, ",sock");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bEthereal )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bNotEthereal )
    {
        strcpy(acOutput, ",noe");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bUpgrade )
    {
        strcpy(acOutput, ",upg");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bBase )
    {
        strcpy(acOutput, ",bas");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bExceptional )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bElite )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( sInput->bNotRuneword )
    {
        strcpy(acOutput, ",nru");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_LOW )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_NORMAL )
    {
        strcpy(acOutput, ",nor");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SUPERIOR )
    {
        strcpy(acOutput, ",hiq");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_MAGIC )
    {
        strcpy(acOutput, ",mag");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_SET )
    {
        strcpy(acOutput, ",set");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_RARE )
    {
        strcpy(acOutput, ",rar");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_UNIQ )
    {
        strcpy(acOutput, ",uni");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_CRAFT )
    {
        strcpy(acOutput, ",crf");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_TAMPERED )
    {
        strcpy(acOutput, ",tmp");
        acOutput += strlen(acOutput);
    }

    if ( sInput->cQuantity > 0 )
    {
        sprintf(acOutput, ",qty=%d", sInput->cQuantity);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}

static char *Cubemain_GenerateOutputProp(char *acOutput, ST_CUBE_OUTPUT *sOutput, EN_CUBE_GRADE cOutGrade)
{
    if ( sOutput->bKeepModifiers )
    {
        strcpy(acOutput, ",mod");
        acOutput += strlen(acOutput);
    }

    if ( !(isD2SigmaActive() && sOutput->cType >= 0x01 && sOutput->cType <= 0x06) )
    {
        if ( sOutput->bSockets )
        {
            sprintf(acOutput, ",sock=%d", sOutput->cQuantity);
            acOutput += strlen(acOutput);
        }
        else if ( sOutput->cQuantity > 0 )
        {
            sprintf(acOutput, ",qty=%d", sOutput->cQuantity);
            acOutput += strlen(acOutput);
        }
    }

    if ( sOutput->bEthereal )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bDestroyFillers )
    {
        strcpy(acOutput, ",uns");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRemoveFillers )
    {
        strcpy(acOutput, ",rem");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRegenerate )
    {
        strcpy(acOutput, ",reg");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bExceptional )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bElite )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRepair )
    {
        strcpy(acOutput, ",rep");
        acOutput += strlen(acOutput);
    }

    if ( sOutput->bRecharge )
    {
        strcpy(acOutput, ",rch");
        acOutput += strlen(acOutput);
    }

    if ( isRoSActive() && sOutput->sFlags & 0x800 )
    {
        strcpy(acOutput, ",keep");
        acOutput += strlen(acOutput);
    }

    if ( cOutGrade == GRADE_LOW )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( !(isD2SigmaActive() && sOutput->cType >= 0x01 && sOutput->cType <= 0x06) )
    {
        if ( cOutGrade == GRADE_NORMAL )
        {
            strcpy(acOutput, ",nor");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_SUPERIOR )
        {
            strcpy(acOutput, ",hiq");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_MAGIC )
        {
            strcpy(acOutput, ",mag");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_SET )
        {
            strcpy(acOutput, ",set");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_RARE )
        {
            strcpy(acOutput, ",rar");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_UNIQ )
        {
            strcpy(acOutput, ",uni");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_CRAFT )
        {
            strcpy(acOutput, ",crf");
            acOutput += strlen(acOutput);
        }

        if ( cOutGrade == GRADE_TAMPERED )
        {
            strcpy(acOutput, ",tmp");
            acOutput += strlen(acOutput);
        }
    }

    if ( !(isRoSActive() && sOutput->cType == 0x82) )
    {
        if ( sOutput->sPrefix > 0 )
        {
            sprintf(acOutput, ",pre=%d", sOutput->sPrefix);
            acOutput += strlen(acOutput);
        }
    }

    if ( sOutput->sSuffix > 0 )
    {
        sprintf(acOutput, ",suf=%d", sOutput->sSuffix);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}


int Cubemain_ProcessInput(void *vInput, char *pcOutput)
{
    ST_CUBE_INPUT *sInput = (ST_CUBE_INPUT*)vInput;
    unsigned char cOutGrade = sInput->cGrade;
    char *pcResult = NULL;
    char acBuffer[128] = {0};

    if ( sInput->bSpecific && ( sInput->cGrade == GRADE_SET || sInput->cGrade == GRADE_UNIQ ) )
    {
        // No need to write ",uni" and ",set" after explicitly defined sets and uniques, it's just a clutter
        cOutGrade = 0;
    }

    if ( sInput->bItemCode || sInput->bTypeCode )
    {
        if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_UNIQ )
        {
            pcResult = Lookup_UniqueItem(sInput->sSpecificID);
        }
        else if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_SET )
        {
            pcResult = Lookup_SetItem(sInput->sSpecificID);
        }
        else if ( sInput->bItemCode && sInput->sGenericID == 0xFFFF )
        {
            pcResult = "any";
        }
        else if ( sInput->bItemCode )
        {
            pcResult = Lookup_Item(sInput->sGenericID);
        }
        else if ( sInput->bTypeCode )
        {
            pcResult = Lookup_ItemType(sInput->sGenericID);
        }

        if ( pcResult )
        {
            if ( pcResult[strlen(pcResult)-1] == ' ' || (sInput->sFlags & 0xFFBC) || cOutGrade || sInput->cQuantity )
            {
                pcOutput[0] = '"';
                strcpy(&pcOutput[1], pcResult);
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateInputProp(pcOutput, sInput, cOutGrade);
                pcOutput[0] = '"';
            }
            else
            {
                strcpy(pcOutput, pcResult);
            }
        }
    }

    return 1;
}

int Cubemain_ProcessOutput(void *vOutput, char *pcOutput)
{
    ST_CUBE_OUTPUT *sOutput = (ST_CUBE_OUTPUT*)vOutput;
    unsigned char cOutGrade = sOutput->cGrade;
    char *pcResult = NULL;
    char acBuffer[128] = {0};

    if ( sOutput->bSpecific && ( sOutput->cGrade == GRADE_SET || sOutput->cGrade == GRADE_UNIQ ) )
    {
        // No need to write ",uni" and ",set" after explicitly defined sets and uniques, it's just a clutter
        cOutGrade = 0;
    }

    if ( sOutput->bSpecific || sOutput->cType )
    {
        if ( sOutput->bSpecific && sOutput->cGrade == GRADE_UNIQ )
        {
            pcResult = Lookup_UniqueItem(sOutput->sSpecificID);
        }
        else if ( sOutput->bSpecific && sOutput->cGrade == GRADE_SET )
        {
            pcResult = Lookup_SetItem(sOutput->sSpecificID);
        }
        else if ( sOutput->cType == 0xFC )
        {
            pcResult = Lookup_Item(sOutput->sGenericID);
        }
        else if ( sOutput->cType == 0xFD )
        {
            pcResult = Lookup_ItemType(sOutput->sGenericID);
        }
        else if ( sOutput->cType == 0xFE )
        {
            pcResult = "useitem";
        }
        else if ( sOutput->cType == 0xFF )
        {
            pcResult = "usetype";
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x01 )
        {
            if ( pcResult = Lookup_Level(*(unsigned short*)&sOutput->cGrade) )
            {
                sprintf(acBuffer, "portal=%s", pcResult);
                pcResult = &acBuffer[0];
            }
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x02 )
        {
            sprintf(acBuffer, "skillpts=%u", *(unsigned short*)&sOutput->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x03 )
        {
            sprintf(acBuffer, "statpts=%u", *(unsigned short*)&sOutput->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x04 )
        {
            if ( pcResult = Lookup_MonStats(*(unsigned short*)&sOutput->cGrade) )
            {
                sprintf(acBuffer, "mon=%s", pcResult);
                pcResult = &acBuffer[0];
            }
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x05 )
        {
            if ( pcResult = Lookup_SuperUnique(*(unsigned short*)&sOutput->cGrade) )
            {
                sprintf(acBuffer, "boss=%s", pcResult);
                pcResult = &acBuffer[0];
            }
        }
        else if ( isD2SigmaActive() && sOutput->cType == 0x06 )
        {
            sprintf(acBuffer, "goldcost=%u", *(unsigned short*)&sOutput->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( sOutput->cType == 0x01 )
        {
            pcResult = "Cow Portal";
        }
        else if ( sOutput->cType == 0x02 )
        {
            pcResult = "Pandemonium Portal";
        }
        else if ( sOutput->cType == 0x03 )
        {
            pcResult = "Pandemonium Finale Portal";
        }
        else if ( isRoSActive() && sOutput->cType == 0x80 )
        {
            pcResult = "red portal";
        }
        else if ( isRoSActive() && sOutput->cType == 0x81 )
        {
            pcResult = "addstat";
        }
        else if ( isRoSActive() && sOutput->cType == 0x82 )
        {
            pcResult = Lookup_Set(sOutput->sPrefix);
        }

        if ( pcResult )
        {
            if ( pcResult[strlen(pcResult)-1] == ' ' || (sOutput->sFlags & 0xFFF7) || cOutGrade || sOutput->cQuantity || sOutput->sPrefix || sOutput->sSuffix )
            {
                pcOutput[0] = '"';
                strcpy(&pcOutput[1], pcResult);
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateOutputProp(pcOutput, sOutput, cOutGrade);
                pcOutput[0] = '"';
            }
            else
            {
                strcpy(pcOutput, pcResult);
            }
        }
    }

    return 1;
}

static int Cubemain_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int id;

    if ( 1 == sscanf(acKey, "input %d", &id) )
    {
        ST_CUBE_INPUT *sInput = (ST_CUBE_INPUT *)&pstLineInfo->vinputmysp1 + (id - 1);

        return Cubemain_ProcessInput(sInput, acOutput);
    }
    else if ( !stricmp(acKey, "output") )
    {
        return Cubemain_ProcessOutput(&pstLineInfo->voutput, acOutput);
    }
    else if ( !stricmp(acKey, "output b") )
    {
        return Cubemain_ProcessOutput(&pstLineInfo->voutputmyspb, acOutput);
    }
    else if ( !stricmp(acKey, "output c") )
    {
        return Cubemain_ProcessOutput(&pstLineInfo->voutputmyspc, acOutput);
    }

    return 0;
}

static int Cubemain_BuildDescription(void *pvLineInfo, char *acOutput, unsigned int iOutputSize)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int i, j, iUse;
    char *pcResult;
    char acBuffer[128] = {0};

    ST_CUBE_INPUT *sInput = (ST_CUBE_INPUT *)pstLineInfo->vinputmysp1;

    ST_CUBE_OUTPUT *sOutputs[] =
    {
        (ST_CUBE_OUTPUT *)pstLineInfo->voutput,
        (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspb,
        (ST_CUBE_OUTPUT *)pstLineInfo->voutputmyspc
    };

    for ( i = 0; i < 3; i++ )
    {
        iUse = 0;
        pcResult = NULL;

        if ( sOutputs[i]->bSpecific && sOutputs[i]->cGrade == GRADE_UNIQ )
        {
            pcResult = Lookup_UniqueItem(sOutputs[i]->sSpecificID);
        }
        else if ( sOutputs[i]->bSpecific && sOutputs[i]->cGrade == GRADE_SET)
        {
            pcResult = Lookup_SetItem(sOutputs[i]->sSpecificID);
        }
        else if ( sOutputs[i]->cType == 0xFC )
        {
            pcResult = String_GetString(Lookup_ItemString(sOutputs[i]->sGenericID), NULL, NULL);
        }
        else if ( sOutputs[i]->cType == 0xFD )
        {
            pcResult = Lookup_ItemType(sOutputs[i]->sGenericID);
        }
        else if ( sOutputs[i]->cType == 0xFE)
        {
            iUse = 1; // useitem
        }
        else if ( sOutputs[i]->cType == 0xFF )
        {
            iUse = 2; // usetype
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x01 )
        {
            pcResult = Lookup_Level(*(unsigned short*)&sOutputs[i]->cGrade);
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x02 )
        {
            sprintf(acBuffer, "%u Skill Points", *(unsigned short*)&sOutputs[i]->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x03 )
        {
            sprintf(acBuffer, "%u Stat Points", *(unsigned short*)&sOutputs[i]->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x04 )
        {
            pcResult = Lookup_MonStats(*(unsigned short*)&sOutputs[i]->cGrade);
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x05 )
        {
            pcResult = Lookup_SuperUnique(*(unsigned short*)&sOutputs[i]->cGrade);
        }
        else if ( isD2SigmaActive() && sOutputs[i]->cType == 0x06 )
        {
            sprintf(acBuffer, "%u Gold Cost", *(unsigned short*)&sOutputs[i]->cGrade);
            pcResult = &acBuffer[0];
        }
        else if ( sOutputs[i]->cType == 0x01 )
        {
            pcResult = "Cow Portal";
        }
        else if ( sOutputs[i]->cType == 0x02 )
        {
            pcResult = "Pandemonium Portal";
        }
        else if ( sOutputs[i]->cType == 0x03 )
        {
            pcResult = "Pandemonium Finale Portal";
        }
        else if ( isRoSActive() && sOutputs[i]->cType == 0x80 )
        {
            pcResult = "Red Portal";
        }
        else if ( isRoSActive() && sOutputs[i]->cType == 0x81 )
        {
            pcResult = "AddStat";
        }
        else if ( isRoSActive() && sOutputs[i]->cType == 0x82 )
        {
            pcResult = Lookup_Set(sOutputs[i]->sPrefix);
        }

        if ( pcResult )
        {
            strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
            if ( strlen(acOutput) < iOutputSize )
            {
                acOutput[strlen(acOutput)] = ' ';
            }
        }

        if ( iUse )
        {
            pcResult = NULL;

            if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_UNIQ )
            {
                pcResult = Lookup_UniqueItem(sInput->sSpecificID);
            }
            else if ( (sInput->bItemCode && sInput->bSpecific) && sInput->cGrade == GRADE_SET )
            {
                pcResult = Lookup_SetItem(sInput->sSpecificID);
            }
            else if ( sInput->bItemCode )
            {
                pcResult = String_GetString(Lookup_ItemString(sInput->sGenericID), NULL, NULL);
            }
            else if ( sInput->bTypeCode )
            {
                pcResult = Lookup_ItemType(sInput->sGenericID);
            }
            else if ( sInput->sGenericID == 0xFFFF )
            {
                pcResult = "Any Item";
            }

            if ( pcResult )
            {
                strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
                if ( strlen(acOutput) < iOutputSize)
                {
                    acOutput[strlen(acOutput)] = ' ';
                }
            }

            for ( j = 0; j < 5; j++ )
            {
                if ( pcResult = Lookup_Property(sOutputs[i]->sMods[j].iMod) )
                {
                    strncpy(&acOutput[strlen(acOutput)], pcResult, iOutputSize-strlen(acOutput));
                    if ( strlen(acOutput) < iOutputSize)
                    {
                        acOutput[strlen(acOutput)] = ' ';
                    }
                }
            }
        }
    }

    return 1;
}

static int Cubemain_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp("description", acKey) )
    {
        char acName[64] = {0};
        Cubemain_BuildDescription(pvLineInfo, acName, 63);
        if ( !String_BuildName(FORMAT(cubemain), 0xFFFF, pcTemplate, acName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }
    else if ( isD2SigmaActive() && CubemainExt_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static void Cubemain_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ladder, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmyspdiff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, CLASS);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, numinputs, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp1, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp2, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp5, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp6, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp7, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, output, STRING);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, lvl, output[9], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, plvl, output[10], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, ilvl, output[11], 1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspb, STRING);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, bmysplvl, outputmyspb[9], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, bmyspplvl, outputmyspb[10], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, bmyspilvl, outputmyspb[11], 1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspc, STRING);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, cmysplvl, outputmyspc[9], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, cmyspplvl, outputmyspc[10], 1, UCHAR);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, cmyspilvl, outputmyspc[11], 1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5, PROPERTY);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);
}

int process_cubemain(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_CUBEMAIN_109) )
    {
        return process_cubemain109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(RoS, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(CubemainExt, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(uniqueitems, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(setitems, acTemplatePath, acBinPath, acTxtPath);
            if ( isRoSActive() )
            {
                MODULE_DEPEND_CALL(sets, acTemplatePath, acBinPath, acTxtPath);
            }
            if ( isD2SigmaActive() )
            {
                MODULE_DEPEND_CALL(levels, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(superuniques, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            Cubemain_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Cubemain_ConvertValue;
            m_stCallback.pfnFieldProc = Cubemain_FieldProc;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? CubemainExt_ExternList : m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


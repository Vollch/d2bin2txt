#include "../global.h"

#define FILE_PREFIX "MonStats2"
#define NAME_PREFIX "mn"

typedef struct
{
    unsigned short vId;
    unsigned char pad0x02[2];

#if 1
    unsigned char vBitCombined1;
    unsigned char vBitCombined2;
    unsigned char vBitCombined3;
#else
    unsigned char vcorpseSel : 1;
    unsigned char vshiftSel : 1;
    unsigned char vnoSel : 1;
    unsigned char valSel : 1;

    unsigned char visSel : 1;
    unsigned char vnoOvly : 1;
    unsigned char vnoMap : 1;
    unsigned char vnoGfxHitTest : 1;

    unsigned char vnoUniqueShift : 1;
    unsigned char vShadow : 1;
    unsigned char vcritter : 1;
    unsigned char vsoft : 1;

    unsigned char vlarge : 1;
    unsigned char vsmall : 1;
    unsigned char visAtt : 1;
    unsigned char vrevive : 1;

    unsigned char bPad5 : 3;
    unsigned char vunflatDead : 1;

    unsigned char vdeadCol : 1;
    unsigned char vobjCol : 1;
    unsigned char vinert : 1;
    unsigned char vcompositeDeath : 1;
#endif
    unsigned char pad0x07;

    unsigned char vSizeX;
    unsigned char vSizeY;
    unsigned char vspawnCol;
    unsigned char vHeight;

    unsigned char vOverlayHeight;
    unsigned char vpixHeight;
    unsigned char vMeleeRng;
    unsigned char pad0x0F;

    unsigned char vBaseW[4];

    unsigned char vHitClass;
    unsigned char vHDvNum;
    unsigned char vTRvNum;
    unsigned char vLGvNum;

    unsigned char vRavNum;
    unsigned char vLavNum;
    unsigned char vRHvNum;
    unsigned char vLHvNum;

    unsigned char vSHvNum;
    unsigned char vS1vNum;
    unsigned char vS2vNum;
    unsigned char vS3vNum;

    unsigned char vS4vNum;
    unsigned char vS5vNum;
    unsigned char vS6vNum;
    unsigned char vS7vNum;

    unsigned char vS8vNum;
    unsigned char pad0x25;

    unsigned char vHDv[12]; //compcode
    unsigned char vTRv[12];
    unsigned char vLGv[12];
    unsigned char vRav[12];
    unsigned char vLav[12];
    unsigned char vRHv[12];
    unsigned char vLHv[12];
    unsigned char vSHv[12];
    unsigned char vS1v[12];
    unsigned char vS2v[12];
    unsigned char vS3v[12];
    unsigned char vS4v[12];
    unsigned char vS5v[12];
    unsigned char vS6v[12];
    unsigned char vS7v[12];
    unsigned char vS8v[12];

    unsigned char pad0xE6[2];

#if 1
    unsigned char vBitCombined4;
    unsigned char vBitCombined5;
#else
    unsigned char vSH : 1;
    unsigned char vLH : 1;
    unsigned char vRH : 1;
    unsigned char vLA : 1;

    unsigned char vRA : 1;
    unsigned char vLG : 1;
    unsigned char vTR : 1;
    unsigned char vHD : 1;

    unsigned char vS8 : 1;
    unsigned char vS7 : 1;
    unsigned char vS6 : 1;
    unsigned char vS5 : 1;

    unsigned char vS4 : 1;
    unsigned char vS3 : 1;
    unsigned char vS2 : 1;
    unsigned char vS1 : 1;
#endif

    unsigned char pad0xEA[2];

    unsigned int vTotalPieces;

#if 1
    unsigned char vBitCombined6;
    unsigned char vBitCombined7;
#else
    unsigned char vmSC : 1;
    unsigned char vmBL : 1;
    unsigned char vmA2 : 1;
    unsigned char vmA1 : 1;

    unsigned char vmGH : 1;
    unsigned char vmWL : 1;
    unsigned char vmNU : 1;
    unsigned char vmDT : 1;

    unsigned char vmRN : 1;
    unsigned char vmSQ : 1;
    unsigned char vmKB : 1;
    unsigned char vmDD : 1;

    unsigned char vmS4 : 1;
    unsigned char vmS3 : 1;
    unsigned char vmS2 : 1;
    unsigned char vmS1 : 1;
#endif

    unsigned char pad0xF2[2];

    unsigned char vdDT;
    unsigned char vdNU;
    unsigned char vdWL;
    unsigned char vdGH;

    unsigned char vdA1;
    unsigned char vdA2;
    unsigned char vdBL;
    unsigned char vdSC;

    unsigned char vdS1;
    unsigned char vdS2;
    unsigned char vdS3;
    unsigned char vdS4;

    unsigned char vdDD;
    unsigned char vdKB;
    unsigned char vdSQ;
    unsigned char vdRN;

#if 1
    unsigned char vBitCombined8;
    unsigned char vBitCombined9;
#else
    unsigned char vSCmv : 1;
    unsigned char b2Pad14 : 1;
    unsigned char vA2mv : 1;
    unsigned char vA1mv : 1;
    unsigned char b2Pad8 : 4;

    unsigned char b2Pad4 : 4;
    unsigned char vS4mv : 1;
    unsigned char vS3mv : 1;
    unsigned char vS2mv : 1;
    unsigned char vS1mv : 1;
#endif

    unsigned char pad0x106[2];

    unsigned char vInfernoLen;
    unsigned char vInfernoAnim;
    unsigned char vInfernoRollback;
    unsigned char vResurrectMode; //monmode

    unsigned short vResurrectSkill; //skills
    short vhtTop;

    short vhtLeft;
    short vhtWidth;

    short vhtHeight;
    unsigned char pad0x116[2];

    unsigned int vautomapCel;

    unsigned char vlocalBlood;
    unsigned char vBleed;
    unsigned char vLight;
    unsigned char vlightmysubr;

    unsigned char vlightmysubg;
    unsigned char vlightmysubb;
    unsigned char vUtrans;
    unsigned char vUtransmybr1Nmybr2;

    unsigned char vUtransmybr1Hmybr2;
    unsigned char pad0x125[3];

    unsigned char vHeart[4];
    unsigned char vBodyPart[4];

    unsigned int vrestore;
} ST_LINE_INFO;//total 308 bytes

typedef struct
{
    unsigned char vId[32];
} ST_MONSTAT;

static unsigned int m_iMonStatsCount = 0;
static unsigned int m_iMonStatsHaveEmpty = 0;
static ST_MONSTAT *m_astMonStats = NULL;

MODULE_SETLINES_FUNC(m_astMonStats, ST_MONSTAT);

static char *MonStats2_GetStatsName(unsigned int id)
{
    if ( id < m_iMonStatsCount )
    {
        return m_astMonStats[id].vId;
    }

    if ( id == -1 && m_iMonStatsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonStats2_ConvertValue_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;

    if ( !stricmp(acKey, "Id") )
    {
        if ( pcResult = Lookup_MonStats(pstLineInfo->vId) )
        {
            strcpy(acOutput, pcResult);
        }

        strncpy(m_astMonStats[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonStats[pstLineInfo->vId].vId));
        String_Trim(m_astMonStats[pstLineInfo->vId].vId);
        m_iMonStatsHaveEmpty |= !m_astMonStats[pstLineInfo->vId].vId[0];

        m_iMonStatsCount++;
        return 1;
    }

    return 0;
}

static char *MonStats2_GenerateList(ST_LINE_INFO *pstLineInfo, unsigned int count, unsigned char *pbList, unsigned int uiListNum, char *acOutput)
{
    unsigned int i;
    char *pcResult;

    if ( 1 < count )
    {
        acOutput[0] = '"';
        acOutput++;
    }

    for ( i = 0; i < uiListNum && i < count; i++ )
    {
        pcResult = Lookup_CompCode(pbList[i]);
        if ( !pcResult )
        {
            pcResult = g_pcFallbackCode;
        }

        if ( i > 0 )
        {
            acOutput[0] = ',';
            acOutput++;
        }
        strcpy(acOutput, pcResult);
        String_Trim(acOutput);
        acOutput += strlen(acOutput);
    }

    if ( 1 < count )
    {
        acOutput[0] = '"';
        acOutput++;
    }

    return acOutput;
}

static int MonStats2_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "HDv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vHDvNum, pstLineInfo->vHDv, sizeof(pstLineInfo->vHDv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "TRv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vTRvNum, pstLineInfo->vTRv, sizeof(pstLineInfo->vTRv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "LGv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vLGvNum, pstLineInfo->vLGv, sizeof(pstLineInfo->vLGv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "Rav") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vRavNum, pstLineInfo->vRav, sizeof(pstLineInfo->vRav), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "Lav") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vLavNum, pstLineInfo->vLav, sizeof(pstLineInfo->vLav), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "RHv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vRHvNum, pstLineInfo->vRHv, sizeof(pstLineInfo->vRHv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "LHv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vLHvNum, pstLineInfo->vLHv, sizeof(pstLineInfo->vLHv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "SHv") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vSHvNum, pstLineInfo->vSHv, sizeof(pstLineInfo->vSHv), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S1v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS1vNum, pstLineInfo->vS1v, sizeof(pstLineInfo->vS1v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S2v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS2vNum, pstLineInfo->vS2v, sizeof(pstLineInfo->vS2v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S3v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS3vNum, pstLineInfo->vS3v, sizeof(pstLineInfo->vS3v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S4v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS4vNum, pstLineInfo->vS4v, sizeof(pstLineInfo->vS4v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S5v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS5vNum, pstLineInfo->vS5v, sizeof(pstLineInfo->vS5v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S6v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS6vNum, pstLineInfo->vS6v, sizeof(pstLineInfo->vS6v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S7v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS7vNum, pstLineInfo->vS7v, sizeof(pstLineInfo->vS7v), acOutput);

        return 1;
    }
    else if ( !stricmp(acKey, "S8v") )
    {
        MonStats2_GenerateList(pstLineInfo, pstLineInfo->vS8vNum, pstLineInfo->vS8v, sizeof(pstLineInfo->vS8v), acOutput);

        return 1;
    }

    return 0;
}

static void MonStats2_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, MONSTAT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, corpseSel, BitCombined1, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, shiftSel, BitCombined1, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noSel, BitCombined1, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, alSel, BitCombined1, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, isSel, BitCombined1, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noOvly, BitCombined1, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noMap, BitCombined1, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noGfxHitTest, BitCombined1, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, noUniqueShift, BitCombined2, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, Shadow, BitCombined2, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, critter, BitCombined2, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, soft, BitCombined2, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, large, BitCombined2, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, small, BitCombined2, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, isAtt, BitCombined2, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, revive, BitCombined2, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, unflatDead, BitCombined3, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, deadCol, BitCombined3, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, objCol, BitCombined3, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, inert, BitCombined3, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, compositeDeath, BitCombined3, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnCol, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayHeight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pixHeight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MeleeRng, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseW, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HDv, STRING); //compcode

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TRv, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LGv, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rav, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lav, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RHv, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LHv, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SHv, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S5v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S6v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S7v, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S8v, STRING);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SH, BitCombined4, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, LH, BitCombined4, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, RH, BitCombined4, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, LA, BitCombined4, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, RA, BitCombined4, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, LG, BitCombined4, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, TR, BitCombined4, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, HD, BitCombined4, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S8, BitCombined5, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S7, BitCombined5, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S6, BitCombined5, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S5, BitCombined5, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S4, BitCombined5, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S3, BitCombined5, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S2, BitCombined5, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S1, BitCombined5, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TotalPieces, UINT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mSC, BitCombined6, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mBL, BitCombined6, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mA2, BitCombined6, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mA1, BitCombined6, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mGH, BitCombined6, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mWL, BitCombined6, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mNU, BitCombined6, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mDT, BitCombined6, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mRN, BitCombined7, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mSQ, BitCombined7, 6, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mKB, BitCombined7, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mDD, BitCombined7, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mS4, BitCombined7, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mS3, BitCombined7, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mS2, BitCombined7, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, mS1, BitCombined7, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dDT, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dNU, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dWL, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dGH, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dA1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dA2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dBL, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dSC, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dS1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dS2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dS3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dS4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dDD, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dKB, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dSQ, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dRN, UCHAR);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, SCmv, BitCombined8, 7, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, A2mv, BitCombined8, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, A1mv, BitCombined8, 4, UCHAR_BIT);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S4mv, BitCombined9, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S3mv, BitCombined9, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S2mv, BitCombined9, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, S1mv, BitCombined9, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InfernoLen, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InfernoAnim, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InfernoRollback, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResurrectMode, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResurrectSkill, SKILL);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, htTop, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, htLeft, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, htWidth, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, htHeight, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, automapCel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, localBlood, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Bleed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubr, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubg, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubb, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utrans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utransmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Utransmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Heart, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyPart, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, restore, UINT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, EOL, EOL);
}

int process_monstats2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            MonStats2_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonStatsCount = 0;
            Lookup_MonStats2 = MonStats2_GetStatsName;

            m_stCallback.pfnConvertValue = MonStats2_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(compcode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonStats2_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = MonStats2_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


#include "global.h"

#define FILE_PREFIX "shrines"
#define NAME_PREFIX "sr"

typedef struct
{
    unsigned char vCode;
    unsigned char vpad0x01[3];

    unsigned int vArg0;
    unsigned int vArg1;

    unsigned int vDurationmyspinmyspframes;

    unsigned char vresetmysptimemyspinmyspminutes;
    unsigned char vrarity;
    unsigned char vviewmyspname[32];

    unsigned char vniftyphrase[32];

    unsigned char vpad0x52[96];

    unsigned char veffectclass;
    unsigned char vpad0xB3;

    unsigned int vLevelMin;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Shrine name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Shrine Type",
    "Effect",
    NULL,
};

static int Shrines_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Shrine name") )
    {
        if ( !String_BuildName(FORMAT(shrines), 0xFFFF, pcTemplate, NAME_PREFIX, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_shrines(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Arg0, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Arg1, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Durationmyspinmyspframes, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, resetmysptimemyspinmyspminutes, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, viewmyspname, STRING);

    if ( isD2DreamlandActive() )
    {
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Niftyphrase, pad0x01[0], USHORT_STRING);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Func, pad0x01[2], CHAR);

        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StateID, niftyphrase[0], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StatID, niftyphrase[4], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StatID2, niftyphrase[6], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StatID3, niftyphrase[8], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StatID4, niftyphrase[10], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Arg2, niftyphrase[12], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Arg3, niftyphrase[16], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, IsTown, niftyphrase[20], CHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, DestLvl, niftyphrase[21], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, ObjectID, niftyphrase[25], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, MissileID, niftyphrase[29], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, BossType, niftyphrase[31], CHAR);

        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, MinionMin, pad0x52[0], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, MinionMax, pad0x52[2], USHORT);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode, pad0x52[4], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCodeNM, pad0x52[8], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCodeHell, pad0x52[12], 4, STRING);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Quantity, pad0x52[16], USHORT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, SoundID, pad0x52[18], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, CltFunc1, pad0x52[22], CHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, CltFunc2, pad0x52[23], CHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Overlay1, pad0x52[24], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Overlay2, pad0x52[28], UINT);

        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, StateID2, pad0x52[32], UINT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Class, pad0x52[36], UINT);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode2, pad0x52[40], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode3, pad0x52[44], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode2NM, pad0x52[48], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode3NM, pad0x52[52], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode2Hell, pad0x52[56], 4, STRING);
        VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, itemCode3Hell, pad0x52[60], 4, STRING);

        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, picks, pad0x52[83], CHAR);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, TreasureClass, pad0x52[84], USHORT_TREASURE);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, iLvl, pad0x52[88], INT);
        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, LevelMax, pad0x52[92], INT);

        VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, Enabled, pad0xB3, CHAR);
    }
    else
    {
        VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, niftyphrase, STRING);
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, effectclass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelMin, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(DreamlandConfig, acTemplatePath, acBinPath, acTxtPath);
            if ( isD2DreamlandActive() )
            {
                MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
                MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            }
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = Shrines_FieldProc;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}


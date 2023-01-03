#include "../global.h"

#define FILE_PREFIX "SetItems"

static void SetItems_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_SETITEMS_109 *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumItems, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transform, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item1myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item2myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item3myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item4myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item5myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspRarity, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspLvlreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspcostmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspcostmyspadd, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspAdd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Item6myspSuffix, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I1MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I2MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I3MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I4MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I5MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Code1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Param1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Max1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Code2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Param2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6Max2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6CodeA, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6ParamA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MinA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MaxA, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6CodeB, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6ParamB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MinB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MaxB, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6CodeC, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6ParamC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MinC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MaxC, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6CodeD, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6ParamD, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MinD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MaxD, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6CodeE, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6ParamE, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MinE, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, I6MaxE, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax6, INT);
}

int process_setitems109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_SETITEMS_109 *pstLineInfo = (ST_SETITEMS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            SetItems_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


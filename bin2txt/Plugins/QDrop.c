#include "../global.h"

#define FILE_PREFIX "hforge"

typedef struct
{
    unsigned int vDifficulty;
    unsigned char vrune1[4];
    unsigned char vrune2[4];
    unsigned char vrune3[4];
    unsigned char vrune4[4];
    unsigned char vrune5[4];
    unsigned char vrune6[4];
    unsigned char vrune7[4];
    unsigned char vrune8[4];
    unsigned char vrune9[4];
    unsigned char vrune10[4];
    unsigned char vrune11[4];
    unsigned char vgem1[4];
    unsigned char vgem2[4];
    unsigned char vgem3[4];
    unsigned char vgem4[4];
    unsigned char vgem5[4];
    unsigned char vgem6[4];
    unsigned char vgem7[4];
    unsigned char vgem8[4];
    unsigned char vgem9[4];
    unsigned char vgem10[4];
    unsigned char vgem11[4];
    unsigned char vgem12[4];
    unsigned char vgem13[4];
    unsigned char vgem14[4];
    unsigned char vgem15[4];
    unsigned char vgem16[4];
    unsigned char vgem17[4];
    unsigned char vgem18[4];
    unsigned char vgem19[4];
    unsigned char vgem20[4];
    unsigned char vgem21[4];
    unsigned char vandariel1[4];
    unsigned char vandariel2[4];
    unsigned char vandariel3[4];
    unsigned char vandariel4[4];
    unsigned char vandariel5[4];
    unsigned char vandariel6[4];
    unsigned char vandariel7[4];
    unsigned char vandariel8[4];
    unsigned char vandariel9[4];
    unsigned char vandariel10[4];
    unsigned char vandariel11[4];
    unsigned char vandariel12[4];
    unsigned char vandariel13[4];
    unsigned char vandariel14[4];
} ST_LINE_INFO;

static int QDrop_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Difficulty") )
    {
        if ( pstLineInfo->vDifficulty == 0 )
        {
            strcpy(acOutput, "Normal");
        }
        else if ( pstLineInfo->vDifficulty == 1 )
        {
            strcpy(acOutput, "Nightmare");
        }
        else if ( pstLineInfo->vDifficulty == 2 )
        {
            strcpy(acOutput, "Hell");
        }

        return 1;
    }

    return 0;
}

int process_QDrop(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rune11, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem11, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem12, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem13, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem14, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem15, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem16, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem17, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem18, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem19, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem20, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gem21, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel11, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel12, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel13, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, andariel14, STRING);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnConvertValue = QDrop_ConvertValue;

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


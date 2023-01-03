#include "../global.h"

#define FILE_PREFIX "D2StatsEx2"

#pragma pack(push, 1)
typedef struct
{
    unsigned char pad0x00[8];
    unsigned int vHcIDx;
    char vEnabled;
    unsigned char vPanel[16];
    unsigned char vMainFunc[16];
    unsigned char vSubFunc[16];
    unsigned int vCondition; // skillcode
    unsigned char vClass; // class
    int vMouseLeft;
    int vMouseRight;
    int vMouseTop;
    int vMouseBottom;
    unsigned short vStringID; // string
    unsigned int vStatID; // itemstat
    unsigned int vStatCalc; // itemcode
    unsigned char vFont;
    unsigned int vStringColor; // itemcode
    int vStringLeft;
    int vStringRight;
    int vStringY;
    unsigned char vAnchor[16];
    int vBoxLeft;
    int vBoxRight;
    int vBoxTop;
    int vBoxBottom;
    unsigned char vBoxStyle[16];
    unsigned char vBorderColor[16];
    unsigned char vGFXFile[16];
    unsigned int vGFXFrame;
    unsigned char vDrawMode;
    unsigned char pad0xC2[7];
} ST_LINE_INFO;
#pragma pack(pop)


int process_D2StatsEx2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HcIDx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Enabled, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Panel, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MainFunc, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubFunc, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Condition, SKILLCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, CLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseBottom, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StringID, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatID, ITEMSTAT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatCalc, ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Font, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StringColor, ITEMCODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StringLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StringRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StringY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Anchor, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BoxLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BoxRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BoxTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BoxBottom, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BoxStyle, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BorderColor, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GFXFile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GFXFrame, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawMode, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skillscode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemscode, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


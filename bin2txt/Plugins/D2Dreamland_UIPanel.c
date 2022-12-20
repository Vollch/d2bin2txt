#include "../global.h"

#define FILE_PREFIX "UIPanel"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    char vFunc;
    char vsetFont;
    int vXpos;
    int vYpos;
    char vAlwaysDisplay;
    int vMouseX1;
    int vMouseX2;
    int vMouseY1;
    int vMouseY2;
    int vStatID;
    int vStatID2;
    int vOrbFrame;
    int vOverlayFrame;
    int vStateID;
    int vOverlayXpos;
    int vOverlayYpos;
    int vUIFrame;
    unsigned int vitemType1; // itemtype
    unsigned int vitemType2; // itemtype
    unsigned int vitemType3; // itemtype
    unsigned int vitemType4; // itemtype
    unsigned int vitemType5; // itemtype
    unsigned int vitemType6; // itemtype
    unsigned int vitemType7; // itemtype
    unsigned int vitemType8; // itemtype
    unsigned int vitemType9; // itemtype
    unsigned int vitemType10; // itemtype
    unsigned short vstringKey; // string
    int vgamma;
    int vdrawMode;
    int vtextColor;
    int vdrawMode2;
    int vdrawMode3;
    int vtransparency;
    int valpha;
    int vred1;
    int vred2;
    int vred3;
    int vgreen1;
    int vgreen2;
    int vgreen3;
    int vblue1;
    int vblue2;
    int vblue3;
    int vsound;
    char vd2modhighres;
    int vAddBarXpos;
    int vminDrawX;
    unsigned char vcharclass1; // class
    unsigned char vcharclass2; // class
    unsigned char vcharclass3; // class
    unsigned char vcharclass4; // class
    unsigned char vcharclass5; // class
    unsigned char vcharclass6; // class
    unsigned char vcharclass7; // class
} ST_LINE_INFO;
#pragma pack(pop)

int process_UIPanel(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Func, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setFont, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xpos, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Ypos, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysDisplay, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseX1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseX2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseY1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MouseY2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatID, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatID2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrbFrame, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayFrame, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StateID, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayXpos, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OverlayYpos, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UIFrame, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType1, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType2, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType3, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType4, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType5, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType6, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType7, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType8, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType9, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemType10, USHORT_ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stringKey, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gamma, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, drawMode, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, textColor, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, drawMode2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, drawMode3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transparency, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, alpha, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, red1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, red2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, red3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, green1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, green2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, green3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, blue1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, blue2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, blue3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sound, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, d2modhighres, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AddBarXpos, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minDrawX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass1, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass2, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass3, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass4, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass5, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass6, UCHAR_PLRCLASS);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, charclass7, UCHAR_PLRCLASS);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
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


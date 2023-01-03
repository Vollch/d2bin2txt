#include "../global.h"

#define FILE_PREFIX "Npc2"
#define NAME_PREFIX "nt"

#pragma pack(push, 1)
typedef struct
{
    unsigned int vhcIdx;
    unsigned int vNpcID;
    char vVendorID;
    char vInventory;
    char vButtonType;
    char vVendorSell;
    char vRepair;
    int vVendoriLvl;
    char vMenu;
    char vNbrMenuItems;
    unsigned short vMenuItemTxt1; //string
    unsigned short vMenuItemTxt2; //string
    unsigned short vMenuItemTxt3; //string
    unsigned short vMenuItemTxt4; //string
    unsigned short vMenuItemTxt5; //string
    char vMenuItemFunc1;
    char vMenuItemFunc2;
    char vMenuItemFunc3;
    char vMenuItemFunc4;
    char vMenuItemFunc5;
    char vNbrSubMenu;
    unsigned short vSubMenu1; //string
    unsigned short vSubMenu2; //string
    unsigned short vSubMenu3; //string
    unsigned short vSubMenu4; //string
    unsigned short vSubMenu5; //string
    unsigned short vSubMenu6; //string
    unsigned short vSubMenuStringKey1; //string
    unsigned short vSubMenuStringKey2; //string
    unsigned short vSubMenuStringKey3; //string
    unsigned short vSubMenuStringKey4; //string
    unsigned short vSubMenuStringKey5; //string
    unsigned short vSubMenuStringKey6; //string
    char vTravelOption;
    unsigned short vDestLvl;
    char vHeal;
    char vNbrSubMenuItems;
    unsigned short vSubMenuItemTxt1; //string
    unsigned short vSubMenuItemTxt2; //string
    unsigned short vSubMenuItemTxt3; //string
    unsigned short vSubMenuItemTxt4; //string
    unsigned short vSubMenuItemTxt5; //string
    unsigned short vSubMenuItemTxt6; //string
    char vSubMenuItemFunc1;
    char vSubMenuItemFunc2;
    char vSubMenuItemFunc3;
    char vSubMenuItemFunc4;
    char vSubMenuItemFunc5;
    char vSubMenuItemFunc6;
    char vIdentify;
    char vUseGreetingSound;
    unsigned int vGreetingSoundID;
    char vAct;
    char vForceVendor;
    char vTrade;
    char vGamble;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int Npc2_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        if ( !String_BuildName(FORMAT(Npc2), 0xFFFF, pcTemplate, Lookup_MonStats(pstLineInfo->vNpcID), iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_Npc2(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NpcID, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VendorID, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Inventory, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ButtonType, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VendorSell, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Repair, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VendoriLvl, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Menu, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NbrMenuItems, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemTxt1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemTxt2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemTxt3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemTxt4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemTxt5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemFunc1, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemFunc2, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemFunc3, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemFunc4, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MenuItemFunc5, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NbrSubMenu, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenu6, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuStringKey6, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TravelOption, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DestLvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Heal, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NbrSubMenuItems, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt1, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt2, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt3, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt4, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt5, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemTxt6, TBL_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc1, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc2, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc3, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc4, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc5, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMenuItemFunc6, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Identify, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UseGreetingSound, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GreetingSoundID, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ForceVendor, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trade, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gamble, CHAR);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = Npc2_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


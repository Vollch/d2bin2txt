#include "../global.h"

#define FILE_PREFIX "MysticOrbs"

#pragma pack(push, 1)
typedef struct
{
    unsigned char vName[32];
    unsigned char vaddLevel;
    unsigned short vtypeString;
    unsigned short vitype1;
    unsigned short vitype2;
    unsigned short vetype1;
    unsigned short vetype2;
    unsigned short vlimit;

    unsigned int vprop1;
    unsigned int vpar1;
    int vmin1;
    int vmax1;

    unsigned int vprop2;
    unsigned int vpar2;
    int vmin2;
    int vmax2;

    unsigned int vprop3;
    unsigned int vpar3;
    int vmin3;
    int vmax3;

    unsigned int vprop4;
    unsigned int vpar4;
    int vmin4;
    int vmax4;

    unsigned int vprop5;
    unsigned int vpar5;
    int vmin5;
    int vmax5;

    unsigned int vprop6;
    unsigned int vpar6;
    int vmin6;
    int vmax6;
} ST_LINE_INFO;
#pragma pack(pop)

int process_MysticOrbs(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, addLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, typeString, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, ITEMTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, limit, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop1, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop2, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop3, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop4, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop5, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,prop6, PROPERTY);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,par6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo,max6, INT);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
        default:
            break;
    }

    return 1;
}


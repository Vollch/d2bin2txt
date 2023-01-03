#include "../global.h"

#define FILE_PREFIX "D2Vendors"
#define NAME_PREFIX "vd"

#pragma pack(push, 1)
typedef struct
{
    int vhcIDx;
    unsigned short vnItems;

    char vi0min;
    char vi0max;
    char vi0magMin;
    char vi0magMax;
    char vi0magLvl;
    char vi0perm;
    char vi0itemcode[4];

    char vi1min;
    char vi1max;
    char vi1magMin;
    char vi1magMax;
    char vi1magLvl;
    char vi1perm;
    char vi1itemcode[4];

    char vi2min;
    char vi2max;
    char vi2magMin;
    char vi2magMax;
    char vi2magLvl;
    char vi2perm;
    char vi2itemcode[4];

    char vi3min;
    char vi3max;
    char vi3magMin;
    char vi3magMax;
    char vi3magLvl;
    char vi3perm;
    char vi3itemcode[4];

    char vi4min;
    char vi4max;
    char vi4magMin;
    char vi4magMax;
    char vi4magLvl;
    char vi4perm;
    char vi4itemcode[4];

    char vi5min;
    char vi5max;
    char vi5magMin;
    char vi5magMax;
    char vi5magLvl;
    char vi5perm;
    char vi5itemcode[4];

    char vi6min;
    char vi6max;
    char vi6magMin;
    char vi6magMax;
    char vi6magLvl;
    char vi6perm;
    char vi6itemcode[4];

    char vi7min;
    char vi7max;
    char vi7magMin;
    char vi7magMax;
    char vi7magLvl;
    char vi7perm;
    char vi7itemcode[4];

    char vi8min;
    char vi8max;
    char vi8magMin;
    char vi8magMax;
    char vi8magLvl;
    char vi8perm;
    char vi8itemcode[4];

    char vi9min;
    char vi9max;
    char vi9magMin;
    char vi9magMax;
    char vi9magLvl;
    char vi9perm;
    char vi9itemcode[4];

    char vi10min;
    char vi10max;
    char vi10magMin;
    char vi10magMax;
    char vi10magLvl;
    char vi10perm;
    char vi10itemcode[4];

    char vi11min;
    char vi11max;
    char vi11magMin;
    char vi11magMax;
    char vi11magLvl;
    char vi11perm;
    char vi11itemcode[4];

    char vi12min;
    char vi12max;
    char vi12magMin;
    char vi12magMax;
    char vi12magLvl;
    char vi12perm;
    char vi12itemcode[4];

    char vi13min;
    char vi13max;
    char vi13magMin;
    char vi13magMax;
    char vi13magLvl;
    char vi13perm;
    char vi13itemcode[4];

    char vi14min;
    char vi14max;
    char vi14magMin;
    char vi14magMax;
    char vi14magLvl;
    char vi14perm;
    char vi14itemcode[4];

    char vi15min;
    char vi15max;
    char vi15magMin;
    char vi15magMax;
    char vi15magLvl;
    char vi15perm;
    char vi15itemcode[4];

    char vi16min;
    char vi16max;
    char vi16magMin;
    char vi16magMax;
    char vi16magLvl;
    char vi16perm;
    char vi16itemcode[4];

    char vi17min;
    char vi17max;
    char vi17magMin;
    char vi17magMax;
    char vi17magLvl;
    char vi17perm;
    char vi17itemcode[4];

    char vi18min;
    char vi18max;
    char vi18magMin;
    char vi18magMax;
    char vi18magLvl;
    char vi18perm;
    char vi18itemcode[4];

    char vi19min;
    char vi19max;
    char vi19magMin;
    char vi19magMax;
    char vi19magLvl;
    char vi19perm;
    char vi19itemcode[4];

    char vi20min;
    char vi20max;
    char vi20magMin;
    char vi20magMax;
    char vi20magLvl;
    char vi20perm;
    char vi20itemcode[4];

    char vi21min;
    char vi21max;
    char vi21magMin;
    char vi21magMax;
    char vi21magLvl;
    char vi21perm;
    char vi21itemcode[4];

    char vi22min;
    char vi22max;
    char vi22magMin;
    char vi22magMax;
    char vi22magLvl;
    char vi22perm;
    char vi22itemcode[4];

    char vi23min;
    char vi23max;
    char vi23magMin;
    char vi23magMax;
    char vi23magLvl;
    char vi23perm;
    char vi23itemcode[4];

    char vi24min;
    char vi24max;
    char vi24magMin;
    char vi24magMax;
    char vi24magLvl;
    char vi24perm;
    char vi24itemcode[4];

    char vi25min;
    char vi25max;
    char vi25magMin;
    char vi25magMax;
    char vi25magLvl;
    char vi25perm;
    char vi25itemcode[4];

    char vi26min;
    char vi26max;
    char vi26magMin;
    char vi26magMax;
    char vi26magLvl;
    char vi26perm;
    char vi26itemcode[4];

    char vi27min;
    char vi27max;
    char vi27magMin;
    char vi27magMax;
    char vi27magLvl;
    char vi27perm;
    char vi27itemcode[4];

    char vi28min;
    char vi28max;
    char vi28magMin;
    char vi28magMax;
    char vi28magLvl;
    char vi28perm;
    char vi28itemcode[4];

    char vi29min;
    char vi29max;
    char vi29magMin;
    char vi29magMax;
    char vi29magLvl;
    char vi29perm;
    char vi29itemcode[4];

    char vUseNextLine;
} ST_LINE_INFO;
#pragma pack(pop)

static char *m_apcInternalProcess[] =
{
    "*desc",
    NULL,
};

static int D2Vendors_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "*desc") )
    {
        char* pcName = NULL;
        if ( pstLineInfo->vhcIDx > 0 )
        {
            pcName = Lookup_MonStats(pstLineInfo->vhcIDx);
        }
        if ( !String_BuildName(FORMAT(D2Vendors), 0xFFFF, pcTemplate, pcName, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}


int process_D2Vendors(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIDx, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nItems, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i0itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i1itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i2itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i3itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i4itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i5itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i6itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i7itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i8itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i9itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i10itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i11itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i12itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i13itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i14itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i15itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i16itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i17itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i18itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i19itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i20itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i21itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i22itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i23itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i24itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i25itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i26itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i27itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i28itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29min, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29max, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29magMin, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29magMax, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29magLvl, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29perm, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, i29itemcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UseNextLine, CHAR);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            m_stCallback.eModuleType = EN_MODULE_PLUGIN;
            m_stCallback.pfnFieldProc = D2Vendors_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);

        default:
            break;
    }

    return 1;
}


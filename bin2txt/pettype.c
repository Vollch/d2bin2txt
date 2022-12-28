#include "global.h"

#define FILE_PREFIX "pettype"
#define NAME_PREFIX "pt"

/*
PetType.txt

pet type = name of the pet type, the "pettype" in skills.txt refers to this

idx = id number of the pet type

group = what group the pet belongs to, you can only have one pet type from each group i.e. Druid spiritwolf/fenris/grizzly

basemax = not absolutely sure. might be that if there's a 1 here the max number of this pet that you can have is always one. A 0 would mean the skills can change this.

warp = does the pet teleport with you, i.e. townportals, waypoints, cave entrances... 1=yes

ranged = if the pet uses ranged attacks, 1=yes

partysend = is the pet's icon displayed in the upper left corner, 1=yes

unsummon = can the pet be unsummoned with the "unsummon" skill, 1=yes

automap = is the pet displayed on the map, 1=yes

name = string file for the text under the pet's icon

drawhp = is the pet's life displayed under its icon, 1=yes

icontype = the type of the pet icon, I believe this determines in what order the icons are displayed in the upper left corner, 1= left 2= middle, 3= right

baseicon = the .dc6 file for the pet's icon, located in dataglobaluihireables

mclass1-4 = the alternative (of the same type) pets' hcldx numbers (ie golems)

micon1-4 = the alternative pet's .dc6 icons.

eol = end of line.

*/

/*
PetType.txt 导引（召唤系）（pet->宠物->召唤系）
A.pet type = 召唤系的类型名（如golem-石魔，skeleton-骷髅），skills.txt中的‘pettype’列参考此值。
B.idx = 召唤系的数字ID
C.group = 召唤系属于哪个组，每一个组中你只能有一种类型的召唤系，如druid的spiritwolf/fenris/grizzly，事实上，整个pettype.txt中也就仅此一组。
D.basemax = 尚不能确定。可能情况：1=一次拥有的该召唤的最大数目为1个；0=可通过技能改变。
E.warp = 召唤系是否能随你一起传送。如踩路点，洞穴入口，townportals。1=可以，0=否。
F.range = 该召唤系是否使用范围攻击。1=是，0=否。
G.partysend = 召唤系图标是否在左上角显示。1=是，0=否。
H.unsummon = 该召唤系是否能通过技能’unsummon（解散）‘解除召唤。1=可以，0=否。
I,automap = 该召唤系是否显示在地图上。1=是，0=否。
J.name = 显示在召唤系图标下方的字符串文件。
K.drawhp = 召唤系的生命值是否在图标下方显示。1=是，0=否。
L.icontype = 该召唤系的图标类型。可能决定了图标在屏幕左上方的排列顺序，1=左边，2=中间，3=右边。
M.baseicon = 该召唤系图标的使用的dc6文件，位于’data\global\ui\hireables\ ‘。
N/P/R/T.mclass1-4 = 供选择的（同类型）召唤系的hcldx数字，如石魔。
O/Q/S/U.micon1-4 = 供选择的召唤系图标，dc6格式。
v.eol = 行结束符‘0’
*/

typedef struct
{
    unsigned int vpetmysptype;

#if 1
    unsigned char vCombinedBit;
#else
    unsigned char iPadding1 : 2;
    unsigned char vdrawhp : 1;
    unsigned char vautomap : 1;

    unsigned char vunsummon : 1;
    unsigned char vpartysend : 1;
    unsigned char vrange : 1;
    unsigned char vwarp : 1;
#endif

    unsigned char pad0x05[3];

    unsigned short vgroup;
    unsigned short vbasemax;

    unsigned short vname;   //string
    unsigned char vicontype;
    unsigned char vbaseicon[32];
    unsigned char vmicon1[32];
    unsigned char vmicon2[32];
    unsigned char vmicon3[32];
    unsigned char vmicon4[32];
    unsigned char pad0x90;

    unsigned char pad0x91[2];
    unsigned short vmclass1;

    unsigned short vmclass2;
    unsigned short vmclass3;

    unsigned short vmclass4;
    unsigned char pad0xBA[2];

    unsigned char pad0xBC[36];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vpetmysptype[64];
} ST_PETTYPE;

static char *m_apcInternalProcess[] =
{
    "idx",
    NULL,
};

static unsigned int m_iPetTypeCount = 0;
static unsigned int m_iPetTypeHaveEmpty = 0;
static ST_PETTYPE *m_astPetTypes = NULL;

MODULE_SETLINES_FUNC(m_astPetTypes, ST_PETTYPE);
MODULE_HAVENAME_FUNC(m_astPetTypes, vpetmysptype, m_iPetTypeCount);

char *Pettype_GetPetType(unsigned int id)
{
    if ( id < m_iPetTypeCount )
    {
        return m_astPetTypes[id].vpetmysptype;
    }

    if ( id == 0xFF && m_iPetTypeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int PetType_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "pet type") )
    {
        char acName[33] = {0};
        strncpy(acName, pstLineInfo->vbaseicon, sizeof(pstLineInfo->vbaseicon));

        if ( !String_BuildName(FORMAT(pettype), pstLineInfo->vname, pcTemplate, acName, pstLineInfo->vpetmysptype, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vpetmysptype);
        }

        strncpy(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype, acOutput, sizeof(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype));
        String_Trim(m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype);
        m_iPetTypeHaveEmpty |= !m_astPetTypes[pstLineInfo->vpetmysptype].vpetmysptype[0];

        m_iPetTypeCount++;
        return 1;
    }

    return 0;
}

static int PetType_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "idx") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vpetmysptype);

        return 1;
    }
    else if ( isD2SigmaActive() && PetTypeExt_ExternProc(pvLineInfo, acKey, iLineNo, pcTemplate, acOutput) )
    {
        return 1;
    }

    return 0;
}

static char *PetType_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    sprintf(pcKey, "%u", pstLineInfo->vpetmysptype);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

static void PetType_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, petmysptype, UCHAR_PET);

    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, drawhp, CombinedBit, 5, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, automap, CombinedBit, 4, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, unsummon, CombinedBit, 3, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, partysend, CombinedBit, 2, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, range, CombinedBit, 1, UCHAR_BIT);
    VALUE_MAP_DEFINE_SIZED(pstValueMap, pstLineInfo, warp, CombinedBit, 0, UCHAR_BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, basemax, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, icontype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseicon, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass4, USHORT);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, eol, EOL);
}

int process_pettype(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(PetTypeExt, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            PetType_InitValueMap(pstValueMap, pstLineInfo);

            m_iPetTypeCount = 0;

            m_stCallback.pfnConvertValue = PetType_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
            //m_stCallback.pfnGetKey = PetType_GetKey;
            m_stCallback.pfnFieldProc = PetType_FieldProc;
            m_stCallback.ppcKeyInternalProcess = isD2SigmaActive() ? PetTypeExt_ExternList : m_apcInternalProcess;

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


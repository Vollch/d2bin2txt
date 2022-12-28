#include "global.h"

#define FILE_PREFIX "montype"
#define NAME_PREFIX "mt"

/*
Type: This is the ID-pointer that is used to link this MonType to a monster in MonStats.txt.

Equiv1, Equiv2 and Equiv3: This works exactly like the equiv (for equivalent) columns in ItemTypes.txt. This works in a quite simple but very powerful way, for example the UndeadFetish MonType is linked to both LowUndead and Demon MonTypes, LowUndead is 
linked to the Undead MonType. So in the eyes of the game, a monster with UndeadFetish assigned to it, is all of these four MonTypes.

StrSing: String key for the string displayed for the singular form (Skeleton), note that this is unused, since the only modifier display code that accesses MonType uses StrPlur.

StrPlur: This is the string key for the plural form of this monsters type (Skeletons), this is used by Damage vs. MonType and Attack Rating vs. MonType modifiers. Beware, the display of these modifiers is bugged because blizzard checks the record count 
for the wrong txt file when it fetches the string, to make them show up you have to add dummy entries to monprop.txt (this file needs to have the same or more entries then montype), it is not in anyway or form related to the last line in the file or to 
the CPU type.

*EOL: End of Line, this is needed to prevent M$-Excel from screwing up the file.


Where are MonTypes used?
Not in many places unfortunately, they are used at present for Modifier Exclusion on bosses (MonUMod.txt), this will let you prevent certain monster types from spawning with specific modifiers (Sand Leapers don't get Lightning Enchanted for example). 
The other place is the dmg-mon and att-mon properties.

*/

typedef struct
{
    unsigned short vtype;
    unsigned short vequiv1;

    unsigned short vequiv2;
    unsigned short vequiv3;

    unsigned short vstrsing;
    unsigned short vstrplur;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vtype[64];
} ST_MONTYPE;

static unsigned int m_iMonTypeCount = 0;
static unsigned int m_iMonTypeHaveEmpty = 0;
static ST_MONTYPE *m_astMonType = NULL;

MODULE_SETLINES_FUNC(m_astMonType, ST_MONTYPE);
MODULE_HAVENAME_FUNC(m_astMonType, vtype, m_iMonTypeCount);

char *MonType_GetType(unsigned int id)
{
    if ( id < m_iMonTypeCount )
    {
        return m_astMonType[id].vtype;
    }

    if ( id == 0xFFFF && m_iMonTypeHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonType_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "type") )
    {
        char *pcName = String_FindString(pstLineInfo->vstrplur, "dummy", NULL);
        if ( !String_BuildName(FORMAT(montype), pstLineInfo->vstrsing, pcTemplate, pcName, pstLineInfo->vtype, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vtype);
        }

        strncpy(m_astMonType[pstLineInfo->vtype].vtype, acOutput, sizeof(m_astMonType[pstLineInfo->vtype].vtype));
        String_Trim(m_astMonType[pstLineInfo->vtype].vtype);
        m_iMonTypeHaveEmpty |= !m_astMonType[pstLineInfo->vtype].vtype[0];

        m_iMonTypeCount++;
        return 1;
    }

    return 0;
}

int process_montype(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, USHORT_MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv1, USHORT_MONTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv2, USHORT_MONTYPE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, equiv3, USHORT_MONTYPE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strsing, USHORT_STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, strplur, USHORT_STRING);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, myasteol, EOL);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iMonTypeCount = 0;

            m_stCallback.pfnConvertValue = MonType_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            File_CopyFile(acTemplatePath, acTxtPath, "monname", ".txt");
            break;

        case EN_MODULE_INIT:
            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


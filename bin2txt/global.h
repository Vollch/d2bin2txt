#ifndef __ANDERS_GLOBAL__
#define __ANDERS_GLOBAL__

#pragma warning( disable: 4996 )

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <io.h>
#include <FCNTL.H>
#include <assert.h>

#define ALL_MODULES(X) \
    X(RoS) \
    X(CharStart) \
    X(D2NewStats) \
    X(D2KillCounter) \
    X(D2Spawn) \
    X(D2RedPortal) \
    X(KillCounter) \
    X(BookOfLore) \
    X(LevelFX) \
    X(ItemDesc) \
    X(Waypoints) \
    X(NoSock) \
    X(QDrop) \
    X(scrollspell) \
    X(bufficons) \
    X(arena) \
    X(armor) \
    X(armtype) \
    X(automagic) \
    X(automap) \
    X(belts) \
    X(bodylocs) \
    X(books) \
    X(charstats) \
    X(chartemplate) \
    X(colors) \
    X(compcode) \
    X(composit) \
    X(cubemain) \
    X(difficultylevels) \
    X(elemtypes) \
    X(events) \
    X(experience) \
    X(gamble) \
    X(gems) \
    X(hiredesc) \
    X(hireling) \
    X(hitclass) \
    X(inventory) \
    X(itemratio) \
    X(itemstatcost) \
    X(itemtypes) \
    X(levels) \
    X(lowqualityitems) \
    X(lvlmaze) \
    X(lvlprest) \
    X(lvlsub) \
    X(lvltypes) \
    X(lvlwarp) \
    X(magicprefix) \
    X(magicsuffix) \
    X(misc) \
    X(misscalc) \
    X(missiles) \
    X(monai) \
    X(monequip) \
    X(monitempercent) \
    X(monlvl) \
    X(monmode) \
    X(monplace) \
    X(monpreset) \
    X(monprop) \
    X(monseq) \
    X(monsounds) \
    X(monstats) \
    X(monstats2) \
    X(montype) \
    X(monumod) \
    X(npc) \
    X(objects) \
    X(objgroup) \
    X(objmode) \
    X(objtype) \
    X(overlay) \
    X(pettype) \
    X(playerclass) \
    X(plrmode) \
    X(plrtype) \
    X(properties) \
    X(qualityitems) \
    X(rareprefix) \
    X(raresuffix) \
    X(runes) \
    X(setitems) \
    X(sets) \
    X(shrines) \
    X(skillcalc) \
    X(skilldesc) \
    X(skills) \
    X(sounds) \
    X(states) \
    X(storepage) \
    X(string) \
    X(superuniques) \
    X(treasureclassex) \
    X(uniqueappellation) \
    X(uniqueitems) \
    X(uniqueprefix) \
    X(uniquesuffix) \
    X(uniquetitle) \
    X(weapons) \

#define FORMAT(module) Get_ModuleNameFormat( EN_MID_##module ), Get_ModuleNameSize( EN_MID_##module ), Get_ModuleNameSeparator( EN_MID_##module )

#define MODULE_ID(key) EN_MID_##key
#define MODULE_ID_DEFINE(key) MODULE_ID(key),

typedef enum
{
    ALL_MODULES(MODULE_ID_DEFINE)

    EN_MID_MAX
} ENUM_MODULE_ID;

typedef struct
{
    unsigned int iLines; //条目数量
} ST_FILE_HEADER;

typedef enum
{
    EN_VALUE_INT, // 0x02
    EN_VALUE_UINT,
    EN_VALUE_SHORT,
    EN_VALUE_USHORT, // 0x03
    EN_VALUE_CHAR, // 0x04
    EN_VALUE_UCHAR, // 0x06
    EN_VALUE_BIT,
    EN_VALUE_STRING, // 0x09, 0x01
    EN_VALUE_UINT_ITEM,
    EN_VALUE_UINT_ITEMCODE, // 0x19
    EN_VALUE_UINT_MISSCODE,
    EN_VALUE_UINT_SKILLCODE,
    EN_VALUE_UINT_DESCCODE,
    EN_VALUE_UINT_PROPERTY,
    EN_VALUE_USHORT_EVENT,
    EN_VALUE_USHORT_ITEMTYPE,
    EN_VALUE_USHORT_ITEMSTAT, // 0x14
    EN_VALUE_USHORT_MISSILE,
    EN_VALUE_USHORT_MONAI,
    EN_VALUE_USHORT_MONPROP,
    EN_VALUE_USHORT_MONSOUND,
    EN_VALUE_USHORT_MONSTAT,
    EN_VALUE_USHORT_MONSTAT2,
    EN_VALUE_USHORT_MONTYPE,
    EN_VALUE_USHORT_OVERLAY,
    EN_VALUE_USHORT_SET,
    EN_VALUE_USHORT_SKILLDESC,
    EN_VALUE_USHORT_SKILL, // 0x14
    EN_VALUE_USHORT_STRING,
    EN_VALUE_USHORT_STRING2,
    EN_VALUE_USHORT_TREASURE,
    EN_VALUE_USHORT_SOUND,
    EN_VALUE_USHORT_STATE,
    EN_VALUE_UCHAR_BODYLOC,
    EN_VALUE_UCHAR_COLOR,
    EN_VALUE_UCHAR_ELEM,
    EN_VALUE_UCHAR_HIREDESC,
    EN_VALUE_UCHAR_HITCLASS,
    EN_VALUE_UCHAR_PLRCLASS, // 0x0D
    EN_VALUE_UCHAR_MONMODE,
    EN_VALUE_UCHAR_PLRMODE,
    EN_VALUE_UCHAR_PET,
    EN_VALUE_UCHAR_STORE,

    EN_VALUE_EOL // 0x00
} ENUM_VALUE_TYPE;

typedef enum
{
    EN_MODULE_PHASE_START,

    EN_MODULE_PREPARE,
    EN_MODULE_SELF_DEPEND,
    EN_MODULE_OTHER_DEPEND,
    EN_MODULE_INIT,

    EN_MODULE_PHASE_MAX,
} ENUM_MODULE_PHASE;

typedef struct
{
    char *acKeyName;
    void *pvValue;
    ENUM_VALUE_TYPE enValueType;
    int iValueLen;
    int iActiveColumn;
} ST_VALUE_MAP;

#define INIT_VALUE_BUFFER \
    do {\
        memset(&m_stCallback, 0, sizeof(m_stCallback));\
        memset(m_acLineInfoBuf, 0, m_iLineBufLength);\
        memset(m_acValueMapBuf, 0, m_iValueBufLength);\
        m_iValueMapIndex = 0;\
    } while (0)

#define MODULE_DEPEND_CALL(module, template, bin ,txt) \
    while (Get_ModulePhase(MODULE_ID(module)) < EN_MODULE_SELF_DEPEND) {\
        int k;\
        ENUM_MODULE_PHASE enCurrentPhase = Get_ModulePhase(MODULE_ID(module));\
        bg_printf(" ", "");\
        bg_printf("#", "depend %s", #module);\
        for ( k = (int)enCurrentPhase + 1; k <= (int)EN_MODULE_SELF_DEPEND; k++ )\
        {\
            bg_printf("#", "phase %d", k);\
            Set_ModulePhase(MODULE_ID(module), k);\
            memset(&m_stCallback, 0, sizeof(m_stCallback));\
            memset(m_acLineInfoBuf, 0, m_iLineBufLength);\
            memset(m_acValueMapBuf, 0, m_iValueBufLength);\
            m_iValueMapIndex = 0;\
            if ( 0 != process_##module(template, bin, txt, k) ) \
            {\
                bg_printf("#", "success");\
            }\
            else\
            {\
                bg_printf("#", "failed");\
                break;\
            }\
        }\
        bg_printf("#", "%s", #module);\
        bg_printf(" ", "");\
    }\

#define VALUE_MAP_DEFINE(map, line, key, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = &line->v##key;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = sizeof(line->v##key);\
        map[m_iValueMapIndex].iActiveColumn = 0;\
        m_iValueMapIndex++;\
    } while (0)

#define VALUE_MAP_DEFINE_2(map, line, key, field, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = &line->v##field;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = sizeof(line->v##field);\
        map[m_iValueMapIndex].iActiveColumn = 0;\
        m_iValueMapIndex++;\
    } while (0)

#define VALUE_MAP_DEFINE_3(map, line, key, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = line;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = sizeof(line);\
        map[m_iValueMapIndex].iActiveColumn = 1;\
        m_iValueMapIndex++;\
    } while (0)

#define SETLINES_FUNC_NAME module_SetLines
#define FINISHED_FUNC_NAME module_Finished
#define MODULE_SETLINES_FUNC(buffer, datastruct) \
    static void module_SetLines(unsigned int uiLines)\
    {\
        if ( NULL != buffer )\
        {\
            return;\
        }\
        buffer = MemMgr_Malloc(sizeof(datastruct) * uiLines);\
        if ( NULL == buffer )\
        {\
            my_error("malloc fail with %u lines\r\n", uiLines);\
        }\
        else\
        {\
            memset(buffer, 0, sizeof(datastruct) * uiLines);\
        }\
    }\
    static void module_Finished()\
    {\
        if ( NULL != buffer )\
        {\
            MemMgr_Free(buffer);\
            buffer = NULL;\
        }\
    }


#define MODULE_HAVENAME module_HaveName
#define MODULE_HAVENAME_FUNC(buffer, key, counter) \
    static int module_HaveName(char* pcTestName)\
    {\
	    unsigned int i;\
	    for ( i = 0; i < counter; i++ )\
	    {\
	    if ( !stricmp(buffer[i].##key, pcTestName) )\
		    {\
			    return 1;\
		    }\
	    }\
	    return 0;\
    }

extern void MemMgr_Init();
extern void *MemMgr_Realloc(void *pvAddr, unsigned int size);
extern void *MemMgr_Malloc(unsigned int size);
extern void MemMgr_Free(void *pvAddr);
extern void MemMgr_FreeAll();

//获取每一行的key，用于在模板文件中找到对应的内容，并和bin文件中的对应行进行合并
//对于没有key的行，则传空指针，只能根据行号对应了
typedef char * (*fnGetKey) (void *pvLineInfo, char *acKey, unsigned int *iKeyLen);
//转换value的内容，比如根据索引值，到另一文件中查找对应的字符串
typedef int (*fnConvertValue) (void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput);
//bit位处理接口
typedef int (*fnBitProc) (void *pvLineInfo, char *acKey, char *acOutput);
//特殊字段处理接口，当bin文件中没有处理某个字段的时候，可以在这里生成值，否则就直接使用模板文件里的内容
typedef int (*fnFieldProc) (void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
//通知该模块，bin文件的行数，便于分配内存
typedef void (*fnSetFileLines)(unsigned int uiLines);
//通知该模块释放内存
typedef void (*fnFinished)();
//Check if name already used in module
typedef int (*fnHaveName) (char *pcTestName);

typedef struct
{
    int iOptional;

    fnGetKey pfnGetKey;
    fnConvertValue pfnConvertValue;
    fnBitProc pfnBitProc;
    fnFieldProc pfnFieldProc;
    fnSetFileLines pfnSetLines;
    fnFinished pfnFinished;

    char **ppcKeyNotUsed;

    char **ppcKeyNotParsed;

    char **ppcKeyInternalProcess;
} ST_CALLBACK;

//公共临时buffer
#define MAX_FILE_SIZE   (10 * 1024 * 1024)
#define m_iGlobaBufLength   MAX_FILE_SIZE
extern char m_acGlobalBuffer[];
#define m_iLineBufLength   (1024 * 1024)
extern char m_acLineInfoBuf[];
#define m_iValueBufLength   (1024 * 1024)
extern char m_acValueMapBuf[];
extern unsigned int m_iValueMapIndex;
extern ST_CALLBACK m_stCallback;
extern unsigned int Global_GetValueMapCount();

extern char *g_pcCustomTable1;
extern char *g_pcCustomTable2;
extern char *g_pcCustomTable3;
extern int g_iTrimSpace;
extern int g_iCompactOutput;

extern int File_GetFileSize(char *pcFileName);
extern int File_CopyFile(char *pcFromPath, char *pcToPath, char *pcFileName, char *pcSuffix);
extern unsigned char *String_Trim(unsigned char *pcValue);
extern void Set_ModulePhase(ENUM_MODULE_ID enMid, ENUM_MODULE_PHASE enPhase);
extern ENUM_MODULE_PHASE Get_ModulePhase(ENUM_MODULE_ID enMid);
extern char* Get_ModuleNameFormat(ENUM_MODULE_ID enMid);
extern int Get_ModuleNameSize(ENUM_MODULE_ID enMid);
extern char Get_ModuleNameSeparator(ENUM_MODULE_ID enMid);

#define MAX_OPERATER_LEVEL  0xFF
#define FUNCTION_OPERATER_LEVEL  1
#define SINGLE_OPERATER_LEVEL  1

typedef enum
{
    EN_OPERATER_START = 0x02,

    EN_OPERATER_BRACKET_1 = 0x02,
    EN_OPERATER_SMALL = 0x0a,
    EN_OPERATER_BIG = 0x0b,
    EN_OPERATER_SMALLEQUAL = 0x0c,
    EN_OPERATER_BIGEQUAL = 0x0d,
    EN_OPERATER_EQUAL = 0x0e,
    EN_OPERATER_NOTEQUAL = 0x0f,
    EN_OPERATER_ADD = 0x10,
    EN_OPERATER_SUB = 0x11,
    EN_OPERATER_MULTI = 0x12,
    EN_OPERATER_DIVIDE = 0x13,
    EN_OPERATER_XOR = 0x14,
    EN_OPERATER_INVERSION = 0x15,
    EN_OPERATER_CONDITION = 0x16,

    EN_OPERATER_MAX,
} ENUM_OPERATER_TYPE;

typedef enum
{
    EN_OPERATER_ARG_1,
    EN_OPERATER_ARG_2,
    EN_OPERATER_ARG_3,
} ENUM_OPERATER_ARGNUM;

typedef enum
{
    EN_OPERATER_LEFT,
    EN_OPERATER_RIGHT,
} ENUM_OPERATER_LEFTRIGHT;

extern void Operater_Init();
extern unsigned char *Operater_GetOpStr(ENUM_OPERATER_TYPE enOpType);
extern unsigned int Operater_GetOpLevel(ENUM_OPERATER_TYPE enOpType);
extern ENUM_OPERATER_LEFTRIGHT Operater_GetLeftRight(ENUM_OPERATER_TYPE enOpType);
extern ENUM_OPERATER_ARGNUM Operater_GetArgNum(ENUM_OPERATER_TYPE enOpType);

//文件处理统一入口，合并模板和bin文件的对应内容
extern int process_file(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback);
extern int process_file_special_bin(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback);
extern int getBinStructSize(char *acBinPath, char *pcFilename);

extern unsigned int my_printf( const char *pcFormat,... );
extern unsigned int bg_printf( const char *pcBG, const char *pcFormat,... );
#define my_error my_printf("[error]: %s-%u\r\n\t", __FILE__, __LINE__);my_printf

extern void * Stack_Create(unsigned int uiElemSize, unsigned int uiElemCount);
extern void Stack_Release(void *pvStack);
extern int Stack_Push(void *pvStack, unsigned char *pcElement, unsigned int uiElemSize);
extern int Stack_Pop(void *pvStack, unsigned char **ppcElement);
extern int Stack_IsEmpty(void *pvStack);
extern int Stack_GetIndex(void *pvStack);

//以下是各个模块提供的外部接口

#define MODULE_DECALRE_FUNC(name) extern int process_##name(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);

ALL_MODULES(MODULE_DECALRE_FUNC)

extern int isRoSActive();

extern int String_StripFileName(char *pcInput, char *pcOutput, unsigned int iSize);
extern int String_BuildName(char *pcNameFormat, int iNameSize, char cNameSeparator, unsigned int iStingId, char *pcTemplate, char *pcName, unsigned int iLine, fnHaveName pfnHaveName, char* acOutput);
extern char *String_FindString(unsigned int id, char* pcFilter);
extern char *String_FindString_2(unsigned int id, char* pcFilter, char* pcFilter2);
extern char *String_GetString(unsigned int id, char* pcFilter, char* pcFilter2);

extern char *Armor_GetArmorCode(unsigned int id);
extern unsigned int Armor_GetArmorString(unsigned int id);
extern unsigned int Armor_GetArmorString2(char *pcVcode);
extern unsigned int Armor_GetArmorCount();

extern char *Weapons_GetWeaponCode(unsigned int id);
extern unsigned int Weapons_GetWeaponString(unsigned int id);
extern unsigned int Weapons_GetWeaponString2(char *pcVcode);
extern unsigned int Weapons_GetWeaponCount();

extern char *Colors_GetColorCode(unsigned int id);

extern char *Compcode_GetCode(unsigned int id);

extern char *PlayerClass_GetClass(unsigned int id);

extern char *StorePage_GetCode(unsigned int id);

extern char *ElemTypes_GetElemStr(unsigned int id);

extern char *BodyLocs_GetLocStr(unsigned int id);

extern char *HitClass_GetClassStr(unsigned int id);

extern char *SkillDesc_GetDesc(unsigned int id);
extern unsigned int SkillDesc_GetString(unsigned int id);

extern char *Overlay_GetOverlay(unsigned int id);

extern char *Missiles_GetMissile(unsigned int id);

extern char *PlrMode_GetCode(unsigned int id);

extern char *MonMode_GetName(unsigned int id);
extern char *MonMode_GetCode(unsigned int id);

extern char *Events_GetEventName(unsigned int id);

extern int SkillsCode_ParseBin(char *acTemplatePath, char *acBinPath, char*acTxtPath);
extern char *SkillsCode_GetExpression(unsigned int id);

extern int SkillDescCode_ParseBin(char *acTemplatePath, char *acBinPath, char*acTxtPath);
extern char *SkillDescCode_GetExpression(unsigned int id);

extern char *Skills_GetSkillName(unsigned int id);

extern char *Sounds_GetSoundName(unsigned int id);
extern char *Sounds_GetSoundName2(unsigned int id);

extern char *ItemTypes_GetItemCode(unsigned int id);

extern char *States_GetStateName(unsigned int id);

extern char *ItemStatCost_GetStateName(unsigned int id);
extern unsigned int ItemStatCost_GetString(unsigned int id);
extern unsigned int ItemStatCost_GetPropertyString(unsigned short asStats[]);

extern char *Properties_GetProperty(unsigned int id);

extern char *Misc_GetItemUniqueCode(unsigned int id);
extern unsigned int Misc_GetItemString2(char *pcVcode);
extern unsigned int Misc_GetItemString(unsigned int id);

extern char *MonStats_GetStatsName(unsigned int id);
extern int MonStats_LinkSkills(void *astSkills, unsigned int iSkillsCount, unsigned int iStructSize, unsigned int iMemberOffset);
extern int MonStats_LinkMonProp(void *astMonProp, unsigned int iMonPropCount, unsigned int iStructSize, unsigned int iMemberOffset);

extern char *Pettype_GetPetType(unsigned int id);

extern char *HireDesc_GetDesc(unsigned int id);

extern char *Levels_GetLevelName(unsigned int id);
extern unsigned char Levels_GetAct(unsigned int id);

extern char *MissCalc_GetCalcCode(unsigned int id);

extern char *MonAi_GetAiName(unsigned int id);

extern char *MonPlace_GetPlaceName(unsigned int id);

extern char *SuperUniques_GetItemUniqueCode(unsigned int id);

extern char *MonSounds_GetItemSoundsCode(unsigned int id);

extern char *TreasureClassEx_GetItemTreasureClass(unsigned int id);
extern void TreasureClassEx_SetOffset(unsigned int uiOffset);

extern char *MonProp_GetPropId(unsigned int id);

extern char *MonSeq_GetSequence(unsigned int id);

extern char *MonStats2_GetStatsName(unsigned int id);

extern char *MonType_GetType(unsigned int id);

extern char *Objects_GetObjectName(unsigned int id);

extern char *SetItems_GetItemUniqueCode(unsigned int id);

extern char *Sets_GetSetName(unsigned int id);

extern char *SkillCalc_GetCalc(unsigned int id);

extern char *UniqueItems_GetItemUniqueCode(unsigned int id);

extern int ItemsCode_ParseBin(char *acTemplatePath, char *acBinPath, char*acTxtPath);
extern char *ItemsCode_GetExpression(unsigned int id);

extern int MissCode_ParseBin(char *acTemplatePath, char *acBinPath, char*acTxtPath);
extern char *MissCode_GetExpression(unsigned int id);

#ifdef __cplusplus
}
#endif

#endif


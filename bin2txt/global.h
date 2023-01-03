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
#include "lookup.h"
#include "D2_109/structs109.h"

#define ALL_MODULES(X) \
    X(BookOfLore) \
    X(bufficons) \
    X(CharStart) \
    X(D2AddSkill) \
    X(D2DC6) \
    X(AddStat) \
    X(Charstats2) \
    X(DreamlandConfig) \
    X(GlobalTCEx2Settings) \
    X(ItemEvent) \
    X(LevelsEx) \
    X(Npc2) \
    X(npctalk) \
    X(objects3) \
    X(pSpawn) \
    X(pSpell) \
    X(RuneDropList) \
    X(ShrineBaseGemTypes) \
    X(Towns) \
    X(TreasureClassEx2) \
    X(TreasureClassEx2NoDrop) \
    X(UIPanel) \
    X(Utility) \
    X(vendor) \
    X(D2KillCounter) \
    X(D2NewStats) \
    X(D2NPCFunc) \
    X(D2StrSound) \
    X(D2Vendors) \
    X(D2RedPortal) \
    X(Achievements) \
    X(CellFiles) \
    X(CharStatsExp) \
    X(CubemainExt) \
    X(experience_sp) \
    X(HireItems) \
    X(itemratio_sp) \
    X(ItemTypesExt) \
    X(LvlTypeNames) \
    X(Missiles2) \
    X(Monstats3) \
    X(MonUModExp) \
    X(MysticOrbs) \
    X(ObjPreset) \
    X(PetTypeExt) \
    X(PropertiesExt) \
    X(Qualities) \
    X(Skills2) \
    X(SkillTabs) \
    X(SkillTree) \
    X(StateIcons) \
    X(StatScreen) \
    X(tables_strings) \
    X(UniqueItems2) \
    X(D2Spawn) \
    X(D2StatsEx2) \
    X(D2LvlTown) \
    X(D2SpawnTown) \
    X(DebauchedCharacter) \
    X(DebauchedItems) \
    X(DebauchedQuests) \
    X(DebauchedSkills) \
    X(DebauchedTemplate) \
    X(DebauchedWaypoints) \
    X(GameDiff) \
    X(HavModEx) \
    X(ItemDesc) \
    X(KillCounter) \
    X(KillExp) \
    X(LevelFX) \
    X(skpoints) \
    X(MagicTwn) \
    X(NoSock) \
    X(QDrop) \
    X(RoS) \
    X(scrollspell) \
    X(SklTree) \
    X(Waypoints) \
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
    X(cubemod) \
    X(cubetype) \
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
    X(skillscode) \
    X(skilldesccode) \
    X(itemscode) \
    X(misscode) \

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
    EN_VALUE_UINT, // 0x02
    EN_VALUE_SHORT, // 0x03
    EN_VALUE_USHORT, // 0x03
    EN_VALUE_CHAR, // 0x04
    EN_VALUE_UCHAR, // 0x06
    EN_VALUE_UINT_BIT,
    EN_VALUE_USHORT_BIT,
    EN_VALUE_UCHAR_BIT,
    EN_VALUE_STRING, // 0x09[4], 0x01[*]
    EN_VALUE_EOL, // 0x00
    EN_VALUE_ITEMCODE, // 0x19
    EN_VALUE_MISSCODE,
    EN_VALUE_SKILLCODE,
    EN_VALUE_DESCCODE,
    EN_VALUE_ITEM,
    EN_VALUE_EVENT,
    EN_VALUE_ITEMSTAT, // 0x14
    EN_VALUE_ITEMTYPE,
    EN_VALUE_MISSILE,
    EN_VALUE_MONAI,
    EN_VALUE_MONPROP,
    EN_VALUE_MONSEQ,
    EN_VALUE_MONSOUND,
    EN_VALUE_MONSTAT,
    EN_VALUE_MONSTAT2,
    EN_VALUE_MONTYPE,
    EN_VALUE_OVERLAY,
    EN_VALUE_PROPERTY,
    EN_VALUE_SET,
    EN_VALUE_SKILLDESC,
    EN_VALUE_SKILL, // 0x11, 0x14
    EN_VALUE_SOUND,
    EN_VALUE_SUPERUNIQUE,
    EN_VALUE_STATE,
    EN_VALUE_TBL_STRING, // 0x16
    EN_VALUE_TBL_STRING2,
    EN_VALUE_TREASURE,
    EN_VALUE_BODYLOC,
    EN_VALUE_COLOR,
    EN_VALUE_ELEMTYPE,
    EN_VALUE_HIREDESC,
    EN_VALUE_HITCLASS,
    EN_VALUE_PET,
    EN_VALUE_CLASS, // 0x0D
    EN_VALUE_PLRMODE,
    EN_VALUE_MONMODE,
    EN_VALUE_STORE,
    EN_VALUE_LEVEL,
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

#define VALUE_MAP_DEFINE_SIZED(map, line, key, field, len, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = &line->v##field;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = len;\
        map[m_iValueMapIndex].iActiveColumn = 0;\
        m_iValueMapIndex++;\
    } while (0)

#define VALUE_MAP_DEFINE_NAMED(map, line, key, field, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = &line->v##field;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = sizeof(line->v##field);\
        map[m_iValueMapIndex].iActiveColumn = 0;\
        m_iValueMapIndex++;\
    } while (0)

#define VALUE_MAP_DEFINE_VIRT(map, line, key, type) \
    do {\
        map[m_iValueMapIndex].acKeyName = #key;\
        map[m_iValueMapIndex].pvValue = line;\
        map[m_iValueMapIndex].enValueType = EN_VALUE_##type;\
        map[m_iValueMapIndex].iValueLen = 0;\
        map[m_iValueMapIndex].iActiveColumn = 0;\
        m_iValueMapIndex++;\
    } while (0)

#define SETLINES_FUNC_NAME SetLines
#define MODULE_SETLINES_FUNC(buffer, datastruct) \
    static void SetLines(unsigned int uiLines)\
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
    }

#define MODULE_HAVENAME HaveName
#define MODULE_HAVENAME_FUNC(buffer, key, counter) \
    static int HaveName(char* pcTestName)\
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
typedef int (*fnConvertValue) (void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
//特殊字段处理接口，当bin文件中没有处理某个字段的时候，可以在这里生成值，否则就直接使用模板文件里的内容
typedef int (*fnFieldProc) (void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
//通知该模块，bin文件的行数，便于分配内存
typedef void (*fnSetFileLines)(unsigned int uiLines);
//通知该模块释放内存
typedef void (*fnFinished)();
//Check if name already used in module
typedef int (*fnHaveName) (char *pcTestName);

typedef enum
{
    EN_MODULE_CORE = 0,
    EN_MODULE_PLUGIN,
    EN_MODULE_EXTENSION,
} ENUM_MODULE_TYPE;

typedef struct
{
    ENUM_MODULE_TYPE eModuleType;

    fnGetKey pfnGetKey;
    fnConvertValue pfnConvertValue;
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
extern char *g_pcFallbackID;
extern char *g_pcFallbackCode;
extern int g_iCompactOutput;
extern int g_iPrintZero;

extern int File_GetFileSize(char *pcFileName);
extern int File_CopyFile(char *pcFromPath, char *pcToPath, char *pcFileName, char *pcSuffix);
extern int File_MergeFiles(char *acBinPath, char *pcFile1, int iSize1, char *pcFile2, int iSize2, char *pcOutFile);
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
extern int process_value(ENUM_VALUE_TYPE enValueType, int iValueLen, void *pvValue, char *acOutput);
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

extern int process_items109(char *pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_magic109(char *pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_rare109(char *pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_unique109(char *pcFilename, char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);

extern int process_books109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_charstats109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_cubemain109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_difficultylevels109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_experience109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_hireling109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_itemstatcost109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_itemtypes109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_lvlmaze109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_levels109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_missiles109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_monstats109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_montype109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_objects109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_overlay109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_npc109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_properties109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_runes109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_setitems109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_skills109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_states109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_superuniques109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_treasureclassex109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);
extern int process_uniqueitems109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase);

extern int isRoSActive();
extern int isD2DreamlandActive();
extern int isD2SigmaActive();
extern int LvlTypeNames_GetLineID(unsigned int line);
extern char *CellFiles_GetName(unsigned int id);
extern int CharStatsExp_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *CharStatsExp_ExternList[];
extern int CubemainExt_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *CubemainExt_ExternList[];
extern int PetTypeExt_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *PetTypeExt_ExternList[];
extern int MonUModExp_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *MonUModExp_ExternList[];
extern int PropertiesExt_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *PropertiesExt_ExternList[];
extern int Missiles2_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *Missiles2_ExternList[];
extern int ItemTypesExt_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *ItemTypesExt_ExternList[];
extern int Skills2_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *Skills2_ExternList[];
extern int UniqueItems2_ExternProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput);
extern char *UniqueItems2_ExternList[];

extern int String_StripFileName(char *pcInput, char *pcOutput, unsigned int iSize);
extern int String_BuildName(char *pcNameFormat, int iNameSize, char cNameSeparator, unsigned int iStingId, char *pcTemplate, char *pcName, unsigned int iLine, fnHaveName pfnHaveName, char* acOutput);
extern char *String_FindString(unsigned int id, char* pcFilter, char* pcFilter2);
extern char *String_GetString(unsigned int id, char* pcFilter, char* pcFilter2);

extern int Cubemain_ProcessInput(void *vInput, char *pcOutput);
extern int Cubemain_ProcessOutput(void *vOutput, char *pcOutput);

extern char *SkillsCode_GetExpression(unsigned int id);
extern char *SkillDescCode_GetExpression(unsigned int id);
extern char *ItemsCode_GetExpression(unsigned int id);
extern char *MissCode_GetExpression(unsigned int id);

extern unsigned int ItemStatCost_GetString(unsigned int id);
extern unsigned int ItemStatCost_GetPropertyString(unsigned short asStats[]);

extern int MonStats_LinkSkills(void *astSkills, unsigned int iSkillsCount, unsigned int iStructSize, unsigned int iMemberOffset);
extern int MonStats_LinkMonProp(void *astMonProp, unsigned int iMonPropCount, unsigned int iStructSize, unsigned int iMemberOffset);

#ifdef __cplusplus
}
#endif

#endif


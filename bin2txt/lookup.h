
struct ST_BT_NODE
{
    char *pcKey;
    unsigned int uiId;
    struct ST_BT_NODE *psLeft;
    struct ST_BT_NODE *psRight;
};
typedef struct ST_BT_NODE ST_BT_NODE;

ST_BT_NODE *Tree_NewNode(char *pcKey, unsigned int uiId);
ST_BT_NODE *Tree_Search(ST_BT_NODE *psTree, char *pcKey);
ST_BT_NODE *Tree_Insert(ST_BT_NODE *psTree, char *pcKey, unsigned int uiId);

typedef char * (*fnGetName) (unsigned int Id);
typedef unsigned int (*fnGetId) (unsigned int Id);

extern fnGetName Lookup_BodyLoc;
extern fnGetName Lookup_Class;
extern fnGetName Lookup_Color;
extern fnGetName Lookup_CompCode;
extern fnGetName Lookup_ElemType;
extern fnGetName Lookup_Event;
extern fnGetName Lookup_HireDesc;
extern fnGetName Lookup_HitClass;
extern fnGetName Lookup_ItemStatCost;
extern fnGetName Lookup_ItemType;
extern fnGetName Lookup_Item;
extern fnGetName Lookup_ItemName;
extern fnGetName Lookup_Level;
extern fnGetName Lookup_LvlType;
extern fnGetName Lookup_MissCalc;
extern fnGetName Lookup_Missile;
extern fnGetName Lookup_MonAI;
extern fnGetName Lookup_MonProp;
extern fnGetName Lookup_MonSeq;
extern fnGetName Lookup_MonSounds;
extern fnGetName Lookup_MonStats;
extern fnGetName Lookup_MonStats2;
extern fnGetName Lookup_MonMode;
extern fnGetName Lookup_MonPlace;
extern fnGetName Lookup_MonType;
extern fnGetName Lookup_Object;
extern fnGetName Lookup_Overlay;
extern fnGetName Lookup_Pet;
extern fnGetName Lookup_PlrMode;
extern fnGetName Lookup_Property;
extern fnGetName Lookup_SetItem;
extern fnGetName Lookup_Set;
extern fnGetName Lookup_SkillCalc;
extern fnGetName Lookup_SkillDesc;
extern fnGetName Lookup_Skill;
extern fnGetName Lookup_Sound;
extern fnGetName Lookup_SuperUnique;
extern fnGetName Lookup_State;
extern fnGetName Lookup_Store;
extern fnGetName Lookup_TreasureClass;
extern fnGetName Lookup_UniqueItem;

extern fnGetId Lookup_SkillDescString;
extern fnGetId Lookup_ItemString;
extern fnGetId Lookup_LevelAct;

extern int g_iTreasureClassOffset;

extern ST_BT_NODE *Map_Items;
extern ST_BT_NODE *Map_RuneLetter;
#include "global.h"

ST_BT_NODE *Tree_NewNode(char *pcKey, unsigned int uiId)
{
    ST_BT_NODE *newTree = malloc(sizeof(ST_BT_NODE));
    if ( newTree != NULL )
    {
        newTree->pcKey = strdup(pcKey);
        newTree->uiId = uiId;
        newTree->psLeft = NULL;
        newTree->psRight = NULL;
        return newTree;
    }
    return NULL;
}

ST_BT_NODE *Tree_Search(ST_BT_NODE *psTree, char *pcKey)
{
    int iCmp;
    if ( !psTree )
    {
        return NULL;
    }
    if ( !(iCmp = strcmp(psTree->pcKey, pcKey)) )
    {
        return psTree;
    }
    return Tree_Search(iCmp > 0 ? psTree->psRight : psTree->psLeft, pcKey);
}

ST_BT_NODE *Tree_Insert(ST_BT_NODE *psTree, char *pcKey, unsigned int uiId)
{
    int iCmp;
    if ( !psTree )
    {
        psTree = Tree_NewNode(pcKey, uiId);
    }
    else if ( iCmp = strcmp(psTree->pcKey, pcKey) )
    {
        ST_BT_NODE **nextNode = iCmp > 0 ? &psTree->psRight : &psTree->psLeft;
        *nextNode = Tree_Insert(*nextNode, pcKey, uiId);
    }
    return psTree;
}

static char *getNameStub(unsigned int Id)
{
    return NULL;
}

static unsigned int getIdStub(unsigned int Id)
{
    return 0xFFFF;
}

fnGetName Lookup_BodyLoc = getNameStub;
fnGetName Lookup_Class = getNameStub;
fnGetName Lookup_Color = getNameStub;
fnGetName Lookup_CompCode = getNameStub;
fnGetName Lookup_ElemType = getNameStub;
fnGetName Lookup_Event = getNameStub;
fnGetName Lookup_HireDesc = getNameStub;
fnGetName Lookup_HitClass = getNameStub;
fnGetName Lookup_ItemStatCost = getNameStub;
fnGetName Lookup_ItemType = getNameStub;
fnGetName Lookup_Item = getNameStub;
fnGetName Lookup_ItemName = getNameStub;
fnGetName Lookup_LvlType = getNameStub;
fnGetName Lookup_MissCalc = getNameStub;
fnGetName Lookup_Missile = getNameStub;
fnGetName Lookup_MonAI = getNameStub;
fnGetName Lookup_MonProp = getNameStub;
fnGetName Lookup_MonSeq = getNameStub;
fnGetName Lookup_MonSounds = getNameStub;
fnGetName Lookup_MonStats = getNameStub;
fnGetName Lookup_MonStats2 = getNameStub;
fnGetName Lookup_MonMode = getNameStub;
fnGetName Lookup_MonPlace = getNameStub;
fnGetName Lookup_MonType = getNameStub;
fnGetName Lookup_Object = getNameStub;
fnGetName Lookup_Overlay = getNameStub;
fnGetName Lookup_Pet = getNameStub;
fnGetName Lookup_PlrMode = getNameStub;
fnGetName Lookup_Property = getNameStub;
fnGetName Lookup_SetItem = getNameStub;
fnGetName Lookup_Set = getNameStub;
fnGetName Lookup_SkillCalc = getNameStub;
fnGetName Lookup_SkillDesc = getNameStub;
fnGetName Lookup_Skill = getNameStub;
fnGetName Lookup_Sound = getNameStub;
fnGetName Lookup_SuperUnique = getNameStub;
fnGetName Lookup_State = getNameStub;
fnGetName Lookup_Store = getNameStub;
fnGetName Lookup_TreasureClass = getNameStub;
fnGetName Lookup_UniqueItem = getNameStub;

fnGetName Lookup_Level = getNameStub;
fnGetName Lookup_ClassName = getNameStub;

fnGetId Lookup_SkillDescString = getIdStub;
fnGetId Lookup_ItemString = getIdStub;
fnGetId Lookup_LevelAct = getIdStub;

int g_iTreasureClassOffset = 0;

ST_BT_NODE *Map_Items = NULL;
ST_BT_NODE *Map_RuneLetter = NULL;
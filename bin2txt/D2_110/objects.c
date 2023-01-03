#include "../global.h"

#define FILE_PREFIX "Objects"


typedef struct
{
    unsigned char vName[64];

    unsigned char pad0x40[128];

    unsigned char vToken[3];
    unsigned char vSpawnMax;

    unsigned char vSelectable0;
    unsigned char vSelectable1;
    unsigned char vSelectable2;
    unsigned char vSelectable3;

    unsigned char vSelectable4;
    unsigned char vSelectable5;
    unsigned char vSelectable6;
    unsigned char vSelectable7;

    unsigned int vTrapProb;

    unsigned int vSizeX;
    unsigned int vSizeY;

    unsigned int vFrameCnt0;
    unsigned int vFrameCnt1;

    unsigned int vFrameCnt2;
    unsigned int vFrameCnt3;

    unsigned int vFrameCnt4;
    unsigned int vFrameCnt5;

    unsigned int vFrameCnt6;
    unsigned int vFrameCnt7;

    unsigned short vFrameDelta0;
    unsigned short vFrameDelta1;

    unsigned short vFrameDelta2;
    unsigned short vFrameDelta3;

    unsigned short vFrameDelta4;
    unsigned short vFrameDelta5;

    unsigned short vFrameDelta6;
    unsigned short vFrameDelta7;

    unsigned char vCycleAnim0;
    unsigned char vCycleAnim1;
    unsigned char vCycleAnim2;
    unsigned char vCycleAnim3;

    unsigned char vCycleAnim4;
    unsigned char vCycleAnim5;
    unsigned char vCycleAnim6;
    unsigned char vCycleAnim7;

    unsigned char vLit0;
    unsigned char vLit1;
    unsigned char vLit2;
    unsigned char vLit3;

    unsigned char vLit4;
    unsigned char vLit5;
    unsigned char vLit6;
    unsigned char vLit7;

    unsigned char vBlocksLight0;
    unsigned char vBlocksLight1;
    unsigned char vBlocksLight2;
    unsigned char vBlocksLight3;

    unsigned char vBlocksLight4;
    unsigned char vBlocksLight5;
    unsigned char vBlocksLight6;
    unsigned char vBlocksLight7;

    unsigned char vHasCollision0;
    unsigned char vHasCollision1;
    unsigned char vHasCollision2;
    unsigned char vHasCollision3;

    unsigned char vHasCollision4;
    unsigned char vHasCollision5;
    unsigned char vHasCollision6;
    unsigned char vHasCollision7;

    unsigned char vIsAttackable0;
    unsigned char vStart0;
    unsigned char vStart1;
    unsigned char vStart2;

    unsigned char vStart3;
    unsigned char vStart4;
    unsigned char vStart5;
    unsigned char vStart6;

    unsigned char vStart7;
    unsigned char vOrderFlag0;
    unsigned char vOrderFlag1;
    unsigned char vOrderFlag2;

    unsigned char vOrderFlag3;
    unsigned char vOrderFlag4;
    unsigned char vOrderFlag5;
    unsigned char vOrderFlag6;

    unsigned char vOrderFlag7;
    unsigned char vEnvEffect;
    unsigned char vIsDoor;
    unsigned char vBlocksVis;

    unsigned char vOrientation;
    unsigned char vPreOperate;
    unsigned char vTrans;
    unsigned char vMode0;

    unsigned char vMode1;
    unsigned char vMode2;
    unsigned char vMode3;
    unsigned char vMode4;

    unsigned char vMode5;
    unsigned char vMode6;
    unsigned char vMode7;
    unsigned char pad0x147;

    int vXoffset;
    int vYoffset;

    unsigned char vDraw;
    unsigned char vHD;
    unsigned char vTR;
    unsigned char vLG;

    unsigned char vRA;
    unsigned char vLA;
    unsigned char vRH;
    unsigned char vLH;

    unsigned char vSH;
    unsigned char vS1;
    unsigned char vS2;
    unsigned char vS3;

    unsigned char vS4;
    unsigned char vS5;
    unsigned char vS6;
    unsigned char vS7;

    unsigned char vS8;
    unsigned char vTotalPieces;
    char vXspace;
    char vYspace;

    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;
    unsigned char vSubClass;

    int vNameOffset;

    unsigned char pad0x16A;
    unsigned char vMonsterOK;
    unsigned char vOperateRange;
    unsigned char vShrineFunction;

    unsigned char vAct;
    unsigned char vLockable;
    unsigned char vGore;
    unsigned char vRestore;

    unsigned char vRestoreVirgins;
    unsigned char vSync;
    unsigned char pad0x176[2];

    int vParm0;
    int vParm1;
    int vParm2;
    int vParm3;

    int vParm4;
    int vParm5;
    int vParm6;
    int vParm7;

    unsigned char vnTgtFX;
    unsigned char vnTgtFY;
    unsigned char vnTgtBX;
    unsigned char vnTgtBY;

    unsigned char vDamage;
    unsigned char vCollisionSubst;
    unsigned char pad0x19E[2];

    int vLeft;
    int vTop;
    int vWidth;
    int vHeight;

    unsigned char vBeta;
    unsigned char vInitFn;
    unsigned char vPopulateFn;
    unsigned char vOperateFn;

    unsigned char vClientFn;
    unsigned char vOverlay;
    unsigned char vBlockMissile;
    unsigned char vDrawUnder;

    unsigned int vOpenWarp;
    unsigned int vAutoMap;
} ST_LINE_INFO;

typedef struct
{
    char vName[64];
} ST_OBJECTS;

static char *m_apcNotUsed[] =
{
    "description - not loaded",
    "Flicker",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Id",
    NULL,
};

static unsigned int m_iBinStructSize = 0;
static unsigned int m_iObjectsCount = 0;
static ST_OBJECTS *m_astObjects = NULL;

MODULE_SETLINES_FUNC(m_astObjects, ST_OBJECTS);

static char *Objects_GetObjectName(unsigned int id)
{
    if ( id >= m_iObjectsCount )
    {
        return NULL;
    }

    return m_astObjects[id].vName;
}

static int Objects_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp("Id", acKey) )
    {
        sprintf(acOutput, "%u", m_iObjectsCount);

        strncpy(m_astObjects[m_iObjectsCount].vName, pstLineInfo->vName, sizeof(m_astObjects[m_iObjectsCount].vName));
        String_Trim(m_astObjects[m_iObjectsCount].vName);

        m_iObjectsCount++;
        return 1;
    }

    return 0;
}

static void Objects_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Token, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpawnMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Selectable7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TrapProb, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt0, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt1, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt3, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameCnt7, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta0, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CycleAnim7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lit7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksLight7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HasCollision7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsAttackable0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Start7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrderFlag7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EnvEffect, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsDoor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlocksVis, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Orientation, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PreOperate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode0, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xoffset, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Yoffset, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Draw, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HD, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TR, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LG, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RA, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LA, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LH, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SH, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S3, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S8, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TotalPieces, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xspace, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Yspace, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubClass, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameOffset, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterOK, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OperateRange, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ShrineFunction, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Lockable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gore, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Restore, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RestoreVirgins, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sync, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm0, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Parm7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nTgtFX, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nTgtFY, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nTgtBX, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nTgtBY, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Damage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollisionSubst, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Left, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Top, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Width, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Height, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beta, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InitFn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PopulateFn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OperateFn, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClientFn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Overlay, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlockMissile, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawUnder, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OpenWarp, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoMap, UINT);
}

int process_objects(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( m_iBinStructSize == sizeof(ST_OBJECTS_109) )
    {
        return process_objects109(acTemplatePath, acBinPath, acTxtPath, enPhase);
    }

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            m_iBinStructSize = getBinStructSize(acBinPath, FILE_PREFIX);
            break;

        case EN_MODULE_SELF_DEPEND:
            Objects_InitValueMap(pstValueMap, pstLineInfo);

            m_iObjectsCount = 0;
            Lookup_Object = Objects_GetObjectName;

            m_stCallback.pfnFieldProc = Objects_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

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

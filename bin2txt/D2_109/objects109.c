#include "../global.h"

#define FILE_PREFIX "Objects"

static char *m_apcNotUsed[] =
{
    "description - not loaded",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "Id",
    NULL,
};

static int Objects_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_OBJECTS_109 *pstLineInfo = pvLineInfo;

    if ( !stricmp("Id", acKey) )
    {
        sprintf(acOutput, "%u", iLineNo);

        return 1;
    }

    return 0;
}

static void Objects_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_OBJECTS_109 *pstLineInfo)
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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TrapProb, UCHAR);

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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta0, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta1, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta3, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta6, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FrameDelta7, UINT);

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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Xoffset, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Yoffset, INT);

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
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flicker, UCHAR);

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

int process_objects109(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_OBJECTS_109 *pstLineInfo = (ST_OBJECTS_109 *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            // Unreachable
            break;

        case EN_MODULE_SELF_DEPEND:
        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_INIT:
            Objects_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Objects_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


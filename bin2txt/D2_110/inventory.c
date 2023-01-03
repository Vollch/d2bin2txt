#include "../global.h"

#define FILE_PREFIX "Inventory"
#define NAME_PREFIX "iv"

typedef struct
{
    int vinvLeft;
    int vinvRight;
    int vinvTop;
    int vinvBottom;

    char vgridX;
    char vgridY;
    unsigned char pad0x12[2];

    int vgridLeft;
    int vgridRight;
    int vgridTop;
    int vgridBottom;

    char vgridBoxWidth;
    char vgridBoxHeight;
    unsigned char pad0x26[2];

    int vrArmLeft;
    int vrArmRight;
    int vrArmTop;
    int vrArmBottom;

    char vrArmWidth;
    char vrArmHeight;
    unsigned char pad0x3A[2];

    int vtorsoLeft;
    int vtorsoRight;
    int vtorsoTop;
    int vtorsoBottom;

    char vtorsoWidth;
    char vtorsoHeight;
    unsigned char pad0x4E[2];

    int vlArmLeft;
    int vlArmRight;
    int vlArmTop;
    int vlArmBottom;

    char vlArmWidth;
    char vlArmHeight;
    unsigned char pad0x62[2];

    int vheadLeft;
    int vheadRight;
    int vheadTop;
    int vheadBottom;

    char vheadWidth;
    char vheadHeight;
    unsigned char pad0x76[2];

    int vneckLeft;
    int vneckRight;
    int vneckTop;
    int vneckBottom;

    char vneckWidth;
    char vneckHeight;
    unsigned char pad0x8A[2];

    int vrHandLeft;
    int vrHandRight;
    int vrHandTop;
    int vrHandBottom;

    char vrHandWidth;
    char vrHandHeight;
    unsigned char pad0x9E[2];

    int vlHandLeft;
    int vlHandRight;
    int vlHandTop;
    int vlHandBottom;

    char vlHandWidth;
    char vlHandHeight;
    unsigned char pad0xB2[2];

    int vbeltLeft;
    int vbeltRight;
    int vbeltTop;
    int vbeltBottom;

    char vbeltWidth;
    char vbeltHeight;
    unsigned char pad0xC6[2];

    int vfeetLeft;
    int vfeetRight;
    int vfeetTop;
    int vfeetBottom;

    char vfeetWidth;
    char vfeetHeight;
    unsigned char pad0xDA[2];

    int vglovesLeft;
    int vglovesRight;
    int vglovesTop;
    int vglovesBottom;

    char vglovesWidth;
    char vglovesHeight;
    unsigned char pad0xEE[2];
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "class",
    NULL,
};

static int Inventory_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "class") )
    {
        char acSize[16] = {0};
        sprintf(acSize, "%dx%d", pstLineInfo->vgridX, pstLineInfo->vgridY);
        if ( !String_BuildName(FORMAT(inventory), 0xFFFF, pcTemplate, acSize, iLineNo, NULL, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

static void Inventory_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invBottom, INT);

    // 1.09 uses gridRows & gridCols, 1.10+ uses gridX & gridY
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridX, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridY, CHAR);
    VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, gridRows, gridX, CHAR);
    VALUE_MAP_DEFINE_NAMED(pstValueMap, pstLineInfo, gridCols, gridY, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBoxWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBoxHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesHeight, CHAR);
}

int process_inventory(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            Inventory_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = Inventory_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

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


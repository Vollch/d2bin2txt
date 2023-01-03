#include "../global.h"

#define FILE_PREFIX "Sounds"
#define NAME_PREFIX "so"


typedef struct
{
    unsigned short vSound;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Index",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "FileName",
    "Volume",
    "Group Size",
    "Loop",
    "Fade In",
    "Fade Out",
    "Defer Inst",
    "Stop Inst",
    "Duration",
    "Compound",
    "Reverb",
    "Falloff",
    "Cache",
    "Async Only",
    "Priority",
    "Stream",
    "Stereo",
    "Tracking",
    "Solo",
    "Music Vol",
    "Block 1",
    "Block 2",
    "Block 3",
    NULL,
};

typedef struct
{
    char vSound[64];
} ST_ITEM_SOUNDS;

static unsigned int m_iItemSoundsCount = 0;
static unsigned int m_iItemSoundsHaveEmpty = 0;
static ST_ITEM_SOUNDS *m_astItemSounds = NULL;

MODULE_SETLINES_FUNC(m_astItemSounds, ST_ITEM_SOUNDS);
MODULE_HAVENAME_FUNC(m_astItemSounds, vSound, m_iItemSoundsCount);

static char *Sounds_GetSoundName(unsigned int id)
{
    if ( id < m_iItemSoundsCount )
    {
        return m_astItemSounds[id].vSound;
    }

    if ( id == -1 && m_iItemSoundsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int Sounds_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Sound") )
    {
        if ( !String_BuildName(FORMAT(sounds), 0xFFFF, pcTemplate, NULL, pstLineInfo->vSound, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vSound);
        }

        strncpy(m_astItemSounds[pstLineInfo->vSound].vSound, acOutput, sizeof(m_astItemSounds[pstLineInfo->vSound].vSound));
        String_Trim(m_astItemSounds[pstLineInfo->vSound].vSound);
        m_iItemSoundsHaveEmpty |= !m_astItemSounds[pstLineInfo->vSound].vSound[0];

        m_iItemSoundsCount++;
        return 1;
    }

    return 0;
}

static int Sounds_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Index") )
    {
        sprintf(acOutput, "%u", pstLineInfo->vSound);

        return 1;
    }

    return 0;
}

static char *Sounds_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    memset(pcKey, 0, sizeof(pcKey));
    sprintf(pcKey, "%u", pstLineInfo->vSound);
    *iKeyLen = (unsigned int)strlen(pcKey);

    return pcKey;
}

int process_sounds(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sound, SOUND);

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            break;

        case EN_MODULE_SELF_DEPEND:
            m_iItemSoundsCount = 0;
            Lookup_Sound = Sounds_GetSoundName;

            //m_stCallback.pfnGetKey = Sounds_GetKey;
            m_stCallback.pfnConvertValue = Sounds_ConvertValue;
            m_stCallback.pfnFieldProc = Sounds_FieldProc;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback) ||
                File_CopyFile(acBinPath, acTxtPath, "Sounds", ".txt") ||
                File_CopyFile(acTemplatePath, acTxtPath, "Sounds", ".txt");
            break;

        case EN_MODULE_OTHER_DEPEND:
            ( File_CopyFile(acBinPath, acTxtPath, "SoundEnviron", ".txt") ||
              File_CopyFile(acTemplatePath, acTxtPath, "SoundEnviron", ".txt") );

        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

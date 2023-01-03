#include "../global.h"

#define FILE_PREFIX "MonSounds"
#define NAME_PREFIX "mo"

typedef struct
{
    unsigned short vId;
    unsigned char pad0x02[2];

    unsigned short vAttack1;    //sounds
    unsigned char pad0x06[2];

    unsigned int vAtt1Del;
    unsigned int vAtt1Prb;
    unsigned short vWeapon1;    //sounds
    unsigned char pad0x12[2];
    unsigned int vWea1Del;
    unsigned int vWea1Vol;

    unsigned short vAttack2;    //sounds
    unsigned char pad0x1E[2];

    unsigned int vAtt2Del;
    unsigned int vAtt2Prb;
    unsigned int vWeapon2;
    unsigned int vWea2Del;
    unsigned int vWea2Vol;

    unsigned short vHitSound; //sounds
    unsigned char pad0x36[2];

    unsigned int vHitDelay;

    unsigned short vDeathSound; //sound
    unsigned char pad0x3E[2];
    unsigned short vDeaDelay;
    unsigned char pad0x42[2];

    unsigned short vSkill1;   //sounds
    unsigned char pad0x46[2];
    unsigned short vSkill2;   //sounds
    unsigned char pad0x4A[2];
    unsigned short vSkill3;   //sounds
    unsigned char pad0x4E[2];
    unsigned short vSkill4;   //sounds
    unsigned char pad0x52[2];

    unsigned short vFootstep; //sounds
    unsigned char pad0x56[2];
    unsigned short vFootstepLayer;    //sounds
    unsigned char pad0x5A[2];

    unsigned int vFsCnt;
    unsigned int vFsOff;
    unsigned int vFsPrb;
    unsigned short vNeutral;  //sounds
    unsigned char pad0x6A[2];
    unsigned int vNeuTime;

    unsigned short vInit; //sounds
    unsigned char pad0x72[2];
    unsigned short vTaunt;    //sounds
    unsigned char pad0x76[2];

    unsigned short vFlee; //sounds
    unsigned char pad0x7A[2];

    unsigned char vCvtMo1;  //monmode
    unsigned char vCvtTgt1;  //monmode
    unsigned char pad0x7E[2];

    unsigned short vCvtSk1;   //skills
    unsigned char pad0x82[2];

    unsigned char vCvtMo2;  //monmode
    unsigned char vCvtTgt2;  //monmode
    unsigned char pad0x86[2];

    unsigned short vCvtSk2;   //skills
    unsigned char pad0x8A[2];

    unsigned char vCvtMo3;  //monmode
    unsigned char vCvtTgt3;  //monmode
    unsigned char pad0x8E[2];

    unsigned short vCvtSk3;   //skills
    unsigned char pad0x92[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vId[64];
} ST_MONSOUND;

static unsigned int m_iMonSoundsCount = 0;
static unsigned int m_iMonSoundsHaveEmpty = 0;
static ST_MONSOUND *m_astMonSounds = NULL;

MODULE_SETLINES_FUNC(m_astMonSounds, ST_MONSOUND);
MODULE_HAVENAME_FUNC(m_astMonSounds, vId, m_iMonSoundsCount);

static char *MonSounds_GetItemSoundsCode(unsigned int id)
{
    if ( id < m_iMonSoundsCount )
    {
        return m_astMonSounds[id].vId;
    }

    if ( id == -1 && m_iMonSoundsHaveEmpty )
    {
        return g_pcFallbackID;
    }

    return NULL;
}

static int MonSounds_ConvertValue(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        char *pcName = NULL;
        ( (pstLineInfo->vAttack1 && (pcName = Lookup_Sound(pstLineInfo->vAttack1))) ||
          (pstLineInfo->vAttack2 && (pcName = Lookup_Sound(pstLineInfo->vAttack2))) ||
          (pstLineInfo->vHitSound && (pcName = Lookup_Sound(pstLineInfo->vHitSound))) ||
          (pstLineInfo->vDeathSound && (pcName = Lookup_Sound(pstLineInfo->vDeathSound))) ||
          (pstLineInfo->vNeutral && (pcName = Lookup_Sound(pstLineInfo->vNeutral))) ||
          (pstLineInfo->vTaunt && (pcName = Lookup_Sound(pstLineInfo->vTaunt))) ||
          (pstLineInfo->vFlee && (pcName = Lookup_Sound(pstLineInfo->vFlee))) ||
          (pstLineInfo->vInit && (pcName = Lookup_Sound(pstLineInfo->vInit))) ||
          (pstLineInfo->vWeapon1 && (pcName = Lookup_Sound(pstLineInfo->vWeapon1))) ||
          (pstLineInfo->vWeapon2 && (pcName = Lookup_Sound(pstLineInfo->vWeapon2))) ||
          (pstLineInfo->vSkill1 && (pcName = Lookup_Sound(pstLineInfo->vSkill1))) ||
          (pstLineInfo->vSkill2 && (pcName = Lookup_Sound(pstLineInfo->vSkill2))) ||
          (pstLineInfo->vSkill3 && (pcName = Lookup_Sound(pstLineInfo->vSkill3))) ||
          (pstLineInfo->vSkill4 && (pcName = Lookup_Sound(pstLineInfo->vSkill4))) ||
          (pstLineInfo->vFootstep && (pcName = Lookup_Sound(pstLineInfo->vFootstep))) ||
          (pstLineInfo->vFootstepLayer && (pcName = Lookup_Sound(pstLineInfo->vFootstepLayer))) );

        if ( !String_BuildName(FORMAT(monsounds), 0xFFFF, pcTemplate, pcName, pstLineInfo->vId, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vId);
        }

        strncpy(m_astMonSounds[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonSounds[pstLineInfo->vId].vId));
        String_Trim(m_astMonSounds[pstLineInfo->vId].vId);
        m_iMonSoundsHaveEmpty |= !m_astMonSounds[pstLineInfo->vId].vId[0];

        m_iMonSoundsCount++;
        return 1;
    }

    return 0;
}

static void MonSounds_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, MONSOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Attack1, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon1, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att1Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att1Prb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea1Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea1Vol, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Attack2, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon2, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att2Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att2Prb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea2Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea2Vol, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSound, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitDelay, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeathSound, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeaDelay, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Footstep, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FootstepLayer, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsCnt, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsOff, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsPrb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Neutral, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NeuTime, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Init, SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Taunt, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flee, SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo1, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt1, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk1, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo2, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt2, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk2, SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo3, MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt3, MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk3, SKILL);

    VALUE_MAP_DEFINE_VIRT(pstValueMap, pstLineInfo, EOL, EOL);
}

int process_monsounds(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;
    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_PREPARE:
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_SELF_DEPEND:
            MonSounds_InitValueMap(pstValueMap, pstLineInfo);

            m_iMonSoundsCount = 0;
            Lookup_MonSounds = MonSounds_GetItemSoundsCode;

            m_stCallback.pfnConvertValue = MonSounds_ConvertValue;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonSounds_InitValueMap(pstValueMap, pstLineInfo);

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


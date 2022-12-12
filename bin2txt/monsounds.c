#include "global.h"

#define FILE_PREFIX "monsounds"
#define NAME_PREFIX "mo"

/*
Title 	MonSounds.txt
Description 	by Nefarius
Sent by 	
This used to reside in a table that was located in the data section of D2Client.dll before 1.10.

Id: this column represents the ID pointer you'd use in MonStats.txt to link this sound-index to a monster, read the file guide for that file for more information.

Attack1 and Attack2: the ID pointer of the sound to play for melee attack1 and melee attack2 (respectively), this is an ID pointer from Sounds.txt. This is played when the monster starts attacking.

Weapon1 and Weapon2: this is the ID pointer to another sound, this sound is used by Blizzard for monsters that wield a weapon, it can be used for any monster though.

Att1Del and Att2Del: number of frames to wait (after starting the attack) before playing the sound.

Wea1Del and Wea2Del: number of frames to wait before playing the weapon sound.

Att1Prb and Att2Prb: chance to play the attack sound (not the weapon sound), this is quite obviously x out of 100 icon_wink.gif.

Wea1Vol and Wea2Vol: sets the volume for the weapon sound to something other then what the sound has defined in Sounds.txt, 255 is full volume, 0 would mute the sound.

HitSound: The ID pointer of the sound to play when the monster takes a hit (it doesn't have to get into GH mode for this to play).

DeathSound: The ID pointer of the sound to play when the monster dies.

HitDelay: Time to wait (in frames) before playing the hit-sound, after the monster gets hit.

DeathDelay: Time to wait (in frames) before playing the death sound.

Skill1 to Skill4: Sound to play when the monster enters S1, S2, S3 or S4 modes. This does _not_ refer to the skill columns in monstats.

Footstep: An ID pointer to a sound that is played each loop of the WL animation.

FootstepLayer: This is an additional sound to play when the monster is in the WL animation mode, like the above.

FsCnt: Number of times to play the footstep sound, for a monster with two legs you'd set this to 2 quite obviously.

FsOff: Could be related to the delay in frames between playing the individual footsteps.

FsPrb: Chance to play the footstep sound. Again, x out of 100.

Neutral: An ID pointer to a sound that is played when the monster is neutral (actually, it's played even if the monster isn't in NU mode, see next column for details).

NeuTime: Delay in frames between playing the Neutral sound.

Init: An ID pointer to sounds that should start playing the moment the monster is initialized (AI related I guess), this is mainly used for looping sounds.

Taunt: An ID pointer to the sound that is played when you encounter the monster, which naturally means, the speech of bosses and the like.

Flee: An ID pointer to a sound that is played when the monster retreats, originally, all monsters were meant to escape when they were low on HP, but Blizzard changed this during the alpha of the game, back then this was probably a lot more significant, 
right now it's only used by fallen.

CvtMo1 to CvtMo3: This is related to sounds that are played when certain skills or sequences are used, this contains the initial animation, like WL for the charge skill.

CvtSk1 to CSkMo3: This is like the above, it contains the ID pointer to the skill in question.

CvtTgt1 to CvtTgt3: This is related to sounds that are played when certain skills or sequences are used, this contains the end-animation of the sequence, like A2 for the charge skill.

*/

typedef struct
{
    unsigned int vId;

    unsigned short vAttack1;    //sounds
    unsigned short sPad1;

    unsigned int vAtt1Del;
    unsigned int vAtt1Prb;
    unsigned short vWeapon1;    //sounds
    unsigned short sPad2;
    unsigned int vWea1Del;
    unsigned int vWea1Vol;

    unsigned short vAttack2;    //sounds
    unsigned short sPad3;

    unsigned int vAtt2Del;
    unsigned int vAtt2Prb;
    unsigned int vWeapon2;
    unsigned int vWea2Del;
    unsigned int vWea2Vol;

    unsigned short vHitSound; //sounds
    unsigned short sPad4;

    unsigned int vHitDelay;

    unsigned short vDeathSound;
    unsigned short sPad5;
    unsigned short vDeaDelay;
    unsigned short sPad6;

    unsigned short vSkill1;   //sounds
    unsigned short sPad7;
    unsigned short vSkill2;   //sounds
    unsigned short sPad8;
    unsigned short vSkill3;   //sounds
    unsigned short sPad9;
    unsigned short vSkill4;   //sounds
    unsigned short sPad10;

    unsigned short vFootstep; //sounds
    unsigned short sPad11;
    unsigned short vFootstepLayer;    //sounds
    unsigned short sPad12;

    unsigned int vFsCnt;
    unsigned int vFsOff;
    unsigned int vFsPrb;
    unsigned short vNeutral;  //sounds
    unsigned short sPad13;
    unsigned int vNeuTime;

    unsigned short vInit; //sounds
    unsigned short sPad14;
    unsigned short vTaunt;    //sounds
    unsigned short sPad15;

    unsigned short vFlee; //sounds
    unsigned short sPad16;

    unsigned char vCvtMo1;  //monmode
    unsigned char vCvtTgt1;  //monmode
    unsigned char iPadding31[2];

    unsigned short vCvtSk1;   //skills
    unsigned short sPad17;

    unsigned char vCvtMo2;  //monmode
    unsigned char vCvtTgt2;  //monmode
    unsigned char iPadding33[2];

    unsigned short vCvtSk2;   //skills
    unsigned short sPad18;

    unsigned char vCvtMo3;  //monmode
    unsigned char vCvtTgt3;  //monmode
    unsigned char iPadding35[2];

    unsigned short vCvtSk3;   //skills
    unsigned short sPad19;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vId[64];
} ST_MONSOUND;

static char *m_apcInternalProcess[] = 
{
    "Id",
    NULL,
};

static unsigned int m_iMonSoundsCount = 0;
static ST_MONSOUND *m_astMonSounds = NULL;

MODULE_SETLINES_FUNC(m_astMonSounds, ST_MONSOUND);
MODULE_HAVENAME_FUNC(m_astMonSounds, vId, m_iMonSoundsCount);

char *MonSounds_GetItemSoundsCode(unsigned int id)
{
    if ( id < m_iMonSoundsCount )
    {
        return m_astMonSounds[id].vId;
    }

    return NULL;
}

static int MonSounds_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !stricmp(acKey, "Id") )
    {
        char *pcName;
        ( (pcName = Sounds_GetSoundName2(pstLineInfo->vAttack1)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vAttack2)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vHitSound)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vDeathSound)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vNeutral)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vTaunt)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vFlee)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vInit)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vWeapon1)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vWeapon2)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vSkill1)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vSkill2)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vSkill3)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vSkill4)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vFootstep)) ||
          (pcName = Sounds_GetSoundName2(pstLineInfo->vFootstepLayer)) );

        if ( !String_BuildName(FORMAT(monsounds), 0xFFFF, pcTemplate, pcName, pstLineInfo->vId, MODULE_HAVENAME, acOutput) )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vId);
        }

        strncpy(m_astMonSounds[pstLineInfo->vId].vId, acOutput, sizeof(m_astMonSounds[pstLineInfo->vId].vId));
        String_Trim(m_astMonSounds[pstLineInfo->vId].vId);
        m_iMonSoundsCount++;
        return 1;
    }

    return 0;
}

static int MonSounds_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !stricmp(acKey, "Id") )
    {
        strncpy(acOutput, m_astMonSounds[iLineNo].vId, sizeof(m_astMonSounds[iLineNo].vId));

        return 1;
    }

    return 0;
}


static void MonSounds_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Attack1, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon1, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att1Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att1Prb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea1Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea1Vol, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Attack2, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon2, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att2Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Att2Prb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea2Del, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Wea2Vol, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSound, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitDelay, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeathSound, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeaDelay, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Footstep, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FootstepLayer, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsCnt, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsOff, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FsPrb, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Neutral, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NeuTime, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Init, USHORT_SOUND);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Taunt, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flee, USHORT_SOUND);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo1, UCHAR_MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt1, UCHAR_MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk1, USHORT_SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo2, UCHAR_MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt2, UCHAR_MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk2, USHORT_SKILL);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtMo3, UCHAR_MONMODE);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtTgt3, UCHAR_MONMODE);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CvtSk3, USHORT_SKILL);

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

            m_stCallback.pfnFieldProc = MonSounds_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME;
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, NULL, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_INIT:
            MonSounds_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnFieldProc = MonSounds_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}


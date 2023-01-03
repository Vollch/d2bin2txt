typedef struct
{
    unsigned char acHead[32];
    unsigned char vclass[16];

    unsigned char vstr;
    unsigned char vdex;
    unsigned char vint;
    unsigned char vvit;

    unsigned char vstamina;
    unsigned char vhpadd;
    unsigned char vPercentStr;
    unsigned char vPercentInt;

    unsigned char vPercentDex;
    unsigned char vPercentVit;
    unsigned char vManaRegen;
    unsigned char pad0x3B;

    int vToHitFactor;

    unsigned char vWalkVelocity;
    unsigned char vRunVelocity;
    unsigned char vRunDrain;
    unsigned char vLifePerLevel;

    unsigned char vStaminaPerLevel;
    unsigned char vManaPerLevel;
    unsigned char vLifePerVitality;
    unsigned char vStaminaPerVitality;

    unsigned char vManaPerMagic;
    unsigned char vBlockFactor;
    unsigned char pad0x4A[2];

    unsigned char vbaseWClass[4];
    unsigned int vStartSkill;

    unsigned char vitem1[4];
    unsigned char vitem1loc;
    unsigned char vitem1count;
    unsigned char pad0x5A[2];

    unsigned char vitem2[4];
    unsigned char vitem2loc;
    unsigned char vitem2count;
    unsigned char pad0x62[2];

    unsigned char vitem3[4];
    unsigned char vitem3loc;
    unsigned char vitem3count;
    unsigned char pad0x6A[2];

    unsigned char vitem4[4];
    unsigned char vitem4loc;
    unsigned char vitem4count;
    unsigned char pad0x72[2];

    unsigned char vitem5[4];
    unsigned char vitem5loc;
    unsigned char vitem5count;
    unsigned char pad0x7A[2];

    unsigned char vitem6[4];
    unsigned char vitem6loc;
    unsigned char vitem6count;
    unsigned char pad0x82[2];

    unsigned char vitem7[4];
    unsigned char vitem7loc;
    unsigned char vitem7count;
    unsigned char pad0x8A[2];

    unsigned char vitem8[4];
    unsigned char vitem8loc;
    unsigned char vitem8count;
    unsigned char pad0x92[2];

    unsigned char vitem9[4];
    unsigned char vitem9loc;
    unsigned char vitem9count;
    unsigned char pad0x9A[2];

    unsigned char vitem10[4];
    unsigned char vitem10loc;
    unsigned char vitem10count;
    unsigned char pad0xA2[2];
} ST_CHARSTATS_109;

typedef struct
{
    unsigned char venabled;
    unsigned char vminmyspdiff;
    unsigned char vstartmyspday;
    unsigned char vstopmyspday;
    unsigned char vweekday;
    unsigned char vclass; // class
    unsigned char vnuminputs;
    unsigned char pad0x07;
    unsigned short vversion;

    unsigned char vinputmysp1[24];
    unsigned char pad0x22[8];
    unsigned char vinputmysp2[24];
    unsigned char pad0x42[8];
    unsigned char vinputmysp3[24];
    unsigned char pad0x62[8];
    unsigned char vinputmysp4[24];
    unsigned char pad0x82[8];
    unsigned char vinputmysp5[24];
    unsigned char pad0xA2[8];
    unsigned char vinputmysp6[24];
    unsigned char pad0xC2[8];
    unsigned char vinputmysp7[24];
    unsigned char pad0xE2[10];
    unsigned char voutput[24];
    unsigned char pad0x104[9];

    unsigned char vlvl;
    unsigned char vplvl;
    unsigned char vilvl;

    unsigned char pad0x110[12];

    unsigned int vmodmysp1; // property
    unsigned short vmodmysp1myspparam;
    unsigned short vmodmysp1myspmin;
    unsigned short vmodmysp1myspmax;
    unsigned char vmodmysp1myspchance;
    unsigned char pad0x127;

    unsigned int vmodmysp2; // property
    unsigned short vmodmysp2myspparam;
    unsigned short vmodmysp2myspmin;
    unsigned short vmodmysp2myspmax;
    unsigned char vmodmysp2myspchance;
    unsigned char pad0x133;

    unsigned int vmodmysp3; // property
    unsigned short vmodmysp3myspparam;
    unsigned short vmodmysp3myspmin;
    unsigned short vmodmysp3myspmax;
    unsigned char vmodmysp3myspchance;
    unsigned char pad0x13F;

    unsigned int vmodmysp4; // property
    unsigned short vmodmysp4myspparam;
    unsigned short vmodmysp4myspmin;
    unsigned short vmodmysp4myspmax;
    unsigned char vmodmysp4myspchance;
    unsigned char pad0x14B;

    unsigned int vmodmysp5; // property
    unsigned short vmodmysp5myspparam;
    unsigned short vmodmysp5myspmin;
    unsigned short vmodmysp5myspmax;
    unsigned char vmodmysp5myspchance;
    unsigned char pad0x157;
} ST_CUBEMAIN_109;

typedef struct
{
    int vResistPenalty;
    unsigned int vDeathExpPenalty;
    unsigned int vUberCodeOddsNormal;
    unsigned int vUberCodeOddsGood;

    unsigned int vMonsterSkillBonus;
    unsigned int vMonsterFreezeDivisor;
    unsigned int vMonsterColdDivisor;
    unsigned int vAiCurseDivisor;
    unsigned int vUltraCodeOddsNormal;
    unsigned int vUltraCodeOddsGood;

    unsigned int vLifeStealDivisor;
    unsigned int vManaStealDivisor;
    unsigned int vExtraUniqueMonsters;
    unsigned int vUniqueDamageBonus;
    unsigned int vChampionDamageBonus;
    unsigned int vHireableBossDamagePercent;

    unsigned int vStaticFieldMin;
} ST_DIFFICULTYLEVELS_109;

typedef struct
{
    unsigned int vId;
    unsigned int vClass;
    unsigned int vAct;
    unsigned int vDifficulty;
    unsigned int vSeller;
    unsigned int vGold;
    unsigned int vLevel;
    unsigned int vExpmyslashLvl;
    unsigned int vHP;
    unsigned int vHPmyslashLvl;
    unsigned int vDefense;
    unsigned int vDefmyslashLvl;
    unsigned int vStr;
    unsigned int vStrmyslashLvl;
    unsigned int vDex;
    unsigned int vDexmyslashLvl;
    unsigned int vAR;
    unsigned int vARmyslashLvl;
    unsigned int vShare;
    unsigned int vDmgmysubMin;
    unsigned int vDmgmysubMax;
    unsigned int vDmgmyslashLvl;
    unsigned int vResist;
    unsigned int vResistmyslashLvl;
    unsigned int vDefaultChance;

    unsigned int vHead;
    unsigned int vTorso;
    unsigned int vWeapon;
    unsigned int vShield;

    unsigned int vSkill1; //skills
    unsigned int vSkill2;
    unsigned int vSkill3;
    unsigned int vSkill4;
    unsigned int vSkill5;
    unsigned int vSkill6;

    unsigned int vChance1;
    unsigned int vChance2;
    unsigned int vChance3;
    unsigned int vChance4;
    unsigned int vChance5;
    unsigned int vChance6;

    unsigned int vChancePerLevel1;
    unsigned int vChancePerLevel2;
    unsigned int vChancePerLevel3;
    unsigned int vChancePerLevel4;
    unsigned int vChancePerLevel5;
    unsigned int vChancePerLevel6;

    unsigned char vMode1;
    unsigned char vMode2;
    unsigned char vMode3;
    unsigned char vMode4;

    unsigned char vMode5;
    unsigned char vMode6;
    unsigned char vLevel1;
    unsigned char vLevel2;

    unsigned char vLevel3;
    unsigned char vLevel4;
    unsigned char vLevel5;
    unsigned char vLevel6;

    unsigned char vLvlPerLvl1;
    unsigned char vLvlPerLvl2;
    unsigned char vLvlPerLvl3;
    unsigned char vLvlPerLvl4;

    unsigned char vLvlPerLvl5;
    unsigned char vLvlPerLvl6;

    unsigned char vHireDesc; //hiredesc

    unsigned char vNameFirst[60];
    unsigned char vNameLast[60];
    unsigned char pad0x147[5];
} ST_HIRELING_109;

typedef struct
{
    char vdamagerelated;
    char vitemspecific;
    unsigned char pad0x02[2];
    int vDivide;
    int vMultiply;
    int vAdd;
    char vValShift;
    char vSavemyspBits;
    unsigned char pad0x12[2];
    int vSavemyspAdd;
    int vTargetmyspStat;
    char vPercent;
    char vPerLevel;
    char vPerLevelShift;
    char vByTime;
    char vEncode;
    unsigned char pad0x21[3];
} ST_ITEMSTATCOST_109;

typedef struct
{
    unsigned char vCode[4];

    unsigned char vEquiv1; // itemtypes
    unsigned char vEquiv2; // itemtypes
    unsigned char vRepair;
    unsigned char vBody;

    unsigned char vBodyLoc1; // bodyloc
    unsigned char vBodyLoc2; // bodyloc
    unsigned short pad0x0A;

    unsigned int vShoots; // item
    unsigned int vQuiver; // item
    unsigned char vThrowable;
    unsigned char vReload;
    unsigned char vReEquip;
    unsigned char vAutoStack;

    unsigned char vMagic;
    unsigned char vRare;
    unsigned char vNormal;
    unsigned char vCharm;

    unsigned char vGem;
    unsigned char vBeltable;
    unsigned char vMaxSock1;
    unsigned char vMaxSock25;

    unsigned char vMaxSock40;
    unsigned char vTreasureClass;
    unsigned char vRarity;
    unsigned char vStaffMods;

    unsigned char vCostFormula;
    unsigned char vClass;
    unsigned char vStorePage; // storepage
    unsigned char vVarInvGfx;

    unsigned char vInvGfx1[32];
    unsigned char vInvGfx2[32];
    unsigned char vInvGfx3[32];
    unsigned char vInvGfx4[32];
    unsigned char vInvGfx5[32];
    unsigned char vInvGfx6[32];
} ST_ITEMTYPES_109;

typedef struct
{
    unsigned char vVel;
    unsigned char vMaxVel;
    unsigned char pad0x02[2];
    unsigned int vAccel;
    unsigned int vRange;
    unsigned int vLevRange;
    unsigned char vLight;
    unsigned char vFlicker;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;
    unsigned char vInitSteps;
    unsigned char vActivate;
    unsigned char vLoopAnim;
    unsigned char vCelFile[64];
    unsigned char vAnimLen;
    unsigned char pad0x59[3];
    unsigned int vRandStart;
    unsigned char vSubLoop;
    unsigned char vSubStart;
    unsigned char vSubStop;
    unsigned char vCollideType;
    unsigned char vCollision;
    unsigned char vClientCol;
    unsigned char vCollideKill;
    unsigned char vCollideFriend;
    unsigned char vLastCollide;
    unsigned char vCanDestroy;
    unsigned char vClientSend;
    unsigned char vNextHit;
    unsigned char vNextDelay;
    unsigned char vSize;
    unsigned char vToHit;
    unsigned char vAlwaysExplode;
    unsigned char vExplosion;
    unsigned char vCanSlow;
    unsigned char vReturnFire;
    unsigned char vGetHit;
    unsigned char vKnockBack;
    unsigned char vTrans;
    unsigned char vQty;
    unsigned char vPierce;
    unsigned int vParam1;
    unsigned int vParam2;
    unsigned char vOpen;
    unsigned char vBeta;
    unsigned char pad0x82[2];
    unsigned int vSpecialSetup;
    unsigned int vSkill;
    unsigned char vHitShift;
    unsigned char pad0x8D[3];
    unsigned int vSrcDamage;
    unsigned int vMinDamage;
    unsigned int vMaxDamage;
    unsigned int vLevDam1;
    unsigned int vLevDam2;
    unsigned int vLevDam3;
    unsigned char vEType; //elem
    unsigned char pad0xA9[3];
    unsigned int vEMin;
    unsigned int vEMax;
    unsigned int vELev1;
    unsigned int vELev2;
    unsigned int vELev3;
    unsigned int vELen;
    unsigned int vELevLen1;
    unsigned int vELevLen2;
    unsigned int vELevLen3;
    unsigned char pad0xD0[4];
    unsigned int vHitClass;
    unsigned int vDamageRate;
    unsigned char vNumDirections;
    unsigned char vAnimSpeed;
    unsigned char vLocalBlood;
} ST_MISSILES_109;

typedef struct
{
    unsigned char vnpc[60];
    unsigned char pad0x3C[4];

    unsigned int vsellmyspmult;
    unsigned int vbuymyspmult;
    unsigned int vrepmyspmult;

    unsigned int vquestflagmyspA;
    unsigned int vquestflagmyspB;
    unsigned int vquestflagmyspC;

    unsigned int vquestsellmultmyspA;
    unsigned int vquestsellmultmyspB;
    unsigned int vquestsellmultmyspC;

    unsigned int vquestbuymultmyspA;
    unsigned int vquestbuymultmyspB;
    unsigned int vquestbuymultmyspC;

    unsigned int vquestrepmultmyspA;
    unsigned int vquestrepmultmyspB;
    unsigned int vquestrepmultmyspC;

    unsigned int vmaxmyspbuy;
    unsigned int vmaxmyspbuymyspmybr1Nmybr2;
    unsigned int vmaxmyspbuymyspmybr1Hmybr2;
} ST_NPC_109;

typedef struct
{
    unsigned char vFilename[64];
    unsigned int vFrames;

    unsigned char vPreDraw;
    unsigned char pad0x45[3];

    unsigned int v1ofN;

    unsigned char vDir;
    unsigned char vOpen;
    unsigned char vBeta;
    unsigned char pad0x4F;

    int vXoffset;
    int vYoffset;
    int vHeight1;
    int vHeight2;
    int vHeight3;
    int vHeight4;
    unsigned int vAnimRate;

    unsigned int vInitRadius;
    unsigned int vRadius;
    unsigned int vLoopWaitTime;

    unsigned char vTrans;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;

    unsigned char vNumDirections;
    unsigned char vLocalBlood;
    unsigned char pad0x7E[2];
} ST_OVERLAY_109;

typedef struct
{
    unsigned char vCode[16];
} ST_PROPERTIES_109;

typedef struct
{
    unsigned char pad0x00[4];
    unsigned char vskill[16]; // skill
    unsigned char vcharclass; // playerclass
    unsigned char pad0x15[3]; // Do not remove; playerclass is loaded as full INT, but this bytes are corrupted by overflown skillname, and should be ignored
    unsigned int vmonster;
    unsigned int venhanceable;
    unsigned int vcostmyspmult;
    unsigned int vcostmyspadd;
    unsigned int vClassReq;
    unsigned int vAttackRank;
    unsigned char vitemclass1[4];
    unsigned char vitemclass2[4];
    unsigned char vitemclass3[4];
    unsigned char vitemclass4[4];
    unsigned char vitemclass5[4];
    unsigned char vitemclass6[4];
    unsigned char vanim[8];
    unsigned char vmonanim[8];
    unsigned char pad0x58[8];
    unsigned char vseqnum;
    unsigned char vDurability;
    unsigned char vShiver;
    unsigned char pad0x63;
    unsigned int vUseAttackRate;
    unsigned int vLineOfSight;
    unsigned int vitemeffect;
    unsigned int vTargetableOnly;
    unsigned int vSearchEnemyXY;
    unsigned int vSearchMonsterNear;
    unsigned int vSelectDead;
    unsigned int vSearchOpenXY;
    unsigned char vTargetPet;
    unsigned char vTargetAlly;
    unsigned char vrange[8];
    unsigned char pad0x8E[6];
    unsigned int vAttackNoMana;
    unsigned char vreqlevel;
    unsigned char vreqstr;
    unsigned char vreqdex;
    unsigned char vreqint;
    unsigned char vreqvit;
    unsigned char pad0x9D[3];
    unsigned int vreqskill1; //skill
    unsigned int vreqskill2; //skill
    unsigned int vreqskill3; //skill
    unsigned int vcastermyspstate; //state
    unsigned int vvictimmyspstate; //state
    unsigned char visaura;
    unsigned char pad0xB5[15];
    unsigned int vstate1;
    unsigned int vstate2;
    unsigned int vstate3;
    unsigned int vDelay;
    unsigned char vskillpage;
    unsigned char vskillrow;
    unsigned char vskillcolumn;
    unsigned char viconcel;
    unsigned char vleftskl;
    unsigned char pad0xD9[3];
    unsigned int vmanashift;
    unsigned int vmana;
    int vlvlmana;
    unsigned char vInterrupt;
    unsigned char vInTown;
    unsigned char vPeriodic;
    unsigned char vFinishing;
    unsigned char vPassive;
    unsigned char pad0xED[3];
    unsigned int vParam1;
    unsigned int vParam2;
    unsigned int vParam3;
    unsigned int vParam4;
    unsigned int vParam5;
    unsigned int vParam6;
    unsigned int vInGame;
    unsigned int vOpen;
    unsigned int vBeta;
    unsigned char pad0x114[12];
    unsigned int vToHit;
    unsigned int vLevToHit;
    unsigned char vHitShift;
    unsigned char vSrcDam;
    unsigned char pad0x12A[2];
    unsigned int vMinDam;
    unsigned int vMaxDam;
    unsigned int vLevDam1;
    unsigned int vLevDam2;
    unsigned int vLevDam3;
    unsigned char vEType; //elem
    unsigned char pad0x141[3];
    unsigned int vEMin;
    unsigned int vEMax;
    unsigned int vELev1;
    unsigned int vELev2;
    unsigned int vELev3;
    unsigned int vELen;
    unsigned int vELevLen1;
    unsigned int vELevLen2;
    unsigned int vELevLen3;
} ST_SKILLS_109;

typedef struct
{
    unsigned char vstate[16];
} ST_STATES_109;

typedef struct
{
    unsigned char vname[64];
    unsigned char pad0x40[128];
    unsigned char vflippyfile[32];
    unsigned char vinvfile[32];
    unsigned char vuniqueinvfile[32];
    unsigned char vsetinvfile[32];

    unsigned char vBetterGem[4];
    unsigned char vcode[4];
    unsigned char vnormcode[4];
    unsigned char vubercode[4];
    unsigned char vultracode[4];
    unsigned char valternategfx[4];
    unsigned char vwclass[4];
    unsigned char v2handedwclass[4];
    unsigned char vTMogType[4];

    unsigned int vminac;
    unsigned int vmaxac;
    unsigned int vgamblemyspcost;
    int vspeed;
    unsigned int vbitfield1;
    unsigned int vcost;
    unsigned int vminstack;
    unsigned int vmaxstack;
    unsigned int vspawnstack;

    unsigned char pad0x188[4];

    unsigned int vgemoffset;
    unsigned short vversion;
    unsigned short vautomyspprefix;

    unsigned short vmissiletype;
    unsigned char vrarity;
    unsigned char vlevel;

    unsigned char vmindam;
    unsigned char vmaxdam;
    unsigned char vminmisdam;
    unsigned char vmaxmisdam;

    unsigned char v2handmindam;
    unsigned char v2handmaxdam;
    unsigned char vrangeadder;
    unsigned char vStrBonus;

    unsigned char vDexBonus;
    unsigned char vreqstr;
    unsigned char vreqdex;
    unsigned char vabsorbs;

    unsigned char vinvwidth;
    unsigned char vinvheight;
    unsigned char vblock;
    unsigned char vdurability;

    unsigned char vnodurability;
    unsigned char vmissile;
    unsigned char vcomponent;
    unsigned char vrArm;

    unsigned char vlArm;
    unsigned char vTorso;
    unsigned char vLegs;
    unsigned char vrSPad;

    unsigned char vlSPad;
    unsigned char v2handed;
    unsigned char vuseable;
    unsigned char vtype;

    unsigned char vtype2;
    unsigned char vsubtype;
    unsigned char vsound;
    unsigned char vunique;

    unsigned char vquest;
    unsigned char vtransparent;
    unsigned char vtranstbl;
    unsigned char pad0x1BB;

    unsigned char vlightradius;
    unsigned char vbelt;
    unsigned char vautobelt;
    unsigned char vstackable;

    unsigned char vspawnable;
    char vspellicon;
    unsigned char vdurwarning;
    unsigned char vqntwarning;

    unsigned char vhasinv;
    unsigned char vgemsockets;
    unsigned char vTransmogrify;
    unsigned char vTMogMin;

    unsigned char vTMogMax;
    unsigned char vhitmyspclass;
    unsigned char v1or2handed;
    unsigned char vgemapplytype;

    unsigned char vlevelreq;
    unsigned char vmagicmysplvl;
    unsigned char vTransform;
    unsigned char vInvTrans;

    unsigned char vcompactsave;
    unsigned char vSkipName;
    unsigned char vNameable;
    unsigned char vAkaraMin;

    unsigned char vGheedMin;
    unsigned char vCharsiMin;
    unsigned char vFaraMin;
    unsigned char vLysanderMin;

    unsigned char vDrognanMin;
    unsigned char vHraltiMin;
    unsigned char vAlkorMin;
    unsigned char vOrmusMin;

    unsigned char vElzixMin;
    unsigned char vAshearaMin;
    unsigned char vCainMin;
    unsigned char vHalbuMin;

    unsigned char vJamellaMin;
    unsigned char vMalahMin;
    unsigned char vLarzukMin;
    unsigned char vDrehyaMin;

    unsigned char vAkaraMax;
    unsigned char vGheedMax;
    unsigned char vCharsiMax;
    unsigned char vFaraMax;

    unsigned char vLysanderMax;
    unsigned char vDrognanMax;
    unsigned char vHraltiMax;
    unsigned char vAlkorMax;

    unsigned char vOrmusMax;
    unsigned char vElzixMax;
    unsigned char vAshearaMax;
    unsigned char vCainMax;

    unsigned char vHalbuMax;
    unsigned char vJamellaMax;
    unsigned char vMalahMax;
    unsigned char vLarzukMax;

    unsigned char vDrehyaMax;
    unsigned char vAkaraMagicMin;
    unsigned char vGheedMagicMin;
    unsigned char vCharsiMagicMin;

    unsigned char vFaraMagicMin;
    unsigned char vLysanderMagicMin;
    unsigned char vDrognanMagicMin;
    unsigned char vHraltiMagicMin;

    unsigned char vAlkorMagicMin;
    unsigned char vOrmusMagicMin;
    unsigned char vElzixMagicMin;
    unsigned char vAshearaMagicMin;

    unsigned char vCainMagicMin;
    unsigned char vHalbuMagicMin;
    unsigned char vJamellaMagicMin;
    unsigned char vMalahMagicMin;

    unsigned char vLarzukMagicMin;
    unsigned char vDrehyaMagicMin;
    unsigned char vAkaraMagicMax;
    unsigned char vGheedMagicMax;

    unsigned char vCharsiMagicMax;
    unsigned char vFaraMagicMax;
    unsigned char vLysanderMagicMax;
    unsigned char vDrognanMagicMax;

    unsigned char vHraltiMagicMax;
    unsigned char vAlkorMagicMax;
    unsigned char vOrmusMagicMax;
    unsigned char vElzixMagicMax;

    unsigned char vAshearaMagicMax;
    unsigned char vCainMagicMax;
    unsigned char vHalbuMagicMax;
    unsigned char vJamellaMagicMax;

    unsigned char vMalahMagicMax;
    unsigned char vLarzukMagicMax;
    unsigned char vDrehyaMagicMax;
    unsigned char vAkaraMagicLvl;

    unsigned char vGheedMagicLvl;
    unsigned char vCharsiMagicLvl;
    unsigned char vFaraMagicLvl;
    unsigned char vLysanderMagicLvl;

    unsigned char vDrognanMagicLvl;
    unsigned char vHraltiMagicLvl;
    unsigned char vAlkorMagicLvl;
    unsigned char vOrmusMagicLvl;

    unsigned char vElzixMagicLvl;
    unsigned char vAshearaMagicLvl;
    unsigned char vCainMagicLvl;
    unsigned char vHalbuMagicLvl;

    unsigned char vJamellaMagicLvl;
    unsigned char vMalahMagicLvl;
    unsigned char vLarzukMagicLvl;
    unsigned char vDrehyaMagicLvl;

    unsigned char vNightmareUpgrade[4];
    unsigned char vHellUpgrade[4];

    unsigned char vPermStoreItem;
    unsigned char pad0x231[3];
} ST_ITEM_109;

typedef struct
{
    unsigned char vName[32];

    unsigned char pad0x21[2];
    unsigned short vversion;

    unsigned int vmod1code; //properties
    unsigned int vmod1param;
    int vmod1min;
    int vmod1max;

    unsigned int vmod2code; //properties
    unsigned int vmod2param;
    int vmod2min;
    int vmod2max;

    unsigned int vmod3code; //properties
    unsigned int vmod3param;
    int vmod3min;
    int vmod3max;

    unsigned char vspawnable;
    unsigned char pad0x55;
    unsigned char vtransformcolor; //colors
    unsigned char pad0x57;

    unsigned int vlevel;
    unsigned int vgroup;
    unsigned int vmaxlevel;

    unsigned char vrare;
    unsigned char vlevelreq;
    unsigned char vclassspecific; //playerclass
    unsigned char vclass; //playerclass

    unsigned char vclasslevelreq;
    unsigned char vitype1; //itemtypes

    unsigned char vitype2;
    unsigned char vitype3;

    unsigned char vitype4;
    unsigned char vitype5;

    unsigned char vitype6;
    unsigned char vitype7;

    unsigned char vetype1; //itemtypes
    unsigned char vetype2;

    unsigned char vetype3;
    unsigned char vetype4;

    unsigned char vetype5;
    unsigned char vfrequency;
    unsigned char pad0x76[2];

    unsigned int vdivide;
    unsigned int vmultiply;
    unsigned int vadd;
} ST_MAGIC_109;

typedef struct
{
    unsigned char pad0x00[14];
    unsigned short vversion;

    unsigned char vitype1;
    unsigned char vitype2;

    unsigned char vitype3;
    unsigned char vitype4;

    unsigned char vitype5;
    unsigned char vitype6;

    unsigned char vitype7;
    unsigned char vetype1;

    unsigned char vetype2;
    unsigned char vetype3;

    unsigned char vetype4;
    unsigned char vname[32];

    unsigned char pad0x3B;
} ST_RARE_109;

typedef struct
{
    unsigned char vcode[4];
    unsigned short vversion;
    unsigned char vname[32];
    unsigned char pad0x26[2];

    unsigned char vbeta;
    unsigned char vtransform;
    unsigned char vinvtransform;
    unsigned char vtransformcolor;

    unsigned int vLevel;

    unsigned char vLevelReq;
    unsigned char pad0x31[3];

    unsigned int vcostmyspmult;
    unsigned int vcostmyspadd;

    unsigned char vcompleted;
    unsigned char pad0x3D[3];

    unsigned int vrarity;

    unsigned int vItemMod1Code; //property
    int vItemMod1Param;
    int vItemMod1Min;
    int vItemMod1Max;

    unsigned int vItemMod2Code; //property
    int vItemMod2Param;
    int vItemMod2Min;
    int vItemMod2Max;

    unsigned int vItemMod3Code; //property
    int vItemMod3Param;
    int vItemMod3Min;
    int vItemMod3Max;

    unsigned int vItemMod4Code; //property
    int vItemMod4Param;
    int vItemMod4Min;
    int vItemMod4Max;

    unsigned int vItemMod5Code; //property
    int vItemMod5Param;
    int vItemMod5Min;
    int vItemMod5Max;

    unsigned int vItemMod6Code; //property
    int vItemMod6Param;
    int vItemMod6Min;
    int vItemMod6Max;

    unsigned int vItemMod7Code; //property
    int vItemMod7Param;
    int vItemMod7Min;
    int vItemMod7Max;

    unsigned int vItemMod8Code; //property
    int vItemMod8Param;
    int vItemMod8Min;
    int vItemMod8Max;

    unsigned int vItemMod9Code; //property
    int vItemMod9Param;
    int vItemMod9Min;
    int vItemMod9Max;

    unsigned int vItemMod10Code; //property
    int vItemMod10Param;
    int vItemMod10Min;
    int vItemMod10Max;
} ST_UNIQUEITEMS_109;

typedef struct
{
    unsigned char vName[96];

    unsigned short vversion;
    unsigned char pad0x62[2];

    unsigned char vNumItems;
    unsigned char pad0x65[32];
    unsigned char vtransform;
    unsigned char vtransformcolor;
    unsigned char pad0x87;
    unsigned int vlevel;

    unsigned char vItem1[4];
    unsigned char pad0x90[4];
    unsigned int vItem1myspRarity;
    unsigned char vItem1myspLvlreq;
    unsigned char pad0x99[3];
    unsigned int vItem1myspcostmyspmult;
    unsigned int vItem1myspcostmyspadd;
    unsigned char vItem1myspAdd;
    unsigned char vItem1myspSuffix[32];
    unsigned char pad0xC5[3];

    unsigned char vItem2[4];
    unsigned char pad0xCC[4];
    unsigned int vItem2myspRarity;
    unsigned char vItem2myspLvlreq;
    unsigned char pad0xD5[3];
    unsigned int vItem2myspcostmyspmult;
    unsigned int vItem2myspcostmyspadd;
    unsigned char vItem2myspAdd;
    unsigned char vItem2myspSuffix[32];
    unsigned char pad0x101[3];

    unsigned char vItem3[4];
    unsigned char pad0x108[4];
    unsigned int vItem3myspRarity;
    unsigned char vItem3myspLvlreq;
    unsigned char pad0x111[3];
    unsigned int vItem3myspcostmyspmult;
    unsigned int vItem3myspcostmyspadd;
    unsigned char vItem3myspAdd;
    unsigned char vItem3myspSuffix[32];
    unsigned char pad0x13D[3];

    unsigned char vItem4[4];
    unsigned char pad0x144[4];
    unsigned int vItem4myspRarity;
    unsigned char vItem4myspLvlreq;
    unsigned char pad0x14D[3];
    unsigned int vItem4myspcostmyspmult;
    unsigned int vItem4myspcostmyspadd;
    unsigned char vItem4myspAdd;
    unsigned char vItem4myspSuffix[32];
    unsigned char pad0x139[3];

    unsigned char vItem5[4];
    unsigned char pad0x180[4];
    unsigned int vItem5myspRarity;
    unsigned char vItem5myspLvlreq;
    unsigned char pad0x189[3];
    unsigned int vItem5myspcostmyspmult;
    unsigned int vItem5myspcostmyspadd;
    unsigned char vItem5myspAdd;
    unsigned char vItem5myspSuffix[32];
    unsigned char pad0x1B5[3];

    unsigned char vItem6[4];
    unsigned char pad0x1BC[4];
    unsigned int vItem6myspRarity;
    unsigned char vItem6myspLvlreq;
    unsigned char pad0x1C5[3];
    unsigned int vItem6myspcostmyspmult;
    unsigned int vItem6myspcostmyspadd;
    unsigned char vItem6myspAdd;
    unsigned char vItem6myspSuffix[32];
    unsigned char pad0x1F1[3];

    unsigned int vI1Code1;
    unsigned int vI1Param1;
    int vI1Min1;
    int vI1Max1;
    unsigned int vI1Code2;
    unsigned int vI1Param2;
    int vI1Min2;
    int vI1Max2;
    unsigned int vI1CodeA;
    unsigned int vI1ParamA;
    int vI1MinA;
    int vI1MaxA;
    unsigned int vI1CodeB;
    unsigned int vI1ParamB;
    int vI1MinB;
    int vI1MaxB;
    unsigned int vI1CodeC;
    unsigned int vI1ParamC;
    int vI1MinC;
    int vI1MaxC;
    unsigned int vI1CodeD;
    unsigned int vI1ParamD;
    int vI1MinD;
    int vI1MaxD;
    unsigned int vI1CodeE;
    unsigned int vI1ParamE;
    int vI1MinE;
    int vI1MaxE;

    unsigned int vI2Code1;
    unsigned int vI2Param1;
    int vI2Min1;
    int vI2Max1;
    unsigned int vI2Code2;
    unsigned int vI2Param2;
    int vI2Min2;
    int vI2Max2;
    unsigned int vI2CodeA;
    unsigned int vI2ParamA;
    int vI2MinA;
    int vI2MaxA;
    unsigned int vI2CodeB;
    unsigned int vI2ParamB;
    int vI2MinB;
    int vI2MaxB;
    unsigned int vI2CodeC;
    unsigned int vI2ParamC;
    int vI2MinC;
    int vI2MaxC;
    unsigned int vI2CodeD;
    unsigned int vI2ParamD;
    int vI2MinD;
    int vI2MaxD;
    unsigned int vI2CodeE;
    unsigned int vI2ParamE;
    int vI2MinE;
    int vI2MaxE;

    unsigned int vI3Code1;
    unsigned int vI3Param1;
    int vI3Min1;
    int vI3Max1;
    unsigned int vI3Code2;
    unsigned int vI3Param2;
    int vI3Min2;
    int vI3Max2;
    unsigned int vI3CodeA;
    unsigned int vI3ParamA;
    int vI3MinA;
    int vI3MaxA;
    unsigned int vI3CodeB;
    unsigned int vI3ParamB;
    int vI3MinB;
    int vI3MaxB;
    unsigned int vI3CodeC;
    unsigned int vI3ParamC;
    int vI3MinC;
    int vI3MaxC;
    unsigned int vI3CodeD;
    unsigned int vI3ParamD;
    int vI3MinD;
    int vI3MaxD;
    unsigned int vI3CodeE;
    unsigned int vI3ParamE;
    int vI3MinE;
    int vI3MaxE;

    unsigned int vI4Code1;
    unsigned int vI4Param1;
    int vI4Min1;
    int vI4Max1;
    unsigned int vI4Code2;
    unsigned int vI4Param2;
    int vI4Min2;
    int vI4Max2;
    unsigned int vI4CodeA;
    unsigned int vI4ParamA;
    int vI4MinA;
    int vI4MaxA;
    unsigned int vI4CodeB;
    unsigned int vI4ParamB;
    int vI4MinB;
    int vI4MaxB;
    unsigned int vI4CodeC;
    unsigned int vI4ParamC;
    int vI4MinC;
    int vI4MaxC;
    unsigned int vI4CodeD;
    unsigned int vI4ParamD;
    int vI4MinD;
    int vI4MaxD;
    unsigned int vI4CodeE;
    unsigned int vI4ParamE;
    int vI4MinE;
    int vI4MaxE;

    unsigned int vI5Code1;
    unsigned int vI5Param1;
    int vI5Min1;
    int vI5Max1;
    unsigned int vI5Code2;
    unsigned int vI5Param2;
    int vI5Min2;
    int vI5Max2;
    unsigned int vI5CodeA;
    unsigned int vI5ParamA;
    int vI5MinA;
    int vI5MaxA;
    unsigned int vI5CodeB;
    unsigned int vI5ParamB;
    int vI5MinB;
    int vI5MaxB;
    unsigned int vI5CodeC;
    unsigned int vI5ParamC;
    int vI5MinC;
    int vI5MaxC;
    unsigned int vI5CodeD;
    unsigned int vI5ParamD;
    int vI5MinD;
    int vI5MaxD;
    unsigned int vI5CodeE;
    unsigned int vI5ParamE;
    int vI5MinE;
    int vI5MaxE;

    unsigned int vI6Code1;
    unsigned int vI6Param1;
    int vI6Min1;
    int vI6Max1;
    unsigned int vI6Code2;
    unsigned int vI6Param2;
    int vI6Min2;
    int vI6Max2;
    unsigned int vI6CodeA;
    unsigned int vI6ParamA;
    int vI6MinA;
    int vI6MaxA;
    unsigned int vI6CodeB;
    unsigned int vI6ParamB;
    int vI6MinB;
    int vI6MaxB;
    unsigned int vI6CodeC;
    unsigned int vI6ParamC;
    int vI6MinC;
    int vI6MaxC;
    unsigned int vI6CodeD;
    unsigned int vI6ParamD;
    int vI6MinD;
    int vI6MaxD;
    unsigned int vI6CodeE;
    unsigned int vI6ParamE;
    int vI6MinE;
    int vI6MaxE;

    unsigned int vPCode2;
    unsigned int vPParam2;
    int vPMin2;
    int vPMax2;
    unsigned int vPCode3;
    unsigned int vPParam3;
    int vPMin3;
    int vPMax3;
    unsigned int vPCode4;
    unsigned int vPParam4;
    int vPMin4;
    int vPMax4;
    unsigned int vPCode5;
    unsigned int vPParam5;
    int vPMin5;
    int vPMax5;

    unsigned int vFCode1;
    unsigned int vFParam1;
    int vFMin1;
    int vFMax1;
    unsigned int vFCode2;
    unsigned int vFParam2;
    int vFMin2;
    int vFMax2;
    unsigned int vFCode3;
    unsigned int vFParam3;
    int vFMin3;
    int vFMax3;
    unsigned int vFCode4;
    unsigned int vFParam4;
    int vFMin4;
    int vFMax4;
    unsigned int vFCode5;
    unsigned int vFParam5;
    int vFMin5;
    int vFMax5;
    unsigned int vFCode6;
    unsigned int vFParam6;
    int vFMin6;
    int vFMax6;
} ST_SETITEMS_109;

typedef struct
{
    char vSpellIcon;
    unsigned char pad0x01[3];

    unsigned int vSpellOffset;
    unsigned int vSkillScrollOffset;
    unsigned int vSkillBookOffset;

    unsigned int vBaseCost;
    unsigned int vCostPerCharge;

    unsigned char vScrollSpellCode[4];
    unsigned char vBookSpellCode[4];
    unsigned char vName[32];
    unsigned char pad0x40[4];
} ST_BOOKS_109;

typedef struct
{
    unsigned char vName[64];
    unsigned char vRunemyspName[64];

    unsigned char vcomplete;
    unsigned char vserver;
    unsigned char pad0x82[4];
    unsigned char vitype1; //itemtypes

    unsigned char vitype2; //itemtypes
    unsigned char vitype3; //itemtypes

    unsigned char vitype4; //itemtypes
    unsigned char vitype5; //itemtypes

    unsigned char vitype6; //itemtypes
    unsigned char vetype1; //itemtypes

    unsigned char vetype2; //itemtypes
    unsigned char vetype3; //itemtypes

    unsigned int vRune1; //miscs
    unsigned int vRune2;

    unsigned int vRune3;
    unsigned int vRune4;

    unsigned int vRune5;
    unsigned int vRune6;

    unsigned int vT1Code1; //properties
    unsigned int vT1Param1;
    int vT1Min1;
    int vT1Max1;

    unsigned int vT1Code2; //properties
    unsigned int vT1Param2;
    int vT1Min2;
    int vT1Max2;

    unsigned int vT1Code3; //properties
    unsigned int vT1Param3;
    int vT1Min3;
    int vT1Max3;

    unsigned int vT1Code4; //properties
    unsigned int vT1Param4;
    int vT1Min4;
    int vT1Max4;

    unsigned int vT1Code5; //properties
    unsigned int vT1Param5;
    int vT1Min5;
    int vT1Max5;

    unsigned int vT1Code6; //properties
    unsigned int vT1Param6;
    int vT1Min6;
    int vT1Max6;

    unsigned int vT1Code7; //properties
    unsigned int vT1Param7;
    int vT1Min7;
    int vT1Max7;
} ST_RUNES_109;

typedef struct
{
    unsigned char vName[32];
    unsigned char vToken[4];
    unsigned char vDT_Dir;
    unsigned char vNU_Dir;
    unsigned char vWL_Dir;
    unsigned char vGH_Dir;
    unsigned char vA1_Dir;
    unsigned char vA2_Dir;
    unsigned char vBL_Dir;
    unsigned char vSC_Dir;
    unsigned char vS1_Dir;
    unsigned char vS2_Dir;
    unsigned char vS3_Dir;
    unsigned char vS4_Dir;
    unsigned char vDD_Dir;
    unsigned char vKB_Dir;
    unsigned char vSQ_Dir;
    unsigned char vRN_Dir;
} ST_MONTYPE_109;

typedef struct
{
    unsigned int vAmazon;
    unsigned int vSorceress;
    unsigned int vNecromancer;
    unsigned int vPaladin;

    unsigned int vBarbarian;
    unsigned int vDruid;
    unsigned int vAssassin;
} ST_EXPERIENCE_109;

typedef struct
{
    unsigned char vId;
    unsigned char vPal;
    unsigned char vAct;
    unsigned char vRain;

    unsigned char vMud;
    unsigned char vNoPer;
    unsigned char vIsInside;
    unsigned char vDrawEdges;

    unsigned int vWarpDist;

    unsigned char vMonLvl1;
    unsigned char vMonLvl2;
    unsigned char vMonLvl3;
    unsigned char vMonLvl1Ex;

    unsigned char vMonLvl2Ex;
    unsigned char vMonLvl3Ex;
    unsigned char pad0x12[2];

    unsigned int vMonDen;

    unsigned char vMonUMin;
    unsigned char vMonUMax;
    unsigned char vMonWndr;
    unsigned char vMonSpcWalk;

    unsigned char vQuest;
    unsigned char vMtot;
    unsigned char pad0x1E[2];

    unsigned int vM1;
    unsigned int vM2;
    unsigned int vM3;
    unsigned int vM4;
    unsigned int vM5;
    unsigned int vM6;
    unsigned int vM7;
    unsigned int vM8;
    unsigned int vM9;
    unsigned int vM10;
    unsigned int vM11;
    unsigned int vM12;
    unsigned int vM13;
    unsigned int vM14;
    unsigned int vM15;
    unsigned int vM16;
    unsigned int vM17;
    unsigned int vM18;
    unsigned int vM19;
    unsigned int vM20;
    unsigned int vM21;
    unsigned int vM22;
    unsigned int vM23;
    unsigned int vM24;
    unsigned int vM25;

    unsigned int vS1;
    unsigned int vS2;
    unsigned int vS3;
    unsigned int vS4;
    unsigned int vS5;
    unsigned int vS6;
    unsigned int vS7;
    unsigned int vS8;
    unsigned int vS9;
    unsigned int vS10;
    unsigned int vS11;
    unsigned int vS12;
    unsigned int vS13;
    unsigned int vS14;
    unsigned int vS15;
    unsigned int vS16;
    unsigned int vS17;
    unsigned int vS18;
    unsigned int vS19;
    unsigned int vS20;
    unsigned int vS21;
    unsigned int vS22;
    unsigned int vS23;
    unsigned int vS24;
    unsigned int vS25;

    unsigned char vUtot;
    unsigned char pad0xE9[3];

    unsigned int vU1;
    unsigned int vU2;
    unsigned int vU3;
    unsigned int vU4;
    unsigned int vU5;
    unsigned int vU6;
    unsigned int vU7;
    unsigned int vU8;
    unsigned int vU9;
    unsigned int vU10;
    unsigned int vU11;
    unsigned int vU12;
    unsigned int vU13;
    unsigned int vU14;
    unsigned int vU15;
    unsigned int vU16;
    unsigned int vU17;
    unsigned int vU18;
    unsigned int vU19;
    unsigned int vU20;
    unsigned int vU21;
    unsigned int vU22;
    unsigned int vU23;
    unsigned int vU24;
    unsigned int vU25;

    unsigned int vC1;
    unsigned int vC2;
    unsigned int vC3;
    unsigned int vC4;
    unsigned int vC5;
    unsigned int vCA1;
    unsigned int vCA2;
    unsigned int vCA3;
    unsigned int vCA4;
    unsigned int vCA5;
    unsigned int vCD1;
    unsigned int vCD2;
    unsigned int vCD3;
    unsigned int vCD4;
    unsigned int vCD5;

    unsigned char vWaypoint;
    unsigned char vObjGrp0;
    unsigned char vObjGrp1;
    unsigned char vObjGrp2;

    unsigned char vObjGrp3;
    unsigned char vObjGrp4;
    unsigned char vObjGrp5;
    unsigned char vObjGrp6;

    unsigned char vObjGrp7;
    unsigned char vObjPrb0;
    unsigned char vObjPrb1;
    unsigned char vObjPrb2;

    unsigned char vObjPrb3;
    unsigned char vObjPrb4;
    unsigned char vObjPrb5;
    unsigned char vObjPrb6;

    unsigned char vObjPrb7;
    unsigned char vLevelName[40];
    unsigned char vLevelWarp[40];
    unsigned char vEntryFile[40];

    unsigned char pad0x215[163];

    unsigned int vThemes;
    unsigned int vFloorFilter;
    unsigned int vBlankScreen;
    unsigned int vSoundEnv;
} ST_LEVELS_109;

typedef struct
{
    int vLayer;
    int vSizeX;
    int vSizeY;
    int vOffsetX;

    int vOffsetY;
    int vDepend;
    int vDrlgType;
    int vLevelType;

    int vSubType;
    int vSubTheme;
    int vSubWaypoint;
    int vSubShrine;

    int vVis0;
    int vVis1;
    int vVis2;
    int vVis3;

    int vVis4;
    int vVis5;
    int vVis6;
    int vVis7;

    int vWarp0;
    int vWarp1;
    int vWarp2;
    int vWarp3;

    int vWarp4;
    int vWarp5;
    int vWarp6;
    int vWarp7;

    unsigned char vIntensity;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;

    int vPortal;
    int vPosition;
    int vSaveMonsters;
    int vLOSDraw;
} ST_LEVELDEFS_109;

typedef struct
{
    unsigned int vLevel;
    unsigned int vRooms;
    unsigned int vSizeX;
    unsigned int vSizeY;
    unsigned int vMerge;
} ST_LVLMAZE_109;

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

    unsigned char vTrapProb;
    unsigned char pad0xCD[3];

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

    unsigned int vFrameDelta0;
    unsigned int vFrameDelta1;

    unsigned int vFrameDelta2;
    unsigned int vFrameDelta3;

    unsigned int vFrameDelta4;
    unsigned int vFrameDelta5;

    unsigned int vFrameDelta6;
    unsigned int vFrameDelta7;

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
    unsigned char pad0x157;

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
    unsigned char vFlicker;
    unsigned char pad0x187;

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
    unsigned char pad0x1AE[2];

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
} ST_OBJECTS_109;

typedef struct
{
    unsigned char vName[60];
    unsigned char pad0x3C[120];

    unsigned char vMonType1;
    unsigned char vMonType2;
    unsigned char vMonType3;
    unsigned char vMonType4;
    unsigned char vMonType5;
    unsigned char vMonType6;
    unsigned char vMonType7;
    unsigned char vMonType8;
    unsigned char vMonType9;
    unsigned char vMonType10;
    unsigned char vMonType11;
    unsigned char vMonType12;
    unsigned char vMonType13;
    unsigned char vMonType14;
    unsigned char vMonType15;
    unsigned char vMonType16;
    unsigned char vMonType17;
    unsigned char vMonType18;
    unsigned char vMonType19;
    unsigned char vMonType20;
    unsigned char vMonType21;
    unsigned char vMonType22;
    unsigned char vMonType23;
    unsigned char vMonType24;
    unsigned char vMonType25;
    unsigned char vMonType26;
    unsigned char vMonType27;
    unsigned char vMonType28;
    unsigned char vMonType29;
    unsigned char vMonType30;
    unsigned char vMonType31;
    unsigned char vMonType32;
    unsigned char vMonType33;
    unsigned char vMonType34;
    unsigned char vMonType35;
    unsigned char vMonType36;
    unsigned char pad0xD8[540];
} ST_UNIQUE_109;

typedef struct
{
    char vTreasuremyspClass[32];

    int vPicks;

    short vMagic;
    short vRare;
    short vSet;
    short vUnique;

    unsigned char pad0x2C[4];

    int vNoDrop;

    char vItem1[64];
    char vItem2[64];
    char vItem3[64];
    char vItem4[64];
    char vItem5[64];
    char vItem6[64];
    char vItem7[64];
    char vItem8[64];
    char vItem9[64];
    char vItem10[64];

    int vProb1;
    int vProb2;
    int vProb3;
    int vProb4;
    int vProb5;
    int vProb6;
    int vProb7;
    int vProb8;
    int vProb9;
    int vProb10;
} ST_TREASURECLASSEX_109;

typedef struct
{
    unsigned char vClass[60];
    unsigned char pad0x3C[120];
    unsigned char vDescriptor[60];
    unsigned char pad0xF0[120];

    unsigned int vBaseId;

    unsigned char vSpawned;
    unsigned char vCode[4];
    unsigned char pad0x171[3];

    unsigned int vMinHP;
    unsigned int vMinHPmybr1Nmybr2;
    unsigned int vMinHPmybr1Hmybr2;
    unsigned int vMaxHP;
    unsigned int vMaxHPmybr1Nmybr2;
    unsigned int vMaxHPmybr1Hmybr2;

    unsigned char vNoMap;
    unsigned char pad0x18D[3];

    unsigned int vSizeX;
    unsigned int vSizeY;

    unsigned char vHeight;
    unsigned char vNoOverlays;
    unsigned char vOverlayHeight;
    unsigned char pad0x19B;

    unsigned int vVelocity;
    unsigned int vRun;

    unsigned char pad0x1A4[8];

    unsigned int vAC;
    unsigned int vACmybr1Nmybr2;
    unsigned int vACmybr1Hmybr2;
    unsigned int vEXP;
    unsigned int vEXPmybr1Nmybr2;
    unsigned int vEXPmybr1Hmybr2;

    unsigned char vLevel;
    unsigned char vLevelmybr1Nmybr2;
    unsigned char vLevelmybr1Hmybr2;
    unsigned char vCanStealFrom;

    unsigned char vColdEffect;
    unsigned char vMeleeRng;
    unsigned char vRarity;
    unsigned char vMinGrp;

    unsigned char vMaxGrp;
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
    unsigned char pad0x1DE[2];

    unsigned char vBaseW[4];

    unsigned char vAIParam1;
    unsigned char vAIParam2;
    unsigned char vAIParam3;
    unsigned char vAIParam4;

    unsigned char vAIParam5;
    unsigned char vModeDH;
    unsigned char vModeN;
    unsigned char vModeW;

    unsigned char vModeGH;
    unsigned char vModeA1;
    unsigned char vModeA2;
    unsigned char vModeB;

    unsigned char vModeC;
    unsigned char vModeS1;
    unsigned char vModeS2;
    unsigned char vModeS3;

    unsigned char vModeS4;
    unsigned char vModeDD;
    unsigned char vModeKB;
    unsigned char vModeSQ;

    unsigned char vModeRN;
    unsigned char vElMode;
    unsigned char vElType;
    unsigned char vElPct;

    unsigned int vElMinD;
    unsigned int vElMaxD;
    unsigned int vElDur;
    unsigned int vMissA1;
    unsigned int vMissA2;
    unsigned int vMissS1;
    unsigned int vMissS2;
    unsigned int vMissS3;
    unsigned int vMissS4;
    unsigned int vMissC;
    unsigned int vMissSQ;

    unsigned char vA1Move;
    unsigned char pad0x229[3];
    unsigned int vA1MinD;
    unsigned int vA1MinDmybr1Nmybr2;
    unsigned int vA1MinDmybr1Hmybr2;
    unsigned int vA1MaxD;
    unsigned int vA1MaxDmybr1Nmybr2;
    unsigned int vA1MaxDmybr1Hmybr2;
    unsigned int vA1ToHit;
    unsigned int vA1ToHitmybr1Nmybr2;
    unsigned int vA1ToHitmybr1Hmybr2;

    unsigned char vA2Move;
    unsigned char pad0x251[3];
    unsigned int vA2MinD;
    unsigned int vA2MinDmybr1Nmybr2;
    unsigned int vA2MinDmybr1Hmybr2;
    unsigned int vA2MaxD;
    unsigned int vA2MaxDmybr1Nmybr2;
    unsigned int vA2MaxDmybr1Hmybr2;
    unsigned int vA2ToHit;
    unsigned int vA2ToHitmybr1Nmybr2;
    unsigned int vA2ToHitmybr1Hmybr2;

    unsigned char vS1Move;
    unsigned char pad0x279[3];
    unsigned int vS1MinD;
    unsigned int vS1MinDmybr1Nmybr2;
    unsigned int vS1MinDmybr1Hmybr2;
    unsigned int vS1MaxD;
    unsigned int vS1MaxDmybr1Nmybr2;
    unsigned int vS1MaxDmybr1Hmybr2;
    unsigned int vS1ToHit;
    unsigned int vS1ToHitmybr1Nmybr2;
    unsigned int vS1ToHitmybr1Hmybr2;

    unsigned char vS2Move;
    unsigned char vS3Move;
    unsigned char vS4Move;
    unsigned char vToBlock;

    unsigned char vCMove;
    unsigned char vAlign;
    unsigned char vIsMelee;
    unsigned char vIsSel;

    unsigned char vIsSel2;
    unsigned char vNeverSel;
    unsigned char vCorpseSel;
    unsigned char vIsAtt;

    unsigned char vPetIgnore;
    unsigned char vIsNPC;
    unsigned char vIsCritter;
    unsigned char vInTown;

    unsigned char vBleed;
    unsigned char vShadow;
    unsigned char vLight;
    unsigned char vNoUniqueShift;

    unsigned char vCompositeDeath;
    unsigned char pad0x2B5[3];

    unsigned int vSkill1;
    unsigned int vSkill2;
    unsigned int vSkill3;
    unsigned int vSkill4;
    unsigned int vSkill5;

    unsigned char vSkill1Seq;
    unsigned char vSkill2Seq;
    unsigned char vSkill3Seq;
    unsigned char vSkill4Seq;

    unsigned char vSkill5Seq;
    unsigned char vSkill1Lvl;
    unsigned char vSkill2Lvl;
    unsigned char vSkill3Lvl;

    unsigned char vSkill4Lvl;
    unsigned char vSkill5Lvl;
    unsigned char vLightR;
    unsigned char vLightG;

    unsigned char vLightB;
    unsigned char vDamageResist;
    unsigned char vDamageResistmybr1Nmybr2;
    unsigned char vDamageResistmybr1Hmybr2;

    unsigned char vMagicResist;
    unsigned char vMagicResistmybr1Nmybr2;
    unsigned char vMagicResistmybr1Hmybr2;
    unsigned char vFireResist;

    unsigned char vFireResistmybr1Nmybr2;
    unsigned char vFireResistmybr1Hmybr2;
    unsigned char vLightResist;
    unsigned char vLightResistmybr1Nmybr2;

    unsigned char vLightResistmybr1Hmybr2;
    unsigned char vColdResist;
    unsigned char vColdResistmybr1Nmybr2;
    unsigned char vColdResistmybr1Hmybr2;

    unsigned char vPoisonResist;
    unsigned char vPoisonResistmybr1Nmybr2;
    unsigned char vPoisonResistmybr1Hmybr2;
    unsigned char pad0x2EB;

    unsigned int vDamageRegen;

    unsigned char veLUndead;
    unsigned char veHUndead;
    unsigned char veDemon;
    unsigned char veMagicUsing;

    unsigned char veLarge;
    unsigned char veSmall;
    unsigned char veFlying;
    unsigned char veOpenDoors;

    unsigned char veBoss;
    unsigned char veSpawnCol;
    unsigned char vPixHeight;
    unsigned char vInteract;

    unsigned char vSpawnComponents;
    unsigned char vSoft;
    unsigned char pad0x2FE[2];

    unsigned char vHeart[4];
    unsigned char vBodyPart[4];
    unsigned int vTreasureClass1; // treasure
    unsigned int vTreasureClass2;
    unsigned int vTreasureClass3;
    unsigned int vTreasureClass4;
    unsigned int vTreasureClass1mybr1Nmybr2; // treasure
    unsigned int vTreasureClass2mybr1Nmybr2;
    unsigned int vTreasureClass3mybr1Nmybr2;
    unsigned int vTreasureClass4mybr1Nmybr2;
    unsigned int vTreasureClass1mybr1Hmybr2; // treasure
    unsigned int vTreasureClass2mybr1Hmybr2;
    unsigned int vTreasureClass3mybr1Hmybr2;
    unsigned int vTreasureClass4mybr1Hmybr2;

    unsigned char vSpawnPctBonus;
    unsigned char vKillable;
    unsigned char vSwitch;
    unsigned char vRestore;

    unsigned char vNeverCount;
    unsigned char vHitClass;
    unsigned char vSplEndDeath;
    unsigned char vSplGetModeChart;

    unsigned char vSplEndGeneric;
    unsigned char vSplClientEnd;
    unsigned char vDeadCollision;
    unsigned char vUnflatDead;

    unsigned char vBloodLocal;
    unsigned char vDeathDamage;
    unsigned char vNoGfxHitTest;
    unsigned char pad0x347;

    unsigned int vHitTestTop;
    unsigned int vHitTestLeft;

    unsigned char vHitTestWidth;
    unsigned char vHitTestHeight;
    unsigned char pad0x352[2];

    unsigned int vAutomapCel;

    unsigned char vGenericSpawn;
    unsigned char vSparsePopulate;
    unsigned char vZoo;
    unsigned char vObjectCollision;

    unsigned char vInert;
    unsigned char pad0x35D[3];
} ST_MONSTATS_109;

typedef struct
{
    unsigned char vName[60];
    unsigned char pad0x3C[120];

    unsigned int vClass;
    unsigned int vMod1;
    unsigned int vMod2;
    unsigned int vMod3;
    unsigned int vMinGrp;
    unsigned int vMaxGrp;
    unsigned int vAutoPos;
    unsigned int vEClass;
    unsigned int vStacks;

    unsigned int vTC; //treasure
    unsigned int vTCmybr1Nmybr2; //treasure
    unsigned int vTCmybr1Hmybr2; //treasure
} ST_SUPERUNIQUE_109;

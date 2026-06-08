#ifndef __ENUMS_H__
#define __ENUMS_H__

enum EMiniGameType {
    EMiniGameType_TARGETS,
    EMiniGameType_SLINGSHOT,
    EMiniGameType_BOWLING,
};

enum ExplosionDirection {
    ExplosionDirection_Up,
    ExplosionDirection_Down,
    ExplosionDirection_AllDirections,
};

enum OnFootEffect {
    OnFootEffect_Collection,
    OnFootEffect_Breakable0,
    OnFootEffect_Impact0,
    OnFootEffect_Impact1,
    OnFootEffect_Impact2,
};

enum TypeValues {
    TypeRace,
    TypeBattle,
    TypeStunt,
    TypeMinigame,
    TypeOnFootMinigame,
    TypeAny,
};

enum DrivingValues {
    DrivingRace,
    DrivingKamikaze,
    DrivingRailShooter,
    DrivingRollingThunder,
    DrivingTimeTrial,
};

enum ThemeValues {
    ThemeAdventure,
    ThemeFairy,
    ThemeDino,
    ThemeEgypt,
    ThemeSolar,
    ThemeMidway,
};

enum SaveMode {
    SaveMode_Load,
    SaveMode_Save,
    SaveMode_Create,
};

enum ModeControlState {
    ModeControl_WaitingForStart,
    ModeControl_Intro,
    ModeControl_PreCountdown,
    ModeControl_CountdownToStart,
    ModeControl_Playing,
    ModeControl_WaitingForFinish,
    ModeControl_Finished,
};

enum ModeType {
    Mode_Race,
    Mode_Battle,
    Mode_Stunt,
    Mode_Platform,
};

enum Skill {
    Easiest,
    Easy,
    Medium,
    Hard,
    Multiplayer,
};

enum TurboIncreaseEvent {
    TurboIncrease_Powerslide_Stage_01,
    TurboIncrease_Powerslide_Stage_02,
    TurboIncrease_Powerslide_Stage_03,
    TurboIncrease_GoodLanding,
    TurboIncrease_Kill_Unclashed,
    TurboIncrease_Kill_Double,
    TurboIncrease_Kill_Rampage,
    TurboIncrease_Kill_Clashed,
    TurboIncrease_Shoot_Stateprop,
};

enum PresentationSound {
    PresentationSound_Back,
    PresentationSound_ControllerInput,
    PresentationSound_Invalid,
    PresentationSound_ScreenChange,
    PresentationSound_Select,
    PresentationSound_SelectVO,
    PresentationSound_SelectMusic,
    PresentationSound_Load,
    PresentationSound_Bell,
    PresentationSound_Crystal,
    PresentationSound_KO,
    PresentationSound_Vibration,
};

enum PresentationLanguage {
    PresentationLanguage_English,
    PresentationLanguage_French,
    PresentationLanguage_Italian,
    PresentationLanguage_German,
    PresentationLanguage_Spanish,
    PresentationLanguage_Dutch,
    PresentationLanguage_Japanese,
};

enum GameCollisionType {
    GameCollisionType_Unknown00000001 = 1,
    GameCollisionType_Ground = 2,
    GameCollisionType_CarChassis = 4,
    GameCollisionType_CarUndercarriage = 8,
    GameCollisionType_WeaponAndPowerUp = 0x10,
    GameCollisionType_WeaponAndPowerUpContainer = 0x20,
    GameCollisionType_Fence = 0x40,
    GameCollisionType_SpeedBoost = 0x80,
    GameCollisionType_Unknown00000100 = 0x100,
    GameCollisionType_Edge = 0x200,
    GameCollisionType_Warp = 0x400,
    GameCollisionType_StateProp = 0x800,
    GameCollisionType_Unknown00001000 = 0x1000,
    GameCollisionType_StickyCharge = 0x2000,
    GameCollisionType_GuidedLandMissile = 0x4000,
    GameCollisionType_ResetVolume = 0x8000,
    GameCollisionType_TrackingMissile = 0x10000,
    GameCollisionType_Unknown00020000 = 0x20000,
    GameCollisionType_Unknown00040000 = 0x40000,
    GameCollisionType_BowlingBallAmmo = 0x80000,
    GameCollisionType_Ammo = 0x100000,
};

enum SurfaceTypeEnum {
    SURFACE_DEFAULT,
    SURFACE_ASPHALT,
    SURFACE_GRASS,
    SURFACE_WATER,
    SURFACE_WATER_SHOULDER,
    SURFACE_MUD,
    SURFACE_MUD_SHOULDER,
    SURFACE_SAND,
    SURFACE_SAND_SHOULDER,
    SURFACE_GRAVEL,
    SURFACE_GRAVEL_SHOULDER,
    SURFACE_DIRT,
    SURFACE_DIRT_SHOULDER,
    SURFACE_METALGRATE,
    SURFACE_METALGRATE_SHOULDER,
    SURFACE_WOOD,
    SURFACE_WOOD_SHOULDER,
    SURFACE_BRICK,
    SURFACE_BRICK_SHOULDER,
    SURFACE_GRASS_SHOULDER,
    SURFACE_ICE,
    SURFACE_ICE_SHOULDER,
    SURFACE_SNOW,
    SURFACE_SNOW_SHOULDER,
    SURFACE_INVALID,
};

enum OutputSamplePlatform {
    PS2,
    XBOX,
    GC,
    PC,
    ALL,
};

enum SoundPositionTypeEnum {
    NONE,
    LEFT,
    RIGHT,
    POSITIONAL,
};

enum SplineMovementEnum {
    SPLINEMOVEMENT_NONE,
    SPLINEMOVEMENT_PITCH,
    SPLINEMOVEMENT_ROLL,
    SPLINEMOVEMENT_YAW,
};

enum VSYNC_MODE {
    VSYNC_NEVER,
    VSYNC_ALWAYS,
    VSYNC_ABOVE_30,
};

enum ScreenPosition {
    Left,
    Center,
    Right,
};

enum WeaponTypeEnum {
    WEAPONANDPOWERUP_RANDOM = -1,
    WEAPONTYPE_EXPLOSIVECHARGE,
    WEAPONTYPE_STICKYCHARGE,
    WEAPONTYPE_TRACKINGMISSILE,
    WEAPONTYPE_TRACKINGSWARM,
    WEAPONTYPE_TRACKINGSWARMMISSILE,
    WEAPONTYPE_GUIDEDLANDMISSILE,
    WEAPONTYPE_GUIDEDMARBLEMISSILE,
    WEAPONTYPE_LARGEPHYSICSPROJECTILE,
    WEAPONTYPE_LARGEPHYSICSPROJECTILE2,
    WEAPONTYPE_LARGEPHYSICSPROJECTILE3,
    WEAPONTYPE_LOCKONMISSILE,
    POWERUPTYPE_SPEEDBOOST,
    POWERUPTYPE_INVISIBILITYSHIELD,
    POWERUPTYPE_DAMAGEMODIFIER,
    POWERUPTYPE_HEALTH,
    POWERUPTYPE_CRYSTAL,
    WEAPONTYPE_MACHINEGUN,
    WEAPONTYPE_ENERGYBALLAMMO,
    WEAPONTYPE_BOWLINGBALLAMMO,
    WEAPONTYPE_SHOTGUN,
    WEAPONTYPE_BOMBLET,
    WEAPONTYPE_BOMBLETAMMO,
    WEAPONTYPE_VELCROAMMO,
    WEAPONTYPE_ROCKETAMMO,
    WEAPONTYPE_CHAINGUN,
};

enum WeaponEffectTypeEnum {
    WEAPONEFFECTTYPE_WUMPA,
    WEAPONEFFECTTYPE_SHOTGUN,
    WEAPONEFFECTTYPE_MACHINEGUN,
    WEAPONEFFECTTYPE_CHAINGUN,
};

enum WeaponAndPowerUpDistributionEnum {
    DISTRIBUTION_SINGLEITEM,
    DISTRIBUTION_CLASHITEM,
    DISTRIBUTION_SINGLEITEM_AI,
    DISTRIBUTION_CLASHITEM_AI,
};

enum TargetingSystemEnum {
    TARGETINGSYSTEM_RETICULE,
    TARGETINGSYSTEM_GROUND,
};

enum AIClashFrequency {
    AI_NEVER_CLASH,
    AI_FREQUENTLY_CLASH,
    AI_RARELY_CLASH,
};

enum ClashFxFrequency {
    ClashFxFrequency_Always,
    ClashFxFrequency_Sometimes,
    ClashFxFrequency_Never
};

enum CAR_EFFECT {
    CAR_EFFECT_EXPLODE,
    CAR_EFFECT_CLASH_FLASH,
    CAR_EFFECT_CLASH_INVITE,
    CAR_EFFECT_CLASH_MERGING,
    CAR_EFFECT_CLASH_SQUIRT,
    CAR_EFFECT_CLASH_TRANSFORMING,
    CAR_EFFECT_CLASH_UNCLASH,
    CAR_EFFECT_DAMAGE_STAGE_01,
    CAR_EFFECT_DAMAGE_STAGE_02,
    CAR_EFFECT_DAMAGE_STAGE_03,
    CAR_EFFECT_SMOKE_STAGE_01,
    CAR_EFFECT_SMOKE_STAGE_02,
    CAR_EFFECT_SMOKE_STAGE_03,
    CAR_EFFECT_FIREMAN_FLARE,
    CAR_EFFECT_UNKNOWN_0E,
    CAR_EFFECT_HARD_LANDING,
    CAR_EFFECT_PEELOUT,
    CAR_EFFECT_POWERSLIDE_STAGE_01,
    CAR_EFFECT_POWERSLIDE_STAGE_02,
    CAR_EFFECT_POWERSLIDE_STAGE_03,
    CAR_EFFECT_QUAD,
    CAR_EFFECT_RUB_CAR,
    CAR_EFFECT_RUB_WALL,
    CAR_EFFECT_BALLOONS,
};

enum ScaleEffectType {
    ScaleEffectUpDown,
    ScaleEffectUp,
    ScaleEffectDown,
};

enum SparkleAlign {
    SparkleAlign_None,
    SparkleAlign_Unknown01,
    SparkleAlign_MotionStreak,
    SparkleAlign_Flat,
    SparkleAlign_Rotation,
    SparkleAlign_RotateLocalAxis,
    SparkleAlign_DecalToNormal,
};

enum SparkleColor {
    SparkleColor_LinearDown,
    SparkleColor_LinearDownAtHalf,
    SparkleColor_LinearAlphaDown,
    SparkleColor_LinearRedDownAtHalf,
    SparkleColor_BulgeDown,
};

enum SparkleMotion {
    SparkleMotion_Linear,
    SparkleMotion_Decelerate,
    SparkleMotion_Gravity,
    SparkleMotion_Drift,
};

enum SparkleScale {
    SparkleScale_Constant,
    SparkleScale_LinearDown,
    SparkleScale_BulgeDown,
    SparkleScale_LinearUp,
    SparkleScale_LinearGrow,
    SparkleScale_LinearTriple,
};

enum SparkleBlendMode {
    SparkleBlendMode_None,
    SparkleBlendMode_Alpha,
    SparkleBlendMode_Add,
    SparkleBlendMode_Unknown03,
    SparkleBlendMode_Modulate,
    SparkleBlendMode_Modulate2,
    SparkleBlendMode_AddModulateAlpha,
    SparkleBlendMode_SubModulateAlpha,
    SparkleBlendMode_DestAlpha,
};

enum EConversationType {
    EConversationType_NONE = -1,
    EConversationType_AMBIENT,
    EConversationType_MISSION_CAR_START,
    EConversationType_MISSION_CAR_WAITING,
    EConversationType_MISSION_CAR_SUCCESS,
    EConversationType_MISSION_CRYSTAL_START,
    EConversationType_MISSION_CRYSTAL_WAITING,
    EConversationType_MISSION_CRYSTAL_SUCCESS,
    EConversationType_MISSION_SKIN_START,
    EConversationType_MISSION_SKIN_WAITING,
    EConversationType_MISSION_SKIN_SUCCESS,
    EConversationType_MINIGAME,
};

enum ConversationRangeEnum {
    ConversationRange_Crystal,
    ConversationRange_Car,
    ConversationRange_Skin,
};

enum TutorialConditionType {
    TutorialCondition_PowerupHeld,
    TutorialCondition_FullBoost,
    TutorialCondition_AimingLow,
};

enum GEARS {
    GEAR_R = -1,
    GEAR_N,
    GEAR_1,
    GEAR_2,
    GEAR_3,
    GEAR_4,
    GEAR_5,
    GEAR_6,
};

#endif

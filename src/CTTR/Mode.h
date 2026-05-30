#ifndef __MODE_H__
#define __MODE_H__

enum ModeControlState {
    ModeControl_WaitingForStart,
    ModeControl_Intro,
    ModeControl_PreCountdown,
    ModeControl_CountdownToStart,
    ModeControl_Playing,
    ModeControl_WaitingForFinish,
    ModeControl_Finished,
};

struct CameraArray;

struct ModeControl {
    ModeControlState GetState();
    void SetState(ModeControlState state);
    void SetParadeLapCameras(const CameraArray* array);
    void StopParadeLapCameras();
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

struct ModeManager {
    ModeType GetActiveMode();
    void SetActiveMode(ModeType mode);
    ModeControl* GetActiveControl();
    void SetActiveControl(ModeControl* mode);
    bool IsPlaying();
    void SetPlaying(bool playing);
    void RegisterOnlineData();
    void UnregisterOnlineData();
    Skill GetSkill();
    void SetSkill(Skill skill);
    void SetTier(int);
    int GetTier() const;
    void SetMultiplayer(bool);
    bool GetMultiplayer() const;
    bool GetHostUSBPs2PspUnlocked();
};

#endif

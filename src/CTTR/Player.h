#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Controller.h"

struct View {};

struct Player {
    void Activate();
    void Deactivate();
    bool IsActive();
    void SetNameOfUser(const char *name);
    const char *GetNameOfUser();
    void SetSlotIndex(uint);
    uint GetSlotIndex();
    void SetViewIndex(uint);
    uint GetViewIndex();
    bool IsLocal();
    void SetVehicleMotifName(const char *name);
    const char *GetVehicleMotifName();
    void SetCharacterMotifName(const char *name);
    const char *GetCharacterMotifName();
    void SetController(Controller *controller);
    Controller *GetController();
    void SetInvertY(bool);
    bool GetInvertY();
    void SetHapticEnable(bool);
    bool GetHapticEnable();
    void fn_8018CBE0(s8);
    void SetDebugController(Controller *controller);
    Controller *GetDebugController();
    void SetView(View *pView);
    View *GetView();

    u8 unk0[0x10];                   // 0x00
    bool mIsActive;                  // 0x10
    const char *mUserName;           // 0x11
    u8 unk15[0x1C];                  // 0x15
    const char *mVehicleMotifName;   // 0x31
    u8 unk35[0x1C];                  // 0x35
    const char *mCharacterMotifName; // 0x51
    u8 unk55[0x30];                  // 0x55
    bool mIsLocal;                   // 0x88
    u8 unk89[3];                     // 0x89
    uint mSlotIndex;                 // 0x8C
    uint mViewIndex;                 // 0x90
    View *mView;                     // 0x94
    u8 unk98[8];                     // 0x98
    Controller *mController;         // 0xA0
    bool mInvertY;                   // 0xA4
    u8 unk[3];                       // 0xA5
    Controller *mDebugController;    // 0xA8
    bool mHapticEnable;              // 0xAC
};

struct PlayerManager {
    Player *GetPlayer(unsigned which);
    unsigned GetNumberOfPlayers();
    unsigned GetNumberOfActivePlayers();
    unsigned GetNumberOfActiveLocalPlayers();
    void ActivateOnlinePlay(const char *ipaddress);
    void DeactivateOnlinePlay();
    const char *GetUniqueName();
    uint GetRangedRandom(unsigned l, unsigned h);
    void SetPlayersReady(bool);
    bool ArePlayersReady();
};

#endif

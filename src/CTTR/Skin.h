#ifndef __SKIN_H__
#define __SKIN_H__

#include "types.h"

struct Skin {
    void SetCharacterName(const char *name);
    void SetSkinName(const char *name);
    void SetLevelName(const char *name);
    void SetUnlockedByDefault();
    void SetUnlockedByDefaultInJapan();
    void MakeCurrent(bool isCurrent);
    void SetDrivingSkinFilename(const char *name);
    void SetOnfootSkinFilename(const char *name);
    void SetSpinSkinFilename(const char *name);
    void SetCheatOnly(bool bCheatOnly);
    void UseJapaneseSkinName();
};

struct SkinManager {
    void LoadCharacterSkins(const char *characterName, const char *levelName, bool isPlatforming,
                            bool isMultiplayer);
    bool IsLoading();
    bool UnloadCharacterSkins(const char *characterName, bool isMultiplayer);
    const char *GetCurrentSkinLoadsetName(const char *characterName, bool isPlatforming,
                                          bool isMultiplayer);
    const char *GetCurrentSpinSkinLoadsetName(const char *characterName, bool isMultiplayer);
};

static SkinManager *gSkinManager;

SkinManager *SkinManager_Get() {
    return gSkinManager;
}

#endif

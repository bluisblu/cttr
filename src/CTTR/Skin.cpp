#include "Skin.h"

void Skin::SetCharacterName(const char *name) {}

void Skin::SetSkinName(const char *name) {}

void Skin::SetLevelName(const char *name) {}

void Skin::SetUnlockedByDefault() {}

void Skin::SetUnlockedByDefaultInJapan() {}

void Skin::MakeCurrent(bool isCurrent) {}

void Skin::SetDrivingSkinFilename(const char *name) {}

void Skin::SetOnfootSkinFilename(const char *name) {}

void Skin::SetSpinSkinFilename(const char *name) {}

void Skin::SetCheatOnly(bool bCheatOnly) {}

void Skin::UseJapaneseSkinName() {}

void SkinManager::LoadCharacterSkins(const char *characterName, const char *levelName,
                                     bool isPlatforming, bool isMultiplayer) {}
bool SkinManager::IsLoading() {}
bool SkinManager::UnloadCharacterSkins(const char *characterName, bool isMultiplayer) {}
const char *SkinManager::GetCurrentSkinLoadsetName(const char *characterName, bool isPlatforming,
                                                   bool isMultiplayer) {}
const char *SkinManager::GetCurrentSpinSkinLoadsetName(const char *characterName,
                                                       bool isMultiplayer) {}

#include "CTTR/LoadSet.h"
#include "pure3d/CompositeDrawable.h"
#include "pure3d/LightGroup.h"
#include "pure3d/Shadow.h"
#include "types.h"

struct TurretMotif {};

struct CharacterDialogNegotiator {};

void CharacterDialogNegotiator_ClearPendingVO(void);

struct CharacterManager {
    void SetLightGroup(pure3d::LightGroup* lightGroup);
    void ClearLightGroup(void);
    unsigned int GetRandomHeadFileNumber(unsigned int maxValue);
};

CharacterManager* gCharacterManager;

CharacterManager* CharacterManager_Get() {
    return gCharacterManager;
}

void CharacterManager::SetLightGroup(pure3d::LightGroup* lightGroup) {}
void CharacterManager::ClearLightGroup(void) {}
unsigned int CharacterManager::GetRandomHeadFileNumber(unsigned int maxValue) {}

struct CharacterMotif {
    void SetCompositeDrawable(pure3d::CompositeDrawable* sourceDrawable);
    void SetAlternateCompositeDrawable(pure3d::CompositeDrawable* sourceDrawable);
    void SetDrivingLoadSet(LoadSet* animSet);
    void SetTurretLoadSet(LoadSet* animset);
    void SetWalkingLoadSet(LoadSet* animset);
    void SetHeadLoadSet(LoadSet* animset);
    void SetCharacterModelPrefix(const char* prefix);
    void SetAnimationPrefix(const char* prefix);
    void SetAnimationPrefixForJapan(const char* prefix);
    void SetAnimationPrefixForNotJapan(const char* prefix);
    const char* GetAnimationPrefix();
    void SetCharacterName(const char* name);
    const char* GetCharacterName();
    void SetCharacterRadius(float fRadius);
    float GetCharacterRadius();
    void SetCharacterRoundness(float fRoundness);
    float GetCharacterRoundness();
    void SetHeadFilename(const char* filename);
    const char* GetHeadFilename();
    bool HasHeadFile();
    void SetHeadName(const char* name, const char* dialogLoadSetName, const char* soundName);
    const char* GetHeadNameByIndex(int index);
    int GetRandomHeadIndex();
    void SetResultsIconName(const char*);
    void SetKillIconName(const char*);
    void SetHudColour(int, int, int);
    void SetDrivingDialogSoundLoadSet(const char* loadSet);
    void SetPlatformDialogSoundLoadSet(const char* loadSet);
    void SetPlatformDialogSoundName(const char* soundName);
    void SetFXSoundLoadSet(const char* loadSet);
    void SetShadow(pure3d::Shadow* pShadow);
    void SetShadowSkin(pure3d::ShadowSkin* pShadowSkin);
    void AddCharacterEffect(const char* effectName, const char* eventName, const char* jointName,
                            bool isAnimated, int effectCount);
    void AddFXLoadSet(LoadSet* fxSet);
    void SetTurretMotif(TurretMotif* motif);
    void EnableLighting(bool enable);
    void HideDuringNIS();
};

void CharacterMotif::SetCompositeDrawable(pure3d::CompositeDrawable* sourceDrawable) {}
void CharacterMotif::SetAlternateCompositeDrawable(pure3d::CompositeDrawable* sourceDrawable) {}
void CharacterMotif::SetDrivingLoadSet(LoadSet* animSet) {}
void CharacterMotif::SetTurretLoadSet(LoadSet* animset) {}
void CharacterMotif::SetWalkingLoadSet(LoadSet* animset) {}
void CharacterMotif::SetHeadLoadSet(LoadSet* animset) {}
void CharacterMotif::SetCharacterModelPrefix(const char* prefix) {}
void CharacterMotif::SetAnimationPrefix(const char* prefix) {}
void CharacterMotif::SetAnimationPrefixForJapan(const char* prefix) {}
void CharacterMotif::SetAnimationPrefixForNotJapan(const char* prefix) {}
const char* CharacterMotif::GetAnimationPrefix() {}
void CharacterMotif::SetCharacterName(const char* name) {}
const char* CharacterMotif::GetCharacterName() {}
void CharacterMotif::SetCharacterRadius(float fRadius) {}
float CharacterMotif::GetCharacterRadius() {}
void CharacterMotif::SetCharacterRoundness(float fRoundness) {}
float CharacterMotif::GetCharacterRoundness() {}
void CharacterMotif::SetHeadFilename(const char* filename) {}
const char* CharacterMotif::GetHeadFilename() {}
bool CharacterMotif::HasHeadFile() {}
void CharacterMotif::SetHeadName(const char* name, const char* dialogLoadSetName,
                                 const char* soundName) {}
const char* CharacterMotif::GetHeadNameByIndex(int index) {}
int CharacterMotif::GetRandomHeadIndex() {}
void CharacterMotif::SetResultsIconName(const char*) {}
void CharacterMotif::SetKillIconName(const char*) {}
void CharacterMotif::SetHudColour(int, int, int) {}
void CharacterMotif::SetDrivingDialogSoundLoadSet(const char* loadSet) {}
void CharacterMotif::SetPlatformDialogSoundLoadSet(const char* loadSet) {}
void CharacterMotif::SetPlatformDialogSoundName(const char* soundName) {}
void CharacterMotif::SetFXSoundLoadSet(const char* loadSet) {}
void CharacterMotif::SetShadow(pure3d::Shadow* pShadow) {}
void CharacterMotif::SetShadowSkin(pure3d::ShadowSkin* pShadowSkin) {}
void CharacterMotif::AddCharacterEffect(const char* effectName, const char* eventName,
                                        const char* jointName, bool isAnimated, int effectCount) {}
void CharacterMotif::AddFXLoadSet(LoadSet* fxSet) {}
void CharacterMotif::SetTurretMotif(TurretMotif* motif) {}
void CharacterMotif::EnableLighting(bool enable) {}
void CharacterMotif::HideDuringNIS() {}

struct Character {
    void SetMotif(CharacterMotif* motif, bool isOnFoot, pure3d::CompositeDrawable* headDrawable,
                  int headIndex);
    void SetDriver();
    void SetUpForPlatforming(bool isAI);
    void ClearAnimations();
    void SetHeldWeaponDefaultForward(bool isForward);
    void SetLandingFX(LoadSet* loadSet,  // lua binding capitalized loadSet as LoadSet
                      const char* Name); // but that conflicts with the type.
};

void Character::SetMotif(CharacterMotif* motif, bool isOnFoot,
                         pure3d::CompositeDrawable* headDrawable, int headIndex) {}
void Character::SetDriver() {}
void Character::SetUpForPlatforming(bool isAI) {}
void Character::ClearAnimations() {}
void Character::SetHeldWeaponDefaultForward(bool isForward) {}
void Character::SetLandingFX(LoadSet* loadSet, const char* Name) {}

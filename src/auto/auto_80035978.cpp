#include "CTTR/Sound.h"
#include "pure3d/StatePropData.h"
#include "types.h"

struct WeaponAndPowerUpMotifBaseClass {};

struct CrystalPowerUpMotif : WeaponAndPowerUpMotifBaseClass {};

struct DamageModifierPowerUpMotif : WeaponAndPowerUpMotifBaseClass {
    void SetDurationInSeconds(f32 seconds);
    void SetRunningOutWarningInSeconds(f32 seconds);
    void SetDamageMultiplier(f32 multiplier);
};

struct HealthPowerUpMotif : WeaponAndPowerUpMotifBaseClass {
    void SetPercentTotalHealthIncrease(f32 percent);
};

struct SpeedBoostPowerUpMotif : WeaponAndPowerUpMotifBaseClass {
    void SetArtAsset(pure3d::StatePropData pName);
    void SetLengthInSeconds(f32 seconds);
    void SetVelocityMultiplier(f32 multiplier);
    void SetMaxSpeedInMps(f32 speed);
    void SetMinSpeedInMps(f32 speed);
    void SetStartSound(Sound* sound);
    void SetStopSound(Sound* sound);
    void SetBoostSound(Sound* sound);
};

void DamageModifierPowerUpMotif::SetDurationInSeconds(f32 seconds) {}
void DamageModifierPowerUpMotif::SetRunningOutWarningInSeconds(f32 seconds) {}
void DamageModifierPowerUpMotif::SetDamageMultiplier(f32 multiplier) {}

void HealthPowerUpMotif::SetPercentTotalHealthIncrease(f32 percent) {}

void SpeedBoostPowerUpMotif::SetArtAsset(pure3d::StatePropData pName) {}
void SpeedBoostPowerUpMotif::SetLengthInSeconds(f32 seconds) {}
void SpeedBoostPowerUpMotif::SetVelocityMultiplier(f32 multiplier) {}
void SpeedBoostPowerUpMotif::SetMaxSpeedInMps(f32 speed) {}
void SpeedBoostPowerUpMotif::SetMinSpeedInMps(f32 speed) {}
void SpeedBoostPowerUpMotif::SetStartSound(Sound* sound) {}
void SpeedBoostPowerUpMotif::SetStopSound(Sound* sound) {}
void SpeedBoostPowerUpMotif::SetBoostSound(Sound* sound) {}

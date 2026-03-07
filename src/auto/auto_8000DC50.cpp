#include "pure3d/PolySkin.h"
#include "pure3d/StatePropData.h"
#include "types.h"

namespace ravenphysics {
struct CollisionObject {};
} // namespace ravenphysics

struct Sound {};

struct ExplosiveChargeMotif {
    void SetDropBoundingBoxFromGeometry(pure3d::PolySkin *pName);
    void SetThrowBoundingBoxFromGeometry(pure3d::PolySkin *pName);
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetThrowMass(f32 mass);
    void SetDropMass(f32 mass);
    f32 GetThrowMass();
    void SetInitialThrowPitchAngle(f32 angle);
    void SetInitialThrowDistance(f32 distance);
    void SetInitialDropPitchAngle(f32 angle);
    void SetInitialDropDistance(f32 distance);
    f32 GetInitialThrowPitchAngle();
    f32 GetInitialThrowDistance();
    f32 GetInitialDropPitchAngle();
    f32 GetInitialDropDistance();
    void SetExplosionStartRadius(f32 radius);
    void SetExplosionEndRadius(f32 radius);
    void SetExplosionMaxDeltaHeight(f32 height);
    void SetExplosionLifetime(uint time);
    f32 GetExplosionStartRadius();
    f32 GetExplosionEndRadius();
    f32 GetExplosionMaxDeltaHeight();
    uint GetExplosionLifetime();
    void SetTrackingMaxAngle(f32 angle);
    void SetTrackingMaxDistance(f32 distance);
    void SetTrackingMoveDistance(f32 distance);
    f32 GetTrackingMaxAngle();
    f32 GetTrackingMaxDistance();
    f32 GetTrackingMoveDistance();
    void SetThrowGroundBounceSpeedMultiplier(f32 multiplier);
    void SetThrowFenceBounceSpeedMultiplier(f32 multiplier);
    f32 GetThrowGroundBounceSpeedMultiplier();
    void SetThrowGroundBounceMaxNumber(uint number);
    uint GetThrowGroundBounceMaxNumber();
    void SetDropGroundBounceSpeedMultiplier(f32 multiplier);
    void SetDropFenceBounceSpeedMultiplier(f32 multiplier);
    void SetDropGroundBounceMaxNumber(uint number);
    uint GetDropGroundBounceMaxNumber();
    f32 GetUnk98();

    u8 unk0[0x90];                         // 0x00
    f32 mThrowMass;                        // 0x90
    f32 mDropMass;                         // 0x94
    f32 unk98;                             // 0x98
    f32 mInitialThrowPitchAngle;           // 0x9C
    f32 mInitialThrowDistance;             // 0xA0
    f32 mInitialDropPitchAngle;            // 0xA4
    f32 mInitialDropDistance;              // 0xA8
    f32 mExplosionStartRadius;             // 0xAC
    f32 mExplosionEndRadius;               // 0xB0
    f32 mExplosionMaxDeltaHeight;          // 0xB4
    uint mExplosionLifetime;               // 0xB8
    f32 mTrackingMaxAngle;                 // 0xBC
    f32 mTrackingMaxDistance;              // 0xC0
    f32 mTrackingMoveDistance;             // 0xC4
    f32 mThrowGroundBounceSpeedMultiplier; // 0xC8
    f32 mThrowFenceBounceSpeedMultiplier;  // 0xCC
    uint mThrowGroundBounceMaxNumber;      // 0xD0
    f32 mDropGroundBounceSpeedMultiplier;  // 0xD4
    f32 mDropFenceBounceSpeedMultiplier;   // 0xD8
    uint mDropGroundBounceMaxNumber;       // 0xDC
};

struct GuidedLandMissileMotif {
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
    void SetTimeToSlowdown(uint milliseconds);
    void SetAttackRadius(f32 radius);
    void SetBumperDistance(f32 distance);
    void SetAttackVelocityAddition(f32 velocity);
    void SetBumperOffset(f32 x, f32 y, f32 z);
    void SetClingTime(uint milliseconds);
    uint GetClingTime();
    void SetControlSensitivity(f32 multiplier);
    void SetClampedOnSound(Sound *sound);

    u8 unk0[0x94];               // 0x00
    f32 mAttackRadius;           // 0x94
    f32 mBumperDistance;         // 0x98
    f32 mAttackVelocityAddition; // 0x9C
    uint mTimeToSlowdown;        // 0xA0
    uint unkA4;                  // 0xA4
    uint unkA8;                  // 0xA8
    uint unkAC;                  // 0xAC
    uint mClingTime;             // 0xB0
    f32 mControlSensitivity;     // 0xB4
};

struct HandLaunchedWeaponMotif {
    void SetForwardDefaultLaunchDirection(bool isTrue);
    void SetDropSpeed(f32 speed);

    u8 unk0[0x70];                       // 0x00
    f32 mDropSpeed;                      // 0x70
    uint unk74;                          // 0x74
    bool mForwardDefaultLaunchDirection; // 0x78
};

struct LargePhysicsWeaponMotif {
    void SetArtAsset(pure3d::StatePropData *pStatePropData);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
};

struct LockOnMissileMotif {
    void SetArtAsset(pure3d::StatePropData *pStatePropData);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
};

struct StickyChargeMotif {
    void SetMoveToVehicleTime(uint milliseconds);
    uint GetMoveToVehicleTime();
    void SetStuckToVehicleMinimumTime(uint milliseconds);
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetOffsetFromVehicle(f32 x, f32 y, f32 z);
    void SetCountdownTime(uint milliseconds);
    void SetArtCountdownTime(uint milliseconds);
    void SetMoveToVehicleBounceHeight(f32 height);
    void SetMoveToTargetVelocity(f32 velocity);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);

    u8 unk0[0x84];                   // 0x00
    uint mMoveToVehicleTime;         // 0x84
    uint mStuckToVehicleMinimumTime; // 0x88
};

struct RibbonEffectGenerator {};

struct TrackingMissileMotif {
    void SetEffectGenerator(RibbonEffectGenerator *pGenerator);
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetHeightOffGround(f32 height);
    void SetMoveCenterMaxVelocityX(f32 velocity);
    void SetMoveCenterMaxVelocityY(f32 velocity);
    void SetMoveCenterRandomInitialVelocityX(f32 min, f32 max);
    void SetMoveCenterRandomInitialVelocityY(f32 min, f32 max);
    void SetMoveCenterRandomAccelerationX(f32 min, f32 max);
    void SetMoveCenterRandomAccelerationY(f32 min, f32 max);
    void SetMoveSporadicallyRandomOffsetX(f32 offset);
    void SetMoveSporadicallyRandomOffsetY(f32 offset);
    void SetMoveSporadicallyRandomOffsetTimeX(f32 min, f32 max);
    void SetMoveSporadicallyRandomOffsetTimeY(f32 min, f32 max);
    void SetMoveTargetVelocityX(f32 velocity);
    void SetMoveTargetRadius(f32 radius);
    void SetAttackTargetRadius(f32 radius);
    void SetAttackTargetVelocityAddition(f32 velocity);
    void SetAttackTargetTime(f32 time);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
    void SetLeaderHPDamage(f32 damage);
};

struct TrackingSwarmMissileMotif {
    void SetEffectGenerator(RibbonEffectGenerator *pGenerator);
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetHeightOffGround(f32 height);
    void SetMoveCenterMaxVelocityX(f32 velocity);
    void SetMoveCenterMaxVelocityY(f32 velocity);
    void SetMoveCenterRandomInitialVelocityX(f32 min, f32 max);
    void SetMoveCenterRandomInitialVelocityY(f32 min, f32 max);
    void SetMoveCenterRandomAccelerationX(f32 min, f32 max);
    void SetMoveCenterRandomAccelerationY(f32 min, f32 max);
    void SetMoveSporadicallyRandomOffsetX(f32 offset);
    void SetMoveSporadicallyRandomOffsetY(f32 offset);
    void SetMoveSporadicallyRandomOffsetTimeX(f32 min, f32 max);
    void SetMoveSporadicallyRandomOffsetTimeY(f32 min, f32 max);
    void SetMoveTargetVelocityX(f32 velocity);
    void SetMoveTargetRadius(f32 radius);
    void SetAttackTargetRadius(f32 radius);
    void SetAttackTargetVelocityAddition(f32 velocity);
    void SetAttackTargetTime(f32 time);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
};

struct TrackingSwarmMotif {
    void SetArtAsset(pure3d::StatePropData *pName);
    void SetSimState(ravenphysics::CollisionObject *pCObject, char *crap);
};

struct WeaponMotif {
    void SetSpeed(f32, f32, f32);
    void SetMinSpeed(f32, f32, f32);
    void SetLifetime(uint milliseconds);
    void SetHPDamage(f32 damage);
    void SetTopSpeedReductionTime(f32 seconds);
    void SetTopSpeedReductionPercentage(f32 speed);
    void SetSpeedReduction(f32 metersPerSec);
    void SetShotSound(Sound *sound);
    void SetTravelSound(Sound *sound);
    void SetHitSound(Sound *sound);
    void SetIdleSound(Sound *sound);
    void SetBounceSound(Sound *sound);
};

void ExplosiveChargeMotif::SetDropBoundingBoxFromGeometry(pure3d::PolySkin *pName) {}

void ExplosiveChargeMotif::SetThrowBoundingBoxFromGeometry(pure3d::PolySkin *pName) {}

void ExplosiveChargeMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void ExplosiveChargeMotif::SetThrowMass(f32 mass) {
    mThrowMass = mass;
}

void ExplosiveChargeMotif::SetDropMass(f32 mass) {
    mDropMass = mass;
}

f32 ExplosiveChargeMotif::GetThrowMass() {
    return mThrowMass;
}

void ExplosiveChargeMotif::SetInitialThrowPitchAngle(f32 angle) {
    mInitialThrowPitchAngle = angle;
}

void ExplosiveChargeMotif::SetInitialThrowDistance(f32 distance) {
    mInitialThrowDistance = distance;
}

void ExplosiveChargeMotif::SetInitialDropPitchAngle(f32 angle) {
    mInitialThrowPitchAngle = angle;
}

void ExplosiveChargeMotif::SetInitialDropDistance(f32 distance) {
    mInitialDropDistance = distance;
}

f32 ExplosiveChargeMotif::GetInitialThrowPitchAngle() {
    return mInitialThrowPitchAngle;
}

f32 ExplosiveChargeMotif::GetInitialThrowDistance() {
    return mInitialThrowDistance;
}

f32 ExplosiveChargeMotif::GetInitialDropPitchAngle() {
    return mInitialDropPitchAngle;
}

f32 ExplosiveChargeMotif::GetInitialDropDistance() {
    return mInitialDropDistance;
}

void ExplosiveChargeMotif::SetExplosionStartRadius(f32 radius) {
    mExplosionStartRadius = radius;
}

void ExplosiveChargeMotif::SetExplosionEndRadius(f32 radius) {
    mExplosionEndRadius = radius;
}

void ExplosiveChargeMotif::SetExplosionMaxDeltaHeight(f32 height) {
    mExplosionMaxDeltaHeight = height;
}

void ExplosiveChargeMotif::SetExplosionLifetime(uint time) {
    mExplosionLifetime = time;
}

f32 ExplosiveChargeMotif::GetExplosionStartRadius() {
    return mExplosionStartRadius;
}

f32 ExplosiveChargeMotif::GetExplosionEndRadius() {
    return mExplosionEndRadius;
}

f32 ExplosiveChargeMotif::GetExplosionMaxDeltaHeight() {
    return mExplosionMaxDeltaHeight;
}

uint ExplosiveChargeMotif::GetExplosionLifetime() {
    return mExplosionLifetime;
}

void ExplosiveChargeMotif::SetTrackingMaxAngle(f32 angle) {
    mTrackingMaxAngle = angle;
}

void ExplosiveChargeMotif::SetTrackingMaxDistance(f32 distance) {
    mTrackingMaxDistance = distance;
}

void ExplosiveChargeMotif::SetTrackingMoveDistance(f32 distance) {
    mTrackingMoveDistance = distance;
}

f32 ExplosiveChargeMotif::GetTrackingMaxAngle() {
    return mTrackingMaxAngle;
}

f32 ExplosiveChargeMotif::GetTrackingMaxDistance() {
    return mTrackingMaxDistance;
}

f32 ExplosiveChargeMotif::GetTrackingMoveDistance() {
    return mTrackingMoveDistance;
}

void ExplosiveChargeMotif::SetThrowGroundBounceSpeedMultiplier(f32 multiplier) {
    mThrowGroundBounceSpeedMultiplier = multiplier;
}

void ExplosiveChargeMotif::SetThrowFenceBounceSpeedMultiplier(f32 multiplier) {
    mThrowFenceBounceSpeedMultiplier = multiplier;
}

f32 ExplosiveChargeMotif::GetThrowGroundBounceSpeedMultiplier() {
    return mThrowGroundBounceSpeedMultiplier;
}

void ExplosiveChargeMotif::SetThrowGroundBounceMaxNumber(uint number) {
    mThrowGroundBounceMaxNumber = number;
}

uint ExplosiveChargeMotif::GetThrowGroundBounceMaxNumber() {
    return mThrowGroundBounceMaxNumber;
}

void ExplosiveChargeMotif::SetDropGroundBounceSpeedMultiplier(f32 multiplier) {
    mDropGroundBounceSpeedMultiplier = multiplier;
}

void ExplosiveChargeMotif::SetDropFenceBounceSpeedMultiplier(f32 multiplier) {
    mDropFenceBounceSpeedMultiplier = multiplier;
}

void ExplosiveChargeMotif::SetDropGroundBounceMaxNumber(uint number) {
    mDropGroundBounceMaxNumber = number;
}

uint ExplosiveChargeMotif::GetDropGroundBounceMaxNumber() {
    return mDropGroundBounceMaxNumber;
}

f32 ExplosiveChargeMotif::GetUnk98() {
    return unk98;
}

void GuidedLandMissileMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void GuidedLandMissileMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void GuidedLandMissileMotif::SetTimeToSlowdown(uint milliseconds) {
    mTimeToSlowdown = milliseconds;
}

void GuidedLandMissileMotif::SetAttackRadius(float radius) {
    mAttackRadius = radius;
}

void GuidedLandMissileMotif::SetBumperDistance(f32 distance) {
    mBumperDistance = distance;
}

void GuidedLandMissileMotif::SetAttackVelocityAddition(f32 velocity) {
    mAttackVelocityAddition = velocity;
}

void GuidedLandMissileMotif::SetBumperOffset(f32 x, f32 y, f32 z) {}

void GuidedLandMissileMotif::SetClingTime(uint milliseconds) {
    mClingTime = milliseconds;
}

uint GuidedLandMissileMotif::GetClingTime() {
    return mClingTime;
}

void GuidedLandMissileMotif::SetControlSensitivity(f32 multiplier) {
    mControlSensitivity = multiplier;
}

void GuidedLandMissileMotif::SetClampedOnSound(Sound *sound) {}

void HandLaunchedWeaponMotif::SetForwardDefaultLaunchDirection(bool isTrue) {
    mForwardDefaultLaunchDirection = isTrue;
}

void HandLaunchedWeaponMotif::SetDropSpeed(f32 speed) {
    mDropSpeed = speed;
}

void LargePhysicsWeaponMotif::SetArtAsset(pure3d::StatePropData *pStatePropData) {}

void LargePhysicsWeaponMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void LockOnMissileMotif::SetArtAsset(pure3d::StatePropData *pStatePropData) {}

void LockOnMissileMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void StickyChargeMotif::SetMoveToVehicleTime(uint milliseconds) {
    mMoveToVehicleTime = milliseconds;
}

uint StickyChargeMotif::GetMoveToVehicleTime() {
    return mMoveToVehicleTime;
}

void StickyChargeMotif::SetStuckToVehicleMinimumTime(uint milliseconds) {
    mStuckToVehicleMinimumTime = milliseconds;
}

void StickyChargeMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void StickyChargeMotif::SetOffsetFromVehicle(f32 x, f32 y, f32 z) {}

void StickyChargeMotif::SetCountdownTime(uint milliseconds) {}

void StickyChargeMotif::SetArtCountdownTime(uint milliseconds) {}

void StickyChargeMotif::SetMoveToVehicleBounceHeight(f32 height) {}

void StickyChargeMotif::SetMoveToTargetVelocity(f32 velocity) {}

void StickyChargeMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void TrackingMissileMotif::SetEffectGenerator(RibbonEffectGenerator *pGenerator) {}

void TrackingMissileMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void TrackingMissileMotif::SetHeightOffGround(f32 height) {}

void TrackingMissileMotif::SetMoveCenterMaxVelocityX(f32 velocity) {}

void TrackingMissileMotif::SetMoveCenterMaxVelocityY(f32 velocity) {}

void TrackingMissileMotif::SetMoveCenterRandomInitialVelocityX(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveCenterRandomInitialVelocityY(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveCenterRandomAccelerationX(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveCenterRandomAccelerationY(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveSporadicallyRandomOffsetX(f32 offset) {}

void TrackingMissileMotif::SetMoveSporadicallyRandomOffsetY(f32 offset) {}

void TrackingMissileMotif::SetMoveSporadicallyRandomOffsetTimeX(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveSporadicallyRandomOffsetTimeY(f32 min, f32 max) {}

void TrackingMissileMotif::SetMoveTargetVelocityX(f32 velocity) {}

void TrackingMissileMotif::SetMoveTargetRadius(f32 radius) {}

void TrackingMissileMotif::SetAttackTargetRadius(f32 radius) {}

void TrackingMissileMotif::SetAttackTargetVelocityAddition(f32 velocity) {}

void TrackingMissileMotif::SetAttackTargetTime(f32 time) {}

void TrackingMissileMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void TrackingMissileMotif::SetLeaderHPDamage(f32 damage) {}

void TrackingSwarmMissileMotif::SetEffectGenerator(RibbonEffectGenerator *pGenerator) {}

void TrackingSwarmMissileMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void TrackingSwarmMissileMotif::SetHeightOffGround(f32 height) {}

void TrackingSwarmMissileMotif::SetMoveCenterMaxVelocityX(f32 velocity) {}

void TrackingSwarmMissileMotif::SetMoveCenterMaxVelocityY(f32 velocity) {}

void TrackingSwarmMissileMotif::SetMoveCenterRandomInitialVelocityX(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveCenterRandomInitialVelocityY(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveCenterRandomAccelerationX(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveCenterRandomAccelerationY(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveSporadicallyRandomOffsetX(f32 offset) {}

void TrackingSwarmMissileMotif::SetMoveSporadicallyRandomOffsetY(f32 offset) {}

void TrackingSwarmMissileMotif::SetMoveSporadicallyRandomOffsetTimeX(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveSporadicallyRandomOffsetTimeY(f32 min, f32 max) {}

void TrackingSwarmMissileMotif::SetMoveTargetVelocityX(f32 velocity) {}

void TrackingSwarmMissileMotif::SetMoveTargetRadius(f32 radius) {}

void TrackingSwarmMissileMotif::SetAttackTargetRadius(f32 radius) {}

void TrackingSwarmMissileMotif::SetAttackTargetVelocityAddition(f32 velocity) {}

void TrackingSwarmMissileMotif::SetAttackTargetTime(f32 time) {}

void TrackingSwarmMissileMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void TrackingSwarmMotif::SetArtAsset(pure3d::StatePropData *pName) {}

void TrackingSwarmMotif::SetSimState(ravenphysics::CollisionObject *pCObject, char *crap) {}

void WeaponMotif::SetSpeed(f32, f32, f32) {}

void WeaponMotif::SetMinSpeed(f32, f32, f32) {}

void WeaponMotif::SetLifetime(uint milliseconds) {}

void WeaponMotif::SetHPDamage(f32 damage) {}

void WeaponMotif::SetTopSpeedReductionTime(f32 seconds) {}

void WeaponMotif::SetTopSpeedReductionPercentage(f32 speed) {}

void WeaponMotif::SetSpeedReduction(f32 metersPerSec) {}

void WeaponMotif::SetShotSound(Sound *sound) {}

void WeaponMotif::SetTravelSound(Sound *sound) {}

void WeaponMotif::SetHitSound(Sound *sound) {}

void WeaponMotif::SetIdleSound(Sound *sound) {}

void WeaponMotif::SetBounceSound(Sound *sound) {}

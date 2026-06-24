#include "CTTR/Wheel.h"

Wheel::Wheel() {}
Wheel::~Wheel() {}

BrakeMotif* Wheel::GetBrakeMotif() {
    return mBrakeMotif;
}
DrivelineComponent* Wheel::GetInput() {
    return mInput;
}
SteeringWheel* Wheel::GetSteeringWheel() {
    return mSteeringWheel;
}
SuspensionMotif* Wheel::GetSuspensionMotif() {
    return mSuspensionMotif;
}
pure3d::Locator* Wheel::GetSuspensionPositionInChassisSpace() {}
WheelMotif* Wheel::GetWheelMotif() {
    return mWheelMotif;
}

void Wheel::SetBrakeMotif(BrakeMotif* motif) {
    mBrakeMotif = motif;
}
void Wheel::SetInput(DrivelineComponent* input) {
    mInput = input;
}
void Wheel::SetSteeringWheel(SteeringWheel* steeringWheel) {
    mSteeringWheel = steeringWheel;
}
void Wheel::SetSuspensionMotif(SuspensionMotif* motif) {
    mSuspensionMotif = motif;
}
void Wheel::SetSuspensionPositionInChassisSpace(pure3d::Locator* locator) {}
void Wheel::SetWheelMotif(WheelMotif* motif) {
    mWheelMotif = motif;
}

WheelMotif::WheelMotif() {
    unkC = 0.4f;
    mBrakeBalance = 0.0f;
    unk14 = 0.0f;
    mSlipAngleInDegrees = 45.0f;
    mSlipTransition = 0.5f;
    unk20 = 0.0f;
    unk24 = 0.0f;
    unk28 = 0.0f;
    mDriving = 0;
    mPowerslideEffectVisibleOnHiddenWheel = 0;
    mPhysical = 1;
    mSteering = 0;
    mSteeringVisual = 1;
    mVisible = 1;
    mVisualInverseSteering = 0;
    mLateralGripInSlip = 0.0f;
    mLateralGripNoSlip = 0.0f;
    mLongtitudinalGrip = 0.0f;
    mMass = 22.0f;
    unk44 = 0.4f;
    unk48 = 0.0f;
    fn_801796F4();
}
WheelMotif::~WheelMotif() {}

f32 WheelMotif::GetUnkC() {
    return unkC;
}
f32 WheelMotif::GetBrakeBalance() /* [0 - 1] */ {
    return mBrakeBalance;
}
bool WheelMotif::GetDriving() {
    return mDriving;
}
f32 WheelMotif::GetLateralGripInSlip() /* [0 - 20] */ {
    return mLateralGripInSlip;
}
f32 WheelMotif::GetLateralGripNoSlip() /* [0 - 20] */ {
    return mLateralGripNoSlip;
}
f32 WheelMotif::GetLongtitudinalGrip() /* [0 - 20] */ {
    return mLongtitudinalGrip;
}
f32 WheelMotif::GetMass() /* [0 - 10000] */ {
    return mMass;
}
f32 WheelMotif::GetUnk44() {
    return unk44;
}
f32 WheelMotif::GetUnk48() {
    return unk48;
}
bool WheelMotif::GetPowerslideEffectVisibleOnHiddenWheel() {
    return mPowerslideEffectVisibleOnHiddenWheel;
}
bool WheelMotif::GetPhysical() {
    return mPhysical;
}
f32 WheelMotif::GetSlipAngleInDegrees() /* [0 - 180] */ {
    return mSlipAngleInDegrees;
}
f32 WheelMotif::GetSlipTransition() /* [0 - 1] */ {}
f32 WheelMotif::GetUnk20() {
    return unk20;
}
f32 WheelMotif::GetUnk24() {
    return unk24;
}
bool WheelMotif::GetSteering() {
    return mSteering;
}
bool WheelMotif::GetSteeringVisual() {
    return mSteeringVisual;
}
bool WheelMotif::GetVisible() {
    return mVisible;
}
bool WheelMotif::GetVisualInverseSteering() {
    return mVisualInverseSteering;
}

void WheelMotif::SetUnkC(f32 unk) {
    unkC = unk;
}
void WheelMotif::SetBrakeBalance(f32 balance /* [0 - 1] */) {
    mBrakeBalance = balance;
}
void WheelMotif::SetUnk14(f32 unk) {
    unk14 = unk;
}
void WheelMotif::SetDriving(bool driving) {
    mDriving = driving;
}
void WheelMotif::SetLateralGripInSlip(f32 lateralGrip /* [0 - 20] */) {
    mLateralGripInSlip = lateralGrip;
}
void WheelMotif::SetLateralGripNoSlip(f32 lateralGrip /* [0 - 20] */) {
    mLateralGripNoSlip = lateralGrip;
}
void WheelMotif::SetLongtitudinalGrip(f32 longtitudinalGrip /* [0 - 20] */) {
    mLongtitudinalGrip = longtitudinalGrip;
}
void WheelMotif::SetMass(f32 mass /* [0 - 10000] */) {
    mMass = mass;
}
void WheelMotif::SetUnk48(f32 unk) {
    unk48 = unk;
}
void WheelMotif::SetPowerslideEffectVisibleOnHiddenWheel(bool v) {
    mPowerslideEffectVisibleOnHiddenWheel = v;
}
void WheelMotif::SetPhysical(bool isPhysical) {
    mPhysical = isPhysical;
}
void WheelMotif::SetSlipAngleInDegrees(f32 slipAngle /* [0 - 180] */) {
    mSlipAngleInDegrees = slipAngle;
}
void WheelMotif::SetSlipTransition(f32 transition /* [0 - 1] */) {}
void WheelMotif::SetSteering(bool steering) {
    mSteering = steering;
}
void WheelMotif::SetSteeringVisual(bool v) {
    mSteeringVisual = v;
}
void WheelMotif::SetVisible(bool visible) {
    mVisible = visible;
}
void WheelMotif::SetVisualInverseSteering(bool steering) {
    mVisualInverseSteering = steering;
}

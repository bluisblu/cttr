#ifndef __WHEEL_H__
#define __WHEEL_H__

#include "CTTR/BrakeMotif.h"
#include "CTTR/DrivelineComponent.h"
#include "pure3d/Locator.h"
#include "types.h"

struct SteeringWheel {};

struct SuspensionMotif {};

// size: 0x4c
struct WheelMotif : DrivelineComponentMotif {
    WheelMotif();
    virtual ~WheelMotif();

    void fn_801796F4();
    f32 GetUnkC();
    f32 GetBrakeBalance() /* [0 - 1] */;
    bool GetDriving();
    f32 GetLateralGripInSlip() /* [0 - 20] */;
    f32 GetLateralGripNoSlip() /* [0 - 20] */;
    f32 GetLongtitudinalGrip() /* [0 - 20] */;
    f32 GetMass() /* [0 - 10000] */;
    f32 GetUnk44();
    f32 GetUnk48();
    bool GetPowerslideEffectVisibleOnHiddenWheel();
    bool GetPhysical();
    f32 GetSlipAngleInDegrees() /* [0 - 180] */;
    f32 GetSlipTransition() /* [0 - 1] */;
    f32 GetUnk20();
    f32 GetUnk24();
    bool GetSteering();
    bool GetSteeringVisual();
    bool GetVisible();
    bool GetVisualInverseSteering();

    void SetUnkC(f32 unk);
    void SetBrakeBalance(f32 balance /* [0 - 1] */);
    void SetUnk14(f32 unk);
    void SetDriving(bool driving);
    void SetLateralGripInSlip(f32 lateralGrip /* [0 - 20] */);
    void SetLateralGripNoSlip(f32 lateralGrip /* [0 - 20] */);
    void SetLongtitudinalGrip(f32 longtitudinalGrip /* [0 - 20] */);
    void SetMass(f32 mass /* [0 - 10000] */);
    void SetUnk48(f32 unk);
    void SetPowerslideEffectVisibleOnHiddenWheel(bool v);
    void SetPhysical(bool isPhysical);
    void SetSlipAngleInDegrees(f32 slipAngle /* [0 - 180] */);
    void SetSlipTransition(f32 transition /* [0 - 1] */);
    void SetSteering(bool steering);
    void SetSteeringVisual(bool v);
    void SetVisible(bool visible);
    void SetVisualInverseSteering(bool steering);

    u8 unk4[0x8];                               // 0x4
    f32 unkC;                                   // 0xC
    f32 mBrakeBalance;                          // 0x10
    f32 unk14;                                  // 0x14
    f32 mSlipAngleInDegrees;                    // 0x18
    f32 mSlipTransition;                        // 0x1C
    f32 unk20;                                  // 0x20
    f32 unk24;                                  // 0x24
    f32 unk28;                                  // 0x28
    bool mDriving;                              // 0x2C
    bool mPowerslideEffectVisibleOnHiddenWheel; // 0x2D
    bool mPhysical;                             // 0x2E
    bool mSteering;                             // 0x2F
    bool mSteeringVisual;                       // 0x30
    bool mVisible;                              // 0x31
    bool mVisualInverseSteering;                // 0x32
    bool unk33;                                 // 0x33
    f32 mLateralGripInSlip;                     // 0x34
    f32 mLateralGripNoSlip;                     // 0x38
    f32 mLongtitudinalGrip;                     // 0x3C
    f32 mMass;                                  // 0x40
    f32 unk44;                                  // 0x44
    f32 unk48;                                  // 0x48
};

struct Wheel : DrivelineComponent {
    Wheel();
    virtual ~Wheel();

    BrakeMotif* GetBrakeMotif();
    DrivelineComponent* GetInput();
    SteeringWheel* GetSteeringWheel();
    SuspensionMotif* GetSuspensionMotif();
    pure3d::Locator* GetSuspensionPositionInChassisSpace();
    WheelMotif* GetWheelMotif();

    void SetBrakeMotif(BrakeMotif* motif);
    void SetInput(DrivelineComponent* input);
    void SetSteeringWheel(SteeringWheel* steeringWheel);
    void SetSuspensionMotif(SuspensionMotif* motif);
    void SetSuspensionPositionInChassisSpace(pure3d::Locator* locator);
    void SetWheelMotif(WheelMotif* motif);

    f32 unk4;                          // 0x4
    f32 unk8;                          // 0x8
    f32 unkC;                          // 0xC
    f32 unk10;                         // 0x10
    u8 unk14[36];                      // 0x14
    f32 unk38;                         // 0x38
    f32 unk3C;                         // 0x3C
    f32 unk40;                         // 0x40
    u8 unk44[4];                       // 0x44
    f32 unk48;                         // 0x48
    u32 unk4C;                         // 0x4C
    u32 unk50;                         // 0x50
    u32 unk54;                         // 0x54
    u8 unk58[116];                     // 0x58
    u32 unkCC;                         // 0xCC
    u32 unkD0;                         // 0xD0
    BrakeMotif* mBrakeMotif;           // 0xD4
    WheelMotif* mWheelMotif;           // 0xD8
    SuspensionMotif* mSuspensionMotif; // 0xDC
    DrivelineComponent* mInput;        // 0xE0
    SteeringWheel* mSteeringWheel;     // 0xE4
    f32 unkE8;                         // 0xE8
    u32 unkEC;                         // 0xEC
    u8 unkF0[36];                      // 0xF0
    f32 unk114;                        // 0x114
    f32 unk118;                        // 0x118
    f32 unk11C;                        // 0x11C
    f32 unk120;                        // 0x120
    u8 unk124[16];                     // 0x124
};

#endif

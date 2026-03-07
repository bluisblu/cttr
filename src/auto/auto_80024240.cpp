#include "types.h"

enum SplineMovementEnum {
    SPLINEMOVEMENT_NONE,
    SPLINEMOVEMENT_PITCH,
    SPLINEMOVEMENT_ROLL,
    SPLINEMOVEMENT_YAW,
};

struct Location {
    void SetPosition(f32 x, f32 y, f32 z);
    void SetQuaternion(f32 w, f32 x, f32 y, f32 z);
};

void Location::SetPosition(f32 x, f32 y, f32 z) {}

void Location::SetQuaternion(f32 w, f32 x, f32 y, f32 z) {}

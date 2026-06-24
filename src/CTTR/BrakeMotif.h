#ifndef __BRAKEMOTIF_H__
#define __BRAKEMOTIF_H__

#include "CTTR/DrivelineComponent.h"
#include "types.h"

// size: 0x10
struct BrakeMotif : DrivelineComponentMotif {
    BrakeMotif();
    virtual ~BrakeMotif();
    void SetBrakeScale(float brakeScale /* [0 - 20000] */);
    u32 unk4;
    u32 unk8;
    f32 mBrakeScale;
};

#endif

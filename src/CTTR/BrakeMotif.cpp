#include "CTTR/BrakeMotif.h"

BrakeMotif::BrakeMotif() {
    mBrakeScale = 0.0f;
}
BrakeMotif::~BrakeMotif() {}

void BrakeMotif::SetBrakeScale(f32 brakeScale /* [0 - 20000] */) {
    mBrakeScale = brakeScale;
}

#include "types.h"

struct DifferentialMotif {};

struct DrivelineComponent {};

struct Differential {
    void SetInput(DrivelineComponent *input);
    void SetMotif(DifferentialMotif *motif);
    void SetOutput(int index, DrivelineComponent *output);

    u8 unk0[0xc];
    DrivelineComponent *mInput; // 0x0C
    uint unk10;                 // 0x10
    uint unk14;                 // 0x14
    DifferentialMotif *mMotif;  // 0x18
};

void Differential::SetInput(DrivelineComponent *input) {
    mInput = input;
}

void Differential::SetMotif(DifferentialMotif *motif) {
    mMotif = motif;
}

void Differential::SetOutput(int index, DrivelineComponent *output) {}

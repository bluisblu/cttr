#include "CTTR/DrivelineComponent.h"
#include "types.h"

struct DifferentialMotif : DrivelineComponentMotif {
    DifferentialMotif() {}
    ~DifferentialMotif() {}
};

struct Differential : DrivelineComponent {
    Differential() {}
    ~Differential() {}

    void SetInput(DrivelineComponent* input);
    void SetMotif(DifferentialMotif* motif);
    void SetOutput(int index, DrivelineComponent* output);

    u8 unk4[0x8];
    DrivelineComponent* mInput;  // 0x0C
    DrivelineComponent* mOutput; // 0x10
    uint unk14;                  // 0x14
    DifferentialMotif* mMotif;   // 0x18
};

void Differential::SetInput(DrivelineComponent* input) {
    mInput = input;
}

void Differential::SetMotif(DifferentialMotif* motif) {
    mMotif = motif;
}

void Differential::SetOutput(int index, DrivelineComponent* output) {
    (&mOutput)[index] = output;
}

void __deadstripped() {
    Differential* diff = new Differential();
    delete diff;
    DifferentialMotif* diffMotif = new DifferentialMotif();
    delete diffMotif;
}

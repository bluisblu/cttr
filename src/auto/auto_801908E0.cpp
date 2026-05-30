#include "CTTR/GameObject.h"

struct LoadSetStateChangeCallback {};

struct SkinMemorySlot : LoadSetStateChangeCallback, GameObject {
    ~SkinMemorySlot() {}
};

void StatsManager_Capture(const char* pMode, const char* pLevel, const char* pFilename) {}

void __deadstripped_801908E0() {
    SkinMemorySlot* pSlot = new SkinMemorySlot();
    delete pSlot;
}

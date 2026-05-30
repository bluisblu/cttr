#include "Mode.h"

// In a different TU at 8003E7A4, might need to define in header
ModeControlState ModeControl::GetState() {}

void ModeControl::SetState(ModeControlState state) {}

void ModeControl::SetParadeLapCameras(const CameraArray* array) {}

void ModeControl::StopParadeLapCameras() {}

// 8000BDF0
ModeType ModeManager::GetActiveMode() {}

void ModeManager::SetActiveMode(ModeType mode) {}

// 8000BDE8
ModeControl* ModeManager::GetActiveControl() {}

void ModeManager::SetActiveControl(ModeControl* mode) {}

bool ModeManager::IsPlaying() {}

void ModeManager::SetPlaying(bool playing) {}

void ModeManager::RegisterOnlineData() {}

void ModeManager::UnregisterOnlineData() {}

// 8005A218
Skill ModeManager::GetSkill() {}

void ModeManager::SetSkill(Skill skill) {}

void ModeManager::SetTier(int) {}

int ModeManager::GetTier() const {}

void ModeManager::SetMultiplayer(bool) {}

bool ModeManager::GetMultiplayer() const {}

bool ModeManager::GetHostUSBPs2PspUnlocked() {}

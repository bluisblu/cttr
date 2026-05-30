#include "Player.h"

void Player::Activate() {
    mIsActive = true;
    mIsLocal = true;
}

void Player::Deactivate() {
    mIsActive = false;
    mIsLocal = false;
    // this->field_0x71 = 0;
    // this->field_0x72 = 0;
    // *(undefined4 *)&this->field_0x84 = 0xffffffff;
    // if (*(int *)&this->field_0x80 != -1) {
    //   FUN_800cd8e0();
    //   *(undefined4 *)&this->field_0x80 = 0xffffffff;
    // }
}

bool Player::IsActive() {
    if (mIsLocal != false) {
        return true;
    }
    return mIsActive;
}

void Player::SetNameOfUser(const char* name) {
    mUserName = name;
}

const char* Player::GetNameOfUser() {
    return mUserName;
}

void Player::SetSlotIndex(uint index) {
    mSlotIndex = index;
}

uint Player::GetSlotIndex() {
    return mSlotIndex;
}

void Player::SetViewIndex(uint index) {
    mViewIndex = index;
}

uint Player::GetViewIndex() {
    return mViewIndex;
}

bool Player::IsLocal() {
    return mIsLocal;
}

void Player::SetVehicleMotifName(const char* name) {
    mVehicleMotifName = name;
}

const char* Player::GetVehicleMotifName() {
    return mVehicleMotifName;
}

void Player::SetCharacterMotifName(const char* name) {
    mCharacterMotifName = name;
}

const char* Player::GetCharacterMotifName() {
    return mCharacterMotifName;
}

void Player::SetController(Controller* controller) {}

Controller* Player::GetController() {
    return mController;
}

void Player::SetInvertY(bool enable) {
    mInvertY = enable;
}

bool Player::GetInvertY() {
    return mInvertY;
}

void Player::SetHapticEnable(bool enable) {
    mHapticEnable = enable;
}

bool Player::GetHapticEnable() {
    return mHapticEnable;
}

void Player::fn_8018CBE0(s8 param_1) {
    if (mController != NULL) {
        if (param_1 == 0 && mHapticEnable != false) {
        }
    }
}

void Player::SetDebugController(Controller* controller) {}

Controller* Player::GetDebugController() {
    return mDebugController;
}

void Player::SetView(View* pView) {
    mView = pView;
}

View* Player::GetView() {
    return mView;
}

Player* PlayerManager::GetPlayer(unsigned which) {}
unsigned PlayerManager::GetNumberOfPlayers() {}
unsigned PlayerManager::GetNumberOfActivePlayers() {}
unsigned PlayerManager::GetNumberOfActiveLocalPlayers() {}
void PlayerManager::ActivateOnlinePlay(const char* ipaddress) {}
void PlayerManager::DeactivateOnlinePlay() {}
const char* PlayerManager::GetUniqueName() {}
uint PlayerManager::GetRangedRandom(unsigned l, unsigned h) {}
void PlayerManager::SetPlayersReady(bool) {}
bool PlayerManager::ArePlayersReady() {}

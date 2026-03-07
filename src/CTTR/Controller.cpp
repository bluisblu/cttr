#include "Controller.h"

// .sbss
u32 lbl_804AD580;
ControllerManager *gControllerManager;
u32 lbl_804AD588;
u8 lbl_804AD58C;
u32 lbl_804AD590;
u8 lbl_804AD594;
u32 lbl_804AD598;
u8 lbl_804AD59C;
u32 lbl_804AD5A0;
u8 lbl_804AD5A4;

void Controller::AddToBucket(const char *) {}

void Controller::SetInputName(const char *, const char *, const char *) {}

void Controller::SetOutputName(const char *, const char *, const char *) {}

bool Controller::IsInputPressed(const char *) {
    return true;
}

void Controller::SetMap(ControllerMap *map, unsigned int locationIndex) {}

void Controller::DepressInput(const char *) {}

void Controller::ReleaseInput(const char *) {}

void Controller::fn_80006614() {}

void Controller::Activate(bool x) {}

static ControllerManager *ControllerManager_Get() {
    return NULL;
}

static void ControllerManager_SetMasterController(Controller *pController) {}

static void ControllerManager_AddMasterControllerInput(const char *uberInputName) {}

bool ControllerManager::AnyInputFromActiveController() const {
    return true;
}

void ControllerManager::ReturnToGame() {}

void ControllerMap::SetInputName(const char *logical, const char *physical) {}

void ControllerMap::SetOutputName(const char *logical, const char *physical) {}

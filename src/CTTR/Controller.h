#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "types.h"

struct ControllerMap {
    ControllerMap();
    void SetInputName(const char* logical, const char* physical);
    void SetOutputName(const char* logical, const char* physical);
};

struct ControllerManager {
    ControllerManager();
    bool AnyInputFromActiveController() const;
    void ReturnToGame();
};

struct Controller {
    Controller();
    void AddToBucket(const char*);
    void SetInputName(const char*, const char*, const char*);
    void SetOutputName(const char*, const char*, const char*);
    bool IsInputPressed(const char*);
    void SetMap(ControllerMap* map, unsigned int locationIndex);
    void DepressInput(const char*);
    void ReleaseInput(const char*);
    void fn_80006614();
    void Activate(bool x);
};

#endif

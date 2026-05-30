#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "core/IRefCount.h"

struct GameObject : core::IRefCount {
    GameObject() {}
    virtual ~GameObject() {}
};

#endif

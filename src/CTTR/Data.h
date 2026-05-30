#ifndef __DATA_H__
#define __DATA_H__

#include "core/IRefCount.h"
#include "types.h"

struct Data {
    void SetScriptAlias(const char*);
};
struct DataBoolean {
    void SetValue(bool value);
    bool GetValue();
};
struct DataNumber {
    void SetValue(f32 value);
    f32 GetValue();
};
struct DataObject {
    void SetValue(core::IRefCount value);
    core::IRefCount GetValue();
};
struct DataString {
    void SetValue(const char* value);
    const char* GetValue();
};

#endif

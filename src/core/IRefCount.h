#ifndef __CORE_IREFCOUNT_H__
#define __CORE_IREFCOUNT_H__

namespace core {
struct IRefCount {
    virtual ~IRefCount() {}
};
} // namespace core

#endif

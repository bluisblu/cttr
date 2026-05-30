#include "CTTR/GameObject.h"
struct Mind : GameObject {
    Mind() {}
    virtual ~Mind() {}
};

void __deadstripped() {
    Mind* m = new Mind();
    delete m;
}

#include "types.h"

int HashString_802430E8(const char* str, int ret) {
    if (str != NULL) {
        int c;
        while ((signed char)(c = *str) != 0) {
            c = (signed char)c;
            int temp = (ret << 5) - ret;
            if (c < 0x61) {
                c += 0x20;
            }
            ret = temp + c;
            str++;
        }
        return ret;
    }
    return ret;
}

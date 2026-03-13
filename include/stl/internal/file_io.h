#ifndef MSL_FILE_IO_H
#define MSL_FILE_IO_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _MSL_COMMON_ANSI_FILES_H
typedef struct _FILE {
    u8 dummy;
} FILE;

int fclose(FILE*);
int fflush(FILE*);
#endif

#ifdef __cplusplus
}
#endif
#endif

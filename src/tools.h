#include <stdint.h>

#ifndef TOOLS_H
#define TOOLS_H

/*
 * Read file and return a buffer with its contents.
 *
 * Changed signature from the original one to be able to return also the size
 * of the readed file.
 */
uint8_t* read_file(const char* filename, size_t* len);

#endif

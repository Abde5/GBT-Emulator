#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

uint8_t* read_file(const char* filename, size_t* len) {
	FILE* file;
	uint8_t* buffer;
	
	// Open the file as read only bytes (uint8_t)
	file = fopen(filename, "rb");

	if (file != NULL) {
		// Get the len of the file
		fseek(file, 0, SEEK_END);
		*len = ftell(file);
		rewind(file);

		// Allocate a buffer with the size of the file and store its contents
		buffer = (uint8_t*)malloc(*len * sizeof(uint8_t));
		fread(buffer, *len, 1, file);
		fclose(file);

		return buffer;
	} else {
		return NULL;
	}
}

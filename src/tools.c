#include <stdio.h>
#include <stdlib.h>
#include "tools.h"


unsigned char* read_file(char* filename){
    FILE *fileptr;
    unsigned char *buffer;
    long filelen;

    fileptr = fopen(filename, "rb");
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);

    buffer = (unsigned char *)malloc(filelen * sizeof(unsigned char));
    fread(buffer, filelen, 1, fileptr);
    fclose(fileptr);

    return buffer;
}

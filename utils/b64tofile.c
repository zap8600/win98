// Convert base64 data to a file
// Intended for me to be able to transfer files to a Windows 98 machine by hand if all else fails

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s [source file containing base64] [output file]\n", argv[0]);
        return 1;
    }

    FILE* base64_file = fopen(argv[1], "rb");
    if(!base64_file) {
        perror(argv[1]);
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if(!output_file) {
        perror(argv[2]);
        fclose(base64_file);
        return 1;
    }

    fseek(base64_file, 0, SEEK_END);
    ssize_t base64_size = ftell(base64_file);
    fseek(base64_file, 0, SEEK_SET);

    fclose(base64_file);
    fclose(output_file);
    return 0;
}

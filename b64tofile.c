// Convert base64 data to a file
// Intended for me to be able to transfer files to a Windows 98 machine by hand if all else fails

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

const char* base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(int argc, char** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s [base64 data file] [output file]\n", argv[0]);
        return 1;
    }

    char* base64_file_name = argv[1];
    char* output_file_name = argv[2];

    FILE* base64_file = fopen(base64_file_name, "rb");
    if(!base64_file) {
        perror(base64_file_name);
        return 1;
    }

    FILE* output_file = fopen(output_file_name, "wb");
    if(!output_file) {
        perror(output_file_name);
        fclose(base64_file);
        return 1;
    }

    fseek(base64_file, 0, SEEK_END);
    long base64_size = ftell(base64_file);
    fseek(base64_file, -2, SEEK_CUR);

    if((base64_size < 4) || (base64_size % 4)) {
        fprintf(stderr, "Invalid ");
    }
}

#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

int compress(char string[], const char *path) {
    char current_value = string[0];
    int length_num = 0;
    int length = stringlen(string);

    FILE *write = fopen(path, "w");

    if (!write) return -1;

    for (int i = 0; i <= length; i++) {
        if (string[i] == current_value) {
            length_num++;
        } else if (string[i] != current_value) {
            fprintf(write, "%c%d", string[i - 1], length_num);
            length_num = 1;
            current_value = string[i];
        } else if (string[i] != string[i + 1]) {
            fprintf(write, "%c", string[i]);
            length_num = 1;
        } else if (string[i] == '\0' || string[i] == '\n') {
            fclose(write);
            break;
        }
    }
    return 0;
}

int decompress(char string[], const char *path) {


    FILE *write = fopen(path, "w");

    if (!write) return -1;

    int length = stringlen(string);
    int num_per_char;
    for (int i = 0; i <= length; i += 2) {
        if (string[i] != '\0') {
            num_per_char = string[i + 1] - '0';
            for (int j = 0; j < num_per_char; j++) {
                fprintf(write, "%c", string[i]);
            }
        } else {
            fclose(write);
            break;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char string[200000];

    FILE *read = fopen(argv[2], "r");
    if (!read) return -1;

    fscanf(read, "%s", string);

    if (stringcmp(argv[1], "compress") == 0) {
        compress(string, argv[2]);
    }
    else if (stringcmp(argv[1], "decompress") == 0) {
        decompress(string, argv[2]);
    }
    else {
        printf("incorrect usage");
    }

    return 0;
}

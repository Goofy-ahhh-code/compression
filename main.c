#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

int compress(char string[]) {
    char current_value = string[0];
    int length_num = 0;
    int length = stringlen(string);
    for (int i = 0; i <= length; i++) {
        if (string[i] == current_value) {
            length_num++;
        } else if (string[i] != current_value) {
            printf("%c%d", string[i - 1], length_num);
            length_num = 1;
            current_value = string[i];
        } else if (string[i] != string[i + 1]) {
            printf("%c", string[i]);
            length_num = 1;
        } else if (string[i] == '\0' || string[i] == '\n') {
            printf("ended");
            break;
        }
    }
    return 0;
}

int decompress(char string[]) {
    int length = stringlen(string);
    int num_per_char;
    for (int i = 0; i <= length; i += 2) {
        if (string[i] != '\0') {
            num_per_char = string[i + 1] - '0';
            for (int j = 0; j < num_per_char; j++) {
                printf("%c", string[i]);
            }
        } else {
            break;
        }
    }
    return 0;
}
int main() {
    char input;
    char string[200000];
    printf("Would you like to compress or decompress");
    scanf("%c", &input);
    if (input == 'c') {
        scanf("%s", string);
        compress(string);
    }
    if (input == 'd') {
        scanf("%s", string);
        decompress(string);
    }
    return 0;
}

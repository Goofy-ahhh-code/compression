#include <stdio.h>

#define MAX_NUM 500

int stringlen(char string[]) {
    int j = 0;
    for (int i = 0; i <= MAX_NUM; i++) {
        if (string[i] == '\0') {
            return j;
            break;

        } else {
            j++;
        }
    }
    return 0;
}

int stringcat(char string[]) {
    for (int i = 0; i <= MAX_NUM; i++) {
        if (string[i] != '\0') {
            printf("%c", string[i]);
        } else {
            return 0;
        }
    }
    return 0;
}

int stringcmp(char a[], char b[]) {
    int first_length = stringlen(a);
    int second_length = stringlen(b);
    int j = 0;
    if (first_length != second_length) {
        return 1; // immediate removal if lengths are NOT the same
    } else {
        for (int i = 0; i <= first_length; i++) {
            if (a[i] == b[i]) {
                j++;
            } else if (a[j] == '\0' && b[j] == '\0') {
                return 0;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

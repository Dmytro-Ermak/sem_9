#include "shake.h"

void strings(FILE* file1, FILE* file2) {
    char c1 = 'q', c2 = 'q';
    char* str = (char*) malloc(sizeof(char));
    while (c1 != EOF && c2 != EOF) {
        int j = 0;
        str[j] = '\0';
        while ((c1 = getc(file1)) != EOF) {
            str = (char*) realloc(str, (j + 2) * sizeof(char));
            str[j++] = c1;
            str[j] = '\0';
            if (c1 == '\n') {
                printf("%s", str);
                str[0] = '\0';
                break;
            }
        }
        if (*str) {
            printf("%s\n", str);
        }
        j = 0;
        while ((c2 = getc(file2)) != EOF) {
            str = (char*) realloc(str, (j + 2) * sizeof(char));
            str[j++] = c2;
            str[j] = '\0';
            if (c2 == '\n') {                
                printf("%s", str);
                str[0] = '\0';
                break;
            }
        }
        if (*str) {
            printf("%s\n", str);
        }
    }
    FILE* file; 
    if (c1 == EOF) {
        file = file2;
    } 
    else if (c2 == EOF) {
        file = file1;
    }
    else {
        return;
    }
    while ((c1 = getc(file)) != EOF) {
        putchar(c1);
    }
}
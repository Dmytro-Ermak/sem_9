#include "shake.h"

int main (int args, char* argv[]) {
    if (args != 3) {
        puts("ERROR ARGS");
        return 1;
    }
    FILE* file1 = fopen(argv[1], "r");
    FILE* file2 = fopen(argv[2], "r");
    if (file1 == NULL || file2 == NULL) {
        puts("ERROR FILE NOT OPEN");
        return 1;
    }
    strings(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
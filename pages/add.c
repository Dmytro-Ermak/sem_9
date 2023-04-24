#include "add.h"

int equivalent(char* first, char* second) {
    while (*first == *second) {
        if (*first == '\0') { 
            return 1;
        }
		*first++;
		*second++;
    } 
    return 0;
}

int check_key(int args, char* argv[], char* key) {
    for (int i = 1; i < (args - 1); i++) {
        if (equivalent(argv[i], key)) {
            return i + 1;
        }
    }
    return 0;
}

void check_arg(int args, char* argv[], int stats[]) {
    if (args != 6) {
        return;
    }
    int i, j;
    if  ((i = check_key(args, argv, "-p")) && (j = check_key(args, argv, "-n"))) {
        stats[1] = atoi(argv[i]);
        stats[2] = atoi(argv[j]);
        if (stats[1] && stats[2]) {
            stats[0] = 1;
        }
    }
    return;
}
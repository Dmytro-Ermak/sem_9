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

void check_arg(int args, char* argv[], int stats[]) {
    if (args != 6 || !equivalent(argv[2], "-p") || !equivalent(argv[4], "-n")) {
        return;
    }
    stats[1] = atoi(argv[3]);
    stats[2] = atoi(argv[5]);
    if (stats[1] && stats[2]) {
        stats[0] = 1;
    }
}
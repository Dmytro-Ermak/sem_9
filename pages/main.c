#include "add.h"
#include "paging.h"

int main(int args, char* argv[]) {
    int stats[3] = {0, 0, 0};
    check_arg(args, argv, stats);
    if (!stats[0]) {
        puts("ERROR ARGS");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        puts("ERROR FILE NOT OPEN");
        return 1;
    }
    paging(file, stats[1], stats[2]);
    fclose(file);
    return 0;
}
#include "struct.h"
#include "tail.h"

int main(int args, char *argv[]) {
    if (args == 2) {
        argv[args++] = "5";
    }
    if (args != 3) {
        puts("ERROR COMMAND");
        return 1;
    }
    int count = atoi(argv[args - 1]);
    if (!count) {
        puts("ERROR COMMAND");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        puts("ERROR FILE NOT OPEN");
        return 1;
    }
    Text text = tail(file, count);    
    print(text);
    fclose(file);
    int j = 0;
    if (text.count > text.cnt_input) {
        j = text.count - text.cnt_input;
    }
    for (j; j < text.count; j++) {
        free(text.strings[j]);
    }
    free(text.strings);
}
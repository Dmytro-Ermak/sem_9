#include "struct.h"

Text tail(FILE* file, int count) {
    Text text = {count, 0, (char**) malloc(sizeof(char*) * count)};
    char* line = (char*) calloc(0, sizeof(char));
    int i = 0;
    char c;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            int j = 0;
            if (text.count > text.cnt_input) {
                j = text.count - text.cnt_input - 1;
            }
            else {
                free(text.strings[0]);
            }
            for (j; j < text.count - 1; j++) {
                text.strings[j] = text.strings[j + 1];            
            }
            text.strings[text.count - 1] = line;
            text.cnt_input++;
            line = NULL;
            char* line = (char*) calloc(0, sizeof(char));
            i = 0;
        }
        else {
            line = (char*) realloc(line, sizeof(char) * (i + 2)); 
            line[i++] = c;
            line[i] = '\0';
        }
    }
    if (*line) {
        int j = 0;
        if (text.count > text.cnt_input) {
            j = text.count - text.cnt_input - 1;
        }
        for (j; j < text.count - 1; j++) {
            text.strings[j] = text.strings[j + 1];            
        }
        text.strings[text.count - 1] = line;
        text.cnt_input++;
        line = NULL;
        i = 0;
    }
    return text;
}

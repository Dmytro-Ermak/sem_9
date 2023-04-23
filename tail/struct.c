#include "struct.h"

void print(Text text) {
    int k = 0;
    if (text.count > text.cnt_input) {
        k = text.count - text.cnt_input;
    }
	for(k; k < text.count; k++) { 
        printf("%s\n",text.strings[k]);
    } 
}
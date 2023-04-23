#include "add.h"

void paging(FILE* file, int str_page, int len) {
    char c;
    int page = 1;
    int len_count = 0;
    int str_count = 0;
    char* str = (char*) malloc(len + 1);
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            printf("%s\n", str);
            len_count = 0;
            if (++str_count == str_page) {
                printf(" -- PAGE %i --\n", page++);
                str_count = 0;            
            }
        } 
        else if (len_count == len) {
            printf("%s\n", str);
            len_count = 0;
            str[len_count++] = c;
            str[len_count] = '\0';            
            if (++str_count == str_page) {
                printf(" -- PAGE %i --\n", page++);
                str_count = 0;            
            }
        }
        else {
            str[len_count++] = c;
            str[len_count] = '\0';
        }
    }
    printf("%s\n", str);
    printf(" -- PAGE %i --\n", page);            
    free(str);
}
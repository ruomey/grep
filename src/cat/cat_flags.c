#include <stdio.h>
#include <string.h>
#include "cat.h"


void open_file(int argc, char *argv[1000], int option){
    int k = 1;
    if (option == 3) {
        printf("     %d  ", k);
    }
    for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        char ch = ' ';
        if (file != NULL) {
            int word = 0;
            int flag_end_str = 0, flag_str_void = 0;
            int count_string = 0;
            while ((ch = fgetc(file)) != EOF) {
                if (option == 2) {
                    flag_b(ch, &word, &k);
                } else if (option == 1) {
                    flag_e(ch);
                } else if (option == 3) {
                    count_str(ch, &k);
                    flag_n(ch, k);
                } else if (option == 4) {
                    int flag_non_void = 0;
                    count_string += void_string(ch, &flag_end_str, &flag_str_void, &flag_non_void);
                    if (!count_string) {
                        printf("%c", ch);
                    } else if (!flag_non_void) {
                        printf("\n%c",ch);
                        count_string = 0;
                    } else if (!count_string && !flag_non_void){
                        printf("%c", ch);
                    }
                }
             }
        }
        fclose(file);
    }
}

void flag_e(char ch){
    if (ch == '\n') {
        printf("$\n");
    } else {
        printf("%c", ch);
    }
}

void flag_n(char ch, int count){
        if (ch == '\n') {
            printf("\n     %d  ", count);
        } else {
            printf("%c", ch);
        }
}

void flag_b(char ch, int *word, int* n){
	if (ch == '\n') {
        printf("\n");
        *word = 0;
        
    }
    else {
        if (!*word) {
            printf("     %d  %c", *n, ch);
            *word = 1;
			*n = *n + 1;
        }
        else {
            printf("%c", ch);
        }
    }
}

void flag_s(char ch, int *flag){
    if (!(*flag)) {
        printf("%c", ch);
    }
}
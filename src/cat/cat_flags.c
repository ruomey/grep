#include <stdio.h>
#include <string.h>
#include "cat.h"


void open_file(int argc, char *argv[1000], int option){
    int k = 1;
    int i = 0;
    if (option == 0) {
        i = 1;
    } else if (option != 0) {
        i = 2;
    }
    int flag_opt3 = 0;
    for (; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        char ch = ' ';
        if (file != NULL) {
            if (option == 3 && !flag_opt3) {
                printf("     %d  ", k);
                flag_opt3 = 1;
            }
            int word = 0;
            int flag_end_str = 0, flag_str_void = 0;
            int count_string = 1;
            while ((ch = fgetc(file)) != EOF) {
                if (option == 0) {
                    non_flag(ch);
                }
                if (option == 2) {
                    flag_b(ch, &word, &k);
                } else if (option == 1) {
                    flag_e(ch);
                } else if (option == 3) {
                    count_str(ch, &k);
                    flag_n(ch, k);
                } else if (option == 4) {
                    void_string(ch, &flag_end_str, &flag_str_void, &count_string);
                    flag_s(ch, count_string);
                }
             }
        } else if (file == NULL){
            printf ("cat: %s: No such file or directory\n", argv[i]);
            continue;
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

void flag_s(char ch, int count_string){
    if (!count_string) {
        printf ("%c", ch);
    } else {
        if (count_string == 1) {
            printf("\n");
        }
    }
}

void non_flag(char ch) {
    printf("%c", ch);
}
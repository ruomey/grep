#include <stdio.h>
#include <string.h>
#include "cat.h"

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
void open_file(int argc, char *argv[1000], int opiton){
    int k = 1;
    if (opiton == 3) {
        printf("     %d  ", k);
    }
    for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        char ch = ' ';
        if (file != NULL) {
            int word = 0;
            while ((ch = fgetc(file)) != EOF) {
                if (opiton == 2) {
                    flag_b(ch, &word, &k);
                } else if (opiton == 1) {
                    flag_e(ch);
                } else if (opiton == 3) {
                    count_str(ch, &k);
                    flag_n(ch, k);
                }
             }
        }
        fclose(file);
    }
}
#include <stdio.h>
#include <string.h>
#include "cat.h"


int change_flags(char *argv) {
    int flag = 0;
    if (strcmp(argv, "-e") == 0 || strcmp(argv, "-E") == 0){
        flag = 1;
    } else if (strcmp(argv, "-b") == 0 || strcmp(argv, "--number-nonblank") == 0) {
        flag = 2;
    } else if (strcmp(argv, "-n") == 0 || strcmp(argv, "--number") == 0) {
        flag = 3;
    } else if (strcmp(argv, "-s") == 0 || strcmp(argv, "--squeeze-blank") == 0) {
        flag = 4;
    } else if (strcmp(argv, "-t" )== 0 || strcmp(argv, "-T") == 0) {
        flag = 5;
    }   
    return flag;
}

int condition_args(char *argv){
    int flag = 0;
    char *pointer = strchr(argv, '.');
    if (pointer != NULL) {
        flag = 1;
    }
    return flag;
}
void flag_e(char ch){
    if (ch == '\n') {
        printf("$\n");
    } else {
        printf("%c", ch);
    }
}
void flag_b(char ch){
    int n = 1;
    if (ch != EOF && ch != '\n') {
        printf("     %d  ", n);
            if (ch == '\n') {
                n++;
                printf("\n     %d  ", n);
            } else {
                printf("%c", ch);
            }
    }
}

void flag_n(char ch, int count){
        if (ch == '\n') {
            printf("\n     %d  ", count);
        } else {
            printf("%c", ch);
        }
    }
void void_string(char ch, int *flag_end_str, int *flag_str_void, int *count_void_str){
        if (ch == '\n') {
            if (!(*flag_str_void) && !(*flag_end_str)) {
                *flag_end_str = 1;
            } else if ((*flag_end_str) && !(*flag_str_void)){
                *flag_str_void = 1;
                (*count_void_str)++;
            } else if ((*flag_str_void) && (*flag_end_str)) {
                (*count_void_str)++;
            } 
        } else {
            *flag_str_void = 0;
            *flag_end_str = 0;
        }
}
void open_file(int argc, char *argv[ARG_MAX], int opiton){
    int k = 1;
    if (opiton == 3) {
        printf("     %d  ", k);
    }
    for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        char ch = ' ';
        if (file != NULL) {
            int flag_end_str = 0, flag_str_void = 0, count_void_str = 0;
            while ((ch = fgetc(file)) != EOF) {
                void_string(ch, &flag_end_str, &flag_str_void, &count_void_str);
                printf("\n %d",count_void_str);
                if (opiton == 2) {
                    
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

void count_str(char ch, int *count){
    if (ch == '\n') {
       (*count)++;
    }
}
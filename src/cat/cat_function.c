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

void void_string(char ch, int *flag_end_str, int *flag_str_void, int *count_void_str){
        if (ch == '\n') {
            if (!(*flag_str_void) && !(*flag_end_str)) {
                printf("     %d  ", *count_void_str);
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

void count_str(char ch, int *count){
    if (ch == '\n') {
       (*count)++;
    }
}
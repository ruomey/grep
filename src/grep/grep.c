#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
    if (!isFlag(argv[1])){
        for (int i = 2; i < argc; i++){
            FILE *file = fopen(argv[i], "r");
            if (file != NULL) {
                char *pointer = NULL;
                ssize_t line = " ";
                if ((pointer = strstr(, argv[1])) != NULL){
                    printf("")
                }
            }
        }
    }
    return 0;
}

int isFlag (char *argv) {
    char *pointer = NULL;
    int flag = 0;
    if ((pointer = strchr(argv, ".")) != NULL){
        flag = 1;
    }
    return flag;
}
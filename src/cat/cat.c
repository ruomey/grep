#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int condition_args(char *argv);
int change_flags(char *argv);
void flag_e(int argc, char *argv[256]);

int main(int argc, char *argv[]) {
    if (condition_args(argv[1])) {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file != NULL) {
                char ch = ' ';
                while ((ch = fgetc(file)) != EOF) {
                    printf("%c", ch);
                }
            }
        }
    } else {
       int option = change_flags(argv[1]);
        switch (option)
        {
        case 1:
            flag_e(argc, argv);
            break;
        case 3:
            int k = 1;
             for (int i = 2; i < argc; i++) {
                FILE *file = fopen(argv[i], "r");
                char ch = ' ';
                if (file != NULL && ch != EOF) {
                    printf("     %d  ", k);
                    while ((ch = fgetc(file)) != EOF) {
                        if (ch == '\n') {
                            k++;
                            printf("\n     %d  ", k);
                        } else {
                            printf("%c", ch);
                        }
                    }
                }
            }
            break;
        case 2:
            int n = 1;
             for (int i = 2; i < argc; i++) {
                FILE *file = fopen(argv[i], "r");
                char ch = ' ';
                //char ch2 = ' ';
                if (file != NULL && ch != EOF && ch != '\n') {
                    printf("     %d  ", n);
                    while ((ch = fgetc(file)) != EOF) {
                        if (ch == '\n') {
                            n++;
                            printf("\n     %d  ", n);
                        } else {
                            printf("%c", ch);
                        }
                    }
                }
            }
            break;
        default:
            break;
        }
    return 0;
    }
}

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
void flag_e(int argc, char *argv[256]){
    for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        char ch = ' ';
        if (file != NULL) {
            while ((ch = fgetc(file)) != EOF) {
                if (ch == '\n') {
                    printf("$\n");
                } else {
                    printf("%c", ch);
                }
            }
        }
    }
}
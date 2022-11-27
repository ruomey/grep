#define _GNU_SOURCE 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#define MAX_COUNT_FLAGS 5
void realloc_memory(int* temp, int *tempCount, char** templates);
void realloc_memory_int(int* temp, int *tempCount, int** templates);
struct opt {
    char opt;
    int index_arg;
};
enum flags {
    FLAG_E,
    FLAG_V,
    FLAG_I,
    FLAG_L,
    FLAG_N
};

int main(int argc, char *argv[]){   
    char grep_option[] = {'e',':', 'v', ':', 'i',':','l', ':', 'n', ':'};
    struct opt *input_option = malloc(argc*sizeof(struct opt));
    int options[5] = {0};
    int *files = malloc(sizeof(int));
    options[FLAG_E] = -1;
    int sizeFiles = 0;
    int tempsize = 1;
    int count = 0;
    int option = 0;
    int size = 1;
    char *buffer = malloc(sizeof(char));
    int temp = 1;
    while (optind < argc){
        if(sizeFiles > tempsize){
            realloc_memory_int(&sizeFiles,&tempsize,&files);
        }
        if ((option = getopt(argc, argv, grep_option)) != -1){
                switch (option){
                case 'e':
                    printf("1");
                    fflush(stdout);
                    if ((size = strlen(optarg)) >= temp){
                        realloc_memory(&size, &temp, &buffer);
                    }
                    printf("2");
                    fflush(stdout);
                    if (options[FLAG_E] == -1){
                        options[FLAG_E] = FLAG_E;

                    }
                    printf("3");
                    fflush(stdout);
                    if (count == FLAG_E){
                        strcpy(buffer, optarg);
                        printf("4");
                    fflush(stdout);
                    } else { 
                        strcat(buffer, optarg);
                        printf("5");
                        fflush(stdout);
                        if (count != argc - 1)
                        strcat(buffer, "|");  
                        printf("6");
                        fflush(stdout);
                    }
                        printf("4");
                        fflush(stdout);
                    for (int i = 0; i < 5; i++){
                        printf("4");
                        fflush(stdout);
                        if(!options[FLAG_E] && options[i]!=0 && i!=0){
                            files[sizeFiles] = input_option[i].index_arg;
                            sizeFiles++;
                            options[i] = 0;
                        }
                    }
                    printf("6");
                        fflush(stdout);
                    size = strlen(buffer);
                    count++;
                    break;
                case 'v':
                    input_option[count].index_arg = count;
                    input_option[count].opt = 'v';
                    if (!options[FLAG_V]){
                        options[FLAG_V] = FLAG_V;
                        strcpy(argv[FLAG_V], optarg);
                    }else {
                        files[sizeFiles] = count;
                        sizeFiles++;
                        strcpy(argv[count], optarg);
                    }
                    count++;
                    break;
                case 'i':
                    strcpy(argv[count], optarg);
                    input_option[count].index_arg = count;
                    input_option[count].opt = 'i';
                    if (!options[FLAG_I]){
                        options[FLAG_I] = FLAG_I;
                        strcpy(argv[FLAG_I], optarg);
                    }else {
                        files[sizeFiles] = count;
                        sizeFiles++;
                        strcpy(argv[count], optarg);
                    }
                    count++;
                    break;
                case 'n':
                    strcpy(argv[count], optarg);
                    input_option[count].index_arg = count;
                    input_option[count].opt = 'n';
                    if (!options[FLAG_N]){
                        options[FLAG_N] = FLAG_N;                
                    } else {
                        files[sizeFiles] = count;
                        sizeFiles++;
                        strcpy(argv[count], optarg);
                    }
                    count++;
                    break;
                case 'l':
                    strcpy(argv[count], optarg);
                    input_option[count].index_arg = count;
                    input_option[count].opt = 'l';
                    if (!options[FLAG_L]){
                        options[FLAG_L] = FLAG_L;
                        strcpy(argv[FLAG_L], optarg);
                    } else {
                        files[sizeFiles] = count;
                        sizeFiles++;
                        strcpy(argv[count], optarg);
                    }
                    count++;
                    break;
                default:
                    break;
                }
            }
            else {
                files[sizeFiles] = optind;
                optind++;
               sizeFiles++;
            }
    }

    for (int i = 0; i < sizeFiles; ++i){

        regex_t arbuz_regex;
        int error = 0;
        int count_string = 1;
        FILE *file = fopen(argv[files[i]], "r");
        if (file != NULL){
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            //printf("Never gonna give you up ");
            int flag = 0;
            while ((read = getline(&line, &len, file)) != -1){
                for (int j = 0; j < 5; j++) {     
                    switch (options[j]){
                        case FLAG_E:
                            if (!flag){
                                if ( (error = regcomp(&arbuz_regex, buffer, REG_EXTENDED)) != 0 ) {
                                    //printf("%s %d\n", buffer, options[j]);
                                    continue;
                                }
                                if ( (error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                                    if (sizeFiles > 0) {
                                        printf("%s:%s",argv[files[i]], line);
                                    } else {
                                        printf("%s",line);
                                    }
                                }
                                free(line);
                                flag = 1;
                            }
                            break;
                        case FLAG_N:
                        
                            if ((error = regcomp(&arbuz_regex, argv[input_option[j].index_arg], REG_EXTENDED)) != 0) {
                                continue;
                            }
                            if ((error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                                if (sizeFiles > 1) {
                                    printf("%s:%d:%s", argv[files[i]], count_string, line);
                                } else {
                                    printf("%d:%s",count_string, line);
                                }
                            }
                            break;
                        default:
                            break;
                    }
                
                }
                count_string++;
            }
            fclose(file);
        } else {
            printf("grep: %s: No such file or directory\n", argv[files[i]]);
        }
    }
}

void realloc_memory(int* temp, int *tempCount, char** templates) {
    if ((*temp) == (*tempCount)) {
          (*tempCount) *= 2;
          *templates = realloc(*templates, (*tempCount) * sizeof(char *));
    }
}
void realloc_memory_int(int* temp, int *tempCount, int** templates) {
    if ((*temp) == (*tempCount)) {
          (*tempCount) *= 2;
          *templates = realloc(*templates, (*tempCount) * sizeof(int *));
    }
}
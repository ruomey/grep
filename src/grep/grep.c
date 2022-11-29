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
    int options[] = {-1, -1, -1, -1, -1};
    int *files = malloc(sizeof(int));
    int sizeFiles = 0;
    int tempsize = 1;
    int count = 0;
    int option = 0;
    int size = 1;
    int flag = 1;
    char *buffer = malloc(sizeof(char));
    int temp = 1;
    printf("opt = %d\n", optind);
    while (optind < argc){
        printf("optind %d < argv %d\n", optind, argc);
        if(sizeFiles > tempsize){
            realloc_memory_int(&sizeFiles,&tempsize,&files);
        }
        if ((option = getopt(argc, argv, grep_option)) >  -1){
            printf("in if optind %d < argv %d\n", optind, argc);
            printf("%c\n", option);
                switch (option){
                case 'e':
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
                    if (options[FLAG_V] ==-1){
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
                    if (options[FLAG_I] == -1){
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
                    if (options[FLAG_N] == -1){
                                            strcpy(argv[count], optarg);
                    input_option[count].index_arg = count;
                    input_option[count].opt = 'n';
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
                    if (options[FLAG_L] == -1){
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
                if (optind == 1) {
                    files[sizeFiles] = optind;
                    sizeFiles++;
                    optind++;
                    flag = 0;
                } else if ((optind == (argc - 1)) && !flag){
                            printf("2");
                            files[sizeFiles] = optind - 1;
                            sizeFiles++;
                            break;
                } else {
                    files[sizeFiles] = optind;
                    optind++;
                    sizeFiles++;
                }
            }
    }
    for (int i = 0; i < sizeFiles; i++){
        printf("%s\n", argv[files[i]]);
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
                if (options[FLAG_E] == FLAG_E){
                    if (!flag){
                        while ((read = getline(&line, &len, file)) != -1){
                            if ( (error = regcomp(&arbuz_regex, buffer, REG_EXTENDED)) != 0 ) {
                                //printf("%s %d\n", buffer, options[j]);
                                continue;
                            }
                            if ( (error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                                printf("%d\n", sizeFiles);
                                if (sizeFiles  > 0) {
                                    printf("fuck\n");
                                    printf("%s:%s",argv[files[i]], line);
                                } else {
                                    printf("%s",line);
                                }
                            }
                            free(line);
                            flag = 1;
                        }
                    }
                }
                if (options[FLAG_N] == FLAG_N) {
                    while ((read = getline(&line, &len, file)) != -1){    
                        if ((error = regcomp(&arbuz_regex, argv[input_option[FLAG_N].index_arg], REG_EXTENDED)) != 0) {
                            continue;
                        }
                        if ((error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                            if (sizeFiles > 1) {
                                printf("%s:%d:%s", argv[files[i]], count_string, line);
                            } else {
                                printf("%d:%s",count_string, line);
                            }
                        }
                        count_string++;
                    }
                }
            fclose(file);
        } else {
            printf("бляяя\n");
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
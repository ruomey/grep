#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cat/cat.h"
#include <string.h>
void realloc_memory_int(int* temp, int *tempCount, int** templates);

struct opt {
    int index;
    char opt;
    int index_arg;
};


int main(int argc, char *argv[]){
    char grep_option[] = {'e',':', 'v', ':', 'i',':','l', ':', 'n', ':'};
    struct opt *input_option = malloc(argc*sizeof(struct opt));
    // int result = 0;
    //int count_opt = 0;
    int count_arg = 0;
    int count = 0;
    for (int i = 1; i < argc; i++){
        if(!condition_args(argv[i])){
            ;
        }
    }
    //int i = 0;
    int option = 0;
    while ((option = getopt(argc, argv, grep_option)) != -1){
        switch (option)
        {
        case 'e':
            count_arg+=1;
            input_option[count].index = count;
            input_option[count].index_arg = count+1;
            input_option[count].opt = 'e';
            strcpy(argv[count+1],optarg);
            count++;
            break;
        case 'v':
        count_arg+=2;
            input_option[count].index = count;
            input_option[count].index_arg = count_arg;
            input_option[count].opt = 'v';
            count++;
            break;
        case 'i':
        count_arg+=2;
            input_option[count].index = count;
            input_option[count].index_arg = count_arg;
            input_option[count].opt = 'i';
            count++;
            break;
        case 'n':
        count_arg+=2;
            input_option[count].index = count;
            input_option[count].index_arg = count_arg;
            input_option[count].opt = 'n';
            count++;
            break;
        case 'l':
        count_arg+=2;
            input_option[count].index = count;
            input_option[count].index_arg = count_arg;
            input_option[count].opt = 'l';
            count++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < count; i++){
        printf("index is %d\n", input_option[i].index);
         printf("index arg is %s\n", argv[input_option[i].index_arg]);
          printf("opt is %c\n", input_option[i].opt);
        
    }
    for (;optind < argc; optind++){
        FILE *file = fopen(argv[optind], "r");
        if (file != NULL){
            ;
        } else {
            printf("бляяя");
        }
    }
    for (int i = 0; i < argc; i++){
        printf("argv is %s\n", argv[i]);
    }
}
void realloc_memory_int(int* temp, int *tempCount, int** templates) {
    if ((*temp) == (*tempCount)) {
          (*tempCount) *= 2;
          *templates = realloc(*templates, (*tempCount) * sizeof(int *));
    }
}

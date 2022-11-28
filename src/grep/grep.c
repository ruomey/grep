#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
void realloc_memory_int(int* temp, int *tempCount, int** templates);

struct opt {
    int index;
    char opt;
    int index_arg;
};


int main(int argc, char *argv[]){   
    char grep_option[] = {'e',':', 'v', ':', 'i',':','l', ':', 'n', ':'};
    struct opt *input_option = malloc(argc*sizeof(struct opt));
    //int count_arg = 0;
    int count = 0;
    int option = 0;
    while ((option = getopt(argc, argv, grep_option)) != -1){
        switch (option){
        case 'e':
            strcpy(argv[count], optarg);
            input_option[count].index = count;
            input_option[count].index_arg = count;
            input_option[count].opt = 'e';
            count++;
            break;
        case 'v':
        strcpy(argv[count], optarg);
            input_option[count].index = count;
            input_option[count].index_arg = count;
            input_option[count].opt = 'v';
            count++;
            break;
        case 'i':
        strcpy(argv[count], optarg);
            input_option[count].index = count;
            input_option[count].index_arg = count;
            input_option[count].opt = 'i';
            count++;
            break;
        case 'n':
        strcpy(argv[count], optarg);
            input_option[count].index = count;
            input_option[count].index_arg = count;
            input_option[count].opt = 'n';
            count++;
            break;
        case 'l':
        strcpy(argv[count], optarg);
            input_option[count].index = count;
            input_option[count].index_arg = count;
            input_option[count].opt = 'l';
            count++;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        printf("index is %d\n", input_option[i].index);
        printf("arg is %s\n", argv[input_option[i].index_arg]);
        printf("opt is %c\n", input_option[i].opt);
        printf("optind is %d\n", argc);
    }
    for (;optind < argc; optind++){
        printf("argv[optind] = %s\n", argv[optind]);
        FILE *file = fopen(argv[optind], "r");
        if (file != NULL){
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            printf("Never gonna give you up ");
            while ((read = getline(&line, &len, file)) != -1){
                printf("never gonna let you down\n");
                for(int i = 0; i < count; i++){
                    regex_t arbuz_regex;
                    int error = 0;
                    if ( (error = regcomp(&arbuz_regex, argv[input_option[i].index_arg], REG_EXTENDED)) != 0 ) {
                        printf("Never gonna run around and desert you\n");
                        continue;
                    }
                    if ( (error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                        printf("Never gonna make you cry, ");
                        printf("%s",line);
                    }
                    printf("never gonna say goodbye\n");
                    regfree(&arbuz_regex);
                    printf("Never gonna tell a lie and hurt you\n");
                }
            }
            free(line);
        } else {
            printf("fuck");
        }
        fclose(file);
    }
}
void realloc_memory_int(int* temp, int *tempCount, int** templates) {
    if ((*temp) == (*tempCount)) {
          (*tempCount) *= 2;
          *templates = realloc(*templates, (*tempCount) * sizeof(int *));
    }
}

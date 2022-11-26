#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
void realloc_memory(int* temp, int *tempCount, char** templates);

struct opt {
    int index;
    char opt;
    int index_arg;
    int count_arg;
};


int main(int argc, char *argv[]){   
    char grep_option[] = {'e',':', 'v', ':', 'i',':','l', ':', 'n', ':'};
    struct opt *input_option = malloc(argc*sizeof(struct opt));
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
        printf("count = %d\n", count);
    }
    int count_arg = 0;
    for (int i = 0; i < count; i++) {
        // printf("index is %d\n", input_option[i].index);
        // printf("arg is %s\n", argv[input_option[i].index_arg]);
        // printf("opt is %c\n", input_option[i].opt);
        // printf("optind is %d\n", argc); 
        for(int j = 0; j < count; j++){
            if (input_option[j].opt == 'e'){
                printf("count arg = %d \n", count_arg);
                strcat(argv[i], "|");
                strcat(argv[i], argv[input_option[j].index_arg]);
            }
            printf("count arg = %d \n", count_arg);
            if (j == count - 1) {
                printf("count arg = %d \n", count_arg);
                count_arg++;
            } 
        } 
        for(int j = 0; j < count; j++){
            if (input_option[j].opt == 'v'){
                strcat(argv[i], "|");
                strcat(argv[i], argv[input_option[j].index_arg]);
            }
            if (j == count - 1) {
                count_arg++;
            } 
        } 
        for(int j = 0; j < count; j++){
            if (input_option[j].opt == 'i' ){
                strcat(argv[i], "|");
                strcat(argv[i], argv[input_option[j].index_arg]);
            }
            if (j == count - 1) {
                count_arg++;
            } 
        } 
        for(int j = 0; j < count; j++){
            if (input_option[j].opt == 'l'){
                strcat(argv[i], "|");
                strcat(argv[i], argv[input_option[j].index_arg]);
            }
            if (j == count - 1) {
                count_arg++;
            } 
        } 
        for(int j = 0; j < count; j++){
            if (input_option[j].opt == 'n' ){
                strcat(argv[i], "|");
                strcat(argv[i], argv[input_option[j].index_arg]);
            }
            if (j == count - 1) {
                count_arg++;
            } 
        }
    }
    printf("%s \n", argv[0]);
    for (;optind < argc; optind++){
        printf("argv[optind] = %s\n", argv[optind]);
        FILE *file = fopen(argv[optind], "r");
        if (file != NULL){
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            //printf("Never gonna give you up ");
            while ((read = getline(&line, &len, file)) != -1){
                //printf("never gonna let you down\n");
                for(int i = 0; i < count_arg; i++){
                    regex_t arbuz_regex;
                    int error = 0;
                    if ( (error = regcomp(&arbuz_regex, argv[i], REG_EXTENDED)) != 0 ) {
                        //printf("Never gonna run around and desert you\n");
                        continue;
                    }
                    if ( (error = regexec(&arbuz_regex, line, 0, NULL, 0)) == 0 ){
                       // printf("Never gonna make you cry, ");
                        printf("%s",line);
                    }
                   //printf("never gonna say goodbye\n");
                    regfree(&arbuz_regex);
                    //printf("Never gonna tell a lie and hurt you\n");
                }
            }
            free(line);
        } else {
            printf("бляяя");
        }
        fclose(file);
    }
}
void realloc_memory(int* temp, int *tempCount, char** templates) {
    if ((*temp) == (*tempCount)) {
          (*tempCount) *= 2;
          *templates = realloc(*templates, (*tempCount) * sizeof(char *));
    }
}

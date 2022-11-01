#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cat.h"

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
        open_file(argc, argv, option);

    }
    return 0;
}

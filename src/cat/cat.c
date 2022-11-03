#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cat.h"

int main(int argc, char *argv[]) {
    int option = condition_args(argv[1]);
    open_file(argc, argv, option);
    return 0;
}

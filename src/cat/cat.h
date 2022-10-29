#ifndef SRC_CAT_H_
#define SRC_CAT_H_
#include <limits.h>
int condition_args(char *argv);
int change_flags(char *argv);
void flag_e(char ch);
void flag_b(char ch);
void flag_n(char ch);
void void_string(int argc, char *argv[ARG_MAX], char ch);
void open_file(int argc, char *argv[ARG_MAX], int opiton);

#endif  // SRC_CAT_H_
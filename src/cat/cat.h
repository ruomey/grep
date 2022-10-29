#ifndef SRC_CAT_H_
#define SRC_CAT_H_
#include <limits.h>
int condition_args(char *argv);
int change_flags(char *argv);
void flag_e(char ch);
void flag_b(char ch);
void flag_n(char ch, int count);
void void_string(char ch, int *flag_end_str, int *flag_str_void, int *count_void_str);
void open_file(int argc, char *argv[ARG_MAX], int opiton);
void count_str(char ch, int *count);

#endif  // SRC_CAT_H_
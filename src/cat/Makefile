CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
EXECUTABLE_1=s21_cat
SOURCES1=cat_flags.c cat.c cat_function.c
c.o:
	$(CC) $(CFLAGS) $< -o $@
s21_cat: $(SOURCES1)
	$(CC) $(LDFLAGS) $(SOURCES1) -o $(EXECUTABLE_1)

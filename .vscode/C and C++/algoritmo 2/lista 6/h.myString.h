#include <stddef.h>
#ifndef myString_H
#define myString_H

char *mystrcpy(char *s1, const char *s2);
char *mystrncpy(char *s1, const char *s2, size_t n);
char *mystrcat(char *s1, const char *s2);
char *mystrncat(char *s1, const char *s2, size_t n);
int *mystrcmp(char *s1, const char *s2);
int *mystrncmp(char *s1, const char *s2, size_t n);
#endif
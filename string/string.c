#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#include <ctype.h>
#endif
unsigned int str_strlen(char *str) {
    char *temp = str;
    while(*temp) temp++;
    return ((int) (temp - str));
}

unsigned int str_isalpha(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}


unsigned int str_strlcpy(char *dest, char *orig, size_t buffSize) {
    unsigned int size = str_strlen(orig) + str_strlen(dest);

    if (str_strlen(orig) > buffSize)
        return (str_strlen(orig) + buffSize);
    if (size < buffSize)
        while (*orig) *dest++ = *orig++;
    else {
        while (size > buffSize) {
            *dest++ = *orig++;
            size--;
        }
        *dest = '\0';
        return (size);
    }
    return (size);
}
unsigned int str_strcmp(char *s1, char *s2) {
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++; s2++;
    }
    return (*(unsigned char *) s1 - *(unsigned char *)s2);
}

short unsigned int str_getWord(FILE *in, char *word) {
    char ch;
    int unsigned n = 0;
    while (!str_isalpha((ch = fgetc(in))) && ch != EOF);
    if (ch == EOF) return (0);
    word[n++] = ch;
    while (str_isalpha((ch = fgetc(in))) && ch != EOF)
        if (n < MAXSIZE) word[n++] = ch;
    word[n] = '\0';
    return (1);
}

void str_strcat(char *s1, char *s2) {
    unsigned int size = str_strlen(s1);
    while (*s2) {
        *(s1 + size) = *s2;
        s1++; s2++;
    }       
}

void showMessage(const char *msg, unsigned char errCod) {
    fprintf(stderr, "%s\n", msg);
    exit(errCod);
}
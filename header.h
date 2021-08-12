#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAX_INPUT_NAME 15

enum {INPUT_ERR, OUTPUT_ERR, MEM_ERROR_STR, MEM_ERROR_NODE, MEM_ERROR_DTYPE};

typedef struct {
    char *word;
    int   freq;   
} dataType;

typedef struct node{
    dataType data;
    struct node *left, *right;
} Node;

typedef struct {
    Node *root;
} Btree;

void showMessage(const char *msg, unsigned char errCod);

/*get a string from input stream*/
short unsigned int str_getWord(FILE *in, char *word);

/*return the size of string*/
unsigned int str_strlen(char *str);

/* return the difference of two strigs*/
unsigned int str_strcmp(char *s1, char *s2);

/* concat two strings*/
void str_strcat(char *s1, char *s2);

/* copy str with security */
unsigned int str_strlcpy(char *dest, char *orig, size_t buffSize);

/* create a node and set the values */
Node * makeNode(dataType data);

/* return a pointer to a new dataType*/
dataType makeDataType(char *word, unsigned int freq);

/* clear the memory */
void clearMemory(Node *node);

/* find or insert a node in tree*/
Node *findOrInsert(Btree bt, dataType data);

/* print the tree */
void InOrder(FILE * out, Node *ptr);
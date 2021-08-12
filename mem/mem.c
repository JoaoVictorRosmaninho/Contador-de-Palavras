#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#endif

Node * makeNode(dataType data) {
    Node *temp_node = NULL;

    if ((temp_node = (Node *) malloc(sizeof(Node))) == NULL)
        showMessage("Memoria insuficiente", MEM_ERROR_NODE);   
    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return (temp_node);
}

dataType makeDataType(char *word, unsigned int freq) {
    dataType data;
     if (((data.word = (char *) malloc(str_strlen(word) + 1))) == NULL)
        showMessage("Memoria insuficiente", MEM_ERROR_STR);
     str_strlcpy(data.word, word, str_strlen(word) + 1);
     data.freq = freq;
     return (data); 
}

void clearMemory(Node *node) {
    if (node != NULL) {
        clearMemory(node->left);
        clearMemory(node->right);
        free(node);
    }
}
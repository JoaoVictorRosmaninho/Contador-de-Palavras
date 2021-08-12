#ifndef HEADER_H
# define HEADER_H
# include "../header.h"
#endif

Node *findOrInsert(Btree bt, dataType data) {
    int cmp;
    if (bt.root == NULL) 
        return makeNode(data);   
    Node *curr = bt.root;
    while ((cmp = str_strcmp(data.word, curr->data.word)) != 0) {
        if (cmp < 0) { //left
            if (curr->left == NULL) return (curr->left = makeNode(data));
            curr = curr->left;
        } else { //right
            if (curr->right == NULL) return (curr->right = makeNode(data));
            curr = curr->right;
        }
    }
    return (curr);
}

void InOrder(FILE * out, Node *ptr) {
    if (ptr != NULL) {
        InOrder(out, ptr->left);
        fprintf(out, "%-15s %2d\n", ptr->data.word, ptr->data.freq);
        InOrder(out, ptr->right);
    }
}
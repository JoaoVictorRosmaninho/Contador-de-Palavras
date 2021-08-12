#ifndef HEADER_H
# define HEADER_H
# include "header.h"
#endif

int main(int argc, char *argv[]) {
    FILE *in, *out;
    char word[MAXSIZE];
    char inputName[MAX_INPUT_NAME + 1];
    Btree bt;
    if (argc != 2)
        showMessage("invalid output. try: ./run <inputFile>", INPUT_ERR);
    bt.root = NULL;
    if ((in = fopen(argv[1], "r")) == NULL)
        showMessage("Erro ao abrir arquivo de entrada", INPUT_ERR);
    str_strlcpy(inputName, argv[1], sizeof(inputName));
    str_strcat(inputName, ".out");   
    if ((out = fopen(inputName, "w")) == NULL)
        showMessage("Error ao criar arquivo de Saída", OUTPUT_ERR); 
    while ((str_getWord(in, word))) {
        if (bt.root == NULL)
            bt.root = makeNode(makeDataType(word, 1));
        else {
            Node *ptr = findOrInsert(bt, makeDataType(word, 0));
            ptr->data.freq++;
        }
    } 
    InOrder(out, bt.root);
    clearMemory(bt.root);
    fclose(in); fclose(out);
    return (0);
}

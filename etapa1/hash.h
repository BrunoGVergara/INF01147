//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 1 | Bruno Grohs Vergara - 324256

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_SIZE 997

typedef struct hash_node
{
    int type;
    char* text;
    struct hash_node* next;
}HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE* hashFind(char *text);
HASH_NODE* hashInsert(char *text, int type);
void hashPrint(void);

#endif

//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 1 | Bruno Grohs Vergara - 324256

#include "hash.h"

HASH_NODE*Table[HASH_SIZE];

void hashInit(void)
{
    int i;
    for(i = 0; i < HASH_SIZE; i++)
    {
        Table[i] = NULL;
    }
}

int hashAddress(char *text)
{
    int i;
    int address = 1;
    for(i = 0; i < strlen(text); i++)
    {
        address = (address * text[i]) % HASH_SIZE + 1;
    }
    return address-1;
}

HASH_NODE *hashFind(char *text)
{
    HASH_NODE *node;
    int address = hashAddress(text);
    for(node=Table[address]; node != NULL; node = node->next)
    {
        if(strcmp(node->text,text)==0)
        {
            return node;
        }
    }
    return NULL;
}

HASH_NODE *hashInsert(char *text, int type)
{
    HASH_NODE *newnode;
    int address = hashAddress(text);
    
    if((newnode = hashFind(text)) != 0)
    {
        return newnode;
    }
    
    newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newnode->type = type;
    newnode->text = (char*) calloc(strlen(text) + 1, sizeof(char));
    strcpy(newnode->text, text);
    
    newnode->next = Table[address];
    Table[address] = newnode;
    
    return newnode;
}

void hashPrint(void)
{
    int i;
    HASH_NODE *node;
    for(i = 0; i < HASH_SIZE; i++)
    {
        if(Table[i] != NULL)
        {
            for(node=Table[i]; node != NULL; node = node->next)
            {
                printf("Tabela[%d] tem %s, do tipo %d.\n",i,node->text,node->type);
            }
        }
    }
}

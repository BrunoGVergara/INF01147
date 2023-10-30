//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 1 | Bruno Grohs Vergara - 324256

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "tokens.h"

int main(int argc, char **argv)
{
    int token;
    if(argc < 2)
    {
        fprintf(stderr,"Call: ./a.out file_name\n");
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    
    while(running)
    {
        token = yylex();
        if(running == 0)
        {
            break;
        }
        switch(token)
        {
            case KW_CHAR: printf("Keyword Char\n"); break;
            case KW_INT: printf("Keyword Int\n"); break;
            case KW_FLOAT: printf("Keyword Float\n"); break;
            case KW_CODE: printf("Keyword Code\n"); break;
            case KW_IF: printf("Keyword If\n"); break;
            case KW_ELSE: printf("Keyword Else\n"); break;
            case KW_WHILE: printf("Keyword While\n"); break;
            case KW_INPUT: printf("Keyword Input\n"); break;
            case KW_PRINT: printf("Keyword Print\n"); break;
            case KW_RETURN: printf("Keyword Return\n"); break;
            
            case OPERATOR_LE: printf("Operador <=\n"); break;
            case OPERATOR_GE: printf("Operador >=\n"); break;
            case OPERATOR_EQ: printf("Operador ==\n"); break;
            case OPERATOR_DIF: printf("Operador !=\n"); break;
            
            case LIT_INT: printf("Literal Inteiro\n"); break;
            case LIT_REAL: printf("Literal Real\n"); break;
            case LIT_CHAR: printf("Literal Char\n"); break;
            case LIT_STRING: printf("Literal String\n"); break;
            
            case TK_IDENTIFIER: printf("Identificador\n"); break;
            
            case TOKEN_ERROR: printf("ERRO\n"); break;
            
            default: printf("Caracter %c\n",yytext[0]); break;
        }
    }
    printf("Arquivo tem %d linhas\n",lineNumber);
    hashPrint();
    exit(0);
}

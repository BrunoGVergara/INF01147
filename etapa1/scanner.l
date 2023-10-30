%{
    //INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
    //   Trabalho - Etapa 1 | Bruno Grohs Vergara - 324256
    
#include "tokens.h"
#include "hash.h"

int running = 1;
int lineNumber = 1;

%}

%x BIG_COMMENT
%x LINE_COMMENT

%%

char                    {return KW_CHAR;}
int                     {return KW_INT;}
float                   {return KW_FLOAT;}
code                    {return KW_CODE;}
if                      {return KW_IF;}
else                    {return KW_ELSE;}
while                   {return KW_WHILE;}
input                   {return KW_INPUT;}
print                   {return KW_PRINT;}
return                  {return KW_RETURN;}

"<="                    {return OPERATOR_LE;}
">="                    {return OPERATOR_GE;}
"=="                    {return OPERATOR_EQ;}
"!="                    {return OPERATOR_DIF;}

"\n"                    {++lineNumber;}
[ \t]

[0-9]+                  {hashInsert(yytext, LIT_INT); return LIT_INT;}
[0-9]+"."[0-9]+         {hashInsert(yytext, LIT_REAL); return LIT_REAL;}
"'"."'"                 {hashInsert(yytext, LIT_CHAR); return LIT_CHAR;}
"\""[^\"]+"\""          {hashInsert(yytext, LIT_STRING); return LIT_STRING;}

[a-zA-Z0-9_]+           {hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}

[-,;()[\]{}=+*/%<>&|~]  {return yytext[0];}

"//"                    {BEGIN(LINE_COMMENT);}
"///"                   {BEGIN(BIG_COMMENT);}

.                       {return TOKEN_ERROR;}

<LINE_COMMENT>.
<LINE_COMMENT>"\n"      {++lineNumber; BEGIN(INITIAL);}

<BIG_COMMENT>"\\\\\\"       {BEGIN(INITIAL);}
<BIG_COMMENT>.
<BIG_COMMENT>\n             {++lineNumber;}

%%

#include "hash.c"
#include "main.c"

void initMe(void)
{
    hashInit();
}
    
int getLineNumber(void)
{
    return lineNumber;
}
    
int isRunning(void)
{
    return running;
}
    
int yywrap()
{
    running = 0;
    return 1;
}

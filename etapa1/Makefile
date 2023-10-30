#INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
#   Trabalho - Etapa 1 | Bruno Grohs Vergara - 324256

etapa1: lex.yy.c
	gcc -o etapa1 lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c etapa1

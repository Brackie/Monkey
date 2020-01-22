#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monkey.h"


const char *LET_IDENT = "let";
const char *FN_IDENT = "fn";

void newToken(int type, char *lit, Token *t){
	t->tokenType = type;
	t->literal = lit;
}

int isLetter(char ch){
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

void readIdentifier(Lexer *l, Identifier *i){
	int j = 0;
	i->start = l->ch;
	while (isLetter(*l->ch)){
		i->identifier[j] = *l->ch;
		j++;
		readChar(l);
	}
	i->end = l->ch - 1;
}

int lookUpIdentifier(Identifier *i){
	int type = IDENTIFIER;
	printf("Start: %c, End: %c, Identifier: %s, Size: %d\n", *i->start, *i->end, i->identifier, (sizeof(i->identifier)/sizeof(i->identifier[0])));
	if (!strcmp(i->identifier, LET_IDENT))
		return LET;
	else if (!strcmp(i->identifier, FN_IDENT))
		return FUNCTION;
	printf("Token Type: %d\n", type);
	return type;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monkey.h"


const char LET_IDENT[4] = "let";
const char FN_IDENT[3] = "fn";

void newToken(int type, char *lit, Token *t){
	t->tokenType = type;
	t->literal = lit;
}

int isLetter(char ch){
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

void readIdentifier(Lexer *l, int *type){
	int j = 0;
	char *identifier = (char*) malloc(sizeof(char) * 54);
	while (isLetter(*l->ch)){
		identifier[j] = *l->ch;
		j++;
		readChar(l);
	}
	if (!isLetter(*l->ch)){
		j++;
		identifier[j] = '\0';
	}
	*type = lookUpIdentifier(identifier);
}

int lookUpIdentifier(char *identifier){
	int type = IDENTIFIER;
	if (!strncmp(identifier, LET_IDENT, sizeof(LET_IDENT))){
		return LET;
	}
	else if (!strncmp(identifier, FN_IDENT, sizeof(FN_IDENT))){
		return FUNCTION;
	}
	return type;
}
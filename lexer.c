#include <stdlib.h>
#include <string.h>

#include "monkey.h"


void newLexer(Lexer *l, char *input){
	l->input = input;
	l->position = 0;
	l->readPosition = l->position;
	readChar(l);
}

void readChar(Lexer *l){
	if(l->readPosition >= strlen(l->input))
		l->ch = 0;
	else
		l->ch = &l->input[l->readPosition];
	l->position = l->readPosition;
	l->readPosition += 1;
}

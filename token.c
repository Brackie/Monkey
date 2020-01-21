#include <stdio.h>
#include <stdlib.h>

#include "monkey.h"


void nextToken(Lexer *l, Token *t){
	switch(l->ch){
		case '=':
			newToken(ASSIGN, l->ch, t);
			break;
		case ';':
			newToken(SEMICOLON, l->ch, t);
			break;
		case '(':
			newToken(LPAREN, l->ch, t);
			break;
		case ')':
			newToken(RPAREN, l->ch, t);
			break;
		case ',':
			newToken(COMMA, l->ch, t);
			break;
		case '+':
			newToken(PLUS, l->ch, t);
			break;
		case '{':
			newToken(LBRACE, l->ch, t);
			break;
		case '}':
			newToken(RBRACE, l->ch, t);
			break;
		case 0:
			newToken(EOF, "", t);
			break;
	}
}

void newToken(int type, char *lit, Token *t){
	t->tokenType = type;
	t->literal = lit;
}



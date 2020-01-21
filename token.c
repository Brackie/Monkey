#include <stdio.h>
#include <stdlib.h>

#include "monkey.h"

void nextToken(Lexer *l, Token *t){
	switch(l->ch){
		case '=':
			newToken(ASSIGN, &lx->ch, t);
			break;
		case ';':
			newToken(SEMICOLON, &lx->ch, t);
			break;
		case '(':
			newToken(LPAREN, &lx->ch, t);
			break;
		case ')':
			newToken(RPAREN, &lx->ch, t);
			break;
		case ',':
			newToken(COMMA, &lx->ch, t);
			break;
		case '+':
			newToken(PLUS, &lx->ch, t);
			break;
		case '{':
			newToken(LBRACE, &lx->ch, t);
			break;
		case '}':
			newToken(RBRACE, &lx->ch, t);
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



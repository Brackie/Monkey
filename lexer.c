#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monkey.h"


void newLexer(Lexer *l, char *input){
	l->input = input;
	l->position = 0;
	l->readPosition = l->position;
	readChar(l);
}

void nextToken(Lexer *l, Token *t){
	switch(*l->ch){
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
		default:
			if (isLetter(*l->ch)){
				int type = IDENTIFIER;
				readIdentifier(l, &type);
				newToken(type, l->ch, t);
				return;
			}
			else{
				newToken(ILLEGAL, l->ch, t);
				return;
			}

	}
	readChar(l);
	jumpWhiteSpace(l);
}

void readChar(Lexer *l){
	if(l->readPosition >= strlen(l->input))
		l->ch = 0;
	else
		l->ch = &l->input[l->readPosition];
	l->position = l->readPosition;
	l->readPosition += 1;
}

void jumpWhiteSpace(Lexer *l){
	printf("%c\n", *l->ch);
	while(*l->ch == ' ' || *l->ch == '\t' || *l->ch == '\n' || *l->ch == '\r')
		readChar(l);
}

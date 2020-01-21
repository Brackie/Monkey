#include <stdlib.h>


enum Symbols
{
	ILLEGAL = -1,
	EOF = 0,

	// Identifiers + Literals
	INDENT = 1,
	INTEGER = 2,

	// Operators
	ASSIGN = 3,
	PLUS = 4,

	// Delimeters
	COMA = 5,
	SEMICOLON = 6,
	LPAREN = 7,
	RPAREN = 8,
	LBRACE = 9,
	RBRACE = 10,

	// Keywords
	FUNCTION = 11,
	LET = 12
}

typedef struct Token{

	int tokenType;
	
	char * literal;

} Token;

typedef struct Lexer{
	
	char * input;
	int position;
	int readPosition;
	char * ch;


} Lexer;


// Returns an instance of a new Lexer
Lexer newLexer(char *input);

// Helper function to read next character in the input
void readChar(Lexer *l);

// Helper function to get the next token in a lexer
void nextToken(Lexer *l, Token *t);

// Helper function to create a new Token
void newToken(int typ, char *lit, Token *t);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token{

	string TokenType;
	
	string Literal;

} Token;


const string ILLEGAL = "ILLEGAL";
const string EOF = "EOF";

// Identifiers + Literals
const string INDENT = "INDENT";
const string INTEGER = "INT";

// Operators
const string ASSIGN = "ASSIGN";
const string PLUS = "PLUS";

// Delimeters
const string COMA = "COMA";
const string SEMICOLON = "SEMICOLON";
const string LPAREN = "LPAREN";
const string RPAREN = "RPAREN";
const string LBRACE = "LBRACE";
const string RBRACE = "RBRACE";

// Keywords
const string FUNCTION = "FUNCTION";
const string LET = "LET";


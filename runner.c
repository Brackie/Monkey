#include <stdio.h>
#include <string.h>
#include "monkey.h"

int tests_run = 0;
#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


char *input = "let five = 5; let ten = 10; let add = fn(x, y) {x + y;}; let result = add(five, ten);";

Token tokens[] = {
	{LET, "let"},
	{IDENTIFIER, "five"},
	{ASSIGN, "="},
	{INTEGER, "5"},
	{SEMICOLON, ";"},
	{LET, "let"},
	{IDENTIFIER, "ten"},
	{ASSIGN, "="},
	{INTEGER, "10"},
	{SEMICOLON, ";"},
	{LET, "let"},
	{IDENTIFIER, "add"},
	{ASSIGN, "="},
	{FUNCTION, "fn"},
	{LPAREN, "("},
	{IDENTIFIER, "x"},
	{COMMA, ","},
	{IDENTIFIER, "y"},
	{RPAREN, ")"},
	{LBRACE, "{"},
	{IDENTIFIER, "x"},
	{PLUS, "+"},
	{IDENTIFIER, "y"},
	{SEMICOLON, ";"},
	{RBRACE, "}"},
	{SEMICOLON, ";"},
	{LET, "let"},
	{IDENTIFIER, "result"},
	{ASSIGN, "="},
	{IDENTIFIER, "add"},
	{LPAREN, "("},
	{IDENTIFIER, "five"},
	{COMMA, ","},
	{IDENTIFIER, "ten"},
	{RPAREN, ")"},
	{SEMICOLON, ";"},
	{EOF, ""}
};

int testNextToken(){
	Token t;
	Lexer l; 
	newLexer(&l, input);
	int i = 0;
	int n = sizeof(tokens) / sizeof(tokens[0]);
	for (int i = 0; i < n; ++i)
	{
		nextToken(&l, &t);
		_assert(t.tokenType == tokens[i].tokenType);
		_assert(*t.literal == *tokens[i].literal);
	}
	return 0;
}

int all_tests() {
    _verify(testNextToken);
    return 0;
}

int main(int argc, char **argv) {
    int result = all_tests();
    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
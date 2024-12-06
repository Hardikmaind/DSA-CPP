#pragma once
#include "lexer.h"

class Parser {
public:
    Parser(Lexer &lexer);
    int parseExpression();

private:
    Lexer &lexer;
    Token currentToken;

    void advance();
    int parseTerm();
};

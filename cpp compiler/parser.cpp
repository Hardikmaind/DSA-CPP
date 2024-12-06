#include "parser.h"
#include <stdexcept>

Parser::Parser(Lexer &lexer) : lexer(lexer) {
    advance();
}

void Parser::advance() {
    currentToken = lexer.getNextToken();
}

int Parser::parseExpression() {
    int result = parseTerm();

    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        TokenType op = currentToken.type;
        advance();
        int right = parseTerm();
        if (op == TokenType::PLUS) {
            result += right;
        } else if (op == TokenType::MINUS) {
            result -= right;
        }
    }

    return result;
}

int Parser::parseTerm() {
    if (currentToken.type != TokenType::NUMBER) {
        throw std::runtime_error("Expected a number");
    }

    int value = std::stoi(currentToken.value);
    advance();
    return value;
}

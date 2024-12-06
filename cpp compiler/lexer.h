#pragma once
#include <string>

enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    END
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string &source);
    Token getNextToken();

private:
    std::string source;
    size_t position;
};

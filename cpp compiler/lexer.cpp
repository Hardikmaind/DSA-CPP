#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string &src) : source(src), position(0) {}

Token Lexer::getNextToken() {
    while (position < source.size()) {
        char current = source[position];

        if (std::isdigit(current)) {
            std::string number;
            while (position < source.size() && std::isdigit(source[position])) {
                number += source[position++];
            }
            return Token{TokenType::NUMBER, number};
        }
        
        if (current == '+') {
            position++;
            return Token{TokenType::PLUS, "+"};
        }
        
        if (current == '-') {
            position++;
            return Token{TokenType::MINUS, "-"};
        }

        position++; // Skip any other characters (like spaces)
    }
    return Token{TokenType::END, ""};
}

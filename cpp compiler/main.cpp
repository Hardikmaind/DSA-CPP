#include <iostream>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string input;
    std::cout << "Enter an expression (e.g., 3 + 4 - 2): ";
    std::getline(std::cin, input);

    Lexer lexer(input);
    Parser parser(lexer);

    try {
        int result = parser.parseExpression();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

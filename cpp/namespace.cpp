#include <iostream>
//in namespace we can define functions, classes, variables, etc. and can use them in the main program without any conflict. with the help of namespace, we can define the same name functions, classes, variables, etc. in different namespaces.we can use name spaces with the help of the scope resolution operator(::).
namespace Custom {
    void f1(int n) {
        for (int i = 1; i <= n; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int N;
    std::cout << "Enter a number: ";
    std::cin >> N;

    Custom::f1(N);

    return 0;
}

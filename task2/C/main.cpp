#include "main.h"

void FirstFunction() {
    std::cout << "I am the first function" << std::endl;
}

void ThirdFunction() {
    std::cout << "I am the third function" << std::endl;
}

int main() {
    FirstFunction();
    SecondFunction();
    ThirdFunction();
}

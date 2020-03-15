#include "main.h"

int ThirdFunction() {
    return 3;
}

int main() {
    std::cout << FirstFunction() << std::endl;
    std::cout << SecondFunction() << std::endl;
    std::cout << ThirdFunction() << std::endl;
}

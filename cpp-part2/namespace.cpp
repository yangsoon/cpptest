#include <iostream>

namespace test1 {
    void echo() {
        std::cout << "test1 echo" << std::endl;
    }
}

namespace test2 {
    void echo() {
        std::cout << "test2 echo" << std::endl;
    }
}
void echo() {
    std::cout << "main echo" << std::endl;
}
int main() {
    test1::echo();
    test2::echo();
    ::echo();
}
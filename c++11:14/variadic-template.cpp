#include <iostream>

void printX() {
    std::cout << std::endl;
}

template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
    std::cout << firstArg << std::endl;
    std::cout << "left:" << sizeof...(args) << "params" << " ";
    // args 会被分为2部分 一部分是第一个参数 第二部分是args...
    printX(args...);
}

void printf(const char *s) {
    while(*s) {
        if(*s=='%'&&*(++s)!='%')
            throw std::runtime_error("invalid format string");
        std::cout << *s++;
    }
}

//printf
template<typename T, typename... Args>
void printf(const char* s, T value, Args... args) {
    while(*s) {
        if(*s=='%'&&*(++s)!='%') {
            std::cout << value;
            printf(++s, args...);
            return;
        }
        std::cout << *s++;
    }
    throw std::runtime_error("invalid format string");
}

int maximum(int n) {return n;}

template<typename...Args>
int maximum(int n, Args... args) {
    return std::max(n, maximum(args...));
}

int main() {
    printX(1,2,3,"asa");
    std::cout << maximum(1,2,3,4) << std::endl;
}
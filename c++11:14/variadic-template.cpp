#include <iostream>
using namespace std;

void printX() {

}

template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
    cout << firstArg << endl;
    cout << "left:" << sizeof...(args) << "params" << endl;
    // args 会被分为2部分 一部分是第一个参数 第二部分是args...
    printX(args...);
}

int main() {
    printX(1,2,3,"asa");
}
// 数量不定的模板参数 c++ 11
#include <iostream>

void print() {
    std::cout<<std::endl;
}

// 将调用者传进的n个参数 分为1个和1个packet(n-1个) 然后递归下去 直到没有参数的时候 调用上面的无参函数
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    // sizeof...(args) 表示还剩下 多少个参数
    std::cout << firstArg << " left:" << sizeof...(args) << ' ';
    print(args...);
}

int main() {
    print(1,2,'a',1.0);
}
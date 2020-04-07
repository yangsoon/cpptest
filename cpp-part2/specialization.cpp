#include <cstdlib>
#include <iostream>

// 通用模板泛化对所以的特定类型不适用 所以需要特化

// 模板泛化
template<class T>
struct my_hash{
    T operator() (T x) const {return x;}
};
// 声明特化之前需要有一个特化版本 不然的话编译器不知道你要特化什么
// 模板特化 如果你在my_hash里面指定了具体的类型 那么在template里面就不用再写类型
// 特化了哪一部分就直接写在模板变量的<>里面 不用写在template里 
template<>
struct my_hash<char>{
    char operator() (char x) const {return x;}
};

template<>
struct my_hash<long>{
    long operator() (long x) const {return x;}
};

template<>
struct my_hash<int>{
    int operator() (int x) const {return x;}
};

int main() {
    std::cout << my_hash<long>()(1000) << std::endl;
    std::cout << my_hash<char>()('a') << std::endl;
    std::cout << my_hash<int>()(10) << std::endl;
    std::cout << my_hash<double>()(1.0) << std::endl;
}
#include <iostream>
#include "../c++/string.h"

using namespace std;

template<typename T>
class complex {
public:
    complex(T r = 0, T i = 0) :re(r), im(i){};
    // const 只能修饰成员函数 不能修饰全局函数
    // const 表示成员函数不会修改数据 只会读取数据
    // 其中const会影响函数签名
    // #1 当成员函数的const和non-const版本都存在的时候
    // const对象只能调用const版本
    // non-const对象只能调用non-const版本
    T real() const {return re;}
    T imag() const {return im;}
private:
    T re, im;
};

int main() {
    const String str("test");
    // 'this' argument to member function 'print' has type 'const String', but function is not marked const
    // str.print(); // 该行报错 因为str是const表示这个对象不会修改成员变量 但是print函数没有被const修饰 有可能会修改成员变量
                    // 所以导致了错误
}
#include <iostream>
using namespace std;

// 如果你定义了一个ctor 编译器就不会给你一个默认的ctor
// 如果强制加上一个=default就会重新获取一个默认的ctor
class Zoo {
public:
    Zoo(int i1, int i2): d1(i1), d2(i2) {}
    // Big three(三巨头) 函数包括 构造函数 拷贝构造 拷贝赋值 析构函数这3种
    // 这些函数有个特点 编译器会为这些函数加上默认版本 除非自己定义
    Zoo(const Zoo&) = delete;
    // 右值引用
    Zoo(Zoo&&) = default;
    Zoo& operator=(const Zoo&) = default;
    Zoo& operator=(const Zoo&&) = delete;
    virtual ~Zoo(){}
private:
    int d1, d2;
};

// =default 只能用在Big Three上 
// =delete 可以用在任何函数上
// (=0 只能用在纯虚函数上)
class Foo {
public:
    Foo(int i):_i(i) {}
    Foo() = default;
    Foo(const Foo& x): _i(x._i){}
    // Foo(const Foo&) = default;
    // Foo(const Foo&) = delete;

    // 因为已经有了用户定义的版本 如果再指定 default的话 就还是错误 定义之后再delete也是会报错的
    Foo& operator=(const Foo& x){_i=x._i;return *this;}
    // Foo& operator=(const Foo& x) = default; error
    // Foo& operator=(const Foo& x) = delete; error

    // 成员函数不能使用default 因为没有默认的函数操作
    // void func1() = default; error
    void func2() = delete;

    // 析构函数 default和 delete不能并存 显然会出现错误
    // ~Foo() = delete; error
    ~Foo() = default;
private:
    int _i;
};

// 如果没有声明ctor编译器会有一个默认的版本
// 如果声明了一个ctor 那么编译器就不会产生默认版本
// 如果你定义 Test t 那么就会报错 因为没有对应的ctor
class Test {
public:
    Test(int a) {}
};

struct NoCopy {
    NoCopy() = default;
    // no-copy
    NoCopy(const NoCopy&) = delete;
    // no assignment
    NoCopy& operator=(const NoCopy&) = delete;
    ~NoCopy() = default;
};

struct NoDtor {
    NoDtor() = default;
    ~NoDtor() = delete;
};

// 不允许被一般的函数调用赋值 但是可以被友元函数和member调用
struct PrivateCopy{
private:
    PrivateCopy(const PrivateCopy&);
    PrivateCopy& operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};

int main() {
    Foo f;
    // Test t; error

    // 错误 因为d早晚要离开作用域 无法调用析构函数所以报错
    // NoDtor d; 
    NoDtor* d = new NoDtor();
    // 错误 因为无法调用析构函数
    // delete d;


}
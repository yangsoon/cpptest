#include <iostream>
#include <cstdlib>

using namespace std;

class Bad{};
// 一个对象new的时候先调用new分配内存 然后调用构造函数 如果ctor出现异常 就调用delete来释放内存防止内存泄露
// 仅限g2.9 该部分了解即可
class Foo {
public:
    Foo(){cout<<"Foo::Foo()"<<endl;}
    // 故意抛出异常 测试调用重载的delete
    Foo(int min) {cout<<"Foo::Foo(min)"<<endl; throw Bad();}

    // #1 一般的new重载
    void* operator new(size_t size) {
        return malloc(size);
    }

    // #2 placement new
    // Foo* p = new(200)Foo; 这样调用
    void* operator new(size_t size, long extra) {
        return malloc(size+extra);
    }

    // 对应#1
    void operator delete(void* , size_t) {
        cout << "operator delete(void*, size_t)" << endl;
    }

    // 对应#2 
    void operator delete(void* , long) {
        cout << "operator delete(void*, long)" << endl;
    }   
};

int main() {
    Foo* p1 = new(300)Foo(1);
}
#include "string.h"
#include <iostream>
using namespace std;

int main() {
    // 前两个离开作用域的时候会自动调用析构函数 c++会自动析构栈上的对象 函数退出的时候会析构
    String s1;
    // static在作用域结束后仍然存在 直到程序结束
    static String s2("hello");
    
    s1 = s2;
    // 但是*p是在堆上分配空间 需要手动释放
    // new 表示先分配内存 然后调用ctor
    String* p = new String("hello");
    // delete 释放了堆上的指针 指针释放之后系统会自动调用析构函数 释放p中的对象 
    // 先调用析构函数dtor 然后释放内存 先调用dtor析构内部申请的内存
    // String::~String(p);
    // operator delete(p); => free(p);
    delete p;

    // 以s1为蓝本 拷贝构造 
    String s3(s1);
    cout << s3 <<endl;
    // 拷贝赋值  编译器会 实现拷贝赋值 拷贝构造 默认操作是浅拷贝是危险的
    s3 = s2;
}
#include <iostream>
using namespace std;

// 每个包含虚函数的对象在内存中都包含一个虚指针，这个指针是指向一个虚表 这个虚表可以
// 看成一个数组 用来存这个对象的虚函数列表 然后依据虚函数的下标位置进行调用函数执行
// (*p->vptr[n])(p) 类似这样的调用

// 注意每一个成员函数都有一个默认的参数 就是调用这个成员函数的对象指针 this 
// 调用成员函数的时候 其实就是调用成员函数 然后传递this进去

// 一个类的对象在内存中含有的是自己的成员数据 不包括成员函数 成员函数可以认为
// 多个对象是共享的，成员函数单独被放在一个内存区域中
class A {
public:
    virtual void vfunc1() { cout << "call A::vfunc1()" << endl;}
    virtual void vfunc2() { cout << "call A::vfunc2()" << endl;}

    void func1() {cout << "call A::func1()" << endl;}
    void func2() {cout << "call A::func2()" << endl;}
private:
    int m_data1;
    int m_data2;
};

class B: public A {
public:
    virtual void vfunc1() { cout << "call B::vfunc1()" << endl;}

    void func2() {cout << "call B::func2()" << endl;}
private:
    int m_data3;
};

class C: public B {
public:
    virtual void vfunc1() { cout << "call C::vfunc1()" << endl;}

    void func2() {cout << "call C::func2()" << endl;}
private:
    int m_data1;
    int m_data4;
};

// C++ 调用函数时候 进行动态绑定的三个条件
// #1 通过指针调用
// #2 调用虚幻函数
// #3 有没有做up-cast转型 即 子类指针转换为父类指针
int main() {
    B b;
    // #1 这里做了强制类型转换但是调用的时候没有使用指针
    // 是A的对象 所以是静态绑定 直接使用a的虚函数
    // 汇编后的代码调用函数时使用的call 后面跟着具体地址
    // 所以是静态绑定
    A a = (A) b;
    a.vfunc1();

    // #2 这里虽然转换成了指针 但是仍然是A的指针 指向的是a的虚函数
    A* pa = &a;
    pa->vfunc1();

    // #3 这里满足动态绑定的3个条件 所以调用的还是b的虚函数
    // 类似于调用了 (*p->vptr[n])(p)
    // 先从对象的虚表中取出虚函数 然后把p这个指针对象传递进去 所以需要指针来进行调用
    pa = new B;
    pa->vfunc1();
}
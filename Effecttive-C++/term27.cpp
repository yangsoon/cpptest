// 1. (T)expression  C风格的转型
// 2. T(expression) 函数风格的转型
// 2种风格的转型 均称为旧式转型

// C++ 提供4个新式转型
// 1. 用于C++对象的常量转型
// const_cast<T>(expression)
// 2. 主要用于执行安全向下转型
// dynamic_cast<T>(expression)
// 3. 执行低级转型(将一个int指针指向int)
// reinterpret_cast<T>(expression)
// 4. 强迫隐式转换 例如 non-const 2 const; int 2 double
// static_cast<T>(expression)

// class Wight {
// public:
//     explicit Wight(int size);
// };

// void doSomeWork(const Wight& w);

// // 将int型转换为wight 函数风格的转型更适合
// void when_use_old_cast() {
//     // 1. 函数风格的转型
//     doSomeWork(Wight(15));
//     // 2. C++风格的转型 static_cast用于隐式转换
//     doSomeWork(static_cast<Wight>(15));
// }

#include <iostream>
using std::endl;
using std::cout;

class Window {
public:
    virtual void onResize() {
        l = 10;
    }
protected:
    int l,w;
};

class SpecialWindow: public Window {
public:
    void onResize() {
        // 当期望在子类中使用父类的方法时候 只能按照下面的方式调用 这样才能修改子类的成员
        // 函数调用会作用在 *this上
        Window::onResize();
        // 下面是错误的执行方法 函数只会作用在一个副本上 不会修改子类对象的成员属性
        // static_cast<Window>(*this).onResize();
        cout << l << endl;
    }
};

int main() {
    SpecialWindow sw;
    sw.onResize();
}
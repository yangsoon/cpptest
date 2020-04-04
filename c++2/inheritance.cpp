#include <iostream>
using namespace std;

class Base{
public:
    Base() {
        cout << "Base ctor" << endl;
    }
    ~Base() {
        cout << "Base dtor" << endl;
    }
};

// 子类创建的时候 先调用父类的构造函数 然后调用子类的构造函数
// 子类析构的时候 先调用子类的析构 然后调用父类的析构函数
// 复合模式一致
class Derived: public Base{
public:
    Derived() {
        cout << "Derived ctor" << endl;
    }
    ~Derived() {
        cout << "Derived dtor" << endl;
    }
};

void test() {
    cout << "...Create..." << endl;
    Derived d;
    cout << "...Destroy..." << endl;
}

int main(){
    test();
}
#include <iostream>
using namespace std;
// 该节配合上篇关于内存讲解部分一起食用
// 可以重载 全局new delete new[] delete[]
// 重载成员函数的new delete new[] delete[] 用于内存管理 内存池

// #1 new和malloc的区别 对象在调用new的时候 是先调用malloc申请一片内存 然后调用ctor进行对象初始化
// 对象在调用delete的时候 是先调用dtor 然后释放内存

class Foo {
public:
    void* operator new(size_t);
    void operator delete(void*, size_t);

    void* operator new[](size_t);
    void operator delete[](void*, size_t);
};

int main() {
    // #1 当调用new的时候 实际上执行流程是
    // try {
    //     #1 调用全局new申请一片内存 返回一个指针指向这块内存
    //     void* mem = operator new(sizeof(Foo));
    //     #2 将mem转化为Foo*类型指针
    //     Foo* p = static_cast<Foo*>(mem);
    //     #3 调用构造函数
    //     p->Foo();
    // }
    Foo *p =new Foo;
    // #2 调用delete的时候
    // p->~Foo(); // #1先调用析构函数
    // operator delete(p) // #2调用全局delete释放内存空间
    delete p;

    // #1 当调用new的时候 实际上执行流程是
    // try {
    //     #1 调用全局new申请一片内存 返回一个指针指向这块内存 内存大小为数组大小加上前后缀用来表示占用空间大小 具体看上篇内容
    //     void* mem = operator new(sizeof(Foo)*N+4);
    //     #2 将mem转化为Foo*类型指针
    //     Foo* p = static_cast<Foo*>(mem);
    //     #3 调用构造函数
    //     p->Foo(); 调用N次
    // }
    const int N = 9;
    Foo *pn =new Foo[N];
    // #2 调用delete的时候
    // p->~Foo(); // #1先调用析构函数 调用N次
    // operatnor delete(p) // #2调用全局delete释放内存空间
    delete pn;  
}
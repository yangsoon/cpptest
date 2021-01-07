// 类中带指针 需要自己实现拷贝构造和拷贝赋值
#ifndef __MYSTRING__
#define __MYSTRING__

#include <string.h>
#include <iostream>
class String {
public:
    String(const char* cstr=0);
    // 只要类带着指针一定要实现 拷贝构造和拷贝赋值 

    String(const String& str);
    String& operator = (const String& str);
    ~String();
    char* get_c_str() const {return m_data;}

    void print() {
        std::cout << m_data << std::endl;
    }
private:
    // 使用指针 因为成员大小不确定
    char* m_data;
};

// 有指针就必须要动态分配内存，所以在析构的时候需要释放 不然会导致内存泄露
// 在头文件，函数声明中设置默认值，在函数实现部分，应该把默认值去掉
// 默认值只在头文件中，或者只在实现，只能有一处 建议只在头文件中写
inline 
String::String(const char* cstr) {
    if(cstr) {
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

// 使用默认的拷贝构造的时候 c++会一个bit一个bit的赋值：
// String b = String("hello"); String a = String("world");
// 对于 b(a) 因为a和b只有指针变量，那么就会使得b中的指针指向a中的指针(存在危险) 那么"hello"这部分就会泄露 
inline
String::String(const String& str) {
    // 申请一片空间 然后把内容拷贝进去 属于深拷贝
    // 系统默认行为的复制指针 属于浅拷贝
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
}

// 拷贝赋值 b = a
// 首先 需要把 b清空 然后重新分配一块和a一样大的内存 将a拷贝过来
inline
String& String::operator=(const String& str) {
    // 检测是不是自己 如果没有这一步 可能会出现错误 影响效率 因为第一个动作是把自己杀掉，如果a = a，那么没有东西可以拷贝了
    if(this==&str) {
        return *this;
    }
    // #1 把自己的内存空间删掉
    delete[] m_data;
    // #2 分配一个足够的空间
    m_data = new char[strlen(str.m_data)+1];
    // #3 深拷贝，把a拷贝过来
    strcpy(m_data, str.m_data);
    return *this;
}

inline
String::~String(){
    // new[] 要搭配 delete[] 调用delete[]的时候系统才知道是析构数组 如果只调用delete p的话 那么系统
    // 就析构并删除第一个数组指针对象 然后回收整个内存块 因为还有2个指针所以删除后造成了内存泄露(想象p执行的内存区域是一个数组)
    // 每个数组都是一个指针指向申请的内存 如果只回收一个就会造成其他的泄露
    // 上述是针对于带有指针的对象，如果不带有指针的对象没有影响
    // eg: Complex* p = new Complex[3] String* s = new String[3];
    // 在p指向的内存空间有数字记录大小 方便删除
    // p和s是数组 析构的时候需要析构3次 
    delete[] m_data;
}

inline
std::ostream& operator << (std::ostream& os, const String& str) {
    return os << str.get_c_str();
}

#endif

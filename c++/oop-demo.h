#ifndef __OOPDEMO__
#define __OOPDEMO__

#include <string>
#include <iostream>

// 继承要搭配虚函数 函数继承的函数继承的是调用权
class Shape {
public:
    // 纯虚函数 要求子类必须重新定义 override
    virtual void draw() const = 0;

    // 虚函数 希望子类重新定义 并且有默认行为
    virtual void error(const std::string& msg);

    // 非虚函数 不希望子类去定义
    int objectID() const;

private:
    double l;
};

// 继承
class CDocument {
public:
    void onOpenFile() {
        std::cout << "check file status" << std::endl;
        Serialize();
        std::cout << "close file" << std::endl;
    }

    virtual void Serialize() {};
};

class MyDocument : public CDocument{
public:
    virtual void Serialize() {
        std::cout << "MyDocument Serializing..." << std::endl;
    }
};

// 委托+继承
#endif
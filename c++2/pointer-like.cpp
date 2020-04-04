#include <iostream>
using namespace std;

// 智能指针
template<class T>
class my_shared_ptr {
public:
    T& operator*() const {
        return *px;
    }

    T* operator->() const {
        return px;
    }

    my_shared_ptr(T* p): px(p) {}
private:
    T* px;
    long* pn;
};
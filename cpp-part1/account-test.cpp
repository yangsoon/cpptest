#include "account.h"
#include <iostream>

class stone {
public:
    stone(double w = 0, double h = 0): w(w), h(h) {}
    // 这里必须是const成员函数 因为在下面的min函数模板中 比较的两个对象a和b都是const的类型 运算符重载是作用在a身上 这时候调用
    // 调用 < 符号的a必须调用const成员函数
    bool operator < (const stone& cmp) const {
        if(w*h<cmp.h*cmp.w) {
            return true;
        }
        return false;
    }
    double getW() const {return w;}
private:
    double w,h;
};

//  函数模板
template<typename T>
inline 
const T& min(const T& a, const T& b) {
    return a < b? a: b;
}

int main() {
    // 通过类调用静态函数
    Account::set_rate(5.0);
    std::cout<< Account::m_rate << std::endl;
    Account a;
    // 通过对象访问
    a.set_rate(7.0);
    std::cout << a.m_rate << std::endl;

    stone s1(1,2);
    stone s2(2,3);

    s1 = min(s1, s2);
    std::cout << s1.getW() << std::endl;
}
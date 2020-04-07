#include <iostream>
using namespace std;


class Fraction{
public:
    // non-explicit-one-argument ctor (非显式的一个参数)
    Fraction(int num, int den = 1): m_num(num), m_den(den) {}
    // # 1 转换函数 把分数当成一个double类型 转换类型
    // 表示分数可以转换为double 
    // 转换函数没有返回类型 因为在函数名上就说明了转换成什么类型
    // 转换函数不会改变类型 
    operator double() const {
        return (double)(m_num)/m_den;
    }


private:
    int m_num; // 分子
    int m_den; // 分母
};

class Fraction1{
public:
    // non-explicit-one-argument ctor (非显式的一个参数)
    // 这样的构造函数可以使得 编译器可以调用non-explicit-one-argument ctor将4转换为Fraction1
    Fraction1(int num, int den = 1): m_num(num), m_den(den) {}

    Fraction1 operator + (const Fraction1& f) {
        return Fraction1(m_num+f.getNum(), m_den+f.getDen());
    }

    int getNum() const {return m_num;}
    int getDen() const {return m_den;}
private:
    int m_num; // 分子
    int m_den; // 分母
};

class Fraction2{
public:
    // 转换函数 vs non-explicit-one-argument ctor (非显式的一个参数)
    // 如果出现了 Fraction2 = f + 4的情况 
    // 编译器不知道是选择将4转换为Fraction还是将Fraction转换为double之后加4再转为int再转为Fraction
    // 因此编译器会报错 二义性 
    // 解决方法看 Fraction3
    Fraction2(int num, int den = 1): m_num(num), m_den(den) {}

    Fraction2 operator + (const Fraction2& f) {
        return Fraction2(m_num+f.getNum(), m_den+f.getDen());
    }

    operator double() const {
        return (double)(m_num)/m_den;
    }

    int getNum() const {return m_num;}
    int getDen() const {return m_den;}
private:
    int m_num; // 分子
    int m_den; // 分母
};

class Fraction3{
public:
    // explicit 为了解决2的问题 表示我这个构造函数只能用来作为构造函数 不能用于类型转换
    explicit Fraction3(int num, int den = 1): m_num(num), m_den(den) {}
    Fraction3 operator + (const Fraction3& f) {
        return Fraction3(m_num+f.getNum(), m_den+f.getDen());
    }

    operator double() const {
        return (double)(m_num)/m_den;
    }

    int getNum() const {return m_num;}
    int getDen() const {return m_den;}
private:
    int m_num; // 分子
    int m_den; // 分母
};


int main() {
    // # 1 转换函数
    Fraction f(3,5);
    double d = 4 + f; // 默认调用operator double将f转换为double
    cout << "4 + f(3,5) = " << d << endl;

    // # 2 non-explicit-one-argument ctor
    Fraction1 f1(3,5);
    // 调用non-explicit-one-argument ctor将4转换为Fraction1
    // 然后调用 operator+
    Fraction1 d1 = f1 + 4; 
    cout << "d1 = f(" << d1.getNum() << ',' << d1.getDen() << ')' << endl;

    // # 3 转换函数 vs non-explicit-one-argument ctor 
    Fraction2 f2(3,5);
    // use of overloaded operator '+' is ambiguous (with operand types 'Fraction2' and 'int')
    // Fraction2 d2 = f2 + 4;  // 报错 因为二义性

    // #4 explicit 关键字
    Fraction3 f3(3,5);
    // // no viable conversion from 'double' to 'Fraction3'
    // Fraction3 d3 = f3 + 4; // 报错 因为无法将4转换为Fraction3

}
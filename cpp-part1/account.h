#ifndef __ACCOUNT__
#define __ACCOUNT__

class Account {
public:
    // 静态数据只有一份 不属于对象 声明
    static double m_rate;
    // 静态函数 在内存只有一份
    // 静态函数没有this 只能存取静态数据！！
    static void set_rate(const double x) {
        m_rate = x;
    }
};
// 静态数据一定要在类外面设初始化 定义=>类型+类::静态变量名
// 类的静态数据必须要在外面定义一下这样才能给初值
double Account::m_rate = 0.8;

#endif
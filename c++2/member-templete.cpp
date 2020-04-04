template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    //  T1 first 表示调用默认的无参构造函数 和 T1 first() 表示声明了一个返回T1的函数
    T1 first;
    T2 second;
    pair(): first(T1()), second(T2()){}
    pair(const T1& a, const T2& b): first(a), second(b){}

    // 成员模板 子类组成的类型对 可以被复制给父类组成的类型对
    template<class U1, class U2>
    pair(const pair<U1, U2>& p): first(p.first), second(p.second){}
};

class Base1{};
class Fish: public Base1{};

class Base2{};
class Duck: public Base2{};


int main() {
    pair<Fish, Duck> p1;
    pair<Base1, Base2> p2(p1);

    Base1* b = new Fish;  // up-cast

}
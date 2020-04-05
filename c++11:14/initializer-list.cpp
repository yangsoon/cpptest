#include <iostream>
// #include <initializer_list>
using namespace std;

// 支持函数接受任意个数的参数
// vector<int> v{1,2,3,4,5,6};
// 的实现原理就是将{1,2,3,4,5}包装成initializer_list 调用参数是initializer_list的ctor
void print(initializer_list<int> vals) {
    for (auto p = vals.begin(); p!=vals.end(); ++p) {
        cout << *p << ' ';
    }
    cout << endl;
}

class P{
public:
    P(int a, int b){
        cout << "P(int a,int b)=" <<a << ' ' << b << endl;
    };
    P(initializer_list<int> initlist) {
        cout << "P(initializer_list<int>)=";
        for(auto i : initlist) {
            cout << i << ' ';
        }
        cout << endl;
    }
};

int main() {
    print({1,2,3,4,5,6,7});

    P p(77,5);
    P q{77,5};
    P r{77,5,23};
    // 调用构造函数
    P s = {77, 5};
}
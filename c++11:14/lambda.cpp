#include <iostream>
#include <vector>
using namespace std;

int main () {
    // 函数对象
    auto l = []{
        cout << "hello lambda" << endl;
    };
    l();


    vector<int> v{1,2,31,4,50};
    int x = 1, y = 8;
    // 用lambda去掉区域内的数据
    v.erase(remove_if(
        v.begin(),
        v.end(),
        [x,y](int n) {return x < n && n < y;}
    ), v.end());

    for(auto i: v) {
        cout << i << ' ';
    }
    cout << endl;
}
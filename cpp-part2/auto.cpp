#include<vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);

    vector<int>::iterator ite;
    ite = v.begin();

    // #2 ite1的类型太长 使用auto可以被自动推导
    auto ite1 = v.end();

    // # 3错误
    // auto ite2;
    // ite2 = v.end();
}



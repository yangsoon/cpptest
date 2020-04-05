#include <iostream>
#include <vector>

// for (dec1:coll) {
//     statement
// }

int main() {
    for(int i : {1,2,3,4,5,1,3}) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int a[5] = {1,2,3,4,5};
    std::vector<int> v(a, a+5);
    // # 1 这个是传值 
    for(auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // # 1 这个是传引用 会修改原vector
    for(auto& e: v) {
        e *= 3;
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
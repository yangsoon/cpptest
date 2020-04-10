#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using std::string;

long get_a_target_long() {
    long target = 0;
    std::cout << "target(0~" << RAND_MAX << "): ";
    std::cin >> target;
    return target; 
}

int compareLongs(const void *a, const void* b) {
    return (*(long*)a - *(long*)b);
}

namespace test_array {
    const int ASIZE = 1000;
    void test_array() {
        std::cout << "\ntest_array()...... \n";
        std::array<long, ASIZE> c;
        clock_t timeStart = clock();    
        for(long i = 0; i < ASIZE; i++) {
            c[i] = rand();
        }
        std::cout << "milli-seconds: " << (clock()-timeStart) << std::endl;
        std::cout << "array.size(): " << c.size() << std::endl;
        std::cout << "array.front(): " << c.front() << std::endl;
        std::cout << "array.back(): " << c.back() << std::endl;
        // 数组在内存的起点地址
        std::cout << "array.data(): " << c.data() << std::endl;
        long target = get_a_target_long();
        timeStart = clock();
        qsort(c.data(), ASIZE, sizeof(long), compareLongs);
        long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
        std::cout << "qsort()+bsearch(), milli-seconds: " << (clock()-timeStart) << std::endl;
        if(pItem!=NULL) {
            std::cout << "found, " << *pItem << std::endl;
        } else {
            std::cout << "not found!" << std::endl;
        }
    }
}
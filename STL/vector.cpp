#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <cstdio>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

string get_a_target_string() {
    long target = 0;
    char buf[10];
    std::cout << "target (0~" << RAND_MAX << ")";
    std::cin >> target;
    snprintf(buf, 10, "%ld", target);
    return string(buf);
}


int compareStrings(const void* a, const void* b) {
    if(*(string*)a > *(string *)b) {
        return 1;
    } else if(*(string*)a < *(string *)b){
        return -1;
    } else {
        return 0;
    }
}

namespace test_vector {
    void test_vector(long& value) {
        cout << "\ntest_vector()....\n";
        vector<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for(long i = 0; i < value; i++) {
            try {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            } catch(exception& p){
                cout << "i=" << i << " " << p.what() << endl;
                abort();
            }
        }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;
        cout << "vector.size():" << c.size() << endl;
        cout << "vector.front():" << c.front() << endl;
        cout << "vector.back():" << c.back() << endl;
        cout << "vector.data():" << c.data() << endl;
        cout << "vector.capacity():" << c.capacity() << endl;
        string target = get_a_target_string();
        {
            timeStart = clock();
            auto pItem = std::find(c.begin(), c.end(), target);
            cout << "find(), milli-seconds:" << (clock()-timeStart) << endl;
            if(pItem!=c.end()) {
                cout << "found, " << *pItem << endl;
            } else {
                cout << "not found!" << endl;
            }
        }

        {
            timeStart = clock();
            sort(c.begin(), c.end(), target);
            string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStrings);
            cout << "sort()+bsearch(), milli-seconds:" << (clock()-timeStart) << endl;
            if(pItem!=NULL) {
                cout << "found, " << *pItem << endl;
            } else {
                cout << "not found!" << endl;
            }
        }
    }
};
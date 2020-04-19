#include <iostream>
#include <cstring>
using namespace std;
class Word {
public:
    Word(const char *s) {
        cout << "const char *s" << endl;
        _s = new char[strlen(s)+1];
        strcpy(_s, s);     
    }
    // Word(const Word &w) {
    //     cout << "const Word &w" << endl;
    //     if(strlen(_s)!=0) {
    //         delete[] _s;
    //     }
    //     _s = new char[strlen(w.getS())+1];
    //     strcpy(_s, w.getS());
    // }
    ~Word() {
        cout << "dctor" << endl;
        delete[] _s;
    }
    char* getS() const {
        return _s;
    }
private:
    char* _s;
};

int main() {
    Word non("hello");
    // #1 对于有指针成员的类 需要自己实现一个拷贝构造函数 不然会出现问题
    Word test = non;
    non.getS();
}
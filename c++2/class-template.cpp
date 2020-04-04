#include <iostream>
using namespace std;

template<typename T>
class complex {
public:
    complex(T r = 0, T i = 0) :re(r), im(i){};
    // complex& operator += (const complex& com);
    T real() {return re;}
    T imag() {return im;}
private:
    T re, im;
};

int main() {
    complex<int> a(1,2);
    complex<double> b(1.1, 1.2);
}
#ifndef __TEMCOM__
#define __TEMCOM__

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

#endif
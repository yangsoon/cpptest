#include "templete-com.h"
#include <iostream>
using namespace std;

int main() {
    complex<double> cd(1.0, 2.0);
    complex<int> ci(3,4);
    cout << cd.imag() << endl; 
}
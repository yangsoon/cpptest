#include <iostream>
using namespace std;

class Point3d {
public:  
    virtual ~Point3d(){};
    float m;
    float n;
private:  
    static Point3d origin;
    float x,y,z;
};

int main() {

}
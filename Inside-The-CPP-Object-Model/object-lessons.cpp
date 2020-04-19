#include <iostream>
#include <cstdio>
using namespace std;

// c语言实现
#define DPoint3d_print(pd) printf("%g, %g, %g\n", pd->x, pd->y, pd->z);

typedef struct point3d{
    float x, y, z;
} Point3d;

void Point3d_print(const Point3d *pd) {
    printf("%g, %g, %g\n", pd->x, pd->y, pd->z);
}

// C++实现
// 成员函数并不出现在class object中
class Point3dCPP {
public:
    Point3dCPP(float x = 0.0, float y = 0.0, float z = 0.0): _x(x), _y(y), _z(z){};
    float getX() const {return _x;};
    float getY() const {return _y;};
    float getZ() const {return _z;};
private:
    float _x, _y, _z;
};

inline ostream& operator<< (ostream &os, const Point3dCPP &pd) {
    return os << "(" << pd.getX() << ", " 
            << pd.getY() << ", " << pd.getZ() << ")";
}

// C++继承
class Point {
public:
    Point(float x): _x(x) {};
    float getX() const {return _x;};
    virtual void test() {
        cout << "Point Test" << endl;
    }
private:
    float _x;
};

class Point2d : public Point {
public:
    Point2d(float x, float y): Point(x), _y(y) {};
    void test() {
        cout << "Point2d Test" << endl;
    }
private:
    float _y;
};

class Point3dOO: public Point2d {
public:
    Point3dOO(float x, float y, float z): Point2d(x, y), _z(z) {};
    float getZ() const {return _z;};
    void test() {
        cout << "Point3d Test" << endl;
    }
private:
    float _z;
};

inline ostream& operator<< (ostream &os, const Point3dOO &pd) {
    return os << "(" << pd.getZ() << ")";
}

// C++ 模板
template<typename T>
class Point3dT {
public:
    Point3dT(T x, T y, T z): _x(x), _y(y), _z(z) {};
    T getX() const {return _x;};
    T getY() const {return _y;};
    T getZ() const {return _z;};
private:
    T _x, _y, _z;
};

// C++ 模板
template<typename T, int dim>
class Point3dV {
public:
    Point3dV(T coords[dim]) {
        for(int i = 0; i < dim; i++) {
            _coords[i] = coords[i];
        }
    }

    T operator[](int i) const{
        assert(i<dim&&i>=0);
        return _coords[i];
    }

private:
    T _coords[dim];
};

template<typename T, int dim> 
inline ostream& operator<< (ostream &os, const Point3dV<T, dim> &pt) {
    os << "(";
    for(int i = 0; i < dim-1; i++){
        os << pt[i] << ", ";
    }
    os << pt[dim-1];
    os << ")";
    return os;
}

void test(Point a, Point *pointer, Point &reference) {
    // 一定调用Point的test因为 传入的子类会被强转为Point类型的对象
    a.test();

    // 选择调用什么函数取决于指针和引用指向的对象，引用也是一种指针
    (*pointer).test();
    reference.test();
}

int main() {
    // #1 C语言风格
    Point3d p3d = {1,2,3};
    Point3d_print(&p3d);

    // #2 CPP
    Point3dCPP p3dcpp(4,5,6);
    cout << p3dcpp << endl;

    // #3 C++继承
    Point3dOO p3doo(7,8,9);
    cout << p3doo << endl;

    // #4 C++模板
    int coord[2] = {10, 11};
    Point3dV<int, 2> p3dv(coord);
    cout << p3dv << endl;
    
    Point3dOO a(1,2,3);
    Point* b = &a;
    b->test();
    Point2d c(1,2);
    b = &c;
    b->test();

    ::test(a, &a, a);
}
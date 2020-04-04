// #1 模板参数个数上面的特化，
// 个数上的特化才会导致temlapte<>和 var<>中的typename的个数变化
template<typename A, typename B>
struct test {
    A a;
    B b;
};

template<typename B>
struct test<int, B>
{
    int a;
    B b;
};

// #2 模板参数类型的偏特
template <typename T>
class C {
public:
    T c;
};

// 如果声明为指针 那么就调用这个, 相当于特别声明了要传递给什么样的类型的参数
template <typename T>
class C<T*> {
public:
    T* c;
};


int main() {
    C<int> c1;
    C<int*> c2;
}
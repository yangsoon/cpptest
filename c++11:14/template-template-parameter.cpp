#include <vector>
using namespace std;

template<typename T,
        template<class>
        class Container
        >
class XCls{
private:
    Container<T> c;
public:
    XCls() {
        for(long i = 0; i < 100; ++i) {
            c.insert(c.end(), T());
        }
    }
};

template<typename T>
using Vec = vector<T, allocator<T>>;

class MyString{};

int main() {
    XCls<MyString, Vec> x;
}
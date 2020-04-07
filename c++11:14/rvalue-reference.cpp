#include <iostream>
#include <string>
using namespace std;

class MyString{
public:
    static size_t DCtor; // 记录默认构造的调用次数
    static size_t Ctor;  // 记录ctor的调用次数
    static size_t CCtor; // 记录copy ctor的调用次数
    static size_t CAsgn; // 记录copy asgn的调用次数
    static size_t MCtor; // 记录move-ctor的调用次数
    static size_t MAsgn; // 记录move-asgn的调用次数
    static size_t Dtor;  // 记录dtor的调用次数
private:
    char* _data;
    size_t _len;
    void _init_data(const char *s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
public:
    // 默认构造
    MyString(): _data(NULL), _len(0) {++DCtor;}
    // 构造 
    MyString(const char* p) : _len(strlen(p)) {
        ++Ctor;
        _init_data(p);
    }
    // 拷贝构造
    MyString(const MyString& str): _len(str._len) {
        ++CCtor;
        _init_data(str._data);
    }
    // copy assignment 拷贝赋值
    MyString& operator=(const MyString& str){
        ++CAsgn;
        if(this==&str) {
            return *this;
        }
        if(_data) delete _data;
        _len = str._len;
        _init_data(str._data);
        return *this;
    }
    // move 构造 with noexcept
    MyString(MyString&& str) noexcept 
        // 把指针拷贝一下 长度拷贝一下
        :_data(str._data), _len(str._len){
        ++MCtor;
        // 删除指针，如果不删除的话 如果右值被析构的时候编译器会调用析构函数把move的数据给回收
        // 配合析构函数来看
        str._len = 0;
        str._data = NULL; // 重要
    }
    // move assignment
    MyString& operator=(MyString&& str) noexcept{
        ++MAsgn;
        // move
        if(this!=&str) {
            if(_data) delete _data;
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = NULL; // 重要
        }
        return *this;
    }

    // 析构函数
    virtual ~MyString() {
        ++DCtor;
        if(_data) delete _data;
    }

    bool operator < (const MyString& rhs) const {
        return string(this->_data) < string(rhs._data);
    }

    bool operator==(const MyString& rhs) const {
        return string(this->_data) == string(rhs._data);
    }

    char* get() const {
        return _data;
    }
};
size_t MyString::DCtor = 0;
size_t MyString::Ctor = 0;
size_t MyString::CCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MCtor = 0;
size_t MyString::Dtor = 0;

int main() {

}
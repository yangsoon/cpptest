#include <iostream>
#include <string.h>

class TextBlock {
public:
    TextBlock(const char* t){
        if(t) {
            text = new char[strlen(t)];
            strcpy(text, t);
        } else {
            text = new char[1];
            text[0] = '\0';
        }
    }
    ~TextBlock() {
        delete []text;
    }
    const char& operator[](std::size_t idx) const {
        return text[idx];
    }
    // 为了避免重复代码 可以通过类型转换的模式实现非const的操作
    char& operator[](std::size_t idx) {
        // 然后返回的结果是const char& 只能通过const_cast转为非const
        return const_cast<char&> (
            // 先将对象强制转换为const类型 使用static_cast
            static_cast<const TextBlock&>(*this)[idx]
        );
    }
private: 
    char* text;
};

int main() {
    TextBlock tb("text");
    const TextBlock ctb("hello");
    std::cout << tb[1] << std::endl;
    std::cout << ctb[0] << std::endl;
}
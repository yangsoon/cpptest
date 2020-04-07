#include "oop-demo.h"

int main() {
    MyDocument my;
    // 调用onOpenFile时候相当于 CDocument::onOpenFile(&my) 把调用对象的指针传递进去
    // 然后当执行到Serialize的时候发现是虚函数就调用this->Serialize
    my.onOpenFile();
}
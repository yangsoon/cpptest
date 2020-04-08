## 知识点目录

### C++入门

1. [头文件和类的声明](#头文件和类的声明)

2. [内联函数](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L11)

3. [构造函数-初始列](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L9)

4. [单例模式](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/Singleton.h)

   > 使用static修饰的变量保证单例，ctor函数放在private内 避免其他用户可以直接调用构造函数

5. [常量(const)成员函数](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L13)

6. [友元函数](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L25)

   > 一个对象的成员函数是该类其他对象的[友元函数](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L18)

7. [操作符重载](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L40)(忘记了的话查看[视频](https://www.bilibili.com/video/BV1aW411H7Xa?p=5))

   > 操作符重载就是重新定义操作符对应的函数，其中重载之后的返回值需要仔细考虑
   >
   > 例如 c+=3 重载+=之后 如果返回c对应的类的话就可以执行 b+=c+=4 
   >
   > 例如 cout << b << c 重载 << 之后 返回osstream 这样能继续输出。

8. [深拷贝和浅拷贝](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/string.h)

9. [拷贝构造](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/string.h#L39)和[拷贝赋值](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/string.h#L50)

10. [带指针对象的析构函数](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/string.h#L68)

11. [static成员变量](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/account.h)

12. [类模板](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/template-com.h)和[函数模板](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/account-test.cpp#L21)

13. [类继承](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/oop-demo.h)

14. [设计模式](https://www.bilibili.com/video/BV1aW411H7Xa?p=13)

## 头文件和类的声明

[示例代码](https://github.com/yangsoon/cpptest/blob/master/cpp-part1/complex.h#L1)

<p align =“center”>
	<img src="../imag/head-class.jpg" width="70%" height="50%" />
</p>


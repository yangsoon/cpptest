## 知识点目录

### C++入门

1.  [转换函数conversion-function](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/conversion-function.cpp)

2.  [explicit用法](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/conversion-function.cpp#L67)

    > explicit for ctors taking  one argument
    >
    > explicit for ctors taking more than one argument c++11

3.  [pointer-like class](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/pointer-like.cpp)

    > 补充智能指针的知识

4.  [仿函数](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/function-like.cpp)

    > 继续学习

5.  [namespace](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/namespace.cpp)

6.  [成员模板](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/member-templete.cpp)

7.  [模板特化](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/specialization.cpp)和[模板偏特化](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/partial-specialization.cpp)

8.  [引用](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/reference.cpp)

9.  [虚指针和虚表,动态绑定](#虚指针和虚表)

    > 当进行动态绑定的时候 就会安装下面的流程进行查找需要的函数,每个包含虚函数的对象在内存中都包含一个虚指针，这个指针是指向一个虚表 这个虚表可以看成一个数组 用来存这个对象的虚函数列表 然后依据虚函数的下标位置进行调用函数执行(*p->vptr[n])(p) 类似这样的调用

10. [new delete new[] delete[]](#new和delete)

11. [const](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/const.cpp)

12. C++11 new [auto](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/auto.cpp) [ranged-base](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/ranged-base-for.cpp) 

13. [variadic-templates](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/variadic-templates.cpp)

    > 详情看c++11部分

14. [重载new()和delete()](https://www.bilibili.com/video/BV1sW411J7JQ?p=2)

    重载new 每个声明都要有独特的参数列，`Foo* pf = new(300, 'a')Foo`也可以重载delete() 只有当new所调用的ctor抛出异常才会调用这些重载版本的delete()

## 头文件和类的声明

[示例代码](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B/complex.h#L1)

<p align =“center”>
	<img src="../imag/head-class.jpg" width="70%" height="50%" />
</p>

## 虚指针和虚表

[示例代码](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/object-model.cpp)

<p align =“center”>
	<img src="../imag/vtbl.jpg" width="70%" height="50%" />
</p>
<p align =“center”>
	<img src="../imag/vtbl2.jpg" width="70%" height="50%" />
</p>

## new和delete
[示例代码](https://github.com/yangsoon/cpptest/blob/master/c%2B%2B2/new-delete.cpp) 

<p align =“center”>
	<img src="../imag/new.jpg" width="70%" height="50%" />
</p>
<p align =“center”>
	<img src="../imag/delete.jpg" width="70%" height="50%" />
</p>
<p align =“center”>
	<img src="../imag/delete[].jpg" width="70%" height="50%" />
</p>
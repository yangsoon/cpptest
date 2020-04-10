## STL

1. STL体系结构

   容器是前闭后开区间，迭代器相当于一个指针，每个容器内的指针都不一样。

   ```c++
   Container<T> c;
   // 每个容器内的指针类型都不一样
   Container<T>::iterator ite = c.begin();
   //c.end()指向数组最后一个元素的后面位置
   for(; ite!=c.end(); ++ite) {...}
   ```

   ```c++
   // c++ 11
   vector<int> vec = {1,2,3};
   for(auto e: vec) {...}
   ```

2. 容器结构分类

   + 序列式容器 方便查找
   + 不定序容器
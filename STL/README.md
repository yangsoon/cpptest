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
   
3. vector array list forward_list

   ```c++
   forward_list<string> c;
   c.sort(); // 自带排序算法
   c.push_front(); // forward_list只能在前面加
   ```

4. deque

   ```c++
   deque<string> c;
   c.push_back(a);
   c.front();
   c.back();
   ```

   ![](../imag/deque.png)

5. stack

   ![](../imag/stack.png)

6. queue

   ![](../imag/queue.png)

7. multiset

   ![](../imag/mult-set.png)

8. multimap

   ![](../imag/mult-map.png)

9. unordered_multiset

   ![](../imag/unordered-mult-set.png)

10. unordered-mult-map

    ![](../imag/unordered-mult-map.png)

11. set

    ![](../imag/set.png)

12. map

    ![](../imag/map.png)

13. 使用分配器
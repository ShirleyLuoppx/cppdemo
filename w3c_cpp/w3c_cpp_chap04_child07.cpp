#include <iostream>
#include <string>
// 引入array数组的头文件
#include <array>
// 引入bitset的头文件
#include <bitset>
// 引入deque的头文件
#include <deque>
// 引入forward_list的头文件
#include <forward_list>
// 引入list的头文件
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * c++ 标准模板库 STL standrd template library
 * 
 * 8位无符号整数是一种数据类型，也称为字节（byte）。它可以表示的数值范围是从0到255（2^8-1）。无符号整数表示只能表示非负数，因此它不包含正负号。在C语言中，无符号整数类型可以使用uint8_t来声明。这种类型通常用于表示不需要负数的数据，例如像像素值、颜色分量等。
 * 是的，结构体在C语言中类似于Java中的实体类（Entity Class）。它们都用于定义一组相关的数据字段。结构体可以包含不同类型的成员变量，而实体类可以包含属性和方法。然而，C语言中的结构体没有方法和继承的概念，主要用于组织和管理数据。
 * 这段代码定义了一个名为xxx的结构体，它只有一个成员变量xxx，类型为uint8_t（8位无符号整数）。


 */

/**
 * array：保存相同类型的元素，且严格按线性顺序存储元素，大小固定，不能改变
 */
void testArray()
{
    cout << "----------------------array----------------------" << endl;
    // 创建一个存储整数的数组，大小为5
    array<int, 5> myArray;

    // 向数组中添加元素
    myArray[0] = 10;
    myArray[1] = 20;
    myArray[2] = 30;
    myArray[3] = 40;
    myArray[4] = 50;

    // 访问数组中的元素
    cout << "first element: " << myArray[0] << endl;
    cout << "last element: " << myArray[4] << endl;

    // 获取数组的大小
    cout << "size of array: " << myArray.size() << endl;

    // 使用迭代器遍历数组
    cout << "elements of array: ";
    for (auto it = myArray.begin(); it != myArray.end(); ++it) // myArray.begin()数组第一个元素的迭代器，myArray.end()数组最后一个元素的迭代器
    {
        cout << *it << " "; // 迭代器的引用就是元素的值
    }

    cout << endl;
    // 数组的第一个元素的地址
    cout << myArray.data() << endl;

    for (int i = 0; i < myArray.size(); i++)
    {
        cout << (&myArray[i]) << endl; // 也可以这样遍历数组，&myArray[i]打印数组的每个元素的地址
    }
    cout << endl;
    cout << myArray.begin() << endl;  // 0x6584dffaa0
    cout << myArray.cbegin() << endl; // 0x6584dffaa0
}

/**
 * bitset：一个N位的固定大小序列，用于存储二进制数据，提供了对二进制数据的基本操作，例如访问数据，替换数据，获取数据为1的大小 等
 */
void testBitset()
{
    cout << "----------------------bitset----------------------" << endl;
    bitset<8> bits; // 创建一个包含 8 位的 bitset 对象，默认值都是0 ，也就是0000 0000

    bits.set(0); // 设置第 0 位为 1，内存中操作位的时候，都是从右往左数，最低位是最右边的这位，set函数有两种，第一种就是只包含一个参数：设置参数位的值为 1；第二种是包含两个参数，第一个参数表示位的位置，第二个参数表示要设置的值，可以设置为0或1
    bits.set(2); // 设置第 2 位为 1

    cout << "Bitset: " << bits << endl; // 输出整个 bitset

    cout << "Bit at index 1: " << bits.test(1) << endl; // 检查第 1 位是否为 1
    cout << "Bit at index 2: " << bits[2] << endl;      // 检查第 2 位是否为 1

    bits.reset(0); // 将第 0 位重置为 0

    cout << "Bitset after reset: " << bits << endl;

    cout << "Number of set bits: " << bits.count() << endl; // 统计设置为 1 的位的数量

    bits.set(0, 1); // 设置第0位为1
    cout << bits << endl;
    cout << bits.all() << endl; // 测试是否设置了 bitset 中的所有位。如果所有位都是 1，则返回 true，否则返回 false
    cout << bits.count() << endl;

    cout << bits.to_ullong() << endl; // 转换为无符号长整数，也就是int型的值
    cout << bits.to_ulong() << endl;  // 转换为无符号长整数，也就是int型的值
}

/**
 * deque：大小不固定的一个双端队列，顾名思义，就是头尾两端都能操作的一个队列 ，都能操作增删改查队列操作，通过下标获取数据，也称作序列容器,存储相同类型的数据
 */
void testDeque()
{
    cout << "----------------------deque----------------------" << endl;
    deque<int> deque; // 创建一个 int 类型的 deque 对象

    deque.push_back(1);  // 在尾部插入元素 1
    deque.push_back(2);  // 在尾部插入元素 2
    deque.push_front(3); // 在头部插入元素 3

    cout << "Deque: ";
    for (const auto &element : deque)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Front element: " << deque.front() << endl; // 访问头部元素
    cout << "Back element: " << deque.back() << endl;   // 访问尾部元素

    deque.pop_front(); // 移除头部元素

    cout << "Deque after pop_front: ";
    for (const auto &element : deque)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "deque.at's element is " << deque.at(1) << endl; // 获取下标为1的元素，还是从0开始

    // 使用 cbegin() 和 cend() 获取常量迭代器
    std::deque<int>::const_iterator it = deque.cbegin();
    std::deque<int>::const_iterator end = deque.cend();

    // 遍历 deque 中的元素
    while (it != end)
    {
        cout << *it << " ";
        ++it;
    }

    cout << endl;

    std::deque<int>::iterator beginit = deque.begin();
    // ++beginit; // 将迭代器移动到第二个元素位置

    deque.insert(beginit, 10); // 在第二个元素之前插入值为 10 的元素

    cout << "Deque after insert: ";
    for (const auto &element : deque)
    {
        cout << element << " ";
    }
    cout << endl;
}

/**
 * forwardList：是一个只能单向顺序访问数据的序列容器，存储相同类型的数据，也是可以实现增删改查的
 */
void testForwardList()
{
    cout << "----------------------forwardList----------------------" << endl;
    std::forward_list<int> forwardList = {1, 2, 3, 4, 5};

    // 遍历 forward_list 中的元素
    std::cout << "Forward List: ";
    for (const auto &element : forwardList)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 在头部插入元素
    forwardList.push_front(0);

    // 在指定位置插入元素
    auto it = forwardList.insert_after(forwardList.begin(), -1); // forwardList.begin()是指向第一个元素的迭代器，insert_after是在指定位置后添加元素

    // 移除指定位置后的元素
    forwardList.erase_after(it); // erase_after是移除指定元素后的元素，it就是上面添加的-1

    // 遍历修改后的 forward_list 中的元素
    std::cout << "Modified Forward List: ";
    for (const auto &element : forwardList)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

/**
 * list：就是一个双向链表，存储相同类型的数据
 */
void testList()
{
    cout << "----------------------list----------------------" << endl;
    std::list<int> myList = {1, 2, 3, 4, 5};

    // 遍历 list 中的元素
    std::cout << "List: ";
    for (const auto &element : myList)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl; // 1，2，3，4，5

    // 在头部插入元素
    myList.push_front(0); // 0，1，2，3，4，5

    // 在尾部插入元素
    myList.push_back(6); // 0，1，2，3，4，5，6

    // 在指定位置插入元素
    auto it = std::next(myList.begin(), 3);
    myList.insert(it, -1); // 0，1，2，-1，3，4，5，6

    // 移除指定位置的元素
    it = std::next(myList.begin(), 2);
    myList.erase(it); // 0，1，-1，3，4，5，6

    // 遍历修改后的 list 中的元素
    std::cout
        << "Modified List: ";
    for (const auto &element : myList)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

/**
 * map：map映射，是一个以键值对的形式存储的容器,键是唯一的，如果插入了相同的键，那么后面的数据会覆盖前面的，数据会自动排序
 */
void testMap()
{
    cout << "----------------------map----------------------" << endl;
    std::map<std::string, int> myMap;

    // 向 map 中插入键值对
    myMap["Alice"] = 25;
    myMap["Alice"] = 10;
    myMap["Charlie"] = 35;
    myMap["Bob"] = 30;

    // 遍历 map 中的键值对
    std::cout << "Map: " << std::endl;
    for (const auto &pair : myMap)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 访问特定的键值对
    std::cout << "Age of Alice: " << myMap["Alice"] << std::endl;

    // 检查键是否存在
    if (myMap.count("Bob") > 0)
    {
        std::cout << "Bob is present in the map." << std::endl;
    }
}

/**
 * queue:队列是一种先进先出（FIFO）（就像一个两头都通的管子）的数据结构，支持pop和push，插入和删除数据
 */
void testQueue()
{
    cout << "----------------------queue----------------------" << endl;
    std::queue<int> myQueue;

    // 向队列中插入元素
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // 访问队列中的元素
    std::cout << "Front element: " << myQueue.front() << std::endl; // 1
    std::cout << "Back element: " << myQueue.back() << std::endl;   // 3

    // 移除队列中的元素
    myQueue.pop(); // 移除队列中的第一个元素

    // 遍历队列中的元素
    std::cout << "Queue: ";
    while (!myQueue.empty())
    {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
}

/**
 * set：是一个有序的不重复的容器，如果插入了重复的值，那么后面的这条数据将会被忽略
 */
void testSet()
{
    cout << "----------------------set----------------------" << endl;
    set<int> mySet;

    // 添加元素
    mySet.insert(5);
    mySet.insert(5); // 这条数据会被忽略
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);

    // 遍历元素
    for (int num : mySet)
    {
        cout << num << " ";
    }
    cout << endl;

    // 查找元素：在mySey集合中查找内容为2的元素，如果有，则返回一个指向该元素的迭代器，如果没得，则返回mySet.end()
    int target = 2;
    if (mySet.find(target) != mySet.end())
    {
        cout << " found " << target << " in set" << endl;
    }
    else
    {
        cout << target << "not found in set" << endl;
    }

    // 删除元素
    mySet.erase(8);

    // 再次遍历元素
    for (int num : mySet)
    {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * stack:堆栈，是一种后进先出（LIFO）的数据结构（就像一个桶，先放进去的东西在最下面，后放进去的东西在最上面，可以最先拿出来），支持入栈push和出栈pop
 */
void testStack()
{
    cout << "----------------------stack----------------------" << endl;
    stack<int> myStack;

    // 入栈
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 获取栈顶元素
    int topElement = myStack.top();
    cout << "top element: " << topElement << endl; // 30

    // 出栈
    myStack.pop();

    // 再次获取栈顶元素
    topElement = myStack.top(); // 20
    cout << "top element after pop: " << topElement << endl;

    // 检查栈是否为空
    bool isEmpty = myStack.empty();
    if (isEmpty)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl; //
    }

    // 获取栈的大小
    int size = myStack.size();
    cout << "size of stack: " << size << endl; // 2
}

/**
 * unorderedMap：是一个无序的不重复的容器，如果插入了重复的值，那么后面的这条数据将会被忽略
 */
void testUnorderedMap()
{
    cout << "----------------------unorderedMap----------------------" << endl;
    unordered_map<string, int> myUnorderedMap;
    myUnorderedMap.insert(make_pair("ppx", 10));
    myUnorderedMap.insert(make_pair("ppj", 30));
    myUnorderedMap.insert(make_pair("ppl", 20));
    myUnorderedMap.insert(make_pair("ppx", 5));

    cout << myUnorderedMap["ppx"] << endl;
    for (auto const &pair : myUnorderedMap)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}

/**
 * unordered_set：是一个无序的不重复的容器，如果插入了重复的值，那么后面的这条数据将会被忽略
 */
void testUnorderedSet()
{
    cout << "----------------------unordered_set:----------------------" << endl;
    unordered_set<int> myUnorderedSet;
    myUnorderedSet.insert(10);
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(88);
    myUnorderedSet.insert(66);
    myUnorderedSet.insert(66);

    for (auto const &element : myUnorderedSet)
    {
        cout << element << " ";
    }
    cout << endl;

    myUnorderedSet.erase(10);
    cout << "after erase element ";
    for (auto const &elem : myUnorderedSet)
    {
        cout << elem << " ";
    }
}

/**
 * vector:是一种支持随机访问的容器，可以在任意位置进行插入和删除
 */
void testVector()
{
    cout << "----------------------vector----------------------" << endl;
    std::vector<int> myVector;

    // 向向量中插入元素
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // 访问向量的元素
    std::cout << "first element: " << myVector[0] << std::endl;
    std::cout << "second element: " << myVector[1] << std::endl;
    std::cout << "third element: " << myVector[2] << std::endl;

    // 遍历向量的元素
    std::cout << "all elements: ";
    for (const auto &num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 获取向量的大小
    std::cout << "size of vector: " << myVector.size() << std::endl;

    // 清空向量
    myVector.clear();
    std::cout << "size of vector after clear: " << myVector.size() << std::endl;
}

/**
 * algorithm:是一个包含各种常用算法的算法库
 */
void testAlgorithm()
{
    cout << "----------------------algorithm----------------------" << endl;
    std::vector<int> myVector = {5, 2, 8, 1, 9, 3};

    // 使用std::sort函数对向量进行排序
    std::sort(myVector.begin(), myVector.end());

    // 使用std::for_each函数遍历并输出向量的元素
    std::cout << "vector after sort: ";
    std::for_each(myVector.begin(), myVector.end(), [](int num)
                  { std::cout << num << " "; });
    std::cout << std::endl;

    // 使用std::find函数查找特定元素
    int target = 8;
    auto it = std::find(myVector.begin(), myVector.end(), target);
    if (it != myVector.end())
    {
        std::cout << target << " exists in vector" << std::endl;
    }
    else
    {
        std::cout << target << " not exists in vector" << std::endl;
    }
}

/**
 * iterator
 */
void testIterator()
{
    cout << "----------------------iterator----------------------" << endl;
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // 使用迭代器遍历向量并输出元素
    std::cout << "elements in vector: ";
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 使用迭代器访问和修改向量的元素
    std::vector<int>::iterator it = myVector.begin();
    *it = 10; // 修改第一个元素

    std::cout << "vector after modify: ";
    for (const auto &num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    testArray();
    testBitset();
    testDeque();
    testForwardList();
    testList();
    testMap();
    testQueue();
    testSet();
    testStack();
    testUnorderedMap();
    testUnorderedSet();
    testVector();
    testAlgorithm();
    testIterator();

    return 0;
}
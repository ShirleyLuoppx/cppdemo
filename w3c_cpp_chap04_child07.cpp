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

using namespace std;

/**
 * c++ 标准模板库 STL standrd template library
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
 * map：是一个以键值对的形式存储的容器
 */
void testMap()
{
    cout << "----------------------map----------------------" << endl;
    std::map<std::string, int> myMap;

    // 向 map 中插入键值对
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 35;

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
 * queue:队列是一种先进先出（FIFO）的数据结构，支持pop和push，插入和删除数据
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
 * set
 */
void testSet()
{
    cout << "----------------------set----------------------" << endl;
}

/**
 * stack
 */
void testStack()
{
    cout << "----------------------stack----------------------" << endl;
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

    return 0;
}
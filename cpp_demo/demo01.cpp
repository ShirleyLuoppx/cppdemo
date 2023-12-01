#include <iostream>
#include <string>
#include "common_demo.h" //引用头文件的时候需要加上双引号

using namespace std;

/**
 * 一些c++的基础知识：
 * .h结尾是头文件，.cpp结尾是源文件，一般来说，头文件里面都是用来声明函数、类，定义宏和全局变量，不会做具体的实现，源文件里面是具体的实现，通过源文件来调用头文件里面的函数、类，提高代码重用性
 */
int main(int argc, char const *argv[])
{

    cout << "Hello World!" << endl;

    cout << endl;

    /**
     *调用枚举类型
     */
    ProjectType p = English; // 声明一个枚举类对象并赋初始值为English
    if (p == Math)
    {
        cout << "current type is Math" << endl;
    }
    else if (p == English)
    {
        cout << "current type is English" << endl;
    }
    else if (p == Chinese)
    {
        cout << "current type is Chinese" << endl;
    }

    return 0;
}

/**
 * struct 的称为结构体，类似与java的实体类，用于存放成员变量
 */
struct Person
{
    // unit8_t 代表无符号8位整数，无符号就是说没得正负，,,,,就是只有正数，，且是正整数，范围是[0,2^8-1]，也就是[0,255]
    uint8_t age;
    // uint16_t 代表无符号16位整数，范围是[0,2^16-1]，也就是[0,65535]
    uint16_t height;
    // uint32_t 代表无符号32位整数，范围是[0,2^32-1]，也就是[0,4294967295]
    uint32_t weight;
    // uint64_t 代表无符号64位整数，范围是[0,2^64-1]，也就是[0,18446744073709551615]
    uint64_t id;
};

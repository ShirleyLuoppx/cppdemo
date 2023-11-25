#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
/**
 * 不使用 using namespace std 的时候也可以直接使用  std::  打印和声明string变量
*/
    std::string greeting = "Hello";
    std::cout << greeting;

    return 0;
}

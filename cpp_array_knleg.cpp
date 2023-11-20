#include <iostream>
#include <string>
// 导入 cmath 库，里面包含一些数学运算的函数，例如abs取绝对值，sqrt开根号等
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    /**
     * 1.19 数组   TODO：MARK一下：c++中的数组的length和size 跟java的不一样，打印的不是数组的长度
     */
    // 声明数组的时候就给定数组长度
    string cars[4] = {"fort", "dazhong", "wey", "changan"};
    string testArrs = {"1"};
    string str = "f";
    int intArray[4] = {1, 2, 3, 4};
    // 不给定数组长度
    int test[] = {1};
    int numA = 1;
    cout << "-------sizeof----------" << endl;
    cout << sizeof(cars) << endl;     // 128
    cout << sizeof(testArrs) << endl; // 32
    cout << sizeof(str) << endl;      // 32-------------->sizeof:string类型的，不管是字符型还是字符型数组的，一个值都占32个字节
    cout << sizeof(intArray) << endl; // 16
    cout << sizeof(test) << endl;     // 4
    cout << sizeof(numA) << endl;     // 4--------------->sizeof(数组):int类型的，不管是整型还是整型数组，一个值占4个字节

    cout << "-------size----------" << endl;

    cout << cars->size() << endl;    // 4
    cout << testArrs.size() << endl; // 1
    cout << str.size() << endl;      // 1--------------->.size()：返回string类型数组/字符的长度

    cout << "-------length----------" << endl;

    cout << cars->length() << endl;    // 4
    cout << testArrs.length() << endl; // 4
    cout << str.length() << endl;      // 1--------------->.length()：返回string类型数组/字符的长度


    return 0;
}

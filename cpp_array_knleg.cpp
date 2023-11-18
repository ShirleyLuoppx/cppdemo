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
    string testArrs[4] = {"1", "2", "3", "4"};
    // 不给定数组长度
    int test[] = {1, 2, 3};

    cout << sizeof(cars) << endl;
    cout << sizeof(testArrs) << endl; 
    
    cout << cars->size() << endl; 
    cout << testArrs->size() << endl; 
    

    cout << cars->length() << endl; 
    cout << testArrs->length() << endl;

    // cout << test.length << endl;//报错

    
    string str = "hello";
    cout << "hello's length is " << str.length() << endl; // 5 ，这两个函数倒是可以用来获取字符串的长度，但是都不能用于获取数组的长度
    cout << "hello's size is " << str.size() << endl;     // 5，这两个函数倒是可以用来获取字符串的长度，但是都不能用于获取数组的长度

    return 0;
}

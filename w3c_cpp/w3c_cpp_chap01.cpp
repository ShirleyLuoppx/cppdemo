#include <iostream>
#include <string>
// 导入 cmath 库，里面包含一些数学运算的函数，例如abs取绝对值，sqrt开根号等
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{

    /**
     * 1.10 C++运算符
     */

    // 赋值运算符
    int x = 3;
    x <<= 5; // 左移位，相当于x的二进制表示为0011向左移动5位，也就等于110 0000，十进制等于96。 另外，有一个快速口诀，x=x*2^5，也就是x=3*2^5=96
    cout << "x << 5 = " << x << endl;

    int y = 96;
    y >>= 5; // 右移位，相当于y的二进制表示为110 0000向右移动5位，也就等于0011，十进制等于3。 另外，有一个快速口诀，y=y/2^5，也就是y=96/2^5=3
    cout << "y >> 5 = " << y << endl;

    cout << endl;

    // 关系运算符 >、<、>=、<=、==、!= ，1true 0 false
    int a = 10;
    int b = 5;
    cout << "a > b " << (a > b) << endl;

    cout << endl;

    // 逻辑运算符 &&与 ||或 !非 跟java一样的

    /**
     * 1.12 数学运算
     * */
    cout << "max value between 3 and 6 is --> " << max(3, 6) << endl;
    cout << "min value between 2 and 7 is --> " << min(2, 7) << endl;
    cout << abs(-5) << endl;  // 绝对值
    cout << sqrt(25) << endl; // 开根号

    cout << endl;

    /**
     * 1.13 布尔值 ， 1true 0false
     */
    bool result = true;
    bool isOn = false;
    cout << "result is " << result << endl;
    cout << "isOn is " << isOn << endl;

    cout << endl;

    /**
     * 1.14 条件语句
     */
    int numA = 10;
    int numB = 8;
    if (numA > numB)
    {
        cout << "numA > numB" << endl;
    }
    else if (numA < numB)
    {
        cout << "numA < numB" << endl;
    }
    else
    {
        cout << "numA == numB" << endl;
    }

    // 三目运算符
    cout << (numA > numB ? "numA > numB = true" : "numA > numB = false") << endl;

    cout << endl;

    /**
     * 1.15 Switch语句 跟java一样
     */
    int day = 6;
    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "maybe error day" << endl;
        break;
    }
    cout << endl;

    /**
     * 1.16 While循环
     */
    int whileNum = 0;
    while (whileNum < 10)
    {
        cout << "whileNum < 10 and whileNum = " << whileNum << endl;
        whileNum += 1;
    }

    whileNum = 0;
    do
    {
        cout << "do While ing and whileNum =" << whileNum << endl;
        whileNum += 1;
    } while (whileNum < 5);

    cout << endl;

    /**
     * 1.17 for循环
     */
    for (int i = 0; i < 10; i++)
    {
        cout << "i = " << i << endl;
    }
    cout << endl;

    /**
     * 1.18 breach/continue
     */
    for (int i = 0; i < 10; i++)
    {
        cout << (i == 6 ? "i = 6 break for circle " : "i ==") << i << endl;
        if (i == 6)
            break;
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {

        if (i == 6)
            continue; // 跳出这次循环，不执行后面的语句，重新进入下一次循环内容

        cout << "i ==" << i << endl;
    }
    cout << endl;

    /**
     * 1.19 数组
     */
    // 声明数组的时候就给定数组长度
    string cars[4] = {"fort", "dazhong", "wey", "changan"};
    string testArrs[4] = {"1", "2", "3", "4"};
    // 不给定数组长度
    int test[] = {1, 2, 3};

    // cout << cars->size() << endl;//奇怪，数组.size是可以 获取数组长度的，但是上次获取得到时候我记得获取的不是这个值....
    for (int i = 0; i < 4; i++)
    {
        cout << " for content of cars : " << cars[i] << endl; // 注意一下，c++文件中打印中文的冒号： 会导致程序无法 正常运行 以及乱码！！！
    }
    cout << endl;

    /**
     * 1.20 引用
     */
    string food = "meal";
    // 创建一个引用变量
    string &myFood = food;
    cout << food << endl;   // meal
    cout << myFood << endl; // meal
    // 打印food这个变量存储的内存地址（比如0x6c2dff8a0），每次重新运行获取到的地址都不一样；
    //在c++中，每次新创建一个变量就会给这个变量分配一个内地址，当给变量赋值的时候，这个值就会被存到这个内存地址
    //内存地址是一个16进制的(0x...)
    cout << &food << endl;
    cout << endl;

    /**
     * 1.21 指针
    */
   //声明一个指针
   //指针的类型应该与指针所指向的变量的类型一致，指针的值就是所指向的变量的内存地址
   //声明指针的方式有3种，string* ptr、string *ptr、string * ptr，但是首选第一种噢
    string* ptr = &food;
    cout << ptr << endl;

    cout << endl;
    return 0;
}

#include <iostream>
//显示添加string库头文件，虽然我现在在visual studio code中不显示包含这个头文件也能使用string类型的变量，这可能是编译器给我添加进去了，为了代码的可移植性和一致性 还是添加比较好的
#include <string>
using namespace std;

int main()
{
    // 如果 不加 命名空间 std的话，输出打印的时候就可以像这样写     std::cout << "Hello, world!" << std::endl;
    // 如果加了namespace 的话输出打印就会简单一些
    cout << "hello a ppx " << endl; // 这个似乎是换行
    // cout << "这是一个打印";//中文打印会乱码
    // cout << "打印++++1";

    // wstring wstr = L"你好呀 皮皮虾";
    // wcout << wstr << endl;//宽字符也显示不出来

    //\n 换行
    cout << "change line test \n";
    cout << "aaaaaaaaa   \n";

    //\n\n 添加一个新的空行
    cout << "a empty line by \n\n";
    cout << "-------\n\n";

    // endl 也换行 ，但是\n 更常用，是首选
    cout << "a new line by endl" << endl;
    cout << "-------\n";

    /*
    多行注释
    */

    // 变量赋值，变量必须指定类型
    int intNum = 11;
    float floatNum = 11.11;
    double doubleNum = 11.11;
    bool boolNum = false;
    string str = "this is a str value";
    char charValue = 'a';
    cout << "intNum = " << intNum << endl;
    cout << "floatNum = " << floatNum << endl;
    cout << "doubleNum = " << doubleNum << endl;
    cout << "boolNum = " << boolNum << endl;
    cout << "str = " << str << endl;
    cout << "charValue = " << charValue << endl;

    cout << "\n";

    // 运算
    int a = 1;
    int b = 3;
    int sum = a + b;
    cout << "sum = " << sum;

    cout << "\n\n";

    // 声明多个变量
    int x, y, z;
    x = 1;
    y = 2;
    z = 3;
    cout << "x = " << x << " y = " << y << " z = " << z << endl;

    string str1 = "hello", strb = "world", strc = "!";
    cout << str1 << strb << strc << endl;

    cout << "\n";

    // 定义常量
    const double PI = 3.14;
    cout << "PI = " << PI << endl;
    cout << "\n";

    // 使用   cin   获取键盘输入并打印出来
    int i;
    cout << "please type in a number:";
    cin >> i;
    cout << "your number is  " << i;

    cout << "\n\n";

    // cout是输出 cin是获取输入

    // 简单的计算器
    int countNum;
    int numberA;
    int numberB;
    cout << "please type in numberA: ";
    cin >> numberA;
    cout << "please type in numberB:";
    cin >> numberB;
    countNum = numberA + numberB;
    cout << "your sumNumber is " << countNum << endl;

    cout << "\n";

    /**
     * 算术运算符：  + - * % / ++ --
     * 赋值运算符：  = += -= *= /=  %= |= ^= <<= >>=
     * 关系运算符：< > >= <= != ==
     * 逻辑运算符：  && || !
     * 位运算符：  & | ^ ~ << >>
    */

    return 0;
}
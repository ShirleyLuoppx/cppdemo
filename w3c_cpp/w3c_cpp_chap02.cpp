#include <iostream>
#include <string>

using namespace std;

// 需要注意一下：要被调用的函数需要写在调用之前，这是因为c++是从上到下 的工作
void myFunction()
{
    cout << "this is my function" << endl;
}

// 或者可以先声明函数，在main中调用，最后再去实现这个函数
void declareFunFirst();

// name为形参，ppx为实参
void testParams(string name)
{
    cout << "name = " << name << endl;
}

// 默认参数，直接在函数参数里面给形参赋值，如果调用函数的时候没有传参就会使用这个默认值
void defaultParam(string country = "Noway")
{
    cout << " country = " << country << endl;
}

// 多个形参
void manyParams(string name, int age)
{
    cout << "name = " << name << " age = " << age << endl;
}

// 有返回值的函数
int calNum(int numA, int numB)
{
    int result = numA + numB;
    cout << "calNum result = " << result << endl;
    return result;
}

// 使用普通变量传递的参数也是可以被修改的
void updateNormalParam(int numA)
{
    cout << "before change numA = " << numA << endl;
    numA = 10;
    cout << "after change numA = " << numA << endl;
}

// 在形参的地方，使用&参数名，也可以使形参的值被改变，但是需要注意的是：在调用函数的地方，传参不能直接传常量，只能传递变量，在变量里面去赋值
// 虽然感觉这个有点鸡肋，不过存在肯定有他的道理，先看看再说
void refrencePassParam(int &x, int &y)
{
    cout << "before change x = " << x << " y = " << y << endl;
    int z = x;
    x = y;
    y = z;
    cout << "after change x = " << x << " y = " << y << endl;
}

// 重载，函数名一致，但是参数个数、类型和返回值都不一样，跟java中的重载定义类似
int subNum(int a, int b)
{
    int result = a + b;
    cout << "result = " << result << endl;
    return result;
}

double subNum(double a, double b)
{
    double result = a + b;
    cout << "result = " << result << endl;
    return result;
}

// w3cschool 第二章 函数
int main(int argc, char const *argv[])
{
    cout << "-------------" << endl;

    subNum(1, 2);
    subNum(1.1, 2.2);

    int x = 2;
    int y = 3;
    refrencePassParam(x, y);

    updateNormalParam(1);

    myFunction();
    declareFunFirst();

    testParams("ppx");

    defaultParam();
    defaultParam("China");

    manyParams("ppx", 18);
    manyParams("LiMing", 20);

    calNum(1, 1);

    return 0;
}

void declareFunFirst()
{
    cout << "this is declareFunFirst" << endl;
}

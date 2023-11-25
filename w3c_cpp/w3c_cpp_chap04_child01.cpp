// #include 是预处理指令，用于在编译之前需要做的一些预处理
#include <iostream> //由于预处理指令不是c++语言所以不需要以分号结尾
#include <string>
#include <vector>

#include <unistd.h>
// 导入c++的csignal头文件
#include <csignal>

// #include、#define、#if、#else、#line  这些都是预处理指令

using namespace std;
// using std::cout;//明确使用std命名空间下的cout

/**
 * 命名空间
 */
// 自定义一个命名空间
namespace first_space
{
    void func()
    {
        cout << "first_space" << endl;
    }
}

namespace second_space
{
    void func()
    { // 不同命名空间下可以包含同名的函数
        cout << "second_space" << endl;
    }

    // 嵌套命名空间
    namespace third_space
    {
        void func()
        {
            cout << "third_space" << endl;
        }
    }
}

// 模板函数
template <typename T>
inline T const &maxNum(T const &a, T const &b)
{
    return a < b ? b : a;
}

// 类模板
template <class T>
class Stack
{
private:
    vector<T> elms;

public:
    void push(T const &); // 入栈，接收一个类型为T的常量引用的入参
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    bool empty() const
    {
        return elms.empty();
    } // 判断栈是否为空
};

template <class T>
void Stack<T>::push(T const &elem)
{
    // 将参数elem添加到 elms
    elms.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elms.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elms.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elms.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素
    return elms.back();
}

/**
 * 预处理器
 */
// 简而言之，#define就是用于创建常量
#define PI 3.1415926              // #define是一个预处理指令，用于创建一个常量，这个常量也称作为一个宏，该预处理指令会使该文件后面所有使用到宏的地方在程序编译之前就被替换为这个宏的值
#define MIN(a, b) (a < b ? a : b) // #define还可以用于定义一个带参的宏
#define DEBUG = 0
#define SAY(x) #x         // #预处理器会将x转换为字符串，这样有啥作用？？？
#define CONCAT(x, y) x##y // ##预处理器 会将xy连接起来，不知道有啥用...

/**
 * 信号处理
 */
void signalHandler(int sig)
{
    cout << "Caught signal " << sig << endl; // ctrl+c 的时候打印
    // 退出程序
    exit(sig);
}

using namespace first_space; // 直接明确使用哪一个命名空间，就可以直接调用该命名空间下的函数
int main(int argc, char const *argv[])
{
    cout << "---------------------------" << endl;

    int signalNum = 0;
    // 注册信号 SIGINT 和 信号处理程序
    signal(SIGINT, signalHandler);
    while (++signalNum)
    {
        cout << "signalNum ++ wait to raise fun " << endl;
        if (signalNum == 3)
        {
            raise(SIGABRT); // raise 可以生成一个信号x，这个信号会传给信号处理程序并执行，(生成的信号要跟注册的信号一致，要不然信号处理程序是收不到的)
        }
        sleep(1);
    }

    cout << endl;

    // 注册一个SIGINT的信号，signalHandler作为信号处理程序
    signal(SIGINT, signalHandler); // 当收到SIGINT信号时，执行signalHandler函数（使用ctrl+c可以使程序中断，进而收到SIGINT信号）

    while (1)
    {
        cout << "exec signal func" << endl;
        sleep(1);
    }

    cout << endl;

    // 几个预定义宏
    cout << __LINE__ << endl; // 当前代码行数
    cout << __FILE__ << endl; // 当前文件名
    cout << __DATE__ << endl; // 当前日期：月-日-年
    cout << __TIME__ << endl; // 当前时间点：时-分-秒

    cout << endl;

    int xy = 100;
    cout << CONCAT(1, 23) << endl;
    cout << SAY(HELLO) << endl;

// #ifdef 条件编译指令，会执行里面的内容
#ifdef DEBUG
    cout << "usage of ifdef" << endl;
#endif

#if 0 // #if 是条件编译中不进行编译的指令，里面的内容不会被编译，相当于注释
    cout << "nothing will be print here" < endl;
#endif

    cout << endl;

    cout << MIN(2, 5) << endl;

    cout << endl;

    cout << PI << endl;

    cout << endl;

    try
    {
        Stack<int> intStack;
        intStack.push(7);
        cout << "top value is " << intStack.top() << endl; // 7

        Stack<string> stringStack;
        stringStack.push("hello");
        cout << "stringstack top value is " << stringStack.top() << endl; // hello
        stringStack.pop();
        stringStack.pop(); // Stack<>::pop(): empty stack
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        return -1;
    }

    cout << endl;

    second_space::func();
    second_space::third_space::func(); // 调用嵌套命名空间里面的函数也是一样的

    func();

    cout << endl;

    cout << maxNum(2, 6) << endl;
    cout << maxNum(2.1, 6.1) << endl;
    string s = "Hello";
    string str = "World";
    cout << maxNum(s, str) << endl;
    cout << maxNum("Hello", "World") << endl;

    return 0;
}

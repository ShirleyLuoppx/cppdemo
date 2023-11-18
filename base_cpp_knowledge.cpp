#include <iostream>
#include <string>
using  namespace std;

int main(int argc, char const *argv[])
{
    
/**
 * 1.11 字符串
*/
    // 字符串串联
    string aStr = "aaaa";
    string bStr = "bbbbb";
    string cStr = aStr +"  "+ bStr;

    string dStr = aStr.append(bStr);

    cout << cStr << endl;
    cout << dStr << endl;

    //string.size 和string.length的作用是一样的
    cout << "cStr length is "<< cStr.length() << endl;
    cout << "dStr size is "<< dStr.size() << endl;

    //打印字符串中的一个字符
    cout << " "<< cStr[0] << endl;
    //替换字符串中的某一个字符
    dStr[1] = 'K';
    cout << dStr << endl;

    // 读取用户输入，遇空格就终止
    /**
     *     string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
     * 
    */



    //获取用户的整行输入 包含空格
    string fullName;
    cout << "please enter your full name:";
    getline(cin,fullName);
    cout << "your full name is "<< fullName << endl;

    return 0;
}

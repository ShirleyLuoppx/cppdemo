// 用于打印log和接收键盘输入
#include <iostream>
#include <string>
// 用于创建、读取、写入文件
#include <fstream>

using namespace std;

/**
 * w3cschool c++ 第四章 高级教程
 */


class Box{
    public:
    Box(){//构造函数，在创建对象时自动调用
        cout << "constructor function" << endl;
    }

    ~Box(){//析构函数，在对象销毁时自动调用
        cout << "destructor function" << endl;
    }
};

int main(int argc, char const *argv[])
{
    cout << "Hello World------------------------------" << endl;

    //给对象动态分配内存地址
    Box* box = new Box[4];
    //删除数组，释放内存
    delete[] box;

    /**
     * 文件创建与读写
     */
    // 创建并打开一个文件
    ofstream MyFile("filename.txt");
    // 写入文件
    MyFile << "create a file ,open it and write sth in it";
    // 关闭文件
    MyFile.close();

    string myText;
    // 读取文件
    ifstream MyReadFile("filename.txt");
    // 循环读取文本到string字符串里面
    while (getline(MyReadFile, myText))
    {
        // 输出文本
        cout << myText << endl;
    }
    // 关闭文件
    MyReadFile.close();

    cout << endl;

    /**
     * 异常处理
     */
    int age = 13;
    try
    {
        if (age < 18)
        {
            throw 505;
        }
        else
        {
            cout << "you are old enough" << endl;
        }
    }
    catch (...) // catch 知道异常类型的时候就直接给类型  例如 int num,如果不知道类型就写... 可以接收任何类型
    {
        cout << "you must bt at least 18" << endl;
        // cout << "error num is  " << num << endl;
    }

    cout << endl;

    /**
     * 动态内存
     */
    double *pvalue = NULL; // 声明一个基本类型的double类型的指针，命令为pvalue，并赋了一个NULL值----（这里声明指针的格式，在我编辑器格式化代码之后就会变成 double *pvalue，但是之前w3cschool说的是推荐double* pvalue这种写法....）
    // pvalue = new double;
    if (!(pvalue = new double)) // 给pvalue动态赋值,此时如果没有可供分配的内存的话，new double就会返回null，所以pvalue也就是null，null打印出来就是0，此时再取反就是1，然后打印一个oom报错信息，并退出程序
    {
        cout << "Error: out of memory." << endl;
        exit(1);
    }

    delete pvalue; // 释放pvalue所指向的内存

    // 声明一个字符数组类型的指针并给他动态分配内存
    char *pchar = NULL;
    pchar = new char[20];

    // 释放内存
    delete[] pchar; // 注意一下这里释放字符数组所指向的内存的时候，一定是要加上[]的数组符号

    /**
     * 一维数组
     */
    int m = 10;
    int *myArray = new int[m]; // 声明一个int数组类型名叫myArray的指针，数组长度为10，并给他动态分配内存
    // 释放内存
    delete[] myArray;

    cout << endl;

    /**
     * 二维数组：就是一个m*n的矩阵，m行n列，矩阵中的元素可以通过索引来取得，相当于用坐标轴中的(x,y)来获取一个点
     */
    int **p;          // 两个*代表二维
    p = new int *[4]; // 第一维为4行
    for (int i = 0; i < 4; i++)
    {
        p[i] = new int[8];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            p[i][j] = i * j;
        }
    }

    // 打印
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 0)
            {
                cout << endl;
            }
            cout << p[i][j] << " ";
        }
    }

    // 释放申请的堆
    for (int i = 0; i < 4; i++)
    {
        delete[] p[i]; // 注意释放的时候都是需要delete[] xxx的，数组符号[]不能少
    }
    delete[] p;

    cout << endl;
    cout << endl;

    /**
     * 三维数组
     */
    int i, j, k; // p[2][3][4]
    int ***q;    // 三个*代表三维
    q = new int **[2];
    for (i = 0; i < 2; i++)
    {
        q[i] = new int *[3];
        for (j = 0; j < 3; j++)
        {
            q[i][j] = new int[4];
        }
    }

    // 输出 p[i][j][k] 三维数据
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                q[i][j][k] = i + j + k;
                cout << q[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 释放内存
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            delete[] q[i][j];
        }
    }

    for (i = 0; i < 2; i++)
    {
        delete[] q[i];
    }
    delete[] q;

    return 0;
}

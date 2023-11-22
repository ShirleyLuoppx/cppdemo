/**
 * 多线程
 */
#include <iostream>
#include <string>
// 导入线程的头文件
#include <pthread.h>

using namespace std;

// 定义一个宏
#define NUM_THREASD 5
void *say_hello(void *args)
{
    cout << "Hello World!" << endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    pthread_t tids[NUM_THREASD];

    for (int i = 0; i < NUM_THREASD; i++)
    {
        // 创建线程
        int ret = pthread_create(&tids[0], NULL, say_hello, NULL);
        if (ret != 0)
        {
            cout << "pthread_create error ret = " << ret << endl; // 因为这里需要使用g++编辑器来输入命令执行程序，我这里就不执行了，后续的web编程和正则表达式也没有看，考虑到可能不会用到，且计划有变，如果要用到再来仔细看看
        }
    }

    // 线程执行完之后退出线程
    pthread_exit(NULL);


    return 0;
}

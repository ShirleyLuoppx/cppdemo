#include <iostream>
#include <string>
using namespace std;

/**
 * w3cschool c++ 第三章面向对象
 * java也是面向对象编程，java编程语言本身是使用c++编写的，jvm是c语言和汇编语言写的
 */

// 创建一个类
class MyClass
{
public:
    // public的属性
    // c++中，一共又3种访问修饰符：private、public、protected
    // public 允许在类外面访问属性和函数，private 不允许在类外面访问属性和函数，protected 不允许在类外面访问属性和函数，但是允许继承的类访问
    string name; // 类种的属性默认都是private的
    int age;

    string brand;
    string model;
    int year;

    // 类里面的public的方法
    void myFun(string elseStr)
    {
        cout << "this is my function in the MyClass " << elseStr << endl;
    }

    // 如果需要在类外部实现方法，需要先在类的内部定义方法，然后在外部实现的时候，使用类::方法名 即可开始实现
    void outClassFun();

    MyClass()
    { // 构造方法，始终是public的且没有返回值，这点与java一致（也许是因为java本身就是c++写的）
        cout << "this is constructor" << endl;
    }

    // MyClass(string x, string y, int z)
    // {
    //     brand = x;
    //     model = y;
    //     year = z;
    //     cout << "this is constructor brand = " << brand << " model = " << model << " year = " << year << endl;
    // }

    // 跟外部函数同理，构造方法也可以在外部定义
    MyClass(string x, string y, int z);

private:
    int salary; // 私有属性通过共有的get函数获取

public:
    int getSalary()
    {
        return salary;
    };
    void setSalary(int s)
    {
        salary = s;
    };
};

// 在类外部定义构造方法
MyClass::MyClass(string x, string y, int z)
{
    brand = x;
    model = y;
    year = z;
    cout << "this is out class constructor brand = " << brand << " model = " << model << " year = " << year << endl;
}

// 在类外部定义方法
void MyClass::outClassFun()
{
    cout << "this is outClassFun" << endl;
}

/**
 * 继承
 */
class MyClassSon : public MyClass
{
public:
    MyClassSon()
    {
        cout << "this is MyClassSon constructor" << endl;
        name = "ppx";
        cout << "MyClass 's name = " << name << endl;
    }
}; // 注意一下，c++中的类末尾反括号后需要打分号的，这里跟java不一样

// 多级继承
class MyClassGrandSon : public MyClassSon
{
public:
    MyClassGrandSon()
    {
        cout << "this is MyClassGrandSon constructor" << endl;
    }

    void printStr()
    {
        cout << "print sth .." << endl;
    }
};

// 多重继承，就是可以一个类同时继承多个类
class MyClassManyExtend : public MyClass, public MyClassGrandSon
{
};

/**
 * 多态
 */
class Animals
{
public:
    void animalSound()
    {
        cout << "The animal makes a sound" << endl;
    }
};

class Dog : public Animals
{
public:
    void animalSound()
    {
        cout << "The dog says: bow wow" << endl;
    }
};

class Pig : public Animals
{
public:
    void animalSound()
    {
        cout << "The pig says: wee wee" << endl;
    }
};

int main(int argc, char const *argv[])
{

    cout << "----------------------------------" << endl;

    Animals animals;
    animals.animalSound();
    Pig pig;
    pig.animalSound();
    Dog dog;
    dog.animalSound();

    cout << endl;

    MyClassManyExtend myClassManyExtend;
    myClassManyExtend.printStr();

    cout << endl;

    MyClassGrandSon myClassGrandSon;
    myClassGrandSon.outClassFun(); // 孙子类调用爷爷类的函数

    cout << endl;

    MyClassSon myClassSon;
    myClassSon.outClassFun(); // 子类调用父类的public函数

    cout << endl;

    MyClass myClass;
    myClass.name = "w3cschool";
    myClass.age = 17;
    cout << "myClass.name = " << myClass.name << " and myClass.age = " << myClass.age << endl;

    myClass.myFun("sth else");
    myClass.outClassFun();

    MyClass myClass1("fort", "sdfsdf", 1999);
    MyClass myClass2("fort1", "sdfsdf1", 19991);

    cout << endl;

    MyClass testSetFun;
    testSetFun.setSalary(20000);
    int mySalary = testSetFun.getSalary();
    cout << "salary is " << mySalary << endl;

    return 0;
}

//https://www.jianshu.com/p/587ab12f7c88
/*
基类与子类的调用关系：
    子类与基类的构造函数的调用：先调用基类的构造函数然后在返回到子类的构造函数中调用
    对基类指针但是实质为子类的虚函数的调用：如果是正常函数就调用基类的，如果是虚函数就调用子类的
*/
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "this is Base's Constroctor";
        cout << endl;
    }
    void fun1() {
        cout << "this is fun1()" << endl;
    }

    virtual void fun2() {
        cout << "this is fun2()" << endl;
    }
};

class A :public Base {
public:
    A()
    {
        cout << "this is A's constuctor" << endl;
    }
    void fun1()
    {
        cout << "A 's fun1()" << endl;
    }
    virtual void fun2()
    {
        cout << "A's fun2()" << endl;
    }
};


class base {
    int x;
    virtual void func1() {
        printf("base func1\n");
    }
};
class sub :base {
    int y;
};

int main_csdn() {
    Base* base;
    base = new A();//与构造函数有关但是与
    base->fun1();
    base->fun2();

	cout << sizeof(A) << sizeof(Base) << endl;//8个字节 8个字节
    cout << sizeof(base) << sizeof(sub) << endl;//8 24
    system("pause");
    return 0;
}

/*
输出结果：
    this is fun1()-->调用
    A's fun2()
*/
//https://www.jianshu.com/p/587ab12f7c88
/*
����������ĵ��ù�ϵ��
    ���������Ĺ��캯���ĵ��ã��ȵ��û���Ĺ��캯��Ȼ���ڷ��ص�����Ĺ��캯���е���
    �Ի���ָ�뵫��ʵ��Ϊ������麯���ĵ��ã���������������͵��û���ģ�������麯���͵��������
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
    base = new A();//�빹�캯���йص�����
    base->fun1();
    base->fun2();

	cout << sizeof(A) << sizeof(Base) << endl;//8���ֽ� 8���ֽ�
    cout << sizeof(base) << sizeof(sub) << endl;//8 24
    system("pause");
    return 0;
}

/*
��������
    this is fun1()-->����
    A's fun2()
*/
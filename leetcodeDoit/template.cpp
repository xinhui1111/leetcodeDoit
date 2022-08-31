#if 0
#include<iostream>  
#include"template_compile.h"  
using namespace std;


void main_template()
{
    base<int> bobj;
    cout << bobj.add_base(2, 3) << endl;
}
#endif

#include<iostream>
using namespace std;
template <class _T>
class CTest
{
public:
    template <class _N>
    void f() { cout<<1111<<endl;  }
};

template <class _T>
void g()
{
    CTest<_T> tt;
    tt.f<int>();
    cout << "1111" << endl;
}

int main_template1(int argc, char* argv[])
{
    g<int>();
    CTest c=CTest<int>();
    c.f<int>();
    return 0;
}
#pragma once
template<class T>
class base
{
public:
    base() {};
    ~base() {};
    T add_base(T x, T y);//ǰ��û�м�ģ����������ԾͿ���ֱ�ӵ��ã����ü�<float>
};

template<class T>
T base<T>::add_base(T x, T y)
{
    return x + y;
}
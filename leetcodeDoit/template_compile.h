#pragma once
template<class T>
class base
{
public:
    base() {};
    ~base() {};
    T add_base(T x, T y);//前面没有加模板参数，所以就可以直接调用，不用加<float>
};

template<class T>
T base<T>::add_base(T x, T y)
{
    return x + y;
}
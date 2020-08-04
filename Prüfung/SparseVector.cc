#include "SparseVector.h"
#include "SparseVectorIterator.h"

template <typename T, int N>
ostream &operator<<(ostream &os, SparseVector<T, N> v)
{
    os << "[ ";
    for (auto [idx, value] : values(v))
    {
        os << value << " ";
    }
    os << "]" << std::endl;
    return os;
}

//Skalarmultiplikation
template <typename A, typename T, int N>
SparseVector<T, N> &operator*(A const a, SparseVector<T, N> &v)
{
    for (auto [idx, value] : values(v))
    {
        v.set(idx, a * value);
    }
    return v;
}

//Skalarprodukt
template <typename T, int N>
T operator*(SparseVector<T, N> &v, SparseVector<T, N> &w)
{
    T res = 0;
    auto it_w = values(w).begin();
    for (auto it_v=values(v).begin(); it_v != values(v).end(); ++it_v)
    {
        while (it_w < it_v)
        {
            ++it_w;
        }
        if (it_w == it_v)
        {
            res += (*it_w).second * (*it_v).second;
        }
    }
    return res;
}

//Addition
template <typename T, int N>
SparseVector<T, N> operator+(SparseVector<T, N> &v, SparseVector<T, N> &w)
{
    SparseVector<T, N> res;
    auto it_w = values(w).begin();
    for (auto it_v=values(v).begin(); it_v != values(v).end(); ++it_v)
    {
        while (it_w < it_v)
        {
            ++it_w;
        }
        if (it_w == it_v)
        {
            res.set((*it_w).first,(*it_w).second + (*it_v).second);
        }
    }
    return res;
}

//Subtraktion
template <typename T, int N>
SparseVector<T, N> operator-(SparseVector<T, N> &v, SparseVector<T, N> &w)
{
    SparseVector<T, N> res;
    auto it_w = values(w).begin();
    for (auto it_v=values(v).begin(); it_v != values(v).end(); ++it_v)
    {
        while (it_w < it_v)
        {
            ++it_w;
        }
        if (it_w == it_v)
        {
            res.set((*it_w).first,(*it_v).second - (*it_w).second);
        }
    }
    return res;
}

int main()
{
    std::array<double, 7> a = {1, 0, 0, 0, 4.5, 5, 0 };
    SparseVector<double, 7> v{a};

    std::array<double, 7> b = {4, 0, 0, 0, 0, 1, 4.3 };
    SparseVector<double, 7> w{b};

    std::cout << v << std::endl;
    std::cout << w << std::endl;

    double s = v * w;
    std::cout << s << std::endl;

    std::cout << v+w << std::endl;
    std::cout << v-w << std::endl;

    w.set(1,0);
    w.set(2,3);
    std::cout << w << std::endl;

    return 0;
}
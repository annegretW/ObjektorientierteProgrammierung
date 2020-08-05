#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

#include <map>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/*
* Class giving an efficient representation of a sparse vector
* Template parameters: T - types of vector entries, N - dimension of vector
*/
template <typename T, int N>
class SparseVector
{

    //allow iterator and range classes to access private member variables
    template <typename V, int M>
    friend class SparseVectorIterator;
    template <typename V, int M>
    friend class SparseVectorRange;

private:
    //map containing index and value of non-zero values of the vector
    map<int, T> data_ = {};

public:
    //Default Constructor
    SparseVector(){};

    //Constructor creating sparse vector out of a given standard array
    SparseVector(std::array<T, N> data)
    {
        for (int i = 0; i < N; i++)
        {
            if (data[i] != 0)
            {
                data_[i] = data[i];
            }
        }
    }

    //Operator returning the vector entry at index i
    T operator[](unsigned int i)
    {
        //check if i is a valid index
        assert(i < N);

        if (data_.find(i) != data_.end())
        {
            return data_[i];
        }
        else
        {
            return 0;
        }
    }

    //Function to set a vector entry
    void set(int i, T value)
    {
        //check if i is a valid index
        assert(i < N);

        if (value != 0)
        {
            data_[i] = value;
        }
        else
        {
            data_.erase(i);
        }
    }

    //Function to return the dimension of the vector
    int size() const
    {
        return N;
    }

    //Function to return the entries of the vector as index-values-pairs
    const map<int, T> &data() const
    {
        return data_;
    }
};

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
    auto it_w = w.data().begin();
    for (auto it_v = v.data().begin(); it_v != v.data().end(); ++it_v)
    {
        while ((*it_w).first < (*it_v).first)
        {
            ++it_w;
        }
        if ((*it_w).first == (*it_v).first)
        {
            res += (*it_w).second * (*it_v).second;
        }
    }
    return res;
}

//Addition
template <typename T, int N>
SparseVector<T, N> &operator+(SparseVector<T, N> &v, SparseVector<T, N> &w)
{
    for (auto it_w = w.data().begin(); it_w != w.data().end(); ++it_w)
    {
        v.set((*it_w).first, v[(*it_w).first] + (*it_w).second);
    }
    return v;
}

//Subtraktion
template <typename T, int N>
SparseVector<T, N> operator-(SparseVector<T, N> &v, SparseVector<T, N> &w)
{
    for (auto it_w = w.data().begin(); it_w != w.data().end(); ++it_w)
    {
        v.set((*it_w).first, v[(*it_w).first] - (*it_w).second);
    }
    return v;
}

#endif
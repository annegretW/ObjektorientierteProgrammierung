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
    T operator[](int i)
    {
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
    void set(int i, T value){
        if (value != 0){
            data_[i] = value;
        }
        else {
            data_.erase(i);
        }
    }

    //Function to return the dimension of the vector
    int size() const
    {
        return N;
    }
};

#endif
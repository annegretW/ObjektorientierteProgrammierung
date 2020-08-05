#ifndef SPARSEVECTORITERATOR
#define SPARSEVECTORITERATOR

#include "SparseVector.h"

/*
* Class representing an iterator of a sparse vector
* Template parameters: T - types of vector entries, N - dimension of vector
*/
template <typename T, int N>
class SparseVectorIterator
{
private:
    SparseVector<T, N> &vector_;
    unsigned int idx_;

public:
    SparseVectorIterator(SparseVector<T, N> &v, int i)
        : vector_(v), idx_(i) {}

    bool operator==(const SparseVectorIterator<T,N> &it) const
    {
        return idx_==it.idx_;
    }

    bool operator!=(const SparseVectorIterator<T,N> &it) const
    {
        return !((*this)==it);
    }

    bool operator<(const SparseVectorIterator<T,N> &it) const
    {
        return idx_<it.idx_;
    }

    SparseVectorIterator<T,N> &operator++()
    {
        idx_++;
        return *this;
    }

    std::pair<const unsigned int, T> operator*()
    {
        return {idx_, vector_[idx_]};
    }

    std::pair<const unsigned int, T&> operator->(){
        return *(*this);
    }
};

/*
* Class representing the range of a sparse vector
* Template parameters: T - types of vector entries, N - dimension of vector
*/
template <typename T, int N>
class SparseVectorRange
{
private:
    SparseVector<T, N> &vector_;

public:
    SparseVectorRange(SparseVector<T, N> &v)
        : vector_(v){};

    SparseVectorIterator<T, N> begin()
    {
        return {vector_, 0};
    }

    SparseVectorIterator<T, N> end()
    {
        return {vector_, N};
    }
};

template <typename T, int N>
SparseVectorRange<T,N> values(SparseVector<T,N>& v){
  return v;
}

#endif
#ifndef MYVEC_H
#define MYVEC_H

#include<iostream>
#include<exception>
using namespace std;

template<typename T>
class myVec
{
public:
    // constructors
    myVec();
    myVec(size_t size);
    myVec(T* array, size_t size);
    ~myVec();

    // getters
    size_t size() const;
    size_t capacity() const;

    // mutators
    void insert(const T& newValue);
    void remove(size_t index);
    void clear();

    // operators
    T operator[](size_t index) const;
    myVec& operator=(const myVec& RHS);
private:
    T *array_;
    size_t size_;
    size_t capacity_;
};

#endif

template<typename T>
myVec<T>::myVec()
{
    array_ = new T[10];
    size_ = 0;
    capacity_ = 10;
}

template<typename T>
myVec<T>::myVec(size_t size)
{
    array_ = new T[size];
    size_ = 0;
    capacity_ = size;
}

template<typename T>
myVec<T>::~myVec()
{
    clear();
}

template<typename T>
size_t myVec<T>::size() const
{
    return size_;
}

template<typename T>
size_t myVec<T>::capacity() const
{
    return capacity_;
}

template<typename T>
void myVec<T>::insert(const T& newValue)
{
    ++size_;
    if (size_ > capacity_)
    {
        capacity_ *= 2;
        T* temp;
        temp = new T[capacity_];
        for (int i = 0; i < size_; ++i)
        {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    array_[size_ - 1] = newValue;
}

template<typename T>
void myVec<T>::remove(size_t index)
{
    if (index < size_)
    {
        while (index < size_)
        {
            array_[index] = array_[index + 1];
            ++index;
        }

        --size_;
    }
}

template<typename T>
void myVec<T>::clear()
{
    delete[] array_;
}

template<typename T>
T myVec<T>::operator[](size_t index) const
{

    if (index < size_ && index >= 0)
    {
        return array_[index];
    }

    else
        throw invalid_argument("Out of range of vector.\n");

}

template<typename T>
myVec<T>& myVec<T>::operator=(const myVec& RHS)
{
    if (this != &RHS)
    {
        size_ = RHS.size_;
        capacity_ = RHS.capacity_;
        array_ = new T[capacity_];
        for (unsigned int i = 0; i < size_; ++i)
        {
            array_[i] = RHS.array_[i];
        }

    }

    return *this;
}
/**
 *  File        :   d_array.cpp
 *  Explain     :   C++ dynamic array implementation like std::vector
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

// implementation of d_array.hpp
#include <stdexcept>


template<class _Ty>
DArray<_Ty>::DArray() : data(nullptr), index(), _capacity(4)
{
    data = new _Ty[_capacity];
}


template<class _Ty>
DArray<_Ty>::~DArray() 
{
    delete[] data;
}



template<class _Ty>
DArray<_Ty>::DArray(std::initializer_list<_Ty> l) : index(0) 
{
    _capacity = l.end() - l.begin();

    data = new _Ty[_capacity];
    
    for (auto listVal : l)
        data[index++] = listVal;
}


template<class _Ty>
const bool DArray<_Ty>::empty() const
{
    return index == 0;
}


template<class _Ty>
const size_t DArray<_Ty>::size() const
{
    return index;
}


template<class _Ty>
const size_t DArray<_Ty>::capacity() const
{
    return _capacity;
}


template<class _Ty>
void DArray<_Ty>::shrinkToFit() 
{
    _capacity = index;
}


template<class _Ty>
_Ty& DArray<_Ty>::at(size_t i) 
{
    if (i >= _capacity)
       std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");

    return data[i];
}


template<class _Ty>
const _Ty& DArray<_Ty>::at(size_t i) const
{
    if (i >= _capacity)
       std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");

    return data[i];
}


template<class _Ty>
_Ty& DArray<_Ty>::operator [](size_t i) 
{
    return at(i);
}


template<class _Ty>
const _Ty& DArray<_Ty>::operator [](size_t i) const
{
    return at(i);
}


template<class _Ty>
_Ty DArray<_Ty>::front() const
{
    return data + 0;
}


template<class _Ty>
_Ty DArray<_Ty>::back() const
{
    return data + size;
}


template<class _Ty>
void DArray<_Ty>::push_back(const _Ty& val) 
{
    if (size() == capacity())
    {
        _capacity *= 2;
        reAlloc();
    }
    
    data[index++] = val;
}


template<class _Ty>
void DArray<_Ty>::pop_back()
{
    if (empty())
        throw std::out_of_range("Error...!");
    
    data[index--].~_Ty();

    if ((size() == (capacity() / 2)) && (size() >= 4))
    {
        _capacity /= 2;
        reAlloc();
    }
    
}


template<class _Ty>
void DArray<_Ty>::reAlloc() 
{
    _Ty* temp = new _Ty[_capacity];

    for (size_t i = 0; i < size(); ++i)
        temp[i] = data[i];
    
    delete[] data;

    data = temp;
}

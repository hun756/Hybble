/**
 *  File        :   array.tcc
 *  Explain     :   C++ Array implementation like std::array
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

// implementation of array.hpp
#include "array.hpp"
#include <stdexcept>


template<class T, size_t MaxSize>
Array<T, MaxSize>::Array(std::initializer_list<T> l) 
{
    if (l.size() > MaxSize)
        throw std::out_of_range("Error..! Array limit exceeded.");
    
    int i = 0;
    for (auto iter = l.begin(); iter != l.end(); ++iter)
        data[i++] = *iter;   
}


template<class T, size_t MaxSize>
const bool Array<T, MaxSize>::empty() const
{
    return MaxSize == 0;
}


template<class T, size_t MaxSize>
const size_t Array<T, MaxSize>::size() const
{
    return MaxSize;
}


template<class T, size_t MaxSize>
const size_t Array<T, MaxSize>::maxSize() const
{
    return MaxSize;
}


template<class T, size_t MaxSize>
inline T& Array<T, MaxSize>::at(size_t index) 
{
    if (index >= MaxSize)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");
    
    return data[index];
}


template<class T, size_t MaxSize>
T Array<T, MaxSize>::front() const
{
    return data[0];
}


template<class T, size_t MaxSize>
T Array<T, MaxSize>::back() const
{
    return data[MaxSize - 1];
}


template<class T, size_t MaxSize>
T& Array<T, MaxSize>::operator [](size_t index) 
{
    return at(index);
}


template<class T, size_t MaxSize>
const T& Array<T, MaxSize>::operator [](size_t index) const
{
    if (index >= MaxSize)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");
    
    return data[index];
}


template<class T, size_t MaxSize>
void Array<T, MaxSize>::swap(Array<T, MaxSize>& arr) 
{
    Array<T, MaxSize> temp;
    temp = data;
    data = arr;
    arr = temp;
}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::iterator Array<T, MaxSize>::begin() 
{
    return iterator(&data[0]);
}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::iterator Array<T, MaxSize>::end() 
{
    return iterator(&data[MaxSize]);
}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::const_iterator Array<T, MaxSize>::begin() const
{
    // return const_iterator(&data[0]);
}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::const_iterator Array<T, MaxSize>::end() const
{
    // return const_iterator(&data[MaxSize]);
}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::const_iterator Array<T, MaxSize>::cbegin() const
{

}


template<class T, size_t MaxSize>
typename Array<T, MaxSize>::const_iterator Array<T, MaxSize>::cend() const
{

}

template<class T, size_t MaxSize>
bool operator==(const Array<T, MaxSize> &lhs, const Array<T, MaxSize> &rhs) {
    return false;
}

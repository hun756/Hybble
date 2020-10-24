/**
 *  File        :   array.cpp
 *  Explain     :   C++ Array implementation like std::array
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

// implementation of array.hpp

#include "array.hpp"
#include <stdexcept>


template<class _Ty, size_t MaxSize>
Array<_Ty, MaxSize>::Array(std::initializer_list<_Ty> l) 
{
    size_t capControl = l.end() - l.begin();

    if (capControl > MaxSize)
        throw std::out_of_range("Error..! Array limit exceeded.");
    
    int i = 0;
    for (auto iter = l.begin(); iter != l.end(); ++iter)
        data[i++] = *iter;   
}


template<class _Ty, size_t MaxSize>
const bool Array<_Ty, MaxSize>::empty() const
{
    return MaxSize == 0;
}


template<class _Ty, size_t MaxSize>
const size_t Array<_Ty, MaxSize>::size() const
{
    return MaxSize;
}


template<class _Ty, size_t MaxSize>
const size_t Array<_Ty, MaxSize>::maxSize() const
{
    return MaxSize;
}


template<class _Ty, size_t MaxSize>
inline _Ty& Array<_Ty, MaxSize>::at(size_t index) 
{
    if (index >= MaxSize)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");
    
    return data[index];
}


template<class _Ty, size_t MaxSize>
_Ty Array<_Ty, MaxSize>::front() const
{
    return data[0];
}


template<class _Ty, size_t MaxSize>
_Ty Array<_Ty, MaxSize>::back() const
{
    return data[MaxSize - 1];
}


template<class _Ty, size_t MaxSize>
_Ty& Array<_Ty, MaxSize>::operator [](size_t index) 
{
    return at(index);
}


template<class _Ty, size_t MaxSize>
const _Ty& Array<_Ty, MaxSize>::operator [](size_t index) const
{
    if (index >= MaxSize)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");
    
    return data[index];
}


template<class _Ty, size_t MaxSize>
void Array<_Ty, MaxSize>::swap(Array<_Ty, MaxSize>& arr) 
{
    Array<_Ty, MaxSize> temp;
    temp = data;
    data = arr;
    arr = temp;
}


template<class _Ty, size_t MaxSize>
typename Array<_Ty, MaxSize>::iterator Array<_Ty, MaxSize>::begin() 
{
    return iterator(&data[0]);
}


template<class _Ty, size_t MaxSize>
typename Array<_Ty, MaxSize>::iterator Array<_Ty, MaxSize>::end() 
{
    return iterator(&data[MaxSize]);
}


template<class _Ty, size_t MaxSize>
const typename Array<_Ty, MaxSize>::const_iterator Array<_Ty, MaxSize>::begin() const
{
    // return const_iterator(&data[0]);
}


template<class _Ty, size_t MaxSize>
const typename Array<_Ty, MaxSize>::const_iterator Array<_Ty, MaxSize>::end() const
{
    // return const_iterator(&data[MaxSize]);
}


template<class _Ty, size_t MaxSize>
typename Array<_Ty, MaxSize>::const_iterator Array<_Ty, MaxSize>::cbegin() const
{

}


template<class _Ty, size_t MaxSize>
typename Array<_Ty, MaxSize>::const_iterator Array<_Ty, MaxSize>::cend() const
{

}

/**
 *  File        :   d_array.tcc
 *  Explain     :   C++ dynamic array implementation like std::vector
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/


#include <stdexcept>

template<class T>
DArray<T>::DArray() : data(nullptr), index(), _capacity(4)
{
    data = new T[_capacity];
}


template<class T>
DArray<T>::~DArray()
{
    delete[] data;
}



template<class T>
DArray<T>::DArray(std::initializer_list<T> l) : index(0)
{
    _capacity = l.end() - l.begin();

    data = new T[_capacity];

    for (auto listVal : l)
        data[index++] = listVal;
}


template<class T>
const bool DArray<T>::empty() const
{
    return index == 0;
}


template<class T>
const size_t DArray<T>::size() const
{
    return index;
}


template<class T>
const size_t DArray<T>::capacity() const
{
    return _capacity;
}


template<class T>
void DArray<T>::shrinkToFit()
{
    _capacity = index;
}


template<class T>
T& DArray<T>::at(size_t i)
{
    if (i >= _capacity)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");

    return data[i];
}


template<class T>
const T& DArray<T>::at(size_t i) const
{
    if (i >= _capacity)
        std::out_of_range("Error..! The index you want to reach is exceed the bounds of the array.");

    return data[i];
}


template<class T>
T& DArray<T>::operator [](size_t i)
{
    return at(i);
}


template<class T>
const T& DArray<T>::operator [](size_t i) const
{
    return at(i);
}


template<class T>
T DArray<T>::front() const
{
    return data + 0;
}


template<class T>
T DArray<T>::back() const
{
    return data + size();
}


template<class T>
void DArray<T>::pushBack(const T& val)
{
    if (size() == capacity())
    {
        _capacity *= 2;
        reAlloc();
    }

    data[index++] = val;
}


template<class T>
void DArray<T>::popBack()
{
    if (empty())
        throw std::out_of_range("Error...!");

    data[index--].~T();

    if ((size() == (capacity() / 2)) && (size() >= 4))
    {
        _capacity /= 2;
        reAlloc();
    }

}


// template<class T>
// template<class... Args>
// T& DArray<T>::emplaceBack(Args&&... args)
// {
//     if (size() >= _capacity)
//     {
//        _capacity *= 2;
//        reAlloc();
//     }

//    data[index] = T(std::forward<Args>(args)...);
//    return data[index++];
// }


template<class T>
void DArray<T>::reAlloc()
{
    T* temp = new T[_capacity];

    for (size_t i = 0; i < size(); ++i)
        temp[i] = data[i];

    delete[] data;

    data = temp;
}
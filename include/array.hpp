/**
 *  File        :   array.hpp
 *  Explain     :   C++ Array implementation like std::array
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of :  ARRAY_HPP */
#ifndef ARAY_HPP
#define ARAY_HPP


// Header files
#include <initializer_list>                 // for constructor with brace installer
#include <cstddef>                          // for size_t usage 
#include "dependencies/array_iterator.hpp"  // iterator classes for iterative operations of Array class.
#include <array>

template <class _Ty, size_t MaxSize>
class Array
{
public:
    using const_iterator            =   ConstIterator<_Ty, MaxSize>;
    using iterator                  =   Iterator<_Ty, MaxSize>;
    using reverse_iterator          =   ReverseIterator<_Ty, MaxSize>;

public:

    /**
     *  Default empty constructor.
    **/
    Array() = default;


    /**
     *  Constructor with initializer list
     *  Usage : Array<> a { 1, 2, 3, 4 };
     *  @param  l   ->  class std::initializer_list& 
    **/
    Array(std::initializer_list<_Ty>);


    /**
     *  empty() method : if array size equal 0, returns true.
     *  @return MaxSize in Template Parameter -> MaxSize ? 1 : 0
    **/
    const bool empty() const;


    /**
     *  @return value of MaxSize;
    **/
    const size_t size() const;


    /**
     *  @return value of MaxSize;
    **/
    const size_t maxSize() const;
    
    
    /**
     *  at() method : accessing to array element.
     * 
     *  @param      size_t     index    -> the index of the array to be accessed.
     *  @return     _Ty&                -> reference of template type. 
    **/
    _Ty& at(size_t);


    /**
     *  front() method : returns first element in the array.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty front() const;

    
    /**
     *  back() method :  returns last element in the array.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty back() const;


    /**
     *  overloading operator [] : accessing to array element.
     * 
     *  @param      size_t     index    -> the index of the array to be accessed.
     *  @return     _Ty&                -> reference of template type. 
    **/
    _Ty& operator [](size_t);

    const _Ty& operator [](size_t) const;

    
    /**
     *  swap() method : accessing to array element.
     * 
     *  @param      Array&     arr    -> the index of the array to be accessed.
    **/
    void swap(Array<_Ty, MaxSize>&);


    /* Iterative Methods */


    /**
     *  begin() method : a pointer that returns the starting point of the array.
     * 
     *  @return object from class Iterator
    **/
    iterator begin();


    /**
     *  end() method : a pointer that returns the ending point of the array.
     * 
     *  @return object from class Iterator
    **/
    iterator end();


    /**
     *  begin() method : a const pointer that returns the starting point of the array.
     * 
     *  @return object from class ConstIterator
    **/
    const const_iterator begin() const;


    /**
     *  end() method : a const pointer that returns the ending point of the array.
     * 
     *  @return object from class ConstIterator
    **/
    const const_iterator end() const;


    /**
     *  cbegin() method : a const (always) pointer that returns the starting point of the array.
     * 
     * 
     *  @return object from class ConstIterator
    **/
    const_iterator cbegin() const;


    /**
     *  cend() method : a const (always) pointer that returns the ending point of the array.
     * 
     *  @return object from class ConstIterator
    **/
    const_iterator cend() const;


    /**
     *  crbegin() method : a pointer that returns the ending point of the array.
     *                     The iteration direction is from the end of the array to the beginning.
     * 
     *  @return object from class ReverseIterator
    **/
    // reverse_iterator crbegin();


    /**
     *  crend() method : a pointer that returns the starting point of the array.
     *                   The iteration direction is from the end of the array to the beginning.
     * 
     *  @return object from class ReverseIterator
    **/
    // reverse_iterator crbend();


private:
    _Ty data[MaxSize];
};

#include "../src/array.cpp"

#endif /* end of include guard : ARAY_HPP */

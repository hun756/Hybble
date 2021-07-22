/**
 *  File        :   array.hpp
 *  Explain     :   C++ Array implementation like std::array
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of :  ARRAY_HPP */
#ifndef ARRAY_HPP
#define ARRAY_HPP


//> Header files
#include <initializer_list>                 //> for constructor with brace installer
#include <cstddef>                          //> for size_t usage
#include "dependencies/array_iterator.hpp"  //> iterator classes for iterative operations of Array class.
#include <array>

namespace DSinCpp {
    template <class T, size_t MaxSize>
    class Array
    {
    public:
        using const_iterator            =   ConstIterator<T, MaxSize>;
        using iterator                  =   Iterator<T, MaxSize>;
        using reverse_iterator          =   ReverseIterator<T, MaxSize>;
        using const_reverse_iterator    =   ConstReverseIterator<T, MaxSize>;

    public:

        /**
        *  @brief
        *      Construct a new DArray object
    **/
        Array() = default;


        /**
        *  @brief
        *      Construct a new DArray object
        *
        *  @param  l
        *      Object from initializer_list class.
        **/
        Array(std::initializer_list<T>);


        friend bool operator ==(const Array<T, MaxSize>& lhs, const Array<T, MaxSize>& rhs);


        /**
        *  @brief
        *      This method checks if the array is empty.
        *
        *  @return
        *      value of bool
        *
        *  @retval
        *      true if index == 0
        **/
        [[nodiscard]] const bool empty() const;


        /**
        *  @brief
        *      This method returns the number of elements of the array.
        *
        *  @return
        *      size_t
        *
        *  @retval
        *      index
        **/
        [[nodiscard]] const size_t size() const;


        /**
        *  @brief
        *      This method returns the maximum number of elements
        *      the array can hold.
        *
        *  @return
        *      <size_t> maxsize value.
        **/
        [[nodiscard]] const size_t maxSize() const;


        /**
        *  @brief
        *      This method takes the desired array element as a parameter.
        *
        *  @param[in]
        *      It is the index of the directory to be accessed.
        *
        *  @return
        *      T&  reference from template
        **/
        T& at(size_t);


        /**
        *  @brief
        *      This method :  returns first element in the array.
        *
        *  @return
        *      the first element of the array.
        **/
        T front() const;


        /**
        *  @brief
        *      This method :  returns first element in the array.
        *
        *  @return
        *      the last element of the array.
        **/
        T back() const;


        /**
        *  @brief
        *      overloading operator [] : takes the desired array element
        *      as a parameter.
        *
        *  @param[in]
        *      It is the index of the directory to be accessed.
        *
        *  @return
        *      T&  reference from template
        **/
        T& operator [](size_t);

        const T& operator [](size_t) const;


        /**
        *  swap() method : accessing to array element.
        *
        *  @param      Array&     arr    -> the index of the array to be accessed.
        **/
        void swap(Array<T, MaxSize>&);


        /* Iterative Methods */


        /**
        *  @brief
        *      This method  a pointer that returns the starting point of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        iterator begin();


        /**
        *  @brief
        *      This method a pointer that returns the ending point of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        iterator end();


        /**
        *  @brief
        *      This method a const pointer that returns the ending
        *      point of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        const_iterator begin() const;


        /**
        *  @brief
        *      This method a const pointer that returns the ending
        *      point of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        const_iterator end() const;


        /**
        *  @brief
        *      This method a const pointer that returns the starting point
        *      of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        reverse_iterator rbegin();


        /**
        *  @brief
        *      This method a const pointer that returns the ending point
        *      of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        reverse_iterator rend();


        /**
        *  @brief
        *      This method : a const pointer that returns the starting point
        *      of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        const_reverse_iterator rbegin() const;


        /**
        *  @brief
        *      This method : a const pointer that returns the ending point
        *      of the array.
        *
        *  @return
        *      object from class Iterator
        **/
        const_reverse_iterator rend() const;


        /**
        *  @brief
        *      This method : a const (always) pointer that returns
        *      the starting point of the array.
        *
        *
        *  @return
        *      object from class ConstIterator
        **/
        const_iterator cbegin() const;


        /**
        *  @brief
        *      This method : a const (always) pointer that returns
        *      the ending point of the array.
        *
        *  @return
        *      object from class ConstIterator
        **/
        const_iterator cend() const;


        /**
        *  @brief
        *      This method a pointer that returns the ending point of the array.
        *      the ending point of the array.
        *
        *  @return
        *      object from class ConstIterator
        **/
        const_reverse_iterator crbegin() const;


        /**
        *  @brief
        *      This method a pointer that returns the starting
        *      point of the array.
        *      The iteration direction is from the end of the array
        *      to the beginning.
        *
        *  @return
        *      object from class ConstIterator
        **/
        const_reverse_iterator crbend() const;


    private:
        T data[MaxSize];
    };
}

#include "array.tcc"

#endif /* end of include guard : ARRAY_HPP */
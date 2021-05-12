/**
 *  File        :   singly_list.hpp
 *  Explain     :   C++ singly linked list implementation.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of : SINGLY_LIST_HPP */
#ifndef SINGLY_LIST_HPP
#define SINGLY_LIST_HPP


#include <initializer_list>
#include <cstddef>
#include "dependencies/list_node.hpp"
#include "dependencies/list_iterator.hpp"



template <class T>
class SinglyList
{
public:
    using       nodeptr     =       SinglyNode<T>*;
    using       node        =       SinglyNode<T>;
public:

    /**
     *  constructor
    **/
    SinglyList();


    /**
     *  Constructor with initializer list 
     *
     *  @param      l   ->      object from initializer_list class
    **/
    SinglyList(std::initializer_list<T>);


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
    const bool empty() const;


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
    const size_t size() const;


    /**
     *  @brief
     *      This method adds an element to the ending of
     *      the dynamic array.
     *
     *  @param  val
     *      It is the value of the element to be added.
    **/
    void push_back(const T&);


    /**
     *  @brief
     *      This method adds an element to the beginning of
     *      the dynamic array.
     *
     *  @param  val
     *      It is the value of the element to be added.
    **/
    void push_front(const T&);


    /**
     *  @brief
     *      This method removes the last item from list.
    **/
    void pop_back();


    /**
     *  @brief
     *      This method removes the first item from list.
    **/
    void pop_front();


    /**
     *  @brief
     *      This method clears the contents of the list
    **/
    void clear();


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

private:
    nodeptr     head;
    nodeptr     tail;
    size_t      theSize = 0;
};


template <class T>
class CircularSinlyList : public SinglyList<T>
{

};


//> template implementation
#include "singly_list.tcc"

#endif /* end of include guard : SINGLY_LIST_HPP */
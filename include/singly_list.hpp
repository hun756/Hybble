/**
 *  File        :   singly_list.hpp
 *  Explain     :   C++ singly linked list implementation.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020      last : 24.10.2020 (edited)
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



template <class _Ty>
class SinglyList
{
public:
    using       nodeptr     =       SinglyNode<_Ty>*;
    using       node        =       SinglyNode<_Ty>;
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
    SinglyList(std::initializer_list<_Ty>);


    /**
     *  empty() method : if list has no element, return true.
     *
     *  @return 	 value of bool  ->  (head == NULL)
    **/
    const bool empty() const;


    /**
     *  size() method : returns elemnt's count.
     *
     *  @return     theSize : unsigned int    ->    //
    **/
    const size_t size() const;


    /**
     *  push_back() method : Typeadds an element to the ending of the list.
     *
     *  @param 		 val : const template reference
    **/
    void push_back(const _Ty&);


    /**
     *  push_front() method : Typeadds an element to the beginning of the list.
     *
     *  @param 		  val : const template reference
    **/
    void push_front(const _Ty&);


    /**
     *  pop_back() method : Removes the last item from list.  
     * 
    **/
    void pop_back();


    /**
     *  pop_front() method : Removes the first item from list.
     *
    **/
    void pop_front();


    /**
     *  clear() method : clears the contents of the list
    **/
    void clear();


    /**
     *  front() method :  returns first element in the list.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty front() const;


    /**
     *  back() method :  returns last element in the list.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty back() const;

private:
    nodeptr     head;
    nodeptr     tail;
    size_t      theSize = 0;
};


template <class _Ty>
class CircularSinlyList : public SinglyList<_Ty>
{

};

#include "../src/singly_list.cpp"

#endif /* end of include guard : SINGLY_LIST_HPP */
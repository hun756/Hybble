/**
 *  File        :   doubly_list.hpp
 *  Explain     :   C++ doubly linked list implementation like std::list<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020      last : 24.10.2020 (edited)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* include guard of : DOUBLY_LİST_HPP */
#ifndef DOUBLY_LIST_HPP
#define DOUBLY_LIST_HPP

#include <initializer_list>
#include "dependencies/list_node.hpp"


template <class _Ty>
class DoublyList
{
public:
    using      nodeptr      =     DoublyNode<_Ty>*;
    using      node         =     DoublyNode<_Ty>;
    using      Iterator     =     Iterator<_Ty>;
public:

     /**
     *  constructor
    **/
    DoublyList();


   /**
     *  Constructor with initializer list 
     *
     *  @param      l   ->      object from initializer_list class
    **/
    DoublyList(std::initializer_list<_Ty>);


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


    /* Iterative methods */

    /**
     *  begin() method :    return adress of first element
     *  end()   method :    return adress of last element  
     * 
     *  @return     object from iterator class
    **/
    Iterator begin();

    Iterator end();

private:

    nodeptr head;
    nodeptr tail;
    size_t  theSize = 0;

};


template <class _Ty>
class CircularDoublyList : public DoublyList<_Ty>
{

};

#include "../src/doubly_list.cpp"

#endif
/* end of include guard : DOUBLY_LİST_HPP */
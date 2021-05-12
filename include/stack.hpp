/**
 *  File        :   stack.hpp
 *  Explain     :   C++ stack implementation like std::stack
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of : STACK_HPP */
#ifndef STACK_HPP
#define STACK_HPP

#include <initializer_list>
#include <cstddef>
#include "list.hpp"

template <class T, class Container = List<T>>
class Stack
{
public:
    Stack();


    Stack(std::initializer_list<T>);


    const bool empty() const;


    const size_t size() const;


    void push(constT&);


    void pop();


   T top();


    void swap(Stack<T>&);

    

private:
    Container con {};
};

#include "stack.tcc"

#endif /* end of include guard : STACK_HPP */
/**
 *  File        :   doubly_list.cpp
 *  Explain     :   C++ doubly_list implementation like std::list<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   23.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* implementation of doubly_list.hpp */
#include "doubly_list.hpp"



template<class _Ty>
DoublyList<_Ty>::DoublyList() : head(nullptr), tail(nullptr)
{

}


template<class _Ty>
DoublyList<_Ty>::DoublyList(std::initializer_list<_Ty> l) 
{
    // none
}


template<class _Ty>
const bool DoublyList<_Ty>::empty() const
{
    return head == nullptr;
}


template<class _Ty>
const size_t DoublyList<_Ty>::size() const
{
    return theSize;
}


template<class _Ty>
void DoublyList<_Ty>::push_back(const _Ty& val) 
{
    if (head == nullptr)
    {
        head = new node(val);
        tail = head;
    }
    
    else
    {
        nodeptr temp = new node(val);
        tail->next   = temp;
        temp->prev   = tail; 
        tail = temp;
    }

    ++theSize;
}


template<class _Ty>
void DoublyList<_Ty>::push_front(const _Ty& val)  
{
    if (head == nullptr)
    {
        head = new node(val);
        tail = head;
    }
    
    else
    {
        nodeptr temp = new node(val);
        head->prev = temp;
        head = temp;
    }

    ++theSize;
}


template<class _Ty>
void DoublyList<_Ty>::pop_back() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_back()");

    nodeptr temp = tail;
    tail = tail->prev;
    delete temp;

    --theSize;
}


template<class _Ty>
void DoublyList<_Ty>::pop_front() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_front()");

    nodeptr temp = head;
    head = head->next;
    delete temp;
    head->prev = nullptr;
    
    --theSize;
}


template<class _Ty>
void DoublyList<_Ty>::clear() 
{
    nodeptr temp;
    
    while (head != tail->next)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;

    theSize = 0;
}


template<class _Ty>
_Ty DoublyList<_Ty>::front() const
{
    if (empty())
        throw std::domain_error("List is empty : front()");

    return head->data;
}


template<class _Ty>
_Ty DoublyList<_Ty>::back() const
{
    if (empty())
        throw std::domain_error("List is empty : back()");

    return tail->data;
}


template<class _Ty>
typename DoublyList<_Ty>::Iterator DoublyList<_Ty>::begin() 
{
    return head;
}


template<class _Ty>
typename DoublyList<_Ty>::Iterator DoublyList<_Ty>::end() 
{
    return tail->next;
}
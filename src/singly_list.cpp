/**
 *  File        :   singly_list.cpp
 *  Explain     :   C++ Singly list implementation like std::list<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   23.10.2020      last : 25.10.2020 (edited)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* implementation of singly_list.hpp */

#include "singly_list.hpp"

template<class _Ty>
SinglyList<_Ty>::SinglyList() : head(nullptr), tail(nullptr)
{

}


template<class _Ty>
SinglyList<_Ty>::SinglyList(std::initializer_list<_Ty> l) 
{
    // for (auto iter = l.begin(); iter != l.end(); ++iter)
    // {   
    //     const _Ty val = *iter; 
    //     push_back(val);
    // }
}


template<class _Ty>
const bool SinglyList<_Ty>::empty() const
{
    return head == nullptr;
}


template<class _Ty>
const size_t SinglyList<_Ty>::size() const
{      
    return theSize;
}


template<class _Ty>
void SinglyList<_Ty>::push_back(const _Ty& val) 
{
    nodeptr temp = new node(val);

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        tail = tail->next;
    }

    ++theSize;
}


template<class _Ty>
void SinglyList<_Ty>::push_front(const _Ty& val) 
{
    nodeptr temp = new node(val);
    if (head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }

    ++theSize;
    
}


template<class _Ty>
void SinglyList<_Ty>::pop_back() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_back()");


    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        nodeptr temp = head;
        while (temp->next != tail)
            temp = temp->next;
        
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    --theSize;
}


template<class _Ty>
void SinglyList<_Ty>::pop_front() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_back()");

    nodeptr temp = head;

    head = head->next;
    delete temp;

    --theSize;
}


template<class _Ty>
void SinglyList<_Ty>::clear() 
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
_Ty SinglyList<_Ty>::front() const
{
    if (empty())
        throw std::domain_error("List is empty : front()");

    return head->data;
}


template<class _Ty>
_Ty SinglyList<_Ty>::back() const
{
    if (empty())
        throw std::domain_error("List is empty : back()");
        
    return tail->data; 
}

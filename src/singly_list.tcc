/**
 *  File        :   singly_list.tcc
 *  Explain     :   C++ Singly list implementation like std::list<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* implementation of singly_list.hpp */

#include "singly_list.hpp"
#include <stdexcept>

template<class T>
SinglyList<T>::SinglyList() : head(nullptr), tail(nullptr)
{

}


template<class T>
SinglyList<T>::SinglyList(std::initializer_list<T> l) 
{
    // for (auto iter = l.begin(); iter != l.end(); ++iter)
    // {   
    //     const T val = *iter; 
    //     push_back(val);
    // }
}


template<class T>
const bool SinglyList<T>::empty() const
{
    return head == nullptr;
}


template<class T>
const size_t SinglyList<T>::size() const
{      
    return theSize;
}


template<class T>
void SinglyList<T>::push_back(const T& val) 
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


template<class T>
void SinglyList<T>::push_front(const T& val) 
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


template<class T>
void SinglyList<T>::pop_back() 
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


template<class T>
void SinglyList<T>::pop_front() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_back()");

    nodeptr temp = head;

    head = head->next;
    delete temp;

    --theSize;
}


template<class T>
void SinglyList<T>::clear() 
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


template<class T>
T SinglyList<T>::front() const
{
    if (empty())
        throw std::domain_error("List is empty : front()");

    return head->data;
}


template<class T>
T SinglyList<T>::back() const
{
    if (empty())
        throw std::domain_error("List is empty : back()");
        
    return tail->data; 
}

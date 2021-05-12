/**
 *  File        :   doubly_list.tcc
 *  Explain     :   C++ doubly_list implementation like std::list<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/
#include <list>

/* implementation of doubly_list.hpp */
#include "doubly_list.hpp"
#include <stdexcept>



template<class T>
DoublyList<T>::DoublyList() : head(nullptr), tail(nullptr)
{

}


template<class T>
DoublyList<T>::DoublyList(std::initializer_list<T> l) 
{
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {   
        const T val = *iter; 
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
            tail = tail->next;
            tail->next = nullptr;
        }

            ++theSize;
        }
}


template<class T>
const bool DoublyList<T>::empty() const
{
    return head == nullptr;
}


template<class T>
const size_t DoublyList<T>::size() const
{
    return theSize;
}


template<class T>
void DoublyList<T>::push_back(const T& val) 
{
    nodeptr temp = new node(val);


    if (head == nullptr)
    {
        head = temp;
        tail = head;
    }
    
    else
    {
        tail->next   = temp;
        temp->prev   = tail; 
        tail = tail->next;
    }

    ++theSize;
}


template<class T>
void DoublyList<T>::push_front(const T& val)  
{
    nodeptr temp = new node(val);
    
    if (head == nullptr)
    {
        head = temp;
        tail = head;
    }
    
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    ++theSize;
}


template<class T>
void DoublyList<T>::pop_back() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_back()");

    nodeptr temp = tail;
    tail = tail->prev;
    delete temp;

    --theSize;
}


template<class T>
void DoublyList<T>::pop_front() 
{
    if (empty())
        throw std::domain_error("List is empty : pop_front()");

    nodeptr temp = head;
    head = head->next;
    delete temp;
    head->prev = nullptr;
    
    --theSize;
}


template<class T>
void DoublyList<T>::clear() 
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
T DoublyList<T>::front() const
{
    if (empty())
        throw std::domain_error("List is empty : front()");

    return head->data;
}


template<class T>
T DoublyList<T>::back() const
{
    if (empty())
        throw std::domain_error("List is empty : back()");

    return tail->data;
}


template<class T>
typename DoublyList<T>::Iterator DoublyList<T>::begin() 
{
    return head;
}


template<class T>
typename DoublyList<T>::Iterator DoublyList<T>::end() 
{
    return tail->next;
}
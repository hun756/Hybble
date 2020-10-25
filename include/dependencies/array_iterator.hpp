/**
 *  File        :   array_iterator.hpp
 *  Explain     :   Iterator class for Array.
 *                  This class contains 3 iterator class.
 *                      -   iterator
 *                      -   const_iterator
 *                      -   reverse_iterator 
 *                      -   const_reverse_iterator
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020      :   last : 24.10.2020 (edited)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* include guard for : ARRAY_ITERATOR_HPP */
#ifndef ARRAY_ITERATOR_HPP
#define ARRAY_ITERATOR_HPP

#include "list_node.hpp"
#include <array>


template <class _Ty, size_t MaxSize>
class ConstIterator
{
public:
    ConstIterator() : current(nullptr) {}

    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    ConstIterator(_Ty*);


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    const bool operator !=(ConstIterator&) const;


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    const ConstIterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    const ConstIterator& operator ++(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    const _Ty& operator *() const;

private:
    _Ty* current;
};
template <class _Ty, size_t MaxSize>
class Iterator : public ConstIterator<_Ty, MaxSize>
{
public:
    // using       Base                =   ConstIterator<_Ty, MaxSize>;
 // using       iterator_class      =   Iterator<_Ty, MaxSize>;

public:
    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    Iterator(_Ty*);


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator !=(const Iterator&);


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator ++(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty& operator *();

private:
    _Ty* current;
};  

// implementation from Iterator

template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>::Iterator(_Ty* initLock) 
{
    current = initLock;
}


template<class _Ty, size_t MaxSize>
bool Iterator<_Ty, MaxSize>::operator !=(const Iterator& rhs) 
{
    // TODO : basedeki constructor cagrilsin..!
    return current != rhs.current;
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator ++() 
{
    current++;
    return *this;
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator ++(int) 
{
    Iterator iter = *this;
    ++(*this);
    return iter;
}


template<class _Ty, size_t MaxSize>
_Ty& Iterator<_Ty, MaxSize>::operator *() 
{
    return *current;
}
// implementation end : Iterator


template <class _Ty, size_t MaxSize>
class ConstReverseIterator 
{
};  
template <class _Ty, size_t MaxSize>
class ReverseIterator : public ConstIterator<_Ty, MaxSize>
{
};  

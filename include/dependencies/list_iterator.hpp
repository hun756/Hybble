/**
 *  File        :   array_iterator.hpp
 *  Explain     :   Iterator class for List.
 *                  This class contains 3 iterator class.
 *                      -   const_iterator
 *                      -   iterator
 *                      -   const_reverse_iterator
 *                      -   reverse_iterator 
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   24.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP


#include "list_node.hpp"

template <class _Ty>
class ConstIterator
{

};


template <class _Ty>
class Iterator : public ConstIterator<_Ty>
{

};

template <class _Ty>
class ConstReverseIterator
{

};


template <class _Ty>
class ReverseIterator : public ConstReverseIterator<_Ty>
{

};

#endif /* end of include guard : LIST_ITERATOR_HPP */
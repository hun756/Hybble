/**
 *  File        :   doubly_list.hpp
 *  Explain     :   Node class for linked list.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   24.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP


template<class _Ty>
class SinglyNode
{
public:

    // members
    _Ty                 data;
    SinglyNode<_Ty>*    next;

    /**
     *  Constructor
     *
     *  @param 		 data  :  _Ty               ->  value of template parameter.
     *  @param 		 prev  :  SinglyNode*       ->  pointer from Singly Node class.
    **/
    SinglyNode(_Ty data = _Ty(), SinglyNode<_Ty>* next = nullptr);
};


template<class _Ty>
SinglyNode<_Ty>::SinglyNode(_Ty data, SinglyNode<_Ty>* next) : data(data), next(next)
{
    
}



template <class _Ty>
class DoublyNode
{
public:

    // members
    _Ty                 data;
    DoublyNode<_Ty>*    next;
    DoublyNode<_Ty>*    prev;

    /**
     *  Constructor
     *
     *  @param 		 data  :  _Ty               ->  value of template parameter.
     *  @param 		 next  :  DoublyNode*       ->  pointer from Doubly Node class.
     *  @param 		 prev  :  DoublyNode*       ->  pointer from Doubly Node class.
    **/
    DoublyNode(_Ty data = _Ty(), DoublyNode<_Ty>* next = nullptr, DoublyNode<_Ty>* prev = nullptr);
};


template<class _Ty>
DoublyNode<_Ty>::DoublyNode(_Ty data, DoublyNode<_Ty>* next, DoublyNode<_Ty>* prev) : data(data), next(next), prev(prev) 
{

}


#endif /* end of include guard : LIST_NODE_HPP */
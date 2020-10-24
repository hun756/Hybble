/**
 *  File        :   x_red_black_tree.hpp
 *  Explain     :   Node class for red black tree.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   24.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/


#ifndef X_RED_BLACK_TREE_HPP
#define X_RED_BLACK_TREE_HPP

enum class Color
{
    Red,
    Black
};


template <class _Ty>
class RedBlackTreeNode
{
public:
    
    // members
    _Ty                         data;
    RedBlackTreeNode<_Ty>*      parent;
    RedBlackTreeNode<_Ty>*      left;
    RedBlackTreeNode<_Ty>*      right;
    Color                       color;

    
    /**
     *  constructor
     *
     *  @param 		 data       : _Ty       ->  value of template parameter.
     *  @param 		 parent     : RBNode*   ->  pointer from RBNode Class
     *  @param 		 left       : RBNode*   ->              ""
     *  @param 		 right      : RBNode*   ->              ""
     *  @param 		 color      : Color     ->  Object of enumeration class 
    **/
    RedBlackTreeNode(_Ty data = _Ty(), 
                     RedBlackTreeNode<_Ty>* parent = nullptr,
                     RedBlackTreeNode<_Ty>* left = nullptr, 
                     RedBlackTreeNode<_Ty>* right = nullptr,
                     Color  color = Color::Red
    );
};

template <class _Ty>
RedBlackTreeNode<_Ty>::RedBlackTreeNode(_Ty data, 
                                        RedBlackTreeNode<_Ty>* parent,
                                        RedBlackTreeNode<_Ty>* left, 
                                        RedBlackTreeNode<_Ty>* right,
                                        Color  color
                        ) : data(data), parent(parent), left(left), right(right), color(color)
{

}


#endif /* emd  X_RED_BLACK_TREE_HPP */
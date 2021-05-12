/**
 *  File        :   x_red_black_tree.hpp
 *  Explain     :   Node class for red black tree.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   05.02.2020  (updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/


#ifndef RED_BLACK_TREE_NODE_HPP
#define RED_BLACK_TREE_NODE_HPP


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
     *  Construct a new Red Black Tree Node object
     *
     *  @param 		 data       : _Ty       ->  value of template parameter.
     *  @param 		 parent     : RBNode*   ->  pointer from RBNode Class
     *  @param 		 left       : RBNode*   ->              ""
     *  @param 		 right      : RBNode*   ->              ""
     *  @param 		 color      : Color     ->  Object of enumeration color class 
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


#endif /* end of include guard :  RED_BLACK_TREE_NODE_HPP */
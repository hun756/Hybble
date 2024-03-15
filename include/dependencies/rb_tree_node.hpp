/**
 *  File        :   x_red_black_tree.hpp
 *  Explain     :   Node class for red black tree.
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@gmail.com
 *  Date        :   03.15.2024  (updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Hybble
 **/

#ifndef RED_BLACK_TREE_NODE_HPP_kik5rs
#define RED_BLACK_TREE_NODE_HPP_kik5rs

#include <memory>

enum class Color {
    Red,
    Black
};

template <typename T>
class RedBlackTreeNode
{
public:
    T data;
    std::unique_ptr<RedBlackTreeNode<T>> left;
    std::unique_ptr<RedBlackTreeNode<T>> right;
    RedBlackTreeNode<T>* parent;
    Color color;

    explicit RedBlackTreeNode(T data = T(), RedBlackTreeNode<T>* parent = nullptr, Color color = Color::Red)
        : data(std::move(data)), parent(parent), color(color)
    {
    }

    RedBlackTreeNode(const RedBlackTreeNode&) = delete;
    RedBlackTreeNode& operator=(const RedBlackTreeNode&) = delete;

    RedBlackTreeNode(RedBlackTreeNode&&) noexcept = default;
    RedBlackTreeNode& operator=(RedBlackTreeNode&&) noexcept = default;

    ~RedBlackTreeNode() = default;
};

#endif /* end of include guard :  RED_BLACK_TREE_NODE_HPP_kik5rs */

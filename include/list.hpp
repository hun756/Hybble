/**
 *  File        :   list.hpp
 *  Explain     :   C++ List implementation like std::list
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* include guard of : LIST_HPP */
#ifndef LIST_HPP
#define LIST_HPP


#include "doubly_list.hpp"


// name aliasing to this format --> List<type>
template <class T>
using List = DoublyList<T>;


#endif /* end of include guard : LIST_HPP */

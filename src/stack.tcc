/**
 *  File        :   stack.tcc
 *  Explain     :   C++ Stack implementation like std::stack<>
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   23.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* implementation of stack.hpp */

template <class T, class Container>
Stack<T, Container>::Stack() : con()
{

}


template <class T, class Container>
Stack<T, Container>::Stack(std::initializer_list<T> l) : con(l)
{

}


template <class T, class Container>
const bool Stack<T, Container>::empty() const
{
    return con.empty();
}


template <class T, class Container>
const size_t Stack<T, Container>::size() const
{
    return con.size();
}


template <class T, class Container>
void Stack<T, Container>::push(const T& val)
{
    con.push_front(val);
}


template <class T, class Container>
void Stack<T, Container>::pop()
{
    con.pop_front();
}

template <class T, class Container>
T Stack<T, Container>::top()
{
    return con.front();
}
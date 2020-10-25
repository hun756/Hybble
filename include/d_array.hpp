/**
 *  File        :   d_array.hpp
 *  Explain     :   C++ dynamic array implementation like std::vector
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   22.10.2020
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of : DARRAY_HPP */
#ifndef DARRAY_HPP
#define DARRAY_HPP


#include <initializer_list>
#include <cstddef>


template <class _Ty>
class DArray
{
public:

    /**
     *  contructor 
    **/
    DArray();


    /**
     *  constructor
    **/
    ~DArray();


    /**
     *  Constructor with initializer list 
     *
     *  @param      l   ->      object from initializer_list class
    **/
    DArray(std::initializer_list<_Ty>);


    /**
     *  empty() method : if list has no element, return true.
     *
     *  @return 	 value of bool  ->  (index == 0)
    **/
    const bool empty() const;


    /**
     *  size() method : returns elemnt's count.
     *
     *  @return     index : size_t    ->    //
    **/
    const size_t size() const;


    /**
     *  capacity() method : is the maximum number of elements the array 
     *                      can take before dynamic enlargement or reduction.
     *
     *  @return 	 _capacity
    **/
    const size_t capacity() const;


    /**
     *  shrinkToFit method : brings capacity to the value of size.
    **/
    void shrinkToFit();

    
    /**
     *  at() method : takes the desired array element as a parameterç
     *
     *  @param 		 i   : size_t   ->  
     *  @return 	 _Ty&  reference from template 
    **/
    _Ty& at(size_t);

    const _Ty& at(size_t) const;


    /**
     *  overloading operator [] : takes the desired array element as a parameterç
     *
     *  @param 		 i   : size_t   ->  
     *  @return 	 _Ty&  reference from template 
    **/
    _Ty& operator [](size_t);

    const _Ty& operator [](size_t)  const;


    /**
     *  front() method :  returns first element in the array.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty front() const;


    /**
     *  back() method :  returns last element in the array.
     * 
     *  @return     _Ty   ->    reference value of the template parameter.
    **/
    _Ty back() const;


    /**
     *  push_back() method : Typeadds an element to the ending of the dynamic array.
     *
     *  @param 		 val : const template reference
    **/
    void push_back(const _Ty&);


    /**
     *  pop_back() method : Removes the last item from list.  
     * 
    **/
    void pop_back();

private:
    void reAlloc();


/* iterative methods */


private:
    _Ty*    data;
    size_t  index;
    size_t  _capacity;
};

#include "../src/d_array.cpp"

#endif /* end of include guard : DARRAY_HPP */
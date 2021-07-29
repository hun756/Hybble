/**
 *  File        :   d_array.hpp
 *  Explain     :   C++ dynamic array implementation like std::vector
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   5.12.2012 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of : D_ARRAY_HPP */
#ifndef D_ARRAY_HPP
#define D_ARRAY_HPP


#include <initializer_list>
#include <cstddef>
#include "dependencies/array_iterator.hpp"


namespace DSinCpp
{
    template <class T>
    class DArray
    {
    public:

        /**
         *  @brief
         *      Construct a new DArray object
        **/
        DArray();


        /**
         *  @brief
         *      Destroy the DArray object
        **/
        ~DArray();


        /**
         *  @brief
         *      Construct a new DArray object
         *
         *  @param  l
         *      Object from initializer_list class.
        **/
        DArray(std::initializer_list<T>);


        /**
         *  @brief
         *      Construct a new DArray object
         *
         *  @param[in] dArr
        **/
        DArray(const DArray<T>& dArr);


        /**
         *  @brief
         *      Construct a new DArray object
         *
         *  @param dArr
        **/
        DArray(DArray<T>&& dArr) noexcept;


        /**
         *  @brief
         *      Overlod operator ==.
         *
         *  @tparam U
         *  @param[in] lhs
         *  @param[in] rhs
         *  @return true
         *  @retval booelan
        **/
        template<class U>
        friend bool operator == (DArray<U>& lhs, DArray<U>& rhs);


        /**
         *  @brief
         *      This method checks if the array is empty.
         *
         *  @return
         *      value of bool
         *
         *  @retval
         *      true if index == 0
        **/
        [[nodiscard]] const bool empty() const;


        /**
         *  @brief
         *      This method returns the number of elements of the array.
         *
         *  @return
         *      size_t
         *
         *  @retval
         *      index
        **/
        [[nodiscard]] const size_t size() const;


        /**
         *  @brief
         *      This method is the maximum number of elements the array
         *      can take before dynamic enlargement or reduction.
         *
         *  @return
         *      <size_t> capacity value.
        **/
        [[nodiscard]] const size_t capacity() const;


        /**
         *  @brief
         *      This method : brings capacity to the value of size.
        **/
        void shrinkToFit();


        /**
         *  @brief
         *      This method takes the desired array element as a parameter.
         *
         *  @param[in]
         *      It is the index of the directory to be accessed.
         *
         *  @return
         *      T&  reference from template
        **/
        T& at(size_t);

        const T& at(size_t) const;


        /**
         *  @brief
         *      overloading operator [] takes the desired array element
         *      as a parameter.
         *
         *  @param[in]
         *      It is the index of the directory to be accessed.
         *
         *  @return
         *      T&  reference from template
        **/
        T& operator [](size_t);

        const T& operator [](size_t)  const;


        /**
         *  @brief
         *      This method :  returns first element in the array.
         *
         *  @return
         *      the first element of the array.
        **/
        T front() const;


        /**
         *  @brief
         *      This method :  returns first element in the array.
         *
         *  @return
         *      the last element of the array.
        **/
        T back() const;


        /**
         *  @brief
         *      This method adds an element to the ending of
         *      the dynamic array.
         *
         *  @param  val
         *      It is the value of the element to be added.
        **/
        void pushBack(const T&);


        /**
         *  @brief
         *      This method removes the last item from list.
        **/
        void popBack();


        /**
         *  @brief 
         * 
         *  @tparam Args 
         * 
         *  @param args 
         * 
         *  @return T& 
        **/
        template<class... Args>
        T& emplaceBack(Args&&... args);

    private:
        /**
         * @brief 
         * 
        **/
        void reAlloc();


    private:
        T*    data;
        size_t  index;
        size_t  _capacity;
    };
}


//> template implementation..
#include "d_array.tcc"

#endif /* end of include guard : DARRAY_HPP */
/**
 *  File        :   t_array.hpp
 *  Explain     :   C++ dynamic array implementation like std::vector
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   16.01.2022 (DD-MM-YYYY)  (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* Include guard of : T_ARRAY_HPP */
#ifndef T_ARRAY_HPP
#define T_ARRAY_HPP


#include <initializer_list>
#include <cstddef>
#include "dependencies/array_iterator.hpp"


namespace DSinCpp
{
    template <class T>
    class TArray
    {
    public:

        /**
         *  @brief
         *      Construct a new TArray object
        **/
        TArray();


        /**
         *  @brief
         *      Destroy the TArray object
        **/
        ~TArray();


        /**
         *  @brief
         *      Construct a new TArray object
         *
         *  @param  l
         *      Object from initializer_list class.
        **/
        TArray(std::initializer_list<T>);


        /**
         *  @brief
         *      Construct a new TArray object
         *
         *  @param[in] dArr
        **/
        TArray(const TArray<T>& dArr);


        /**
         *  @brief
         *      Construct a new TArray object
         *
         *  @param dArr
        **/
        TArray(TArray<T>&& dArr) noexcept;


        TArray& operator =(const TArray& dArr);

        TArray& operator =(TArray&& dArr) noexcept ;

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
        friend bool operator == (TArray<U>& lhs, TArray<U>& rhs);


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
        [[nodiscard]] bool empty() const;


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
        [[nodiscard]] size_t size() const;


        /**
         *  @brief
         *      This method is the maximum number of elements the array
         *      can take before dynamic enlargement or reduction.
         *
         *  @return
         *      <size_t> capacity value.
        **/
        [[nodiscard]] size_t capacity() const;


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
#include "t_array.tcc"

#endif /* end of include guard : T_ARRAY_HPP */
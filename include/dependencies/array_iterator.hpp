/**
 *  File        :   array_iterator.hpp
 *  Explain     :   Iterator class for Array.
 *                  This class contains 3 iterator class.
 *                      -   iterator
 *                      -   const_iterator
 *                      -   reverse_iterator 
 *                      -   const_reverse_iterator
 *  Author      :   Mehmet Ekemen
 *  Nickname    :   `hun
 *  Email       :   ekemenms@hotmail.com
 *  Date        :   7/22/2021       (Updated)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* include guard for : ARRAY_ITERATOR_HPP */
#ifndef ARRAY_ITERATOR_HPP
#define ARRAY_ITERATOR_HPP


template <class T, size_t MaxSize>
class ConstIterator
{
public:
    // ---------------- FOR std::reverse_iterator ----------------
    // using value_type        = T;
    // using difference_type   = ptrdiff_t;
    // using pointer           = T*;
    // using reference         = T&;
    // -----------------------------------------------------------
public:
    /**
     *  @brief 
     *      Construct a new Const Iterator object
     * 
     */
    ConstIterator();

    /**
     *  @brief 
     *      Construct a new Const Iterator object
     * 
     */
    ConstIterator(T*);


    /**
     *  @brief 
     *      Construct a new Const Iterator object
     *
     *  @return ConstIterator&	 
     *      Reference an object from class iterator.
    **/
    ConstIterator& operator ++();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     *
     *  @return 	 
     *      Ref Object from class iterator
    **/
    ConstIterator& operator ++(int);


    /**
     *  @brief 
     *      Overloading operator ++ (prefix)
     *
     *  @return 	 
     *      Object from class iterator
    **/
    ConstIterator& operator --();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     *
     *  @return 	 
     *      Object from class iterator
    **/
    ConstIterator& operator --(int);


    /**
     *  @brief 
     *      Overloading operator *
     *
     *  @return T& 
     *      Adress of template value. Return this value of adress.
    **/
    T& operator *() const;


    /**
     *  @brief 
     *      Overloading operator ->
     *
     *  @return T&    
     *      Adress of template value. Return this value of adress.
    **/
    T* operator ->() const;
    

    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator !=(const ConstIterator&) const;


    /**
     * @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval 	 
     *      !(current == rhs.current)
    **/
    bool operator ==(const ConstIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     *  
     *  @retval 	 
     *      !(current == rhs.current)
    **/
    bool operator <(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator >(const ConstIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator <=(const ConstIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator >=(const ConstIterator&) const;

private:
    const T* current;
};

//> implementation from ConstIterator
template <class T, size_t MaxSize>
ConstIterator<T, MaxSize>::ConstIterator() : current(nullptr)
{

}


template<class T, size_t MaxSize>
ConstIterator<T, MaxSize>::ConstIterator(T* initLock)
{
    current = initLock;
}


template<class T, size_t MaxSize>
ConstIterator<T, MaxSize>& ConstIterator<T, MaxSize>::operator ++() 
{
    ++current;
}


template<class T, size_t MaxSize>
ConstIterator<T, MaxSize>& ConstIterator<T, MaxSize>::operator ++(int) 
{
    ConstIterator iter = *this;
    ++(*this);
    return iter;
}


template<class T, size_t MaxSize>
T& ConstIterator<T, MaxSize>::operator *() const
{
    return *current;
}


template<class T, size_t MaxSize>
T* ConstIterator<T, MaxSize>::operator ->() const
{
    return current;
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator !=(const ConstIterator& rhs) const
{
    return current != rhs.current;
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator ==(const ConstIterator& rhs) const
{
    return current == rhs.current;
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator <(const ConstIterator& rhs) const
{
    return current < rhs.current;
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator >(const ConstIterator& rhs) const
{
    return current > rhs.current;
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator <=(const ConstIterator& rhs) const
{
    return !(current > rhs.current);
}


template<class T, size_t MaxSize>
bool ConstIterator<T, MaxSize>::operator >=(const ConstIterator& rhs) const
{
    return !(current < rhs.current);
}

// implementation end : ConstIterator
    

template <class T, size_t MaxSize>
class Iterator : public ConstIterator<T, MaxSize>
{
public:
    using       Base        =       ConstIterator<T, MaxSize>;

public:

    /**
     *  @brief 
     *      Construct a new Iterator object
     * 
     */
    Iterator();


    /**
     * @brief 
     *      Construct a new Iterator object
     * 
     * @param[in] initLock 
     */
    Iterator(T* initLock);


    /**
     *  @brief 
     *      Overloading operator ++ (prefix)
     * 
     *  @return Iterator& 
     */
    Iterator& operator ++();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return Iterator& 
     */
    Iterator& operator ++(int);


    /**
     *  @brief 
     *      Overloading operator ++ (prefix)
     * 
     *  @return Iterator& 
     */
    Iterator& operator --();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return Iterator& 
     */
    Iterator& operator --(int);


    /**
     *  @brief 
     *      Overloading operator *
     *
     *  @return T&  
     *      Adress of template value. Return this value of adress.
    **/
    T& operator *();


    /**
     *  @brief 
     *      Overloading operator ->
     *
     *  @return T& 
     *      Adress of template value. Return this value of adress.
    **/
    T* operator ->();

};  

// implementation from Iterator

template<class T, size_t MaxSize>
Iterator<T, MaxSize>::Iterator(T* initLock)  : Base(initLock)
{
    
}


template<class T, size_t MaxSize>
Iterator<T, MaxSize>& Iterator<T, MaxSize>::operator ++() 
{
    Base::operator++();
    return *this;
}


template<class T, size_t MaxSize>
Iterator<T, MaxSize>& Iterator<T, MaxSize>::operator ++(int) 
{
    Iterator iter = *this;
    Base::operator++();
    return iter;
}


template<class T, size_t MaxSize>
Iterator<T, MaxSize>& Iterator<T, MaxSize>::operator --() 
{
    Base::operator--();
    return *this;
}


template<class T, size_t MaxSize>
Iterator<T, MaxSize>& Iterator<T, MaxSize>::operator --(int) 
{
    Iterator iter = *this;
    Base::operator--();
    return iter;
}


template<class T, size_t MaxSize>
T& Iterator<T, MaxSize>::operator *() 
{
    return const_cast<T&>(Base::operator*());
}


template<class T, size_t MaxSize>
T* Iterator<T, MaxSize>::operator ->() 
{
    return const_cast<T*>(Base::operator->());
}

// implementation end : Iterator

template <class T, size_t MaxSize>
class ConstReverseIterator
{
public:
    // ---------------- FOR std::reverse_iterator ----------------
    // using value_type        = T;
    // using difference_type   = ptrdiff_t;
    // using pointer           = T*;
    // using reference         = T&;
    // -----------------------------------------------------------
public:
    ConstReverseIterator();

    /**
     *  @brief 
     *      Construct a new Const Reverse Iterator object.
     * 
     * @param[in] initLock
    **/
    ConstReverseIterator(T*);


    /**
     *  @brief
     *      Overloading operator ++ (prefix). 
     * 
     *  @return ConstReverseIterator& 
    **/
    ConstReverseIterator& operator ++();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return ConstReverseIterator& 
    **/
    ConstReverseIterator& operator ++(int);


    /**
     *  @brief 
     *      Overloading operator ++ (prefix)
     * 
     *  @return ConstReverseIterator& 
    **/
    ConstReverseIterator& operator --();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return ConstReverseIterator& 
    **/
    ConstReverseIterator& operator --(int);


    /**
     *  @brief 
     *      Overloading operator *
     *
     *  @return T&
     *      Adress of template value. Return this value of adress.
    **/
    const T& operator *() const;


    /**
     *  @brief 
     *      overloading operator ->
     *
     *  @return T&
     *      Adress of template value. Return this value of adress.
    **/
    T* operator ->() const;
    

    /**
     *  @brief 
     * 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator !=(const ConstReverseIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator ==(const ConstReverseIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator <(const ConstReverseIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator >(const ConstReverseIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @retval
     *      !(current == rhs.current)
    **/
    bool operator <=(const ConstReverseIterator&) const;


    /**
     *  @brief 
     *      Overloading operator !=
     *
     *  @param[in] rhs
     * 
     *  @return
     *      !(current == rhs.current)
    **/
    bool operator >=(const ConstReverseIterator&) const;

private:
    const T* current;
};

// implementation from ConstReverseIterator
template <class T, size_t MaxSize>
ConstReverseIterator<T, MaxSize>::ConstReverseIterator() : current(nullptr)
{

}


template<class T, size_t MaxSize>
ConstReverseIterator<T, MaxSize>::ConstReverseIterator(T* initLock)
{
    current = initLock;
}


template<class T, size_t MaxSize>
ConstReverseIterator<T, MaxSize>& ConstReverseIterator<T, MaxSize>::operator ++() 
{
    ++current;
    return *this;
}


template<class T, size_t MaxSize>
ConstReverseIterator<T, MaxSize>& ConstReverseIterator<T, MaxSize>::operator ++(int) 
{
    ConstReverseIterator iter = *this;
    ++(*this);
    return iter;
}


template<class T, size_t MaxSize>
const T& ConstReverseIterator<T, MaxSize>::operator *() const
{
    return *current;
}


template<class T, size_t MaxSize>
T* ConstReverseIterator<T, MaxSize>::operator ->() const
{
    return current;
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator !=(const ConstReverseIterator& rhs) const
{
    return current != rhs.current;
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator ==(const ConstReverseIterator& rhs) const
{
    return current == rhs.current;
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator <(const ConstReverseIterator& rhs) const
{
    return current < rhs.current;
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator >(const ConstReverseIterator& rhs) const
{
    return current > rhs.current;
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator <=(const ConstReverseIterator& rhs) const
{
    return !(current > rhs.current);
}


template<class T, size_t MaxSize>
bool ConstReverseIterator<T, MaxSize>::operator >=(const ConstReverseIterator& rhs) const
{
    return !(current < rhs.current);
}

// implementation end : ConstReverseIterator
    

template <class T, size_t MaxSize>
class ReverseIterator : public ConstReverseIterator<T, MaxSize>
{
public:
    using       Base        =       ConstReverseIterator<T, MaxSize>;

public:

    /**
     *  @brief 
     *      Construct a new Reverse Iterator object
     * 
    **/
    ReverseIterator();


    /**
     *  @brief 
     *      Construct a new Reverse Iterator object
     * 
     *  @param[in]  T*
    **/
    ReverseIterator(T*);

    /**
     *  @brief 
     *      Overloading operator ++ (prefix)
     * 
     *  @return ReverseIterator& 
    **/
    ReverseIterator& operator ++();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return ReverseIterator& 
    **/
    ReverseIterator& operator ++(int);

    /**
     *  @brief
     *      Overloading operator ++ (prefix)
     * 
     *  @return ReverseIterator& 
    **/
    ReverseIterator& operator --();


    /**
     *  @brief 
     *      Overloading operator ++ (postfix)
     * 
     *  @return ReverseIterator& 
    **/
    ReverseIterator& operator --(int);


    /**
     *  @brief 
     *      Overloading operator *
     *
     *  @return T&
     *      Adress of template value. Return this value of adress.
    **/
    T& operator *();


    /**
     * @brief 
     *      Overloading operator *
     *
     *  @return T&
     *      Adress of template value. Return this value of adress.
    **/
    T* operator ->();

};  

// implementation from ReverseIterator

template<class T, size_t MaxSize>
ReverseIterator<T, MaxSize>::ReverseIterator(T* initLock)  : Base(initLock)
{
    
}


template<class T, size_t MaxSize>
ReverseIterator<T, MaxSize>& ReverseIterator<T, MaxSize>::operator ++() 
{
    Base::operator++();
    return *this;
}


template<class T, size_t MaxSize>
ReverseIterator<T, MaxSize>& ReverseIterator<T, MaxSize>::operator ++(int) 
{
    ReverseIterator iter = *this;
    Base::operator++();
    return iter;
}


template<class T, size_t MaxSize>
ReverseIterator<T, MaxSize>& ReverseIterator<T, MaxSize>::operator --() 
{
    Base::operator--();
    return *this;
}


template<class T, size_t MaxSize>
ReverseIterator<T, MaxSize>& ReverseIterator<T, MaxSize>::operator --(int) 
{
    ReverseIterator iter = *this;
    Base::operator--();
    return iter;
}


template<class T, size_t MaxSize>
T& ReverseIterator<T, MaxSize>::operator *() 
{
    return const_cast<T&>(Base::operator*());
}


template<class T, size_t MaxSize>
T* ReverseIterator<T, MaxSize>::operator ->() 
{
    return const_cast<T*>(Base::operator->());
}

// implementation end : ReverseIterator



#endif /* end of include guard : ARRAY_ReverseIterator_HPP */
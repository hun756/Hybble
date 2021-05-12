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
 *  Date        :   22.10.2020      :   last : 24.10.2020 (edited)
 *  Github      :   github.com/hun756
 *  Resource    :   https://github.com/hun756/Data-Sutructures-in-CPlusPlus/
**/

/* include guard for : ARRAY_ITERATOR_HPP */
#ifndef ARRAY_ITERATOR_HPP
#define ARRAY_ITERATOR_HPP


template <class _Ty, size_t MaxSize>
class ConstIterator
{
public:
    // ---------------- FOR std::reverse_iterator ----------------
    // using value_type        = _Ty;
    // using difference_type   = ptrdiff_t;
    // using pointer           = _Ty*;
    // using reference         = _Ty&;
    // -----------------------------------------------------------
public:
    ConstIterator();

    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    ConstIterator(_Ty*);


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    ConstIterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    ConstIterator& operator ++(int);


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    ConstIterator& operator --();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    ConstIterator& operator --(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty& operator *() const;


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty* operator ->() const;
    

    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator !=(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator ==(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator <(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator >(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator <=(const ConstIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator >=(const ConstIterator&) const;

private:
    const _Ty* current;
};

// implementation from ConstIterator
template <class _Ty, size_t MaxSize>
ConstIterator<_Ty, MaxSize>::ConstIterator() : current(nullptr)
{

}


template<class _Ty, size_t MaxSize>
ConstIterator<_Ty, MaxSize>::ConstIterator(_Ty* initLock)
{
    current = initLock;
}


template<class _Ty, size_t MaxSize>
ConstIterator<_Ty, MaxSize>& ConstIterator<_Ty, MaxSize>::operator ++() 
{
    ++current;
}


template<class _Ty, size_t MaxSize>
ConstIterator<_Ty, MaxSize>& ConstIterator<_Ty, MaxSize>::operator ++(int) 
{
    ConstIterator iter = *this;
    ++(*this);
    return iter;
}


template<class _Ty, size_t MaxSize>
_Ty& ConstIterator<_Ty, MaxSize>::operator *() const
{
    return *current;
}


template<class _Ty, size_t MaxSize>
_Ty* ConstIterator<_Ty, MaxSize>::operator ->() const
{
    return current;
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator !=(const ConstIterator& rhs) const
{
    return current != rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator ==(const ConstIterator& rhs) const
{
    return current == rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator <(const ConstIterator& rhs) const
{
    return current < rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator >(const ConstIterator& rhs) const
{
    return current > rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator <=(const ConstIterator& rhs) const
{
    return !(current > rhs.current);
}


template<class _Ty, size_t MaxSize>
bool ConstIterator<_Ty, MaxSize>::operator >=(const ConstIterator& rhs) const
{
    return !(current < rhs.current);
}

// implementation end : ConstIterator
    

template <class _Ty, size_t MaxSize>
class Iterator : public ConstIterator<_Ty, MaxSize>
{
public:
    using       Base        =       ConstIterator<_Ty, MaxSize>;

public:

    /**
     *  Type  your explain here...
    **/
    Iterator();


    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    Iterator(_Ty*);

    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator ++(int);

    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator --();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    Iterator& operator --(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty& operator *();


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty* operator ->();

};  

// implementation from Iterator

template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>::Iterator(_Ty* initLock)  : Base(initLock)
{
    
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator ++() 
{
    Base::operator++();
    return *this;
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator ++(int) 
{
    Iterator iter = *this;
    Base::operator++();
    return iter;
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator --() 
{
    Base::operator--();
    return *this;
}


template<class _Ty, size_t MaxSize>
Iterator<_Ty, MaxSize>& Iterator<_Ty, MaxSize>::operator --(int) 
{
    Iterator iter = *this;
    Base::operator--();
    return iter;
}


template<class _Ty, size_t MaxSize>
_Ty& Iterator<_Ty, MaxSize>::operator *() 
{
    return const_cast<_Ty&>(Base::operator*());
}


template<class _Ty, size_t MaxSize>
_Ty* Iterator<_Ty, MaxSize>::operator ->() 
{
    return const_cast<_Ty*>(Base::operator->());
}

// implementation end : Iterator

template <class _Ty, size_t MaxSize>
class ConstReverseIterator
{
public:
    // ---------------- FOR std::reverse_iterator ----------------
    // using value_type        = _Ty;
    // using difference_type   = ptrdiff_t;
    // using pointer           = _Ty*;
    // using reference         = _Ty&;
    // -----------------------------------------------------------
public:
    ConstReverseIterator();

    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    ConstReverseIterator(_Ty*);


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    ConstReverseIterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    ConstReverseIterator& operator ++(int);


    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class iterator
    **/
    ConstReverseIterator& operator --();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class iterator
    **/
    ConstReverseIterator& operator --(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    const _Ty& operator *() const;


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty* operator ->() const;
    

    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator !=(const ConstReverseIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator ==(const ConstReverseIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator <(const ConstReverseIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator >(const ConstReverseIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator <=(const ConstReverseIterator&) const;


    /**
     *  Overloading operator !=
     *
     *  @param 		 rhs        ->  const iterator&
     *  @return 	 !(current == rhs.current)
    **/
    bool operator >=(const ConstReverseIterator&) const;

private:
    const _Ty* current;
};

// implementation from ConstReverseIterator
template <class _Ty, size_t MaxSize>
ConstReverseIterator<_Ty, MaxSize>::ConstReverseIterator() : current(nullptr)
{

}


template<class _Ty, size_t MaxSize>
ConstReverseIterator<_Ty, MaxSize>::ConstReverseIterator(_Ty* initLock)
{
    current = initLock;
}


template<class _Ty, size_t MaxSize>
ConstReverseIterator<_Ty, MaxSize>& ConstReverseIterator<_Ty, MaxSize>::operator ++() 
{
    ++current;
    return *this;
}


template<class _Ty, size_t MaxSize>
ConstReverseIterator<_Ty, MaxSize>& ConstReverseIterator<_Ty, MaxSize>::operator ++(int) 
{
    ConstReverseIterator iter = *this;
    ++(*this);
    return iter;
}


template<class _Ty, size_t MaxSize>
const _Ty& ConstReverseIterator<_Ty, MaxSize>::operator *() const
{
    return *current;
}


template<class _Ty, size_t MaxSize>
_Ty* ConstReverseIterator<_Ty, MaxSize>::operator ->() const
{
    return current;
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator !=(const ConstReverseIterator& rhs) const
{
    return current != rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator ==(const ConstReverseIterator& rhs) const
{
    return current == rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator <(const ConstReverseIterator& rhs) const
{
    return current < rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator >(const ConstReverseIterator& rhs) const
{
    return current > rhs.current;
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator <=(const ConstReverseIterator& rhs) const
{
    return !(current > rhs.current);
}


template<class _Ty, size_t MaxSize>
bool ConstReverseIterator<_Ty, MaxSize>::operator >=(const ConstReverseIterator& rhs) const
{
    return !(current < rhs.current);
}

// implementation end : ConstReverseIterator
    

template <class _Ty, size_t MaxSize>
class ReverseIterator : public ConstReverseIterator<_Ty, MaxSize>
{
public:
    using       Base        =       ConstReverseIterator<_Ty, MaxSize>;

public:

    /**
     *  Type  your explain here...
    **/
    ReverseIterator();


    /**
     *  Constructor : 
     *
     *  @param 		 _Ty*   initLock    -> 
    **/
    ReverseIterator(_Ty*);

    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class ReverseIterator
    **/
    ReverseIterator& operator ++();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class ReverseIterator
    **/
    ReverseIterator& operator ++(int);

    /**
     *  Overloading operator ++ (prefix)
     *
     *  @return 	 object from class ReverseIterator
    **/
    ReverseIterator& operator --();


    /**
     *  Overloading operator ++ (postfix)
     *
     *  @return 	 object from class ReverseIterator
    **/
    ReverseIterator& operator --(int);


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty& operator *();


    /**
     *  overloading operator *
     *
     *  @return 	 _Ty&    ->  adress of template value. Return this value of adress.
    **/
    _Ty* operator ->();

};  

// implementation from ReverseIterator

template<class _Ty, size_t MaxSize>
ReverseIterator<_Ty, MaxSize>::ReverseIterator(_Ty* initLock)  : Base(initLock)
{
    
}


template<class _Ty, size_t MaxSize>
ReverseIterator<_Ty, MaxSize>& ReverseIterator<_Ty, MaxSize>::operator ++() 
{
    Base::operator++();
    return *this;
}


template<class _Ty, size_t MaxSize>
ReverseIterator<_Ty, MaxSize>& ReverseIterator<_Ty, MaxSize>::operator ++(int) 
{
    ReverseIterator iter = *this;
    Base::operator++();
    return iter;
}


template<class _Ty, size_t MaxSize>
ReverseIterator<_Ty, MaxSize>& ReverseIterator<_Ty, MaxSize>::operator --() 
{
    Base::operator--();
    return *this;
}


template<class _Ty, size_t MaxSize>
ReverseIterator<_Ty, MaxSize>& ReverseIterator<_Ty, MaxSize>::operator --(int) 
{
    ReverseIterator iter = *this;
    Base::operator--();
    return iter;
}


template<class _Ty, size_t MaxSize>
_Ty& ReverseIterator<_Ty, MaxSize>::operator *() 
{
    return const_cast<_Ty&>(Base::operator*());
}


template<class _Ty, size_t MaxSize>
_Ty* ReverseIterator<_Ty, MaxSize>::operator ->() 
{
    return const_cast<_Ty*>(Base::operator->());
}

// implementation end : ReverseIterator



#endif /* end of include guard : ARRAY_ReverseIterator_HPP */
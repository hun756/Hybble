#ifndef PAIR_HPP
#define PAIR_HPP

template <class T1, class T2>
class Pair
{
public:
    Pair(T1 first, T2 second) : first(first), second(second) {}
private:
    T1 first;
    T2 second;
};


template<typename T1, typename T2>
Pair makePair(T1 first, T2 second)
{
    return Pair(first, second);
}


#endif /* end of include guard : PAIR_HPP */
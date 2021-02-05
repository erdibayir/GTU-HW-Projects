#ifndef GtuIterator_h
#define GtuIterator_h

namespace GTU{
template<class T>
class GTUIterator{
public:
    GTUIterator(T* data);
    GTUIterator& operator++();
    bool operator==(const GTUIterator&) const;
    bool operator!=(const GTUIterator&) const;
    T& operator*();
    GTUIterator& operator--();


private:
    T* Data;
};
}
#endif
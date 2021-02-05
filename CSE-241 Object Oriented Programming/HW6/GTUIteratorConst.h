#ifndef GtuIteratorConst_h
#define GtuIteratorConst_h

namespace GTU{
template<class T>
class GTUIteratorConst{
public:
    GTUIteratorConst(T* data);
    GTUIteratorConst& operator++();
    bool operator==(const GTUIteratorConst&) const;
    bool operator!=(const GTUIteratorConst&) const;
    T& operator*() const;
    GTUIteratorConst& operator--();


private:
    T* Data;
};
}
#endif
#ifndef GtuContainer_h
#define GtuContainer_h
namespace GTU{
template <class T>
class GTUContainer{
public:
    virtual int size()=0;
    virtual bool empty()=0;
    virtual void insert(T)=0; 
    virtual T* begin()=0;
    virtual T* end()=0;
    virtual T* erase(T)=0;
    virtual void clear()=0;
};
}
#endif
#ifndef GtuSet_h
#define GtuSet_h
#include"GTUContainer.h"

namespace GTU{
template <class T>
class GTUSet:public GTUContainer<T>{
public:
    GTUSet();
    virtual int size() override;
    virtual bool empty() override;
    virtual void insert(T data) override;
    void print();
    virtual T* begin() override;
    virtual T* end() override;
    virtual T* erase(T value) override;
    virtual void clear() override;
    
private:
        int size_of_Data;   // This variable represent the capacity of Data
        T* Data;            // Data of Set Class 
        int current;        //This variable represent the last index of Data
};
}

#endif
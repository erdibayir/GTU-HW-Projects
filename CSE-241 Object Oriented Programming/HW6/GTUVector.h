#ifndef GtuVector_h
#define GtuVector_h
#include "GTUContainer.h"

namespace GTU{
template<class T>
class GTUVector:public GTUContainer<T>{
public:
    GTUVector();
    virtual int size() override;
    virtual bool empty() override;
    virtual void insert(T data) override;
    void print();
    virtual T* begin() override;
    virtual T* end() override;
    virtual T* erase(T value) override;
    virtual void clear() override;
    
    T& operator[] (T index);
private:
        int size_of_Data;   // This variable represent the capacity of Data
        T* Data;            // Data of Vector Class 
        int current;        //This variable represent the last index of Data

    };
}


#endif
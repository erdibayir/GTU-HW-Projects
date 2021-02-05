#include <iostream>
#include "GTUIteratorConst.h"

namespace GTU{
template <class T>
GTUIteratorConst<T>::GTUIteratorConst(T* data){
    Data=data;
}
template <class T>
GTUIteratorConst<T>& GTUIteratorConst<T>::operator++(){
    ++Data;
    return *this;
}
template <class T>
GTUIteratorConst<T>& GTUIteratorConst<T>::operator--(){
    --Data;
    return *this;
}
template<class T>
bool GTUIteratorConst<T>::operator==(const GTUIteratorConst& It)const {
    if(Data==It.Data)
        return true;
    else
        return false;
}
template <class T>
bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst& It)const{
     if(Data!=It.Data)
        return true;
    else
        return false;
}
template<class T>
T& GTUIteratorConst<T>::operator*() const{
    return *Data;
}


}
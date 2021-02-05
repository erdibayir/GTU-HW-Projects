#include <iostream>
#include "GTUIterator.h"

namespace GTU{
template <class T>
GTUIterator<T>::GTUIterator(T* data){
    Data=data;
}
template <class T>
GTUIterator<T>& GTUIterator<T>::operator++(){
    ++Data;
    return *this;
}
template <class T>
GTUIterator<T>& GTUIterator<T>::operator--(){
    --Data;
    return *this;
}
template<class T>
bool GTUIterator<T>::operator==(const GTUIterator& It)const {
    if(Data==It.Data)
        return true;
    else
        return false;
}
template <class T>
bool GTUIterator<T>::operator!=(const GTUIterator& It)const{
     if(Data!=It.Data)
        return true;
    else
        return false;
}
template<class T>
T& GTUIterator<T>::operator*(){
    return *Data;
}


}
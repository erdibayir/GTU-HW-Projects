#include <iostream>
#include "GTUSet.h"
#include <math.h>
using std::cout;
using std::endl;
namespace GTU{
template <class T>
GTUSet<T>::GTUSet(){
        Data =new T[1];
        size_of_Data=1;
        current=0;

    };
template <class T>
T* GTUSet<T>::begin(){
        return &Data[0];
    };
template <class T>
T* GTUSet<T>::end(){
    return &Data[current-1];
}
template <class T>
int GTUSet<T>::size(){
    return current;   
}
template <class T>
bool GTUSet<T>::empty(){
    if(current==0)
        return true;
    else
        return false;
}
template <class T>
void GTUSet<T>::insert(T data){

    if(current==size_of_Data){
        T* new_arr=new T[2*size_of_Data];
        for (int i = 0; i < size_of_Data; i++) { 
                new_arr[i] = Data[i];
    }
    delete [] Data;
    Data = new_arr;
    size_of_Data  = size_of_Data*2;
    }
       int check_value=0;
    for(int i=0 ; i < size_of_Data; i++){
        if(Data[i]==data)
            check_value++;
    }
    if(check_value==0){
        Data[current] =data;
        current++;   
    }
    
}
template<class T>
T* GTUSet<T>::erase(T value){
    int index_of_erase;
    for(int i=0 ; i<current;i++){
        if(Data[i]==value)
            index_of_erase=i;
    }

    T* new_Data=new T[size_of_Data];
    int j=0;
    for (int i = 0; i < size_of_Data; i++){
            if(index_of_erase!=i){
                new_Data[j] = Data[i];
                j++;
            }

        }
     delete [] Data;
     Data = new_Data;
     current=current-1;
}
template <class T>
void GTUSet<T>::clear(){
    delete [] Data;
    size_of_Data=1;
    current=0;
}
template<class T>
void GTUSet<T>::print(){
    cout << "Set:" ;
    for (int i=0 ; i< current; i++)
        cout <<Data[i] << " ";
        cout << endl;
    }

}
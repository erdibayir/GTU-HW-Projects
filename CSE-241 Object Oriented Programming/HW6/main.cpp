#include <iostream>
using namespace std;
#include "GTUSet.cpp"
#include "GTUVector.cpp"
#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"
using namespace GTU;
template <class T>
GTUIterator<T> find(GTUIterator<T> first , GTUIterator<T> last , const T&value){
    while (first!=last) {
    if (*first==value) 
        return first;
    ++first;
    }
  return last;
}

int main(){ 
    GTUSet<int> s1;
    cout << "SET" << endl;
    cout <<  "Empty:"<<s1.empty() << endl;
    cout << "Size:"<<s1.size() << endl;
    cout << "Inserting Set" << endl;
    s1.insert(8);
    s1.insert(3);
    s1.insert(4);
    s1.insert(4);
    s1.insert(5);
    s1.print();
    cout << "Erasing" << endl;
    s1.erase(4);
    s1.print();
    cout << "Cleaning"<< endl;
    s1.clear();
    s1.print();
    cout << "Inserting Set" << endl;
    s1.insert(1);
    s1.insert(5);
    s1.insert(7);
    s1.print();
    cout << "Begin:"<<*s1.begin()<< endl;
    cout << "End:"<<*s1.end()<< endl;
    cout << "Empty:" << s1.empty() << endl;
    cout << "Size:"<< s1.size() << endl;
    GTUVector<int> GTU_Vector;
    cout << "Inserting Vector" << endl;
    GTU_Vector.insert(4);
    GTU_Vector.insert(3); 
    GTU_Vector.print();
    cout << "Cleaning" << endl;
    GTU_Vector.clear();
    GTU_Vector.insert(6);
    GTU_Vector.insert(2);
    GTU_Vector.insert(7);
    GTU_Vector.insert(5);
    GTU_Vector.insert(3);
    
    cout << "Begin:"<<*GTU_Vector.begin()<< endl;
    cout << "End:"<<*GTU_Vector.end()<< endl;
    cout << "Empty:" << GTU_Vector.empty() << endl;
    cout << "Size:"<< GTU_Vector.size() << endl;
    GTUIterator<int> it1(GTU_Vector.begin());
    GTUIterator<int> it2(GTU_Vector.end());
    GTUIterator<int> it3= find(it1,it2,3);
    cout <<"Find:"<< *it3 << endl;
  
    return 0;
}
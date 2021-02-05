#include <iostream>
#include <fstream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
#include "BoardArray2d.h"
#include "BoardVector.h"
#include "BoardArray1d.h"

bool Ordering_Class(Puzzle::AbstractBoard * ptr , int size){
    int checking =0;

    for(int i=0 ; i < size ; i++){

        if( ptr[i].isSolved()== false){
            return false;
        }
        else
            return true;
    }

    return checking;
};

int main(int argc, char *argv[] ) {
    srand(time(NULL));
    space_cord cord;
    Puzzle::BoardArray2d b1;

//     BoardArray2d Class Test

    cout << "--------BoardArray2d-----------" << endl;
    if(argc==1){ // If  user don't enter test file in command line
 
    cord=b1.setsize(3); // For Hw1 // 3 is size of puzzle taking from user
    cout << b1; // Print Puzzle with operator << overloading

    cout << "Move testing for BoardArray2d" << endl;
    cord = b1.move ('l' , cord); // Move testing
    cout << b1; 
    }
    if(argc==2){ // If user enter test file
	b1.readfromfile(argv[1]);
    cout << b1;
    }
    // b1.writeToFile(); // Take input file name  from user and write board to file
    // cout << b1(2,2) << endl; // operator() overloading test 

    //  BoardVector Class Test
     cout << "--------BoardVector-----------" << endl;
   
  Puzzle::BoardVector v1;
  if(argc==1){ // If user dont enter text file on command line
    space_cord cord2;
    cord2=v1.setsize(3);
    cout << v1; // Print Puzzle with operator << overloading
    cout << "Move testing for BoardVector" << endl;
    cord2 = v1.move ('l' , cord2); // Move testing
    cout << v1;
    }
  if(argc==2){  // If user enter text file for read puzzle
 v1.readfromfile(argv[1]);
 cout << v1;
  }
 // cout << v1(1,1) << endl;  operator() overloading test
// v1.writeToFile(); Take input file name  from user and write board to file

//BoardArray1d Class Test

cout << "--------BoardArray1d-----------" << endl;
   Puzzle::BoardArray1d b3;
    space_cord cord3;
    
   if(argc==1){ // If user dont enter text file on command line
    cord3=b3.setsize(3);
   cout << b3;
   cout << "Move testing for BoardArray1d" << endl;
    cord3 = b3.move ('l' , cord3); // Move testing
    cout << b3;
    
   }
   if(argc==2){ // If user enter text file for read puzzle
    b3.readfromfile(argv[1]);
    cout << b3;
   }
    // b3.writeToFile(); Take input file name  from user and write board to file
    // cout << b3(2,0) << endl; operator ( ) overloading test
   
    return 0;
}
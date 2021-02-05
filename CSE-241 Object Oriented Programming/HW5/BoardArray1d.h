#ifndef BoardArray1d_h
#define BoardArray1d_h
#include "AbstractBoard.h"

namespace Puzzle{

class BoardArray1d:public AbstractBoard{
    public:

    
    virtual space_cord setsize(int size) override; // pure virtual function of AbstractBoard override
    int check_random_number(int random_number);
    virtual void print() override; // pure virtual function of AbstractBoard override
    virtual void readfromfile(std::string load_name) override; // this load_name is  parameter argv[1] of main function
    virtual void writeToFile() override; // pure virtual function of AbstractBoard override
    virtual space_cord reset(space_cord cord) override; // pure virtual function of AbstractBoard override
    virtual space_cord move(char  move , space_cord cord) override; // pure virtual function of AbstractBoard override
    int assign_puzzle_type();
     virtual bool isSolved() override; // pure virtual function of AbstractBoard  override
    virtual int number_of_moves() override;
    virtual int operator() (int i , int j) override; // pure virtual function of AbstractBoard  override
    friend std::ostream&  operator << (std::ostream& os,  BoardArray1d& board){
		board.print();
		return os;
	}
     bool operator==(BoardArray1d& A1){
            int check=0;

           for(int  i=0 ; i< row ; i++){
               for(int j=0; j <column; j++){
                   if(arr[i*row+j]!=A1.arr[i*row+j])
                        check++;
               }
           }
            if(check==0)
                return true;
            else
                return false;
        }

    private:
    int *arr;
    int row;
    int column;
    int number_of_move;




};




}

#endif
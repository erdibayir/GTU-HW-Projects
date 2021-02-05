#ifndef BoardVector_h
#define BoardVector_h
#include <cmath>
#include <vector>
#include "AbstractBoard.h"

namespace Puzzle{
    class BoardVector:public AbstractBoard{
    public:
    virtual space_cord setsize(int size) override; // pure virtual function of AbstractBoard override
    int check_random_number(int** temp_arr,int random_number, int row,int column);
    virtual void print() override; // pure virtual function of AbstractBoard override
    virtual void readfromfile(std::string load_name) override; // this load_name is  parameter argv[1] of main function
    virtual void writeToFile() override; // pure virtual function of AbstractBoard override
    virtual space_cord reset(space_cord cord) override; // pure virtual function of AbstractBoard override
    int assign_puzzle_type();
    virtual space_cord move(char  move , space_cord cord) override; // pure virtual function of AbstractBoard override
     virtual bool isSolved() override; // pure virtual function of AbstractBoard  override
     virtual int number_of_moves() override; // pure virtual function of AbstractBoard  override
     virtual int operator() (int i , int j) override; // pure virtual function of AbstractBoard  override
       friend std::ostream&  operator << (std::ostream& os,  BoardVector& board){
		board.print();
		return os;
	}
     bool operator==(BoardVector& A1){
            int check=0;
            std::vector <std::vector<int> > temp=A1.arr;
            
           for(int  i=0 ; i< arr.size() ; i++){
               for(int j=0; j <arr[i].size(); j++){
                   if(arr[i][j]!=temp[i][j])
                        check++;
               }
           }
            if(check==0)
                return true;
            else
                return false;
        }
    private:
        std::vector <std::vector<int> > arr;
		char last_move;
		int number_of_move;



    };


}



#endif
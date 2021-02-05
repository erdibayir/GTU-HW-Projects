#include <iostream>
#include <fstream>
#include "BoardArray1d.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace Puzzle{

space_cord BoardArray1d::setsize(int size){

     row=size;
    column=size; 

    arr = new int [row*column]; 
   

     space_cord cord; // define space room X and Y coordinates
		cord.spaceX=rand() % row;
		cord.spaceY=rand() % column;
		arr[cord.spaceX*row+cord.spaceY]=-5;
 
        for (int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < column ; j++){
					if(arr[i*row+j]!=-5){

						int random_number=1+rand() % ((row*column)-1);
						int check;

						check=check_random_number(random_number);//this control function check that the random number is not already used

						while(check==0){
							random_number=1+rand() % ((row*column)-1);
							check=check_random_number(random_number);
					}
							arr[i*row+j]=random_number;
		    	    }
		        }
    	    }

    return cord;

}

int BoardArray1d::check_random_number(int random_number){
     int i,j;
	int check=1;
	for(i = 0 ; i < row  ; i++){
		for(j = 0 ; j < column ; j++){
			if(arr[i*row+j]==random_number){
				check=0;
				break;
			}
		}
	}
	return check;
}
void BoardArray1d::print(){
    int define_puzzle=0;  // this variable assign that this puzzle read to file puzzle or hw1 puzzle
	for(int i=0 ;i < row ; i++){
		for(int j=0 ; j < column ;j++){
			if(arr[i*row+j]==0)
				define_puzzle++;
		}
	}
	if(define_puzzle==0){
		for (int i = 0 ; i < row ; i++){

			for(int j = 0 ; j < column ; j++){
					if(arr[i*row+j] != -5)
					cout <<arr[i*row+j] << "\t" ;
					else
					cout << " \t";
					}
				cout << endl;
		}
	}
	else{
		for ( int i = 0 ; i < row ; i++){
			for( int j = 0 ; j < column ; j++){
				if(arr[i*row+j]==-5){
					cout << "bb" << " ";
				}
				else if(arr[i*row+j]==0)
					cout <<"00" << " ";
				else if(arr[i*row+j] < 10)
					cout << "0" << arr[i*row+j] << " ";
				else
					cout << arr[i*row+j] << " ";
			}

				cout << endl;
		}
	}
}

void BoardArray1d::readfromfile(std::string load_name){
    int i,j;	
	string data;
	string line;

	row=0;
	column=0;

 
	std::ifstream input_file;
	input_file.open(load_name);
	
	//Find Row of Puzzle in File
	while(!input_file.eof()){
		getline(input_file,line);
		row++;
		
	}
	
	// Find Column of Puzzle in File
	for(i=0 ; line[i] ; i++){
		if(line[i]==' ')
			column++;
	}
	column++;
	
	input_file.close();

	string STRING[row][column];

	input_file.open(load_name);

	//Read data of file to string  array
	while(!input_file.eof()){
		for(i=0 ;i < row ; i++){
			for(j=0 ; j < column ; j++){
				input_file >> data;
				STRING[i][j]=data;		
			}
		}		
	}
	input_file.close();

	//Create integer puzzle array

	
	arr = new int [row*column]; 

        // Convert string array to int array for using functions
		int temp;

		for(int i=0 ; i < row ;i ++){
			for(int j=0 ; j < column ; j++){
				if(STRING[i][j]=="bb")
			 		arr[i*row+j]=-5;

			 	else{
					temp=atoi(STRING[i][j].c_str());
					arr[i*row+j]=temp;	 		
			 	}		
			}
		}
}

void BoardArray1d::writeToFile(){
	std::ofstream save_file;
	int i,j;
	string save_name;
	cout << "Enter a name for save file(Example:a.txt):" << endl;
	cin >> save_name;
	cout << "Saving..." << endl;
	save_file.open(save_name);

	for( i=0 ; i< row ; i++){
		for(j=0 ; j<column ; j++){
			if(j != column-1){
			if(arr[i*row+j]==-5){
					save_file << "bb" << " ";
				}
				else if(arr[i*row+j]==0)
					save_file <<"00" << " ";
				else if(arr[i*row+j]< 10)
					save_file << "0" << arr[i*row+j] << " ";
				else
					save_file << arr[i*row+j] << " ";
			}
			else{
				if(arr[i*row+j]==-5){
					save_file << "bb";
				}
				else if(arr[i*row+j]==0)
					save_file <<"00";
				else if(arr[i*row+j] < 10)
					save_file << "0" << arr[i*row+j];
				else
					save_file << arr[i*row+j];
			}
		}
		if(i!=row-1)
			save_file << endl;
	}
	save_file.close();	
}

int BoardArray1d::assign_puzzle_type(){
		int type=0; // if type:0 we play hw1 puzzle
	for(int i=0 ; i < row ; i++){
		for(int j=0 ; j< column ; j++){
			if(arr[i*row+j]==0)
				type++;
		}
	}
	return type;
}

space_cord BoardArray1d::reset(space_cord cord){
	int type=assign_puzzle_type();
	if(type==0){
	int order_number=1;
	for(int i = 0 ; i < row; i++){
		for(int j = 0 ; j < column ; j++){
			arr[i*row+j]=order_number;
				order_number++;
					}
			}
			cord.spaceX=row-1;
			cord.spaceY=column-1;
			arr[cord.spaceX*row+cord.spaceY]=-5;
		}
		else {

			int biggest_one=arr[0];
	
	for( int i = 0 ; i < row; i++){
		for( int j = 1 ; j < column ; j++){
				if(arr[i*row+j] > biggest_one)
					biggest_one=arr[i*row+j];

			}
	}
	
	
	int order_number=1;
				for(int  i = 0 ; i < row; i++){
					for( int j = 0 ; j < column ; j++){
						if(arr[i*row+j]!=0 ){

							arr[i*row+j]=order_number;
							order_number++;
							}
						if(arr[i*row+j]==biggest_one+1)
							arr[i*row+j]=-5;
							cord.spaceX=i;
							cord.spaceY=j;
						}
				}
		}
		return cord;
	}

space_cord BoardArray1d::move(char move , space_cord cord){
	
	if(move == 'l' || move == 'L'){
				if(cord.spaceY > 0 && cord.spaceY <=column-1 && arr[cord.spaceX*row+cord.spaceY-1]!=0){
					int temp=arr[cord.spaceX*row+cord.spaceY-1];
					cord.spaceY-=1;
					arr[cord.spaceX*row+cord.spaceY]=-5;
					arr[cord.spaceX*row+cord.spaceY+1]=temp;
					}
				}
				if(move == 'r' || move == 'R'){
				if(cord.spaceY >= 0 && cord.spaceY < column-1 && arr[cord.spaceX*row+cord.spaceY+1]!=0){
					int temp=arr[cord.spaceX*row+cord.spaceY+1];
					cord.spaceY+=1;
					arr[cord.spaceX*row+cord.spaceY]=-5;
					arr[cord.spaceX*row+cord.spaceY-1]=temp;
					}
				}
			if(move == 'u' || move == 'U'){
				if(cord.spaceX > 0 && cord.spaceX <= row-1 && arr[cord.spaceX*row+cord.spaceY]!=0){
					int temp=arr[cord.spaceX*row+cord.spaceY];
					cord.spaceX-=1;
					arr[cord.spaceX*row+cord.spaceY]=-5;
					arr[cord.spaceX*row+cord.spaceY]=temp;
					}
				}
			if(move == 'd' || move == 'D'){
				if(cord.spaceX >= 0 && cord.spaceX < row-1 && arr[cord.spaceX*row+cord.spaceY]!=0){
					int temp=arr[cord.spaceX*row+cord.spaceY];
					cord.spaceX+=1;
					arr[cord.spaceX*row+cord.spaceY]=-5;
					arr[cord.spaceX*row+cord.spaceY]=temp;
						}
					}
				number_of_move++;
				return cord;
				}
bool BoardArray1d::isSolved(){
	int type=assign_puzzle_type();
	int check=true;

	if(type==0){ // this condition checks whether puzzle of hw1 is solved
	int value_of_rooms=1;
	for(int i = 0 ; i < row ; i++){
		for (int j = 0 ; j < column ; j++){
			if(i == row-1 && j== column-1)
				continue;
			else{

				if(arr[i*row+j]!=value_of_rooms){
					check = false;
				}
				value_of_rooms+=1;
					}
				}
			}		
		}
	else{
		int solution_control_arr[row][column];
		for(int i=0 ; i< row ; i++){
			for(int j=0 ; j < column ;j++){
				solution_control_arr[i][j]=arr[i*row+j];
			}
		}
 
		int biggest_one=solution_control_arr[0][0];
		space_cord solution_space;
	for( int i = 0 ; i < row; i++){
		for( int j = 1 ; j < column ; j++){
				if(solution_control_arr[i][j] > biggest_one){
					biggest_one=solution_control_arr[i][j];
				}

			}
	}
	
	
	int order_number=1;
				for(int  i = 0 ; i < row; i++){
					for( int j = 0 ; j < column ; j++){
						if(solution_control_arr[i][j]!=0 ){

							solution_control_arr[i][j]=order_number;
							order_number++;
							}
						if(solution_control_arr[i][j]==biggest_one+1)
							solution_control_arr[i][j]=-5;
						}
				}
				for(int i=0 ; i< row ; i++){
					for(int j=0 ; j <column ;j++){
						if(solution_control_arr[i][j]!=arr[i*row+j]){
							check=false;
							break;
						}
					}
				}
			}
			return check;
		}

    int BoardArray1d::number_of_moves(){
	return number_of_move;
}

int BoardArray1d::operator()(int i , int j){
    return arr[i*row+j];
}


}
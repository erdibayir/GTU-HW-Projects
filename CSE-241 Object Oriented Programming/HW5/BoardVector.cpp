#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "BoardVector.h"

using namespace std;

namespace Puzzle{

    int BoardVector::check_random_number(int **temp_arr,int random_number,int row ,int column){
	int i,j;
	int check=1;
	
	for(i = 0 ; i < row  ; i++){
		for(j = 0 ; j < column ; j++){
			if(temp_arr[i][j]==random_number){	
				check=0;
				break;
			}
		}
	}
	return check;
}

    space_cord BoardVector::setsize(int size){
        int row=size;
	int column=size;
	int **temp_arr;

        space_cord cord; // define space room X and Y coordinates
		cord.spaceX=rand() % row;
		cord.spaceY=rand() % column;

		temp_arr = new int* [size];
   	 	for (int i=0; i<row; i++)
        	temp_arr[i] = new int[size];


		temp_arr[cord.spaceX][cord.spaceY]=-5;

		
		for (int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < column ; j++){
					if(temp_arr[i][j]!=-5){

						int random_number=1+rand() % ((row*column)-1);
						int check;

						check=check_random_number(temp_arr,random_number,row,column);//this control function check that the random number is not already used

						while(check==0){
							random_number=1+rand() % ((row*column)-1);
							check=check_random_number(temp_arr,random_number,row,column);
					}
							temp_arr[i][j]=random_number;
			}
		}

	}
		for(int i = 0 ; i < row ; i++ ){
		std::vector <int> temp;
			for(int j=0 ; j < column ; j++ ){
				int value=temp_arr[i][j];
				temp.push_back(value);
			}
		arr.push_back(temp);
	    }
            return cord;	
    }
void BoardVector::print(){
    int define_puzzle=0;  // this variable assign that this puzzle read to file puzzle or hw1 puzzle
	for(int i=0 ;i < arr.size(); i++){
		for(int j=0 ; j < arr[i].size() ;j++){
			if(arr[i][j]==0)
				define_puzzle++;
		}
	}
	if(define_puzzle==0){
		
		for (int i = 0 ; i < arr.size() ; i++){

			for(int j = 0 ; j < arr[i].size() ; j++){
					if(arr[i][j] != -5)
					cout <<arr[i][j] << "\t" ;
					else
					cout << " \t";
					}
				cout << endl;
		}
	}
	else{
		for ( int i = 0 ; i < arr.size() ; i++){
			for( int j = 0 ; j < arr[i].size() ; j++){
				if(arr[i][j]==-5){
					cout << "bb" << " ";
				}
				else if(arr[i][j]==0)
					cout <<"00" << " ";
				else if(arr[i][j] < 10)
					cout << "0" << arr[i][j] << " ";
				else
					cout << arr[i][j] << " ";
			}

				cout << endl;
		}
	}

}
void BoardVector::readfromfile(string load_name){
        int i,j;	
	string data;
	string line;

	int row=0;
	int column=0;

 	arr.resize(0);
	ifstream input_file;
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


        // Convert string array to vector for using functions
		int temp_integer;
		for(int i = 0 ; i < row ; i++ ){
		vector <int> temp;
			for(int j=0 ; j < column ; j++ ){
				if(STRING[i][j]=="bb"){
					temp.push_back(-5);
				}
				else{
					temp_integer=atoi(STRING[i][j].c_str());
					temp.push_back(temp_integer);
				}
			}
		arr.push_back(temp);
	}	
}
void BoardVector::writeToFile(){
    int row=arr.size();
	int column=arr[0].size();
	ofstream save_file;
	int i,j;
	string save_name;
	cout << "Enter a name for save file(Example:a.txt):" << endl;
	cin >> save_name;
	cout << "Saving..." << endl;
	save_file.open(save_name);

	for( i=0 ; i< row ; i++){
		for(j=0 ; j<column ; j++){
			if(j != column-1){
			if(arr[i][j]==-5){
					save_file << "bb" << " ";
				}
				else if(arr[i][j]==0)
					save_file <<"00" << " ";
				else if(arr[i][j] < 10)
					save_file << "0" << arr[i][j] << " ";
				else
					save_file << arr[i][j] << " ";
			}
			else{
				if(arr[i][j]==-5){
					save_file << "bb";
				}
				else if(arr[i][j]==0)
					save_file <<"00";
				else if(arr[i][j] < 10)
					save_file << "0" << arr[i][j];
				else
					save_file << arr[i][j];
			}
		}
		if(i!=row-1)
			save_file << endl;
	}
	save_file.close();
}

int BoardVector::assign_puzzle_type(){
    int type=0; // if type:0 we play hw1 puzzle
	int row=arr.size();
	int column=arr[0].size();
	for(int i=0 ; i < row ; i++){
		for(int j=0 ; j< column ; j++){
			if(arr[i][j]==0)
				type++;
		}
	}
	return type;
}


space_cord BoardVector::reset(space_cord cord){
    int row=arr.size();
	int column=arr[0].size();
	int type=assign_puzzle_type();
	if(type==0){
	int order_number=1;
	for(int i = 0 ; i < row; i++){
		for(int j = 0 ; j < column ; j++){
			arr[i][j]=order_number;
				order_number++;
					}
			}
			cord.spaceX=row-1;
			cord.spaceY=column-1;
			arr[cord.spaceX][cord.spaceY]=-5;
		}
		else {

			int biggest_one=arr[0][0];
	
	for( int i = 0 ; i < row; i++){
		for( int j = 1 ; j < column ; j++){
				if(arr[i][j] > biggest_one)
					biggest_one=arr[i][j];

			}
	}
	
	
	int order_number=1;
				for(int  i = 0 ; i < row; i++){
					for( int j = 0 ; j < column ; j++){
						if(arr[i][j]!=0 ){

							arr[i][j]=order_number;
							order_number++;
							}
						if(arr[i][j]==biggest_one+1)
							arr[i][j]=-5;
							cord.spaceX=i;
							cord.spaceY=j;
						}
				}
		}
		return cord;

}
space_cord BoardVector::move(char move ,space_cord cord){
    int row=arr.size();
	int column=arr[0].size();
	if(move == 'l' || move == 'L'){
				if(cord.spaceY > 0 && cord.spaceY <=column-1 && arr[cord.spaceX][cord.spaceY-1]!=0){
					int temp=arr[cord.spaceX][cord.spaceY-1];
					cord.spaceY-=1;
					arr[cord.spaceX][cord.spaceY]=-5;
					arr[cord.spaceX][cord.spaceY+1]=temp;
					}
				}
				if(move == 'r' || move == 'R'){
				if(cord.spaceY >= 0 && cord.spaceY < column-1 && arr[cord.spaceX][cord.spaceY+1]!=0){
					int temp=arr[cord.spaceX][cord.spaceY+1];
					cord.spaceY+=1;
					arr[cord.spaceX][cord.spaceY]=-5;
					arr[cord.spaceX][cord.spaceY-1]=temp;
					}
				}
			if(move == 'u' || move == 'U'){
				if(cord.spaceX > 0 && cord.spaceX <= row-1 && arr[cord.spaceX-1][cord.spaceY]!=0){
					int temp=arr[cord.spaceX-1][cord.spaceY];
					cord.spaceX-=1;
					arr[cord.spaceX][cord.spaceY]=-5;
					arr[cord.spaceX+1][cord.spaceY]=temp;
					}
				}
			if(move == 'd' || move == 'D'){
				if(cord.spaceX >= 0 && cord.spaceX < row-1 && arr[cord.spaceX+1][cord.spaceY]!=0){
					int temp=arr[cord.spaceX+1][cord.spaceY];
					cord.spaceX+=1;
					arr[cord.spaceX][cord.spaceY]=-5;
					arr[cord.spaceX-1][cord.spaceY]=temp;
					}
				}

				return cord;
}
bool BoardVector::isSolved(){
    int type=assign_puzzle_type();
	int check=true;
	int row=arr.size();
	int column=arr[0].size();
	if(type==0){ // this condition checks whether puzzle of hw1 is solved
	int value_of_rooms=1;
	for(int i = 0 ; i < row ; i++){
		for (int j = 0 ; j < column ; j++){
			if(i == row-1 && j== column-1)
				continue;
			else{

				if(arr[i][j]!=value_of_rooms){
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
				solution_control_arr[i][j]=arr[i][j];
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
						if(solution_control_arr[i][j]!=arr[i][j]){
							check=false;
							break;
						}
					}
				}

	}

		return check;

}

int BoardVector::number_of_moves(){
    return number_of_move;
}
int BoardVector::operator()(int i , int j){
    return arr[i][j];
}

}
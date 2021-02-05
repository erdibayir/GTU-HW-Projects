#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;




struct space_cord{

		int spaceX;
		int spaceY;
};

struct coord
{
	int X;
	int Y;
	
};

struct heuristic
{
	int heuristic_value;
	string name;
};
int check_random_number(int **puzzle,int size,int random_number);
void fill_puzzle(int **puzzle , int size);
void print_puzzle(int **puzzle, int size);
space_cord select_move_direction(int **puzzle ,space_cord cord, string move,int size);
int succed_control(int **puzzle, int size);
void gameplay(int **puzzle,int size);
int calculate_heuristic_value(int **puzzle, int size);
coord find_order_number_coord(int **puzzle, int size, int order_number);

int main(){
	srand(time(NULL));
	int **puzzle;    // 2-D pointer which represents puzzle
	int size;

	cout << "Please enter the problem size " << endl;
	cin >> size ;
	cout << endl;
	gameplay(puzzle,size);

	return 0;
}

coord find_order_number_coord(int **puzzle, int size, int order_number){
	coord c1;
	for(int i =0 ; i < size ; i++){
		for(int j= 0 ; j<size ; j++){
			if(puzzle[i][j]==order_number){
				c1.X=i;
				c1.Y=j;
			}
		}
	}
	return c1;


}
int calculate_heuristic_value(int **puzzle, int size){
	int order_number = 1;
	coord c1;
	int heuristic_value=0;

	for(int i =0 ; i < size ; i++){
		for (int j =0 ; j < size ;j++){
			if(order_number!=size*size){
					if(puzzle[i][j]!= order_number){
						c1=find_order_number_coord(puzzle ,size ,order_number);

					heuristic_value+=fabs(c1.X-i) + fabs(c1.Y-j);	
					}
				}	
				order_number++;
			}
						
	}

	return heuristic_value;
}

int check_random_number(int **puzzle,int size,int random_number){

	int i,j;
	int check=1;
	for(i = 0 ; i < size  ; i++){
		for(j = 0 ; j < size ; j++){
			if(puzzle[i][j]==random_number){
				check=0;
				break;
			}
		}
	}
	return check;
}

void fill_puzzle(int **puzzle , int size){
	for (int i = 0 ; i < size ; i++){
				for(int j = 0 ; j < size ; j++){
					if(puzzle[i][j]!=-5){

						int random_number=1+rand() % ((size*size)-1);
						int check;

						check=check_random_number(puzzle,size,random_number);//this control function check that the random number is not already used

						while(check==0){
							random_number=1+rand() % ((size*size)-1);
							check=check_random_number(puzzle,size,random_number);
					}
							puzzle[i][j]=random_number;
			}
		}
	}
}
void print_puzzle(int **puzzle, int size){
		for (int i = 0 ; i < size ; i++){

			for(int j = 0 ; j < size ; j++){
					if(puzzle[i][j] != -5)
					cout <<puzzle[i][j] << "\t" ;
					else
					cout << " \t";
					}
				cout << endl;
		}
	}

space_cord select_move_direction(int **puzzle ,space_cord cord, string move,int size){
			if(move == "l" || move == "L"){
				if(cord.spaceY > 0 && cord.spaceY <= size-1){
					int temp=puzzle[cord.spaceX][cord.spaceY-1];
					cord.spaceY-=1;
					puzzle[cord.spaceX][cord.spaceY]=-5;
					puzzle[cord.spaceX][cord.spaceY+1]=temp;
					}
				}
			if(move == "r" || move == "R"){
				if(cord.spaceY >= 0 && cord.spaceY < size-1){
					int temp=puzzle[cord.spaceX][cord.spaceY+1];
					cord.spaceY+=1;
					puzzle[cord.spaceX][cord.spaceY]=-5;
					puzzle[cord.spaceX][cord.spaceY-1]=temp;
					}
				}
			if(move == "u" || move == "U"){
				if(cord.spaceX > 0 && cord.spaceX <= size-1){
					int temp=puzzle[cord.spaceX-1][cord.spaceY];
					cord.spaceX-=1;
					puzzle[cord.spaceX][cord.spaceY]=-5;
					puzzle[cord.spaceX+1][cord.spaceY]=temp;
					}
				}
			if(move == "d" || move == "D"){
				if(cord.spaceX >= 0 && cord.spaceX < size-1){
					int temp=puzzle[cord.spaceX+1][cord.spaceY];
					cord.spaceX+=1;
					puzzle[cord.spaceX][cord.spaceY]=-5;
					puzzle[cord.spaceX-1][cord.spaceY]=temp;
					}
				}

			if(move == "s" || move == "S"){
				int order_number=1;
				for(int i = 0 ; i < size; i++){
					for(int j = 0 ; j < size ; j++){
							puzzle[i][j]=order_number;
							order_number++;
						}
				}
				cord.spaceX=size-1;
				cord.spaceY=size-1;
				puzzle[cord.spaceX][cord.spaceY]=-5;

				int random_moves =size*size; // number of random moves;
				int counter_for_direction; // it choose random direction

				for(int i = 0 ; i < random_moves ; i++){
					counter_for_direction=1+rand() % 4 ;
					if(counter_for_direction==1){
						cord=select_move_direction(puzzle,cord,"l",size);
					}

					if(counter_for_direction==2){
						cord=select_move_direction(puzzle,cord,"r",size);
					}
					if(counter_for_direction==3){
						cord=select_move_direction(puzzle,cord,"u",size);
					}
					if(counter_for_direction==4){
						cord=select_move_direction(puzzle,cord,"d",size);
					}
 				}
 				int check_succed=succed_control(puzzle,size);  
 				if(check_succed==0)
 					cord = select_move_direction(puzzle,cord,"s",size);
 				else
					cout <<"Puzzle was shuffled in " << random_moves <<" moves!!" << endl << endl;

			}
				return cord;
}
int succed_control(int **puzzle, int size){
	int value_of_rooms=1;
	int check_succed=0;
	for(int i = 0 ; i < size ; i++){
		for (int j = 0 ; j < size ; j++){
			if(i == size-1 && j== size-1)
				continue;
			else{

				if(puzzle[i][j]!=value_of_rooms)
					check_succed =check_succed+1;
				value_of_rooms+=1;
				}
			
		}
	}
		return check_succed;

}
void gameplay(int **puzzle,int size){
		int i;
		string move;
		int total_moves=0; // counter for moves
		space_cord cord; // define space room X and Y coordinates
		cord.spaceX=rand() % size;
		cord.spaceY=rand() % size;
		int check_succed;

	    // allocate memories for puzzle
	 	puzzle = (int **)malloc(size * sizeof(int *));
   	 	for (i=0; i<size; i++)
        	puzzle[i] = (int *)malloc(size * sizeof(int));

	    puzzle[cord.spaceX][cord.spaceY]=-5; // assign -5 to space room coordinates

		fill_puzzle(puzzle,size);	// this function fill the puzzle with random numbers
		cout << "Your initial random board is" << endl;
		print_puzzle(puzzle,size);	// this function show the puzzle on screen

		

		while(1){
		cout << "Your Move:";
		cin >> move;
		total_moves+=1;

			
			if(move == "l" || move == "L")
				cord=select_move_direction(puzzle,cord,"l",size); // this function select move direction for rebuild puzzle
			if(move == "r" || move == "R")
				cord=select_move_direction(puzzle,cord,"r",size);
			if(move == "d" || move == "D")
				cord=select_move_direction(puzzle,cord,"d",size);
			if(move == "U" || move == "u")
				cord=select_move_direction(puzzle,cord,"u",size);
			if(move == "i" || move == "I"){
				int temp_spaceX=cord.spaceX;
				int temp_spaceY=cord.spaceY; 

				heuristic L,R,D,U,min;

				 L.heuristic_value=500,R.heuristic_value=500,D.heuristic_value=500,U.heuristic_value=500;

				cord=select_move_direction(puzzle,cord,"l",size);
				if(temp_spaceY!= cord.spaceY){		
				L.heuristic_value=calculate_heuristic_value(puzzle,size); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"r",size);
			}

			cord=select_move_direction(puzzle,cord,"r",size);
				if(temp_spaceY!= cord.spaceY){		
				R.heuristic_value=calculate_heuristic_value(puzzle,size); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"l",size);
			}


			cord=select_move_direction(puzzle,cord,"d",size);
				if(temp_spaceX!= cord.spaceX){		
				D.heuristic_value=calculate_heuristic_value(puzzle,size); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"u",size);
			}

			cord=select_move_direction(puzzle,cord,"u",size);
				if(temp_spaceX!= cord.spaceX){		
				U.heuristic_value=calculate_heuristic_value(puzzle,size); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"d",size);
			}

			L.name="left";
			R.name="right";
			D.name="down";
			U.name="up";

			heuristic arr[4];
			arr[0]=L;
			arr[1]=R;
			arr[2]=D;
			arr[3]=U;

			min.heuristic_value=L.heuristic_value;
			min.name=L.name;
			
			for(int i=1; i< 4 ;i++){
				if(arr[i].heuristic_value < min.heuristic_value){
					min.heuristic_value=arr[i].heuristic_value;
					min.name=arr[i].name;
						}
					}

			if(min.name=="left"){
				cout << "Intelligent move chooses L" << endl;
				cord=select_move_direction(puzzle,cord,"l",size);
			}
			if(min.name=="right"){
				cout << "Intelligent move chooses R" << endl;
				cord=select_move_direction(puzzle,cord,"r",size);
			}
			if(min.name=="down"){
				cout << "Intelligent move chooses D" << endl;
				cord=select_move_direction(puzzle,cord,"d",size);
			}
			if(min.name=="up"){
				cout << "Intelligent move chooses U" << endl;
				cord=select_move_direction(puzzle,cord,"u",size);
			}


			}
			if(move == "s" || move == "S"){
				total_moves=0;
				cord=select_move_direction(puzzle,cord,"s",size);
			}
			if(move == "q" || move == "Q"){
				cout << "Exit..." << endl;	
				break;
			}

			check_succed=succed_control(puzzle,size); // this function do that if problem is solved return 0 if isnt solved return 1 
			
			print_puzzle(puzzle,size);

			if(check_succed==0){
			cout << "You Win!" << endl;
			cout << "Total number of moves:" << total_moves << endl;
				break;
			}	
		}
}
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct puzzle_struct
{
	int **arr;
	int row;
	int column;
	
};

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

puzzle_struct check_succed(puzzle_struct puzzle);
puzzle_struct load_configuration(string load_name,puzzle_struct puzzle);
void print_puzzle(puzzle_struct puzzle );
space_cord select_move_direction(puzzle_struct puzzle ,space_cord cord, string move);
void gameplay(puzzle_struct puzzle,string load_name);
int succed_control(puzzle_struct puzzle);
void save_configuration(puzzle_struct puzzle );


int main(int argc, char  *argv[]){
	int i,j;
	puzzle_struct puzzle;
	string data;
	string line;
	puzzle.row=0;
	puzzle.column=0;	
	string load_name;
	if(argc==1){

		cout << "Enter txt for loading(Ex:a.txt):";
		cin >> load_name;
		puzzle=load_configuration(load_name , puzzle);
		gameplay(puzzle,load_name); 
	}	

 	else if(argc==2){
 		load_name=argv[1];
 		puzzle=load_configuration(load_name , puzzle);
		gameplay(puzzle,load_name);
		}
	return 0;
}

puzzle_struct load_configuration(string load_name,puzzle_struct puzzle){
	int i,j;	
	string data;
	string line;

	puzzle.row=0;
	puzzle.column=0;

 
	ifstream input_file;
	input_file.open(load_name);
	
	//Find Row of Puzzle in File
	while(!input_file.eof()){
		getline(input_file,line);
		puzzle.row++;
		
	}
	
	// Find Column of Puzzle in File
	for(i=0 ; line[i] ; i++){
		if(line[i]==' ')
			puzzle.column++;
	}
	puzzle.column++;
	
	input_file.close();

	string STRING[puzzle.row][puzzle.column];

	input_file.open(load_name);

	//Read data of file to string  array
	while(!input_file.eof()){
		for(i=0 ;i < puzzle.row ; i++){
			for(j=0 ; j < puzzle.column ; j++){
				input_file >> data;
				STRING[i][j]=data;		
			}
		}		
	}
	input_file.close();

	//Create integer puzzle array

	
	puzzle.arr = (int **)malloc(puzzle.row * sizeof(int *));
   	 	for (i=0; i<puzzle.row; i++)
        	puzzle.arr[i] = (int *)malloc(puzzle.column * sizeof(int));

        // Convert string array to int array for using functions
		int temp;

		for(int i=0 ; i < puzzle.row ;i ++){
			for(int j=0 ; j < puzzle.column ; j++){
				if(STRING[i][j]=="bb")
			 		puzzle.arr[i][j]=-5;

			 	else{
					temp=atoi(STRING[i][j].c_str());
					puzzle.arr[i][j]=temp;	 		
			 	}		
			}
		}
		
		return puzzle;

}

void save_configuration(puzzle_struct puzzle){
	ofstream save_file;
	int i,j;
	string save_name;
	cout << "Enter a name for save file(Example:a.txt):" << endl;
	cin >> save_name;
	cout << "Saving..." << endl;
	save_file.open(save_name);

	for( i=0 ; i< puzzle.row ; i++){
		for(j=0 ; j<puzzle.column ; j++){
			if(j != puzzle.column-1){
			if(puzzle.arr[i][j]==-5){
					save_file << "bb" << " ";
				}
				else if(puzzle.arr[i][j]==0)
					save_file <<"00" << " ";
				else if(puzzle.arr[i][j] < 10)
					save_file << "0" << puzzle.arr[i][j] << " ";
				else
					save_file << puzzle.arr[i][j] << " ";
			}
			else{
				if(puzzle.arr[i][j]==-5){
					save_file << "bb";
				}
				else if(puzzle.arr[i][j]==0)
					save_file <<"00";
				else if(puzzle.arr[i][j] < 10)
					save_file << "0" << puzzle.arr[i][j];
				else
					save_file << puzzle.arr[i][j];
			}
		}
		if(i!=puzzle.row-1)
			save_file << endl;
	}
	save_file.close();

}


void print_puzzle(puzzle_struct puzzle){
			
		//print function
		for ( int i = 0 ; i < puzzle.row ; i++){
			for( int j = 0 ; j < puzzle.column ; j++){
				if(puzzle.arr[i][j]==-5){
					cout << "bb" << " ";
				}
				else if(puzzle.arr[i][j]==0)
					cout <<"00" << " ";
				else if(puzzle.arr[i][j] < 10)
					cout << "0" << puzzle.arr[i][j] << " ";
				else
					cout << puzzle.arr[i][j] << " ";
			}

				cout << endl;
		}	
}

space_cord select_move_direction(puzzle_struct puzzle ,space_cord cord, string move){
			if(move == "l" || move == "L"){
				if(cord.spaceY > 0 && cord.spaceY <= puzzle.column-1 && puzzle.arr[cord.spaceX][cord.spaceY-1]!=0){
					int temp=puzzle.arr[cord.spaceX][cord.spaceY-1];
					cord.spaceY-=1;
					puzzle.arr[cord.spaceX][cord.spaceY]=-5;
					puzzle.arr[cord.spaceX][cord.spaceY+1]=temp;
					}
				}
			if(move == "r" || move == "R"){
				if(cord.spaceY >= 0 && cord.spaceY < puzzle.column-1 && puzzle.arr[cord.spaceX][cord.spaceY+1]!=0){
					int temp=puzzle.arr[cord.spaceX][cord.spaceY+1];
					cord.spaceY+=1;
					puzzle.arr[cord.spaceX][cord.spaceY]=-5;
					puzzle.arr[cord.spaceX][cord.spaceY-1]=temp;
					}
				}
			if(move == "u" || move == "U"){
				if(cord.spaceX > 0 && cord.spaceX <= puzzle.row-1 && puzzle.arr[cord.spaceX-1][cord.spaceY]!=0){
					int temp=puzzle.arr[cord.spaceX-1][cord.spaceY];
					cord.spaceX-=1;
					puzzle.arr[cord.spaceX][cord.spaceY]=-5;
					puzzle.arr[cord.spaceX+1][cord.spaceY]=temp;
					}
				}
			if(move == "d" || move == "D"){
				if(cord.spaceX >= 0 && cord.spaceX < puzzle.row-1 && puzzle.arr[cord.spaceX+1][cord.spaceY]!=0){
					int temp=puzzle.arr[cord.spaceX+1][cord.spaceY];
					cord.spaceX+=1;
					puzzle.arr[cord.spaceX][cord.spaceY]=-5;
					puzzle.arr[cord.spaceX-1][cord.spaceY]=temp;
					}
				}

	
				return cord;
}

coord find_order_number_coord(puzzle_struct puzzle, int order_number){
	coord c1;
	int counter=0;
	for(int i =0 ; i < puzzle.row ; i++){
		for(int j= 0 ; j<puzzle.column ; j++){
				if(puzzle.arr[i][j]!=0 ){
					counter++;

					if(counter==order_number){
						c1.X=i;
						c1.Y=j;
						break;
					}
				}
				
			
		}
	}
	
	return c1;
}
int calculate_heuristic_value(puzzle_struct puzzle){
	int order_number = 1;
	coord c1;
	int heuristic_value=0;

	for(int i =0 ; i < puzzle.row ; i++){
		for (int j =0 ; j < puzzle.column ;j++){
					if(puzzle.arr[i][j]==order_number){
						c1=find_order_number_coord(puzzle ,order_number);
						heuristic_value+=fabs(c1.X-i) + fabs(c1.Y-j);
				
						order_number++;
						i=0;
						j=0;
					}
					
			}
						
	}
	
	return heuristic_value;
}

puzzle_struct check_succed_function(puzzle_struct puzzle){

	;

	int biggest_one=puzzle.arr[0][0];
	
	for( int i = 0 ; i < puzzle.row; i++){
		for( int j = 1 ; j < puzzle.column ; j++){
				if(puzzle.arr[i][j] > biggest_one)
					biggest_one=puzzle.arr[i][j];

			}
	}
	
	
	int order_number=1;
				for(int  i = 0 ; i < puzzle.row; i++){
					for( int j = 0 ; j < puzzle.column ; j++){
						if(puzzle.arr[i][j]!=0 ){

							puzzle.arr[i][j]=order_number;
							order_number++;
							}
						if(puzzle.arr[i][j]==biggest_one+1)
							puzzle.arr[i][j]=-5;
						}
				}
				
					int last_value=0;
				

		return puzzle;		
}

void gameplay(puzzle_struct puzzle,string load_name){
		int i;
		string move;
		int total_moves=0; // counter for moves
		space_cord cord; // define space room X and Y coordinates
		
		for (int i=0 ; i < puzzle.row ; i++){
			for(int j=0 ; j < puzzle.column ; j++ ){
				if(puzzle.arr[i][j]==-5){
					cord.spaceX=i;
					cord.spaceY=j;
					break;
				}
			}
		}
	

	    puzzle.arr[cord.spaceX][cord.spaceY]=-5; // assign -5 to space room coordinates

	    cout << "R-Right" << endl << "L-Left" << endl << "D-Down" << endl << "U-Up" << endl
	    	 << "E- Save Configuration" << endl << "Y-Load Configuration" << endl << "V-Solve Puzzle" <<
	    	 	endl << "T-Total Moves" << endl << endl;


	    	puzzle_struct temp; 
	    	 temp=puzzle;
			temp=check_succed_function(temp);
			puzzle=load_configuration(load_name,puzzle);
			 
			  print_puzzle(puzzle);
		
		while(1){
		cout << "Your Move:";
		cin >> move;
			if(move !="t" && move!="T"){
				total_moves=total_moves+1;
			}

			if(move == "Y" || move == "y"){
				cout << "Load your configuration file to puzzle(Example:a.txt):";
				string load_name;
				cin >> load_name;
				puzzle=load_configuration(load_name,puzzle);
				
			for(int i=0 ; i < puzzle.row ; i++){
				for(int j=0 ; j < puzzle.column ; j++ ){
					if(puzzle.arr[i][j]==-5){
						cord.spaceX=i;
						cord.spaceY=j;
						break;
						}
					}
				}
			}
			
			
			if(move == "l" || move == "L")
				cord=select_move_direction(puzzle,cord,"l"); // this function select move direction for rebuild puzzle
			if(move == "r" || move == "R")
				cord=select_move_direction(puzzle,cord,"r");
			if(move == "d" || move == "D")
				cord=select_move_direction(puzzle,cord,"d");
			if(move == "U" || move == "u")
				cord=select_move_direction(puzzle,cord,"u");
			if(move == "E" || move == "e")
				save_configuration(puzzle);
			if(move == "T" || move == "t")
				cout << "Total Moves:" << total_moves << endl;
			if(move == "q" || move == "Q"){
				cout << "Exit..." << endl;	
				break;
			}


			if(move == "v" || move == "V"){

				while(check_succed!=0){
					int check_succed=0;
					for(int i=0 ; i< puzzle.row ; i++){
						for(int j=0 ; j <puzzle.column ;j++){
							if(temp.arr[i][j]!=puzzle.arr[i][j])
								check_succed++;
						}
					}


				int temp_spaceX=cord.spaceX;
				int temp_spaceY=cord.spaceY; 

				heuristic L,R,D,U,min;

				 L.heuristic_value=500,R.heuristic_value=500,D.heuristic_value=500,U.heuristic_value=500;

				cord=select_move_direction(puzzle,cord,"l");
				if(temp_spaceY!= cord.spaceY){
						
				L.heuristic_value=calculate_heuristic_value(puzzle); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"r");
			}

			cord=select_move_direction(puzzle,cord,"r");
				if(temp_spaceY!= cord.spaceY){
						
				R.heuristic_value=calculate_heuristic_value(puzzle); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"l");
			}


			cord=select_move_direction(puzzle,cord,"d");
				if(temp_spaceX!= cord.spaceX){		
				D.heuristic_value=calculate_heuristic_value(puzzle); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"u");
			}

			cord=select_move_direction(puzzle,cord,"u");
				if(temp_spaceX!= cord.spaceX){		
				U.heuristic_value=calculate_heuristic_value(puzzle); // this function calculate the distance to final pozisition
				cord=select_move_direction(puzzle,cord,"d");
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

			
			min=arr[0];
			
			for(int i=1; i< 4 ;i++){
				if(arr[i].heuristic_value < min.heuristic_value){
					min.heuristic_value=arr[i].heuristic_value;
					min.name=arr[i].name;
						}
					}

			int counter_for_random_move=0;
			for(int i=0 ; i< 4 ; i++){
				if(min.heuristic_value==arr[i].heuristic_value)
					counter_for_random_move++;
			}
			
			if(counter_for_random_move>=2){
				
				int random_move = rand()%4;
				if(random_move==0){
					cord=select_move_direction(puzzle,cord,"l");
						
				}
				if(random_move==1){
					cord=select_move_direction(puzzle,cord,"r");
					
				}
				if(random_move==2){
					cord=select_move_direction(puzzle,cord,"d");
					
				}
				if(random_move==3){
					cord=select_move_direction(puzzle,cord,"u");
					
				}
			}
			

			if(min.name=="left"){
				
				cord=select_move_direction(puzzle,cord,"l");
			}
			if(min.name=="right"){
				
				cord=select_move_direction(puzzle,cord,"r");
			}
			if(min.name=="down"){
				
				cord=select_move_direction(puzzle,cord,"d");
			}
			if(min.name=="up"){
				
				cord=select_move_direction(puzzle,cord,"u");
					}
					
					cout << "Total Moves:" << total_moves << endl;
					cout << endl << endl;

				}
			}
				print_puzzle(puzzle);	
			}
			
		}
	
		



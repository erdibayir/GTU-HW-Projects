#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


struct space_cord{

		int spaceX; // this structure hold X and Y cordinates of space room
		int spaceY;
};
struct heuristic // tnis structure use for calculate heuristic distance for intellegent move
{
	int heuristic_value;
	string name;
};

struct coord
{
	int X;
	int Y;
	
};

class NPuzzle
{
public:
	NPuzzle() {    };
	
	void print();
	void print_report(int total_moves);
	void readfromfile(string load_name);
	void writeToFile();
	space_cord shuffle(space_cord cord);
	space_cord reset(space_cord cord);
	void setsize(int size);
	space_cord moveRandom(space_cord cord);
	space_cord moveIntellegent(space_cord cord);
	space_cord move(char  move , space_cord cord);
	space_cord solvePuzzle(space_cord cord);
	
	void gameplay();

	
	
private:
	class Board
	{
	public:
		
		Board() { };
		void print();
		void readfromfile(string load_name);
		void writeToFile();
		space_cord reset(space_cord cord);
		void setsize(int size);
		space_cord move(char move , space_cord cord);
		bool isSolved();
		void get_ordinary_puzzle();
		int check_random_number(int** temp_arr,int random_number,int row ,int column);
		int get_row();
		int get_column();
		vector <vector <int > > get_vector();
		int assign_puzzle_type();
		int calculate_heuristic_distance();
		coord find_order_number_coord(int order_number);
	
	private:
		vector <vector<int> > arr;
		char last_move;
		int number_of_moves;

	};
	Board board;
	vector<Board> v_board;
	friend ostream&  operator << (ostream& os,  Board& board){
		board.print();
		return os;
	}

};
void NPuzzle::setsize(int size){
	board.setsize(size);
}

int NPuzzle::Board::get_row(){
	return arr.size();
}
int NPuzzle::Board::get_column(){
	return arr[0].size();
}
vector <vector <int > > NPuzzle::Board::get_vector(){
	return arr;
}

bool NPuzzle::Board::isSolved(){
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
		
void NPuzzle::Board::readfromfile(string load_name){
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
int NPuzzle::Board::check_random_number(int **temp_arr,int random_number,int row ,int column){
	int i,j;
	int check=1;
	
	for(i = 0 ; i < column  ; i++){
		for(j = 0 ; j < column ; j++){
			if(temp_arr[i][j]==random_number){	
				check=0;
				break;
			}
		}
	}
	return check;
}
void NPuzzle::Board::setsize(int size){
	int row=size;
	int column=size;
	int **temp_arr;
        space_cord cord; // define space room X and Y coordinates
		cord.spaceX=rand() % row;
		cord.spaceY=rand() % column;

		temp_arr = (int **)malloc(row * sizeof(int *));
   	 	for (int i=0; i<row; i++)
        	temp_arr[i] = (int *)malloc(column * sizeof(int));
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
		vector <int> temp;
			for(int j=0 ; j < column ; j++ ){
				int value=temp_arr[i][j];
				temp.push_back(value);
			}
		arr.push_back(temp);
	}	

}
space_cord NPuzzle::reset(space_cord cord){
	cord=board.reset(cord);
	v_board.resize(0); // Vector of board objects resized 0
	return cord;
}

int NPuzzle::Board::assign_puzzle_type(){ // this function assign that we are playing puzzle of hw1 or hw2 now.
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
space_cord NPuzzle::Board::reset(space_cord cord){
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
space_cord NPuzzle::move(char  move , space_cord cord){
	board.move(move , cord);
}
space_cord NPuzzle::Board::move(char move , space_cord cord){
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


void NPuzzle::writeToFile(){
	board.writeToFile();
}
void NPuzzle::Board::writeToFile(){
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
void NPuzzle::print(){
	board.print();
}
void NPuzzle::print_report(int total_moves){
	cout << "Total Moves:" << total_moves << endl;
}
space_cord NPuzzle::moveRandom(space_cord cord){
	
	int counter_for_direction; // it choose random direction
	counter_for_direction=1+rand() % 4 ;

	if(counter_for_direction==1){
		cord=move('l',cord);
	}
	if(counter_for_direction==2){
		cord=move('r',cord);
	}
	if(counter_for_direction==3){
		cord=move('u',cord);
	}
	if(counter_for_direction==4){
		cord=move('d',cord);
	}
 		return cord;
}

space_cord NPuzzle::shuffle(space_cord cord){
	cord=reset(cord); // reset the board to solution
	int size=board.get_row();
	int random_moves =size*size; // number of random moves;

	for(int i=0 ; i <5 ; i++){
		cord=moveRandom(cord); //space room  moves  size*size times 
	}
 				bool check_succed=board.isSolved();  
 				if(check_succed==true)
 					cord =shuffle(cord); // if space room didnt change end of the shuffle, it do shuffle to puzzle again
 				else
					cout <<"Puzzle was shuffled in " << random_moves <<" moves!!" << endl << endl;
 				return cord;
	
}
void NPuzzle::gameplay(){
		int i;
		char c_move;
		int total_moves=0; // counter for moves
		space_cord cord; // define space room X and Y coordinates
		int row=board.get_row(); // get row information
		int column=board.get_column();
		vector < vector<int> > arr=board.get_vector();

		for (int i=0 ; i < row ; i++){
			for(int j=0 ; j < column ; j++ ){
				if(arr[i][j]==-5){
					cord.spaceX=i;
					cord.spaceY=j;
					break;
				}
			}
		}
		arr[cord.spaceX][cord.spaceY]=-5;
		cout << "Your initial random board is" << endl;
		cout << board; // print with operator
		cout << endl;
	    cout << "R-Right" << endl << "L-Left" << endl << "D-Down" << endl << "U-Up" << endl
	    	 << "E- Save Configuration" << endl << "O-Load Configuration" << endl << "V-Solve Puzzle" << endl
	    	  << "T-Total Moves" << endl << "S-Shuflle" << endl << endl;


	    while(1){
			cout << "Your Move:";
			cin >> c_move;
			if(c_move !='t' && c_move!='T'){
				total_moves=total_moves+1;

			}
			
			if(c_move == 's' || c_move == 'S'){
				cord=shuffle(cord);
				total_moves=0;
				v_board.resize(1);
			}			

			if(c_move == 'o' || c_move == 'O'){
				cout << "Load your configuration file to puzzle(Example:a.txt):";
				string load_name;
				cin >> load_name;
				readfromfile(load_name);
				cout << "Your initial random board is" << endl << endl;
				int row=board.get_row(); // get row information
				int column=board.get_column();
				vector < vector<int> > arr=board.get_vector();
			for(int i=0 ; i < row ; i++){
				for(int j=0 ; j < column ; j++ ){
					if(arr[i][j]==-5){
						cord.spaceX=i;
						cord.spaceY=j;
						
						break;
						}
					}
				}

				v_board.push_back(board);
				int is_Fileread=1;   // this variable check the puzzle hw1 puzzle or hw2 puzzle
			}


			

			if(c_move == 'l' || c_move == 'L'){
				cord=move('l' ,cord);
			}
			if(c_move == 'r' || c_move == 'R'){
				cord=move('r' ,cord);
			}
			if(c_move == 'd' || c_move == 'D'){
				cord=move('d' ,cord);
			}
			if(c_move == 'u' || c_move == 'U'){
				cord=move('u' ,cord);
			}

			if(c_move == 'E' || c_move == 'e'){
				writeToFile();
			}
			if(c_move == 'T' || c_move == 't'){
				print_report(total_moves);
			}
			cout << board;// print with operator


			bool  solution_control=board.isSolved();
			if(solution_control==true){
				print();
				cout << "You win!!"<< "  ";
				print_report(total_moves);
				break; 
			}
			/*if(c_move == 'v' || c_move == 'V'){
				cord=solvePuzzle(cord);
			}

			

			
			
			}*/

			
		}
}

void NPuzzle::Board::print(){
	int define_puzzle=0;  // this variable assign that this puzzle read to file puzzle or hw1 puzzle
	for(int i=0 ;i < arr.size() ; i++){
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


void NPuzzle::readfromfile(string load_name){
	board.readfromfile(load_name);

}

int main(int argc, char  *argv[])
{
	srand(time(NULL));
	NPuzzle p;
	if(argc==2){
	string load_name=argv[1];

	p.readfromfile(load_name);
	p.gameplay();
}

if(argc==1){
		int size;
		cout << "Please enter the problem size " << endl;
		cin >> size ;

		p.setsize(size);		
		p.gameplay();
	}
	


	return 0;
}




#include <stdio.h>
#include <stdlib.h>


#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n'&& *ch_iter!=13) {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}
int stringcompare(char str1[], char str2[]) 
{
    int i=0, j=0;
    while(str1[i] != '\0' && str2[i] != '\0') 
    {
        
        if(str1[i] != str2[i]) 
        {
            j = 1;
            break;
        }
        i++;
    }

    if(j == 0 && str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}

	void printfpuzzle(char puzzle[DICT_SIZE][DICT_SIZE],char *dict[DICT_SIZE],int coord[DICT_SIZE][4]){
		int sayac,i,j,k,satir,sutun;
	char randomcharecter;
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			puzzle[i][j]=0;
		}
	}
	k=0;

	

for(sayac=0;sayac<DICT_SIZE;sayac++){
	if(coord[sayac][1]==coord[sayac][3]){
		k=0;
		if(coord[sayac][0]<coord[sayac][2]){
		for(satir=coord[sayac][0];satir<=coord[sayac][2];satir++){
			sutun=coord[sayac][1];
			puzzle[satir][sutun]=dict[sayac][k];
			k++;
			}
		}
		else{
			for(satir=coord[sayac][0];satir>=coord[sayac][2];satir=satir-1){
			sutun=coord[sayac][1];
			puzzle[satir][sutun]=dict[sayac][k];
			k++;
			}
		}	
	}

else if(coord[sayac][0]==coord[sayac][2]){
	k=0;
	if(coord[sayac][1]<coord[sayac][3]){
	for(sutun=coord[sayac][1];sutun<=coord[sayac][3];sutun++){
	satir=coord[sayac][0];
	puzzle[satir][sutun]=dict[sayac][k];
	k++;
		}
	}
	else{
		for(sutun=coord[sayac][1];sutun>=coord[sayac][3];sutun=sutun-1){
		satir=coord[sayac][0];
	puzzle[satir][sutun]=dict[sayac][k];
	k++;
		}

	}
}
else{
	k=0;
	if(coord[sayac][0]<coord[sayac][2]){
	sutun=coord[sayac][1];
	for(satir=coord[sayac][0];satir<=coord[sayac][2];satir++){
		
		puzzle[satir][sutun]=dict[sayac][k];
		k++;
		sutun++;
		
				}
		}
	if(coord[sayac][0]>coord[sayac][2]){
		sutun=coord[sayac][1];
	for(satir=coord[sayac][0];satir>=coord[sayac][2];satir=satir-1){
		puzzle[satir][sutun]=dict[sayac][k];
		k++;
		sutun=sutun-1;
		
				}
		}

	}

}


for(i=0;i<DICT_SIZE;i++){
	for(j=0;j<DICT_SIZE;j++){
		if(puzzle[i][j]==0)
				puzzle[i][j]=randomcharecter = 'a' + (rand() % 26);
		}
	}

for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			printf("%c ",puzzle[i][j]);
			}
		printf("\n");
		
	}
}

int string_length(char s[]) {
   int c = 0;
 
   while (s[c] != '\0')
      c++;
 
   return c;
}
int main(){
	int sayac,i,j,k,satir,sutun;
	char randomcharecter;
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	print_dictionary(dict);
	printf("Cordinatlar:\n");
	print_coord(coord);
	printf("\n\n");
	
	// WRITE HERE...
	


	char puzzle[DICT_SIZE][DICT_SIZE];

	printfpuzzle(puzzle,dict,coord);

	char word[10];
	int row,column,mark,compare,compare2,lengthofword;
	int diff='a'-'A';
	int allcounter=0,foundcounter;
	while(allcounter!=15){
	printf("Please enter row:");
	scanf("%d",&row);
	printf("Please enter column:");
	scanf("%d",&column);
	printf("Please enter word(write 'exit game'for exit):");
	scanf(" %[^\n]",word);
	int exitcompare,wincounter=0;
	char exit[15]="exit game";
	
	exitcompare=stringcompare(exit,word);
	if(exitcompare==1){
		return 0;
			}
	else{
	lengthofword=string_length(word);
	char dest[lengthofword];
	
	for(i=0;i<DICT_SIZE;i++){
		for (k = 0; k < string_length(dict[i]); k++)
        {
            if ( dict[i][k] == '\n' || dict[i][k] == '\r' )
                dict[i][k] = '\0';
        }
		compare=stringcompare(dict[i],word);
		if(compare==1){
			
			mark=i;
			copy_string(dict[i],dest);
		}	
	}
	
	int destination_compare=stringcompare(dest,word);
	
	
	if((row==coord[mark][0] && column==coord[mark][1]) ||(row==coord[mark][2] && column==coord[mark][3])){
		


		
		i=0;
		foundcounter=0;
		for(sutun=column;sutun<column+lengthofword;sutun++){
			if(puzzle[row][sutun]==dest[i]){
				foundcounter++;
			}
			i++;
		}
		
	if(foundcounter==lengthofword){
		allcounter++;
			
			for(sutun=column;sutun<column+lengthofword;sutun++){
				puzzle[row][sutun]=puzzle[row][sutun]-32;
				}
			}
			
			i=0;
		foundcounter=0;
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
			if(puzzle[row][sutun]==dest[i]){
				foundcounter++;
			}
			i++;
		}
		
	if(foundcounter==lengthofword){
		allcounter++;
			
			for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
				puzzle[row][sutun]=puzzle[row][sutun]-32;
				}
			}

		
		i=0;
		foundcounter=0;
		for(satir=row;satir<row+lengthofword;satir++){
				if(puzzle[satir][column]==dest[i]|| puzzle[satir][column]==(dest[i]-32)){
					foundcounter++;
				}
			i++;
		}
	if(foundcounter==lengthofword){
		allcounter++;
			for(satir=row;satir<row+lengthofword;satir++){
				if(puzzle[satir][column]>='a' && puzzle[satir][column]<='z'){
					puzzle[satir][column]=puzzle[satir][column]-diff;
				}
			}
		}

		
		i=lengthofword-1;
		foundcounter=0;
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
			if(puzzle[row][sutun]==dest[i]){
				foundcounter++;
			}
			i=i-1;
		}
	if(foundcounter==lengthofword){	
		allcounter++;
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
				puzzle[row][sutun]=puzzle[row][sutun]-diff;
			
			}
		}
		
		foundcounter=0;
		i=lengthofword-1;
		for(satir=row;satir>row-lengthofword;satir=satir-1){
			if(puzzle[satir][column]==dest[i] || puzzle[satir][column]==(dest[i]-32)){
				foundcounter++;
			}
			i=i-1;
		}
	if(foundcounter==lengthofword){
		allcounter++;
		for(satir=row;satir>row-lengthofword;satir=satir-1){
			if(puzzle[satir][column]>='a' && puzzle[satir][column]<='z'){
				puzzle[satir][column]=puzzle[satir][column]-diff;		
					}
				}
			}
		
		foundcounter=0;
		i=0;
		for(satir=row;satir>row-lengthofword;satir=satir-1){
			if(puzzle[satir][column]==dest[i]){
				foundcounter++;
			}
			i++;
		}
	if(foundcounter==lengthofword){
		allcounter++;
		for(satir=row;satir>row-lengthofword;satir=satir-1){
				puzzle[satir][column]=puzzle[satir][column]-diff;		
			}
		}
		
		foundcounter=0;
		i=lengthofword-1;
		for(satir=row;satir<row+lengthofword;satir++){
			if(puzzle[satir][column]==dest[i]){
				foundcounter++;
			}
			i=i-1;
		}
	if(foundcounter==lengthofword){
		allcounter++;
		for(satir=row;satir<row+lengthofword;satir++){
				puzzle[satir][column]=puzzle[satir][column]-diff;		
			}
		}

		
		
		foundcounter=0;
		i=0;
		satir=row;
		for(sutun=column;sutun<column+lengthofword;sutun++){
			if(puzzle[satir][sutun]==dest[i] || puzzle[satir][sutun]==(dest[i]-32)){
				foundcounter++;		
				}
			i++;
			satir++;
		}
		
	if(foundcounter==lengthofword){
		satir=row;
		
		allcounter++;
			for(sutun=column;sutun<column+lengthofword;sutun++){
				if(puzzle[satir][sutun]>='a' && puzzle[satir][sutun]<='z'){
				puzzle[satir][sutun]=puzzle[satir][sutun]-diff;
			}
				satir++;		
				}
		}
		
		foundcounter=0;
		i=lengthofword-1;
		satir=row;
	
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
			if(puzzle[satir][sutun]==dest[i] || puzzle[satir][sutun]==(dest[i]-32)){
				foundcounter++;
				}
			satir=satir-1;
			i=i-1;
		}

		satir=row;
	if(foundcounter==lengthofword){
		allcounter++;
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
			if(puzzle[satir][sutun]>='a' && puzzle[satir][sutun]<='z'){
				puzzle[satir][sutun]=puzzle[satir][sutun]-diff;
			}
					satir=satir-1;
				
			}
		}
	
		
		foundcounter=0;
		i=0;
		satir=row;
		for(sutun=column;sutun<column+lengthofword;sutun++){
			if(puzzle[satir][sutun]==dest[i]){
				foundcounter++;			
				}
			i++;
			satir=satir-1;
		}

		satir=row;
	if(foundcounter==lengthofword){
		allcounter++;
		for(sutun=column;sutun<column+lengthofword;sutun++){	
				puzzle[satir][sutun]=puzzle[satir][sutun]-diff;
			satir=satir-1;
		}
	}
		
		foundcounter=0;
		i=lengthofword-1;
		satir=row;
	
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
			if(puzzle[satir][sutun]==dest[i]){
				foundcounter++;
			}
			satir=satir+1;
			i=i-1;
		}
		satir=row;
	if(foundcounter==lengthofword){
		allcounter++;
		for(sutun=column;sutun>column-lengthofword;sutun=sutun-1){
				puzzle[satir][sutun]=puzzle[satir][sutun]-diff;
			satir=satir+1;
		}
	}
		
	}
		else{
			printf("\n\nThe word or coordinate you entered is incorrect. Please try again.\n");
		}



for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			printf("%c ",puzzle[i][j]);
				}
		printf("\n");	
		}
	}
}

if(allcounter==15)
	printf("You win!!\n");

		
	return 0;
}

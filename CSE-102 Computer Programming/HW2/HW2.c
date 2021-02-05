#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#define T 10
int make_a_guess(int trial , int min , int max);
void show_scores(int score_human , int score_program);
void draw_hourglass(int height);
void draw_mountain_road(int length , int max_radius);
void menu();

int main(){

	srand(time(NULL));
	menu();

	return 0;
}

void draw_hourglass(int height){
	int i,j,k,star,space;
	star=height;
	space=0;
 
 		if(height % 2 != 0){
		for(i=0;i<height;i++){
			for(j=1;j<=star;j++){
			printf("*");

			}
			if(i<(height/2)){
			star=star-2;
			space=space+1;
			}
			else{
			star=star+2;
			space=space-1;
			}
		printf("\n");
			for(k=0;k<space;k++){
			printf(" ");
			}
		}

	}
	else if (height % 2 ==0 || height<0){
		printf("You entered wrong type value.\nPlease enter a positive odd number:");
		scanf("%d",&height);
		printf("\n");
		draw_hourglass(height);

	}

}

void draw_mountain_road(int length , int max_radius){
	int counter,i,k,j,space,slash,r;

	for(counter=1;counter<=length;counter++){
		r= 1+rand()% max_radius;

 	if(counter % 2 !=0){
 		if(counter==1)
 			space=max_radius;

	for(i=1;i<2*r+1;i++){
		if(i<=r){
		for(k=1;k<=space;k++)
			printf(" ");

			printf("/");
			space=space-1;
	}

		if(i==r+1){
			for(k=1;k<=space;k++)
				printf(" ");
			printf("|%d\n",r);
			space=space+1;
		}

		if(i>r){
			
			for(k=1;k<=space;k++)
			printf(" ");
		
		
			printf("\\");
			space=space+1;
		}

		printf("\n");

 }
 
}
 if(counter % 2 ==0){	
  	
	for(i=1;i<2*r+1;i++){
		if (i<=r){
		for(k=1;k<=space;k++)
			printf(" ");

		printf("\\");
		space=space+1;
	}

	if(i==r+1){
		for(k=1;k<=space;k++)
			printf(" ");

		printf("|%d\n",r);
		space=space-1;
	}

	if(i>r){
		for(k=1;k<=space;k++)
			printf(" ");

			printf("/");
			space=space-1;
	}

	printf("\n");
 }

	}	
	
 }
 	}
int make_a_guess(int trial , int min , int max){
	int gn;
	printf("(Trial: %d)Make a guess between %d and %d:",trial,min , max);
	scanf("%d",&gn);
	return gn;
	
		}
void show_scores(int score_human , int score_program){
	printf("Your Score : %d Program Score : %d\n",score_human,score_program );
}
		
void menu(){
	int gn,i,length,max_radius,choice,height;
	int score_human=0,score_program=0;
	int distance,trial,ln,min,max;

	while(choice!=4){
		printf("****Menu****\n\n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\n");
		printf("Choice:");
		scanf("%d",&choice);

	switch(choice){
	 case 1:
	 	min=1,max=1024;
		trial=1;
	 	ln = 1 + rand() % 1024;
	 

	for( i=1;i<=T;i++){
		gn=make_a_guess(trial,min,max);

		distance=fabs(gn-ln);

		trial=trial+1;		

		if(gn<ln)
			min=gn;
	 	else if(gn>ln)
			max=gn;

		if(distance>=512 && distance<=1023)
			printf("Distance : 10\n");
		else if(distance>=256 && distance<=511)
			printf("Distance : 9\n");
		else if(distance>=128 && distance<=255)
			printf("Distance : 8\n");
		else if(distance>=64 && distance<=127)
			printf("Distance : 7\n");
		else if(distance>=32 && distance<=63)
			printf("Distance : 6\n");
		else if(distance>=16 && distance<=31)
			printf("Distance : 5\n");
		else if(distance>=8 && distance<=15)
			printf("Distance : 4\n");
		else if(distance>=4 && distance<=7)
			printf("Distance : 3\n");
		else if(distance>=2 && distance<=3)
			printf("Distance : 2\n");
		else if(distance==1)
			printf("Distance : 1\n");
		else if(distance==0){
			printf("Disctance : 0. You win!\n");
			score_human=score_human+1;
			show_scores(score_human,score_program);
				break;

		}
				if(i==T){
				printf("You lost\n");
				score_program=score_program+1;
				show_scores(score_human,score_program);
			}

	}

		break;

		case 2:	
	   		printf("Please enter a  height:");
	   		scanf("%d",&height);
	   		printf("\n");
	  		draw_hourglass(height);
	  		printf("\n");

			break;
		case 3:
			printf("Enter length:");
			scanf("%d",&length);
			printf("Enter max radius:");
			scanf("%d",&max_radius);
			draw_mountain_road(length,max_radius);
		

	}
}
}
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define PI 3
#define red 0
#define yellow 1
#define blue 2
#define black 3
#define white 4

double CreateBody(int shape){
	if(shape==1){
		double size;
		int edge;

		printf("Please enter  edge length for the Square Pokemon:\n");
		scanf("%d",&edge);

		size=edge*edge;

		return size;

	}
	if(shape==2){

		double size;
		int edge,edge2;

		printf("Please enter two edge length for the Rectengular Pokemon:\n");
		scanf("%d %d",&edge,&edge2);

		size=edge*edge2;

		return size;


	}
	if(shape==3){
		double size;
		double radius;

		printf("Please enter a  number for the radius:");
		scanf("%lf",&radius);

		size=(PI)*(radius)*(radius);

		return size;
	}
}


int SetColor(int color){

		if(color % 5 == 1 || color>=1000)
				return 1;
		if(color % 5  == 0)
				return 0;
		if(color % 5 == 2)
				return 2;
		if(color % 5 == 3)
				return 3;
		if(color % 5 == 4)
				return 4;

}

double LoadMoves(int shape,double body_size){
	if(shape==1){
		double move;
		int edge;

		edge=sqrt(body_size);
		move=(body_size/edge)*4;

		return move;

	}
	if(shape==2){
		double move;

		move=((body_size/5)*2)+10;

		return move;

	}
	if(shape==3){
		double radius;
		double move;

		radius=sqrt(body_size / PI);
		move=2*PI*radius;

		return move;
	}
}

int SetAtackPower(int lower_bound, int upper_bound){
	int attackpower;
	
	srand(time(NULL));
	attackpower= lower_bound  + rand() % upper_bound;

	return attackpower;
}

void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){
	int i,j,edge;
	if(shape==1){
	 	edge=sqrt(body_size);
	  	for(i=1;i<=edge;i++){
	 	 	for(j=0;j<edge;j++){

	 		printf("X");
	 	  }
	 	  printf("\n");
	   }

	   printf("Name: Square Pokemon\n");
	   printf("Size: %.2f\n",body_size);

	   if(color==red)
	   printf("Color:Red\n");
		if(color==yellow)
			printf("Color:Yellow\n");
		if(color==blue)
			printf("Color:Blue\n");
		if(color==black)
			printf("Color:Black\n");
		if(color==white)
			printf("Color:White\n");


	   printf("Move:%.2f\n",move_length);
	   printf("Attack Power:%d\n",attack_power);

	}

	if(shape==2){
		edge=body_size/5;
		for(i=1;i<=5;i++){
			for(j=0;j<edge;j++){
				printf("X");
			}
			printf("\n");
		}

		printf("Name: Rectangular Pokemon\n");
		printf("Size: %.2f\n",body_size);

		if(color==red)
	   printf("Color:Red\n");
		if(color==yellow)
			printf("Color:Yellow\n");
		if(color==blue)
			printf("Color:Blue\n");
		if(color==black)
			printf("Color:Black\n");
		if(color==white)
			printf("Color:White\n");

	    printf("Move:%.2f\n",move_length);
	    printf("Attack Power:%d\n",attack_power);
	}
	if(shape==3){
		printf("Name: Circular  Pokemon\n");
		printf("Size: %.2f\n",body_size);
		if(color==red)
	   printf("Color:Red\n");
		if(color==yellow)
			printf("Color:Yellow\n");
		if(color==blue)
			printf("Color:Blue\n");
		if(color==black)
			printf("Color:Black\n");
		if(color==white)
			printf("Color:White\n");

	    printf("Move:%.2f\n",move_length);
	    printf("Attack Power:%d\n",attack_power);
	}

}

int main(){
	int shape, color, attack_power;
	double size_of_body, move_length;
	shape=CIRCULAR;
	size_of_body = CreateBody(shape);
	color=798;
	color=SetColor(color);
	move_length = LoadMoves(shape,size_of_body);
	attack_power=SetAtackPower (0, 150);
	ShowPokemon(shape,size_of_body,color, move_length,attack_power);

	return 0;
}

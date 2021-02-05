#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

void menu();
void draw_triangle(int height);
int take_grades(int grades_array[]);
int take_exam_grades(int exam_array[2]);
double calculate_homework(int grades_array[]);
double calculate_lab(int grades_array[]);
double calculate_all(int hw_avarage,int exam_array[],int lab_avarage);
int add(int number1 ,int number2);
int sub(int number1 ,int  number2);
int multi(int number1 ,int number2);
int divi(int number1 ,int number2);
int power(int number1 ,int number2);
int modulo(int number1 ,int number2);
int doit(int function(int firstt , int secondd),int first_number, int second_number);
int menuforoperate();



int main(){

	menu();

	return 0;
}
int add(int number1 ,int number2){
	int addition=number1  + number2;

	return addition;
}
int sub(int number1 ,int  number2){
	int substriction;
	substriction=number1 - number2;

	return substriction;
}
int multi(int number1 ,int number2){
	int multiplication;
	multiplication=number1*number2;
	return multiplication;
}
int divi(int number1 ,int number2){
	int division;
	division=number1/number2;
	return division;
}
int power(int number1 ,int number2){

	int powerr;
	powerr=pow(number1,number2);
	return powerr;

}
int modulo(int number1 ,int number2){
	int modd;
	modd= number1 % number2;
	return modd;

}

int doit(int function(int firstt , int secondd),int first_number, int second_number){

	function(first_number,second_number);

}


int menuforoperate(){

	int result,first_number,second_number;
		char operator;
		result=0;
		while(operator!='x'){
		scanf(" %c",&operator);
		scanf("%d%d",&first_number,&second_number);
		
	switch(operator){

		case '+':{


		result=doit(add,first_number,second_number);
		printf("%d\n",result);
		
		break;
}
	case '-':{

		result=doit(sub,first_number,second_number);
		printf("%d\n",result);
		break;
}
	case '*':{

		result=doit(multi,first_number,second_number);
		printf("%d\n",result);
		break;
}
	case '/':{

		result=doit(divi,first_number,second_number);
		printf("%d\n",result);
		break;
}
case '^':{

		result=result=doit(power,first_number,second_number);
		printf("%d\n",result);
		break;
}

case '%':{

		result=doit(modulo,first_number,second_number);
		printf("%d\n",result);
		break;
}

	

	}



}
}

void draw_triangle(int height){

	int k,j,star,space,i;

	space=height-1;
	star=2;
	for(i=1;i<=height;i++){

		for(k=1;k<=space;k++){
			printf(" ");
		}

		for(j=1;j<=star;j++){
			if(j==1)
			printf("/");
			else if(j==star)
				printf("\\");
			else
				printf("*");
		}

		star=star+2;
		space=space-1;
		printf("\n");
	}

	space=space+1;
	star=star-2;

	for(i=1;i<=height;i++){

		for(k=1;k<=space;k++){
			printf(" ");
		}

		for(j=1;j<=star;j++){
			if(j==1)
			printf("\\");
			else if(j==star)
				printf("/");
			else
				printf("*");
		}

		star=star-2;
		space=space+1;
		printf("\n");
	}

}

int take_grades(int grades_array[]){

	int i,grades;



	for(i=0;i<10;i++){
		scanf("%d",&grades);
		grades_array[i]=grades;
	}


}
int take_exam_grades(int exam_array[2]){

		int i;
		double grades;
		for(i=0;i<2;i++){

			scanf("%lf",&grades);
			exam_array[i]=grades;

		}

	}

	double calculate_homework(int grades_array[]){
		int i;
		double avarage,total;

		take_grades(grades_array);


		total=0;
		for(i=0;i<10;i++){

			total=total+grades_array[i];
		}

		avarage=total/10;

		return avarage;



	}
	double calculate_lab(int grades_array[]){
		int i,lab11,lab12;
		double avarage,total;


		scanf("%d %d ",&lab11,&lab12);

		take_grades(grades_array);

		


		total=0;
		for(i=0;i<12;i++){

			grades_array[10]=lab11;
			grades_array[11]=lab12;

			total=total+grades_array[i];
		}
		avarage=total/12;

		return avarage;

}

	double calculate_all(int hw_avarage,int exam_array[],int lab_avarage){
		double weigthed_avarage;
		take_exam_grades(exam_array);

		weigthed_avarage=(exam_array[0]*30)/100 + (exam_array[1]*40)/100
		 + (hw_avarage*10)/100 + (lab_avarage*20)/100;

		 return weigthed_avarage;

	}

void menu(){
	int choice,height;
	 int i,lab_grades[12];
	int hw_grades[10];
	int exam_array[2];
	double lab_avarage,hw_avarage;


	while(choice!=4){
		printf("****Menu****\n\n");
		printf("1.Calculater\n");
		printf("2.Overall Avarage Calculate\n");
		printf("3. Draw Diamond\n");
		printf("4. Exit\n");
		printf("Choice:");
		scanf("%d",&choice);

		switch(choice){
	 case 1:
	 	printf("\n\nAddition= + \n");
	 	printf("Substriction= - \n");
	 	printf("Multiplication= * \n");
	 	printf("Division= / \n");
	 	printf("Take mod= %% \n");
	 	printf("Power of number= ^ \n\n\n");

	 	menuforoperate();
	 	break;
	 case 2:
		printf("Please Enter Homework Grades:");
		hw_avarage=calculate_homework(hw_grades);
		printf("Please Enter Lab Grades:");
		lab_avarage=calculate_lab(lab_grades);
		printf("Please Enter Midtern And Final Exam Grades:\n");
		printf("Your Overall Avarage:%.2f\n",calculate_all(hw_avarage,exam_array,lab_avarage));
		break;
	 case 3:

	printf("Please enter height:\n");
	scanf("%d",&height);
	draw_triangle(height);
	 break;



  		}
	}	
}

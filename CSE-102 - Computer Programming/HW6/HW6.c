#include <stdio.h>
#include <string.h>


int part5findcapital(char *string){
	if(string[0]>='A' && string[0]<='Z')
		return string[0];
	else
		return part5findcapital(string+1);
}

int powertake(int base,int exponent){
	if(exponent==1)
		return base;
	if(exponent==0)
		return 1;
	else
		return base*powertake(base,exponent-1);
}

int part4find(int number,int lengthofnumber){
	int result=0;	
	if(number<1)
		return result;
	else{
		result=powertake(number%10,lengthofnumber);
		return result+part4find((number/10),lengthofnumber);
	}	
}


int get_int_len(int value){
  	int l=1;
  	while(value>9){
  		l++;
  		value/=10; 
 	 	}
  	return l;
}


int part3_find(int input){
	printf("%d ",input);
	if(input<=1)
		return 0;
	else{
		if(input % 2 == 0){
			input=input/2;
			return part3_find(input);
		}
		if(input % 2 == 1){
			input=(3*input)+1;
			return part3_find(input);
		}

	}

}
int part2_find(int array[],int lengthofarray){
	lengthofarray=lengthofarray/2;
}

int common(int number1,int number2){
	int temp;
  	if(number1==0 || number2==0)
  		return 0;
	if(number1 % number2 == 0)
		return number2;
	else
		temp=number1%number2;
	 	return common(number2,temp);
}

void menu(){
	int choice;
	while(choice!=6){
		int number1,number2;
		int number,lengthofnumber,output;
		int length;
		char string[length];
		printf("\n****Menu****\n\n");
		printf("1.FİND GCD\n");
		printf("2.MERGE SORT\n");
		printf("3.CALCULATE BY FORMULA\n");
		printf("4.EQUAL OR NOT EQUAL\n");
		printf("5.FİND BİG LETTER\n");
		printf("6.EXİT\n");
		printf("Choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				
				printf("Enter two number:");
				scanf("%d",&number1);
				scanf("%d",&number2);
				printf("\n\nResult:%d\n\n",common(number1,number2));
			break;
			case 2:
				
			break;
			case 3:
				
				printf("Enter a number:");
				scanf("%d",&number);
				part3_find(number);
			break;
			case 4:
				
				printf("Enter number:");
				scanf("%d",&number);
				lengthofnumber=get_int_len(number);
				output=part4find(number,lengthofnumber);	
				if(output==number)
					printf("Equal\n");
				else
					printf("Not equal\n");
					
			break;
			case 5:
				
				printf("Enter a word:");
				scanf("%s",string);
				length=strlen(string);
				printf("%c\n",part5findcapital(string));
			break;
		}
	}
}
int main(){

	menu();
	
	return 0;
}
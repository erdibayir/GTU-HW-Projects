#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

struct person{
	char name[SIZE];
	char surname[SIZE];
	char musical_work[SIZE];
	int age; 
	int data;	
	struct person *next;
} *top;



void print_stack(){
	int i=1;
	if(top==NULL){
		printf("Stack içinde eleman bulunamadı\n");
	}
	else{
	struct person  *iter;
	iter=top;
	while(iter!=NULL){
		printf("%d)",i);
		printf("%s\n",iter->name);
		printf(" %s\n",iter->surname);
		printf(" %s\n",iter->musical_work);
		printf(" %d\n",iter->age);

		iter=iter->next;
		i++;
		}
	}
}
void  addNode(char name[], char surname [], char creation [], int age){


	if(top==NULL){
		top=malloc(sizeof(struct person));
		strcpy(top->name,name);
		strcpy(top->surname,surname);
		strcpy(top->musical_work,creation);
		top->age=age;
		top->next=NULL;

	}
	else{
	struct person *temp;
	temp=malloc(sizeof(struct person));
	strcpy(temp->name,name);
	strcpy(temp->surname,surname);
	strcpy(temp->musical_work,creation);
	temp->age=age;
	temp->next=top;
	top=temp;
}
	



}
void swap_node(struct person *iter1,struct person *iter2){




	int age_temp;
	char name_temp[SIZE];
	char surname_temp[SIZE];
	char creation_temp[SIZE];

				age_temp=iter1->age;
				iter1->age=iter2->age;
				iter2->age=age_temp;

				strcpy(name_temp,iter1->name);
				strcpy(iter1->name,iter2->name);
				strcpy(iter2->name,name_temp);

				strcpy(surname_temp,iter1->surname);
				strcpy(iter1->surname,iter2->surname);
				strcpy(iter2->surname,surname_temp);


				strcpy(creation_temp,iter1->musical_work);
				strcpy(iter1->musical_work,iter2->musical_work);
				strcpy(iter2->musical_work,creation_temp);
	
}
void deleteNode(){
	if(top==NULL){
		printf("Stack içinde  eleman yoktur.Silme islemi yapamazsın\n");	
	}

	else{
		struct person  *temp;
		temp=top;
		top=top->next;
		free(temp);
	}

}
void Sort_Alphabetically(){

	struct person *iter1;
	struct person *iter2;

	int i=0;

	for(iter1=top;iter1!=NULL;iter1=iter1->next){
		for(iter2=iter1->next;iter2!=NULL;iter2=iter2->next){

			while(iter1->name[i] == iter2->name[i]){
				i++;
			}
			
			if(iter2->name[i] < iter1->name[i]){
					swap_node(iter1,iter2);
			}
		}
	}
}

void Sort_Increasingly(){
	struct person *iter1;
	struct person *iter2;

	for(iter1=top;iter1!=NULL;iter1=iter1->next){
		for(iter2=iter1->next;iter2!=NULL;iter2=iter2->next){
			if(iter2->age < iter1->age)
					swap_node(iter1,iter2);
		}
	}
}


void menu(){
	char name[SIZE],surname[SIZE],creation[SIZE];
	int choice=-2,age;

	while(choice!=5){
	printf("\n\n****MENU****\n\n");
	printf("1- Add a Person to the Stack\n");
	printf("2- Pop a Person from the Stack\n");
	printf("3- Sort Alphabetical Order\n");
	printf("4- Sort Age in Increasing Order\n");
	printf("5- Exit menu\n");
	printf("\n*************\n\n");
	scanf("%d",&choice);

	switch(choice){

		case 1:
		printf("Name:");
		scanf(" %[^\n]s",name);
		printf("Surname:");
		scanf(" %[^\n]s",surname);
		printf("Creation:");
		scanf(" %[^\n]s",creation);
		printf("Age:");
		scanf(" %d",&age);
		printf("\n\n");
		addNode(name,surname,creation,age);
		printf("%s\n",top->name );
		print_stack();

		break;
		case 2:
		deleteNode();
		print_stack();
		break;
		case 3:
		Sort_Alphabetically();
		print_stack();
		break;
		case 4:
		Sort_Increasingly();
		print_stack();
		break;
		case 5:
		printf("Exit....\n");
		break;


	}
}

}

int main(){
	
	top=NULL;
	menu();

	return 0;
}
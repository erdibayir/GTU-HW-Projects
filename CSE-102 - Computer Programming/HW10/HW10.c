#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef struct stack{
	int data;
	struct stack *next;

}stack;


typedef struct queue{
	int data;
	struct queue *next;

}queue;

struct queue *front=NULL;
struct queue *rear=NULL;
typedef queue queue;
	
typedef struct bst{

	int data;
	struct bst *right;
	struct bst *left;
}bst;





 stack *stack_add_node( stack *stack_, int add_data){


	if(stack_==NULL){

		stack_=malloc(sizeof( stack));
		stack_->data=add_data;
		stack_->next=NULL;
		return stack_;

	}
	else{
	 stack  *temp;
	temp=malloc(sizeof( stack ));
	temp->data=add_data;
	temp->next=stack_;
	stack_=temp;
	return stack_;
	}
	
}

 queue * enqueue( queue *queue_,int value){
 	
	if(queue_==NULL){
		
		queue_=malloc(sizeof( queue));
		queue_->data=value;
		queue_->next=NULL;
		front=rear=queue_;
		
		return queue_;
	}


	else{
	
		
		queue *temp;
		temp=malloc(sizeof( queue));
		temp->data=value;
		temp->next=NULL;
		rear->next=temp;
		rear=temp;
		return queue_;

	}


}

 bst * bst_node_ekle( bst *bst_,int value){
	if(bst_== NULL ){
		bst_=malloc(sizeof( bst));
		bst_ ->data=value;
		bst_->right=NULL;
		bst_->left=NULL;
		return bst_;
	}
	else if(bst_->data < value){
		 bst *temp=bst_;
		temp->right=bst_node_ekle(temp->right,value);
		return bst_;
	}
	else{
		 bst *temp=bst_;
		temp->left=bst_node_ekle(temp->left,value);
		return bst_;

	}

	
}


void fill_structures( stack  **stack_ ,  queue **queue_, bst **bst_, int data[20]){
	int i;
	double total_time;
	clock_t start,end;

	printf("-----------------\n");
	printf("FİLL STRUCTURES\n-----------------\n");

	printf("Structures\t\tStack\t\tQueue\t\tBST\n");
	printf("Filling Tİme\t\t");

	start=clock();
	for(i=0;i<SIZE;i++){
		(*stack_)=stack_add_node((*stack_),data[i]);
	}
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC*1000;
	printf("%.3f\t\t",total_time);


	start=clock();
	for(i=0;i<SIZE;i++){
		(*queue_)=enqueue((*queue_),data[i]);
	}
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC*1000;
	printf("%.3f\t\t",total_time);

	start=clock();
	for(i=0;i<SIZE;i++){
		(*bst_)=bst_node_ekle((*bst_),data[i]);
	}
	end=clock();
	total_time=(double)(end-start)/CLOCKS_PER_SEC*1000;
	printf("%.3f\t\t",total_time);
	printf("\n\n");
}
void print_stack( stack *stack_){
	int i=1;
	 stack  *iter;
	iter=stack_;
	while(iter!=NULL){
		printf("%d  ",iter->data);
		iter=iter->next;
		i++;
		}

}
void print_stack_reverse(stack *stack_){
	int i=0,j,k;

	stack *iter=stack_;
	while(iter!=NULL){
		i++;
		iter=iter->next;
	}
	iter=stack_;
for(j=i;j>0;j=j-1){
	iter=stack_;
	for(k=0;k<j-1;k++){
		iter=iter->next;
		}
		printf("%d  ",iter->data);
	}
}



void swap_stack_node( stack *iter1, stack *iter2){
	int data_temp;
	data_temp=iter1->data;
	iter1->data=iter2->data;
	iter2->data=data_temp;
	
}
void order_stack( stack *stack_){
	 stack *iter1;
	 stack *iter2;

	int i=0;

	for(iter1=stack_;iter1!=NULL;iter1=iter1->next){
		for(iter2=iter1->next;iter2!=NULL;iter2=iter2->next){
			
			if(iter2->data > iter1->data){
					swap_stack_node(iter1,iter2);
			}
		}
	}
}

void print_queue( queue *queue_){
	
	 queue *temp;
	temp=queue_;
	
			
	while(temp!=NULL){
			
			printf("%d  ",temp->data);
			temp=temp->next;
			
		}
		
	}
void swap_queue_node( queue *iter1, queue *iter2){
	int data_temp;
	data_temp=iter1->data;
	iter1->data=iter2->data;
	iter2->data=data_temp;
}

void order_queue( queue *queue_){
	 queue *iter1;
	 queue *iter2;

	int i=0;

	for(iter1=queue_;iter1!=NULL;iter1=iter1->next){
		for(iter2=iter1->next;iter2!=NULL;iter2=iter2->next){
			
			if(iter2->data > iter1->data){
					swap_queue_node(iter1,iter2);
			}
		}
	}
}

void print_bst( bst *bst_){
	if(bst_!=NULL){
	 bst *temp=bst_;
	print_bst(temp->right);
	printf("%d  ",temp->data);
	print_bst(temp->left);
		}
	
	 }

int search_bst( bst *bst_, int val_to_search){
	
	/*
	Searching of bst is different because we can't change 
		   order of value in bst so this searching started root and find depth of value 
		  */
	int res_count=0,step=1;
	bst *iter=bst_;
	while(iter!=NULL){

		if(iter->data==val_to_search){
			printf("1 result founded on %d. depth of tree\n",step);
			iter=iter->left;
			step++;

		}
		else if(iter->data < val_to_search){
			iter=iter->right;
			step++;
		}
		
	else 	if(iter->data > val_to_search){
			iter=iter ->left;
			step++;
		}




	}
	
}
void search_stack( stack *stack_, int val_to_search){
	int res_count=0,step=1,founded;

	if(stack_==NULL){
		printf("Not Found \n");
	}
	else{

		 stack *iter=stack_;
		 printf("FOR STACK\n");
		while(iter!=NULL){
			if(iter->data==val_to_search){
				res_count=1;
				founded=step;
				printf("%d result founded on %d. step\n",res_count,founded);

			}
			step++;
			iter=iter->next;
		}
		if(res_count==0)
			printf("Not founded\n");
		
	}
}
void search_queue( queue *queue_, int val_to_search){
	int res_count=0,step=1,founded;

	if(queue_==NULL){
		printf("Not Found \n");
	}
	else{

		 queue *iter=queue_;
		 printf("FOR QUEUE\n");
		while(iter!=NULL){
			if(iter->data==val_to_search){
				res_count=1;
				founded=step;
				printf("%d result founded on %d. step\n",res_count,founded);

			}
			step++;
			iter=iter->next;
		}
		
	}
}

stack *search_for_pop(stack *stack_,int value){
	if(stack_==NULL){
		printf("Not Found \n");
		return NULL;
	}
	else{
		 stack *iter=stack_;
		 if(iter->data==value){
			iter=iter->next;
			return iter;
		 }
		 else{
		while(iter->next->data!=value){
				iter=iter->next;
		}
		stack *temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
		return stack_;
	}

	
	}

}

int find_max_stack(stack *stack_){
	stack *iter=stack_;
	int max=iter->data;
	while(iter!=NULL){
		if(max<iter->data){
			max=iter->data;
		}
			iter=iter->next;
	}

	return max;
}
int find_min_stack(stack *stack_){

	stack *iter=stack_;
	int min=iter->data;
	while(iter!=NULL){
		if(min>iter->data){
			min=iter->data;
		}
			iter=iter->next;
	}

	return min;

}



int find_max_queue(queue *queue_){
	queue *iter=queue_;
	int max=iter->data;
	while(iter!=NULL){
		if(max<iter->data){
			max=iter->data;
		}
			iter=iter->next;
	}

	return max;
}
int find_min_queue(queue *queue_){

	queue *iter=queue_;
	int min=iter->data;
	while(iter!=NULL){
		if(min>iter->data){
			min=iter->data;
		}
			iter=iter->next;
	}

	return min;

}


queue *search_for_dequeue(queue *queue_,int value){
	if(queue_==NULL){
		printf("Not Found \n");
		return NULL;
	}
	else{
		 queue *iter=queue_;
		 if(iter->data==value){
			iter=iter->next;
			return iter;
		 }
		 else{
		while(iter->next->data!=value){
				iter=iter->next;
		}
		queue *temp=iter->next;
		iter->next=iter->next->next;
		free(temp);
		return queue_;
	}

	
	}

}



int bst_max( bst *bst_){
	if(bst_==NULL){
		return -1;
	}
	while(bst_->right!=NULL)
		bst_=bst_->right;
		return bst_->data;

}

int bst_min( bst *bst_){
	if(bst_==NULL){
		return -1;
	}
	while(bst_->left!=NULL)
		bst_=bst_->left;
		return bst_->data;
}

 bst * sil( bst *bst_,int silinen){
	if(bst_==NULL){
		return NULL;
	}
	if(bst_->data==silinen){
		if(bst_->left==NULL && bst_->right ==NULL){
			return NULL;
		}
		if(bst_->right!=NULL){
			bst_->data=bst_min(bst_->right);
			bst_->right=sil(bst_->right,bst_min(bst_->right));
			return bst_;

		}
		
			bst_->data=bst_max(bst_->left);
			bst_->left=sil(bst_->left,bst_max(bst_->left));
			return bst_;
		
	}
	if(bst_->data < silinen){
		bst_->right=sil(bst_->right,silinen);
		return bst_;
	}
		bst_->left=sil(bst_->left,silinen);
		return bst_;
}

void ordered_print( stack * stack_,  queue * queue_,  bst * bst_){

	printf("-----------------\n");
	printf("ORDERED PRİNT\n-----------------");

	int i;
	double total_time_stack,total_time_queue,total_time_bst;
	clock_t start,end;

	

	start=clock();
	order_stack(stack_);
	printf("\nSTACK DESCENDİNG ORDER   : ");
	print_stack(stack_);
	
	end=clock();
	total_time_stack=(double)(end-start)/CLOCKS_PER_SEC*1000;

	start=clock();
	order_queue(queue_);
	printf("\nQUEUE DESCENDİNG ORDER   : ");
	print_queue(queue_);

	end=clock();
	total_time_queue=(double)(end-start)/CLOCKS_PER_SEC*1000;


	start=clock();
	printf("\nBST DESCENDİNG ORDER     : ");
	print_bst(bst_);
	
	end=clock();
	total_time_bst=(double)(end-start)/CLOCKS_PER_SEC*1000;
	

	printf("\n\nStructures\t\tStack\t\tQueue\t\tBST\n");
	printf("Ordering Tİme\t\t%.3f\t\t%.3f\t\t%.3f",total_time_stack,total_time_queue,total_time_bst);
	printf("\n\n\n");


}




void search( stack * stack_,  queue * queue_,  bst * bst_, int val_to_search){
	printf("-----------------\n");
	printf("SEARCHİNG\n-----------------\n");

	double total_time_stack,total_time_queue,total_time_bst;
	clock_t start,end;

	start=clock();
	search_stack(stack_,val_to_search);
	end=clock();
	total_time_stack=(double)(end-start)/CLOCKS_PER_SEC*1000;

	start=clock();
	search_queue(queue_,val_to_search);
	end=clock();
	total_time_queue=(double)(end-start)/CLOCKS_PER_SEC*1000;


	start=clock();
	printf("FOR BST\n");
	search_bst(bst_,val_to_search);
	end=clock();
	total_time_bst=(double)(end-start)/CLOCKS_PER_SEC*1000;



	printf("\n\nStructures\t\tStack\t\tQueue\t\tBST\n");
	printf("Search Tİme\t\t%.3f\t\t%.3f\t\t%.3f",total_time_stack,total_time_queue,total_time_bst);
	printf("\n\n\n");


}

void special_traverse(stack * stack_, queue * queue_, bst * bst_){
	printf("-----------------\n");
	printf("SPECİAL TRAVERSE\n-----------------");
	int i,max,min;

	stack *new_stack=NULL;
	queue *new_queue=NULL;


	double total_time_stack,total_time_queue,total_time_bst;
	clock_t start,end;

	start=clock();
	while(stack_!=NULL){
		max=find_max_stack(stack_);
	new_stack=stack_add_node(new_stack,max);
	stack_=search_for_pop(stack_,max);


	min=find_min_stack(stack_);
	new_stack=stack_add_node(new_stack,min);
	stack_=search_for_pop(stack_,min);
}
	end=clock();
	total_time_stack=(double)(end-start)/CLOCKS_PER_SEC*1000;

printf("\nTRAVERSE STACK   : ");
print_stack_reverse(new_stack);
	

	start=clock();
	while(queue_!=NULL){
	max=find_max_queue(queue_);
	new_queue=enqueue(new_queue,max);
	queue_=search_for_dequeue(queue_,max);


	min=find_min_queue(queue_);
	new_queue=enqueue(new_queue,min);
	queue_=search_for_dequeue(queue_,min);

}	
	printf("\nTRAVERSE QUEUE   : ");
	print_queue(new_queue);
	printf("\n");
	end=clock();
	total_time_queue=(double)(end-start)/CLOCKS_PER_SEC*1000;


	printf("TRAVERSE BST     : ");
	start=clock();
	while(bst_!=NULL){
		max=bst_max(bst_);
		printf("%d  ",max);
		bst_=sil(bst_,max);

		min=bst_min(bst_);
		printf("%d  ",min );
		bst_=sil(bst_,min);

	}
	end=clock();
	total_time_bst=(double)(end-start)/CLOCKS_PER_SEC*1000;
	printf("\n");


printf("\nStructures\t\tStack\t\tQueue\t\tBST\n");
	printf("TRAVERSE Tİme\t\t%.3f\t\t%.3f\t\t%.3f",total_time_stack,total_time_queue,total_time_bst);
	printf("\n\n\n");




	



}


int main(){

int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,
				8, 23, 4};
 bst * bst_=NULL;
 queue * queue_=NULL;
 stack * stack_=NULL;

fill_structures(&stack_, &queue_, &bst_, data);
ordered_print(stack_, queue_, bst_);
search(stack_, queue_, bst_, 5);
special_traverse(stack_, queue_, bst_);
return 0;
}

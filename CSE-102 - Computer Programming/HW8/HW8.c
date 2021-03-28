#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef enum{noone,car,cap}player_type;
typedef enum{start,property,tax,punish,fortune}block_type;

typedef struct 
{
	player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;

}player;

 struct block
{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	block_type type;
	struct block *next;
};





struct block *sira_atla(struct block *board,int x){
	struct block *temp;
	temp=board;
	int i;
	for(i=0;i<x;i++){
		board=board->next;
	}
	return board;
}


struct block *init_the_board( struct block **board){
	int i;
	int block_id_info[24]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	int price_info[24]={0,16000,0,0,16500,17000,0,20000,23000,0,0,30000,0,33000,0,0,35000,40000,0,43000,60000,0,0,70000};
	int rent_inf0[24]={0,800,1500,0,850,875,2,1000,1100,0,1750,1350,2000,1500,2250,0,1600,1750,1,1900,2500,0,5000,3500};
	int rent_1_info[24]={0,4000,0,0,4250,4500,0,5000,5500,0,0,7000,0,8000,0,0,8500,9500,0,11000,15000,0,0,20000};
	int rent_2_info[24]={0,9000,0,0,9500,10000,0,12000,12500,0,0,15000,0,16000,0,0,17000,19000,0,21500,28000,0,0,35500};
	int rent_3_info[24]={0,25000,0,0,26000,28000,0,30000,33000,0,0,40000,0,42000,0,0,45000,48000,0,55000,60000,0,0,65000};
	char name_info[24][24]={"Start","Esenyurt","Car Park","Fortune Card","Tuzla","Arnavutkoy",
	"Wait 2 Turn","Catalca","Beykoz","Fortune Card","Car Fix","Maltepe","Bills","Sisli","Oil",
	"Fortune Card","Atasehir","Sarıyer","Wait 1 Turn","Kadıkoy","Besiktas","Fortune Card","Vocation","Bebek"};

	int house_price_info[24]={0,10000,0,0,12000,12000,0,13000,13000,0,0,15000,0,16000,0,0,17000,19000,0,23000,30000,0,0,35000};
	block_type type_info[24]={start,property,tax,fortune,property,property,punish,property,
								property,fortune,tax,property,tax,property,tax,fortune,property,
								property,punish,property,property,fortune,tax,property};

struct block *temp;
temp=(*board);
temp=malloc(sizeof(struct block));
temp->next=NULL;


temp->name="Start";

struct block *iter;
iter=temp;


for(i=0;i<24;i++){

	
	iter->next=malloc(sizeof(struct block));
	iter->block_id=block_id_info[i];
	iter->price=price_info[i];
	iter->rent=rent_inf0[i];
	iter->rent_1=rent_1_info[i];
	iter->rent_2=rent_2_info[i];
	iter->rent_3=rent_3_info[i];
	iter->house_price=house_price_info[i];
	iter->type=type_info[i];
	iter->next->next=NULL;
	iter=iter->next;
	
}
struct block *iter2;
iter2=temp->next;
iter2->name="Esenyurt";
iter2=iter2->next;
iter2->name="Car Park";
iter2=iter2->next;
iter2->name="Fortune Card";
iter2=iter2->next;
iter2->name="Tuzla";
iter2=iter2->next;
iter2->name="Arnavutköy";
iter2=iter2->next;
iter2->name="Wait 2 turn";
iter2=iter2->next;
iter2->name="Çatalca";
iter2=iter2->next;
iter2->name="Beykoz";
iter2=iter2->next;
iter2->name="Fortune Card";
iter2=iter2->next;
iter2->name="Car Fix";
iter2=iter2->next;
iter2->name="Maltepe";
iter2=iter2->next;
iter2->name="Bills";
iter2=iter2->next;
iter2->name="Sisli";
iter2=iter2->next;
iter2->name="Oil";
iter2=iter2->next;
iter2->name="Fortune Card";
iter2=iter2->next;
iter2->name="Atasehir";
iter2=iter2->next;
iter2->name="Sariyer";
iter2=iter2->next;
iter2->name="Wait 1 Turn";
iter2=iter2->next;
iter2->name="Kadiköy";
iter2=iter2->next;
iter2->name="Besiktas";
iter2=iter2->next;
iter2->name="Fortune Card";
iter2=iter2->next;
iter2->name="Vocation";
iter2=iter2->next;
iter2->name="Bebek";


return temp;
}
void show_board(struct block *board , player player_one , player player_two){
	
	int j,i,k;
	struct block *temp;
	struct block *temp2;
	struct block *temp3;
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<7;i++){
		temp=board;
		temp=sira_atla(board,i);
		printf("%10s\t|",temp->name);
		
	}
	printf("\n");
	for(i=0;i<7;i++){
	temp=board;
	temp=sira_atla(board,i);
		if(temp->price!=0){	
		printf("%10d$\t|",temp->price);
		}
		else if(temp->rent!=0){
				printf("%10d$\t|",temp->rent);
			}
			else
				printf("%10s\t|"," ");
	}

	printf("\n");
	for(i=0;i<7;i++){
		temp=board;
		temp=sira_atla(board,i);

		if(player_one.current_block_id==temp->block_id && player_two.current_block_id==temp->block_id)
			printf("%10s\t|","Car Cap");

		else if(player_one.current_block_id==temp->block_id)
			printf("%10s\t|","Car");

		else if(player_two.current_block_id==temp->block_id)
			printf("%10s\t|","Cap");
		else
			printf("%10s\t|"," ");

	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	
	k=7;
	for(i=23;i>=18;i=i-1){
		temp=board;
		temp=sira_atla(board,i);
		temp2=board;
		temp2=sira_atla(board,k);
		
		if(k<=11 && i>18){
			printf("%10s\t|",temp->name);
			printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n",temp2->name);
			if(temp->price!=0){
				printf("%10d$\t|",temp->price);
			}
				
			else if(temp->rent!=0){
				printf("%10d$\t|",temp->rent);
			}
			
			else
				printf("%10s\t|"," ");
			if(temp2->price!=0){
			printf("\t\t\t\t\t\t\t\t\t\t|%10d$\t|\n",temp2->price);
			}
			else if(temp2->rent!=0){
				printf("\t\t\t\t\t\t\t\t\t\t|%10d$\t|\n",temp2->rent);
			}
			else
				printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n"," ");
			if(i!=19){
				if(player_one.current_block_id==temp->block_id && player_two.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Car Cap");
				else if(player_one.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Car");
				else if(player_two.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Cap");

				 if(player_one.current_block_id==temp2->block_id && player_two.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car Cap");
				else if(player_one.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car");
				else if(player_two.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Cap");
				else{
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|%10s\t|\n"," "," ");
				}


			printf("-----------------\t\t\t\t\t\t\t\t\t\t-----------------");
		}
			if(i==19){
				if(player_one.current_block_id==temp->block_id && player_two.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Car Cap");
				else if(player_one.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Car");
				else if(player_two.current_block_id==temp->block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|\t\t|\n","Cap");
				

				else if(player_one.current_block_id==temp2->block_id && player_two.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car Cap");
				else if(player_one.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car");
				else if(player_two.current_block_id==temp2->block_id)
					printf("\t\t\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Cap");
				else{
					printf("%10s\t|\t\t\t\t\t\t\t\t\t\t|%10s\t|\n"," "," ");
				}
				printf("-----------------------------------------------------------------------------------------------------------------");
			}
		}
		
		if(i==18){
		
		for(j=18;j>=12;j=j-1){
		temp3=board;
		temp3=sira_atla(board,j);

		printf("%10s\t|",temp3->name);
		}
		printf("\n");
		for(j=18;j>=12;j=j-1){
			temp3=sira_atla(board,j);
			if(temp3->price!=0){
				printf("%10d$\t|",temp3->price);
			}
			else if(temp3->rent!=0){
				printf("%10d$\t|",temp3->rent);
				}
			else
				printf("%10s\t|"," ");
		}
		printf("\n");
		for(j=18;j>=12;j=j-1){
		temp3=board;
		temp3=sira_atla(board,j);
	if(player_one.current_block_id==temp3->block_id && player_two.current_block_id==temp3->block_id)
		printf("%10s\t|","Car Cap");
	else if(player_one.current_block_id==temp3->block_id)
		printf("%10s\t|","Car");
	else if(player_two.current_block_id==temp3->block_id)
		printf("%10s\t|","Cap");
	else
		printf("%10s\t|"," ");

		}

	}

		printf("\n");
		k++;
	}
	printf("-----------------------------------------------------------------------------------------------------------------\n");

	
}
void show_proporties(struct block *board){
	struct block *temp;

	int i,choice=-2;
	while(choice!=0){
	printf("Please select a property to see details:\n");
	for(i=0;i<20;i++){
		temp=board;
		temp=sira_atla(board,i);

		if(temp->type==1){
			printf("%d -\t%s\n",temp->block_id,temp->name);
			}
		}
		printf("0 -\tExit\n");
		scanf("%d",&choice);
		temp=sira_atla(board,choice);
		if(choice==0)
			break;
		if(temp->type==1){
		printf("----------------------------------\n");

		printf("|\t%10s\t\t|\n",temp->name);
		printf("----------------------------------\n");
		printf("|\tRent     \t%d$\t|\n",temp->rent);
		printf("|\tRent 1 H \t%d$\t|\n",temp->rent_1);
		printf("|\tRent 2 H \t%d$\t|\n",temp->rent_2);
		printf("|\tRent 3 H \t%d$\t|\n",temp->rent_3);
		printf("----------------------------------\n");
		printf("|\tHouse Price:\t%d$\t|\n",temp->house_price);
		printf("----------------------------------\n");
		}
		else
			printf("Please Select Property Place\n");
	}
}
void buy_property(struct block *current_block,player *current_player){
	int i,placebuying,housebuying;
	int avarage=33625,dice;
	int propertyfind=0;

 	if(current_block->type==property && current_block->owner.type==noone && current_player->type==car){
				if(current_player->account>=current_block->price){	
				printf("Do You want to buy %s ?\n",current_block->name);
				printf("Yes :1 No :2\n");
				printf("Select:");
				scanf("%d",&placebuying);
				if(placebuying==1){
					if(current_block->block_id==current_player->current_block_id &&
						current_player->account>=current_block->price && current_block->type==1){
							for(i=0;i<11;i++){
							if(current_player->owned_block_ids[i]==-2){
							current_player->owned_block_ids[i]=current_block->block_id;
								break;
						}	
					}
				}	
					if(current_player->type==car){
						
						current_block->owner.type=car;
					}
					if(current_player->type==cap){
						current_block->owner.type=cap;
					}
					current_player->account=current_player->account-current_block->price;
					while(housebuying!=2){
					if(current_block->house_count==3){
							printf("Number of house 3.You can't buy house!!\n");
							break;
							}
					printf("Do you want to buy house for %s\n",current_block->name);
					printf("Yes :1 No :2\n");
					printf("Select:");
					scanf("%d",&housebuying);
					if(housebuying==1){
						current_block->house_count++;
						current_player->account=current_player->account-current_block->house_price;
								}
							}	
						}
					}
				}
			
			else if(current_block->owner.type==current_player->type && current_block->type==1 && current_player->type==car ){
					while(housebuying!=2){
					if(current_block->house_count==3){
							printf("Number of house 3.You can't buy house!!\n");
							break;
							}
					printf("Do you want to buy house for %s\n",current_block->name);
					printf("Yes :1 No :2\n");
					printf("Select:");
					scanf("%d",&housebuying);
					if(housebuying==1){
						current_block->house_count++;
						current_player->account=current_player->account-current_block->house_price;
				}
			}
		}
		 
		else if(current_block->owner.type==noone && current_player->type==cap && current_block->type==property){
			if(current_player->account>=current_block->price){
				if(current_block->price<avarage){
					printf("Price of the %s is lower then avarage so Computer Buy %s\n",current_block->name,current_block->name);
					current_block->owner.type=cap;
					current_player->account=current_player->account-current_block->price;
					for(i=0;i<11;i++){
						if(current_player->owned_block_ids[i]==-2){
							current_player->owned_block_ids[i]=current_block->block_id;
								break;
							}	
						}	
					}

			else{
					dice=1+rand()%6;
					printf("Computer rolled the dice to decide to buying or not buying property Dice=>%d\n",dice);
					if(dice>=1 && dice<=3){
						current_block->owner.type==cap;
						current_player->account=current_player->account-current_block->price;
						printf("Computer Buy %s\n",current_block->name);
						for(i=0;i<11;i++){
							if(current_player->owned_block_ids[i]==-2){
							current_player->owned_block_ids[i]=current_block->block_id;
								break;
							}	
						}
					}
					else{
						printf("Computer don't buy %s because dice is not between 1 and 3\n",current_block->name);
					}
				}
			}
			else{
				printf("Computer doesn't have money for buying %s \n",current_block->name );
			}


		}
		
		else if(current_block->owner.type==cap && current_player->type==cap  && current_block->type==property ){
				for(i=0;i<11;i++){
					if(current_player->owned_block_ids[i]!=-2){
								propertyfind++;
							}	
					}
				if(current_player->account>=current_block->house_price){
				if(propertyfind>=4){
					dice=1+rand()%6;
					printf("Computer rolled the dice to decide to buying or not buying house for %s:%d\n",current_block->name,dice);
					if(dice>=1 && dice<=3){
						if(current_block->house_count<3){
							printf("Computer buy house for %s\n",current_block->name);
							current_block->house_count++;
							current_player->account=current_player->account-current_block->house_price;
							}
						else{
							printf("Computer already have three house for %s\n",current_block->name);
							}
						}
						else{
							printf("Computer don't buy house  because dice=>%d\n",dice);
						}

					}
				}
				else{
					printf("Computer doesn't have buy house for %s\n",current_block->name );
				}
			}
		}

void show_my_properties(struct block *board,player *current_player){
	struct block *temp;
	int k=0,i;
	printf("Your Properties\n");
			for(i=0;i<11;i++){
				temp=board;
				temp=sira_atla(board,i);
				if(current_player->owned_block_ids[i]!=-2){
					temp=sira_atla(board,current_player->owned_block_ids[i]);
				printf("%d - %s\n",current_player->owned_block_ids[i],
				temp->name);
				}
	}
}
void sell_property(struct block *board,player *current_player){
	struct block *temp,*temp2;
	temp=board;
	int sell=-2,choice,bankprice;
	int k,i;
	int max_property;
	if(current_player->type==car){
		
		printf("Your Properties\n");
			for(i=0;i<11;i++){
			if(current_player->owned_block_ids[i]!=-2){
			temp=sira_atla(board,current_player->owned_block_ids[i]);
			printf("%d - %s\n",current_player->owned_block_ids[i],
				temp->name);
		}
		
	}
		while(sell!=0){
			
			//Show Properties
			printf("0 - Exit\n");
			printf("Select Properties For Selling:");
			scanf("%d",&sell);
			sell;
			if(sell!=0){
				temp=sira_atla(board,sell);
				bankprice=temp->price/2;
				current_player->account=current_player->account+bankprice+((temp->house_count*temp->house_price)/2);
				temp2=sira_atla(board,current_player->current_block_id);
				temp2->owner.type=noone;
			}
			for(i=0;i<11;i++){
				if(current_player->owned_block_ids[i]==sell){
					current_player->owned_block_ids[i]=-2;
					break;
					}
				}
			

			printf("Your Properties\n");
			for(i=0;i<11;i++){
				if(current_player->owned_block_ids[i]!=-2){
					temp2=sira_atla(board,current_player->owned_block_ids[i]);

				printf("%d - %s\n",current_player->owned_block_ids[i],
				temp2->name);
					}
				}
			}
		}
		
		if(current_player->type==cap){
			
			temp=sira_atla(board,current_player->owned_block_ids[0]);
			max_property=temp->price;
			for(i=0;i<11;i++){
			if(current_player->owned_block_ids[i]!=-2){
			temp=sira_atla(board,current_player->owned_block_ids[i]);
			if(max_property<temp->price){
				max_property=temp->block_id;
						}	
					}
				}
				temp=sira_atla(board,max_property);
				printf("Computer sell %s\n",temp->name);
				bankprice=temp->price/2;
				current_player->account=current_player->account+bankprice+((temp->house_count*temp->house_price)/2);
				temp2=sira_atla(board,current_player->current_block_id);
				temp2->owner.type=noone;

		}
	}

struct fortune_card
{
	char *card_name;
	int card_tipe;
	struct fortune_card *next;
	
};
void gameplay(struct block *board,player player_one,player player_two){
	struct block *temp,*temp2,*temp_for_fortune;
	temp=board;
	

	int i,buy_house_counter;
	int punish_block,placebuying,housebuying;
	int waitcounter1=1,waitcounter2=2,player_selecting,select,dice;
	struct block current_block;
	player_one.current_block_id=0;
	player_two.current_block_id=0;
	player_one.type=car;
	player_two.type=cap;
	player_one.account=100000;
	player_two.account=100000;

	int buy_house_fortune;
	struct fortune_card *fortune_list;
	struct fortune_card * fortune_temp;
	int selecting_card;

	for(i=0;i<24;i++){
		temp=sira_atla(board,i);
		temp->house_count=0;
				}

	for(i=0;i<11;i++){
		player_one.owned_block_ids[i]=-2;
		player_two.owned_block_ids[i]=-2;
				}
	for(i=0;i<24;i++){
		temp=sira_atla(board,i);
		temp->owner.type=noone;
				}
	 show_board(board ,player_one ,player_two);
	 player_selecting=0;
	 

	while(player_one.account>=0 && player_two.account>=0){
	if(player_selecting==0){
		printf("\n\nYour Account:%d\tComputer account:%d\n\n",player_one.account,player_two.account);

		printf("YOUR  TURN\n");
		printf("1 - Roll the dice\n");
		printf("2 - Show my account\n");
		printf("3 - Show my Properties\n");
		printf("4 - Show property deeds\n");
		printf("5 - Buy Property\n");
		printf("6 - Buy House\n");
		printf("7 - Sell property\n");
		printf("Please select an option to continue:");
		scanf("%d",&select);
	}
	
		
		if(player_selecting==0){

			switch(select){
			case 1:
				dice=1+rand()%6;
				player_one.current_block_id=player_one.current_block_id+dice;

				if(player_one.current_block_id>=24){
					player_one.current_block_id=player_one.current_block_id%24;
					player_one.account=player_one.account+10000;
				}
				//Temp move on linked list when reach  current block; 
				temp=sira_atla(board,player_one.current_block_id);
				
				printf("Car has arrived %s\n",temp->name);

				if(player_two.current_block_id==5){
					if(waitcounter2!=0){
						waitcounter2=waitcounter2-1;
							}
					else{
						player_selecting=player_selecting+1;
						waitcounter2=2;
					}
				}
				else if(player_two.current_block_id==15){
					if(waitcounter1!=0){
						waitcounter1=waitcounter1-1;
							}
					else{
						player_selecting=player_selecting+1;
						waitcounter1=1;
					}
				}
				else{
						player_selecting=player_selecting+1;
					
					}

				
				fortune_list=malloc(sizeof(struct fortune_card));
				fortune_list->next=NULL;
				fortune_temp=fortune_list;
				for(i=1;i<=5;i++){
					fortune_temp->next=malloc(sizeof(struct fortune_card));
					fortune_temp->card_tipe=i;
					fortune_temp->next->next=NULL;
					fortune_temp=fortune_temp->next;

				}
				fortune_temp=fortune_list;
				fortune_temp->card_name="Free House";
				fortune_temp=fortune_temp->next;
				fortune_temp->card_name="Time Travel";
				fortune_temp=fortune_temp->next;
				fortune_temp->card_name="Garnishment";
				fortune_temp=fortune_temp->next;
				fortune_temp->card_name="Generosity";
				fortune_temp=fortune_temp->next;
				fortune_temp->card_name="Treasure Hunter";
				fortune_temp=fortune_temp->next;

				fortune_temp=fortune_list;

				selecting_card=1+rand()%5;
				while(selecting_card!=fortune_temp->card_tipe){
					fortune_temp=fortune_temp->next;
				}
				if(temp->type==fortune){
				printf("Lucky Card is :%d ",selecting_card);
					
				if(fortune_temp->card_tipe==1){
					printf("-You can buy Free house\n");
					show_my_properties(board,&player_one);
					printf("Select property for buy house:");
					scanf("%d",&buy_house_fortune);
					temp_for_fortune=sira_atla(board,buy_house_fortune);
					temp_for_fortune->house_count++;
					printf("You get free house for %s\n",temp_for_fortune->name);

					}
				int dice_fortune=1+rand()%6;
				if(fortune_temp->card_tipe==2){
					printf("-You can use Time Travel\n");
					printf("You rolled the dice for Time Travel:%d\n",dice_fortune);
					if(dice_fortune>=1 && dice_fortune<=3){
						printf("You have moved two blocks\n");
						player_one.current_block_id+=2;
						temp=sira_atla(board,player_one.current_block_id);
					}
					else{
						printf("You moved two blocks down\n");
						player_one.current_block_id=player_one.current_block_id-2;
						temp=sira_atla(board,player_one.current_block_id);
					}

				}
				if(fortune_temp->card_tipe==3){
					printf("-You must Garnishment\n");
					printf("Your account:%d - ",player_one.account);
					player_one.account=player_one.account-5000;
					printf("5000$=%d\n",player_one.account);

				}
				if(fortune_temp->card_tipe==4){
					printf("-You must Generosity your opponent\n");
					printf("Your account:%d - ",player_one.account);
					player_one.account=player_one.account-10000;
					player_two.account=player_two.account+10000;
					printf("10000$=%d\n",player_one.account);
				}
				if(fortune_temp->card_tipe==5){
					printf("-You won Treasure\n");
					printf("Your account:%d + ",player_one.account);
					player_one.account=player_one.account+20000;
					printf("20000$=%d\n",player_one.account);

					}

					
				}
				

				if(temp->type==tax){
					printf("""You pay tax for %s\n",temp->name);
					player_one.account=player_one.account-temp->rent;
				}
				
				buy_property(temp,&player_one);
			
			if(temp->owner.type==cap){
					if(temp->house_count==0){
						if(player_one.account>=temp->rent){
							printf("You paid rent for %s\n",temp->name);
							player_one.account=player_one.account-temp->rent;
							player_two.account=player_two.account+temp->rent;
						}
						else{
							while(player_one.account<temp->rent){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}

						}
					}

					if(board[player_one.current_block_id].house_count==1){
						if(player_one.account>=temp->rent_1){
							printf("You paid rent for %s\n",temp->name);
							player_one.account=player_one.account-temp->rent_1;
							player_two.account=player_two.account+temp->rent_1;
						}
						else{
							while(player_one.account<temp->rent_1){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(temp->house_count==2){
						if(player_one.account>=temp->rent_2){
							printf("You paid rent for %s\n",temp->name);
							player_one.account=player_one.account-temp->rent_2;
							player_two.account=player_two.account+temp->rent_2;
						}
						else{
							while(player_one.account<temp->rent_2){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(temp->house_count==3){
						if(player_one.account>=temp->rent_3){		
							player_one.account=player_one.account-temp->rent_3;
							player_two.account=player_two.account+temp->rent_3;
							printf("You paid rent for %s\n",temp->name);
						}
						else{
							while(player_one.account<temp->rent_3){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
				}
	
			break;
		
			case 2:
				printf("CAR account:%d$\n",player_one.account);
				
			break;
			case 3:
				show_my_properties(board,&player_one);
			break;

			case 4:
				show_proporties(board);
			break;
			case 5:
				buy_property(temp,&player_one);

			
			break;
			case 6:
			buy_property(temp,&player_one);
			break;
			case 7:
				sell_property(board,&player_one);
			break;
				}
			}

			
			
		
		else if(player_selecting==1){

			
				dice=1+rand()%6;
				
				player_two.current_block_id=player_two.current_block_id+dice;

				if(player_two.current_block_id>=24){
					player_two.current_block_id=player_two.current_block_id%24;
					player_two.account=player_two.account+10000;
				}
				temp=sira_atla(board,player_two.current_block_id);

				if(player_one.current_block_id==5){

					if(waitcounter2!=0){
					waitcounter2=waitcounter2-1;	
					}
					else{
						waitcounter2=2;
						player_selecting=player_selecting-1;
					}
				}
				else if(player_one.current_block_id==15){
					if(waitcounter1!=0){
					waitcounter1=waitcounter1-1;	
					}
					else{
						player_selecting=player_selecting-1;
						waitcounter1=1;
						
					}
				}
				else{
						player_selecting=player_selecting-1;
					}

				
				show_board(board,player_one,player_two);
				
				printf("***COMPUTER TURN****\n");
				printf("Computer rolled the dice:%d\n",dice);
				printf("Computer has arrived %s\n",temp->name);

				fortune_list=malloc(sizeof(struct fortune_card));
				fortune_list->next=NULL;
				fortune_temp=fortune_list;
				for(i=1;i<=5;i++){
					fortune_temp->next=malloc(sizeof(struct fortune_card));
					fortune_temp->card_tipe=i;
					fortune_temp->next->next=NULL;
					fortune_temp=fortune_temp->next;

				}
				
				fortune_temp=fortune_list;

				int selecting_card;
				selecting_card=1+rand()%5;
				while(selecting_card!=fortune_temp->card_tipe){
					fortune_temp=fortune_temp->next;
				}
				if(temp->type==fortune){
				printf("Lucky Card is :%d ",selecting_card);
					
				if(fortune_temp->card_tipe==1){
					printf("-COMPUTER can buy Free house\n");
					show_my_properties(board,&player_two);
					printf("Select property for buy house:");
					scanf("%d",&buy_house_fortune);
					temp_for_fortune=sira_atla(board,buy_house_fortune);
					temp_for_fortune->house_count++;
					printf("COMPUTER get free house for %s\n",temp_for_fortune->name);

					}
				int dice_fortune=1+rand()%6;
				if(fortune_temp->card_tipe==2){
					printf("-COMPUTER can use Time Travel\n");
					printf("COMPUTER rolled the dice for Time Travel:%d\n",dice_fortune);
					if(dice_fortune>=1 && dice_fortune<=3){
						printf("COMPUTER have moved two blocks\n");
						player_two.current_block_id+=2;
						temp=sira_atla(board,player_two.current_block_id);
					}
					else{
						printf("COMPUTER moved two blocks down\n");
						player_two.current_block_id=player_two.current_block_id-2;
						temp=sira_atla(board,player_two.current_block_id);
					}

				}
				if(fortune_temp->card_tipe==3){
					printf("-COMPUTER must Garnishment\n");
					printf("COMPUTER account:%d - ",player_two.account);
					player_two.account=player_two.account-5000;
					printf("5000$=%d\n",player_two.account);

				}
				if(fortune_temp->card_tipe==4){
					printf("-COMPUTER must Generosity to YOU\n");
					printf("COMPUTER account:%d - ",player_two.account);
					player_two.account=player_two.account-10000;
					player_one.account=player_one.account+10000;
					printf("10000$=%d\n",player_two.account);
				}
				if(fortune_temp->card_tipe==5){
					printf("-COMPUTER won Treasure\n");
					printf("COMPUTER account:%d + ",player_two.account);
					player_two.account=player_two.account+20000;
					printf("20000$=%d\n",player_two.account);

					}

					
				}

				if(temp->type==2){
					printf("""Computer pay tax for %s""\n",temp->name);
					player_two.account=player_two.account-temp->rent;
				}
				buy_property(temp,&player_two);

				if(temp->owner.type==car){
					if(temp->house_count==0){
						if(player_two.account>=temp->rent){
							player_two.account=player_two.account-temp->rent;
							player_one.account=player_one.account+temp->rent;
							printf("Computer paid rent %d  for %s\n",temp->rent,temp->name);
						}
						else{
							while(player_two.account<temp->rent){
								printf("COMPUTER Money isnt enough to pay rent.COMPUTER must sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("COMPUTER Lost!!!\n");
									break;
								}
							}

						}
					}
					if(temp->house_count==1){
						if(player_two.account>=temp->rent_1){
							printf("Computer paid rent %d  for %s\n",temp->rent_1,temp->name);
							player_two.account=player_two.account-temp->rent_1;
							player_one.account=player_one.account+temp->rent_1;
						}
						else{
							while(player_two.account<temp->rent_1){
								printf("COMPUTER's Money isnt enough to pay rent.COMPUTER must sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("COMPUTER Lost!!!\n");
									break;
								}
							}
						}
					}
					if(temp->house_count==2){
						if(player_two.account>=temp->rent_2){
							printf("Computer paid rent %d  for %s\n",temp->rent_2,temp->name);
							player_one.account=player_one.account+temp->rent_2;
							player_two.account=player_two.account-temp->rent_2;
						}
						else{
							while(player_two.account<temp->rent_2){
								printf("COMPUTER Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("COMPUTER Lost!!!\n");
									break;
								}
							}
						}
					}
					if(temp->house_count==3){
						if(player_two.account>=temp->rent_3){	
							printf("Computer paid rent %d  for %s\n",temp->rent_3,temp->name);
							player_one.account=player_one.account+temp->rent_3;
							player_two.account=player_two.account-temp->rent_3;
						}
						else{
							while(player_two.account<temp->rent_3){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("COMPUTER Lost!!!\n");
									break;
								}
							}
						}
					}
				}
			if(player_one.account<=0){
				printf("Computer win!!You Lost\n");
				break;
			}
			if(player_two.account<=0){
				printf("Congrulations you Win!!\n");
				break;
				}
			
			}
			
		}
	
}

int main(){
	
srand(time(NULL));
	int i;
	struct block *board=NULL;
	struct block *temp;
	player player_one;
	player player_two;
	temp=init_the_board(&board);
	gameplay(temp,player_one,player_two);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum{noone,car,cap}player_type;
typedef enum{start,property,tax,punish}block_type;

typedef struct 
{
	player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char *name;

}player;

typedef struct 
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
}block;


void init_the_board(block board[20]){
	int i;
	int block_id_info[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int price_info[20]={0,16000,0,16500,17000,0,20000,23000,0,30000,0,33000,0,35000,40000,0,43000,60000,0,70000};
	int rent_inf0[20]={0,800,1500,850,875,2,1000,1100,1750,1350,2000,1500,2250,1600,1750,1,1900,2500,5000,3500};
	int rent_1_info[20]={0,4000,0,4250,4500,0,5000,5500,0,7000,0,8000,0,8500,9500,0,11000,15000,0,20000};
	int rent_2_info[20]={0,9000,0,9500,10000,0,12000,12500,0,15000,0,16000,0,17000,19000,0,21500,28000,0,35500};
	int rent_3_info[20]={0,25000,0,26000,28000,0,30000,33000,0,40000,0,42000,0,45000,48000,0,55000,60000,0,65000};
	int house_price_info[20]={0,10000,0,12000,12000,0,13000,13000,0,15000,0,16000,0,17000,19000,0,23000,30000,0,35000};
	block_type type_info[20]={0,1,2,1,1,3,1,1,2,1,2,1,2,1,1,3,1,1,2,1};
for(i=0;i<20;i++){
	board[i].block_id=block_id_info[i];
	board[i].price=price_info[i];
	board[i].rent=rent_inf0[i];
	board[i].rent_1=rent_1_info[i];
	board[i].rent_2=rent_2_info[i];
	board[i].rent_3=rent_3_info[i];
	board[i].house_price=house_price_info[i];
	board[i].house_count=0;
	board[i].type=type_info[i];	

	}
	board[0].name="Start";
	board[1].name="Esenyurt";
	board[2].name="Car Park";
	board[3].name="Tuzla";
	board[4].name="Arnavutköy";
	board[5].name="Wait 2 Turn";
	board[6].name="Catalca";
	board[7].name="Beykoz";
	board[8].name="Car Fix";
	board[9].name="Maltepe";
	board[10].name="Bills";
	board[11].name="Sisli";
	board[12].name="Oil";
	board[13].name="Atasehir";
	board[14].name="Sariyer";
	board[15].name="Wait 1 Turn";
	board[16].name="Kadiköy";
	board[17].name="Besiktas";
	board[18].name="Vocation";
	board[19].name="Bebek";



}

void show_board(block board[20] , player player_one , player player_two){
	int j,i,k;
	
	printf("--------------------------------------------------------------------------------------------------\n");
	for(i=0;i<6;i++){
		printf("%10s\t|",board[i].name);
		
	}
	printf("\n");
	for(i=0;i<6;i++){
		if(board[i].price!=0){
		printf("%10d$\t|",board[i].price);
		}
		if(board[i].price==0){
			printf("%10d$\t|",board[i].rent);
		}

	}
	printf("\n");
	for(i=0;i<6;i++){
		if(player_one.current_block_id==board[i].block_id && player_two.current_block_id==board[i].block_id)
			printf("%10s\t|","Car Cap");

		else if(player_one.current_block_id==board[i].block_id)
			printf("%10s\t|","Car");

		else if(player_two.current_block_id==board[i].block_id)
			printf("%10s\t|","Cap");
		else
			printf("%10s\t|"," ");

	}
	printf("\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	
	k=6;
	for(i=19;i>=15;i=i-1){
		
		if(k<=10 && i>15){
			printf("%10s\t|",board[i].name);
			printf("\t\t\t\t\t\t\t\t|%10s\t|\n",board[k].name);
			if(board[i].price!=0){
				printf("%10d$\t|",board[i].price);
				}
			else{
				printf("%10d$\t|",board[i].rent);
			}
			if(board[k].price!=0){
			printf("\t\t\t\t\t\t\t\t|%10d$\t|\n",board[k].price);
			}
			else{
				printf("\t\t\t\t\t\t\t\t|%10d$\t|\n",board[k].rent);
			}

			if(i!=16){
				if(player_one.current_block_id==board[i].block_id && player_two.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Car Cap");
				else if(player_one.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Car");
				else if(player_two.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Cap");

			else if(player_one.current_block_id==board[k].block_id && player_two.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car Cap");
				else if(player_one.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car");
				else if(player_two.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Cap");
				else{
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n"," ");
				}


			printf("-----------------\t\t\t\t\t\t\t\t------------------");
		}
			if(i==16){
				if(player_one.current_block_id==board[i].block_id && player_two.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Car Cap");
				else if(player_one.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Car");
				else if(player_two.current_block_id==board[i].block_id)
					printf("%10s\t|\t\t\t\t\t\t\t\t|\t\t|\n","Cap");
				

				else if(player_one.current_block_id==board[k].block_id && player_two.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car Cap");
				else if(player_one.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Car");
				else if(player_two.current_block_id==board[k].block_id)
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n","Cap");
				else{
					printf("\t\t\t\t\t\t\t\t\t\t|%10s\t|\n"," ");
				}
				printf("--------------------------------------------------------------------------------------------------");
			}
		}
		
		if(i==15){
		
		for(j=15;j>=10;j=j-1){
		printf("%10s\t|",board[j].name);
		}
		printf("\n");
		for(j=15;j>=10;j=j-1){
			if(board[j].price!=0){
				printf("%10d$\t|",board[j].price);
			}
			else{
			printf("%10d$\t|",board[j].rent);
				}
		}
		printf("\n");
		for(j=15;j>=10;j=j-1){
	if(player_one.current_block_id==board[j].block_id && player_two.current_block_id==board[j].block_id)
		printf("%10s\t|","Car Cap");
	else if(player_one.current_block_id==board[j].block_id)
		printf("%10s\t|","Car");
	else if(player_two.current_block_id==board[j].block_id)
		printf("%10s\t|","Cap");
	else
		printf("%10s\t|"," ");

		}

	}

		printf("\n");
		k++;
	}
	printf("--------------------------------------------------------------------------------------------------\n");

	
}
void show_proporties(block board[20]){
	int i,choice;
	while(choice!=0){
	printf("Please select a property to see details:\n");
	for(i=0;i<20;i++){
		if(board[i].type==1){
			printf("%d -\t%s\n",board[i].block_id,board[i].name);
			}
		}
		printf("0 -\tExit\n");
		scanf("%d",&choice);
		if(choice==0)
			break;
		if(board[choice].type==1){
		printf("----------------------------------\n");

		printf("|\t%10s\t\t|\n",board[choice].name);
		printf("----------------------------------\n");
		printf("|\tRent     \t%d$\t|\n",board[choice].rent);
		printf("|\tRent 1 H \t%d$\t|\n",board[choice].rent_1);
		printf("|\tRent 2 H \t%d$\t|\n",board[choice].rent_2);
		printf("|\tRent 3 H \t%d$\t|\n",board[choice].rent_3);
		printf("----------------------------------\n");
		printf("|\tHouse Price:\t%d$\t|\n",board[choice].house_price);
		printf("----------------------------------\n");
		}
		else
			printf("Please Select Property Place\n");
	}
}
void buy_property(block *current_block,player *current_player){
	int i,placebuying,housebuying;

 	if(current_block->type==1 && current_block->owner.type==noone){
				if(current_player->account>=current_block->price){	
				printf("Do You want to buy this Place ?\n");
				printf("Yes :1 No :2\n");
				printf("Select:");
				scanf("%d",&placebuying);
				if(placebuying==1){
					if(current_block->block_id==current_player->current_block_id &&
						current_player->account>=current_block->price && current_block->type==1){
							printf("You bought this property\n");
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
					printf("Do you want to buy house for this Place\n");
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
			
			else if(current_block->owner.type==current_player->type && current_block->type==1){
					while(housebuying!=2){
					if(current_block->house_count==3){
							printf("Number of house 3.You can't buy house!!\n");
							break;
							}
					printf("Do you want to buy house for this Place\n");
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

void show_my_properties(block board[20],player *current_player){
	
	int k=0,i;
	printf("Your Properties\n");
			for(i=0;i<11;i++){
				if(current_player->owned_block_ids[i]!=-2){
				printf("%d - %s\n",current_player->owned_block_ids[i],
				board[current_player->owned_block_ids[i]].name);
				}
	}
}
void sell_property(block board[20],player *current_player){
		int sell=-2,choice,bankprice;
		int k,i;
		printf("Your Properties\n");
			for(i=0;i<11;i++){
			if(current_player->owned_block_ids[i]!=-2)
			printf("%d - %s\n",current_player->owned_block_ids[i],
				board[current_player->owned_block_ids[i]].name);
		
	}
		while(sell!=0){
			
			//Show Properties
			printf("0 - Exit\n");
			printf("Select Properties For Selling:");
			scanf("%d",&sell);
			sell;
			if(sell!=0){
				bankprice=board[sell].price/2;
				current_player->account=current_player->account+bankprice+((board[sell].house_count*board[sell].house_price)/2);
				board[current_player->current_block_id].owner.type=noone;
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
				printf("%d - %s\n",current_player->owned_block_ids[i],
				board[current_player->owned_block_ids[i]].name);
				}
			}
		}
	}
void gameplay(block board[20],player player_one,player player_two){
	int i,buy_house_counter;
	int punish_block,placebuying,housebuying;
	int waitcounter1=1,waitcounter2=2,player_selecting,select,dice;
	block current_block;
	player_one.current_block_id=0;
	player_two.current_block_id=0;
	player_one.type=car;
	player_two.type=cap;
	player_one.account=100000;
	player_two.account=100000;

	for(i=0;i<20;i++){
		board[i].house_count=0;
				}

	for(i=0;i<11;i++){
		player_one.owned_block_ids[i]=-2;
		player_two.owned_block_ids[i]=-2;
				}
	for(i=0;i<20;i++){
		board[i].owner.type=noone;
				}
	 show_board(board ,player_one ,player_two);
	 player_selecting=0;
	 

	while(player_one.account>=0 && player_two.account>=0){
	if(player_selecting==0)
		printf("PLAYER 1 TURN\n");
	if(player_selecting!=0)
		printf("PLAYER 2 TURN\n");

		printf("1 - Roll the dice\n");
		printf("2 - Show my account\n");
		printf("3 - Show my Properties\n");
		printf("4 - Show property deeds\n");
		printf("5 - Buy Property\n");
		printf("6 - Buy House\n");
		printf("7 - Sell property\n");
		printf("Please select an option to continue:");
		scanf("%d",&select);

		
		if(player_selecting==0){

			switch(select){
			case 1:
				dice=1+rand()%6;
				printf("Number of Steps:%d\n",dice);
				player_one.current_block_id=player_one.current_block_id+dice;

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

					
				if(player_one.current_block_id>=20){
					player_one.current_block_id=player_one.current_block_id%20;
					player_one.account=player_one.account+10000;
				}
				show_board(board,player_one,player_two);
				buy_property(&board[player_one.current_block_id],&player_one);
			
			if(board[player_one.current_block_id].owner.type==cap){
					if(board[player_one.current_block_id].house_count==0){
						if(player_one.account>=board[player_one.current_block_id].rent){
							player_one.account=player_one.account-board[player_one.current_block_id].rent;
						}
						else{
							while(player_one.account<board[player_one.current_block_id].rent){
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
						if(player_one.account>=board[player_one.current_block_id].rent_1){
							player_one.account=player_one.account-board[player_one.current_block_id].rent_1;
						}
						else{
							while(player_one.account<board[player_one.current_block_id].rent_1){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(board[player_one.current_block_id].house_count==2){
						if(player_one.account>=board[player_one.current_block_id].rent_2){
							player_one.account=player_one.account-board[player_one.current_block_id].rent_2;
						}
						else{
							while(player_one.account<board[player_one.current_block_id].rent_2){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_one);
								if(player_one.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(board[player_one.current_block_id].house_count==3){
						if(player_one.account>=board[player_one.current_block_id].rent_3){		
							player_one.account=player_one.account-board[player_one.current_block_id].rent_3;
						}
						else{
							while(player_one.account<board[player_one.current_block_id].rent_3){
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
				buy_property(&board[player_one.current_block_id],&player_one);

			
			break;
			case 6:
			buy_property(&board[player_one.current_block_id],&player_one);
			break;
			case 7:
				sell_property(board,&player_one);
			break;
				}
			}

			
			
		
		else if(player_selecting==1){
		switch(select){
			case 1:
				dice=1+rand()%6;
				printf("Number of Steps:%d\n",dice);
				player_two.current_block_id=player_two.current_block_id+dice;

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

				if(player_two.current_block_id>=20){
					player_two.current_block_id=player_two.current_block_id%20;
					player_two.account=player_two.account+10000;
				}
				if(board[player_two.current_block_id].type==2){
					player_two.account=player_two.account-board[player_two.current_block_id].rent;
				}
				show_board(board,player_one,player_two);
				buy_property(&board[player_two.current_block_id],&player_two);

				if(board[player_two.current_block_id].owner.type==car){
					if(board[player_two.current_block_id].house_count==0){
						if(player_two.account>=board[player_two.current_block_id].rent)
							player_two.account=player_two.account-board[player_two.current_block_id].rent;
						else{
							while(player_two.account<board[player_two.current_block_id].rent){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}

						}
					}
					if(board[player_two.current_block_id].house_count==1){
						if(player_two.account>=board[player_two.current_block_id].rent_1)
							player_two.account=player_two.account-board[player_two.current_block_id].rent_1;
						else{
							while(player_two.account<board[player_two.current_block_id].rent_1){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(board[player_two.current_block_id].house_count==2){
						if(player_two.account>=board[player_two.current_block_id].rent_2)
							player_two.account=player_two.account-board[player_two.current_block_id].rent_2;
						else{
							while(player_two.account<board[player_two.current_block_id].rent_2){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
					if(board[player_two.current_block_id].house_count==3){
						if(player_two.account>=board[player_two.current_block_id].rent_3)		
							player_two.account=player_two.account-board[player_two.current_block_id].rent_3;
						else{
							while(player_two.account<board[player_two.current_block_id].rent_3){
								printf("Your Money isnt enough to pay rent.Please sell property\n");
								sell_property(board,&player_two);
								if(player_two.account==0){
									printf("You Lost!!!\n");
									break;
								}
							}
						}
					}
				}
				
			break;
		
			case 2:
				printf("CAP account:%d$\n",player_two.account);
			break;
			case 3:
				show_my_properties(board,&player_two);
			break;

			case 4:
				show_proporties(board);
			break;
			case 5:
				buy_property(&board[player_two.current_block_id],&player_two);
			break;
			case 6:
				buy_property(&board[player_two.current_block_id],&player_two);
			break;
			case 7:
				sell_property(board,&player_two);
			break;
			if(player_one.account<=0){
				printf("Player 2 win!!\n");
				break;
			}
			if(player_two.account<=0){
				printf("Player 1 win!!\n");
				break;
			}
			
			}
			
		}
	}
}

int main(){
	
srand(time(NULL));
	int i;
	block board[20];
	player player_one;
	player player_two;
	init_the_board(board);
	
	gameplay(board,player_one,player_two);
	return 0;
}

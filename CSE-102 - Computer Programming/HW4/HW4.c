#include <stdio.h>
#include<time.h>
typedef enum{Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby}pokemon;
typedef enum{quadratic,linear}attack_type;

void pokedex(char Pokemon_name[10][11],int range[], attack_type type[],int attack_power[],int stamina[]);
int stringcomparision(char str1[], char str2[]);
void show_Pokemons(char Pokemon_name[10][11],pokemon Pokemons[],int pokemon_count);
void oaks_laboratory(char Pokemon_name[10][11],pokemon Pokemons[],pokemon *my_Pokemons);
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons);
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons);
void menu();
void show_area(char pokemon_name[11][10],int area[8][8],int pokemon_staminas[2][4]);
int main(){
	menu();

	return 0;
}


int stringcomparision(char str1[], char str2[]){
    int i = 0, j = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
   
        if(str1[i] != str2[i]) 
        {
            j= 1;
            break;
        }
        i++;
    }

   
    if(j == 0 && str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}


void pokedex(char pokemon_name[10][11],int range[],attack_type  type[],int attack_power[],int stamina[]){
		int compare;
		char pokemontype[10];
		printf("Please type name of Pokemon(type exit to close Pokedex):");
		scanf("%s",pokemontype);
		int i=0;
	while(i!=11){

		compare=stringcomparision(pokemontype,pokemon_name[i]);
		if(compare==1){
		printf("\n\nName : %s\n",pokemon_name[i]);
		if(type[i]==quadratic)
			printf("A. Type: Quadratic\n");
		if(type[i]==linear)
			printf("A. Type: linear\n");
		printf("Range: %d block \n",range[i]);
		printf("A. Power : %d\n",attack_power[i]);
		printf("Stamina: %d\n\n\n",stamina[i]);
		
	}
	i++;
}
	

menu();	
}
	void show_Pokemons(char pokemon_name[10][11],pokemon Pokemons[],int pokemon_count){
		int a=0,i;
		if(pokemon_count==10){
		printf("\n");
		for(i=0;i<10;i++){
			printf("%d - %s\n",i,pokemon_name[Pokemons[i]]);
	
		}
	}
		else{
			printf("****YOUR POCKET***\n");
			
			for(i=0;i<4;i++){
				if(Pokemons[i]==-5)
					printf("%d-This slot is empty!!\n",i);
				else
				printf("%d - %s\n",i,pokemon_name[Pokemons[i]]);
			}
		printf("\n\n");
	}
}
	
	void catch_a_pokemon(char pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons){
		int i;
		printf("Catch a Pokemon:\n");
		int selectpokemon;
			scanf("%d",&selectpokemon);
			if(my_Pokemons[0]!=-5 && my_Pokemons[1]!=-5  && my_Pokemons[2]!=-5  && my_Pokemons[3]!=-5){
				printf("Your pocket is full.Please release a pokemon to choose again!!\n");
			}
else{
			if(selectpokemon==my_Pokemons[0] || selectpokemon==my_Pokemons[1]|| selectpokemon==my_Pokemons[2] || selectpokemon==my_Pokemons[3]){
				printf("You have already %s pokemon\n",pokemon_name[selectpokemon]);
			}
	else{
		for(i=0;i<4;i++){
			if(my_Pokemons[i]==-5){
				my_Pokemons[i]=selectpokemon;
				break;
					}
				}
				
		}
			
		}
		printf("\n\n");
		
	}
	void release_a_pokemon(char pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons){
		printf("Choose which pokemon to release:\n");
		int releasepokemon;
		scanf("%d",&releasepokemon);
		my_Pokemons[releasepokemon]=-5;
		
		printf("\n\n");
	}
	

void menu(){
	int choice;
	int pokemon_count;
	
	char pokemonname[10][11]={
		"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"
	};
	int range[10]={1,3,4,3,2,2,1,2,3,2};
	int attack_power[10]={500,350,300,400,250,250,350,200,350,300};

	int stamina[10]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};

	attack_type type[10]={quadratic,linear,linear,linear,quadratic,linear,quadratic,quadratic,linear,linear};

	pokemon Pokemons[10]={Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby};
	
	pokemon my_Pokemons[4];
	printf("1) Open Pokedex\n");
	printf("2) Go to Oak’s Laboratory\n");
	printf("3) Enter the tournament\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		pokedex(pokemonname,range,type,attack_power,stamina);
		break;
		case 2:
		oaks_laboratory(pokemonname,Pokemons,my_Pokemons);
		break;
	}
}
void oaks_laboratory(char pokemon_name[10][11],pokemon Pokemons[],pokemon *my_Pokemons){
	int i,choice;
	char pokemonname[10][11]={
		"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"
	};
	
	for(i=0;i<4;i++){
		my_Pokemons[i]=-5;
	}
	while(choice!=5){
		int pokemon_count,a;
		printf("\nWelcome to Laboratory of Professor Oak. How can I help you?\n\n");
		printf("1)Show Pokemons\n");
		printf("2)Catch a Pokemon\n");
		printf("3)Release a Pokemon\n");
		printf("4)Show my pocket\n");
		printf("5)Back\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			show_Pokemons(pokemonname,Pokemons,10);
			break;
			case 2:
				show_Pokemons(pokemonname,Pokemons,10);
				catch_a_pokemon(pokemonname,Pokemons,my_Pokemons);
				break;
			case 3:
				show_Pokemons(pokemonname,my_Pokemons,0);
				release_a_pokemon(pokemonname,Pokemons,my_Pokemons);
				break;
			case 4:
				show_Pokemons(pokemonname,my_Pokemons,0);
				break;
			case 5:
				menu();
			break;


		}
	}
}

 

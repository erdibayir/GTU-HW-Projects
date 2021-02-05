#include <cstdlib>
#include <iostream>
#include "Ant.h"
#include "Organism.h"
#include "Grid.h"
#include "PoisonAnt.h"
using namespace std;

Ant::Ant(Grid* n_Grid, int x_, int y_) : Organism(n_Grid, x_, y_){ }

void Ant::create_spring(int x_, int y_){
    new Ant(this->g, x_, y_);
    breed_count = 0;            // Create new offspring
}
Organism_type Ant::get_type() const{
    return ANT;  // Return type of ant
}
void Ant::move(){
    breed_count++; // Increse breed count
    Move_Direction direction = g->random_move(); // Create random move direction
    switch (direction){
        case UP:
            if(g->get_coord(x, y + 1) == NULL && in_grid(x, y + 1)){ // **************
                move_coordinates(x, y + 1);
            }
            break;
        case DOWN:
            if(g->get_coord(x, y - 1) == NULL && in_grid(x, y - 1)){
                move_coordinates(x, y - 1);                         // Test all direction to move
            }
            break;
        case LEFT:
            if(g->get_coord(x - 1, y) == NULL && in_grid(x - 1, y)){
                move_coordinates(x - 1, y);
            }
            break;
        case RIGHT:
            if(g->get_coord(x + 1, y) == NULL && in_grid(x + 1, y)){
                move_coordinates(x + 1, y);                     //***********************
            }
            break;
        default:
            break;
    }
 
}

void Ant::breed(){
    if(breed_count >= BREED_ANTS){
        int Mutaion_Possible = rand() % 100;
        if(Mutaion_Possible <= POSSIBAL_POISON_ANTS){
            if(g->get_coord(x, y + 1) == NULL && in_grid(x, y + 1)){ //***********************
                PoisonAnt *n_Poison = new PoisonAnt(g,x, y+1);
                breed_count = 0;
            }
            else if(g->get_coord(x, y - 1) == NULL && in_grid(x, y - 1)){
                PoisonAnt *n_Poison = new PoisonAnt(g,x, y-1);                      
                breed_count = 0;
            }
            else if(g->get_coord(x - 1, y) == NULL && in_grid(x - 1, y)){//  If mutation realized  create Posion ant
                PoisonAnt *n_Poison = new PoisonAnt(g,x-1, y);
                breed_count = 0;
            } 
            else if(g->get_coord(x + 1, y) == NULL && in_grid(x + 1, y)){
                    PoisonAnt *n_Poison = new PoisonAnt(g,x, x+1);
                    breed_count = 0;                               //**************************
            }
        }
    else
        breed_adjacent(); // If mutaion dont realized create regular offspring ant
    }
     
}

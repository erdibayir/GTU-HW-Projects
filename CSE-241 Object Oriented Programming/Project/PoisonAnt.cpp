#include <cstdlib>

#include <iostream>
#include "PoisonAnt.h"
#include "Organism.h"
#include "Grid.h"
using namespace std;

PoisonAnt::PoisonAnt(Grid* n_Grid, int x_, int y_) : Ant(n_Grid, x_, y_){ }  // Paramater Constructor

void PoisonAnt::move(){
    breed_count++;      
    Move_Direction direction = g->random_move();                    // Move functions same as Ant
    switch (direction){
        case UP:
            if(g->get_coord(x, y + 1) == NULL && in_grid(x, y + 1)){
                move_coordinates(x, y + 1);
            }
            break;
        case DOWN:
            if(g->get_coord(x, y - 1) == NULL && in_grid(x, y - 1)){
                move_coordinates(x, y - 1);
            }
            break;
        case LEFT:
            if(g->get_coord(x - 1, y) == NULL && in_grid(x - 1, y)){
                move_coordinates(x - 1, y);
            }
            break;
        case RIGHT:
            if(g->get_coord(x + 1, y) == NULL && in_grid(x + 1, y)){
                move_coordinates(x + 1, y);
            }
            break;
        default:
            
            break;
    }
}

void PoisonAnt::breed(){
    if(breed_count >= BREED_POISON_ANTS){            // IF andjacent points is not empty  Poison eat other Organim than create  offspring Poison Ant
        bool is_breed = breed_adjacent();
        if(is_breed == false){
            if(g->get_coord(x, y + 1) != NULL){
                if(g->get_coord(x, y + 1)->get_type() == ANT || g->get_coord(x, y + 1)->get_type() == BUG || g->get_coord(x, y + 1)->get_type() == POISON_ANT ){
                    delete g->get_coord(x, y + 1);
                    create_spring(x, y + 1);
                    return;
                }
            }
            if(g->get_coord(x, y - 1) != NULL){
                if(g->get_coord(x, y - 1)->get_type() == ANT  || g->get_coord(x, y -1)->get_type() == BUG || g->get_coord(x, y - 1)->get_type() == POISON_ANT ){
                    delete g->get_coord(x, y - 1);
                    create_spring(x, y - 1);
                    return;
                }
            }
            if(g->get_coord(x + 1, y) != NULL){
                if(g->get_coord(x + 1, y)->get_type() == ANT  || g->get_coord(x + 1, y)->get_type() == BUG || g->get_coord(x + 1,y)->get_type() == POISON_ANT ){
                    delete g->get_coord(x + 1, y);
                   create_spring(x +1, y);
                   return;
                }
            }
            if(g->get_coord(x - 1, y) != NULL){
                if(g->get_coord(x - 1, y)->get_type() == ANT  || g->get_coord(x - 1, y)->get_type() == BUG || g->get_coord(x - 1, y)->get_type() == POISON_ANT ){
                    delete g->get_coord(x - 1, y);
                    create_spring(x - 1,y);
                    return;
                }
            }
        }
    }
}


void PoisonAnt::create_spring(int x_, int y_){
    new PoisonAnt(this->g, x_, y_);
    breed_count = 0;
}
Organism_type PoisonAnt::get_type() const{
    return POISON_ANT;
}
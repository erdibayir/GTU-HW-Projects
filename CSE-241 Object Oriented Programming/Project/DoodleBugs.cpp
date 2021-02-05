#include "DoodleBugs.h"
#include "Organism.h"
using namespace std;

DoodleBugs::DoodleBugs(Grid* n_Grid, int x_, int y_) : Organism(n_Grid, x_, y_){
    is_Poisoned = false;
    poisoned_count = 0;
    death_count = 0;
}
bool DoodleBugs::check_dead() const{
    if(death_count >= STARVE_BUGS){
        return true;
    }
    if(poisoned_count > DEATH_POISON_BUGS){
        return true;
    }
    else{
        return false;
    }
}
void DoodleBugs::create_spring(int x_, int y_){
    new DoodleBugs(this->g, x_, y_);
    breed_count = 0;
}

void DoodleBugs::breed(){
    if(breed_count >= BREED_BUGS){
        breed_adjacent();
    }
    
}
void DoodleBugs::move(){                                    //*********************
    breed_count++;
    death_count++;
    if(is_Poisoned == true){
        poisoned_count++;
    }
    if(g->get_coord(x, y + 1) != NULL){
        if(g->get_coord(x, y + 1)->get_type() == ANT){
            death_count = 0;
            delete g->get_coord(x, y + 1);
            move_coordinates(x, y + 1);
            return;
        }
        else if(g->get_coord(x, y + 1)->get_type() == POISON_ANT){
            death_count = 0;
            is_Poisoned = true;
            delete g->get_coord(x, y + 1);
            move_coordinates(x, y + 1);
            return;
        }
    }
    if(g->get_coord(x, y - 1) != NULL){
        if(g->get_coord(x, y - 1)->get_type() == ANT){
            death_count = 0;
            delete g->get_coord(x, y - 1);
            move_coordinates(x, y - 1);
            return;
        }
        else if(g->get_coord(x, y - 1)->get_type() == POISON_ANT){
            death_count = 0;
            is_Poisoned = true;
            delete g->get_coord(x, y - 1);                  // IF Doddlebugs have adjacent ant, eat the adjacent and move
            move_coordinates(x, y - 1);
            return;
        }
    }
    if(g->get_coord(x - 1, y) != NULL){
        if(g->get_coord(x - 1, y)->get_type() == ANT){
            death_count = 0;
            is_Poisoned = true;
            delete g->get_coord(x - 1, y);
            move_coordinates(x - 1, y);
            return;
        }
        else if(g->get_coord(x - 1, y)->get_type() == POISON_ANT){
            death_count = 0;
            is_Poisoned = true;
            delete g->get_coord(x -1, y );
            move_coordinates(x -1 , y );
            return;
        }
    }
    if(g->get_coord(x + 1, y) != NULL){
        if(g->get_coord(x + 1, y)->get_type() == ANT){
            death_count = 0;
            delete g->get_coord(x + 1, y);
            move_coordinates(x + 1, y);
            return;
        }
        else if(g->get_coord(x + 1, y)->get_type() == POISON_ANT){
            death_count = 0;
            is_Poisoned = true;
            delete g->get_coord(x + 1, y);
            move_coordinates(x + 1, y);
            return;
        }
    }                                               //******************************************
    Move_Direction direction = g->random_move(); // Create Random move direction
    switch (direction){                                         //**************************
        case UP:
            if(g->get_coord(x, y + 1) == NULL && in_grid(x, y + 1)){
                move_coordinates(x, y + 1);
            }
            break;
        case DOWN:
            if(g->get_coord(x, y - 1) == NULL && in_grid(x, y - 1)){
                move_coordinates(x, y - 1);
            }
            break;                                                  // IF doodlebugs dont has adjacent ant,then move like Ant
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
            break;                                                  //**********************
    }
}


Organism_type DoodleBugs::get_type() const{
    return BUG;
}
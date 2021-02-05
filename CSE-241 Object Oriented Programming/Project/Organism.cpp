#include <iostream>
#include "Organism.h"
#include "Grid.h"

Organism::Organism(Grid* n_Grid, int x_, int y_){
    g = n_Grid;
    x = x_;
    y = y_;
    breed_count = 0;
    has_moved = false;
    g->set_coord(x, y, this);
}

void Organism::setMoved(bool hasMoved){
    has_moved = hasMoved;
}

bool Organism::hasMoved() const{
    return has_moved;
}


bool Organism::in_grid(int x_, int y_){ // Check Coordinates in map or not
    return (x_ >= 0) && (x_ < GRIDSIZE) && (y_ >= 0) && (y_ < GRIDSIZE);
}
bool Organism::check_dead() const{ // Check Organism is dead or not
    return false;
}
void Organism::move_coordinates(int x_, int y_){ // Change grid cordinates

        g->set_coord(x_, y_, g->get_coord(x, y));
    
        g->set_coord(x, y, NULL);
        
        x = x_;
        y = y_;
    
    g->get_coord(x, y)->setMoved(true);
}

bool Organism::breed_adjacent(){  // Create new offspring of Organism.
    if((g->get_coord(x, y + 1) == NULL) && in_grid(x, y + 1))
    {
        create_spring(x, y + 1); // Craate new offspring
        return true;
    }
    else if((g->get_coord(x, y - 1) == NULL) && in_grid(x, y - 1))
    {
        create_spring(x, y - 1);
        return true;
    }
    else if((g->get_coord(x - 1, y) == NULL)  && in_grid(x - 1, y))
    {
        create_spring(x - 1, y);
        return true;
    }
    else if((g->get_coord(x + 1, y) == NULL)  && in_grid(x + 1, y))
    {
        create_spring(x + 1, y);
        return true;
    }
    else{
        return false;
    }
}


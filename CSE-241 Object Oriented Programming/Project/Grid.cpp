#include <iostream>
#include <cstdlib> 
#include "Grid.h"
#include "Ant.h"
#include "DoodleBugs.h"
using namespace std;
Grid::Grid(){                               // Make all organism NULL in  array
    for (int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            grid[i][j] = NULL;
        }
    }
    create_new_Organism(ANT, INITIAL_ANTS); // Create initial Ants
    create_new_Organism(BUG, INITIAL_BUGS);  // Create initial Doodlebugs
}

Organism* Grid::get_coord(int x, int y) const{
    if ((x >= 0) && (x < GRIDSIZE) && (y >= 0) && (y < GRIDSIZE)) {
        return grid[x][y];
    } else {
        return NULL;
    }
}


Grid::~Grid(){                      // Delete All organism
    for (int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            if (grid[i][j] != NULL){
                delete grid[i][j];
            }
        }
    }
}
void Grid::simulation(){                   
    for(int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            if(grid[i][j] != NULL){
                grid[i][j]->setMoved(false);
            }
        }
    }

    Organism_move(BUG);                         // Move Doodlebugs firstly
    Organism_move(ANT);                         // Move Ant 
    Organism_move(POISON_ANT);                  // Move poison ant
     for (int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            if ((grid[i][j] != NULL) && grid[i][j]->check_dead()){
                delete grid[i][j];
                grid[i][j] = NULL;
            }
        }
    }
    Organism_breed();                   // Breed All Organism
}
Position Grid::random_poz() const{
    Position p;
    p.x = rand() % GRIDSIZE;
    p.y = rand() % GRIDSIZE;
    return p;
}


Move_Direction Grid::random_move() const{
    return static_cast<Move_Direction>(rand() % 4);
}
void Grid::create_new_Organism(Organism_type type_, int count){
    int org_count = 0;
    while (org_count < count){
        Position p = random_poz();
        if (grid[p.x][p.y] == NULL){
            org_count++;
            if (type_ == ANT){
                new Ant(this, p.x, p.y);
            }
            else if (type_ == BUG){
                new DoodleBugs(this, p.x, p.y);
            }
        }
    }
}

void Grid::print() const{                       // Display in screen all Organism
    for (int j = 0; j < GRIDSIZE; j++){
        for (int i = 0; i < GRIDSIZE; i++){
            if (grid[i][j] == NULL){
                cout << ". ";
            } else {
                if (grid[i][j]->get_type() == ANT){
                    cout << "o ";
                }
                else if (grid[i][j]->get_type() == BUG){
                    cout << "X ";
                }
                else if (grid[i][j]->get_type() == POISON_ANT){
                    cout << "c ";
                }
            }
        }
        cout << endl;
    }
}
void Grid::set_coord(int x, int y, Organism* org){
    if ((x >= 0) && (x < GRIDSIZE) && (y >= 0) && (y < GRIDSIZE)) {
        grid[x][y] = org;
    }
}



void Grid::Organism_move(Organism_type type_){
    for(int i = 0; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            if(grid[i][j] != NULL){
                if(grid[i][j]->get_type() == type_ && !(grid[i][j]->hasMoved())){
                    grid[i][j]->move();
                }
            }
        }
    }
}
void Grid::Organism_breed(){
    for(int i = 0; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            if(grid[i][j] != NULL){
                grid[i][j]->breed();
            }
        }
    }
}
#ifndef Ant_h
#define Ant_h
#include <iostream>
#include "Organism.h"
#include "Grid.h"
class Ant : public Organism{
public:
    
    Ant(Grid* n_Grid, int x_, int y_);
    Organism_type get_type() const;
    void create_spring(int x_, int y_); // Create new offspring of Ant
    void move(); // Move Ant in Grid
    void breed(); // Breed Ant in Grid
    
};

#endif 

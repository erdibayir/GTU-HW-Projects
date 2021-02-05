#ifndef PoisonAnt_h
#define PoisonAnt_h
#include <iostream>
#include "Ant.h"
#include "Grid.h"

class PoisonAnt : public Ant{
public:
    
    PoisonAnt(Grid* n_Grid, int x_, int y_); // Paramater Constructor
    Organism_type get_type() const; // Return Poison Ant type
    void create_spring(int x_, int y_); // Create Poison Ant offspring
    void move();    // Move for Poison Ant
    void breed();   // Breed for Poison Ant
};

#endif 
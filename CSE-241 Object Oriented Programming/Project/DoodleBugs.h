#ifndef Doodlebugs_h
#define Doodlebugs_h
#include <iostream>
#include "Grid.h"
#include "Organism.h"

class DoodleBugs : public Organism{
public:
    DoodleBugs(Grid* aGrid, int x_, int y_);
    bool check_dead() const; // Check Doodlebugs is died or alive
    void create_spring(int whereX, int whereY); // Create DoodleBugs offspring
    void move();
    void breed();
    Organism_type get_type() const;
    
    
private:
    int poisoned_count; // If Doodlebugs eat Poison Ant poisoned_count is increased
    bool is_Poisoned;   // If Doodlebugs eat Poison Ant is_Poisoned must be true
    int death_count;    // Dead counter for starve
};

#endif 

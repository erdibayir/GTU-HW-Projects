#ifndef GRID_H
#define GRID_H
#include "Organism.h"

enum Move_Direction{UP = 0, DOWN, LEFT, RIGHT};

const int GRIDSIZE = 15;  // Grid Size
const int INITIAL_ANTS = 100; // İnitial number of ants
const int INITIAL_BUGS = 5;
const int BREED_ANTS = 3;
const int BREED_POISON_ANTS = 4;
const int POSSIBAL_POISON_ANTS = 5; // Possible of become Poison ant  % 5
const int BREED_BUGS = 8; // Number of breed Doodlebugs
const int STARVE_BUGS = 3; // Number of Starve  Doodlebugs
const int DEATH_POISON_BUGS = 2;

struct Position{
    int x;
    int y;
};

class Grid{
    public:
        Grid();
        ~Grid();
        Organism* get_coord(int x, int y) const;
        void set_coord(int x, int y, Organism* org);
        Position random_poz() const;
        Move_Direction random_move() const;
        void create_new_Organism(Organism_type type_, int count);
        void Organism_move(Organism_type type_); // Move all Organism
        void print() const;
        void simulation(); // Simualiton for move and breed
       
        void Organism_breed(); // Breed all organism

    private:
        Organism* grid[GRIDSIZE][GRIDSIZE];
};
#endif

#ifndef Organism_h
#define Organism_h
enum Organism_type {ANT, BUG,POISON_ANT};
class Grid;

class Organism{
    public:
        Organism(Grid* n_Grid, int x_, int y_); // Paramater Constructor
        virtual ~Organism() { } // Destructor
        virtual void move() = 0; // Pure virtual move function.
        virtual void breed() = 0; // Pure virtual move function.
        virtual Organism_type get_type() const = 0; // Return type of Organism.
        bool in_grid(int x_, int y_);
        virtual void create_spring(int x_, int y_) = 0;
        void move_coordinates(int x_, int y_);
        bool breed_adjacent();
        void setMoved(bool hasMoved); // Set has_moved variable
        bool hasMoved() const; // Return has_moved
        virtual bool check_dead() const;
        
    protected:
        int x;  // This variable keeps x coordinates for Class.
        int y; //  This variable keeps y coordinates for Class.
        bool has_moved; // This variable keeps the object whether it moves.
        int breed_count; // It is a  counter that when Organism will breed.
        Grid* g;
};

#endif

#ifndef abstractboard_h
#define abstractboard_h

struct space_cord{ // From HW1

		int spaceX; // this structure hold X and Y cordinates of space room
		int spaceY;
};
namespace Puzzle{
class AbstractBoard{
public:
    virtual void print() =0;
    virtual void readfromfile(std::string load_name) =0;
    virtual void writeToFile()=0;
    virtual space_cord reset(space_cord cord)=0;
    virtual space_cord setsize(int size)=0;
    virtual space_cord move(char  move , space_cord cord)=0;
    virtual int operator() (int i , int j)= 0;
    virtual bool isSolved()=0;
    virtual int number_of_moves()=0;
    bool operator==(AbstractBoard&);

    };
}

#endif
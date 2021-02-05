#include <iostream>
#include <ctime>
#include "Grid.h"
using namespace std;

int main(){
    srand(time(NULL));
    Grid m_grid; // Create Grid Object
    string input;
    while (true){ 
        m_grid.print();
        m_grid.simulation();
        getline(cin,input);
    }
    return 0;
}

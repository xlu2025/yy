#include "organism.hpp"

// Constructor to initialize the organism's position and steps
Organism::Organism(int r, int c)
    : row(r), col(c), steps(0), moved(false) {}

// Get the row position of the organism
int Organism::getRow() const {
    return row;
}

// Get the column position of the organism
int Organism::getCol() const {
    return col;
}

// Check if the organism has moved in the current time step
bool Organism::hasMoved() const {
    return moved;
}

// Set the moved status of the organism
void Organism::setMoved(bool movedStatus) {
    moved = movedStatus;
}

#pragma once
using namespace std;
class Simulation; // Forward declaration

enum OrganismType { MALE_ANT, FEMALE_ANT, QUEEN_ANT, DOODLEBUG };

class Organism {
protected:
    int row;
    int col;
    int steps;
    bool moved;

public:
    Organism(int r, int c);
    virtual ~Organism() = default;

    virtual void move(Simulation* sim) = 0;
    virtual void breed(Simulation* sim) = 0;
    virtual void starve(Simulation* sim) = 0;

    int getRow() const;
    int getCol() const;
    bool hasMoved() const;
    void setMoved(bool moved);

    virtual OrganismType getType() const = 0;
    virtual char getSymbol() const = 0;
};

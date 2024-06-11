#pragma once


#include "organism.hpp"

class DoodleBug : public Organism {
private:
    int starveSteps;

public:
    DoodleBug(int r, int c);
    void move(Simulation* sim) override;
    void breed(Simulation* sim) override;
    void starve(Simulation* sim) override;
    OrganismType getType() const override { return DOODLEBUG; }
    char getSymbol() const override { return 'X'; }
};



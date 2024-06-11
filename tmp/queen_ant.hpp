#pragma once


#include "ant.hpp"

class QueenAnt : public Ant {
private:
    bool mated;
    int breedSteps;

public:
    QueenAnt(int r, int c);
    void move(Simulation* sim) override;
    void breed(Simulation* sim) override;
    void starve(Simulation* sim) override;
    char getSymbol() const override { return 'Q'; }
};



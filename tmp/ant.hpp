#pragma once

#include "organism.hpp"

class Simulation; // Forward declaration

class Ant : public Organism {
private:
    bool isMale;

public:
    Ant(int r, int c, bool male);
    void move(Simulation* sim) override;
    void breed(Simulation* sim) override;
    void starve(Simulation* sim) override;
    OrganismType getType() const override { return isMale ? MALE_ANT : FEMALE_ANT; }
    char getSymbol() const override { return isMale ? 'o' : 'w'; } // 根据性别打印符号
};

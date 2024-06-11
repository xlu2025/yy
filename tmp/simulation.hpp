#pragma once

#include "organism.hpp"
#include <vector>

class Simulation {
private:
    int rows;
    int cols;
    int time_steps;
    std::vector<std::vector<Organism*>> grid;
    int numAnts;
    int numDoodlebugs;
    int numQueens;

public:
    Simulation(int r, int c, int steps, int ants, int doodlebugs, int queens)
        : rows(r), cols(c), time_steps(steps), numAnts(ants), numDoodlebugs(doodlebugs), numQueens(queens) {
        grid.resize(rows, std::vector<Organism*>(cols, nullptr));
    }
    ~Simulation();

    void initialize(int numMaleAnts, int numFemaleAnts, int numQueens, int numDoodlebugs);
    void simulate();
    void printGrid() const;

    bool isInBounds(int r, int c) const;
    bool isCellEmpty(int r, int c) const;
    bool isAnt(int r, int c) const;

    void moveOrganism(int oldRow, int oldCol, int newRow, int newCol);
    void addOrganism(Organism* org);
    void removeOrganism(int r, int c);
    bool checkExtinction() const {
        return numAnts == 0 || numDoodlebugs == 0 || numQueens == 0;
    }
};

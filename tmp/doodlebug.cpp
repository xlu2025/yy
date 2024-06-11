#include "doodlebug.hpp"
#include "simulation.hpp"
#include <cstdlib>
#include <ctime>

DoodleBug::DoodleBug(int r, int c) : Organism(r, c), starveSteps(0) {}

// Move method for DoodleBug
void DoodleBug::move(Simulation* sim) {
    static const int directions[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Up, Down, Left, Right
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // 4 corners
    };

    for (int i = 0; i < 8; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (sim->isInBounds(newRow, newCol) && sim->isAnt(newRow, newCol)) {
            sim->moveOrganism(row, col, newRow, newCol);
            row = newRow;
            col = newCol;
            starveSteps = 0;
            moved = true;
            steps++;
            return;
        }
    }

    // If no ants to eat, move to an empty cell
    int dir = rand() % 8;
    int newRow = row + directions[dir][0];
    int newCol = col + directions[dir][1];

    if (sim->isInBounds(newRow, newCol) && sim->isCellEmpty(newRow, newCol)) {
        sim->moveOrganism(row, col, newRow, newCol);
        row = newRow;
        col = newCol;
    }
    moved = true;
    steps++;
    starveSteps++;
}

// Breed method for DoodleBug
void DoodleBug::breed(Simulation* sim) {
    if (steps >= 10) {
        static const int directions[16][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // Up, Down, Left, Right
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, // 4 corners
            {-2, 0}, {2, 0}, {0, -2}, {0, 2},  // 2 steps in 4 main directions
            {-2, -2}, {-2, 2}, {2, -2}, {2, 2} // 2 steps in 4 diagonal directions
        };

        for (int i = 0; i < 16; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (sim->isInBounds(newRow, newCol) && sim->isCellEmpty(newRow, newCol)) {
                sim->addOrganism(new DoodleBug(newRow, newCol));
                steps = 0;
                break;
            }
        }
    }
}

// Starve method for DoodleBug
void DoodleBug::starve(Simulation* sim) {
    if (starveSteps >= 20) {
        sim->removeOrganism(row, col);
    }
}

#include "queen_ant.hpp"
#include "simulation.hpp"
#include <cstdlib>
#include <ctime>

QueenAnt::QueenAnt(int r, int c) : Ant(r, c,0), mated(false), breedSteps(0) {}

// Move method for QueenAnt
void QueenAnt::move(Simulation* sim) {
    if (!mated) {
        return; // Queen doesn't move until it has mated
    }
    Ant::move(sim);
}

// Breed method for QueenAnt
void QueenAnt::breed(Simulation* sim) {
    if (breedSteps >= 30) {
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
                // 设置种子，以确保每次运行生成不同的随机数序列
                srand(time(nullptr));

                // 生成随机数
                int random_number = rand();

                // 将随机数模2得到0或1
                int isMale = random_number % 2;
                sim->addOrganism(new Ant(newRow, newCol,isMale));
            }
        }

        breedSteps = 0;
    }
    else {
        breedSteps++;
    }
}

// Starve method for QueenAnt
void QueenAnt::starve(Simulation* sim) {
    // QueenAnts do not starve
}

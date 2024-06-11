#include "simulation.hpp"
#include <iostream>

int main() {
    int rows = 100;
    int cols = 100;
    int time_steps = 10; // 或任何你想要模拟的步数

    int numMaleAnts, numFemaleAnts, numQueens, numDoodlebugs;
    cout << "Enter the number of male ants: ";
    cin >> numMaleAnts;
    cout << "Enter the number of female ants: ";
    cin >> numFemaleAnts;
    cout << "Enter the number of queen ants: ";
    cin >> numQueens;
    cout << "Enter the number of doodlebugs: ";
    cin >> numDoodlebugs;

    Simulation sim(rows, cols, time_steps, numMaleAnts+ numFemaleAnts, numDoodlebugs,numQueens);
    sim.initialize(numMaleAnts, numFemaleAnts, numQueens, numDoodlebugs);
    sim.simulate();

    return 0;
}

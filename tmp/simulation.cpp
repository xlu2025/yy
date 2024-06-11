#include "simulation.hpp"
#include "ant.hpp"
#include "queen_ant.hpp"
#include "doodlebug.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>



Simulation::~Simulation() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete grid[i][j];
        }
    }
}

void Simulation::initialize(int numMaleAnts, int numFemaleAnts, int numQueens, int numDoodlebugs) {
    srand(time(0));

    // �������
    for (int i = 0; i < numMaleAnts; ++i) {
        int r = rand() % rows;
        int c = rand() % cols;
        while (grid[r][c] != nullptr) {
            r = rand() % rows;
            c = rand() % cols;
        }
        grid[r][c] = new Ant(r, c, true);
    }

    // ��Ӵ���
    for (int i = 0; i < numFemaleAnts; ++i) {
        int r = rand() % rows;
        int c = rand() % cols;
        while (grid[r][c] != nullptr) {
            r = rand() % rows;
            c = rand() % cols;
        }
        grid[r][c] = new Ant(r, c, false);
    }

    // ����Ϻ�
    for (int i = 0; i < numQueens; ++i) {
        int r = rand() % rows;
        int c = rand() % cols;
        while (grid[r][c] != nullptr) {
            r = rand() % rows;
            c = rand() % cols;
        }
        grid[r][c] = new QueenAnt(r, c);
    }

    // ���ʳ����
    for (int i = 0; i < numDoodlebugs; ++i) {
        int r = rand() % rows;
        int c = rand() % cols;
        while (grid[r][c] != nullptr) {
            r = rand() % rows;
            c = rand() % cols;
        }
        grid[r][c] = new DoodleBug(r, c);
    }
}

void Simulation::simulate() {
    for (int t = 0; t < time_steps; ++t) {
        if (checkExtinction()) {
            std::cout << "One species extinct. Simulation stopped.\n";
            break;
        }
        // ���ƶ�����ʳ����
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr && grid[i][j]->getType() == DOODLEBUG) {
                    grid[i][j]->move(this);
                }
            }
        }

        // �ƶ���������
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr && (grid[i][j]->getType() == MALE_ANT || grid[i][j]->getType() == FEMALE_ANT || grid[i][j]->getType() == QUEEN_ANT)) {
                    grid[i][j]->move(this);
                }
            }
        }

        // ������������ķ�ֳ�ͼ���
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != nullptr) {
                    grid[i][j]->breed(this);
                    grid[i][j]->starve(this);
                }
            }
        }

        // ��ӡ����
        printGrid();
    }
}

void Simulation::printGrid() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == nullptr) {
                cout << ".";
            }
            else {
                cout << grid[i][j]->getSymbol();
            }
        }
        cout << endl;
    }
    cout << "\n\n\n\n\n\n";
}

bool Simulation::isInBounds(int r, int c) const {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool Simulation::isCellEmpty(int r, int c) const {
    return grid[r][c] == nullptr;
}

bool Simulation::isAnt(int r, int c) const {
    return grid[r][c] != nullptr && (grid[r][c]->getType() == MALE_ANT || grid[r][c]->getType() == FEMALE_ANT || grid[r][c]->getType() == QUEEN_ANT);
}

void Simulation::moveOrganism(int oldRow, int oldCol, int newRow, int newCol) {
    grid[newRow][newCol] = grid[oldRow][oldCol];
    grid[oldRow][oldCol] = nullptr;
}

void Simulation::addOrganism(Organism* org) {
    grid[org->getRow()][org->getCol()] = org;
}

void Simulation::removeOrganism(int r, int c) {
    delete grid[r][c];
    grid[r][c] = nullptr;
}

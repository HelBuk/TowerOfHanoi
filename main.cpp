#include "hanoi.hpp"
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Tower of Hanoi - 3 rods.\n";
    std::cout << "Number of disks: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input. Using default: 4\n";
        n = 4;
    }

    Towers towers;
    for (int disk = n; disk >= 1; --disk) 
        towers.source.push_back(disk);

    std::cout << "\nInitial state:\n";
    printState(towers);

    hanoi(n,
          towers.source, towers.auxiliary, towers.target,
          "Source", "Auxiliary", "Target",
          towers); // `towers` is used for visualization

    std::cout << "Done.\n";
}
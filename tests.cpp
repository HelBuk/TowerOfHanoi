#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "hanoi.hpp"

bool isValidRod(const std::vector<int>& rod) {
    // Rod is stored largest -> smallest, so each next disk should be smaller.
    for (std::size_t i = 1; i < rod.size(); ++i) {
        if (rod[i - 1] < rod[i]) {
            return false;
        }
    }
    return true;
}

bool isValidTowerState(const Towers& towers) {
    return isValidRod(towers.source)
        && isValidRod(towers.auxiliary)
        && isValidRod(towers.target);
}

Towers makeInitialTowers(int n) {
    Towers towers;

    for (int disk = n; disk >= 1; --disk) {
        towers.source.push_back(disk);
    }

    return towers;
}

void testInitialTowerSetup() {
    Towers towers = makeInitialTowers(4);

    assert((towers.source == std::vector<int>{4, 3, 2, 1}));
    assert(towers.auxiliary.empty());
    assert(towers.target.empty());
    assert(isValidTowerState(towers));
}

void testMoveDisk() {
    Towers towers;
    towers.source = {3, 2, 1};

    moveDisk(towers.source, towers.target,
             "Source", "Target",
             towers);

    assert((towers.source == std::vector<int>{3, 2}));
    assert((towers.target == std::vector<int>{1}));
    assert(isValidTowerState(towers));
}


int main() {
    testInitialTowerSetup();
    testMoveDisk();
    std::cout << "All tests passed.\n";
    return 0;
}
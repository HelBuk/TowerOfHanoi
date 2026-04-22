#include <iostream>
#include <vector>
#include <string>

// Tower of Hanoi: recursive solution.
// Allows user to setup a number of disks (> 0). 
// If smaller or equal to 0 - program uses default - 4.

struct Towers {
    std::vector<int> source;
    std::vector<int> auxiliary;
    std::vector<int> target;
};

void printRod(const std::string& name, const std::vector<int>& rod) {
    std::cout << name << ": ";
    for (int disk : rod) std::cout << disk << ' ';
    std::cout << '\n';
}

void printState(const Towers& t) {
    printRod("Source",    t.source);
    printRod("Auxiliary", t.auxiliary);
    printRod("Target",    t.target);
    std::cout << '\n';
}

void moveDisk(std::vector<int>& from, std::vector<int>& to,
              std::string_view fromName, std::string_view toName,
              const Towers& towers) {
    int disk = from.back();
    from.pop_back();
    to.push_back(disk);
    std::cout << "Move disk " << disk << " from " << fromName << " to " << toName << '\n';
    printState(towers);
}

void hanoi(int n,
           std::vector<int>& source, std::vector<int>& auxiliary, std::vector<int>& target,
           std::string_view sourceName, std::string_view auxiliaryName, std::string_view targetName,
           Towers& towers) {
    if (n == 0) return;

    // recursion:  `source` -> `auxiliary`
    hanoi(n - 1, source, target, auxiliary,
          sourceName, targetName, auxiliaryName, towers);

    // Move the largest remaining disk from source to target.
    moveDisk(source, target, sourceName, targetName, towers);
    
     // recursion:  `auxiliary` -> `target`
    hanoi(n - 1, auxiliary, source, target,
          auxiliaryName, sourceName, targetName, towers);
}

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
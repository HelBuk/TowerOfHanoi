#ifndef HANOI_HPP
#define HANOI_HPP

#include <string_view>
#include <vector>

struct Towers {
    std::vector<int> source;
    std::vector<int> auxiliary;
    std::vector<int> target;
};

void printState(const Towers& towers);

void moveDisk(std::vector<int>& from,
              std::vector<int>& to,
              std::string_view fromName,
              std::string_view toName,
              const Towers& towers);

void hanoi(int n,
           std::vector<int>& source,
           std::vector<int>& auxiliary,
           std::vector<int>& target,
           std::string_view sourceName,
           std::string_view auxiliaryName,
           std::string_view targetName,
           Towers& towers);

#endif
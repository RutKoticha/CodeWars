/**
 * @file 198_House_Robber.cpp
 * @author Rut Koticha
 * @date 2025-12-29
 * @brief Not brief-able, just look at the notes
 */

#include <vector>

class Solution {
public:
  int rob(std::vector<int>& houses)
  {
    size_t totalHouses = houses.size();

    switch (totalHouses)
    {
    case 1:
      return houses.front();
    case 2:
      return std::max(houses.front(), houses.back());
    case 3:
      return std::max(houses.front() + houses.back(), houses.at(1));
    }

    std::vector<int> profit = houses;

    profit.at(2) = std::max(houses.at(0) + houses.at(2), houses.at(1));

    for (int i = 3; i < totalHouses; i++)
    {
      int current = houses.at(i);
      int previous = profit.at(i - 1);
      int previousInCycle = profit.at(i - 2);
      int previousInSeparateCycle = profit.at(i - 3);

      int maxInBothCycles = std::max(previousInCycle, previousInSeparateCycle);

      profit.at(i) = std::max(maxInBothCycles + current, previous);
    }

    return profit.back();
  }
};

/**
 * @file 213_House_Robber_II.cpp
 * @author Rut Koticha
 * @date 2025-12-31
 */

#include <vector>
#include <algorithm>

class Solution {
private:
  int CalculateProfit(const std::vector<int>& profit, size_t i)
  {
    int current = profit.at(i);
    int previous = profit.at(i - 1);
    int previousInCycle = profit.at(i - 2);
    int previousInSeparateCycle = profit.at(i - 3);

    int maxInBothCycles = std::max(previousInCycle, previousInSeparateCycle);

    return std::max(maxInBothCycles + current, previous);
  }

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
      return *(std::max_element(houses.begin(), houses.end()));
    }

    std::vector<int> profitFront = houses;
    profitFront.back() = 0;
    profitFront.at(2) = std::max(houses.at(0) + houses.at(2), houses.at(1));

    std::vector<int> profitBack = houses;
    profitBack.front() = 0;
    profitBack.at(2) = std::max(houses.at(2), houses.at(1));

    int  current, previous, previousInCycle, previousNotInCycle, maxInBothCycles;
    for (int i = 3; i < totalHouses; i++)
    {
      /* <---------- Calculate for front taking version ----------> */
      profitFront.at(i) = CalculateProfit(profitFront, i);

      /* <---------- Calculate for back taking version ----------> */
      profitBack.at(i) = CalculateProfit(profitBack, i);
    }

    return std::max(profitFront.back(), profitBack.back());
  }
};

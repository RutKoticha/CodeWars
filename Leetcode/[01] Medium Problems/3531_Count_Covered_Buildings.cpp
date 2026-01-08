/**
 * @file 3531_Count_Covered_Buildings.cpp
 * @author Rut Koticha
 * @date 2025-12-11
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
  int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings)
  {
    using Coordinate = std::pair<int, int>;

    int totalBuildings = buildings.size();
    std::unordered_map<int, std::vector<Coordinate>> buildingsPerX;
    std::unordered_map<int, std::vector<Coordinate>> buildingsPerY;

    for (auto buildingCoords : buildings)
    {
      buildingsPerX[buildingCoords[0]].push_back({ buildingCoords[0], buildingCoords[1] });
      buildingsPerY[buildingCoords[1]].push_back({ buildingCoords[0], buildingCoords[1] });
    }

    for (auto buildingCoords : buildings)
    {
      int x = buildingCoords[0], y = buildingCoords[1];
    }
  }
};

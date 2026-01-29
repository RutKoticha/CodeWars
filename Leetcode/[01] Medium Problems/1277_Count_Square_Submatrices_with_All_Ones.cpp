/**
 * @file 1277_Count_Square_Submatrices_with_All_Ones.cpp
 * @author Rut Koticha
 * @date 2026-01-28
 */

#include <vector>

class Solution {
private:
  std::vector<std::vector<int>> totalSquares;
  int m_MaximumX, m_MaximumY;

private:
  int GetMin(int x, int y)
  {
    bool outOfUpSide = x <= 0;
    bool outOfLeftSide = y <= 0;

    if (outOfLeftSide || outOfUpSide)
      return 0;

    int upValue = totalSquares.at(x - 1).at(y);
    int leftValue = totalSquares.at(x).at(y - 1);
    int leftUpValue = totalSquares.at(x - 1).at(y - 1);

    return std::min(std::min(leftValue, leftUpValue), upValue);
  }

public:
  int countSquares(std::vector<std::vector<int>>& matrix)
  {
    totalSquares = matrix;
    this->m_MaximumX = matrix.size() - 1;
    this->m_MaximumY = matrix.front().size() - 1;

    int sum = 0;
    for (int x = 0; x <= m_MaximumX; x++)
    {
      for (int y = 0; y <= m_MaximumY; y++)
      {
        if (!totalSquares.at(x).at(y))
          continue;

        totalSquares.at(x).at(y) = GetMin(x, y) + 1;
        sum += totalSquares.at(x).at(y);
      }
    }

    return sum;
  }
};

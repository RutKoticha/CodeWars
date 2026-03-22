/**
 * @file 70_Climbing_Stairs.cpp
 * @author Rut Koticha
 * @date 2025-12-29
 * @brief Its just fibonacci sequence, just do rough work
 */

#include <vector>

class Solution {
public:
  int climbStairs(int n)
  {
    unsigned int previousWays = 1;
    unsigned int currentWays = 2;
    unsigned int nextWays;

    for (int i = 2; i <= n; i++)
    {
      nextWays = currentWays + previousWays;
      previousWays = currentWays;
      currentWays = nextWays;
    }

    return previousWays;
  }
};

/**
 * @file 2211_Count_Collisions_on_a_Road.cpp
 * @author Rut Koticha
 * @date 2025-12-04
 */

#include <string>

class Solution
{
public:
  int countCollisions(std::string directions)
  {
    int totalCollisions = 0;

    const int totalDirections = directions.length();
    for (int i = 1; i < totalDirections; i++)
    {
      if ((directions[i] == 'L' && directions[i - 1] == 'R'))
      {
        totalCollisions += 2;
        directions[i] = 'S';
        i++;
      }

      if ((directions[i] == 'S' && directions[i - 1] == 'R'))
      {
        totalCollisions++;
        directions[i - 1] = 'S';
      }
      else if ((directions[i - 1] == 'S' && directions[i] == 'L'))
      {
        totalCollisions++;
        directions[i] = 'S';
      }
    }

    return totalCollisions;
  }
};

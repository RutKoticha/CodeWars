/**
 * @file 7_Reverse_Integer.cpp
 * @author Rut Koticha
 * @date 2026-02-02
 */

#include <cstdint>
#include <climits>
#include <cmath>

class Solution {
public:
  int32_t reverse(int32_t number)
  {
    int32_t reversed = 0, remainder = 0;

    while (number)
    {
      if (std::abs(reversed) >= (INT32_MAX / 10))
        return 0;

      remainder = number % 10;
      reversed = (10 * reversed) + remainder;
      number /= 10;
    }

    return reversed;
  }
};

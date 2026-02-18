/**
 * @file 693_Binary_Number_with_Alternating_Bits.cpp
 * @author Rut Koticha
 * @date 2026-02-19
 */

#include <cstdint>

class Solution {
public:
  bool hasAlternatingBits(int n)
  {
    uint32_t shiftedN = n >> 1;

    uint32_t andResult = n & shiftedN;
    uint32_t orResult = n | shiftedN;

    uint32_t maxedN = 1;
    while (n)
    {
      maxedN <<= 1;
      n >>= 1;
    }

    maxedN -= 1;

    bool andResult0 = !andResult;
    bool orResultMaxed = orResult == maxedN;

    return andResult0 && orResultMaxed;
  }
};

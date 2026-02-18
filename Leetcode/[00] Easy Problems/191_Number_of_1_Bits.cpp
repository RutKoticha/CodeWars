/**
 * @file 191_Number_of_1_Bits.cpp
 * @author Rut Koticha
 * @date 2026-02-19
 */

class Solution {
public:
  int hammingWeight(int n)
  {
    int total1Bits = 0;

    while (n)
    {
      total1Bits += (n & 1);
      n >>= 1;
    }

    return total1Bits;
  }
};

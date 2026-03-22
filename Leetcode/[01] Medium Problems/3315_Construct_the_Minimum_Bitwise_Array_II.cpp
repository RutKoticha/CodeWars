/**
 * @file 3315_Construct_the_Minimum_Bitwise_Array_II.cpp
 * @author Rut Koticha
 * @date 2026-01-21
 * @brief Find the last consecutive 1 from the end and flip it
 */

#include <vector>
#include <bitset>

static const int TOTAL_BITS = 32;

class Solution {
public:
  std::vector<int> minBitwiseArray(std::vector<int>& nums)
  {
    std::vector<int> answer;

    for (int& number : nums)
    {
      std::bitset<32> bits(number);
      if (!bits.test(0))
      {
        answer.push_back(-1);
        continue;
      }

      for (int i = 1; i < 32; i++)
      {
        if (!bits.test(i))
        {
          answer.push_back(bits.reset(i - 1).to_ulong());
          break;
        }
      }
    }

    return answer;
  }
};

/**
 * @file 961_N_Repeated_Element_in_Size_2N_Array.cpp
 * @author Rut Koticha
 * @date 2026-01-02
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
  int repeatedNTimes(std::vector<int>& nums)
  {
    int totalNumbers = nums.size();
    int requiredFrequency = totalNumbers >> 1;

    std::unordered_map<int, int> frequency;

    for (int& num : nums)
      frequency[num]++;

    for (auto [number, freq] : frequency)
    {
      if (freq >= requiredFrequency)
        return number;
    }

    return -1;
  }
};

/**
 * @file 39_Combination_Sum.cpp
 * @author Rut Koticha
 * @date 2025-11-03
 */

#include <vector>
#include <set>

class Solution {
private:
  std::vector<int> m_Candidates;
  int m_Target;
  std::set<std::vector<int>> m_Combinations;

  void FindCombinations(int currentSum = 0, std::vector<int> combination = {}, int index = 0)
  {
    if (currentSum == this->m_Target)
      m_Combinations.insert(combination);

    if (currentSum > this->m_Target)
      return;

    if (index >= this->m_Candidates.size())
      return;

    // Take
    combination.push_back(this->m_Candidates.at(index));
    FindCombinations(currentSum + this->m_Candidates.at(index), combination, index);
    combination.pop_back();

    // Not take
    FindCombinations(currentSum, combination, index + 1);
  }

public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
  {
    this->m_Candidates = candidates;
    this->m_Target = target;

    FindCombinations();

    return std::vector<std::vector<int>>(this->m_Combinations.begin(), this->m_Combinations.end());
  }
};

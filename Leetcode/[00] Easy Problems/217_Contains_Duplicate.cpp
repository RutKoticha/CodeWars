/**
 * Author: Rut Koticha
 * Date: 2025-07-09 22:04
 */

#include <set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::set<int> numbersSet;

    for (auto &&number : nums) {
      if (numbersSet.find(number) != numbersSet.end()) {
        return false;
      }
      numbersSet.insert(number);
    }

    return true;
  }
};

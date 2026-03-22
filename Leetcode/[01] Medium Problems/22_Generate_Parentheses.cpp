/**
 * Author: Rut Koticha
 * Date: 2025-07-22 19:57
 */

#include <iostream>
#include <set>
#include <vector>

class Solution {
private:
  std::set<std::string> findAllCombinations(short n) {
    if (n == 1) {
      return {"()"};
    }

    std::set<std::string> nCombinations = {};
    std::set<std::string> oneLessThanNCombinations =
        this->findAllCombinations(n - 1);

    for (std::string combination : oneLessThanNCombinations) {
      nCombinations.insert("(" + combination + ")");
      nCombinations.insert("()" + combination);
      nCombinations.insert(combination + "()");
    }

    return nCombinations;
  }

public:
  std::vector<std::string> generateParenthesis(int n) {
    std::set<std::string> allCombinations = findAllCombinations(n);
    std::vector<std::string> allCombinationsVector(allCombinations.begin(),
                                                   allCombinations.end());
    return allCombinationsVector;
  }
};

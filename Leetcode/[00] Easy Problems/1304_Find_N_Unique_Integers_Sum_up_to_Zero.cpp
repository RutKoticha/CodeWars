/**
 * Author: Rut Koticha
 * Date: 2025-09-07 21:02
 */

#include <vector>

class Solution {
public:
  std::vector<int> sumZero(int n) {
    std::vector<int> numbers;

    if (n & 1) {
      numbers.push_back(0);
      n--;
    } else {
    }

    for (int i = 1; i <= n; i += 2) {
      numbers.push_back(i);
      numbers.push_back(-i);
    }
    
    return numbers;
  }
};

/**
 * Author: Rut Koticha
 * Date: 2025-09-03 07:19
 */

#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int number = 0;

    for (int num : nums) {
      number ^= num;
    }

    return number;
  }
};

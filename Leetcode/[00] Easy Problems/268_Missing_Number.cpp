/**
 * Author: Rut Koticha
 * Date: 2025-09-01 23:02
 */

#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int number = 0;

    for (int i = 0; i < n; i++) {
      number = number ^ i ^ nums[i];
    }

    number ^= n;

    return number;
  }
};

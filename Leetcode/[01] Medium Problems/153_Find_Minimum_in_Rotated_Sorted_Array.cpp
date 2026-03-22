/**
 * Author: Rut Koticha
 * Date: 2025-09-18 19:54
 */

#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int n = nums.size();

    int left = 0, right = n - 1;

    while (left < right) {
      int mid = left + (right - left) >> 1;

      if (nums[mid] < nums[right]) {
        right = mid; // Right order so change right to get lower value
      } else {
        left = mid + 1; // Incorrect order so change left to get lower value
      }
    }

    return nums.at(left);
  }
};

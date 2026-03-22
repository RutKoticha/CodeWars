/**
 * Author: Rut Koticha
 * Date: 2025-10-05 14:38
 * File: 33_Search_in_Rotated_Sorted_Array.cpp
 */

#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) {
      int mid = left + ((right - left) >> 1);

      if (nums[mid] == target) {
        return mid;
      }

      if (nums[left] <= nums[mid]) { // Left sorted portion
        if (target > nums[mid] || target < nums[left]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else { // Right sorted portion
        if (target < nums[mid] || target > nums[right]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }

    return -1;
  }
};

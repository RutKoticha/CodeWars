/**
 * Author: Rut Koticha
 * Date: 2025-09-10 18:34
 */

#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int n = height.size();

    // Can not find the area if there
    // are not at least two walls
    if (n < 2) {
      return -1;
    }

    // Point left to start and right to end
    int left = 0;
    int right = n - 1;

    // Get the max area as the currently known region where water can be
    int max_area = std::min(height[left], height[right]) * (right - left);

    // Loop until the two meet or cross
    while (left < right) {
      // Get area of current region
      int area = std::min(height[left], height[right]) * (right - left);

      // Test for it being larger so far
      max_area = std::max(max_area, area);

      // Update the pointer with the smaller value of the two
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return max_area;
  }
};

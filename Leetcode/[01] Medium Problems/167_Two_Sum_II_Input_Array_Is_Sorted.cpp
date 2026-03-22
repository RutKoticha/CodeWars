/**
 * Author: Rut Koticha
 * Date: 2025-08-27 09:38
 */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();

    int left = 0;
    int right = n - 1;

    while (left < right) {
      int sum = numbers[left] + numbers[right];

      if (sum == target) {
        return {left + 1, right + 1};

        // Skip duplicates from the left side
        while (left < right && numbers[left] == numbers[left + 1]) {
          left++;
        }

        // Skip duplicates from the right side
        while (left < right && numbers[right] == numbers[right - 1]) {
          right--;
        }
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }

    return {};
  }
};

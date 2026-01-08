/**
 * Author: Rut Koticha
 * Date: 2025-08-27 08:55
 */

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();

    set<vector<int>> result;

   for (int i = 0; i < n - 2; i++) {
      // Don't take duplicate targets
      if (i > 0 && numbers[i] == numbers[i - 1]) {
        continue;
      }

      // Select the target
      int target = -numbers[i];

      // Do two sum II on the remaining elements
      int left = i + 1;
      int right = n - 1;

      while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
          result.insert({numbers[i], numbers[left], numbers[right]});

          // Skip duplicates from the left side
          while (left < right && numbers[left] == numbers[left + 1]) {
            left++;
          }
          left++;

          // Skip duplicates from the right side
          while (left < right && numbers[right] == numbers[right - 1]) {
            right--;
          }
          right--;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }

    return vector<vector<int>>(result.begin(), result.end());
  }
};

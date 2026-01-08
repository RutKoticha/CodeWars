#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-02-27 10:44:26 (Thursday)
 */

class Solution {
  public:
    int searchInsert(std::vector<int> & nums, int target);
};

int Solution::searchInsert(std::vector<int> & nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

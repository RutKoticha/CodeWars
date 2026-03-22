/**
 * @file 27_Remove_Element.cpp
 * @author Rut Koticha
 * @date 2026-01-01
 */

#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>&, int);
};

int Solution::removeElement(std::vector<int>& nums, int val)
{
    int length = nums.size();

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        if (nums[left] == val)
        {
            std::swap(nums[left], nums[right]);
            right--;
        }
        else
        {
            left++;
        }
    }

    return left;
}

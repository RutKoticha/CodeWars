#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-03-03 15:35:48 (Monday)
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
};

class Solution {
  private:
    TreeNode* DivideAndConquer(std::vector<int> &, int, int);

  public:
    TreeNode* sortedArrayToBST(std::vector<int> &);
};

TreeNode* Solution::DivideAndConquer(std::vector<int> & nums,
                                     int left,
                                     int right) {
    if(left == right) {
        return new TreeNode(nums[left]);
    }

    int mid = left + ((right - left) >> 1);

    auto root = new TreeNode(nums[mid]);
    root->left = nullptr;
    root->right = nullptr;

    if(left < mid) {
        root->left = DivideAndConquer(nums, left, mid);
    }

    if(mid < right) {
        root->right = DivideAndConquer(nums, mid + 1, right);
    }

    return root;
}

TreeNode* Solution::sortedArrayToBST(std::vector<int> & nums) {
    if(nums.size() == 1) {
        return new TreeNode(nums[0]);
    }

    if(nums.size() == 2) {
        auto root = new TreeNode(nums[0]);
        root->right = new TreeNode(nums[1]);
        return root;
    }

    return DivideAndConquer(nums, 0, nums.size());
}

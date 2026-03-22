/**
 * Author: Rut Koticha
 * Date: 2025-10-24 22:28
 * File: 124_Binary_Tree_Maximum_Path_Sum.cpp
 */

#include <climits>
#include <cmath>

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif

class Solution {
 private:
  int global_max{INT_MIN};

  int findMax(TreeNode *root) {
    int left_max{0};
    int right_max{0};

    if (root->left) {
      left_max = std::max(0, findMax(root->left));
    }

    if (root->right) {
      right_max = std::max(0, findMax(root->right));
    }

    int current_level_max_value = left_max + right_max + root->val;
    global_max = std::max(global_max, current_level_max_value);

    return root->val + std::max(left_max, right_max);
  }

 public:
  int maxPathSum(TreeNode *root) { return std::max(findMax(root), global_max); }
};

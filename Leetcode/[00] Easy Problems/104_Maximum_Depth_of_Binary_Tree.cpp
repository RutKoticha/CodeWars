/**
 * Author: Rut Koticha
 * Date: 2025-10-07 22:19
 * File: 104_Maximum_Depth_of_Binary_Tree.cpp
 */

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
public:
  int maxDepth(TreeNode *root, int depth = 0) {
    if (!root) {
      return depth;
    }

    return std::max(maxDepth(root->left, depth + 1),
                    maxDepth(root->right, depth + 1));
  }
};

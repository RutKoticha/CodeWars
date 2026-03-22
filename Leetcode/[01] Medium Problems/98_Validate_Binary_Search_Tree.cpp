/**
 * Author: Rut Koticha
 * Date: 2025-10-13 11:23
 * File: 98_Validate_Binary_Search_Tree.cpp
 */

#include <cmath>

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
  bool isValidBST(TreeNode *root, long min = -__LONG_MAX__,
                  long max = __LONG_MAX__) {
    if (root->val <= min || root->val >= max) {
      return false;
    }

    bool validLeft = true, validRight = true;

    if (root->left) {
      validLeft = isValidBST(root->left, min, root->val);
    }

    if (root->right) {
      validRight = isValidBST(root->right, root->val, max);
    }

    return (validLeft && validRight);
  }
};

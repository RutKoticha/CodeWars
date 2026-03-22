/**
 * Author: Rut Koticha
 * Date: 2025-10-13 11:09
 * File: 102_Binary_Tree_Level_Order_Traversal.cpp
 */

#include <queue>
#include <vector>

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

using LeveledNode = std::pair<TreeNode *, int>;

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::queue<LeveledNode> queue;
    std::vector<std::vector<int>> levels;

    queue.push({root, 0});

    while (!queue.empty()) {
      auto [node, level] = queue.front();
      queue.pop();

      if (levels.size() == level) {
        levels.push_back({node->val});
      } else {
        levels[level].push_back(node->val);
      }

      if (node->left) {
        queue.push({node->left, level + 1});
      }

      if (node->right) {
        queue.push({node->right, level + 1});
      }
    }

    return levels;
  }
};

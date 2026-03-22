#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-03-03 14:45:01 (Monday)
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

#define INF 1e9+7

class Solution {
  private:
    std::vector<std::vector<int>> bfsTraversal(TreeNode*);
    bool checkLevelWiseSymmetry(std::vector<std::vector<int>>);
    void addToLevel(std::vector<std::vector<int>> &, TreeNode*, int);
  public:
    bool isSymmetric(TreeNode* root) ;
};

void Solution::addToLevel(std::vector<std::vector<int>> & levels,
                          TreeNode* node,
                          int level) {

    int insertingValue = (node) ? node->val : -INF;

    if(levels.size() <= level) {
        levels.push_back({insertingValue});
    } else {
        levels[level].push_back(insertingValue);
    }

}

std::vector<std::vector<int>> Solution::bfsTraversal(TreeNode* root) {
    std::vector<std::vector<int>> levels;
    std::queue<std::pair<TreeNode*, int>> nodes;

    nodes.push({root, 0});
    while(!nodes.empty()) {
        auto [node, level] = nodes.front();
        nodes.pop();

        addToLevel(levels, node, level);

        if(node) {
            nodes.push({node->left, level + 1});
            nodes.push({node->right, level + 1});
        }
    }
    return levels;
}

bool Solution::checkLevelWiseSymmetry(std::vector<std::vector<int>> levels) {
    for(auto level : levels) {
        int length = level.size();

        int left = 0,
            right = length - 1;
        while(left < right) {
            if(level[left] != level[right]) {
                return false;
            }
            left++;
            right--;
        }
    }

    return true;
}

bool Solution::isSymmetric(TreeNode* root) {
    std::queue<std::pair<TreeNode*, int>> nodes;
    std::vector<std::vector<int>> levels;

    levels = bfsTraversal(root);
    return checkLevelWiseSymmetry(levels);
}

/* Alternative Solution:

class Solution {
public:
    bool isSym(TreeNode* leftTree , TreeNode* rightTree){
        if(leftTree == NULL && rightTree == NULL){
            return true;
        }
        if(leftTree == NULL || rightTree == NULL || leftTree->val != rightTree->val){
            return false;
        }
        return isSym(leftTree->left,rightTree->right) && isSym(leftTree->right,rightTree->left);
    }


    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSym(root->left,root->right);
    }
};

*/

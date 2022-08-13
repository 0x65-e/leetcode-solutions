//#103. Binary Tree Zigzag Level Order Traversal (C++) - 3ms/81.47% 12.8MB/5.35%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> table;
        descend(root, table, 0);
        for (int i = 1; i < table.size(); i += 2) {
            std::reverse(table[i].begin(), table[i].end());
        }
        return table;
    }
private:
    void descend(TreeNode* root, vector<vector<int>>& table, int level) {
        if (root != nullptr) {
            if (table.size() == level) {
                table.push_back({root->val});
            } else {
                table[level].push_back(root->val);
            }
            descend(root->left, table, level+1);
            descend(root->right, table, level+1);
        }
    }
};
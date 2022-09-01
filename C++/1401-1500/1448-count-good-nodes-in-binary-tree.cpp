//#1448. Count Good Nodes in Binary Tree (C++) - 151ms/88.97% 86.4MB/54.67%
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
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + goodNodesLimit(root->left, root->val) + goodNodesLimit(root->right, root->val);
    }
private:
    int goodNodesLimit(TreeNode* root, int limit) {
        if (root == nullptr) return 0;
        if (root->val >= limit) {
            return 1 + goodNodesLimit(root->left, root->val) + goodNodesLimit(root->right, root->val);
        } else {
            return goodNodesLimit(root->left, limit) + goodNodesLimit(root->right, limit);
        }
    }
};
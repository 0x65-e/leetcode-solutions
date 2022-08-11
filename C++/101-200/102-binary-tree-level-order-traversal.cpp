//#102. Binary Tree Level Order Traversal (C++) - 4ms/74.89% 13.3MB/13.90%
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        traverse(root, order, 0);
        return order;
    }
private:
    void traverse(TreeNode* root, vector<vector<int>>& ordering, int base) {
        if (root != nullptr) {
            if (ordering.size() == base) {
                ordering.push_back({root->val});
            } else {
                ordering[base].push_back(root->val);
            }
            traverse(root->left, ordering, base+1);
            traverse(root->right, ordering, base+1);
        }
    }
};
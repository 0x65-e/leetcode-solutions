//#94. Binary Tree Inorder Traversal (C++) - 3ms/60.87% 8.2MB/91.37%
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
private:
    void traverse(TreeNode* root, vector<int>& ordering) {
        if (root != nullptr) {
            traverse(root->left, ordering);
            ordering.push_back(root->val);
            traverse(root->right, ordering);
        }
    }
};
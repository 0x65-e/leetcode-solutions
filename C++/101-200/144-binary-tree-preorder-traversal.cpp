//#144. Binary Tree Preorder Traversal (C++) - 6ms/21.24% 8.3MB/76.59%
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
private:
    void traverse(TreeNode* root, vector<int>& ordering) {
        if (root != nullptr) {
            ordering.push_back(root->val);
            traverse(root->left, ordering);
            traverse(root->right, ordering);
        }
    }
};
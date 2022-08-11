//#145. Binary Tree Postorder Traversal (C++) - 0ms/100.00% 8.4MB/63.74%
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
private:
    void traverse(TreeNode* root, vector<int>& ordering) {
        if (root != nullptr) {
            traverse(root->left, ordering);
            traverse(root->right, ordering);
            ordering.push_back(root->val);
        }
    }
};
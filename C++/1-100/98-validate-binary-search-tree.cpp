//#98. Validate Binary Search Tree (C++) - 7ms/98.53% 21.9MB/6.45%
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return checkValid(root).first;
    }
private:
    pair<bool, pair<int, int>> checkValid(TreeNode* root) {
        pair<bool, pair<int, int>> out = { true, { root->val, root->val } };
        if (root->left != nullptr) {
            pair<bool, pair<int, int>> leftTree = checkValid(root->left);
            // Propagate errors immediately
            if (leftTree.first == false) {
                out.first = false;
                return out;
            }
            // Invalid - left subtree has larger value than root
            if (leftTree.second.second >= root->val) {
                out.first = false;
                return out;
            }
            // Update the new min
            out.second.first = leftTree.second.first;
        }
        if (root->right != nullptr) {
            pair<bool, pair<int, int>> rightTree = checkValid(root->right);
            // Propagate errors immediately
            if (rightTree.first == false) {
                out.first = false;
                return out;
            }
            // Invalid - right subtree has smaller value than root
            if (rightTree.second.first <= root->val) {
                out.first = false;
                return out;
            }
            // Update the new max
            out.second.second = rightTree.second.second;
        }
        return out;
    }
};
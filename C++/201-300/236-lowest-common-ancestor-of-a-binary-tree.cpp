//#236. Lowest Common Ancestor of a Binary Tree (C++) - 1255ms/5.06% 13.9MB/99.71%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (isDescendant(root->left, p) && isDescendant(root->left, q)) {
                root = root->left;
            } else if (isDescendant(root->right, p) && isDescendant(root->right, q)) {
                root = root->right;
            } else {
                break;
            }
        }
        return root;
    }
private:
    bool isDescendant(TreeNode* root, TreeNode* node) {
        if (root == node) {
            return true;
        } else if (root == nullptr) {
            return false;
        }
        return isDescendant(root->left, node) || isDescendant(root->right, node);
    }
};
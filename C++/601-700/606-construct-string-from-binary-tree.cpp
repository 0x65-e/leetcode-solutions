//#606. Construct String from Binary Tree (C++) - 55ms/24.24% 53.4MB/41.81%
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
    string tree2str(TreeNode* root) {
        if (root == nullptr) return "";
        else {
            string out;
            out.append(to_string(root->val));
            string left = tree2str(root->left);
            string right = tree2str(root->right);
            if (left != "" || right != "") {
                out.push_back('(');
                out.append(left);
                out.push_back(')');
            }
            if (right != "") {
                out.push_back('(');
                out.append(right);
                out.push_back(')');
            }
            return out;
        }
    }
};
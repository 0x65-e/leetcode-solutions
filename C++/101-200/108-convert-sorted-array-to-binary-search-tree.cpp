//#108. Convert Sorted Array to Binary Search Tree (C++) - 20ms/65.25% 21.4MB/41.16%
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructSubtree(nums.cbegin(), nums.cend());
    }
private:
    TreeNode* constructSubtree(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
        if (end == begin) {
            return nullptr;
        } else if (end - begin == 1) {
            return new TreeNode(*begin);
        } else {
            vector<int>::const_iterator mid = begin + (end - begin) / 2;
            TreeNode* left = constructSubtree(begin, mid);
            TreeNode* right = constructSubtree(mid+1, end);
            return new TreeNode(*mid, left, right);
        }
    }
};
//#173. Binary Search Tree Iterator (C++) - 30ms/91.67% 25MB/5.37%
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        descend(root);
        impl = order.cbegin();
    }
    
    int next() {
        int out = *impl;
        impl++;
        return out;
    }
    
    bool hasNext() {
        return impl != order.cend();
    }
private:
    list<int> order;
    list<int>::const_iterator impl;
    
    void descend(TreeNode* root) {
        if (root != nullptr) {
            descend(root->left);
            order.push_back(root->val);
            descend(root->right);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
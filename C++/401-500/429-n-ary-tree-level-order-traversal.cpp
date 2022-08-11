//#429. N-ary Tree Level Order Traversal (C++) - 42ms/34.63% 11.7MB/63.52%
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> order;
        traverse(root, order, 0);
        return order;
    }
private:
    void traverse(Node* root, vector<vector<int>>& ordering, int base) {
        if (root != nullptr) {
            if (ordering.size() == base) {
                ordering.push_back({root->val});
            } else {
                ordering[base].push_back(root->val);
            }
            for (Node* child : root->children) {
                traverse(child, ordering, base+1);
            }
        }
    }
};
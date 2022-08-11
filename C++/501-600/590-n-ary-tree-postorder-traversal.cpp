//#590. N-ary Tree Postorder Traversal (C++) - 21ms/94.50% 11.3MB/32.76%
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
    vector<int> postorder(Node* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
private:
    void traverse(Node* root, vector<int>& ordering) {
        if (root != nullptr) {
            for (Node* child : root->children) {
                traverse(child, ordering);
            }
            ordering.push_back(root->val);
        }
    }
};
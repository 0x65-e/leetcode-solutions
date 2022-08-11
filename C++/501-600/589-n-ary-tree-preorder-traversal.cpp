//#589. N-ary Tree Preorder Traversal (C++) - 19ms/97.49% 11.3MB/50.98%
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
    vector<int> preorder(Node* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
private:
    void traverse(Node* root, vector<int>& ordering) {
        if (root != nullptr) {
            ordering.push_back(root->val);
            for (Node* child : root->children) {
                traverse(child, ordering);
            }
        }
    }
};
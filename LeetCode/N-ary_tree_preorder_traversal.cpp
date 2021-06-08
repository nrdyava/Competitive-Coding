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
void preorderTraversal(Node* head, vector<int> &vect){
    if (head == nullptr) return;
    vect.push_back(head->val);
    for (auto child: head->children){
        preorderTraversal(child, vect);
    }
}

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }
};
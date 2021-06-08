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
void postorderTraversal(Node* head, vector<int> &vect){
    if (head == nullptr) return;
    for (auto child: head->children) postorderTraversal(child, vect);
    vect.push_back(head->val);
    return;
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }

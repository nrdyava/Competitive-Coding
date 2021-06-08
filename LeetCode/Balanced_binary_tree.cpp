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

int height(TreeNode* head){
    if (head == nullptr) return 0;
    if (head->left == nullptr && head->right == nullptr) return 1;
    return 1 + max(height(head->left), height(head->right));
} 

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(height(root->left) - height(root->right)) >1) return false;
        return isBalanced(root->left)*isBalanced(root->right);
    }
};
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
    bool solver(TreeNode* root, TreeNode* low, TreeNode* high){
        if(root == nullptr) return true;
        
        if((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val)) return false;
        
        return solver(root->left, low, root) && solver(root->right, root, high);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return solver(root, nullptr, nullptr);
    }
};
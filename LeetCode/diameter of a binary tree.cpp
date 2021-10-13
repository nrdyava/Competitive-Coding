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
    int solver(TreeNode* root, int &res){
        if(root == nullptr) return -1;
        
        int left = solver(root->left, res);
        int right = solver(root->right, res);
        res = max(res, left+right+2);
        
        return max(left, right)+1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solver(root, res);
        return res;
    }
};
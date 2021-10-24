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
    int depth(TreeNode* root){
        if(root == nullptr) return -1;
        return 1+depth(root->left);   
    }
    
    void solver(TreeNode* root, int lvl, int &ans, int d){
        if(lvl == d) return;
        if(root->left == nullptr && root->right == nullptr){
            ans = ans - 2;
            return;
        }
        
        if(root->right == nullptr){
            ans = ans-1;
            return;
        }
        
        solver(root->right, lvl+1, ans, d);
        solver(root->left, lvl+1, ans, d);
        return;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int d = depth(root);
        
        if(d == 0) return 1;
        
        int ans = pow(2, d);
        
        solver(root, 0, ans, d);
        
        return pow(2, d) - 1 + ans;
    }
};
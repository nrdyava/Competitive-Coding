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
    int solver(TreeNode* root, int maxx){
        if(root == nullptr) return 0;
        int temp = 0;
        if((root->val) >= maxx) temp++;
        maxx = max(maxx, root->val);
        
        
        return temp + solver(root->left, maxx) + solver(root->right, maxx);;
    }
    
public:
    int goodNodes(TreeNode* root) {
        int maxx = INT_MIN;
        return solver(root, maxx);
    }
};
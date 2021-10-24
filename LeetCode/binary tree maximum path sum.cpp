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
    int solver(TreeNode* root, int &maxx){
        if(root == nullptr) return 0;
        int leftps = solver(root->left, maxx);
        int rightps = solver(root->right, maxx);
        
        if(root->left != nullptr) maxx = max(maxx, leftps);
        if(root->right != nullptr) maxx = max(maxx, rightps);
        
        if(leftps < 0) leftps = 0;
        if(rightps < 0) rightps = 0;
        maxx = max(maxx, root->val+leftps+rightps);
        
        return max(root->val + leftps, root->val + rightps);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;
        solver(root, maxx);
        return maxx;
    }
};
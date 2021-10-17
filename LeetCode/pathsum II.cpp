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
    void solver(TreeNode* root, int pathsum, vector<int> &path, vector<vector<int>>& ans, int targetSum){
        if(root == nullptr) return;
        pathsum = pathsum+root->val;
        path.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            if(pathsum == targetSum){
                ans.push_back(path);
                path.pop_back();
                return;
            }
        }
        
        solver(root->left, pathsum, path, ans, targetSum);
        solver(root->right, pathsum, path, ans, targetSum);
        path.pop_back();
        return;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int pathsum = 0;
        
        solver(root, pathsum, path, ans, targetSum);
        return ans;
    }
};
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

bool path_sum(TreeNode* root, int target, int pathsum){
    if (root == nullptr) return false;
    pathsum = pathsum + root->val;
    if (root->left == nullptr && root->right == nullptr){
        return (pathsum == target)?true:false;
    }
    return path_sum(root->left, target, pathsum) || path_sum(root->right, target, pathsum);
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int pathsum = 0;
        return path_sum(root, targetSum, pathsum);
    }
};
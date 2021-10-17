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
    void solver(TreeNode* root, unordered_map<int, int> &M, int target, int &count, int sum){
        if(root == nullptr) return;
        sum = sum + root->val;
        if(sum == target) count++;
        
        int prefixsum = sum - target;
        if(M.count(prefixsum)){
            count += M[prefixsum];
        }
        
        M[sum]++;
        solver(root->left, M, target, count, sum);
        solver(root->right, M, target, count, sum);
        M[sum]--;
        return;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> M;
        int count = 0;
        solver(root, M, targetSum, count, 0);
        return count;
    }
};
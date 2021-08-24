/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int hps(TreeNode* A, int target, int csum){
    if(A == NULL) return 0;

    csum = csum + A->val;
    if(!A->left && !A->right && csum == target) return 1;

    return hps(A->left, target, csum) || hps(A->right, target, csum);
}


int Solution::hasPathSum(TreeNode* A, int B) {
    return hps(A, B, 0);
}

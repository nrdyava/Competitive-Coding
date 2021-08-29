/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxp(TreeNode* root, int &res){
    if(root == NULL) return 0;

    int l = maxp(root->left, res);
    int r = maxp(root->right, res);

    int singlep = max(max(l, r) + root->val, root->val);

    int maxx = max(singlep, l + r + root->val);

    res = max(res, maxx);

    return singlep;
}

int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    maxp(A, res);
    return res;   
}

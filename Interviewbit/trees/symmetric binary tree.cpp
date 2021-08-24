/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sym(TreeNode* A, TreeNode* B){
    if(A == NULL && B == NULL) return 1;

    if(A == NULL || B == NULL) return 0;

    if(A->val == B->val){
        return sym(A->left, B->right) * sym(A->right, B->left);
    }
    return 0;
}

int Solution::isSymmetric(TreeNode* A) {
    return sym(A->left, A->right);
}

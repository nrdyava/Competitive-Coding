/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void shum(TreeNode* A, int csum, int &total){
    if(A == NULL) return;
    csum = (csum*10 + A->val)%1003;

    if(!A->left && !A->right){
        total = (total + csum)%1003;
        return;
    }

    if(A->left) shum(A->left, csum, total);
    if(A->right) shum(A->right, csum, total);
    return;
}


int Solution::sumNumbers(TreeNode* A) {
    int total = 0;
    int csum = 0;

    shum(A, csum, total);
    return total;
}

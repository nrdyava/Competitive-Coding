/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL || !A->left && !A->right) return A;

    if(A->left){
        flatten(A->left);

        TreeNode* tempRight = A->right;
        A->right = A->left;
        A->left = NULL;

        TreeNode* temp = A->right;

        while(temp->right){
            temp = temp->right;
        }
        temp->right = tempRight;
    }
    flatten(A->right);
    return A;
}

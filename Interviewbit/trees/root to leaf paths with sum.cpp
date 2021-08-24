/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void ps(TreeNode* A, int B, int csum, vector<int> temp, vector<vector<int>> &ans){
    if(A == NULL) return;

    csum = csum+A->val;
    temp.push_back(A->val);

    if(!A->left && !A->right && csum == B){
        ans.push_back(temp);
        return;
    }

    if(A->left) ps(A->left, B, csum, temp, ans);
    if(A->right) ps(A->right, B, csum, temp, ans);
    return;
}


vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
    vector<int> temp;
    vector<vector<int>> ans;
    int csum = 0;
    ps(A, B, csum, temp, ans);
    return ans;

}

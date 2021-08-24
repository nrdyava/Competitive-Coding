/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void DT(TreeNode* A, map<int, vector<int>> &M, int row, int col){
    if(A == NULL) return;
    M[row - col].push_back(A->val);
    if(A->left) DT(A->left, M, row+1, col-1);
    if(A->right) DT(A->right, M, row+1, col+1);
    return;
}

vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int>> M;
    DT(A, M, 0, 0);
    vector<int> ans;

    for(auto m:M){
        ans.insert(ans.end(), m.second.begin(), m.second.end());
    }
    return ans;
}

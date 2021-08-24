/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void rightview(TreeNode* A, map<int, int>& M, int level){
    if(A == NULL) return;

    if(M.find(level) == M.end()){
        M[level] = A->val;
    }

    rightview(A->right, M, level+1);
    rightview(A->left, M, level+1);

    return;
}

vector<int> Solution::solve(TreeNode* A) {
    map<int, int> M;
    rightview(A, M, 1);
    vector<int> ans;

    for(auto pr: M){
        ans.push_back(pr.second);
    }
    return ans;
}

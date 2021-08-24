/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void vot(TreeNode* A, map<int, map<int, vector<int>>> &M, int col, int row){
    if(!A) return;

    M[col][row].push_back(A->val);
    if(A->left) vot(A->left, M, col-1, row+1);
    if(A->right) vot(A->right, M, col+1, row+1);
    return;
}

vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, map<int, vector<int>>> M;
    vector<vector<int>> ans;

    vot(A, M, 0, 0);

    for(auto col: M){
        vector<int> temp;
        for(auto row: col.second){
            temp.insert(temp.end(), row.second.begin(), row.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

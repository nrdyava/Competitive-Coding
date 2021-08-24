/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* inpr(vector<int>& Pr, int left, int right, int &prIndex, unordered_map<int, int> &M){
    if(left > right) return NULL;

    TreeNode* root = new TreeNode(Pr[prIndex++]);

    if(left == right) return root;

    int inIndex = M[root->val];

    root->left = inpr(Pr, left, inIndex - 1, prIndex, M);
    root->right = inpr(Pr, inIndex + 1, right, prIndex, M);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();

    unordered_map<int, int> M;
    for(int i=0; i<n; i++){
        M[B[i]] = i;
    }
    int prIndex = 0;
    return inpr(A, 0, n-1, prIndex, M);
}

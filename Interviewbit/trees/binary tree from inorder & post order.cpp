/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* inpo(vector<int> &po, int left, int right, int &poIndex, unordered_map<int, int> &M){
    if(left > right){
        return NULL;
    }

    TreeNode* root = new TreeNode(po[poIndex--]);

    if(left == right) return root;

    int inIndex = M[root->val];

    root->right = inpo(po, inIndex+1, right, poIndex, M);
    root->left = inpo(po, left, inIndex-1, poIndex, M);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = B.size();
    unordered_map<int, int> M;
    for(int i=0; i<n; i++){
        M[A[i]] = i;
    }

    int poIndex = n-1;

    return inpo(B, 0, n-1, poIndex, M);
}

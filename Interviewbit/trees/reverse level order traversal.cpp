/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    stack<int> s;
    vector<int> ans;

    if(A == NULL) return ans;

    queue<TreeNode*> Q;
    Q.push(A);

    while(!Q.empty()){
        TreeNode* curr = Q.front();
        s.push(curr->val);
        Q.pop();

        if(curr->right) Q.push(curr->right);
        if(curr->left) Q.push(curr->left);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

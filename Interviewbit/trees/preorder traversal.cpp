/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> iot;
    stack<TreeNode*> s;
    if(A == NULL) return iot;

    s.push(A);

    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();

        iot.push_back(curr->val);

        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }

    return iot;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> pot;
    stack<int> out;
    stack<TreeNode*> s;

    s.push(A);

    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();

        out.push(curr->val);

        if(curr->left){
            s.push(curr->left);
        }
        if(curr->right){
            s.push(curr->right);
        }
    }

    while(!out.empty()){
        pot.push_back(out.top());
        out.pop();
    }
    return pot;
}

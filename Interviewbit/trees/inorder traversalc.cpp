/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> iot;
    stack<TreeNode*> s;

    TreeNode* curr = A;

    while(!s.empty() || curr!=NULL){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            iot.push_back(curr->val);
            curr = curr->right;
        }
        
    }
    return iot;
}

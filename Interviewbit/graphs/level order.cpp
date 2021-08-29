/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    int n1;

    queue<TreeNode*> q;
    q.push(A);
    TreeNode* curr;

    while(!q.empty()){
        n1 = q.size();
        vector<int> temp;

        while(n1--){
            curr = q.front();
            q.pop();

            temp.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }   
        ans.push_back(temp);
    }
    return ans;
}

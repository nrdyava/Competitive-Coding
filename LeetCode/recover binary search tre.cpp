/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, vector<TreeNode*>& A){
        if(root == nullptr) return;
        
        inorder(root->left, A);
        A.push_back(root);
        inorder(root->right, A);
        return;
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> A;
        inorder(root, A);
        int l, r;
        
        for(int i=1; i<A.size(); i++){
            if(A[i-1]->val > A[i]->val){
                l = i-1;
                break;
            }
        }
        
        for(int i=A.size()-2; i>=0; i--){
            if(A[i]->val > A[i+1]->val){
                r = i+1;
                break;
            }
        }
        swap(A[l]->val, A[r]->val);
        return;
    }
};
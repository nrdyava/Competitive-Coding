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
    void traverse_inorder(TreeNode* root, vector<TreeNode*> &inorder){
        if(root == nullptr) return;
        
        traverse_inorder(root->left, inorder);
        inorder.push_back(root);
        traverse_inorder(root->right, inorder);
    }
    
    TreeNode* constructBST(vector<TreeNode*> &inorder, int start, int end){
        if(start > end) return nullptr;
        int mid = start+(end-start)/2;
        
        TreeNode* root = inorder[mid];
        root->left = constructBST(inorder, start, mid-1);
        root->right = constructBST(inorder, mid+1, end);
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        traverse_inorder(root, inorder);
        return constructBST(inorder, 0, inorder.size()-1);
        
    }
};
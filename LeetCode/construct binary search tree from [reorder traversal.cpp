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
public:
    TreeNode* solver(vector<int> preorder, int start, int end){
        
        if(start>end) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        int right_index;
        for(int i=start+1; i<=end; i++){
            if(preorder[i]>preorder[start]){
                right_index = i;
                break;
            }
        }
        
        root->left = solver(preorder, start+1, right_index-1);
        root->right = solver(preorder, right_index, end);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solver(preorder, 0, preorder.size()-1);
    }
};
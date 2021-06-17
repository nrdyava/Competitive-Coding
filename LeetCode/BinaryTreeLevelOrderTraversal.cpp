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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> inorderVect;
        if (root == nullptr) return inorderVect;
        
        q.push(root);
        
        while(q.size()){
            
            TreeNode* node;
            vector<int> temp;
            vector<TreeNode*> vect;
            
            while(q.size()){
                
                node = q.front();
                temp.push_back(node->val);
                q.pop();
                
                if(node->left) vect.push_back(node->left);
                if(node->right) vect.push_back(node->right);
                
            }
            
            for(int i=0; i<vect.size(); i++) q.push(vect[i]);
            inorderVect.push_back(temp);
        }
        return inorderVect;
    }
};
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
    bool areSameTrees(TreeNode* l, TreeNode* r){
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        bool comp_a = (l->val == r->val);
        bool comp_b = areSameTrees(l->left, r->right);
        bool comp_c = areSameTrees(l->right, r->left);
        return comp_a && comp_b && comp_c;
        }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return areSameTrees(root->left, root->right);
    }
};
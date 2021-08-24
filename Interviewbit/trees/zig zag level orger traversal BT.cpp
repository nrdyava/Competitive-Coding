/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void zzlot(TreeNode* A, map<int, deque<int>> &M, int level){
    if(A == NULL) return;

    if(M.find(level) != M.end()){
        M[level].push_back(A->val);
    }
    else{
        deque<int> temp2;
        M[level] = temp2;
        M[level].push_back(A->val);
    }

    zzlot(A->left, M, level+1);
    zzlot(A->right, M, level+1);

    return;
}


vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    map<int, deque<int>> M;

    zzlot(A, M, 1);

    vector<int> temp;
    

    for(auto lvl: M){
        temp = {};
        if(lvl.first % 2 == 1){
            while(!lvl.second.empty()){
                temp.push_back(lvl.second.front());
                lvl.second.pop_front();
        }
        }
        else{
            while(!lvl.second.empty()){
            temp.push_back(lvl.second.back());
            lvl.second.pop_back();
        }
        }
        ans.push_back(temp);
    }
    return ans;
}

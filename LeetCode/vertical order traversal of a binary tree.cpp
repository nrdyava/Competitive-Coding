class Solution {
public:
    vector<vector<int>> res;
    map<int, vector<pair<int,int>>> mp;
        
    
    void vertOrder(TreeNode *node, int x, int y){
        
        if(node == NULL)
            return;
        
        mp[x].push_back({node->val, y});
        vertOrder(node->left, x-1, y-1);
        vertOrder(node->right, x+1, y-1);
        
    }
    
    static bool compare(pair<int, int> &a, pair<int, int> &b){    //comparator
    
        
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        if(root == NULL)
            return res;
        
        vertOrder(root, 0, 0);
        
        for(auto it = mp.begin(); it!=mp.end(); it++){
            
            vector<pair<int, int>> vec = it->second;
            sort(vec.begin(), vec.end(), compare);
            
            vector<int> ans;
            for(int i=0; i<vec.size(); i++){
                ans.push_back(vec[i].first);
            }
            res.push_back(ans);
        }
        
        return res;
        
    }
};
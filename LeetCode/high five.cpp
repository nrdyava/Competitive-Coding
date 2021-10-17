class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> M;
        for(int i=0; i<items.size(); i++) M[items[i][0]].push(items[i][1]);
        
        vector<vector<int>> ans;
        for(auto ele: M){
            int temp = 0;
            for(int i=0; i<5; i++){
                temp += ele.second.top();
                ele.second.pop();
            }
            temp = temp / 5;
            ans.push_back({ele.first, temp});
        }
        return ans;
    }
};
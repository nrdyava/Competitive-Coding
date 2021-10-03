class Solution {
    vector<vector<int>> solver(vector<int> candidates, int start, int end, int target){
        if(start > end){
            if(target == 0){
                return {{}};
            }
            else return {};
        }
        
        if(target == 0) return {{}};
        if(target < 0) return {};
        
        vector<vector<int>> without = solver(candidates, start+1, end, target);
        vector<vector<int>> with= solver(candidates, start, end, target - candidates[start]);
        
        vector<vector<int>> s;
        for(int i=0; i<with.size(); i++){
            with[i].push_back(candidates[start]);
            s.push_back(with[i]);
        }
        
        for(int i=0; i<without.size(); i++){
            s.push_back(without[i]);
        }
        
        return s;
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return solver(candidates, 0, candidates.size()-1, target);
    }
};
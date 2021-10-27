class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        vector<vector<int>> ans;
        int k = 0;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i, newInterval);
                k=1;
                break;
            }
        }
        if(k==0) intervals.push_back(newInterval);
        //return intervals;
            
        vector<int> temp = intervals[0];
            
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>temp[1]){
                ans.push_back(temp);
                temp = intervals[i];
            }
            else{
                temp[1] = max(temp[1], intervals[i][1]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
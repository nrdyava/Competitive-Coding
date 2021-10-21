class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int maxbfr = values[0]+0;
        int ans = INT_MIN;
        
        for(int i=1; i<n; i++){
            ans = max(ans, maxbfr+values[i]-i);
            maxbfr = max(maxbfr, values[i]+i);
        }
        return ans;
    }
};
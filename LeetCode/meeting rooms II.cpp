class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arr(n);
        vector<int> dep(n);
        
        for(int i=0; i<n; i++){
            arr[i] = intervals[i][0];
            dep[i] = intervals[i][1];
        }
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int idx = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i]<dep[idx]) ans++;
            else idx++;
        }
        return ans;
    }
};
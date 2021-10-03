class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool visited[100009] = {false};
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int count = 0;
                int start = nums[i];
                
                do{
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }
                while(start != nums[i]);
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
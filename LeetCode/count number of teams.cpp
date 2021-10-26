class Solution {
public:
    int numTeams(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        
        for(int i=1; i<n-1; i++){
            int left = 0, right = 0;
            
            for(int j=0; j<i; j++){
                if(A[j]<A[i]) left++;
            }
            
            for(int j=i+1; j<n; j++){
                if(A[j]>A[i]) right++;
            }
            
            ans += (left*right + (i-left)*(n-i-right-1));
        }
        return ans;
    }
};
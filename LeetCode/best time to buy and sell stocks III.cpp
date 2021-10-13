class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        
        int left[n];
        int right[n];
        
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        
        for(int i=1; i<n; i++){
            left[i] = min(left[i-1], prices[i]);
        }
        
        for(int i=0; i<n; i++){
            left[i] = prices[i] - left[i];
            if(i>0) left[i] = max(left[i], left[i-1]);
        }
        
        for(int i=n-2; i>=0; i--) right[i] = max(right[i+1], prices[i]);
        
        for(int i=n-1; i>=0; i--){
            right[i] = right[i] - prices[i];
            if(i<n-1) prices[i] = max(right[i+1], right[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, left[i]+right[i]);
        }
        return ans;
    }
};
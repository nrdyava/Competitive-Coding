class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int n = prices.size();
        int maxp = 0;
        int temp = prices[0];
        
        for(int i=1; i<n;i++){
            if (prices[i] > temp){
                maxp += prices[i]-temp;
                temp = prices[i];
            }
            else temp = prices[i];
        }
        return maxp;
    }
};
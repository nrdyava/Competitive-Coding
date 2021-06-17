class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ncoins[amount+1];
        int cs = coins.size();
        
        for(int i=0;i<=amount;i++) ncoins[i] = INT_MAX-1;
        ncoins[0] = 0;
        
        for(int i=1; i<=amount; i++){
            for(int j = 0; j<cs; j++){
                if(i >= coins[j]) ncoins[i] = min(ncoins[i], ncoins[i-coins[j]]+1);
            }
        }
        return (ncoins[amount] == INT_MAX - 1)?-1:ncoins[amount];
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ncoins = coins.size();
        vector<int> ncombs(amount+1, 0);
        ncombs[0] = 1;
        
        for(int i=0; i<ncoins; i++){
            for(int j=coins[i]; j<=amount; j++){
                ncombs[j] += ncombs[j - coins[i]];
            }
        }
        
        return ncombs[amount];
    }
};
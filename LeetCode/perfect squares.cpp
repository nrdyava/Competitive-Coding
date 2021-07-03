class Solution {
public:
    int numSquares(int n) {
        vector<int> vec(n+1, INT_MAX-1);
        vec[0] = 0;
        int k = floor(sqrt(n));
        vector<int> squares(k+1,0);
        for(int i=1; i<=k; i++) squares[i] = pow(i,2);
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(i>=squares[j]) vec[i] = min(vec[i], vec[i-squares[j]] + 1);
            }
        }
        return vec[n];
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> nconn(n, 0);
        vector<vector<int>> adjmat(n, vector<int>(n, 0));
        
        int maxx = 0;
        for(auto road:roads){
            nconn[road[0]]++;
            nconn[road[1]]++;
            adjmat[road[0]][road[1]] = 1;
            adjmat[road[1]][road[0]] = 1;
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int temp = nconn[i]+nconn[j] - adjmat[i][j];
                maxx = max(maxx, temp);
            }
        }
        return maxx;
    }
};
class Solution {
public:
    int numTrees(int n) {
        vector<int> ntrees(n+1, 0);
        ntrees[0] = 1;
        ntrees[1] = 1;
        
        for(int i=2; i<=n;i++){
            for(int j=0; j<i; j++){
                ntrees[i] += ntrees[j]*ntrees[i-j-1]; 
            }
        }
        return ntrees[n];
    }
};
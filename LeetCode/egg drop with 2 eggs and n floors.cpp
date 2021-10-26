class Solution {
public:
    
    int solver(int k, int n, vector<vector<int>> &lookup){
        if(n==0 || n==1) return n;
        if(k==1) return n;
        
        if(lookup[k][n] != -1) return lookup[k][n];
        
        int low = 0, high = n, minn = INT_MAX;
        
        while(low <= high){
            
            int mid = (low+high)/2;
            
            int left = solver(k-1, mid-1, lookup);
            int right = solver(k, n-mid, lookup);
            
            int temp = 1+max(left, right);
            
            minn = min(minn, temp);
            
            if(left<right) low = mid+1;
            else high = mid-1;   
        }
        return lookup[k][n] = minn;
        
    }
    
    int twoEggDrop(int n) {
        int k=2;
        vector<vector<int>> lookup(k+1, vector<int>(n+1, -1));
        return solver(k, n, lookup);
    }
};
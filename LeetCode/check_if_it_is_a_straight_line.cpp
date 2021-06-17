class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int num_diff, den_diff;
        int snum_diff = (coordinates[1][1] - coordinates[0][1]);
        int sden_diff = (coordinates[1][0] - coordinates[0][0]);
        
        for(int i=1;i<n;i++){
            num_diff = coordinates[i][1] - coordinates[i-1][1];
            den_diff = coordinates[i][0] - coordinates[i-1][0];
            if (snum_diff*den_diff != sden_diff*num_diff) return false;
        }
        
        return true;
    }
};
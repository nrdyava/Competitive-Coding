class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k, left, right, mid, ceil_sum;
        
        left = 1;
        right = *max_element(piles.begin(), piles.end());
        k = right;
        
        if (piles.size() == 1){
            return ceil(1.0*piles[0]/h);
        }
        
        while(left <= right){
            mid = (right + left)/2;
            
            ceil_sum = 0;
            for(auto ele: piles) ceil_sum += ceil(1.0*ele/mid);
    
            if(ceil_sum <= h){
                right = mid - 1;
                k = mid;
            }
            else left = mid+1;
        }
        
        return k;
    }
};
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left, right=0, mid,lwc, daysTakes, tempSum;
        left = *max_element(weights.begin(), weights.end());
        right = accumulate(weights.begin(), weights.end(), right);
        lwc = right;
        
        while(left <= right){
            mid = (left + right)/2;
            daysTakes = 1;
            tempSum = 0;
            for(auto weight: weights){
                if (tempSum + weight <= mid) tempSum += weight;
                else{
                    tempSum = weight;
                    daysTakes++;
                }
            }
            
            if (daysTakes<=days){
                right = mid - 1;
                lwc = mid;
            }
            else left = mid+1;
        }
        return lwc;
    }
};
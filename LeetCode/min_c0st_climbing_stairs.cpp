class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int CostArr[cost.size()+1];
        CostArr[0] = 0;
        CostArr[1] = 0;
        for (int i=2;i<cost.size()+1;i++){
            CostArr[i] = min(cost[i-1] + CostArr[i-1], cost[i-2] + CostArr[i-2]);
        }
        return CostArr[cost.size()];
    }
};
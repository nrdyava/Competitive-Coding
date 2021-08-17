class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(), idx = 0, deficit = 0;
        int gasSum = 0, costSum = 0;
        
        for(int i = 0 ; i < n ; i++) {
            gasSum += gas[i];
            costSum += cost[i];
            if(gasSum < costSum) {
                deficit += costSum - gasSum;
                gasSum = costSum = 0;
                idx = i+1;
            }
        }
        
        int surplus = gasSum - costSum;
        return  surplus >= deficit ? idx : -1;
    }
};
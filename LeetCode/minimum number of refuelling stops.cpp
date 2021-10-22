class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel > target) return 0;
        int count = 0;
        int fuel = startFuel;
        int idx = 0;
        priority_queue<int> pq;
    
        
        while(fuel<target){
            while(idx < stations.size() && fuel >= stations[idx][0]){
                pq.push(stations[idx][1]);
                idx++;
            }
            
            if(pq.size() == 0) return -1;
            
            fuel = fuel + pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};
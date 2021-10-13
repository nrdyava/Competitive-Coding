class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int i=0; i<stones.size(); i++) pq.push(stones[i]);
        
        while(pq.size() >=2){
            int s1 = pq.top();pq.pop();
            int s2 = pq.top(); pq.pop();
            
            int rem = abs(s1 - s2);
            
            if(rem == 0){
                continue;
            }
            pq.push(rem);
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
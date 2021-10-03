class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> M;
        for(int i=0; i<n; i++){
            M[arr[i]].push_back(i);
        }
        
        int steps = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            steps++;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();
                
                if(curr-1>=0 && M.find(arr[curr-1]) != M.end()){
                    q.push(curr-1);
                }
                
                if(curr+1 < n && M.find(arr[curr+1]) != M.end()){
                    if(curr+1 == n-1) return steps;
                    q.push(curr+1);
                }
                
                if(M.find(arr[curr])!=M.end()){
                    for(auto k: M[arr[curr]]){
                        if(curr == k) continue;
                        if(k == n-1) return steps;
                        q.push(k);
                    }
                    M.erase(arr[curr]);
                }
                
            }
        }
        return steps;
    }
};
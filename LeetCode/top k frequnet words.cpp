typedef pair<string, int> psi;

class comparator{
    public:
    bool operator()(psi& a, psi& b){
        if(a.second == b.second) return a.first>b.first;
        return a.second<b.second;
    }
};

class Solution {
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto &c:words){
            m[c]++;
        }
        
        priority_queue<psi, vector<psi>, comparator> pq;
        for(auto itr: m){
            pq.push(make_pair(itr.first, itr.second));
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
    
};
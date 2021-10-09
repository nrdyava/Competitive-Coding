class Solution {
    vector<string> ans;
    
    void solver(string curr, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph){
        priority_queue<string, vector<string>, greater<string>> &pq = graph[curr];
        while(!pq.empty()){
            string child = pq.top();
            pq.pop();
            solver(child, graph);
        }
        ans.insert(ans.begin(), curr);
        return;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(auto ticket: tickets){
            graph[ticket[0]].push(ticket[1]);
        }
        solver("JFK", graph);
        return ans;
    }
};
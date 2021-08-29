/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*, UndirectedGraphNode*> M;
    queue<UndirectedGraphNode*> q;

    q.push(node);
    UndirectedGraphNode* nnode = new UndirectedGraphNode(node->label);

    M[node] = nnode;

    while(!q.empty()){
        UndirectedGraphNode* u = q.front();
        q.pop();

        vector<UndirectedGraphNode*> v = u->neighbors;

        for(int i=0; i<v.size(); i++){
            if(M[v[i]] == NULL){
                UndirectedGraphNode* nnode = new UndirectedGraphNode(v[i]->label);
                M[v[i]] = nnode;
                q.push(v[i]);
            }
            M[u]->neighbors.push_back(M[v[i]]);
        }
    } 
    return M[node];
}

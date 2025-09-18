class Solution {
public:
    int cnt =0;
    void dfs(int node, unordered_map<int,vector<int>>&adj,unordered_set<int>&s,vector<int>&vis){
     vis[node]=1;
     cnt++;
     for(auto adjnode:adj[node]){
        if(vis[adjnode]==0 && s.find(adjnode)==s.end()){
            dfs(adjnode,adj,s,vis);
        }
     }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>s;
        for(int i=0;i<restricted.size();i++){
            s.insert(restricted[i]);
        }
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        dfs(0,adj,s,vis);
        return cnt;
    }
};
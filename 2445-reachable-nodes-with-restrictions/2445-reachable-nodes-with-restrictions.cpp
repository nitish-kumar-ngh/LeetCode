class Solution {
public:
    unordered_set<int>s;
    void f(int src,vector<int>&vis,   unordered_map<int,vector<int>>&adj,vector<int>& restricted){
        vis[src]=1;
        for(auto &it:adj[src]){
            if(vis[it]==0 && s.find(it)==s.end()){
                f(it,vis,adj,restricted);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<restricted.size();i++){
         s.insert(restricted[i]);
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt =0;
        vector<int>vis(n,0);
        f(0,vis,adj,restricted);
        for(int i=0;i<n;i++){
            if(vis[i]==1)cnt++;
        }
        return cnt;
    }
};
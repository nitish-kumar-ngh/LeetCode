class Solution {
public:
    int cnt =0;
    void dfs(vector<int>&vis, unordered_map<int,vector<pair<int,int>>>&adj,int node){
        vis[node]=1;

        for(auto v:adj[node]){
            if(vis[v.first]==0){
                if(v.second==0)cnt++;
                dfs(vis,adj,v.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<connections.size();i++){
            int u= connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        vector<int>vis(n,0);
         
         dfs(vis,adj,0);
         return cnt;
        
    }
};
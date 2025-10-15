class Solution {
public:
    int dfs(int curr,int parent, unordered_map<int,vector<int>>&adj,vector<bool>& hasApple){
        int d =0;
        for(auto &child:adj[curr]){
            if(child==parent)continue;
            int childtime = dfs(child,curr,adj,hasApple);
            if(childtime>0 || hasApple[child]==true){
                 d=d+childtime+2;
            }
        }
        return d;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
         unordered_map<int,vector<int>>adj;

         for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        
         }
         
        return  dfs(0,-1,adj,hasApple);

       
         
    }
};
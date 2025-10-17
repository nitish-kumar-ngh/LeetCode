class Solution {
public:
    int ans =-1;

     void dfs(int curr,unordered_map<int,vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,int cnt){     
        vis[curr]=1;
        pathvis[curr]=1;
        for(auto &it:adj[curr]){
            if(vis[it]==0){
                 dfs(it,adj,vis,pathvis,cnt+1);
            }else if( pathvis[it]==1){
                ans= max(ans,cnt);
            }
        }
        pathvis[curr]=0;

     }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
          unordered_map<int,vector<int>>adj1;
        for(int i=0;i<edges.size();i++){
           if(edges[i]!=-1) {
            adj[i].push_back(edges[i]);
            adj1[edges[i]].push_back(i);
            }
        }
        // vector<int>vis(n,0);
        // vector<int>pathvis(n,0);
        // for(int i=0;i<n;i++){
        //     if(vis[i]==0){
        //     dfs(i,adj,vis,pathvis,1);
        //     }
        // }

         vector<int>vis1(n,0);
        vector<int>pathvis1(n,0);
        for(int i=0;i<n;i++){
            if(vis1[i]==0){
            dfs(i,adj1,vis1,pathvis1,1);
            }
        }


        return ans;
    }
};